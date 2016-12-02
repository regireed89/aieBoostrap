#include "Vector2.h"

Vector2::Vector2() {};//default constructor
Vector2::Vector2(float a, float b)//constuctor takes two float arguments
{
	x = a;
	y = b;

}

Vector2 Vector2::add(Vector2 & other)
{
	float a = this->x + other.x;
	float b = this->y + other.y;

	return Vector2(a, b);
}


Vector2 Vector2::subtract(Vector2 &other)//function to subtract one vector from another
{
	float a = this->x - other.x;
	float b = this->y - other.y;

	return Vector2(a, b);
}

Vector2 Vector2::ScalarMult(Vector2 &mult)//function to multiply 2d vectors
{
	float a = this->x * mult.x;
	float b = this->y * mult.y;

	return Vector2(a, b);
}

float Vector2::Magnitude()//function to find the magnitude of a 2d vector
{
	//float a = sqrt(x*x + y*y);


	return 0;
}

Vector2 Vector2::Normalize()//function to normalize a vector
{
	Vector2 vec = Vector2(x / Magnitude(), y / Magnitude());

	return vec;
}

float Vector2::DotProduct(Vector2 &other)//function to find the dotproduct of two 2d vectors
{
	float a = this->x * other.x;
	float b = this->y * other.y;
	float c = a + b;

	return c;
}
 