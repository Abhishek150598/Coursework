#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::drawPolygon()
{
    int i;
    for(i = 1; i < polygonVertices.size(); i++)
    {
        p1.setX(polygonVertices[i-1].first);
        p1.setY(polygonVertices[i-1].second);
        p2.setX(polygonVertices[i].first);
        p2.setY(polygonVertices[i].second);
        drawBresenham();
    }
    p1.setX(polygonVertices[i-1].first);
    p1.setY(polygonVertices[i-1].second);
    p2.setX(polygonVertices[0].first);
    p2.setY(polygonVertices[0].second);
    drawBresenham();
}

void MainWindow::translate(int tx, int ty)
{
    for(int i = 0; i < polygonVertices.size(); i++)
    {
        int x = polygonVertices[i].first + tx;
        int y = polygonVertices[i].second + ty;
        polygonVertices[i] = qMakePair(x, y);

   }
    resetCanvas();
    drawPolygon();
}

void MainWindow::scale(float sx, float sy)
{
    for(int i = 0; i < polygonVertices.size(); i++)
    {
        int x = round((float)polygonVertices[i].first * sx);
        int y = round((float)polygonVertices[i].second * sy);
        polygonVertices[i] = qMakePair(x, y);

   }
   resetCanvas();
   drawPolygon();
}

void MainWindow::rotate(float theta)
{
    for(int i = 0; i < polygonVertices.size(); i++)
    {

        float x = (float)polygonVertices[i].first;
        float y = (float)polygonVertices[i].second;
        int x1 = round(x * cos(theta) - y * sin(theta));
        int y1 = round(x * sin(theta) + y * cos(theta));
        polygonVertices[i] = qMakePair(x1, y1);
    }
    resetCanvas();
    drawPolygon();
}

void MainWindow::reflectX()
{
    for(int i = 0; i < polygonVertices.size(); i++)
    {
        int x = polygonVertices[i].first;
        int y = -polygonVertices[i].second;
        polygonVertices[i] = qMakePair(x, y);

   }
    resetCanvas();
    drawPolygon();
}

void MainWindow::reflectY()
{
    for(int i = 0; i < polygonVertices.size(); i++)
    {
        int x = -polygonVertices[i].first;
        int y = polygonVertices[i].second;
        polygonVertices[i] = qMakePair(x, y);

   }
    resetCanvas();
    drawPolygon();
}

void MainWindow::on_tx_valueChanged(int arg1)
{
    tx = arg1;
}

void MainWindow::on_ty_valueChanged(int arg1)
{
    ty = arg1;
}


void MainWindow::on_sx_valueChanged(double arg1)
{
    sx = arg1;
}

void MainWindow::on_sy_valueChanged(double arg1)
{
    sy = arg1;
}

void MainWindow::on_translateButton_clicked()
{
    translate(tx, ty);
}


void MainWindow::on_setScalePt_clicked()
{
    scalePt.setX(getPixelX(ui->frame->x));
    scalePt.setY(getPixelY(ui->frame->y));
}

void MainWindow::on_scaleButton_clicked()
{
    translate(-scalePt.x(), -scalePt.y());
    scale(sx, sy);
    translate(scalePt.x(), scalePt.y());
}


void MainWindow::on_theta_valueChanged(int arg1)
{
    theta = arg1;
}

void MainWindow::on_setRotatePt_clicked()
{
    rotatePt.setX(getPixelX(ui->frame->x));
    rotatePt.setY(getPixelY(ui->frame->y));
}

void MainWindow::on_rotateButton_clicked()
{
    translate(-rotatePt.x(), -rotatePt.y());
    rotate(PI * (theta) / 180);
    translate(rotatePt.x(), rotatePt.y());
}

void MainWindow::on_reflectX_clicked()
{
    reflectX();
}

void MainWindow::on_reflectY_clicked()
{
    reflectY();
}

void MainWindow::on_reflectpoint_1_clicked()
{
    p1.setX(getPixelX(ui->frame->x));
    p1.setY(getPixelY(ui->frame->y));
    cout << p1.x() << " " << p1.y() << endl;
}

void MainWindow::on_reflectpoint_2_clicked()
{
    p2.setX(getPixelX(ui->frame->x));
    p2.setY(getPixelY(ui->frame->y));
    drawBresenham();
}

void MainWindow::on_draw_reflection_clicked()
{
    QPoint p_1 = p1, p_2 = p2;
    double m = (double)(p2.y() - p1.y()) / (double)(p2.x() - p1.x());
    int c = p2.y() - m * p2.x();
    double th = atan(m);
    translate(0, -c);
    rotate(-th);
    reflectX();
    rotate(th);
    translate(0, c);
    p1 = p_1;
    p2 = p_2;
    drawBresenham();
}

void MainWindow::shear(float shx, float shy)
{
    for(int i = 0; i < polygonVertices.size(); i++)
    {
        int x = round((float)polygonVertices[i].first + (float)polygonVertices[i].second * shx);
        int y = round((float)polygonVertices[i].second + (float)polygonVertices[i].first * shy);
        polygonVertices[i] = qMakePair(x, y);

   }
   resetCanvas();
   drawPolygon();
}

void MainWindow::on_shx_valueChanged(double arg1)
{
    shx = arg1;
}

void MainWindow::on_shy_valueChanged(double arg1)
{
    shy = arg1;
}

void MainWindow::on_shear_clicked()
{
    shear(shx, shy);
}



