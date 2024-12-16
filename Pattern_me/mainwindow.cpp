#include "mainwindow.h"
#include "ui_mainwindow.h"

static QImage img(500,500, QImage::Format_RGB888);
static QRgb bgColor(qRgb(0,0,0));

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->display->setPixmap(QPixmap::fromImage(img));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ddaalgo(int x1, int y1, int x2, int y2)
{
    QRgb val;
    val = qRgb(255,0,206);
    int len = 0;
    if(abs(x2-x1)>=abs(y2-y1))
    {
        len = abs(x2-x1);
    }
    else
    {
        len = abs(y2-y1);
    }
    float dx = float(x2-x1)/float(len);
    float dy = float(y2-y1)/float(len);
    float x = x1;
    float y = y1;
    for(int i = 0; i<=len; i++)
    {
        img.setPixel(x,y,val);
        x+=dx;
        y+=dy;
    }
}

void MainWindow::bresenham(int xc, int yc, int r)
{
    QRgb val;
    val = qRgb(255,244,0);
    int x = 0;
    int y = r;
    int p = 3-(2*r);
    do{
        img.setPixel(xc+x,yc+y,val);
        img.setPixel(xc+x,yc-y,val);
        img.setPixel(xc-x,yc+y,val);
        img.setPixel(xc-x,yc-y,val);
        img.setPixel(xc+y,yc+x,val);
        img.setPixel(xc+y,yc-x,val);
        img.setPixel(xc-y,yc+x,val);
        img.setPixel(xc-y,yc-x,val);

        if(p<0)
        {
            p+=(4*x)+6;
            x+=1;
        }
        else
        {
            p+=(4*(x-y))+10;
            y-=1;
            x+=1;
        }
    }while(x<=y);
}


void MainWindow::on_create_clicked()
{
    int xc = ui->xc->toPlainText().toInt();
    int yc = ui->yc->toPlainText().toInt();
    int R = ui->rad->toPlainText().toInt();
    int r = R*0.5;
    int s = 0.866*R;

    ddaalgo(xc,yc-R,xc-s,yc+r);
    ddaalgo(xc,yc-R,xc+s,yc+r);
    ddaalgo(xc-s,xc+r,xc+s,yc+r);

    bresenham(xc,yc,R);
    bresenham(xc,yc,r);

    ui->display->setPixmap(QPixmap::fromImage(img));
    ui->display->show();
}


void MainWindow::on_clear_clicked()
{
    img.fill(bgColor);
    ui->display->setPixmap(QPixmap::fromImage(img));
}



















