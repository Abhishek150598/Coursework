/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <my_label.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    my_label *frame;
    QFrame *x_axis;
    QFrame *y_axis;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_3;
    QLabel *label_3;
    QLabel *mouse_movement;
    QLabel *label_5;
    QLabel *mouse_pressed;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_2;
    QPushButton *set_point1;
    QPushButton *set_point2;
    QGridLayout *gridLayout;
    QRadioButton *parametric;
    QRadioButton *dda;
    QRadioButton *bresenham;
    QWidget *tab_2;
    QWidget *layoutWidget_2;
    QGridLayout *gridLayout_5;
    QRadioButton *parametricCircle;
    QRadioButton *midpointCircle;
    QRadioButton *bresenhamCircle;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout_10;
    QPushButton *setCentre;
    QLabel *label_2;
    QSpinBox *setRadius;
    QWidget *tab_3;
    QWidget *layoutWidget_3;
    QGridLayout *gridLayout_6;
    QRadioButton *midpointEllipse;
    QRadioButton *parametricEllipse;
    QWidget *layoutWidget3;
    QGridLayout *gridLayout_9;
    QPushButton *setCentreEllipse;
    QLabel *label_4;
    QSpinBox *setA;
    QLabel *label_7;
    QSpinBox *setB;
    QWidget *tab_4;
    QWidget *layoutWidget4;
    QGridLayout *gridLayout_7;
    QRadioButton *floodFill;
    QRadioButton *boundaryFill;
    QRadioButton *scanLine;
    QWidget *layoutWidget5;
    QGridLayout *gridLayout_8;
    QPushButton *setStartingPoint;
    QPushButton *setPointPolygon;
    QPushButton *completePolygon;
    QPushButton *fill;
    QWidget *layoutWidget6;
    QGridLayout *gridLayout_13;
    QLabel *label_8;
    QLabel *label_9;
    QComboBox *boundaryColor;
    QComboBox *fillColor;
    QWidget *tab_6;
    QWidget *layoutWidget7;
    QGridLayout *gridLayout_24;
    QLabel *label_6;
    QGridLayout *gridLayout_23;
    QGridLayout *gridLayout_19;
    QLabel *label_14;
    QSpinBox *xmin;
    QGridLayout *gridLayout_20;
    QLabel *label_16;
    QSpinBox *xmax;
    QGridLayout *gridLayout_21;
    QLabel *label_17;
    QSpinBox *ymin;
    QGridLayout *gridLayout_22;
    QLabel *label_18;
    QSpinBox *ymax;
    QWidget *layoutWidget8;
    QGridLayout *gridLayout_25;
    QPushButton *drawWindow;
    QPushButton *lineClipping;
    QPushButton *areaClipping;
    QWidget *tab_5;
    QWidget *layoutWidget_4;
    QGridLayout *gridLayout_15;
    QLabel *label_12;
    QLabel *translate_2;
    QLabel *label_13;
    QDoubleSpinBox *sx;
    QDoubleSpinBox *sy;
    QWidget *layoutWidget_5;
    QGridLayout *gridLayout_16;
    QSpinBox *theta;
    QLabel *label_15;
    QLabel *rotate;
    QWidget *layoutWidget_6;
    QGridLayout *gridLayout_17;
    QLabel *rotate_2;
    QPushButton *reflectpoint_2;
    QPushButton *reflectpoint_1;
    QPushButton *draw_reflection;
    QWidget *layoutWidget9;
    QGridLayout *gridLayout_18;
    QPushButton *reflectX;
    QPushButton *reflectY;
    QWidget *layoutWidget10;
    QGridLayout *gridLayout_14;
    QLabel *translate;
    QSpinBox *ty;
    QLabel *label_11;
    QLabel *label_10;
    QSpinBox *tx;
    QPushButton *translateButton;
    QPushButton *setScalePt;
    QPushButton *scaleButton;
    QPushButton *rotateButton;
    QPushButton *setRotatePt;
    QWidget *layoutWidget_7;
    QGridLayout *gridLayout_26;
    QLabel *label_19;
    QLabel *translate_3;
    QLabel *label_20;
    QDoubleSpinBox *shx;
    QDoubleSpinBox *shy;
    QPushButton *shear;
    QLabel *timeLabel;
    QWidget *layoutWidget11;
    QGridLayout *gridLayout_12;
    QLabel *label;
    QSpinBox *spinBox;
    QWidget *layoutWidget12;
    QGridLayout *gridLayout_11;
    QPushButton *Draw;
    QPushButton *reset;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1017, 677);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        frame = new my_label(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 450, 450));
        frame->setMouseTracking(true);
        frame->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        frame->setFrameShape(QFrame::Box);
        x_axis = new QFrame(centralWidget);
        x_axis->setObjectName(QStringLiteral("x_axis"));
        x_axis->setGeometry(QRect(0, 225, 450, 2));
        x_axis->setStyleSheet(QStringLiteral("background-color: rgb(255, 85, 255);"));
        x_axis->setFrameShape(QFrame::HLine);
        x_axis->setFrameShadow(QFrame::Sunken);
        y_axis = new QFrame(centralWidget);
        y_axis->setObjectName(QStringLiteral("y_axis"));
        y_axis->setGeometry(QRect(225, 0, 2, 450));
        y_axis->setStyleSheet(QLatin1String("\n"
"background-color: rgb(85, 255, 255);"));
        y_axis->setFrameShape(QFrame::VLine);
        y_axis->setFrameShadow(QFrame::Sunken);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(580, 10, 139, 92));
        gridLayout_3 = new QGridLayout(layoutWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_3->addWidget(label_3, 0, 0, 1, 1);

        mouse_movement = new QLabel(layoutWidget);
        mouse_movement->setObjectName(QStringLiteral("mouse_movement"));
        mouse_movement->setFrameShape(QFrame::Panel);

        gridLayout_3->addWidget(mouse_movement, 1, 0, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_3->addWidget(label_5, 2, 0, 1, 1);

        mouse_pressed = new QLabel(layoutWidget);
        mouse_pressed->setObjectName(QStringLiteral("mouse_pressed"));
        mouse_pressed->setFrameShape(QFrame::Panel);

        gridLayout_3->addWidget(mouse_pressed, 3, 0, 1, 1);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(460, 110, 541, 301));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        layoutWidget1 = new QWidget(tab);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 20, 207, 89));
        gridLayout_4 = new QGridLayout(layoutWidget1);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        set_point1 = new QPushButton(layoutWidget1);
        set_point1->setObjectName(QStringLiteral("set_point1"));

        gridLayout_2->addWidget(set_point1, 0, 0, 1, 1);

        set_point2 = new QPushButton(layoutWidget1);
        set_point2->setObjectName(QStringLiteral("set_point2"));

        gridLayout_2->addWidget(set_point2, 1, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout_2, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        parametric = new QRadioButton(layoutWidget1);
        parametric->setObjectName(QStringLiteral("parametric"));

        gridLayout->addWidget(parametric, 0, 0, 1, 1);

        dda = new QRadioButton(layoutWidget1);
        dda->setObjectName(QStringLiteral("dda"));

        gridLayout->addWidget(dda, 1, 0, 1, 1);

        bresenham = new QRadioButton(layoutWidget1);
        bresenham->setObjectName(QStringLiteral("bresenham"));

        gridLayout->addWidget(bresenham, 2, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout, 0, 1, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        layoutWidget_2 = new QWidget(tab_2);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(110, 20, 104, 83));
        gridLayout_5 = new QGridLayout(layoutWidget_2);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        parametricCircle = new QRadioButton(layoutWidget_2);
        parametricCircle->setObjectName(QStringLiteral("parametricCircle"));

        gridLayout_5->addWidget(parametricCircle, 0, 0, 1, 1);

        midpointCircle = new QRadioButton(layoutWidget_2);
        midpointCircle->setObjectName(QStringLiteral("midpointCircle"));

        gridLayout_5->addWidget(midpointCircle, 1, 0, 1, 1);

        bresenhamCircle = new QRadioButton(layoutWidget_2);
        bresenhamCircle->setObjectName(QStringLiteral("bresenhamCircle"));

        gridLayout_5->addWidget(bresenhamCircle, 2, 0, 1, 1);

        layoutWidget2 = new QWidget(tab_2);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 20, 82, 82));
        gridLayout_10 = new QGridLayout(layoutWidget2);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        gridLayout_10->setContentsMargins(0, 0, 0, 0);
        setCentre = new QPushButton(layoutWidget2);
        setCentre->setObjectName(QStringLiteral("setCentre"));

        gridLayout_10->addWidget(setCentre, 0, 0, 1, 1);

        label_2 = new QLabel(layoutWidget2);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_10->addWidget(label_2, 1, 0, 1, 1);

        setRadius = new QSpinBox(layoutWidget2);
        setRadius->setObjectName(QStringLiteral("setRadius"));

        gridLayout_10->addWidget(setRadius, 2, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        layoutWidget_3 = new QWidget(tab_3);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(120, 30, 104, 83));
        gridLayout_6 = new QGridLayout(layoutWidget_3);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        midpointEllipse = new QRadioButton(layoutWidget_3);
        midpointEllipse->setObjectName(QStringLiteral("midpointEllipse"));

        gridLayout_6->addWidget(midpointEllipse, 1, 0, 1, 1);

        parametricEllipse = new QRadioButton(layoutWidget_3);
        parametricEllipse->setObjectName(QStringLiteral("parametricEllipse"));

        gridLayout_6->addWidget(parametricEllipse, 0, 0, 1, 1);

        layoutWidget3 = new QWidget(tab_3);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(20, 30, 82, 91));
        gridLayout_9 = new QGridLayout(layoutWidget3);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        gridLayout_9->setContentsMargins(0, 0, 0, 0);
        setCentreEllipse = new QPushButton(layoutWidget3);
        setCentreEllipse->setObjectName(QStringLiteral("setCentreEllipse"));

        gridLayout_9->addWidget(setCentreEllipse, 0, 0, 1, 2);

        label_4 = new QLabel(layoutWidget3);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_9->addWidget(label_4, 1, 0, 1, 1);

        setA = new QSpinBox(layoutWidget3);
        setA->setObjectName(QStringLiteral("setA"));

        gridLayout_9->addWidget(setA, 1, 1, 1, 1);

        label_7 = new QLabel(layoutWidget3);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_9->addWidget(label_7, 2, 0, 1, 1);

        setB = new QSpinBox(layoutWidget3);
        setB->setObjectName(QStringLiteral("setB"));

        gridLayout_9->addWidget(setB, 2, 1, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        layoutWidget4 = new QWidget(tab_4);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(170, 20, 115, 83));
        gridLayout_7 = new QGridLayout(layoutWidget4);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        floodFill = new QRadioButton(layoutWidget4);
        floodFill->setObjectName(QStringLiteral("floodFill"));

        gridLayout_7->addWidget(floodFill, 0, 0, 1, 1);

        boundaryFill = new QRadioButton(layoutWidget4);
        boundaryFill->setObjectName(QStringLiteral("boundaryFill"));

        gridLayout_7->addWidget(boundaryFill, 1, 0, 1, 1);

        scanLine = new QRadioButton(layoutWidget4);
        scanLine->setObjectName(QStringLiteral("scanLine"));

        gridLayout_7->addWidget(scanLine, 2, 0, 1, 1);

        layoutWidget5 = new QWidget(tab_4);
        layoutWidget5->setObjectName(QStringLiteral("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(0, 20, 161, 131));
        gridLayout_8 = new QGridLayout(layoutWidget5);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        setStartingPoint = new QPushButton(layoutWidget5);
        setStartingPoint->setObjectName(QStringLiteral("setStartingPoint"));

        gridLayout_8->addWidget(setStartingPoint, 0, 0, 1, 1);

        setPointPolygon = new QPushButton(layoutWidget5);
        setPointPolygon->setObjectName(QStringLiteral("setPointPolygon"));

        gridLayout_8->addWidget(setPointPolygon, 1, 0, 1, 1);

        completePolygon = new QPushButton(layoutWidget5);
        completePolygon->setObjectName(QStringLiteral("completePolygon"));

        gridLayout_8->addWidget(completePolygon, 2, 0, 1, 1);

        fill = new QPushButton(layoutWidget5);
        fill->setObjectName(QStringLiteral("fill"));

        gridLayout_8->addWidget(fill, 3, 0, 1, 1);

        layoutWidget6 = new QWidget(tab_4);
        layoutWidget6->setObjectName(QStringLiteral("layoutWidget6"));
        layoutWidget6->setGeometry(QRect(10, 160, 231, 50));
        gridLayout_13 = new QGridLayout(layoutWidget6);
        gridLayout_13->setSpacing(6);
        gridLayout_13->setContentsMargins(11, 11, 11, 11);
        gridLayout_13->setObjectName(QStringLiteral("gridLayout_13"));
        gridLayout_13->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(layoutWidget6);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_13->addWidget(label_8, 0, 0, 1, 1);

        label_9 = new QLabel(layoutWidget6);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_13->addWidget(label_9, 0, 1, 1, 1);

        boundaryColor = new QComboBox(layoutWidget6);
        boundaryColor->setObjectName(QStringLiteral("boundaryColor"));

        gridLayout_13->addWidget(boundaryColor, 1, 0, 1, 1);

        fillColor = new QComboBox(layoutWidget6);
        fillColor->setObjectName(QStringLiteral("fillColor"));

        gridLayout_13->addWidget(fillColor, 1, 1, 1, 1);

        tabWidget->addTab(tab_4, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        layoutWidget7 = new QWidget(tab_6);
        layoutWidget7->setObjectName(QStringLiteral("layoutWidget7"));
        layoutWidget7->setGeometry(QRect(20, 30, 177, 157));
        gridLayout_24 = new QGridLayout(layoutWidget7);
        gridLayout_24->setSpacing(6);
        gridLayout_24->setContentsMargins(11, 11, 11, 11);
        gridLayout_24->setObjectName(QStringLiteral("gridLayout_24"));
        gridLayout_24->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget7);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_24->addWidget(label_6, 0, 0, 1, 1);

        gridLayout_23 = new QGridLayout();
        gridLayout_23->setSpacing(6);
        gridLayout_23->setObjectName(QStringLiteral("gridLayout_23"));
        gridLayout_19 = new QGridLayout();
        gridLayout_19->setSpacing(6);
        gridLayout_19->setObjectName(QStringLiteral("gridLayout_19"));
        label_14 = new QLabel(layoutWidget7);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout_19->addWidget(label_14, 0, 0, 1, 1);

        xmin = new QSpinBox(layoutWidget7);
        xmin->setObjectName(QStringLiteral("xmin"));

        gridLayout_19->addWidget(xmin, 0, 1, 1, 1);


        gridLayout_23->addLayout(gridLayout_19, 0, 0, 1, 1);

        gridLayout_20 = new QGridLayout();
        gridLayout_20->setSpacing(6);
        gridLayout_20->setObjectName(QStringLiteral("gridLayout_20"));
        label_16 = new QLabel(layoutWidget7);
        label_16->setObjectName(QStringLiteral("label_16"));

        gridLayout_20->addWidget(label_16, 0, 0, 1, 1);

        xmax = new QSpinBox(layoutWidget7);
        xmax->setObjectName(QStringLiteral("xmax"));

        gridLayout_20->addWidget(xmax, 0, 1, 1, 1);


        gridLayout_23->addLayout(gridLayout_20, 1, 0, 1, 1);

        gridLayout_21 = new QGridLayout();
        gridLayout_21->setSpacing(6);
        gridLayout_21->setObjectName(QStringLiteral("gridLayout_21"));
        label_17 = new QLabel(layoutWidget7);
        label_17->setObjectName(QStringLiteral("label_17"));

        gridLayout_21->addWidget(label_17, 0, 0, 1, 1);

        ymin = new QSpinBox(layoutWidget7);
        ymin->setObjectName(QStringLiteral("ymin"));

        gridLayout_21->addWidget(ymin, 0, 1, 1, 1);


        gridLayout_23->addLayout(gridLayout_21, 2, 0, 1, 1);

        gridLayout_22 = new QGridLayout();
        gridLayout_22->setSpacing(6);
        gridLayout_22->setObjectName(QStringLiteral("gridLayout_22"));
        label_18 = new QLabel(layoutWidget7);
        label_18->setObjectName(QStringLiteral("label_18"));

        gridLayout_22->addWidget(label_18, 0, 0, 1, 1);

        ymax = new QSpinBox(layoutWidget7);
        ymax->setObjectName(QStringLiteral("ymax"));

        gridLayout_22->addWidget(ymax, 0, 1, 1, 1);


        gridLayout_23->addLayout(gridLayout_22, 3, 0, 1, 1);


        gridLayout_24->addLayout(gridLayout_23, 1, 0, 1, 1);

        layoutWidget8 = new QWidget(tab_6);
        layoutWidget8->setObjectName(QStringLiteral("layoutWidget8"));
        layoutWidget8->setGeometry(QRect(228, 50, 141, 121));
        gridLayout_25 = new QGridLayout(layoutWidget8);
        gridLayout_25->setSpacing(6);
        gridLayout_25->setContentsMargins(11, 11, 11, 11);
        gridLayout_25->setObjectName(QStringLiteral("gridLayout_25"));
        gridLayout_25->setContentsMargins(0, 0, 0, 0);
        drawWindow = new QPushButton(layoutWidget8);
        drawWindow->setObjectName(QStringLiteral("drawWindow"));

        gridLayout_25->addWidget(drawWindow, 0, 0, 1, 1);

        lineClipping = new QPushButton(layoutWidget8);
        lineClipping->setObjectName(QStringLiteral("lineClipping"));

        gridLayout_25->addWidget(lineClipping, 1, 0, 1, 1);

        areaClipping = new QPushButton(layoutWidget8);
        areaClipping->setObjectName(QStringLiteral("areaClipping"));

        gridLayout_25->addWidget(areaClipping, 2, 0, 1, 1);

        tabWidget->addTab(tab_6, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        layoutWidget_4 = new QWidget(tab_5);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(200, 10, 161, 83));
        gridLayout_15 = new QGridLayout(layoutWidget_4);
        gridLayout_15->setSpacing(6);
        gridLayout_15->setContentsMargins(11, 11, 11, 11);
        gridLayout_15->setObjectName(QStringLiteral("gridLayout_15"));
        gridLayout_15->setContentsMargins(0, 0, 0, 0);
        label_12 = new QLabel(layoutWidget_4);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_15->addWidget(label_12, 3, 0, 1, 1);

        translate_2 = new QLabel(layoutWidget_4);
        translate_2->setObjectName(QStringLiteral("translate_2"));

        gridLayout_15->addWidget(translate_2, 0, 0, 1, 1);

        label_13 = new QLabel(layoutWidget_4);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_15->addWidget(label_13, 1, 0, 1, 1);

        sx = new QDoubleSpinBox(layoutWidget_4);
        sx->setObjectName(QStringLiteral("sx"));
        sx->setSingleStep(0.2);
        sx->setValue(1);

        gridLayout_15->addWidget(sx, 1, 1, 1, 1);

        sy = new QDoubleSpinBox(layoutWidget_4);
        sy->setObjectName(QStringLiteral("sy"));
        sy->setSingleStep(0.2);
        sy->setValue(1);

        gridLayout_15->addWidget(sy, 3, 1, 1, 1);

        layoutWidget_5 = new QWidget(tab_5);
        layoutWidget_5->setObjectName(QStringLiteral("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(10, 140, 161, 51));
        gridLayout_16 = new QGridLayout(layoutWidget_5);
        gridLayout_16->setSpacing(6);
        gridLayout_16->setContentsMargins(11, 11, 11, 11);
        gridLayout_16->setObjectName(QStringLiteral("gridLayout_16"));
        gridLayout_16->setContentsMargins(0, 0, 0, 0);
        theta = new QSpinBox(layoutWidget_5);
        theta->setObjectName(QStringLiteral("theta"));
        theta->setMinimum(-360);
        theta->setMaximum(360);
        theta->setSingleStep(5);

        gridLayout_16->addWidget(theta, 1, 1, 1, 1);

        label_15 = new QLabel(layoutWidget_5);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout_16->addWidget(label_15, 1, 0, 1, 1);

        rotate = new QLabel(layoutWidget_5);
        rotate->setObjectName(QStringLiteral("rotate"));

        gridLayout_16->addWidget(rotate, 0, 0, 1, 1);

        layoutWidget_6 = new QWidget(tab_5);
        layoutWidget_6->setObjectName(QStringLiteral("layoutWidget_6"));
        layoutWidget_6->setGeometry(QRect(200, 150, 141, 112));
        gridLayout_17 = new QGridLayout(layoutWidget_6);
        gridLayout_17->setSpacing(6);
        gridLayout_17->setContentsMargins(11, 11, 11, 11);
        gridLayout_17->setObjectName(QStringLiteral("gridLayout_17"));
        gridLayout_17->setContentsMargins(0, 0, 0, 0);
        rotate_2 = new QLabel(layoutWidget_6);
        rotate_2->setObjectName(QStringLiteral("rotate_2"));

        gridLayout_17->addWidget(rotate_2, 0, 0, 1, 1);

        reflectpoint_2 = new QPushButton(layoutWidget_6);
        reflectpoint_2->setObjectName(QStringLiteral("reflectpoint_2"));

        gridLayout_17->addWidget(reflectpoint_2, 2, 0, 1, 1);

        reflectpoint_1 = new QPushButton(layoutWidget_6);
        reflectpoint_1->setObjectName(QStringLiteral("reflectpoint_1"));

        gridLayout_17->addWidget(reflectpoint_1, 1, 0, 1, 1);

        draw_reflection = new QPushButton(layoutWidget_6);
        draw_reflection->setObjectName(QStringLiteral("draw_reflection"));

        gridLayout_17->addWidget(draw_reflection, 3, 0, 1, 1);

        layoutWidget9 = new QWidget(tab_5);
        layoutWidget9->setObjectName(QStringLiteral("layoutWidget9"));
        layoutWidget9->setGeometry(QRect(370, 150, 117, 58));
        gridLayout_18 = new QGridLayout(layoutWidget9);
        gridLayout_18->setSpacing(6);
        gridLayout_18->setContentsMargins(11, 11, 11, 11);
        gridLayout_18->setObjectName(QStringLiteral("gridLayout_18"));
        gridLayout_18->setContentsMargins(0, 0, 0, 0);
        reflectX = new QPushButton(layoutWidget9);
        reflectX->setObjectName(QStringLiteral("reflectX"));

        gridLayout_18->addWidget(reflectX, 0, 0, 1, 1);

        reflectY = new QPushButton(layoutWidget9);
        reflectY->setObjectName(QStringLiteral("reflectY"));

        gridLayout_18->addWidget(reflectY, 1, 0, 1, 1);

        layoutWidget10 = new QWidget(tab_5);
        layoutWidget10->setObjectName(QStringLiteral("layoutWidget10"));
        layoutWidget10->setGeometry(QRect(10, 10, 145, 83));
        gridLayout_14 = new QGridLayout(layoutWidget10);
        gridLayout_14->setSpacing(6);
        gridLayout_14->setContentsMargins(11, 11, 11, 11);
        gridLayout_14->setObjectName(QStringLiteral("gridLayout_14"));
        gridLayout_14->setContentsMargins(0, 0, 0, 0);
        translate = new QLabel(layoutWidget10);
        translate->setObjectName(QStringLiteral("translate"));

        gridLayout_14->addWidget(translate, 0, 0, 1, 1);

        ty = new QSpinBox(layoutWidget10);
        ty->setObjectName(QStringLiteral("ty"));
        ty->setMinimum(-40);
        ty->setMaximum(40);
        ty->setValue(0);

        gridLayout_14->addWidget(ty, 3, 1, 1, 1);

        label_11 = new QLabel(layoutWidget10);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_14->addWidget(label_11, 3, 0, 1, 1);

        label_10 = new QLabel(layoutWidget10);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_14->addWidget(label_10, 1, 0, 1, 1);

        tx = new QSpinBox(layoutWidget10);
        tx->setObjectName(QStringLiteral("tx"));
        tx->setMinimum(-40);
        tx->setMaximum(40);

        gridLayout_14->addWidget(tx, 1, 1, 1, 1);

        translateButton = new QPushButton(tab_5);
        translateButton->setObjectName(QStringLiteral("translateButton"));
        translateButton->setGeometry(QRect(40, 100, 89, 25));
        setScalePt = new QPushButton(tab_5);
        setScalePt->setObjectName(QStringLiteral("setScalePt"));
        setScalePt->setGeometry(QRect(200, 100, 71, 25));
        scaleButton = new QPushButton(tab_5);
        scaleButton->setObjectName(QStringLiteral("scaleButton"));
        scaleButton->setGeometry(QRect(290, 100, 71, 25));
        rotateButton = new QPushButton(tab_5);
        rotateButton->setObjectName(QStringLiteral("rotateButton"));
        rotateButton->setGeometry(QRect(100, 200, 71, 25));
        setRotatePt = new QPushButton(tab_5);
        setRotatePt->setObjectName(QStringLiteral("setRotatePt"));
        setRotatePt->setGeometry(QRect(10, 200, 71, 25));
        layoutWidget_7 = new QWidget(tab_5);
        layoutWidget_7->setObjectName(QStringLiteral("layoutWidget_7"));
        layoutWidget_7->setGeometry(QRect(400, 10, 121, 83));
        gridLayout_26 = new QGridLayout(layoutWidget_7);
        gridLayout_26->setSpacing(6);
        gridLayout_26->setContentsMargins(11, 11, 11, 11);
        gridLayout_26->setObjectName(QStringLiteral("gridLayout_26"));
        gridLayout_26->setContentsMargins(0, 0, 0, 0);
        label_19 = new QLabel(layoutWidget_7);
        label_19->setObjectName(QStringLiteral("label_19"));

        gridLayout_26->addWidget(label_19, 3, 0, 1, 1);

        translate_3 = new QLabel(layoutWidget_7);
        translate_3->setObjectName(QStringLiteral("translate_3"));

        gridLayout_26->addWidget(translate_3, 0, 0, 1, 1);

        label_20 = new QLabel(layoutWidget_7);
        label_20->setObjectName(QStringLiteral("label_20"));

        gridLayout_26->addWidget(label_20, 1, 0, 1, 1);

        shx = new QDoubleSpinBox(layoutWidget_7);
        shx->setObjectName(QStringLiteral("shx"));
        shx->setSingleStep(0.2);
        shx->setValue(1);

        gridLayout_26->addWidget(shx, 1, 1, 1, 1);

        shy = new QDoubleSpinBox(layoutWidget_7);
        shy->setObjectName(QStringLiteral("shy"));
        shy->setSingleStep(0.2);
        shy->setValue(1);

        gridLayout_26->addWidget(shy, 3, 1, 1, 1);

        shear = new QPushButton(tab_5);
        shear->setObjectName(QStringLiteral("shear"));
        shear->setGeometry(QRect(420, 100, 71, 25));
        tabWidget->addTab(tab_5, QString());
        timeLabel = new QLabel(centralWidget);
        timeLabel->setObjectName(QStringLiteral("timeLabel"));
        timeLabel->setGeometry(QRect(530, 420, 181, 21));
        layoutWidget11 = new QWidget(centralWidget);
        layoutWidget11->setObjectName(QStringLiteral("layoutWidget11"));
        layoutWidget11->setGeometry(QRect(460, 10, 113, 51));
        gridLayout_12 = new QGridLayout(layoutWidget11);
        gridLayout_12->setSpacing(6);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        gridLayout_12->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget11);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_12->addWidget(label, 0, 0, 1, 1);

        spinBox = new QSpinBox(layoutWidget11);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setValue(6);

        gridLayout_12->addWidget(spinBox, 1, 0, 1, 1);

        layoutWidget12 = new QWidget(centralWidget);
        layoutWidget12->setObjectName(QStringLiteral("layoutWidget12"));
        layoutWidget12->setGeometry(QRect(570, 450, 82, 58));
        gridLayout_11 = new QGridLayout(layoutWidget12);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        gridLayout_11->setContentsMargins(0, 0, 0, 0);
        Draw = new QPushButton(layoutWidget12);
        Draw->setObjectName(QStringLiteral("Draw"));

        gridLayout_11->addWidget(Draw, 1, 0, 1, 1);

        reset = new QPushButton(layoutWidget12);
        reset->setObjectName(QStringLiteral("reset"));

        gridLayout_11->addWidget(reset, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1017, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(5);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        frame->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "Mouse Movement", Q_NULLPTR));
        mouse_movement->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "Mouse Pressed", Q_NULLPTR));
        mouse_pressed->setText(QString());
        set_point1->setText(QApplication::translate("MainWindow", "Set point 1", Q_NULLPTR));
        set_point2->setText(QApplication::translate("MainWindow", "Set point 2", Q_NULLPTR));
        parametric->setText(QApplication::translate("MainWindow", "Parametric", Q_NULLPTR));
        dda->setText(QApplication::translate("MainWindow", "DDA", Q_NULLPTR));
        bresenham->setText(QApplication::translate("MainWindow", "Bresenham", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Line", Q_NULLPTR));
        parametricCircle->setText(QApplication::translate("MainWindow", "Parametric", Q_NULLPTR));
        midpointCircle->setText(QApplication::translate("MainWindow", "Midpoint", Q_NULLPTR));
        bresenhamCircle->setText(QApplication::translate("MainWindow", "Bresenham", Q_NULLPTR));
        setCentre->setText(QApplication::translate("MainWindow", "Set centre", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Radius", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Circle", Q_NULLPTR));
        midpointEllipse->setText(QApplication::translate("MainWindow", "Midpoint", Q_NULLPTR));
        parametricEllipse->setText(QApplication::translate("MainWindow", "Parametric", Q_NULLPTR));
        setCentreEllipse->setText(QApplication::translate("MainWindow", "Set centre", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "a", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "b", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Ellipse", Q_NULLPTR));
        floodFill->setText(QApplication::translate("MainWindow", "Flood fill", Q_NULLPTR));
        boundaryFill->setText(QApplication::translate("MainWindow", "Boundary fill", Q_NULLPTR));
        scanLine->setText(QApplication::translate("MainWindow", "Scan line", Q_NULLPTR));
        setStartingPoint->setText(QApplication::translate("MainWindow", "Set starting point ", Q_NULLPTR));
        setPointPolygon->setText(QApplication::translate("MainWindow", "Set point ", Q_NULLPTR));
        completePolygon->setText(QApplication::translate("MainWindow", "Complete polygon", Q_NULLPTR));
        fill->setText(QApplication::translate("MainWindow", "Fill", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "Boundary color", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "Fill color", Q_NULLPTR));
        boundaryColor->clear();
        boundaryColor->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Blue", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Red", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Green", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Yellow", Q_NULLPTR)
         << QApplication::translate("MainWindow", "White", Q_NULLPTR)
        );
        fillColor->clear();
        fillColor->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Yellow", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Blue", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Red", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Green", Q_NULLPTR)
         << QApplication::translate("MainWindow", "White", Q_NULLPTR)
        );
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Polygon", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Enter window dimensions", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "xmin", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainWindow", "xmax", Q_NULLPTR));
        label_17->setText(QApplication::translate("MainWindow", "ymin", Q_NULLPTR));
        label_18->setText(QApplication::translate("MainWindow", "ymax", Q_NULLPTR));
        drawWindow->setText(QApplication::translate("MainWindow", "Draw Window", Q_NULLPTR));
        lineClipping->setText(QApplication::translate("MainWindow", "Line clipping", Q_NULLPTR));
        areaClipping->setText(QApplication::translate("MainWindow", "Area clipping", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("MainWindow", "Clipping", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "Along Y-axis", Q_NULLPTR));
        translate_2->setText(QApplication::translate("MainWindow", "Scale", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "Along X-axis", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWindow", "Angle", Q_NULLPTR));
        rotate->setText(QApplication::translate("MainWindow", "Rotate", Q_NULLPTR));
        rotate_2->setText(QApplication::translate("MainWindow", "Reflect", Q_NULLPTR));
        reflectpoint_2->setText(QApplication::translate("MainWindow", "Set Point 2", Q_NULLPTR));
        reflectpoint_1->setText(QApplication::translate("MainWindow", "Set point 1", Q_NULLPTR));
        draw_reflection->setText(QApplication::translate("MainWindow", "Draw reflection", Q_NULLPTR));
        reflectX->setText(QApplication::translate("MainWindow", "Reflect about X", Q_NULLPTR));
        reflectY->setText(QApplication::translate("MainWindow", "Reflect about Y", Q_NULLPTR));
        translate->setText(QApplication::translate("MainWindow", "Translate", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "Along Y-axis", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "Along X-axis", Q_NULLPTR));
        translateButton->setText(QApplication::translate("MainWindow", "Translate", Q_NULLPTR));
        setScalePt->setText(QApplication::translate("MainWindow", "Set pt", Q_NULLPTR));
        scaleButton->setText(QApplication::translate("MainWindow", "Scale", Q_NULLPTR));
        rotateButton->setText(QApplication::translate("MainWindow", "Rotate", Q_NULLPTR));
        setRotatePt->setText(QApplication::translate("MainWindow", "Set pt", Q_NULLPTR));
        label_19->setText(QApplication::translate("MainWindow", "sh-Y", Q_NULLPTR));
        translate_3->setText(QApplication::translate("MainWindow", "Shear", Q_NULLPTR));
        label_20->setText(QApplication::translate("MainWindow", "sh-X", Q_NULLPTR));
        shear->setText(QApplication::translate("MainWindow", "Shear", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MainWindow", "Transformation", Q_NULLPTR));
        timeLabel->setText(QApplication::translate("MainWindow", " Time taken: ", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Change grid size", Q_NULLPTR));
        Draw->setText(QApplication::translate("MainWindow", "Draw", Q_NULLPTR));
        reset->setText(QApplication::translate("MainWindow", "Reset", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
