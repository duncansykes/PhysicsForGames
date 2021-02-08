#include "Vector2.h"

namespace mathfs
{
	Vector2::Vector2(float a_x, float a_y)
	{
		x = a_x;
		y = a_y;
	}

	Vector2::Vector2()
	{
		x = 0;
		y = 0;
	}

	Vector2::~Vector2()
	{
	}

	Vector2 Vector2::Add(float x1, float y1, float x2, float y2)
	{
		return Vector2((x1 + y1), (x2 + y2));
	}

	Vector2 Vector2::Add(Vector2 vector_one, Vector2 vector_two)
	{
		Vector2 result((vector_one.x + vector_two.x), (vector_one.y + vector_two.y));
		return result;
	}



	Vector2 Vector2::Normalize()
	{

		float size = Magnitude();

		float ax = x / size;
		float ay = y / size;

		return Vector2(ax,ay);
	}

	float Vector2::Magnitude()
	{
		float sq = oprt->inv_sqrt((x * x) + (y * y));

		return sq;
	}

	Vector2 Vector2::Subtract(Vector2 vector_two, Vector2 vector_one)
	{
		return Vector2((vector_two.x - vector_one.x), (vector_two.y - vector_one.y));
	}




	


}