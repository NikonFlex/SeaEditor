#ifndef SVGICONSET_H
#define SVGICONSET_H

#include <QSvgRenderer>
#include <QMap>
#include <QPointer>

class SvgIconSet
{
private:
  SvgIconSet();
  SvgIconSet( const SvgIconSet& );
  SvgIconSet& operator=( SvgIconSet& );
  static SvgIconSet* _instance;
  QMap<QString, QPointer<QSvgRenderer>> _ship_pictures;

public:
  static QPointer<QSvgRenderer> GetRenderer(QString iconName);
};

#endif // SVGICONSET_H
