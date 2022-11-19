/********************************************************************************
** Form generated from reading UI file 'routepropertyview.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROUTEPROPERTYVIEW_H
#define UI_ROUTEPROPERTYVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RoutePropertyView
{
public:
    QLabel *TitleLabel;
    QGroupBox *SelectedPointGroupBox;
    QLabel *XNameLabel;
    QLabel *YNameLabel;
    QLabel *PointPosNameLabel;
    QLabel *PointPosLabel;
    QLineEdit *XLineEdit;
    QLineEdit *YLineEdit;
    QLabel *PointsNumberNameLabel;
    QLabel *PointsNumberLabel;
    QLabel *RouteLengthNameLabel;
    QLabel *RouteTimeNameLabel;
    QLabel *RouteLengthLabel;
    QLabel *RouteTimeLabel;

    void setupUi(QWidget *RoutePropertyView)
    {
        if (RoutePropertyView->objectName().isEmpty())
            RoutePropertyView->setObjectName(QStringLiteral("RoutePropertyView"));
        RoutePropertyView->resize(360, 450);
        RoutePropertyView->setMinimumSize(QSize(360, 333));
        RoutePropertyView->setMaximumSize(QSize(360, 16777215));
        RoutePropertyView->setStyleSheet(QLatin1String("QWidget\n"
"{\n"
"	background-color:rgb(30, 33, 39);\n"
"	color:rgb(255, 255, 255);\n"
"}"));
        TitleLabel = new QLabel(RoutePropertyView);
        TitleLabel->setObjectName(QStringLiteral("TitleLabel"));
        TitleLabel->setGeometry(QRect(0, 0, 360, 43));
        QFont font;
        font.setFamily(QStringLiteral("Bahnschrift Light Condensed"));
        font.setPointSize(14);
        TitleLabel->setFont(font);
        TitleLabel->setStyleSheet(QStringLiteral("border: 1px solid white;"));
        TitleLabel->setAlignment(Qt::AlignCenter);
        SelectedPointGroupBox = new QGroupBox(RoutePropertyView);
        SelectedPointGroupBox->setObjectName(QStringLiteral("SelectedPointGroupBox"));
        SelectedPointGroupBox->setGeometry(QRect(20, 195, 320, 160));
        QFont font1;
        font1.setFamily(QStringLiteral("Bahnschrift Light Condensed"));
        font1.setPointSize(12);
        SelectedPointGroupBox->setFont(font1);
        SelectedPointGroupBox->setStyleSheet(QLatin1String("QGroupBox {\n"
"    border: 1px solid gray;\n"
"    border-color:rgb(255, 255, 255);\n"
"	margin-top: 3px;\n"
"	border-top-left-radius: 5px;\n"
"    border-top-right-radius: 5px;\n"
"    border-bottom-left-radius: 5px;\n"
"    border-bottom-right-radius: 5px;\n"
"}"));
        SelectedPointGroupBox->setAlignment(Qt::AlignCenter);
        SelectedPointGroupBox->setFlat(false);
        XNameLabel = new QLabel(SelectedPointGroupBox);
        XNameLabel->setObjectName(QStringLiteral("XNameLabel"));
        XNameLabel->setGeometry(QRect(5, 70, 100, 40));
        XNameLabel->setFont(font1);
        YNameLabel = new QLabel(SelectedPointGroupBox);
        YNameLabel->setObjectName(QStringLiteral("YNameLabel"));
        YNameLabel->setGeometry(QRect(5, 110, 100, 40));
        YNameLabel->setFont(font1);
        PointPosNameLabel = new QLabel(SelectedPointGroupBox);
        PointPosNameLabel->setObjectName(QStringLiteral("PointPosNameLabel"));
        PointPosNameLabel->setGeometry(QRect(5, 30, 100, 40));
        PointPosNameLabel->setFont(font1);
        PointPosLabel = new QLabel(SelectedPointGroupBox);
        PointPosLabel->setObjectName(QStringLiteral("PointPosLabel"));
        PointPosLabel->setGeometry(QRect(105, 30, 210, 40));
        PointPosLabel->setFont(font1);
        XLineEdit = new QLineEdit(SelectedPointGroupBox);
        XLineEdit->setObjectName(QStringLiteral("XLineEdit"));
        XLineEdit->setGeometry(QRect(105, 70, 210, 40));
        XLineEdit->setFont(font1);
        XLineEdit->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"	selection-background-color:rgb(2, 191,150);\n"
"}\n"
"\n"
"QLineEdit:hover\n"
"{\n"
"    border: 2px solid rgb(2, 191,150);\n"
"}"));
        YLineEdit = new QLineEdit(SelectedPointGroupBox);
        YLineEdit->setObjectName(QStringLiteral("YLineEdit"));
        YLineEdit->setGeometry(QRect(105, 110, 210, 40));
        YLineEdit->setFont(font1);
        YLineEdit->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"	selection-background-color:rgb(2, 191,150);\n"
"}\n"
"\n"
"QLineEdit:hover\n"
"{\n"
"    border: 2px solid rgb(2, 191,150);\n"
"}"));
        PointsNumberNameLabel = new QLabel(RoutePropertyView);
        PointsNumberNameLabel->setObjectName(QStringLiteral("PointsNumberNameLabel"));
        PointsNumberNameLabel->setGeometry(QRect(20, 60, 100, 40));
        PointsNumberNameLabel->setFont(font1);
        PointsNumberLabel = new QLabel(RoutePropertyView);
        PointsNumberLabel->setObjectName(QStringLiteral("PointsNumberLabel"));
        PointsNumberLabel->setGeometry(QRect(120, 60, 220, 40));
        PointsNumberLabel->setFont(font1);
        RouteLengthNameLabel = new QLabel(RoutePropertyView);
        RouteLengthNameLabel->setObjectName(QStringLiteral("RouteLengthNameLabel"));
        RouteLengthNameLabel->setGeometry(QRect(20, 100, 100, 40));
        RouteLengthNameLabel->setFont(font1);
        RouteTimeNameLabel = new QLabel(RoutePropertyView);
        RouteTimeNameLabel->setObjectName(QStringLiteral("RouteTimeNameLabel"));
        RouteTimeNameLabel->setGeometry(QRect(20, 140, 100, 40));
        RouteTimeNameLabel->setFont(font1);
        RouteLengthLabel = new QLabel(RoutePropertyView);
        RouteLengthLabel->setObjectName(QStringLiteral("RouteLengthLabel"));
        RouteLengthLabel->setGeometry(QRect(120, 100, 220, 40));
        RouteLengthLabel->setFont(font1);
        RouteTimeLabel = new QLabel(RoutePropertyView);
        RouteTimeLabel->setObjectName(QStringLiteral("RouteTimeLabel"));
        RouteTimeLabel->setGeometry(QRect(120, 140, 220, 40));
        RouteTimeLabel->setFont(font1);

        retranslateUi(RoutePropertyView);

        QMetaObject::connectSlotsByName(RoutePropertyView);
    } // setupUi

    void retranslateUi(QWidget *RoutePropertyView)
    {
        RoutePropertyView->setWindowTitle(QApplication::translate("RoutePropertyView", "Form", 0));
        TitleLabel->setText(QApplication::translate("RoutePropertyView", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\274\320\260\321\200\321\210\321\200\321\203\321\202\320\260", 0));
        SelectedPointGroupBox->setTitle(QApplication::translate("RoutePropertyView", "\320\222\321\213\320\261\321\200\320\260\320\275\320\275\320\260\321\217 \321\202\320\276\321\207\320\272\320\260 \320\274\320\260\321\200\321\210\321\200\321\203\321\202\320\260", 0));
        XNameLabel->setText(QApplication::translate("RoutePropertyView", "X", 0));
        YNameLabel->setText(QApplication::translate("RoutePropertyView", "Y", 0));
        PointPosNameLabel->setText(QApplication::translate("RoutePropertyView", "\320\235\320\276\320\274\320\265\321\200", 0));
        PointPosLabel->setText(QString());
        PointsNumberNameLabel->setText(QApplication::translate("RoutePropertyView", "\320\222\321\201\320\265\320\263\320\276 \320\242\320\276\321\207\320\265\320\272", 0));
        PointsNumberLabel->setText(QString());
        RouteLengthNameLabel->setText(QApplication::translate("RoutePropertyView", "\320\224\320\273\320\270\320\275\320\260", 0));
        RouteTimeNameLabel->setText(QApplication::translate("RoutePropertyView", "\320\222\321\200\320\265\320\274\321\217", 0));
        RouteLengthLabel->setText(QString());
        RouteTimeLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class RoutePropertyView: public Ui_RoutePropertyView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROUTEPROPERTYVIEW_H
