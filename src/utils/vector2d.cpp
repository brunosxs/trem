#include "vector2d.h"
#include "utils.h"

#include <cassert>
#include <cmath>

const Vector2 Vector2::Zero;

std::ostream& operator<<(std::ostream& consoleOut, const Vector2& vec)
{
	std::cout << "X: " << vec.mX << ", Y: " << vec.mY << std::endl;
	return consoleOut;
}

Vector2 operator*(float scalar, const Vector2& vec)
{
	return vec * scalar;
}

bool Vector2::operator==(const Vector2& vec2) const
{
	return IsEqual(mX, vec2.mX) && IsEqual(mY, vec2.mY);
}

bool Vector2::operator!=(const Vector2& vec2) const
{
	return !(*this == vec2);
}

Vector2 Vector2::operator-() const
{
	return Vector2(-mX, -mY);
}

Vector2 Vector2::operator*(float scale) const
{
	return Vector2(scale * mX, scale * mY);
}

Vector2 Vector2::operator/(float scale) const
{
	assert(fabsf(scale) > EPSILON);

	return Vector2(mX / scale, mY / scale);
}

Vector2& Vector2::operator*=(float scale)
{
	*this = *this * scale;
	return *this;
}

Vector2& Vector2::operator/=(float scale)
{
	assert(fabsf(scale) > EPSILON);

	*this = *this / scale;
	return *this;
}

Vector2 Vector2::operator+(const Vector2& vec) const
{
	return Vector2(mX + vec.mX, mY + vec.mY);
}

Vector2 Vector2::operator-(const Vector2& vec) const
{
	return Vector2(mX - vec.mX, mY - vec.mY);
}

Vector2& Vector2::operator+=(const Vector2& vec)
{
	*this = *this + vec;
	return *this;
}

Vector2& Vector2::operator-=(const Vector2& vec)
{
	*this = *this - vec;
	return *this;
}

float Vector2::Mag2() const
{
	return Dot(*this);
}

float Vector2::Mag() const
{
	return sqrt(Mag2());
}

Vector2 Vector2::GetUnitVec() const
{
	float mag = Mag();

	if(mag > EPSILON)
	{
		return *this / mag;
	}

	return Vector2::Zero;
}

Vector2& Vector2::Normalize()
{
	float mag = Mag();

	if(mag > EPSILON)
	{
		*this /= mag;
	}

	return *this;
}

float Vector2::Distance(const Vector2& vec) const
{
	return (vec - *this).Mag();
}

float Vector2::Dot(const Vector2& vec) const
{
	return mX * vec.mX + mY * vec.mY;
}

Vector2 Vector2::ProjectOnto(const Vector2& vec2) const
{
	Vector2 unitVec2 = vec2.GetUnitVec();

	float dot = Dot(unitVec2);

	return unitVec2 * dot;
}

float Vector2::AngleBetween(const Vector2& vec2) const
{
	return acosf(GetUnitVec().Dot(vec2.GetUnitVec()));
}

Vector2 Vector2::Reflect(const Vector2& normal) const
{
	//v - 2(v dot n)n
	return *this - 2 * ProjectOnto(normal);
}

void Vector2::Rotate(float angle, const Vector2& aroundPoint)
{
	float cosine = cosf(angle);
	float sine = sinf(angle);

	Vector2 thisVec(mX, mY);

	thisVec -= aroundPoint;

	float xRot = thisVec.mX * cosine - thisVec.mY * sine;
	float yRot = thisVec.mX * sine + thisVec.mY * cosine;

	Vector2 rot = Vector2(xRot, yRot);

	*this = rot + aroundPoint;
}

Vector2 Vector2::RotationResult(float angle, const Vector2& aroundPoint) const
{
	float cosine = cosf(angle);
	float sine = sinf(angle);

	Vector2 thisVec(mX, mY);

	thisVec -= aroundPoint;

	float xRot = thisVec.mX * cosine - thisVec.mY * sine;
	float yRot = thisVec.mX * sine + thisVec.mY * cosine;

	Vector2 rot = Vector2(xRot, yRot);

	return rot + aroundPoint;
}
