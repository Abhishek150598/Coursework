#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::on_addPointCurve_clicked()
{
    int x0 = getPixelX(ui->frame->x);
    int y0 = getPixelY(ui->frame->y);
    bez.push_back(QPoint(x0, y0));
}

int MainWindow::nCr(int n, int r)
{
    return fact(n) / (fact(r) * fact(n - r));
}

int MainWindow::fact(int n)
{
    int res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}

void MainWindow::on_drawCurve_clicked()
{
    int l = bez.size();
    float xi;
    float yi;
    point(bez[0].x(), bez[0].y());
    point(bez[l-1].x(), bez[l-1].y());
    for(float t = 0.005 ; t <= 1.0; t += 0.005)
    {
        xi = 0.0;
        yi = 0.0;
        for(int i = 0; i < l; i++)
        {
            float p = nCr(l-1, i)*pow(t, i)*pow(1-t, l-1-i);
            xi += p * bez[i].x();
            yi += p * bez[i].y();
        }
        point(round(xi), round(yi));
    }

    QPoint b = bez[l-1];
    bez.clear();
    bez.push_back(b);

}
