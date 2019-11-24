/********************************************************************************
** Form generated from reading UI file 'simulator.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMULATOR_H
#define UI_SIMULATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Simulator
{
public:
    QAction *Open;
    QAction *Save;
    QAction *Quit;
    QAction *Run;
    QWidget *centralWidget;
    QTextEdit *Prog;
    QLineEdit *Title;
    QPushButton *Clear;
    QLabel *Acc;
    QLabel *Index;
    QLineEdit *Acc_Val;
    QLineEdit *Index_Val;
    QLabel *Input;
    QLabel *Program;
    QLabel *Register;
    QLabel *Num;
    QLabel *Str;
    QLineEdit *Number;
    QLineEdit *String;
    QLineEdit *Status;
    QLabel *Res;
    QLineEdit *Result;
    QTableWidget *Memory;
    QLabel *label;
    QPushButton *Clear_Mem;
    QTableWidget *Symtab;
    QLabel *label_2;
    QPushButton *Clr_Sym;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuRun;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Simulator)
    {
        if (Simulator->objectName().isEmpty())
            Simulator->setObjectName(QStringLiteral("Simulator"));
        Simulator->resize(846, 509);
        Open = new QAction(Simulator);
        Open->setObjectName(QStringLiteral("Open"));
        Save = new QAction(Simulator);
        Save->setObjectName(QStringLiteral("Save"));
        Quit = new QAction(Simulator);
        Quit->setObjectName(QStringLiteral("Quit"));
        Run = new QAction(Simulator);
        Run->setObjectName(QStringLiteral("Run"));
        QIcon icon;
        QString iconThemeName = QStringLiteral("Run");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        Run->setIcon(icon);
        centralWidget = new QWidget(Simulator);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Prog = new QTextEdit(centralWidget);
        Prog->setObjectName(QStringLiteral("Prog"));
        Prog->setGeometry(QRect(10, 70, 231, 321));
        Title = new QLineEdit(centralWidget);
        Title->setObjectName(QStringLiteral("Title"));
        Title->setGeometry(QRect(40, 20, 781, 22));
        Clear = new QPushButton(centralWidget);
        Clear->setObjectName(QStringLiteral("Clear"));
        Clear->setGeometry(QRect(250, 390, 80, 22));
        Clear->setAutoFillBackground(true);
        Acc = new QLabel(centralWidget);
        Acc->setObjectName(QStringLiteral("Acc"));
        Acc->setGeometry(QRect(270, 90, 81, 16));
        Index = new QLabel(centralWidget);
        Index->setObjectName(QStringLiteral("Index"));
        Index->setGeometry(QRect(270, 120, 71, 16));
        Acc_Val = new QLineEdit(centralWidget);
        Acc_Val->setObjectName(QStringLiteral("Acc_Val"));
        Acc_Val->setGeometry(QRect(350, 90, 113, 22));
        Index_Val = new QLineEdit(centralWidget);
        Index_Val->setObjectName(QStringLiteral("Index_Val"));
        Index_Val->setGeometry(QRect(350, 120, 113, 22));
        Input = new QLabel(centralWidget);
        Input->setObjectName(QStringLiteral("Input"));
        Input->setGeometry(QRect(260, 230, 201, 16));
        Input->setTextFormat(Qt::AutoText);
        Input->setIndent(3);
        Program = new QLabel(centralWidget);
        Program->setObjectName(QStringLiteral("Program"));
        Program->setGeometry(QRect(50, 50, 59, 14));
        Program->setFrameShape(QFrame::NoFrame);
        Program->setFrameShadow(QFrame::Plain);
        Program->setLineWidth(1);
        Register = new QLabel(centralWidget);
        Register->setObjectName(QStringLiteral("Register"));
        Register->setGeometry(QRect(310, 60, 141, 20));
        Register->setFrameShape(QFrame::Box);
        Register->setFrameShadow(QFrame::Raised);
        Register->setLineWidth(2);
        Num = new QLabel(centralWidget);
        Num->setObjectName(QStringLiteral("Num"));
        Num->setGeometry(QRect(270, 270, 61, 21));
        Str = new QLabel(centralWidget);
        Str->setObjectName(QStringLiteral("Str"));
        Str->setGeometry(QRect(260, 310, 61, 16));
        Str->setIndent(3);
        Number = new QLineEdit(centralWidget);
        Number->setObjectName(QStringLiteral("Number"));
        Number->setGeometry(QRect(340, 270, 113, 22));
        String = new QLineEdit(centralWidget);
        String->setObjectName(QStringLiteral("String"));
        String->setGeometry(QRect(340, 310, 113, 22));
        Status = new QLineEdit(centralWidget);
        Status->setObjectName(QStringLiteral("Status"));
        Status->setGeometry(QRect(170, 420, 301, 31));
        Res = new QLabel(centralWidget);
        Res->setObjectName(QStringLiteral("Res"));
        Res->setGeometry(QRect(270, 340, 59, 20));
        Res->setIndent(7);
        Result = new QLineEdit(centralWidget);
        Result->setObjectName(QStringLiteral("Result"));
        Result->setGeometry(QRect(340, 340, 113, 22));
        Memory = new QTableWidget(centralWidget);
        if (Memory->columnCount() < 1)
            Memory->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        Memory->setHorizontalHeaderItem(0, __qtablewidgetitem);
        if (Memory->rowCount() < 20)
            Memory->setRowCount(20);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        Memory->setVerticalHeaderItem(0, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        Memory->setVerticalHeaderItem(1, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        Memory->setVerticalHeaderItem(2, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        Memory->setVerticalHeaderItem(3, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        Memory->setVerticalHeaderItem(4, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        Memory->setVerticalHeaderItem(5, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        Memory->setVerticalHeaderItem(6, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        Memory->setVerticalHeaderItem(7, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        Memory->setVerticalHeaderItem(8, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        Memory->setVerticalHeaderItem(9, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        Memory->setVerticalHeaderItem(10, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        Memory->setVerticalHeaderItem(11, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        Memory->setVerticalHeaderItem(12, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        Memory->setVerticalHeaderItem(13, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        Memory->setVerticalHeaderItem(14, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        Memory->setVerticalHeaderItem(15, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        Memory->setVerticalHeaderItem(16, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        Memory->setVerticalHeaderItem(17, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        Memory->setVerticalHeaderItem(18, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        Memory->setVerticalHeaderItem(19, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        Memory->setItem(0, 0, __qtablewidgetitem21);
        Memory->setObjectName(QStringLiteral("Memory"));
        Memory->setGeometry(QRect(490, 80, 151, 331));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(520, 60, 59, 14));
        Clear_Mem = new QPushButton(centralWidget);
        Clear_Mem->setObjectName(QStringLiteral("Clear_Mem"));
        Clear_Mem->setGeometry(QRect(520, 420, 91, 22));
        Symtab = new QTableWidget(centralWidget);
        if (Symtab->columnCount() < 2)
            Symtab->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        Symtab->setHorizontalHeaderItem(0, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        Symtab->setHorizontalHeaderItem(1, __qtablewidgetitem23);
        if (Symtab->rowCount() < 13)
            Symtab->setRowCount(13);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        Symtab->setVerticalHeaderItem(0, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        Symtab->setVerticalHeaderItem(1, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        Symtab->setVerticalHeaderItem(2, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        Symtab->setVerticalHeaderItem(3, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        Symtab->setVerticalHeaderItem(4, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        Symtab->setVerticalHeaderItem(5, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        Symtab->setVerticalHeaderItem(6, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        Symtab->setVerticalHeaderItem(7, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        Symtab->setVerticalHeaderItem(8, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        Symtab->setVerticalHeaderItem(9, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        Symtab->setVerticalHeaderItem(10, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        Symtab->setVerticalHeaderItem(11, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        Symtab->setVerticalHeaderItem(12, __qtablewidgetitem36);
        Symtab->setObjectName(QStringLiteral("Symtab"));
        Symtab->setGeometry(QRect(650, 130, 221, 201));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(740, 100, 59, 14));
        Clr_Sym = new QPushButton(centralWidget);
        Clr_Sym->setObjectName(QStringLiteral("Clr_Sym"));
        Clr_Sym->setGeometry(QRect(720, 360, 101, 22));
        Simulator->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Simulator);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 846, 19));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuRun = new QMenu(menuBar);
        menuRun->setObjectName(QStringLiteral("menuRun"));
        Simulator->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Simulator);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Simulator->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Simulator);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Simulator->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuRun->menuAction());
        menuFile->addAction(Open);
        menuFile->addAction(Save);
        menuFile->addAction(Quit);
        menuRun->addAction(Run);

        retranslateUi(Simulator);

        QMetaObject::connectSlotsByName(Simulator);
    } // setupUi

    void retranslateUi(QMainWindow *Simulator)
    {
        Simulator->setWindowTitle(QApplication::translate("Simulator", "Simulator", Q_NULLPTR));
        Open->setText(QApplication::translate("Simulator", "Open", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        Open->setShortcut(QApplication::translate("Simulator", "Ctrl+O", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        Save->setText(QApplication::translate("Simulator", "Save", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        Save->setShortcut(QApplication::translate("Simulator", "Ctrl+S", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        Quit->setText(QApplication::translate("Simulator", "Quit", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        Quit->setShortcut(QApplication::translate("Simulator", "Ctrl+Q", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        Run->setText(QApplication::translate("Simulator", "Run", Q_NULLPTR));
        Run->setIconText(QApplication::translate("Simulator", "Run", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        Run->setShortcut(QApplication::translate("Simulator", "Ctrl+R", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        Clear->setText(QApplication::translate("Simulator", "Clear", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        Clear->setShortcut(QApplication::translate("Simulator", "Ctrl+P", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        Acc->setText(QApplication::translate("Simulator", "Accumulator", Q_NULLPTR));
        Index->setText(QApplication::translate("Simulator", "Index Reg", Q_NULLPTR));
        Input->setText(QApplication::translate("Simulator", "        Input for the Program", Q_NULLPTR));
        Program->setText(QApplication::translate("Simulator", "Program", Q_NULLPTR));
        Register->setText(QApplication::translate("Simulator", "    Register Content", Q_NULLPTR));
        Num->setText(QApplication::translate("Simulator", "Number", Q_NULLPTR));
        Str->setText(QApplication::translate("Simulator", "String", Q_NULLPTR));
        Res->setText(QApplication::translate("Simulator", "Result", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = Memory->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Simulator", "Content", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = Memory->verticalHeaderItem(0);
        ___qtablewidgetitem1->setText(QApplication::translate("Simulator", "2000", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = Memory->verticalHeaderItem(1);
        ___qtablewidgetitem2->setText(QApplication::translate("Simulator", "2001", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = Memory->verticalHeaderItem(2);
        ___qtablewidgetitem3->setText(QApplication::translate("Simulator", "2002", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = Memory->verticalHeaderItem(3);
        ___qtablewidgetitem4->setText(QApplication::translate("Simulator", "2003", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = Memory->verticalHeaderItem(4);
        ___qtablewidgetitem5->setText(QApplication::translate("Simulator", "2004", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = Memory->verticalHeaderItem(5);
        ___qtablewidgetitem6->setText(QApplication::translate("Simulator", "2005", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = Memory->verticalHeaderItem(6);
        ___qtablewidgetitem7->setText(QApplication::translate("Simulator", "2006", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = Memory->verticalHeaderItem(7);
        ___qtablewidgetitem8->setText(QApplication::translate("Simulator", "2007", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem9 = Memory->verticalHeaderItem(8);
        ___qtablewidgetitem9->setText(QApplication::translate("Simulator", "2008", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem10 = Memory->verticalHeaderItem(9);
        ___qtablewidgetitem10->setText(QApplication::translate("Simulator", "2009", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem11 = Memory->verticalHeaderItem(10);
        ___qtablewidgetitem11->setText(QApplication::translate("Simulator", "200A", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem12 = Memory->verticalHeaderItem(11);
        ___qtablewidgetitem12->setText(QApplication::translate("Simulator", "200B", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem13 = Memory->verticalHeaderItem(12);
        ___qtablewidgetitem13->setText(QApplication::translate("Simulator", "200C", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem14 = Memory->verticalHeaderItem(13);
        ___qtablewidgetitem14->setText(QApplication::translate("Simulator", "200D", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem15 = Memory->verticalHeaderItem(14);
        ___qtablewidgetitem15->setText(QApplication::translate("Simulator", "200E", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem16 = Memory->verticalHeaderItem(15);
        ___qtablewidgetitem16->setText(QApplication::translate("Simulator", "200F", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem17 = Memory->verticalHeaderItem(16);
        ___qtablewidgetitem17->setText(QApplication::translate("Simulator", "2010", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem18 = Memory->verticalHeaderItem(17);
        ___qtablewidgetitem18->setText(QApplication::translate("Simulator", "2011", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem19 = Memory->verticalHeaderItem(18);
        ___qtablewidgetitem19->setText(QApplication::translate("Simulator", "2012", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem20 = Memory->verticalHeaderItem(19);
        ___qtablewidgetitem20->setText(QApplication::translate("Simulator", "2013", Q_NULLPTR));

        const bool __sortingEnabled = Memory->isSortingEnabled();
        Memory->setSortingEnabled(false);
        Memory->setSortingEnabled(__sortingEnabled);

        label->setText(QApplication::translate("Simulator", "Memory", Q_NULLPTR));
        Clear_Mem->setText(QApplication::translate("Simulator", "Clear Memory", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        Clear_Mem->setShortcut(QApplication::translate("Simulator", "Ctrl+M", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        QTableWidgetItem *___qtablewidgetitem21 = Symtab->horizontalHeaderItem(0);
        ___qtablewidgetitem21->setText(QApplication::translate("Simulator", "Name", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem22 = Symtab->horizontalHeaderItem(1);
        ___qtablewidgetitem22->setText(QApplication::translate("Simulator", "Value", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem23 = Symtab->verticalHeaderItem(0);
        ___qtablewidgetitem23->setText(QApplication::translate("Simulator", "1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem24 = Symtab->verticalHeaderItem(1);
        ___qtablewidgetitem24->setText(QApplication::translate("Simulator", "2", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem25 = Symtab->verticalHeaderItem(2);
        ___qtablewidgetitem25->setText(QApplication::translate("Simulator", "3", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem26 = Symtab->verticalHeaderItem(3);
        ___qtablewidgetitem26->setText(QApplication::translate("Simulator", "4", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem27 = Symtab->verticalHeaderItem(4);
        ___qtablewidgetitem27->setText(QApplication::translate("Simulator", "5", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem28 = Symtab->verticalHeaderItem(5);
        ___qtablewidgetitem28->setText(QApplication::translate("Simulator", "6", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem29 = Symtab->verticalHeaderItem(6);
        ___qtablewidgetitem29->setText(QApplication::translate("Simulator", "7", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem30 = Symtab->verticalHeaderItem(7);
        ___qtablewidgetitem30->setText(QApplication::translate("Simulator", "8", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem31 = Symtab->verticalHeaderItem(8);
        ___qtablewidgetitem31->setText(QApplication::translate("Simulator", "9", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem32 = Symtab->verticalHeaderItem(9);
        ___qtablewidgetitem32->setText(QApplication::translate("Simulator", "10", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem33 = Symtab->verticalHeaderItem(10);
        ___qtablewidgetitem33->setText(QApplication::translate("Simulator", "11", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem34 = Symtab->verticalHeaderItem(11);
        ___qtablewidgetitem34->setText(QApplication::translate("Simulator", "12", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem35 = Symtab->verticalHeaderItem(12);
        ___qtablewidgetitem35->setText(QApplication::translate("Simulator", "13", Q_NULLPTR));
        label_2->setText(QApplication::translate("Simulator", "SYMTAB", Q_NULLPTR));
        Clr_Sym->setText(QApplication::translate("Simulator", "Clear SYMTAB", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        Clr_Sym->setShortcut(QApplication::translate("Simulator", "Ctrl+T", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        menuFile->setTitle(QApplication::translate("Simulator", "File", Q_NULLPTR));
        menuRun->setTitle(QApplication::translate("Simulator", "Build", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Simulator: public Ui_Simulator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMULATOR_H
