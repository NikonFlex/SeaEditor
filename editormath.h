#ifndef EDITORMATH_H
#define EDITORMATH_H

#include <math.h>
#include <QtMath>
#include <QPoint>

struct Point
{
  double x;
  double y;

  Point(){ x = 0; y = 0; }
  Point(double px, double py) { x = px; y = py; }

  const Point operator - (const Point& p) const
  {
    return Point(x - p.x, y - p.y);
  }

  const Point operator + (const Point& p) const
  {
    return Point(x + p.x, y + p.y);
  }

  const Point operator * (const double& n) const
  {
    return Point(x * n, y * n);
  }

  const Point operator / (const double& n) const
  {
    return Point(x / n, y / n);
  }

  double distTo(const Point& p)
  {
    return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
  }
};

struct DistanceBearing
{
  double distance;
  double bearing;

  DistanceBearing(){ distance = 0; bearing = 0; }

  DistanceBearing(const Point& p)
  {
    distance = Point(p.x, p.y).distTo(Point(0, 0));

    double angle = qRadiansToDegrees(qAtan2(p.y, p.x));
    if (angle <= 0)
      angle = abs(angle - 90);
    else if (angle >= 0 && angle <= 90)
      angle = 90 - angle;
    else
      angle = 360 - (angle - 90);

    bearing = angle;
  }

  DistanceBearing(double dist, double bear){ distance = dist; bearing = bear; }
};

inline Point ConvertToPoint(const DistanceBearing& distance_bearing)
{
  double x = distance_bearing.distance * qSin(qDegreesToRadians(distance_bearing.bearing));
  double y = distance_bearing.distance * qCos(qDegreesToRadians(distance_bearing.bearing));
  return Point(x, y);
}

inline DistanceBearing ConvertToDistanceBearing(const Point& p){ return DistanceBearing(p); }

inline double CalculateAngleOnPoint(const Point& p1, const Point& p2)
{
  double Dir_C_to_A = atan2((p1.y + 100) - p1.y, p1.x - p1.x);
  double Dir_C_to_B = atan2(p2.y - p1.y, p2.x - p1.x);
  double Angle_ACB = Dir_C_to_A - Dir_C_to_B;

  const double Pi = qAcos(-1);
  if (Angle_ACB > Pi)
    Angle_ACB -= 2 * Pi;
  else if (Angle_ACB < -Pi)
    Angle_ACB += 2 * Pi;

  int angle = qRadiansToDegrees(Angle_ACB);
  return angle < 0 ? 180 - angle : abs(angle - 180);
}


class BoundRect
{
public:
  BoundRect();
  Point GetLow() const;
  Point GetHigh() const;
  double GetWidth() const;
  double GetHeight() const;
  bool IsEmpty() const;
  void AddPoint(Point p);
  void SetEmpty();

private:
  Point _low;
  Point _high;
  Point _center;
  Point getCenter() const;
};

class Transformation
{
public:
  Transformation(double screen_w, double screen_h, double border_shift, BoundRect& b_rect);
  Transformation(){};
  QPoint WorldToScreen(const Point& world_pos) const;
  Point ScreenToWorld(const QPoint& screen_pos) const;
  bool IsEmpty() const { return _scale == 0 ;}
  void SetViewShift(const Point& mouse_move_amount);
  void SetWorldShift(const Point& p);
  void UpdateScale(double difference);

private:
  double _border_shift = 0;
  double _scale = 0;
  Point _world_shift;
  Point _view_shift;
  int _screen_h;
};

#endif // EDITORMATH_H
