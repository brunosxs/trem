/*
 * Vector2.h
 *
 *  Created on: Jan. 8, 2019
 *      Author: serge
 */

#ifndef UTILS_VEC2D_H_
#define UTILS_VEC2D_H_

#include <iostream>

class Vector2 {

	public:

	static const Vector2 Zero;

	Vector2(): Vector2(0, 0){}
    Vector2(float x, float y): mX(x), mY(y){}

    inline void SetX(float x) {mX = x;}
    inline void SetY(float y) {mY = y;}
    inline float GetX() const {return mX;}
    inline float GetY() const {return mY;}

    friend std::ostream& operator<<(std::ostream& consoleOut, const Vector2& vec);

    bool operator==(const Vector2& vec2) const;
    bool operator!=(const Vector2& vec2) const;

    Vector2 operator-() const;
    Vector2 operator*(float scale) const;
    Vector2 operator/(float scale) const;
    Vector2& operator*=(float scale);
    Vector2& operator/=(float scale);

    Vector2 operator+(const Vector2& vec) const;
    Vector2 operator-(const Vector2& vec) const;
    Vector2& operator+=(const Vector2& vec);
    Vector2& operator-=(const Vector2& vec);

    float Mag2() const;
    float Mag() const;

    Vector2 GetUnitVec() const;
    Vector2& Normalize();

    float Distance(const Vector2& vec) const;
    float Dot(const Vector2& vec) const;

    Vector2 ProjectOnto(const Vector2& vec2) const;

    float AngleBetween(const Vector2& vec2) const;

    Vector2 Reflect(const Vector2& normal) const;


    void Rotate(float angle, const Vector2& aroundPoint);
    Vector2 RotationResult(float angle, const Vector2& aroundPoint) const;

    friend Vector2 operator*(float scalar, const Vector2& vec);

	private:
	float mX, mY;
};

#endif /* UTILS_VEC2D_H_ */
