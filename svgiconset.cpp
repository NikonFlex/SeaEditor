#include "svgiconset.h"

SvgIconSet::SvgIconSet()
{
  QPointer<QSvgRenderer> ship = new QSvgRenderer();
  QPointer<QSvgRenderer> selected_ship = new QSvgRenderer();
  QPointer<QSvgRenderer> ownship = new QSvgRenderer();
  QPointer<QSvgRenderer> selected_ownship = new QSvgRenderer();
  ship->load(QString(":/ships/res/ship.svg"));
  selected_ship->load(QString(":/ships/res/selected_ship.svg"));
  ownship->load(QString(":/ships/res/ownship.svg"));
  selected_ownship->load(QString(":/ships/res/selected_ownship.svg"));
  _ship_pictures.insert("ship", ship);
  _ship_pictures.insert("selected_ship", selected_ship);
  _ship_pictures.insert("ownship", ownship);
  _ship_pictures.insert("selected_ownship", selected_ownship);
}

SvgIconSet* SvgIconSet::_instance = 0;

QPointer<QSvgRenderer> SvgIconSet::GetRenderer(QString iconName)
{
  if (_instance == 0)
    _instance = new SvgIconSet();
  return _instance->_ship_pictures.value(iconName);
}

