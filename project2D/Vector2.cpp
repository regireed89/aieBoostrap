#include <iostream>
#include "Vector2.h"
using namespace std;


Vector2::Vector2() {};//default constructor
Vector2::Vector2(float a, float b)//constuctor takes two float arguments
{
	x = a;
	y = b;
}

Vector2 Vector2::operator +(Vector2 &other)//function to add two vectors together
{
	return Vector2(x + other.x, y + other.y);
}

Vector2 Vector2::operator -(Vector2 &other)//function to subtract one vector from another
{
	float a = this->x - other.x;
	float b = this->y - other.y;

	return Vector2(a, b);
}

<<<<<<< HEAD
Vector2 Vector2::operator *(const float &mult)//function to multiply 2d vectors
{
	return Vector2(x*mult, y*mult);
=======
Vector2 Vector2::ScalarMult(float &mult)//function to multiply 2d vectors
{
	float a = this->x * mult;
	float b = this->y * mult;

	return Vector2(a, b);
>>>>>>> origin/master
}

float Vector2::Magnitude()//function to find the magnitude of a 2d vector
{
	float a = sqrt((x*x) + (y*y));

	return a;
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

void Vector2::Print()//prints out the vector
{
	cout << "2D Vector" << endl;
	cout << "x=" << x << "y=" << y << endl;
	cout << "____" << endl;
}
 