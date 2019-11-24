#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->x_axis->hide();
    ui->y_axis->hide();
    connect(ui->frame, SIGNAL(Mouse_Pos()), this, SLOT(Mouse_Pressed()));
    connect(ui->frame, SIGNAL(sendMousePosition(QPoint&)), this, SLOT(showMousePosition(QPoint&)));
    img = QImage(450,450,QImage::Format_RGB888);
    tabIndex = 4;
    gridSize = 6;
    r = 37;
    tx = 0;
    ty = 0;
    sx = 1.0;
    sy = 1.0;
    shx = 0.0;
    shy = 0.0;
    scalePt.setX(0);
    scalePt.setY(0);
    rotatePt.setX(0);
    rotatePt.setY(0);
    theta = 0.0;
    boundaryColor = qRgb(0, 0, 255);
    fillColor = qRgb(255, 255, 0);
    bgColor = qRgb(0, 0, 0);
    ui->tx->setRange(-r, r);
    ui->ty->setRange(-r, r);
    ui->xmin->setRange(-r, r);
    ui->ymin->setRange(-r, r);
    ui->xmax->setRange(-r, r);
    ui->ymax->setRange(-r, r);
    resetCanvas();
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Function to reset the canvas
void MainWindow::resetCanvas()
{
    img.fill(qRgb(0,0,0));
    drawGrid();
    drawAxis();
    ui->frame->setPixmap(QPixmap::fromImage(img));
}

// Function to draw the grid
void MainWindow::drawGrid()
{
    for(int i = 0; i < 450; i++)
    {
        for(int j = 0; j < 450; j += gridSize)
        {
            img.setPixel(i, j, qRgba(0, 253, 0, 60)); // Horizontal grid
            img.setPixel(j, i, qRgba(0, 253, 0, 60)); // Vertical grid
        }
    }

}

// Function to draw the X and Y axes
void MainWindow::drawAxis()
{
    for(int i = -r; i <= r; i++)
    {
        point(i, 0, qRgb(252, 0, 0)); // X axis
        point(0, i, qRgb(252, 0, 0)); // Y axis
    }
}

// Coordinate transformation function for X
int MainWindow::getPixelX(int x)
{
    int px = (x / gridSize) - r;
    return px;

}

// Coordinate transformation function for Y
int MainWindow::getPixelY(int y)
{
    int py = r - (y / gridSize);
    return py;
}

// Coordinate back-transformation function for X
int MainWindow::getCoordX(int px)
{
    int x = (px + r) * gridSize;
    return x;
}

// Coordinate back-transformation function for Y
int MainWindow::getCoordY(int py)
{
    int y = (r - py) * gridSize;
    return y;
}

// Function that plots a point at coordinate px, py
void MainWindow::point(int px,int py, QColor color)
{
    int x_left = getCoordX(px);
    int y_top = getCoordY(py);
    for(int i = x_left; i < x_left + gridSize; i++)
    {
        for(int j = y_top; j < y_top + gridSize; j++)
        {
            img.setPixelColor(i, j, color);
        }
    }
    ui->frame->setPixmap(QPixmap::fromImage(img));
}

// Function to show mouse hover coordinates
void MainWindow::showMousePosition(QPoint &pos)
{
    ui->mouse_movement->setText(" X : "+QString::number(getPixelX(pos.x()))+", Y : "+QString::number(getPixelY(pos.y())));
}

// Function to show mouse click coordinates
void MainWindow::Mouse_Pressed()
{
    int px = getPixelX(ui->frame->x);
    int py = getPixelY(ui->frame->y);
    bgColor = getBgColor(px, py);
    ui->mouse_pressed->setText(" X : "+QString::number(px)+", Y : "+QString::number(py));
    point(px, py, fillColor);
}

QColor MainWindow::getBgColor(int pos_x, int pos_y)
{
    int x = getCoordX(pos_x) + gridSize / 2;
    int y = getCoordY(pos_y) + gridSize / 2;
    return img.pixelColor(x, y);
}

// Function to draw on canvas
void MainWindow::on_Draw_clicked()
{
    clock_t begin = clock();
    if(tabIndex == 0)
    {

        if(ui->parametric->isChecked())
        {
            lines.push_back(qMakePair(p1, p2));
            drawParametric();
        }
        else if(ui->dda->isChecked())
        {
            lines.push_back(qMakePair(p1, p2));
            drawDDA();
        }
        else if(ui->bresenham->isChecked())
        {
            lines.push_back(qMakePair(p1, p2));
            drawBresenham();
        }

    }
    else if(tabIndex == 1)
    {
        if(ui->parametricCircle->isChecked())
        {
            drawParametricCircle();
        }
        else if(ui->midpointCircle->isChecked())
        {
            drawMidpointCircle();
        }
        else if(ui->bresenhamCircle->isChecked())
        {
            drawBresenhamCircle();
        }
    }
    else if(tabIndex == 2)
    {
        if(ui->parametricEllipse->isChecked())
        {
            drawParametricEllipse();
        }
        else if(ui->midpointEllipse->isChecked())
        {
            drawMidpointEllipse();
        }
    }

    clock_t end = clock();
    double time_spent = 0.0;
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    ui->timeLabel->setText(" Time taken: " + QString::number(time_spent));

}

// Function to change grid size
void MainWindow::on_spinBox_valueChanged(int arg1)
{
    gridSize = (int)arg1;
    r = 450 / (2 * gridSize);
    ui->tx->setRange(-r, r);
    ui->ty->setRange(-r, r);
    ui->xmin->setRange(-r, r);
    ui->ymin->setRange(-r, r);
    ui->xmax->setRange(-r, r);
    ui->ymax->setRange(-r, r);
    lines.clear();
    polygonVertices.clear();
    bez.clear();
    resetCanvas();
}


void MainWindow::on_tabWidget_tabBarClicked(int index)
{
    tabIndex = index;
}



void MainWindow::on_reset_clicked()
{
    lines.clear();
    polygonVertices.clear();
    bez.clear();
    resetCanvas();
}

void MainWindow::on_boundaryColor_activated(const QString &arg1)
{
    if(arg1 == "Blue")
        boundaryColor = qRgb(0, 0, 255);
    if(arg1 == "Red")
        boundaryColor = qRgb(255, 0, 0);
    if(arg1 == "Green")
        boundaryColor = qRgb(0, 255, 0);
    if(arg1 == "Yellow")
        boundaryColor = qRgb(255, 255, 0);
    if(arg1 == "White")
        boundaryColor = qRgb(255, 255, 255);

}


void MainWindow::on_fillColor_activated(const QString &arg1)
{
    if(arg1 == "Blue")
        fillColor = qRgb(0, 0, 255);
    if(arg1 == "Red")
        fillColor = qRgb(255, 0, 0);
    if(arg1 == "Green")
        fillColor = qRgb(0, 255, 0);
    if(arg1 == "Yellow")
        fillColor = qRgb(255, 255, 0);
    if(arg1 == "White")
        fillColor = qRgb(255, 255, 255);
}

















