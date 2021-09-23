/*
 * Utils.cpp
 *
 *  Created on: Jan. 8, 2019
 *      Author: serge
 */

#include "utils.h"
#include <cmath>



bool IsEqual(float x, float y)
{
	return fabsf(x - y) < EPSILON;
}

bool IsGreaterThanOrEqual(float x, float y)
{
	return x > y || IsEqual(x, y);
}

bool IsLessThanOrEqual(float x, float y)
{
	return x < y || IsEqual(x, y);
}
