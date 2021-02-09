#pragma once
#include "operations.h"
#include "Vector2.h"
#include "glm/glm.hpp"
namespace mathfs
{	
	class Vector4
	{
	public:

		Vector4(float x, float y, float z, float w);
		Vector4();
		~Vector4();

		float x;
		float y;
		float z;
		float w;
		
		glm::vec4 vectortoglm()
		{
			return glm::vec4(x, y, z, w);
		}

		Vector4 Add(Vector4 one, Vector4 two);

		Vector4 operator+(const Vector4& a)
		{
			Vector4 temp;
			temp.x = x + a.x;
			temp.y = y + a.x;
			temp.z = z + a.z;
			temp.w = w + a.w;
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
		Vector4& operator+=(const Vector4& a)
		{
			this->x += a.x;
			this->y += a.y;
			this->z += a.z;
			this->w += a.w;
			return *this;
		}

		Vector4 operator+(const glm::vec4& a)
		{
			Vector4 temp;
			temp.x = x + a.x;
			temp.y = y + a.y;
			temp.z = z + a.z;
			temp.w = w + a.w;

			return temp;
		}
		Vector4 operator-(const glm::vec4& a)
		{
			Vector4 temp;
			temp.x = x - a.x;
			temp.y = y - a.y;
			temp.z = z - a.z;
			temp.y = w - a.w;
			return temp;
		}
		Vector4 operator*(const glm::vec4& a)
		{
			Vector4 temp;
			temp.x = x * a.x;
			temp.y = y * a.y;
			temp.z = z * a.z;
			temp.y = w * a.w;
			return temp;
		}
		Vector4 operator/(const glm::vec4& a)
		{
			Vector4 temp;
			temp.x = x / a.x;
			temp.y = y / a.y;
			temp.z = z / a.z;
			temp.y = w / a.w;
			return temp;
		}
		Vector4& operator+=(const glm::vec4& a)
		{
			this->x += a.x;
			this->y += a.y;
			this->z += a.z;
			this->w += a.w;
			return *this;
		}

		Vector4 Normalize();
		float Magnitude();

	private:
		operations* oprt = new operations();
	};

	namespace extra
	{
		inline float dot(float ax, float ay, float az, float aw,
			float bx, float by, float bz, float bw)
		{
			return (ax * bx) + (ay * by) + (az * bz) + (aw * bw);
		};

		inline float dot(Vector4 a, Vector4 b)
		{
			float dotprod = (a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.y);
			return dotprod;
		};
	}
}