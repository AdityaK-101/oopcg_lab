#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math.h"
#include "QMouseEvent"
#include "QColorDialog"

QImage img(650,650,QImage::Format_RGB888);//img is object of class QImage
static QColor color;//Decalration and initialised in further on_clicked funtion.

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ver = 0;
    start = true;
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
        img.setPixel(floor(x),floor(y),color.rgb());
        x = x+x_inc;
        y = y+y_inc;
    }
    ui->output->setPixmap(QPixmap::fromImage(img));
}

int sign(int n){ //Basically used for bresenham line.
    if(n<0)
        return -1;
    else return 1;
}

void MainWindow::Bresenham(int x1,int y1,int x2,int y2){
    int x,y;
    x = x1;
    y = y1;
    int dx,dy,p;
    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    int i = 0;
    if(dx>=dy){//if slope is less than 1.
        p = 2*dy - dx;//Decision parameter
        while(i<dx){
            img.setPixel(x,y,color.rgb());
            if(p>0){
                p+=2*dy-2*dx;
                y+= sign(y2-y1);
            }
            else if (p<0){
                p+=2*dy;
            }
            x+=sign(x2-x1);
            i++;
        }

    }
    else{//else part will be executed when slope is greater than 1.
        p = 2*dx - dy;
        while(i<dy){
            img.setPixel(x,y,color.rgb());
            if(p>0){
                p+=2*dx-2*dy;
                x+=sign(x2-x1);
            }
            else if (p<0){
                p+=2*dx;
            }
            y+=sign(y2-y1);
            i++;
        }
    }
    ui->output->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_choiceColor_clicked()
{
    color = QColorDialog::getColor();
}

void MainWindow::mousePressEvent(QMouseEvent *ev){
    if(start){//will execute similar to loop until start isn't updated to false.
        float p = ev->pos().x();//reads x coordinate of vertex, p is storing postion of x
        float q = ev->pos().y();//reads y coordinate of vertex(same)
        a[ver] = p;
        b[ver] = q;
        if(ev->button()==Qt::RightButton){
            DDALine(a[0],b[0],a[ver-1],b[ver-1]);//A line will be drawn between first to last vertex and polygon will be closed.
            start = false;//Updating flag
        }else{
            if(ver>0){
                DDALine(a[ver],b[ver],a[ver-1],b[ver-1]);//Draws line from next vertex to previous vertex(decresing index)
            }
        }
        ver++;//Incrementing vertex
    }
}

void MainWindow::Scanfill(){
    //Phase 1: Assign value of Ymin and value of Ymax
    int ymin = 1000000, ymax = 0, temp,k;
    for(int i=0;i<ver;i++){
        if(b[i]>ymax){
            ymax = b[i];
        }
        if(b[i]<ymin){
            ymin = b[i];
        }
    }

    //Phase 2: Calculate slope for each coordinate in a and b and append those values to slope array.
    a[ver] = a[0];
    b[ver] = b[0];
    for(int i=0;i<ver;i++){
        dx = a[i+1] - a[i];
        dy = b[i+1] - b[i];
        //Note that we have to now calculate 1/m instead of m.
        if(dx==0.0){
            slope[i] = 0.0;//Assigning inverse values as we are intrested in 1/m(logically)
        }else if(dy==0.0){
            slope[i] = 1.0;
        }if(dx!=0.0 && dy!=0.0){
            slope[i] = float(dx)/float(dy);
        }
    }

    //Phase 3: Compute Intersection Points and append those to respective array xi[].
    for(int j=ymin;j<ymax;j++){
        k = 0;
        for(int i=0;i<ver;i++){
            if((b[i]<=j && b[i+1]>j) || (b[i]>j && b[i+1]<=j)){
                //We have formula , x(intersection) = x + (1/m * (y2 - y1))
                xi[k] = (int)(a[i] + (slope[i] * (j- b[i])));
                k++;
            }
        }

        //Phase 3.2 : Sort x coordinates in ascending order
        //Sorting the obtained intersected points using bubble sort
        for(int m=0;m<(k-1);m++){
            for(int n=0;n<k-m-1;n++){
                if(xi[n] > xi[n+1]){
                    temp = xi[n];
                    xi[n] = xi[n+1];
                    xi[n+1] = temp;
                }
            }
        }

        //Phase 3.3: Calling bresenham function to fill scan line.
        for(int i=0;i<k;i+=2){
            Bresenham(xi[i],j,xi[i+1],j);
        }
    }
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *ev){
    Scanfill();
}
