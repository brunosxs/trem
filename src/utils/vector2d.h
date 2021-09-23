/*
 * Vector2d.h
 *
 *  Created on: Jan. 8, 2019
 *      Author: serge
 */

#ifndef UTILS_VEC2D_H_
#define UTILS_VEC2D_H_

#include <iostream>

class Vector2d {

	public:

	static const Vector2d Zero;

	Vector2d(): Vector2d(0, 0){}
    Vector2d(float x, float y): mX(x), mY(y){}

    inline void SetX(float x) {mX = x;}
    inline void SetY(float y) {mY = y;}
    inline float GetX() const {return mX;}
    inline float GetY() const {return mY;}

    friend std::ostream& operator<<(std::ostream& consoleOut, const Vector2d& vec);

    bool operator==(const Vector2d& vec2) const;
    bool operator!=(const Vector2d& vec2) const;

    Vector2d operator-() const;
    Vector2d operator*(float scale) const;
    Vector2d operator/(float scale) const;
    Vector2d& operator*=(float scale);
    Vector2d& operator/=(float scale);

    Vector2d operator+(const Vector2d& vec) const;
    Vector2d operator-(const Vector2d& vec) const;
    Vector2d& operator+=(const Vector2d& vec);
    Vector2d& operator-=(const Vector2d& vec);

    float Mag2() const;
    float Mag() const;

    Vector2d GetUnitVec() const;
    Vector2d& Normalize();

    float Distance(const Vector2d& vec) const;
    float Dot(const Vector2d& vec) const;

    Vector2d ProjectOnto(const Vector2d& vec2) const;

    float AngleBetween(const Vector2d& vec2) const;

    Vector2d Reflect(const Vector2d& normal) const;


    void Rotate(float angle, const Vector2d& aroundPoint);
    Vector2d RotationResult(float angle, const Vector2d& aroundPoint) const;

    friend Vector2d operator*(float scalar, const Vector2d& vec);

	private:
	float mX, mY;
};

#endif /* UTILS_VEC2D_H_ */
