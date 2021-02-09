#pragma once
#include "operations.h"
#include "Vector2.h"
namespace mathfs
{
	class Vector4
	{
	public:
		Vector4(float x, float y, float z, float w);
		Vector4();
		~Vector4();


		Vector4 Add(Vector4 one, Vector4 two);
		Vector4 Add(Vector4 one, Vector2 two);
		Vector4 Add(Vector2 one, Vector4 two);


		Vector4 Subtract(Vector4 one, Vector4 two);
		Vector4 Devide(Vector4 one, Vector4 two);
		Vector4 Dot(Vector4 one, Vector4 two);


		Vector4 operator+(const Vector4& a)
		{
			Vector4 temp;
			temp.x = x + a.x;
			temp.y = y + a.x;
			temp.z = z + a.z;
			temp.w = w + a.w;
			return temp;
		}
		Vector4 operator+(const Vector2& a)
		{
			Vector4 temp;
			temp.x = x + a.x;
			temp.y = y + a.x;
			temp.z = z;
			temp.w = w;
			return temp;
		}

		Vector4 operator-(const Vector4& a)
		{
			Vector4 temp;
			temp.x = x - a.x;
			temp.y = y - a.y;
			temp.z = z - a.z;
			temp.y = w - a.w;
			return temp;
		}
		Vector4 operator*(const Vector4& a)
		{
			Vector4 temp;
			temp.x = x * a.x;
			temp.y = y * a.y;
			temp.z = z * a.z;
			temp.y = w * a.w;
			return temp;

		}
		Vector4 operator/(const Vector4& a)
		{
			Vector4 temp;
			temp.x = x / a.x;
			temp.y = y / a.y;
			temp.z = z / a.z;
			temp.y = w / a.w;
			return temp;
		}
		Vector4 operator+=(const Vector4& a)
		{
			this->x += a.x;
			this->y += a.y;
			this->z += a.z;
			this->w += a.w;
			return *this;
		}







		Vector4 Normalize();

		float Magnitude();

		float x;
		float y;
		float z;
		float w;

	private:


		operations* oprt = new operations();


	};

}