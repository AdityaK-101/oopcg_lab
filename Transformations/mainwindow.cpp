#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math.h"
#include "QColorDialog"
#include "QMouseEvent"
#define pi 3.412

QImage img(500,500,QImage::Format_RGB888);
static QColor bgcolor(255,255,255);
static QColor color(qRgb(230,230,230));

vertex* polygon = new vertex[20];
int count = 0;
bool draw = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    img.fill(bgcolor);
    ui->output->setPixmap(QPixmap::fromImage(img));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::DDALine(float x1, float y1, float x2, float y2){
    float x_inc, y_inc,x,y;
    float l = abs(x2-x1)>=abs(y2-y1)?abs(x2-x1):abs(y2-y1);
    x_inc = (x2 - x1)/l;
    y_inc = (y2 - y1)/l;
    x = x1;
    y = y1;
    for(int i=0;i<l;i++){
        img.setPixelColor((x),(y), color);
        x += x_inc;
        y += y_inc;
    }
    ui->output->setPixmap(QPixmap::fromImage(img));
}

void vertex::translate(int tx, int ty){
    vertex v(tx,ty);
    *this = *this + v;
}

void vertex::rotate(double A)
{
    vertex temp(*this);

    this->x = (temp.x * cos(A)) - (temp.y * sin(A));
    this->y = (temp.x * sin(A)) + (temp.y * cos(A));

 }

void vertex::rotate(double A, int px, int py)
{
    this->translate(-px, -py);
    this->rotate(A);
    this->translate(px, py);
}

void vertex::scale(float sx, float sy){
    vertex v(sx,sy);
    *this = *this * v;
}

void MainWindow::mousePressEvent(QMouseEvent *ev){
    if(draw){
        if(ev->button() == Qt::RightButton){
            DDALine(polygon[0].x,polygon[0].y,polygon[count-1].x,polygon[count - 1].y);
            draw = false;
            return;
        }
        vertex p;
        p.x = ev->pos().x();
        p.y = ev->pos().y();
        polygon[count] = p;
        if(count){
            DDALine(polygon[count - 1].x, polygon[count - 1].y, polygon[count].x, polygon[count].y);
        }
        count ++;
    }
}

void MainWindow::draw_polygon(){
    clear_screen();
    int i = 1;
    while(i<count){
        DDALine(polygon[i-1].x, polygon[i-1].y,polygon[i].x, polygon[i].y);
        i++;
    }
    DDALine(polygon[0].x, polygon[0].y, polygon[i-1].x, polygon[i-1].y);
}

void MainWindow::on_color_clicked()
{
    color = QColorDialog::getColor();
}


void MainWindow::on_pushButton_2_clicked()
{
    draw = true;
}

void MainWindow::clear_screen(){
    img.fill(bgcolor);
    ui->output->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_clear_clicked()
{
    delete[] polygon;
    polygon = new vertex[20];
    draw = false;
    clear_screen();
}


void MainWindow::on_Translate_clicked()
{
    int tx = ui->plainTextEdit->toPlainText().toInt();
    int ty = ui->plainTextEdit_2->toPlainText().toInt();
    for(int i=0;i<count;i++){
        polygon[i].translate(tx,ty);
    }
    draw_polygon();
}


void MainWindow::on_Rotate_clicked()
{
    double a = pi * (ui->plainTextEdit_3->toPlainText().toDouble())/180;
    int p1 = ui->plainTextEdit_4->toPlainText().toInt();
    int p2 = ui->plainTextEdit_5->toPlainText().toInt();
    if(p1 || p2){
        for(int i=0;i<count;i++){
            polygon[i].rotate(a,p1,p2);
        }
    }else{
        for(int i=0;i<count;i++){
            polygon[i].rotate(a);
        }
    }
    draw_polygon();
}


void MainWindow::on_Scale_clicked()
{
    int sx = ui->plainTextEdit_6->toPlainText().toInt();
    int sy = ui->plainTextEdit_7->toPlainText().toInt();
    for(int i=0;i<count;i++){
        polygon[i].scale(sx,sy);
    }
    draw_polygon();
}

