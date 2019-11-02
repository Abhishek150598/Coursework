#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::on_setStartingPoint_clicked()
{
    sp.setX(getPixelX(ui->frame->x));
    sp.setY(getPixelY(ui->frame->y));
    prevpt = sp;
    polygonVertices.clear();
    polygonVertices.push_back(qMakePair(sp.x(), sp.y()));
    stop = sp.y();
    sbottom = sp.y();
    sleft = sp.x();
    sright = sp.x();
}

void MainWindow::on_setPointPolygon_clicked()
{
    currpt.setX(getPixelX(ui->frame->x));
    currpt.setY(getPixelY(ui->frame->y));
    polygonVertices.push_back(qMakePair(currpt.x(), currpt.y()));
    p2 = prevpt;
    p1 = currpt;
    drawParametric();
    prevpt = currpt;
    if(stop < currpt.y())
        stop = currpt.y();
    else if(sbottom > currpt.y())
        sbottom = currpt.y();
    if(sright < currpt.x())
        sright = currpt.x();
    else if(sleft > currpt.x())
        sleft = currpt.x();
}

void MainWindow::on_completePolygon_clicked()
{
    p2 = prevpt;
    p1 = sp;
    drawParametric();
}

bool MainWindow::isBoundary(int pos_x, int pos_y)
{
    return getBgColor(pos_x, pos_y) == boundaryColor;
}

bool MainWindow::isWall(int pos_x, int pos_y)
{
    return (pos_x == r || pos_x == -r || pos_y == r || pos_y == -r);
}

bool MainWindow::isColored(int pos_x, int pos_y)
{
    return getBgColor(pos_x, pos_y) == fillColor;
}

void MainWindow::boundaryFill(int pos_x, int pos_y)
{
    if(isWall(pos_x, pos_y) || isBoundary(pos_x, pos_y) || isColored(pos_x, pos_y))
        return;

    point(pos_x, pos_y, fillColor);

    boundaryFill(pos_x + 1, pos_y);
    boundaryFill(pos_x - 1, pos_y);
    boundaryFill(pos_x, pos_y + 1);
    boundaryFill(pos_x, pos_y - 1);
}

void MainWindow::floodFill(int pos_x, int pos_y)
{
    if(isWall(pos_x, pos_y) || (getBgColor(pos_x, pos_y) != bgColor))
        return;

    point(pos_x, pos_y, fillColor);

    floodFill(pos_x + 1, pos_y);
    floodFill(pos_x - 1, pos_y);
    floodFill(pos_x, pos_y + 1);
    floodFill(pos_x, pos_y - 1);
}

int MainWindow::x_intersect(int y0, int x1, int y1, int x2, int y2)
{
    if((y0 >= y1 && y0 <= y2) || (y0 >= y2 && y0 <= y1))
    {
        return x1 + (y0 - y1) * (x2 - x1) / (y2 - y1);
    }
    else
        return 2*r;
}

void MainWindow::scanLine()
{
    cout << "LRTB: " << sleft << " " << sright << " " << stop << " " << sbottom << endl;
    for(int i = sbottom; i <= stop; i++)
    {
        int n = polygonVertices.size();
        QVector <int> x_int;
        for(int j = 0; j < n; j++)
        {
            int xi = x_intersect(i, polygonVertices[j].first, polygonVertices[j].second,  polygonVertices[(j+1) % n].first, polygonVertices[(j+1) % n].second);
            if(xi != 2*r)
            {
                x_int.push_back(xi);
            }
        }
        sort(x_int.begin(), x_int.end());

        for(int j = 0; j < x_int.size(); j++)
        {
            cout << x_int[j] << endl;
        }

        for(int j = 1; j < x_int.size(); j+=2)
        {
            for(int k = x_int[j-1] + 1; k < x_int[j-1]; k++)
                point(x_int[k], i);
        }
    }
}

void MainWindow::on_fill_clicked()
{

    int pos_x = getPixelX(ui->frame->x);
    int pos_y = getPixelY(ui->frame->y);

    if(ui->boundaryFill->isChecked())
    {
        point(pos_x, pos_y, qRgb(0, 0, 0));
        boundaryFill(pos_x, pos_y);
    }
    else if(ui->floodFill->isChecked())
    {
        point(pos_x, pos_y, bgColor);
        floodFill(pos_x, pos_y);
    }
    else if(ui->scanLine->isChecked())
    {
        scanLine();
    }
}
