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
    void DDALine(float x1, float y1, float x2, float y2);
    void draw_polygon();
    void clear_screen();
    ~MainWindow();

private slots:
    void on_color_clicked();

    void on_pushButton_2_clicked();

    void on_clear_clicked();

    void on_Translate_clicked();

    void on_Rotate_clicked();

    void on_Scale_clicked();

protected:
    void mousePressEvent(QMouseEvent *ev);

private:
    Ui::MainWindow *ui;
};

class vertex{
public:
    int x;
    int y;
    vertex():x(0),y(0){}

    vertex(int a, int b):x(a),y(b){}

    vertex(vertex &t){
        this->x = t.x;
        this->y = t.y;
    }

    vertex operator + (vertex &v){
        this->x += v.x;
        this->y += v.y;
        return *this;
    }

    vertex operator - (vertex &v){
        this->x -= v.x;
        this->y -= v.y;
        return *this;
    }

    vertex operator * (vertex &v){
        this->x *= v.x;
        this->y *= v.y;
        return *this;
    }

    void translate(int tx, int ty);
    void rotate(double a);
    void rotate(double a, int p1, int p2);
    void scale(float sx, float sy);
};
#endif // MAINWINDOW_H
