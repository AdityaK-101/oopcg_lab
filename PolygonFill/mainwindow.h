#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    int a[50];//array for storing x coordinates of polygon vertices.
    int b[50];//array for storing y coordinates of polygon vertices.
    int ver;//Number of Vertices
    bool start;//Flag used to accept vertices from user
    float dx,dy;
    float slope[50];//for storing slopes of edges of polygon.
    int xi[50];//Array for storing intersection points of scanline and given polygon.
    void DDALine(float x1, float y1, float x2 , float y2);//For drawing edges of polygon.
    void Bresenham(int x1, int y1, int x2, int y2);//For filling polygon, used with scanfill.
    void Scanfill();//For Polygon Filling.
    ~MainWindow();

private slots:
    void on_choiceColor_clicked();

protected:
    void mousePressEvent(QMouseEvent *ev);//For Drawing Edges
    void mouseDoubleClickEvent(QMouseEvent *ev);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
