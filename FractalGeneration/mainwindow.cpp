#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math.h"

QImage img(650,650,QImage::Format_RGB888);
QColor bgColor(qRgb(0,0,0));
int n=0;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::DDALine(float x1,float y1,float x2,float y2){
    float x,y,x_inc,y_inc,l;
    l = abs(x2-x1)>abs(y2-y1)?abs(x2-x1):abs(y2-y1);
    //variable = (condition) ? (expr if true):(expr if false)
    //type = (10%2==0)?even:odd;
    x_inc = (x2-x1)/l;
    y_inc = (y2-y1)/l;
    x = x1;
    y = y1;
    for(int i=0;i<l;i++){
        img.setPixel(floor(x),floor(y),qRgb(255,255,255));
        x = x+x_inc;
        y = y+y_inc;
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::KochCurve(int n, int x1, int y1, int x2, int y2){
        if(n == 0){
            DDALine(x1, y1, x2, y2);
        }

        else{
            //draw curve
            int x3 = (2*x1 + x2)/3;
            int y3 = (2*y1 + y2)/3;

            int x4 = (x1 + 2*x2)/3;
            int y4 = (y1 + 2*y2)/3;

            int x5 = x3 + (x4 - x3)*(0.5) + (y4 - y3)*(0.86);
            int y5 = y3 - (x4 - x3)*(0.86) + (y4 - y3)*(0.5);

            KochCurve(n-1, x1, y1, x3, y3);
            KochCurve(n-1, x3, y3, x5, y5);
            KochCurve(n-1, x5, y5, x4, y4);
            KochCurve(n-1, x4, y4, x2, y2);
        }
}

void MainWindow::on_verticalSlider_valueChanged(int value)
{
    img.fill(bgColor);
    ui->label->setPixmap(QPixmap::fromImage(img));
    n = value;
    KochCurve(n, 100, 250, 400, 250);
}

