/********************************************************************************
** Form generated from reading UI file 'targetpropertyview.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TARGETPROPERTYVIEW_H
#define UI_TARGETPROPERTYVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TargetPropertyView
{
public:
    QLabel *TitleLabel;
    QLabel *CourseLabel;
    QLineEdit *TargetCourseLineEdit;
    QGroupBox *CoordGroupBox;
    QRadioButton *BearingDistanceRadioButton;
    QRadioButton *XYRadioButton;
    QLabel *XBearingLabel;
    QLineEdit *XBearingLineEdit;
    QLabel *YDistanceLabel;
    QLineEdit *YDistanceLineEdit;
    QLabel *SpeedLabel;
    QLineEdit *SpeedLineEdit;
    QLabel *TargetNameLabel;
    QLineEdit *TargetNameLineEdit;

    void setupUi(QWidget *TargetPropertyView)
    {
        if (TargetPropertyView->objectName().isEmpty())
            TargetPropertyView->setObjectName(QStringLiteral("TargetPropertyView"));
        TargetPropertyView->resize(360, 450);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TargetPropertyView->sizePolicy().hasHeightForWidth());
        TargetPropertyView->setSizePolicy(sizePolicy);
        TargetPropertyView->setMinimumSize(QSize(360, 360));
        TargetPropertyView->setMaximumSize(QSize(360, 450));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(30, 33, 39, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        TargetPropertyView->setPalette(palette);
        TargetPropertyView->setAutoFillBackground(false);
        TargetPropertyView->setStyleSheet(QLatin1String("background-color:rgb(30, 33, 39);\n"
"color:rgb(255, 255, 255);"));
        TitleLabel = new QLabel(TargetPropertyView);
        TitleLabel->setObjectName(QStringLiteral("TitleLabel"));
        TitleLabel->setGeometry(QRect(0, 0, 360, 43));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(TitleLabel->sizePolicy().hasHeightForWidth());
        TitleLabel->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamily(QStringLiteral("Bahnschrift Light Condensed"));
        font.setPointSize(14);
        font.setItalic(false);
        TitleLabel->setFont(font);
        TitleLabel->setStyleSheet(QStringLiteral("border: 1px solid white;"));
        TitleLabel->setAlignment(Qt::AlignCenter);
        CourseLabel = new QLabel(TargetPropertyView);
        CourseLabel->setObjectName(QStringLiteral("CourseLabel"));
        CourseLabel->setGeometry(QRect(20, 100, 100, 40));
        QFont font1;
        font1.setFamily(QStringLiteral("Bahnschrift Light Condensed"));
        font1.setPointSize(12);
        CourseLabel->setFont(font1);
        TargetCourseLineEdit = new QLineEdit(TargetPropertyView);
        TargetCourseLineEdit->setObjectName(QStringLiteral("TargetCourseLineEdit"));
        TargetCourseLineEdit->setGeometry(QRect(120, 100, 220, 40));
        TargetCourseLineEdit->setFont(font1);
        TargetCourseLineEdit->setFocusPolicy(Qt::ClickFocus);
        TargetCourseLineEdit->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"	selection-background-color:rgb(2, 191,150);\n"
"}\n"
"\n"
"QLineEdit:hover\n"
"{\n"
"    border: 2px solid rgb(2, 191,150);\n"
"}"));
        CoordGroupBox = new QGroupBox(TargetPropertyView);
        CoordGroupBox->setObjectName(QStringLiteral("CoordGroupBox"));
        CoordGroupBox->setGeometry(QRect(20, 195, 320, 160));
        CoordGroupBox->setFont(font1);
        CoordGroupBox->setStyleSheet(QLatin1String("QGroupBox {\n"
"    border: 1px solid gray;\n"
"    border-color:rgb(255, 255, 255);\n"
"	margin-top: 3px;\n"
"	border-top-left-radius: 5px;\n"
"    border-top-right-radius: 5px;\n"
"    border-bottom-left-radius: 5px;\n"
"    border-bottom-right-radius: 5px;\n"
"}"));
        CoordGroupBox->setAlignment(Qt::AlignCenter);
        BearingDistanceRadioButton = new QRadioButton(CoordGroupBox);
        BearingDistanceRadioButton->setObjectName(QStringLiteral("BearingDistanceRadioButton"));
        BearingDistanceRadioButton->setGeometry(QRect(5, 30, 190, 40));
        BearingDistanceRadioButton->setFont(font1);
        BearingDistanceRadioButton->setStyleSheet(QLatin1String("QGroupBox {\n"
"    border: 2px solid gray;\n"
"    border-color: #FF17365D;\n"
"    border-bottom-left-radius: 15px;\n"
"    border-bottom-right-radius: 15px;\n"
"}"));
        XYRadioButton = new QRadioButton(CoordGroupBox);
        XYRadioButton->setObjectName(QStringLiteral("XYRadioButton"));
        XYRadioButton->setGeometry(QRect(200, 30, 115, 40));
        XYRadioButton->setFont(font1);
        XYRadioButton->setStyleSheet(QStringLiteral(""));
        XBearingLabel = new QLabel(CoordGroupBox);
        XBearingLabel->setObjectName(QStringLiteral("XBearingLabel"));
        XBearingLabel->setGeometry(QRect(5, 70, 100, 40));
        XBearingLabel->setFont(font1);
        XBearingLineEdit = new QLineEdit(CoordGroupBox);
        XBearingLineEdit->setObjectName(QStringLiteral("XBearingLineEdit"));
        XBearingLineEdit->setGeometry(QRect(105, 70, 200, 40));
        XBearingLineEdit->setFont(font1);
        XBearingLineEdit->setAutoFillBackground(false);
        XBearingLineEdit->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"	selection-background-color:rgb(2, 191,150);\n"
"}\n"
"\n"
"QLineEdit:hover\n"
"{\n"
"    border: 2px solid rgb(2, 191,150);\n"
"}"));
        YDistanceLabel = new QLabel(CoordGroupBox);
        YDistanceLabel->setObjectName(QStringLiteral("YDistanceLabel"));
        YDistanceLabel->setGeometry(QRect(5, 110, 100, 40));
        YDistanceLabel->setFont(font1);
        YDistanceLineEdit = new QLineEdit(CoordGroupBox);
        YDistanceLineEdit->setObjectName(QStringLiteral("YDistanceLineEdit"));
        YDistanceLineEdit->setGeometry(QRect(105, 110, 200, 40));
        YDistanceLineEdit->setFont(font1);
        YDistanceLineEdit->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"	selection-background-color:rgb(2, 191,150);\n"
"}\n"
"\n"
"QLineEdit:hover\n"
"{\n"
"    border: 2px solid rgb(2, 191,150);\n"
"}"));
        SpeedLabel = new QLabel(TargetPropertyView);
        SpeedLabel->setObjectName(QStringLiteral("SpeedLabel"));
        SpeedLabel->setGeometry(QRect(20, 140, 100, 40));
        SpeedLabel->setFont(font1);
        SpeedLineEdit = new QLineEdit(TargetPropertyView);
        SpeedLineEdit->setObjectName(QStringLiteral("SpeedLineEdit"));
        SpeedLineEdit->setGeometry(QRect(120, 140, 220, 40));
        SpeedLineEdit->setFont(font1);
        SpeedLineEdit->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"	selection-background-color:rgb(2, 191,150);\n"
"}\n"
"\n"
"QLineEdit:hover\n"
"{\n"
"    border: 2px solid rgb(2, 191,150);\n"
"}"));
        TargetNameLabel = new QLabel(TargetPropertyView);
        TargetNameLabel->setObjectName(QStringLiteral("TargetNameLabel"));
        TargetNameLabel->setGeometry(QRect(20, 60, 100, 40));
        TargetNameLabel->setFont(font1);
        TargetNameLineEdit = new QLineEdit(TargetPropertyView);
        TargetNameLineEdit->setObjectName(QStringLiteral("TargetNameLineEdit"));
        TargetNameLineEdit->setGeometry(QRect(120, 60, 220, 40));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush2(QColor(2, 191, 150, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Highlight, brush2);
        TargetNameLineEdit->setPalette(palette1);
        TargetNameLineEdit->setFont(font1);
        TargetNameLineEdit->setAutoFillBackground(false);
        TargetNameLineEdit->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"	selection-background-color:rgb(2, 191,150);\n"
"}\n"
"\n"
"QLineEdit:hover\n"
"{\n"
"    border: 2px solid rgb(2, 191,150);\n"
"}"));

        retranslateUi(TargetPropertyView);

        QMetaObject::connectSlotsByName(TargetPropertyView);
    } // setupUi

    void retranslateUi(QWidget *TargetPropertyView)
    {
        TargetPropertyView->setWindowTitle(QApplication::translate("TargetPropertyView", "Form", 0));
        TitleLabel->setText(QApplication::translate("TargetPropertyView", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \321\206\320\265\320\273\320\270", 0));
        CourseLabel->setText(QApplication::translate("TargetPropertyView", "\320\232\321\203\321\200\321\201", 0));
        CoordGroupBox->setTitle(QApplication::translate("TargetPropertyView", "\320\232\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\321\213", 0));
        BearingDistanceRadioButton->setText(QApplication::translate("TargetPropertyView", "\320\237\320\265\320\273\320\273\320\265\320\275\320\263, \320\264\320\270\321\201\321\202\320\260\320\275\321\206\320\270\321\217", 0));
        XYRadioButton->setText(QApplication::translate("TargetPropertyView", "X, Y", 0));
        XBearingLabel->setText(QApplication::translate("TargetPropertyView", "\320\237\320\265\320\273\320\265\320\275\320\263", 0));
        YDistanceLabel->setText(QApplication::translate("TargetPropertyView", "\320\224\320\270\321\201\321\202\320\260\320\275\321\206\320\270\321\217", 0));
        SpeedLabel->setText(QApplication::translate("TargetPropertyView", "\320\241\320\272\320\276\321\200\320\276\321\201\321\202\321\214", 0));
        TargetNameLabel->setText(QApplication::translate("TargetPropertyView", "\320\230\320\274\321\217", 0));
    } // retranslateUi

};

namespace Ui {
    class TargetPropertyView: public Ui_TargetPropertyView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TARGETPROPERTYVIEW_H
