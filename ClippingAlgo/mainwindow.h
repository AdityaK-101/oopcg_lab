#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class point
{
public:
    float x;
    float y;
    int outcode = 0;
    friend class MainWindow;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void createWindow();
    void generateOutcodes(point &p);
    int checkOutcodes(point p1, point p2);
    void DDAline(float x1, float y1, float x2, float y2, uint value);
    void clipline_oneinside(point &p1, point &p2);
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_windowColor_clicked();

    void on_lineColor_clicked();


    void on_createLine_clicked();

    void on_createWindow_clicked();

    void on_clipLine_clicked();

protected slots:
    void mousePressEvent(QMouseEvent *event);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
