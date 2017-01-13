#pragma once
#include "includes.h"
#include "pt_utils.h"

enum class Direction
{
  Right,
  Left,
  Top,
  Bottom
};

struct SingleMove
{
  Point pt;
  Direction direction;

  bool operator==(const SingleMove& right)
  {
    return (this->direction == right.direction &&
      this->pt == right.pt);
  }

  SingleMove& operator=(const SingleMove& right)
  {
    pt = right.pt;
    direction = right.direction;
    return *this;
  }
};

std::array<SingleMove, 4> moveCoords{ {
  { { 0,1 }, Direction::Right },
  { { 0,-1 }, Direction::Left },
  { { 1,0 }, Direction::Bottom },
  { { -1,0 }, Direction::Top }
  } };