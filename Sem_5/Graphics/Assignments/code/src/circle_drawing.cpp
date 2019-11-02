#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

void MainWindow::drawPoints(int x, int y)
{
    point(centre.x() + x, centre.y() + y);
    point(centre.x() + x, centre.y() - y);
    point(centre.x() - x, centre.y() + y);
    point(centre.x() - x, centre.y() - y);
    point(centre.x() + y, centre.y() + x);
    point(centre.x() + y, centre.y() - x);
    point(centre.x() - y, centre.y() + x);
    point(centre.x() - y, centre.y() - x);
}

void MainWindow::on_setRadius_valueChanged(int arg1)
{
    radius = arg1;
}

void MainWindow::on_setCentre_clicked()
{
    centre.setX(getPixelX(ui->frame->x));
    centre.setY(getPixelY(ui->frame->y));
}

void MainWindow::drawParametricCircle()
{
    point(centre.x(), centre.y());
    for(float i = 0; i < 360; i += 0.2)
    {
        int ix = round(centre.x() + radius * cos(PI * i / 180.0));
        int iy = round(centre.y() + radius * sin(PI * i / 180.0));
        point(ix, iy);
    }
}

void MainWindow::drawMidpointCircle()
{
    point(centre.x(), centre.y());
    int x = 0;
    int y = radius;
    int p = 1 - radius;

    drawPoints(x, y);
    while(x < y)
    {
        if(p < 0)
        {
            ++x;
            p += 2 * x + 1;
        }
        else
        {
            ++x; --y;
            p += 1 + 2 * (x - y);
        }
        drawPoints(x, y);
    }
}

void MainWindow::drawBresenhamCircle()
{
    point(centre.x(), centre.y());
    int x = 0;
    int y = radius;
    int p = 3 - 2 * radius;

    drawPoints(x, y);
    while(x < y)
    {
        if(p < 0)
        {
            ++x;
            p += 2 * x + 3;
        }
        else
        {
            ++x; --y;
            p += 5 + 2 * (x - y);
        }
        drawPoints(x, y);


    }
}
