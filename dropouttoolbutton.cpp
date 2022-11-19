#include "dropouttoolbutton.h"

DropOutToolButton::DropOutToolButton(QWidget *parent) :
    QToolButton(parent)
{
    setPopupMode(QToolButton::MenuButtonPopup);
    QObject::connect(this, SIGNAL(triggered(QAction*)),
                     this, SLOT(setDefaultAction(QAction*)));
}
