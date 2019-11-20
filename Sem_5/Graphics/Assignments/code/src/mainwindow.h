#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>
#include <QImage>
#include <time.h>
#include <QPixmap>
#include <QImage>
#include <iostream>
#include <QMouseEvent>
#include <QPainter>
#include <QPaintDevice>
#include <QPoint>
#include <iostream>
#include <math.h>
#include <time.h>
#include <QVector>
#include <QPair>
#include <QThread>
#include <algorithm>
#define PI 3.14159
using namespace std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public slots:
    void Mouse_Pressed();
    void showMousePosition(QPoint& pos);
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_Draw_clicked();
    void on_set_point1_clicked();
    void on_set_point2_clicked();
    void on_spinBox_valueChanged(int arg1);
    void on_setRadius_valueChanged(int arg1);
    void on_setCentre_clicked();
    void on_tabWidget_tabBarClicked(int index);
    void on_setA_valueChanged(int arg1);
    void on_setB_valueChanged(int arg1);
    void on_setCentreEllipse_clicked();
    void on_setStartingPoint_clicked();
    void on_reset_clicked();
    void on_setPointPolygon_clicked();
    void on_completePolygon_clicked();
    void on_fill_clicked();
    void on_boundaryColor_activated(const QString &arg1);
    void on_fillColor_activated(const QString &arg1);
    void on_tx_valueChanged(int arg1);
    void on_ty_valueChanged(int arg1);
    void on_sx_valueChanged(double arg1);
    void on_sy_valueChanged(double arg1);
    void on_theta_valueChanged(int arg1);
    void on_reflectpoint_1_clicked();
    void on_reflectpoint_2_clicked();
    void on_draw_reflection_clicked();
    void on_reflectX_clicked();
    void on_reflectY_clicked();
    void on_xmin_valueChanged(int arg1);
    void on_xmax_valueChanged(int arg1);
    void on_ymin_valueChanged(int arg1);
    void on_ymax_valueChanged(int arg1);

    void on_drawWindow_clicked();

    void on_lineClipping_clicked();

    void on_areaClipping_clicked();

    void on_translateButton_clicked();

    void on_setScalePt_clicked();

    void on_scaleButton_clicked();

    void on_setRotatePt_clicked();

    void on_rotateButton_clicked();

    void on_shx_valueChanged(double arg1);

    void on_shy_valueChanged(double arg1);

    void on_shear_clicked();

    void on_addPointCurve_clicked();

    void on_drawCurve_clicked();

private:
    Ui::MainWindow *ui;
    QImage img;
    QPoint p1,p2;
    QPoint centre;
    QPoint sp, prevpt, currpt;
    QColor boundaryColor, fillColor, bgColor;
    QVector <QPair <QPoint, QPoint> > lines;
    QVector <QPair <int, int> > polygonVertices;
    QVector <QPoint> bez;
    int a, b;
    int radius;
    int gridSize;
    int tabIndex;
    int r;
    int tx, ty;
    float sx, sy;
    float shx, shy;
    QPoint scalePt, rotatePt;
    float theta;
    int xmin, xmax, ymin, ymax;
    int stop, sleft, sright, sbottom;
    void drawParametric();
    void drawDDA();
    void drawBresenham();
    void drawVertical();
    void drawParametricCircle();
    void drawMidpointCircle();
    void drawBresenhamCircle();
    void drawParametricEllipse();
    void drawMidpointEllipse();
    void drawPoints(int, int);
    void ellipsePoints(int, int);
    void floodFill(int, int);
    void boundaryFill(int, int);
    void drawPolygon();
    void translate(int, int);
    void scale(float,float);
    void rotate(float);
    void shear(float, float);
    void reflectX();
    void reflectY();
    void cohenSutherland(QPoint, QPoint);
    void sutherlandHodgeman();
    int computeCode(QPoint);
    void drawWindow();
    QColor getBgColor(int, int);
    bool isWall(int, int);
    bool isBoundary(int, int);
    bool isColored(int, int);
    int x_intersect(int, int, int, int, int);
    void scanLine();
    void point(int,int, QColor = qRgb(0, 0, 255));
    void drawGrid();
    void drawAxis();
    int getPixelX(int);
    int getPixelY(int);
    int getCoordX(int);
    int getCoordY(int);
    void resetCanvas();
    void swap();
    int nCr(int, int);
    int fact(int);
    enum region{left = 1, right = 2, bottom = 4, top = 8};
};

#endif // MAINWINDOW_H
