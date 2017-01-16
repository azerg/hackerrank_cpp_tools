#pragma once
#include "includes.h"

struct Point;

//======================================================================================================

double MovesCountBetween(const Point& pt1, const Point& pt2);
/*!
* Checks if lines are crossed, returns @Point where they are crossed at.
*/
bool GetCrossingPoint(const Point& A1, const Point& A2, const Point& B1, const Point& B2, Point& out);

//======================================================================================================

struct Point
{
  Point() = default;
  Point(double x, double y) :
    x{x},
    y{y}
  {}

  double x, y;

  bool operator==(const Point& right) const
  {
    return this->x == right.x && this->y == right.y;
  }
  bool operator!=(const Point& right) const
  {
    return !(*this == right);
  }
  Point operator+(const Point pt) const noexcept
  {
    return Point(this->x + pt.x, this->y + pt.y);
  }
  Point operator-(const Point pt) const noexcept
  {
    return Point(this->x - pt.x, this->y - pt.y);
  }
  Point operator*(const Point pt) const noexcept
  {
    return Point(this->x * pt.x, this->y * pt.y);
  }
  Point operator/(const Point pt) const noexcept
  {
    return Point(this->x / pt.x, this->y / pt.y);
  }
  Point operator*(double val) const noexcept
  {
    return Point(this->x * val, this->y * val);
  }
  Point& operator+=(const Point& pt)
  {
    assert(this != &pt);
    x += pt.x;
    y += pt.y;
    return *this;
  }
  Point& operator-=(const Point& pt)
  {
    assert(this != &pt);
    x -= pt.x;
    y -= pt.y;
    return *this;
  }
};

//======================================================================================================

double MovesCountBetween(const Point& pt1, const Point& pt2)
{
  return ceil(sqrt(pow(pt1.x - pt2.x, 2) + pow(pt1.y - pt2.y, 2)));
}

bool LineCollision(const Point& A1, const Point& A2, const Point& B1, const Point& B2, double* out)
{
  auto Dot = [](const Point& a, const Point& b) { return (a.x*b.x) + (a.y*b.y); };
  auto PerpDot = [](const Point& a, const Point& b) { return (a.y*b.x) - (a.x*b.y); };

  Point a(A2 - A1);
  Point b(B2 - B1);

  double f = PerpDot(a, b);
  if (!f)      // lines are parallel
    return false;

  Point c(B2 - A2);
  double aa = PerpDot(a, c);
  double bb = PerpDot(b, c);

  if (f < 0)
  {
    if (aa > 0) return false; if (bb > 0) return false; if (aa < f) return false; if (bb < f) return false;
  }
  else
  {
    if (aa < 0) return false; if (bb < 0) return false; if (aa > f) return false; if (bb > f) return false;
  }

  if (out)
    *out = 1.0 - (aa / f);
  return true;
}

bool GetCrossingPoint(const Point& A1, const Point& A2,
  const Point& B1, const Point& B2, Point& out)
{
  double pointOfCollision;
  auto reslt = LineCollision(A1, A2, B1, B2, &pointOfCollision);
  if (!reslt)
    return false;

  out = ((B2 - B1) * pointOfCollision) + B1;
  return true;
}


