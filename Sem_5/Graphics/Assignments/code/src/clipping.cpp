#include "mainwindow.h"
#include "ui_mainwindow.h"

int MainWindow::computeCode(QPoint pt1)
{
    int code = 0;

    if(pt1.x() < xmin)
        code |= left;
    else if(pt1.x() > xmax)
        code |= right;
    if(pt1.y() < ymin)
        code |= bottom;
    else if(pt1.y() > ymax)
        code |= top;

    return code;
}

void MainWindow::cohenSutherland(QPoint pt1, QPoint pt2)
{
    int code1 = computeCode(pt1);
    int code2 = computeCode(pt2);
    cout << code1 << " " << code2 << endl;
    bool accept = false;

    while(1)
    {
        // If both the regions codes are 0000, the entire line is accepted
        if((code1 | code2) == 0)
        {
            accept = true;
            break;
        }
        // If the region codes have at least one common set bit, the entire line is rejected.
        if(code1 & code2)
        {
            cout << "reject" << endl;
            break;
        }

        int code_out;
        double x, y;

        if(code1 != 0)
            code_out = code1;
        else
            code_out = code2;

        // Point is above the clipping window
        if(code_out & top)
        {
            x = pt1.x() + (double)(pt2.x() - pt1.x()) * (ymax - pt1.y()) / (double)(pt2.y() - pt1.y());
            y = ymax;
        }
        else if(code_out & bottom)
        {
            x = pt1.x() + (double)(pt2.x() - pt1.x()) * (ymin - pt1.y()) / (double)(pt2.y() - pt1.y());
            y = ymin;
        }
        else if(code_out & right)
        {
            y = pt1.y() + (double)(pt2.y() - pt1.y()) * (xmax - pt1.x()) / (double)(pt2.x() - pt1.x());
            x = xmax;
        }
        else if(code_out & left)
        {
            y = pt1.y() + (double)(pt2.y() - pt1.y()) * (xmin - pt1.x()) / (double)(pt2.x() - pt1.x());
            x = xmin;
        }

        if (code_out == code1)
        {
            pt1.setX(x);
            pt1.setY(y);
            code1 = computeCode(pt1);
        }
        else
        {
            pt2.setX(x);
            pt2.setY(y);
            code2 = computeCode(pt2);
        }
        cout << code1 << " " << code2 << endl;
    }

    if(accept)
    {
        p1 = pt1;
        p2 = pt2;
        drawBresenham();
    }
}

