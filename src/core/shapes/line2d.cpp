//
// Created by brunosxs on 23/09/2021.
//

#include "line2d.h"
#include <cmath>
#include "utils/utils.h"

Line2d::Line2d(): p0(Vector2()), p1(Vector2()) {}

Line2d::Line2d(float x0, float y0, float x1, float y1): p0(Vector2(x0, y0)), p1(Vector2(x1, y1)) {

}

Line2d::Line2d(const Vector2 &pp0, const Vector2 &pp1): p0(pp0), p1(pp1) {}

bool Line2d::operator==(const Line2d &line) const {
    return p0 == line.GetP0() and p1 == line.GetP1();
}

float Line2d::MininumDistanceFromPoint(const Vector2 &p, bool limitToSegment) const {

    return p.Distance(ClosestPoint(p, limitToSegment));
}

Vector2 Line2d::ClosestPoint(const Vector2 &p, bool limitToSegment) const {
    Vector2 p0toP = p - p0;
    Vector2 p0toP1 = p1 - p0;
    float l2 = p0toP1.Mag2();
    float dot = p0toP.Dot(p0toP1);
    float t = dot / l2;
    if (limitToSegment) {
        t = std::fmax(0, std::fmin(1.0f, t));
    }
    return p0 + p0toP1 * t;
}

Vector2 Line2d::Midpoint() const {

    return Vector2((p0.GetX() + p1.GetX()) / 2.0f, (p0.GetY() + p1.GetY()) / 2.0f);
}

float Line2d::Slope() const {
    float dx = p1.GetX() - p0.GetX();
    if (fabs(dx) < EPSILON) {
        return 0;
    }
    float dy = p1.GetY() - p0.GetY();
    return dy / dx;
}

float Line2d::Length() const {
    return p1.Distance(p0);
}

