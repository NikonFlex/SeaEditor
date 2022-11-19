#include "shiplabel.h"
#include "screenview.h"
#include "QMouseEvent"

ShipLabel::ShipLabel(QWidget *widget) : QLabel(widget)
{
  this->setAttribute( Qt::WA_TransparentForMouseEvents );
  setMouseTracking(true);
}

