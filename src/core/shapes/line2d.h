//
// Created by brunosxs on 23/09/2021.
//

#ifndef TREM_LINE2D_H
#define TREM_LINE2D_H
#include <utils/vector2d.h>

class Line2d {
public:
    Line2d();
    Line2d(float x0, float y0, float x1, float y1);
    Line2d(const Vector2& pp0, const Vector2& pp1);

    inline const Vector2& GetP0() const { return p0;};
    inline const Vector2& GetP1() const { return p1;};
    inline void SetP0(const Vector2& pp0) { p0 = pp0; };
    inline void SetP1(const Vector2& pp1) { p1 = pp1; };

    bool operator==(const Line2d& line) const;
    float MininumDistanceFromPoint(const Vector2& p, bool limitToSegment = false) const;
    Vector2 ClosestPoint(const Vector2& p, bool limitToSegment = false) const;

    Vector2 Midpoint() const;
    float Slope() const;
    float Length() const;
private:
    Vector2 p0, p1;

};


#endif //TREM_LINE2D_H
