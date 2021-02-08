#include "Vector3.h"
namespace mathfs
{
	Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z)
	{
	}


	Vector3::Vector3() : x(0), y(0), z(0)
	{
	}

	Vector3::~Vector3()
	{
	}

	Vector3 Vector3::Add(Vector3 vector1, Vector3 vector2)
	{
		return Vector3(
			(vector1.x + vector2.x),
			(vector1.y + vector2.y),
			(vector1.z + vector2.z)
		);

	}

	Vector3 Vector3::Subtract(Vector3 vector1, Vector3 vector2)
	{
		return Vector3(
			(vector1.x - vector2.x),
			(vector1.y - vector2.y),
			(vector1.z - vector2.z)
		);
	}



	Vector3 Vector3::Dot(Vector3 vector1, Vector3 vector2)
	{
		return Vector3(
			(vector1.x * vector2.x),
			(vector1.y * vector2.y),
			(vector1.z * vector2.z)
		);
	}

	Vector3 Vector3::Normalize()
	{

		float size = Magnitude();

		float ax = x / size;
		float ay = y / size;
		float az = z / size;


		return Vector3(ax, ay, az);
	}

	float Vector3::Magnitude()
	{
		float sq = oprt->inv_sqrt((x * x) + (y * y) + (z * z));
		return sq;
	}
}