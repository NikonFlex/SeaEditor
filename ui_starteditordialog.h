/********************************************************************************
** Form generated from reading UI file 'starteditordialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTEDITORDIALOG_H
#define UI_STARTEDITORDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartEditorDialog
{
public:
    QWidget *centralwidget;
    QListWidget *scenarios_widget;
    QPushButton *edit_scenario_button;
    QPushButton *delete_scenario_button;
    QPushButton *create_scenario_button;

    void setupUi(QMainWindow *StartEditorDialog)
    {
        if (StartEditorDialog->objectName().isEmpty())
            StartEditorDialog->setObjectName(QStringLiteral("StartEditorDialog"));
        StartEditorDialog->resize(800, 600);
        centralwidget = new QWidget(StartEditorDialog);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        scenarios_widget = new QListWidget(centralwidget);
        scenarios_widget->setObjectName(QStringLiteral("scenarios_widget"));
        scenarios_widget->setGeometry(QRect(300, 20, 200, 100));
        edit_scenario_button = new QPushButton(centralwidget);
        edit_scenario_button->setObjectName(QStringLiteral("edit_scenario_button"));
        edit_scenario_button->setGeometry(QRect(300, 140, 201, 31));
        delete_scenario_button = new QPushButton(centralwidget);
        delete_scenario_button->setObjectName(QStringLiteral("delete_scenario_button"));
        delete_scenario_button->setGeometry(QRect(300, 180, 201, 31));
        create_scenario_button = new QPushButton(centralwidget);
        create_scenario_button->setObjectName(QStringLiteral("create_scenario_button"));
        create_scenario_button->setGeometry(QRect(300, 380, 201, 61));
        StartEditorDialog->setCentralWidget(centralwidget);

        retranslateUi(StartEditorDialog);

        QMetaObject::connectSlotsByName(StartEditorDialog);
    } // setupUi

    void retranslateUi(QMainWindow *StartEditorDialog)
    {
        StartEditorDialog->setWindowTitle(QApplication::translate("StartEditorDialog", "MainWindow", 0));
        edit_scenario_button->setText(QApplication::translate("StartEditorDialog", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \321\201\321\206\320\265\320\275\320\260\321\200\320\270\320\271", 0));
        delete_scenario_button->setText(QApplication::translate("StartEditorDialog", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\201\321\206\320\265\320\275\320\260\321\200\320\270\320\271", 0));
        create_scenario_button->setText(QApplication::translate("StartEditorDialog", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \321\201\321\206\320\265\320\275\320\260\321\200\320\270\320\271", 0));
    } // retranslateUi

};

namespace Ui {
    class StartEditorDialog: public Ui_StartEditorDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTEDITORDIALOG_H
