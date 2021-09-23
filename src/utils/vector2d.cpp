#include "vector2d.h"
#include "utils.h"

#include <cassert>
#include <cmath>

const Vector2d Vector2d::Zero;

std::ostream& operator<<(std::ostream& consoleOut, const Vector2d& vec)
{
	std::cout << "X: " << vec.mX << ", Y: " << vec.mY << std::endl;
	return consoleOut;
}

Vector2d operator*(float scalar, const Vector2d& vec)
{
	return vec * scalar;
}

bool Vector2d::operator==(const Vector2d& vec2) const
{
	return IsEqual(mX, vec2.mX) && IsEqual(mY, vec2.mY);
}

bool Vector2d::operator!=(const Vector2d& vec2) const
{
	return !(*this == vec2);
}

Vector2d Vector2d::operator-() const
{
	return Vector2d(-mX, -mY);
}

Vector2d Vector2d::operator*(float scale) const
{
	return Vector2d(scale * mX, scale * mY);
}

Vector2d Vector2d::operator/(float scale) const
{
	assert(fabsf(scale) > EPSILON);

	return Vector2d(mX / scale, mY / scale);
}

Vector2d& Vector2d::operator*=(float scale)
{
	*this = *this * scale;
	return *this;
}

Vector2d& Vector2d::operator/=(float scale)
{
	assert(fabsf(scale) > EPSILON);

	*this = *this / scale;
	return *this;
}

Vector2d Vector2d::operator+(const Vector2d& vec) const
{
	return Vector2d(mX + vec.mX, mY + vec.mY);
}

Vector2d Vector2d::operator-(const Vector2d& vec) const
{
	return Vector2d(mX - vec.mX, mY - vec.mY);
}

Vector2d& Vector2d::operator+=(const Vector2d& vec)
{
	*this = *this + vec;
	return *this;
}

Vector2d& Vector2d::operator-=(const Vector2d& vec)
{
	*this = *this - vec;
	return *this;
}

float Vector2d::Mag2() const
{
	return Dot(*this);
}

float Vector2d::Mag() const
{
	return sqrt(Mag2());
}

Vector2d Vector2d::GetUnitVec() const
{
	float mag = Mag();

	if(mag > EPSILON)
	{
		return *this / mag;
	}

	return Vector2d::Zero;
}

Vector2d& Vector2d::Normalize()
{
	float mag = Mag();

	if(mag > EPSILON)
	{
		*this /= mag;
	}

	return *this;
}

float Vector2d::Distance(const Vector2d& vec) const
{
	return (vec - *this).Mag();
}

float Vector2d::Dot(const Vector2d& vec) const
{
	return mX * vec.mX + mY * vec.mY;
}

Vector2d Vector2d::ProjectOnto(const Vector2d& vec2) const
{
	Vector2d unitVec2 = vec2.GetUnitVec();

	float dot = Dot(unitVec2);

	return unitVec2 * dot;
}

float Vector2d::AngleBetween(const Vector2d& vec2) const
{
	return acosf(GetUnitVec().Dot(vec2.GetUnitVec()));
}

Vector2d Vector2d::Reflect(const Vector2d& normal) const
{
	//v - 2(v dot n)n
	return *this - 2 * ProjectOnto(normal);
}

void Vector2d::Rotate(float angle, const Vector2d& aroundPoint)
{
	float cosine = cosf(angle);
	float sine = sinf(angle);

	Vector2d thisVec(mX, mY);

	thisVec -= aroundPoint;

	float xRot = thisVec.mX * cosine - thisVec.mY * sine;
	float yRot = thisVec.mX * sine + thisVec.mY * cosine;

	Vector2d rot = Vector2d(xRot, yRot);

	*this = rot + aroundPoint;
}

Vector2d Vector2d::RotationResult(float angle, const Vector2d& aroundPoint) const
{
	float cosine = cosf(angle);
	float sine = sinf(angle);

	Vector2d thisVec(mX, mY);

	thisVec -= aroundPoint;

	float xRot = thisVec.mX * cosine - thisVec.mY * sine;
	float yRot = thisVec.mX * sine + thisVec.mY * cosine;

	Vector2d rot = Vector2d(xRot, yRot);

	return rot + aroundPoint;
}
