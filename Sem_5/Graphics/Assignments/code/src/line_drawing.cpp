#include "mainwindow.h"
#include "ui_mainwindow.h"

// Set p1 when Set Point 1 button is clicked
void MainWindow::on_set_point1_clicked()
{
    p1.setX(getPixelX(ui->frame->x));
    p1.setY(getPixelY(ui->frame->y));

}

// Set p2 when Set Point 2 button is clicked
void MainWindow::on_set_point2_clicked()
{
    p2.setX(getPixelX(ui->frame->x));
    p2.setY(getPixelY(ui->frame->y));
}

// Function to swap points p1 and p2
void MainWindow::swap()
{
    QPoint temp = p1;
    p1 = p2;
    p2 = temp;
}

// Function to draw lines parallel to Y-axis
void MainWindow::drawVertical()
{
    if(p1.y() > p2.y())
        swap();

    for(int iy = p1.y(); iy <= p2.y(); iy++)
        point(p1.x(), iy, boundaryColor);

}

// Draw a line using PARAMETRIC ALGORITHM
void MainWindow::drawParametric()
{
    // For lines parallel to Y- axis
    if(p1.x() == p2.x())
    {
        drawVertical();
        return;
    }

    // Calculating m and c for the equation of line
    double m = (double)(p2.y() - p1.y()) / (double)(p2.x() - p1.x());
    double c = p2.y() - m * p2.x();

    // For |m| <= 1 iterate through x and find y
    if (abs(m) <= 1.0)
    {
        if(p1.x() > p2.x())
            swap();

        for(int ix = p1.x(); ix <= p2.x(); ix++)
        {
            double fy =  m * (double)ix + c;
            int iy = round(fy);
            point(ix, iy, boundaryColor);
        }
    }
    // For |m| > 1 iterate through y and find x
    else
    {
        if(p1.y() > p2.y())
            swap();

        for(int iy = p1.y(); iy <= p2.y(); iy++)
        {
            double fx = ((double)iy - c) / m;
            int ix = round(fx);
            point(ix, iy, boundaryColor);
        }

    }
}

// Draw a line using DDA ALGORITHM
void MainWindow::drawDDA()
{

    // For lines parallel to Y- axis
    if(p1.x() == p2.x())
    {
        drawVertical();
        return;
    }

    // Calculating slope of the line
    double m = double(p2.y() - p1.y()) / double(p2.x() - p1.x());


    // For |m| <= 1, increment x by 1 and y by m
    if(abs(m) <= 1.0)
    {
        if(p1.x() > p2.x())
            swap();

        double ix = (double)p1.x();
        double iy = (double)p1.y();

        while(ix <= p2.x())
        {
            point(round(ix), round(iy), boundaryColor);
            ix = ix + 1;
            iy = iy + m;
        }
    }
    // For |m| > 1, increment x by 1/m and y by 1
    else
    {
        if(p1.y() > p2.y())
            swap();

        double ix = (double)p1.x();
        double iy = (double)p1.y();

        while(iy <= p2.y())
        {
            point(round(ix), round(iy), boundaryColor);
            ix = ix + 1/m;
            iy = iy + 1;
        }

    }


}

// Draw a line using BRESENHAM ALGORITHM
void MainWindow::drawBresenham()
{
    // For lines parallel to Y- axis
    if(p1.x() == p2.x())
    {
        drawVertical();
        return;
    }

    // Calculating dx and dy for the line
    int dy = p2.y() - p1.y();
    int dx = p2.x() - p1.x();
    double m = (double)dy / (double)dx;

    if(m >= 0.0 && m <= 1.0)
    {
        if(p1.x() > p2.x())
        {
            swap();
            dy = -dy;
            dx = -dx;
        }


        int x = p1.x();
        int y = p1.y();
        int p = 2 * dy - dx;
        point(x, y);
        while(x < p2.x())
        {
            if(p < 0)
            {
                point(++x, y, boundaryColor);
                p += 2 * dy;
            }
            else
            {
                point(++x, ++y, boundaryColor);
                p += 2 * dy - 2 * dx;
            }
        }
    }

    else if(m > 1.0)
    {
        if(p1.y() > p2.y())
        {
            swap();
            dy = -dy;
            dx = -dx;
        }

        int x = p1.x();
        int y = p1.y();
        double p = 2 * dx - dy;
        point(x, y);
        while(y < p2.y())
        {
            if(p < 0)
            {
                point(x, ++y, boundaryColor);
                p += 2 * dx;
            }
            else
            {
                point(++x, ++y, boundaryColor);
                p += 2 * dx - 2 * dy;
            }
        }
    }

    else if(m < 0.0 && m >= -1.0)
    {
        if(p1.x() > p2.x())
        {
            swap();
            dy = -dy;
            dx = -dx;
        }

        int x = p1.x();
        int y = p1.y();
        dy = -dy;
        double p = 2 * dy - dx;
        point(x, y);
        while(x < p2.x())
        {
            if(p < 0)
            {
                point(++x, y, boundaryColor);
                p += 2 * dy;
            }
            else
            {
                point(++x, --y, boundaryColor);
                p += 2 * dy - 2 * dx;
            }
        }
    }
    else
    {
        if(p1.y() > p2.y())
        {
            swap();
            dy = -dy;
            dx = -dx;
        }

        int x = p1.x();
        int y = p1.y();
        dx = -dx;
        double p = 2 * dx - dy;
        point(x, y);
        while(y < p2.y())
        {
            if(p < 0)
            {
                point(x, ++y, boundaryColor);
                p += 2 * dx;
                //cout << "p=" << p << endl;
            }
            else
            {
                point(--x, ++y, boundaryColor);
                p += 2 * dx - 2 * dy;
                //cout << "p=" << p << endl;
            }
        }
    }
}
