/********************************************************************************
** Form generated from reading UI file 'editor.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITOR_H
#define UI_EDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include <dropouttoolbutton.h>
#include <routepropertyview.h>
#include <screenview.h>
#include <targetpropertyview.h>

QT_BEGIN_NAMESPACE

class Ui_Editor
{
public:
    QAction *edit_route_point_tool;
    QAction *add_route_point_tool;
    QAction *delete_route_point_tool;
    QAction *save_command;
    QAction *load_command;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QSplitter *VerticalSplitter;
    ScreenView *ScreenViewW;
    QSplitter *HorizontalSplitter;
    TargetPropertyView *TargetPropertyViewW;
    QToolButton *zoom_all_command;
    QToolButton *default_tool;
    QToolButton *add_ship_tool;
    QToolButton *rotate_tool;
    QToolButton *add_route_tool;
    DropOutToolButton *edit_route_tool;
    QToolButton *move_tool;
    QToolButton *delete_ship_tool;
    QToolButton *delete_route_command;
    RoutePropertyView *RoutePropertyViewW;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *Editor)
    {
        if (Editor->objectName().isEmpty())
            Editor->setObjectName(QStringLiteral("Editor"));
        Editor->setWindowModality(Qt::ApplicationModal);
        Editor->setEnabled(true);
        Editor->resize(1580, 1086);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Editor->sizePolicy().hasHeightForWidth());
        Editor->setSizePolicy(sizePolicy);
        Editor->setStyleSheet(QStringLiteral("background-color:rgb(30, 33, 39);"));
        edit_route_point_tool = new QAction(Editor);
        edit_route_point_tool->setObjectName(QStringLiteral("edit_route_point_tool"));
        edit_route_point_tool->setCheckable(true);
        QIcon icon;
        icon.addFile(QStringLiteral(":/toolButton/res/edit_route_tool.png"), QSize(), QIcon::Normal, QIcon::Off);
        edit_route_point_tool->setIcon(icon);
        QFont font;
        font.setFamily(QStringLiteral("Bahnschrift Light Condensed"));
        font.setPointSize(11);
        edit_route_point_tool->setFont(font);
        add_route_point_tool = new QAction(Editor);
        add_route_point_tool->setObjectName(QStringLiteral("add_route_point_tool"));
        add_route_point_tool->setCheckable(true);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/toolButton/res/add_route_point_tool.png"), QSize(), QIcon::Normal, QIcon::Off);
        add_route_point_tool->setIcon(icon1);
        add_route_point_tool->setFont(font);
        delete_route_point_tool = new QAction(Editor);
        delete_route_point_tool->setObjectName(QStringLiteral("delete_route_point_tool"));
        delete_route_point_tool->setCheckable(true);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/toolButton/res/delete_route_point.png"), QSize(), QIcon::Normal, QIcon::Off);
        delete_route_point_tool->setIcon(icon2);
        delete_route_point_tool->setFont(font);
        save_command = new QAction(Editor);
        save_command->setObjectName(QStringLiteral("save_command"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/ToolBarIcons/add_route.png"), QSize(), QIcon::Normal, QIcon::Off);
        save_command->setIcon(icon3);
        save_command->setFont(font);
        load_command = new QAction(Editor);
        load_command->setObjectName(QStringLiteral("load_command"));
        centralwidget = new QWidget(Editor);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 5, 0);
        VerticalSplitter = new QSplitter(centralwidget);
        VerticalSplitter->setObjectName(QStringLiteral("VerticalSplitter"));
        VerticalSplitter->setOrientation(Qt::Horizontal);
        VerticalSplitter->setHandleWidth(5);
        ScreenViewW = new ScreenView(VerticalSplitter);
        ScreenViewW->setObjectName(QStringLiteral("ScreenViewW"));
        sizePolicy.setHeightForWidth(ScreenViewW->sizePolicy().hasHeightForWidth());
        ScreenViewW->setSizePolicy(sizePolicy);
        ScreenViewW->setMinimumSize(QSize(1000, 1000));
        ScreenViewW->setStyleSheet(QLatin1String("background-color:rgb(40, 44, 52);\n"
""));
        VerticalSplitter->addWidget(ScreenViewW);
        HorizontalSplitter = new QSplitter(VerticalSplitter);
        HorizontalSplitter->setObjectName(QStringLiteral("HorizontalSplitter"));
        HorizontalSplitter->setOrientation(Qt::Vertical);
        HorizontalSplitter->setHandleWidth(5);
        TargetPropertyViewW = new TargetPropertyView(HorizontalSplitter);
        TargetPropertyViewW->setObjectName(QStringLiteral("TargetPropertyViewW"));
        TargetPropertyViewW->setMinimumSize(QSize(360, 360));
        TargetPropertyViewW->setMaximumSize(QSize(360, 16777215));
        TargetPropertyViewW->setAutoFillBackground(false);
        TargetPropertyViewW->setStyleSheet(QLatin1String("QFrame\n"
"{\n"
"  border: 5px solid black;\n"
"}"));
        zoom_all_command = new QToolButton(TargetPropertyViewW);
        zoom_all_command->setObjectName(QStringLiteral("zoom_all_command"));
        zoom_all_command->setGeometry(QRect(320, 10, 35, 35));
        zoom_all_command->setMinimumSize(QSize(35, 35));
        zoom_all_command->setStyleSheet(QLatin1String("QAbstractButton::hover\n"
"{\n"
"	border: 2px solid rgb(2, 191, 150);\n"
"	border-radius: 6px;\n"
"}\n"
"\n"
"QToolButton:checked\n"
"{\n"
"	border: 2px solid rgb(215, 2, 64);\n"
"	border-radius: 6px;\n"
"}\n"
"\n"
"QToolButton:pressed\n"
"{\n"
"	border: 2px solid rgb(215, 2, 64);\n"
"	border-radius: 6px;\n"
"}"));
        zoom_all_command->setCheckable(false);
        default_tool = new QToolButton(TargetPropertyViewW);
        default_tool->setObjectName(QStringLiteral("default_tool"));
        default_tool->setGeometry(QRect(0, 10, 35, 35));
        default_tool->setMinimumSize(QSize(35, 35));
        default_tool->setStyleSheet(QLatin1String("QAbstractButton::hover\n"
"{\n"
"	border: 2px solid rgb(2, 191, 150);\n"
"	border-radius: 6px;\n"
"}\n"
"\n"
"QToolButton:checked\n"
"{\n"
"	border: 2px solid rgb(215, 2, 64);\n"
"	border-radius: 6px;\n"
"}\n"
"\n"
"QToolButton:pressed\n"
"{\n"
"	border: 2px solid rgb(215, 2, 64);\n"
"	border-radius: 6px;\n"
"}"));
        default_tool->setCheckable(false);
        add_ship_tool = new QToolButton(TargetPropertyViewW);
        add_ship_tool->setObjectName(QStringLiteral("add_ship_tool"));
        add_ship_tool->setGeometry(QRect(120, 10, 35, 35));
        add_ship_tool->setMinimumSize(QSize(35, 35));
        add_ship_tool->setStyleSheet(QLatin1String("QAbstractButton::hover\n"
"{\n"
"	border: 2px solid rgb(2, 191, 150);\n"
"	border-radius: 6px;\n"
"}\n"
"\n"
"QToolButton:checked\n"
"{\n"
"	border: 2px solid rgb(215, 2, 64);\n"
"	border-radius: 6px;\n"
"}\n"
"\n"
"QToolButton:pressed\n"
"{\n"
"	border: 2px solid rgb(215, 2, 64);\n"
"	border-radius: 6px;\n"
"}"));
        add_ship_tool->setCheckable(true);
        rotate_tool = new QToolButton(TargetPropertyViewW);
        rotate_tool->setObjectName(QStringLiteral("rotate_tool"));
        rotate_tool->setGeometry(QRect(80, 10, 35, 35));
        rotate_tool->setMinimumSize(QSize(35, 35));
        rotate_tool->setStyleSheet(QLatin1String("QAbstractButton::hover\n"
"{\n"
"	border: 2px solid rgb(2, 191, 150);\n"
"	border-radius: 6px;\n"
"}\n"
"\n"
"QToolButton:checked\n"
"{\n"
"	border: 2px solid rgb(215, 2, 64);\n"
"	border-radius: 6px;\n"
"}\n"
"\n"
"QToolButton:pressed\n"
"{\n"
"	border: 2px solid rgb(215, 2, 64);\n"
"	border-radius: 6px;\n"
"}"));
        rotate_tool->setCheckable(true);
        add_route_tool = new QToolButton(TargetPropertyViewW);
        add_route_tool->setObjectName(QStringLiteral("add_route_tool"));
        add_route_tool->setGeometry(QRect(200, 10, 35, 35));
        add_route_tool->setMinimumSize(QSize(35, 35));
        add_route_tool->setStyleSheet(QLatin1String("QAbstractButton::hover\n"
"{\n"
"	border: 2px solid rgb(2, 191, 150);\n"
"	border-radius: 6px;\n"
"}\n"
"\n"
"QToolButton:checked\n"
"{\n"
"	border: 2px solid rgb(215, 2, 64);\n"
"	border-radius: 6px;\n"
"}\n"
"\n"
"QToolButton:pressed\n"
"{\n"
"	border: 2px solid rgb(215, 2, 64);\n"
"	border-radius: 6px;\n"
"}"));
        add_route_tool->setCheckable(true);
        edit_route_tool = new DropOutToolButton(TargetPropertyViewW);
        edit_route_tool->setObjectName(QStringLiteral("edit_route_tool"));
        edit_route_tool->setGeometry(QRect(280, 10, 35, 35));
        edit_route_tool->setMinimumSize(QSize(35, 35));
        edit_route_tool->setStyleSheet(QLatin1String("QAbstractButton:hover\n"
"{\n"
"    border: 2px solid rgb(2, 191, 150);\n"
"	border-radius: 6px;\n"
"}\n"
"\n"
"QToolButton\n"
"{\n"
"	background-color:rgb(30, 33, 39);\n"
"}\n"
"\n"
"QToolButton::menu-indicator\n"
"{\n"
"   width:0px;\n"
"}\n"
"\n"
"QToolButton QAbstractItemView {\n"
"   background-color:rgb(30, 33, 39);\n"
"   background: transparent;\n"
"}\n"
"\n"
"QToolButton:checked\n"
"{\n"
"	border: 2px solid rgb(215, 2, 64);\n"
"	border-radius: 6px;\n"
"}\n"
"\n"
"QToolButton:pressed\n"
"{\n"
"	border: 2px solid rgb(215, 2, 64);\n"
"	border-radius: 6px;\n"
"}\n"
""));
        edit_route_tool->setCheckable(true);
        edit_route_tool->setPopupMode(QToolButton::InstantPopup);
        edit_route_tool->setArrowType(Qt::NoArrow);
        move_tool = new QToolButton(TargetPropertyViewW);
        move_tool->setObjectName(QStringLiteral("move_tool"));
        move_tool->setGeometry(QRect(40, 10, 35, 35));
        move_tool->setMinimumSize(QSize(35, 35));
        move_tool->setStyleSheet(QLatin1String("QAbstractButton::hover\n"
"{\n"
"	border: 2px solid rgb(2, 191, 150);\n"
"	border-radius: 6px;\n"
"}\n"
"\n"
"QToolButton:checked\n"
"{\n"
"	border: 2px solid rgb(215, 2, 64);\n"
"	border-radius: 6px;\n"
"}\n"
"\n"
"QToolButton:pressed\n"
"{\n"
"	border: 2px solid rgb(215, 2, 64);\n"
"	border-radius: 6px;\n"
"}"));
        move_tool->setCheckable(true);
        delete_ship_tool = new QToolButton(TargetPropertyViewW);
        delete_ship_tool->setObjectName(QStringLiteral("delete_ship_tool"));
        delete_ship_tool->setGeometry(QRect(160, 10, 35, 35));
        delete_ship_tool->setMinimumSize(QSize(35, 35));
        delete_ship_tool->setStyleSheet(QLatin1String("QAbstractButton::hover\n"
"{\n"
"	border: 2px solid rgb(2, 191, 150);\n"
"	border-radius: 6px;\n"
"}\n"
"\n"
"QToolButton:checked\n"
"{\n"
"	border: 2px solid rgb(215, 2, 64);\n"
"	border-radius: 6px;\n"
"}\n"
"\n"
"QToolButton:pressed\n"
"{\n"
"	border: 2px solid rgb(215, 2, 64);\n"
"	border-radius: 6px;\n"
"}"));
        delete_ship_tool->setCheckable(true);
        delete_route_command = new QToolButton(TargetPropertyViewW);
        delete_route_command->setObjectName(QStringLiteral("delete_route_command"));
        delete_route_command->setGeometry(QRect(240, 10, 35, 35));
        delete_route_command->setMinimumSize(QSize(35, 35));
        delete_route_command->setStyleSheet(QLatin1String("QAbstractButton::hover\n"
"{\n"
"	border: 2px solid rgb(2, 191, 150);\n"
"	border-radius: 6px;\n"
"}\n"
"\n"
"QToolButton:checked\n"
"{\n"
"	border: 2px solid rgb(215, 2, 64);\n"
"	border-radius: 6px;\n"
"}\n"
"\n"
"QToolButton:pressed\n"
"{\n"
"	border: 2px solid rgb(215, 2, 64);\n"
"	border-radius: 6px;\n"
"}"));
        delete_route_command->setCheckable(false);
        HorizontalSplitter->addWidget(TargetPropertyViewW);
        RoutePropertyViewW = new RoutePropertyView(HorizontalSplitter);
        RoutePropertyViewW->setObjectName(QStringLiteral("RoutePropertyViewW"));
        RoutePropertyViewW->setMinimumSize(QSize(360, 333));
        RoutePropertyViewW->setMaximumSize(QSize(360, 16777215));
        RoutePropertyViewW->setAutoFillBackground(false);
        RoutePropertyViewW->setStyleSheet(QStringLiteral("border: 1px solid black;"));
        HorizontalSplitter->addWidget(RoutePropertyViewW);
        VerticalSplitter->addWidget(HorizontalSplitter);

        horizontalLayout->addWidget(VerticalSplitter);

        Editor->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Editor);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1580, 33));
        menubar->setFont(font);
        menubar->setStyleSheet(QLatin1String("QMenuBar\n"
" {\n"
"    background-color:rgb(30, 33, 39);\n"
"	color:rgb(255, 255, 255);\n"
"}\n"
"\n"
"QMenuBar::item \n"
"{\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"QMenuBar::item:selected\n"
"{\n"
"    border:2px solid rgb(2, 191, 150);\n"
"	border-radius: 6px;\n"
"	color:rgb(255, 255, 255);\n"
"}"));
        menu = new QMenu(menubar);
        menu->setObjectName(QStringLiteral("menu"));
        menu->setFont(font);
        menu->setStyleSheet(QLatin1String("QMenu\n"
" {\n"
"    background-color:rgb(30, 33, 39);\n"
"}\n"
"\n"
"QMenu::item \n"
"{\n"
"    background-color: transparent;\n"
"	padding-left: 30px;\n"
"	padding-right: 15px;\n"
"	padding-top: 3px;\n"
"	padding-bottom: 3px;\n"
"	color:rgb(255, 255, 255);\n"
"}\n"
"\n"
"QMenu::item:selected\n"
"{\n"
"	border:2px solid rgb(2, 191, 150);\n"
"	border-radius: 6px;\n"
"	color:rgb(255, 255, 255);\n"
"} "));
        Editor->setMenuBar(menubar);
        statusbar = new QStatusBar(Editor);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        statusbar->setFont(font);
        statusbar->setStyleSheet(QStringLiteral("color:rgb(255, 255, 255);"));
        Editor->setStatusBar(statusbar);
        toolBar = new QToolBar(Editor);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setMinimumSize(QSize(35, 0));
        toolBar->setMovable(false);
        toolBar->setAllowedAreas(Qt::LeftToolBarArea);
        Editor->addToolBar(Qt::LeftToolBarArea, toolBar);

        menubar->addAction(menu->menuAction());
        menu->addAction(save_command);
        menu->addAction(load_command);

        retranslateUi(Editor);

        QMetaObject::connectSlotsByName(Editor);
    } // setupUi

    void retranslateUi(QMainWindow *Editor)
    {
        Editor->setWindowTitle(QApplication::translate("Editor", "Editor", 0));
        edit_route_point_tool->setText(QApplication::translate("Editor", "\321\200\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \321\202\320\276\321\207\320\272\321\203", 0));
        edit_route_point_tool->setIconText(QApplication::translate("Editor", "\321\200\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \321\202\320\276\321\207\320\272\321\203", 0));
        add_route_point_tool->setText(QApplication::translate("Editor", "\320\264\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\202\320\276\321\207\320\272\321\203", 0));
        delete_route_point_tool->setText(QApplication::translate("Editor", "\321\203\320\264\320\260\320\273\320\270\321\202\321\214 \321\202\320\276\321\207\320\272\321\203", 0));
        save_command->setText(QApplication::translate("Editor", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", 0));
        load_command->setText(QApplication::translate("Editor", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", 0));
        zoom_all_command->setText(QApplication::translate("Editor", "...", 0));
        default_tool->setText(QApplication::translate("Editor", "...", 0));
        add_ship_tool->setText(QApplication::translate("Editor", "...", 0));
        rotate_tool->setText(QApplication::translate("Editor", "...", 0));
        add_route_tool->setText(QApplication::translate("Editor", "...", 0));
        edit_route_tool->setText(QApplication::translate("Editor", "...", 0));
        move_tool->setText(QApplication::translate("Editor", "...", 0));
        delete_ship_tool->setText(QApplication::translate("Editor", "...", 0));
        delete_route_command->setText(QApplication::translate("Editor", "...", 0));
        menu->setTitle(QApplication::translate("Editor", "\320\241\321\206\320\265\320\275\320\260\321\200\320\270\320\271", 0));
        toolBar->setWindowTitle(QApplication::translate("Editor", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class Editor: public Ui_Editor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITOR_H
