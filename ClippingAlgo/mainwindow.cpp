#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMouseEvent>
#include "QColorDialog"

static QImage img(500,500, QImage::Format_RGB888);
static QRgb bgColor(qRgb(0,0,0));
static QRgb color;
static QRgb windowColor;
static float wxmin, wxmax, wymin, wymax;

int points = 0;
bool draw = false;
bool setWindow = false;
point *arr = new point[20];


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    img.fill(bgColor);
    ui->background->setPixmap(QPixmap::fromImage(img));
}

MainWindow::~MainWindow()
{
    delete[] arr;
    arr = NULL;
    delete ui;
}

void MainWindow::on_windowColor_clicked()
{
    windowColor = QColorDialog::getColor().rgb();
}

void MainWindow::on_lineColor_clicked()
{
    color = QColorDialog::getColor().rgb();
}

void MainWindow::on_createLine_clicked()
{
    draw = true;
}

void MainWindow::on_createWindow_clicked()
{
    wxmin = ui->plainTextEdit->toPlainText().toInt();
    wymin = ui->plainTextEdit_2->toPlainText().toInt();
    wxmax = ui->plainTextEdit_3->toPlainText().toInt();
    wymax = ui->plainTextEdit_4->toPlainText().toInt();
    createWindow();
    setWindow = true;
}

void MainWindow::DDAline(float x1, float y1, float x2, float y2, uint value){
    int length = 0;
    if (abs(x2 - x1) >= abs(y2 - y1)){
        length = abs(x2 - x1);
    }
    else {
        length = abs(y2 - y1);
    }
    float dx = float(x2 - x1)/float(length);
    float dy = float(y2 - y1)/float(length);
    float x = x1;
    float y = y1;
    int i = 1;
    while (i <= length){
        img.setPixel(x, y, value);
        x = x + dx;
        y = y + dy;
        i++;
    }
}

void MainWindow::createWindow(){
    DDAline(wxmin, wymin, wxmax, wymin, windowColor);
    DDAline(wxmin, wymin, wxmin, wymax, windowColor);
    DDAline(wxmax, wymin, wxmax, wymax, windowColor);
    DDAline(wxmin, wymax, wxmax, wymax, windowColor);

    ui->background->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::generateOutcodes(point &p){
    (p.y > wymax)?(p.outcode += 8):(p.outcode += 0);
    (p.y < wymin)?(p.outcode += 4):(p.outcode += 0);
    (p.x > wxmax)?(p.outcode += 2):(p.outcode += 0);
    (p.x < wxmin)?(p.outcode += 1):(p.outcode += 0);
}

int MainWindow::checkOutcodes(point p1, point p2){
    if(!(p1.outcode | p2.outcode)){
        return 0;
    }
    else if(p1.outcode & p2.outcode){
        return -1;
    }
       return 1;
}

void MainWindow::mousePressEvent(QMouseEvent *ev){

    if(setWindow && draw){
        point p;
        p.x = ev->pos().x();
        p.y = ev->pos().y();
        generateOutcodes(p);
        arr[points] = p;
        if(points % 2 != 0){
            DDAline(arr[points - 1].x,arr[points - 1].y, arr[points].x, arr[points].y, color);
           ui->background->setPixmap(QPixmap::fromImage(img));
        }
        points++;
    }
}

void MainWindow::on_clipLine_clicked()
{
    int i = 0;
    while (i <= points){
        int check = checkOutcodes(arr[i], arr[i+1]);
        if (check == -1){
            // completely outside, set endpoints as '-1'
            arr[i].x = arr[i].y = arr[i+1].x = arr[i+1].y = -1;
        }

        else if (check == 1){
            float m = (arr[i+1].y - arr[i].y) / (arr[i+1].x - arr[i].x);
            point outPoint = (arr[i].outcode > arr[i+1].outcode) ? (arr[i]) : (arr[i+1]);
            point inPoint = (arr[i].outcode < arr[i+1].outcode) ? (arr[i]) : (arr[i+1]);

            switch(outPoint.outcode){
            case 1 : // x is fixed as wx1, y calculated accordingly
                outPoint.y = inPoint.y + (m * (wxmin - inPoint.x));
                outPoint.x = wxmin;
                break;

            case 2 : // x is fixed as wx2, y calculated accordingly
                outPoint.y = inPoint.y + (m * (wxmax - inPoint.x));
                outPoint.x = wxmax;
                break;

            case 4 : // y is fixed as wy1, x calculated accordingly
                outPoint.x = inPoint.x + ((1/m) * (wymin - inPoint.y));
                outPoint.y = wymin;
                break;

            case 8 : // y is fixed as wy2, x calculated accordingly
                outPoint.x = inPoint.x + ((1/m) * (wymax - inPoint.y));
                outPoint.y = wymax;
                break;
            }

            if (arr[i].outcode > arr[i+1].outcode){
                arr[i].x = outPoint.x;
                arr[i].y = outPoint.y;
            } else {
                arr[i+1].x = outPoint.x;
                arr[i+1].y = outPoint.y;
            }
        }
        i += 2;
    }


    for (int i=0; i<500; i++){
        for (int j=0; j<500; j++){
            img.setPixel(i, j, bgColor);
        }
    }
    ui->background->setPixmap(QPixmap::fromImage(img));

    createWindow();

    i = 0;
    while (i <= points){
        if (arr[i].x != -1) {
            DDAline(arr[i].x, arr[i].y, arr[i+1].x, arr[i+1].y, color);
        }
        i+=2;
    }

    ui->background->setPixmap(QPixmap::fromImage(img));
}

