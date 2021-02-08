#include "Vector4.h"
namespace mathfs
{
	Vector4::Vector4(float x, float y, float z, float w) :
		x(x), y(y), z(z), w(w)
	{
	}

	Vector4::Vector4() : x(0), y(0), z(0), w(0)
	{
	}

	Vector4::~Vector4()
	{
	}

	Vector4 Vector4::Add(Vector4 one, Vector4 two)
	{
		return Vector4(
			(one.x + two.x),
			(one.y + two.y),
			(one.z + two.z),
			(one.w + two.w));
	}

	Vector4 Vector4::Subtract(Vector4 one, Vector4 two)
	{
		return Vector4(
			(one.x - two.x),
			(one.y - two.y),
			(one.z - two.z),
			(one.w - two.w));
	}

	Vector4 Vector4::Devide(Vector4 one, Vector4 two)
	{
		return Vector4();
	}

	Vector4 Vector4::Dot(Vector4 one, Vector4 two)
	{
		return Vector4(
			(one.x * two.x),
			(one.y * two.y),
			(one.z * two.z),
			(one.w * two.w));
	}

	Vector4 Vector4::Normalize()
	{
		float size = Magnitude();

		float ax, ay, az, aw;

		ax = x / size;
		ay = y / size;
		az = z / size;
		aw = w / size;

		return Vector4(ax, ay, az, aw);
	}

	float Vector4::Magnitude()
	{
		float size = oprt->inv_sqrt((x * x) + (y * y) + (z * z) + (w * w));

		return size;
	}
}