void MainWindow::sutherlandHodgeman()
{
    QVector <QPair <int, int> > newVertices;
    // For left boundary
    for(int i = 0; i < polygonVertices.size(); i++)
    {
        // i is the current point index, while k is the next point index
        int k = (i + 1) % polygonVertices.size();

        int xi = polygonVertices[i].first;
        int yi = polygonVertices[i].second;
        int xk = polygonVertices[k].first;
        int yk = polygonVertices[k].second;

        cout << xi << " " << yi << " " << xk << " " << yk << endl;

        //CASE 1: when both points are inside
        if(xi >= xmin && xk >= xmin)
        {
            newVertices.push_back(qMakePair(xk, yk));
        }
        //CASE 2: when only point k is inside
        else if(xi < xmin && xk >= xmin)
        {
            int x1 = xmin;
            int y1 = ((xmin - xi) * (yk - yi) / (xk - xi) + yi);
            newVertices.push_back(qMakePair(x1, y1));
            newVertices.push_back(qMakePair(xk, yk));
        }
        //CASE 3: when only point i is inside
        else if(xi >= xmin && xk < xmin)
        {
            int x1 = xmin;
            int y1 = (xmin - xi) * (yk - yi) / (xk - xi) + yi;
            newVertices.push_back(qMakePair(x1, y1));
        }

    }

    polygonVertices.clear();
    polygonVertices = newVertices;
    newVertices.clear();

    // For right boundary
    for(int i = 0; i < polygonVertices.size(); i++)
    {
        // i is the current point index, while k is the next point index
        int k = (i + 1) % polygonVertices.size();

        int xi = polygonVertices[i].first;
        int yi = polygonVertices[i].second;
        int xk = polygonVertices[k].first;
        int yk = polygonVertices[k].second;

        cout << xi << " " << yi << " " << xk << " " << yk << endl;

        //CASE 1: when both points are inside
        if(xi <= xmax && xk <= xmax)
        {
            newVertices.push_back(qMakePair(xk, yk));
        }
        //CASE 2: when only point k is inside
        else if(xi > xmax && xk <= xmax)
        {
            int x1 = xmax;
            int y1 = ((xmax - xi) * (yk - yi) / (xk - xi) + yi);
            newVertices.push_back(qMakePair(x1, y1));
            newVertices.push_back(qMakePair(xk, yk));
        }
        //CASE 3: when only point i is inside
        else if(xi <= xmax && xk > xmax)
        {
            int x1 = xmax;
            int y1 = (xmax - xi) * (yk - yi) / (xk - xi) + yi;
            newVertices.push_back(qMakePair(x1, y1));
        }

    }

    polygonVertices.clear();
    polygonVertices = newVertices;
    newVertices.clear();

    // For bottom boundary
    for(int i = 0; i < polygonVertices.size(); i++)
    {
        // i is the current point index, while k is the next point index
        int k = (i + 1) % polygonVertices.size();

        int xi = polygonVertices[i].first;
        int yi = polygonVertices[i].second;
        int xk = polygonVertices[k].first;
        int yk = polygonVertices[k].second;

        cout << xi << " " << yi << " " << xk << " " << yk << endl;

        //CASE 1: when both points are inside
        if(yi >= ymin && yk >= ymin)
        {
            newVertices.push_back(qMakePair(xk, yk));
        }
        //CASE 2: when only point k is inside
        else if(yi < ymin && yk >= ymin)
        {
            int y1 = ymin;
            int x1 = ((ymin - yi) * (xk - xi) / (yk - yi) + xi);
            newVertices.push_back(qMakePair(x1, y1));
            newVertices.push_back(qMakePair(xk, yk));
        }
        //CASE 3: when only point i is inside
        else if(yi >= ymin && yk < ymin)
        {
            int y1 = ymin;
            int x1 = (ymin - yi) * (xk - xi) / (yk - yi) + xi;
            newVertices.push_back(qMakePair(x1, y1));
        }

    }

    polygonVertices.clear();
    polygonVertices = newVertices;
    newVertices.clear();

    // For top boundary
    for(int i = 0; i < polygonVertices.size(); i++)
    {
        // i is the current point index, while k is the next point index
        int k = (i + 1) % polygonVertices.size();

        int xi = polygonVertices[i].first;
        int yi = polygonVertices[i].second;
        int xk = polygonVertices[k].first;
        int yk = polygonVertices[k].second;

        cout << xi << " " << yi << " " << xk << " " << yk << endl;

        //CASE 1: when both points are inside
        if(yi <= ymax && yk <= ymax)
        {
            newVertices.push_back(qMakePair(xk, yk));
        }
        //CASE 2: when only point k is inside
        else if(yi > ymax && yk <= ymax)
        {
            int y1 = ymax;
            int x1 = ((ymax - yi) * (xk - xi) / (yk - yi) + xi);
            newVertices.push_back(qMakePair(x1, y1));
            newVertices.push_back(qMakePair(xk, yk));
        }
        //CASE 3: when only point i is inside
        else if(yi <= ymax && yk > ymax)
        {
            int y1 = ymax;
            int x1 = (ymax - yi) * (xk - xi) / (yk - yi) + xi;
            newVertices.push_back(qMakePair(x1, y1));
        }

    }
    polygonVertices.clear();
    polygonVertices = newVertices;
    newVertices.clear();

    drawPolygon();

}
void MainWindow::on_xmin_valueChanged(int arg1)
{
    ui->xmax->setMinimum(arg1);
    xmin = arg1;
}

void MainWindow::on_xmax_valueChanged(int arg1)
{
    xmax = arg1;
}

void MainWindow::on_ymin_valueChanged(int arg1)
{
    ui->ymax->setMinimum(arg1);
    ymin = arg1;
}

void MainWindow::on_ymax_valueChanged(int arg1)
{
    ymax = arg1;
}
void MainWindow::drawWindow()
{
    for(int i = xmin; i <= xmax; i++)
    {
        point(i, ymin, qRgb(230, 255, 255));
        point(i, ymax, qRgb(230, 255, 255));
    }
    for(int i = ymin; i <= ymax; i++)
    {
        point(xmin, i, qRgb(230, 255, 255));
        point(xmax, i, qRgb(230, 255, 255));
    }
}

void MainWindow::on_drawWindow_clicked()
{
   drawWindow();
}

void MainWindow::on_lineClipping_clicked()
{
    resetCanvas();
    drawWindow();
    for(int i = 0; i < lines.size(); i++)
    {
        QPoint pt1 = lines[i].first;
        QPoint pt2 = lines[i].second;
        cohenSutherland(pt1, pt2);
    }

}


void MainWindow::on_areaClipping_clicked()
{
    resetCanvas();
    drawWindow();
    sutherlandHodgeman();
}
