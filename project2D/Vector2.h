#pragma once
class Vector2;
class Vector2
{
public:

	float x, y;
	Vector2();
	Vector2(float a, float b);

	Vector2 operator +(Vector2 &other);
	Vector2 operator -(Vector2 &other);//function to subtract one vector from another
	Vector2 operator *(const float &mult);//function to multiply 2d vectors

	float Magnitude();//function to find the magnitude of a 2d vector
	Vector2 Normalize();//function to normalize a vector
	float DotProduct(Vector2 &other);//function to find the dotproduct of two 2d vectors
	void Print();//prints out the vector

};