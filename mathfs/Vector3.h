#pragma once
#include "operations.h"
#include "glm/glm.hpp"
namespace mathfs
{
	class Vector3
	{
	public:

		Vector3(float x, float y, float z);
		Vector3();
		~Vector3();

		float x;
		float y;
		float z;

		glm::vec3 vectortoglm()
		{
			return glm::vec3(x, y, z);
		}

		Vector3 operator+(const Vector3& a)
		{
			Vector3 temp;
			temp.x = x + a.x;
			temp.y = y + a.y;
			temp.z = z + a.z;
			return temp;
		}
		Vector3 operator-(const Vector3& a)
		{
			Vector3 temp;
			temp.x = x - a.x;
			temp.y = y - a.y;
			temp.z = z - a.z;
			return temp;
		}
		Vector3 operator*(const Vector3& a)
		{
			Vector3 temp;
			temp.x = x * a.x;
			temp.y = y * a.y;
			temp.z = z * a.z;
			return temp;
		}
		Vector3 operator/(const Vector3& a)
		{
			Vector3 temp;
			temp.x = x / a.x;
			temp.y = y / a.y;
			temp.z = z / a.z;
			return temp;
		}
		Vector3 operator+=(const Vector3& a)
		{
			this->x += a.x;
			this->y += a.y;
			this->z += a.z;
			return *this;
		}

		Vector3 operator+(const glm::vec3& a)
		{
			Vector3 temp;
			temp.x = x + a.x;
			temp.y = y + a.y;
			temp.z = z + a.z;
			return temp;
		}
		Vector3 operator-(const glm::vec3& a)
		{
			Vector3 temp;
			temp.x = x - a.x;
			temp.y = y - a.y;
			temp.z = z - a.z;
			return temp;
		}
		Vector3 operator*(const glm::vec3& a)
		{
			Vector3 temp;
			temp.x = x * a.x;
			temp.y = y * a.y;
			temp.z = z * a.z;
			return temp;
		}
		Vector3 operator/(const glm::vec3& a)
		{
			Vector3 temp;
			temp.x = x / a.x;
			temp.y = y / a.y;
			temp.z = z / a.z;
			return temp;
		}
		Vector3& operator+=(const glm::vec3& a)
		{
			this->x += a.x;
			this->y += a.y;
			this->z += a.z;
			return *this;
		}

		Vector3 Normalize();
		float Magnitude();

	private:
		operations* oprt = new operations();
	};

	namespace extra
	{
		inline float dot(float ax, float ay, float az,
			float bx, float by, float bz)
		{
			return (ax * bx) + (ay * by) + (az * bz);
		}

		inline float dot(Vector3 a, Vector3 b)
		{
			return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
		}

		inline float dot(glm::vec3 a, glm::vec3 b)
		{
			return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
		}

		inline float distance(Vector3 a, Vector3 b)
		{
			operations* oprt = new operations();

			float distX = a.x - b.x;
			float distY = a.y - b.y;
			float distZ = a.z - b.z;

			return oprt->inv_sqrt((distZ * distZ) + (distY * distY) + (distX * distX));
		}
	}
}