#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::ellipsePoints(int x, int y)
{
    point(centre.x() + x, centre.y() + y);
    point(centre.x() + x, centre.y() - y);
    point(centre.x() - x, centre.y() + y);
    point(centre.x() - x, centre.y() - y);
}

void MainWindow::on_setA_valueChanged(int arg1)
{
    a = arg1;
}

void MainWindow::on_setB_valueChanged(int arg1)
{
    b = arg1;
}

void MainWindow::on_setCentreEllipse_clicked()
{
    centre.setX(getPixelX(ui->frame->x));
    centre.setY(getPixelY(ui->frame->y));
}

void MainWindow::drawParametricEllipse()
{
    point(centre.x(), centre.y());
    for(float i = 0; i < 360; i += 0.5)
    {
        int ix = round(centre.x() + a * cos(PI * i / 180.0));
        int iy = round(centre.y() + b * sin(PI * i / 180.0));
        point(ix, iy);
    }
}

void MainWindow::drawMidpointEllipse()
{
    double d2;
    point(centre.x(), centre.y());
    int x = 0;
    int y = b;
    double dl = b*b - a*a*b + 0.25*a*a;
    ellipsePoints(x, y);

    while(a*a*(y-0.5) > b*b*(x+1))
    {
        if(dl < 0)
            dl += b*b*(2*x+3);
        else
        {
            dl += b*b*(2*x+3) + a*a*(-2*y+2);
            y--;
        }
        x++;
        ellipsePoints(x, y);
    }

    d2 = b*b*(x+0.5)*(x+0.5) + a*a*(y-1)*(y-1) - a*a*b*b;
    while(y > 0)
    {
        if(d2 < 0)
        {
            d2 += b*b*(2*x+2) + a*a*(-2*y+3);
            x++;
        }
        else
            d2 += a*a*(-2*y+3);

        y--;
        ellipsePoints(x, y);
    }
}
