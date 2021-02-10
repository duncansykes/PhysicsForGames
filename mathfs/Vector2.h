#pragma once
#include "operations.h"
#include "glm/glm.hpp"
#include "Vector4.h"
namespace mathfs
{
	class Vector2
	{
	public:

		Vector2(float a_x, float a_y);
		Vector2();
		~Vector2();

		float x;
		float y;
		
		glm::vec2 vectorToglm()
		{
			return glm::vec2(x, y);
		}

		Vector2 Add(float x1, float y1, float x2, float y2);
		Vector2 Add(Vector2 vector_one, Vector2 vector_two);
		Vector2 Subtract(Vector2 vector_one, Vector2 vector_two);

		

		
		Vector2 operator-() {
			Vector2 temp;
			temp.x = -x;
			temp.y = -y;
			return temp;
		}
		Vector2 operator+(const Vector2& a)
		{
			Vector2 temp;
			temp.x = x + a.x;
			temp.y = y + a.y;
			return temp;
		}
		Vector2 operator*(const Vector2& a)
		{
			Vector2 temp;
			temp.x = x * a.x;
			temp.y = y * a.y;

			return temp;
		}
		Vector2 operator/(const Vector2& a)
		{
			Vector2 temp;
			temp.x = x / a.x;
			temp.y = y / a.y;
			return temp;
		}
		Vector2 operator-(const Vector2& a)
		{
			Vector2 temp;
			temp.x = x - a.x;
			temp.y = y - a.y;

			return temp;
		}
		Vector2& operator+=(const Vector2& rhs)
		{
			this->x += rhs.x;
			this->y += rhs.y;

			return *this;
		}

		Vector2 operator+(const glm::vec2& a)
		{
			Vector2 temp;
			temp.x = x + a.x;
			temp.y = y + a.y;
			return temp;
		}
		Vector2 operator*(const glm::vec2& a)
		{
			Vector2 temp;
			temp.x = x * a.x;
			temp.y = y * a.y;

			return temp;
		}
		Vector2 operator/(const glm::vec2& a)
		{
			Vector2 temp;
			temp.x = x / a.x;
			temp.y = y / a.y;
			return temp;
		}
		Vector2 operator-(const glm::vec2& a)
		{
			Vector2 temp;
			temp.x = x - a.x;
			temp.y = y - a.y;

			return temp;
		}
		Vector2& operator+=(const glm::vec2& rhs)
		{
			this->x += rhs.x;
			this->y += rhs.y;

			return *this;
		}

		Vector2 operator+(const float& a)
		{
			Vector2 temp;
			temp.x = x + a;
			temp.y = y + a;
			return temp;
		}
		Vector2 operator*(const float& a)
		{
			Vector2 temp;
			temp.x = x * a;
			temp.y = y * a;

			return temp;
		}
		Vector2 operator-(const float& a)
		{
			Vector2 temp;
			temp.x = x - a;
			temp.y = y - a;
			return temp;
		}
		Vector2 operator/(const float& a)
		{
			Vector2 temp;
			temp.x = x / a;
			temp.y = y / a;
			return temp;
		}
		Vector2& operator+=(const float& a)
		{
			this->x += a;
			this->y += a;

			return *this;
		}

		
		Vector2 Normalize();
		float Magnitude();

	private:
		operations* oprt = new operations();
	};

	namespace extra
	{

		
		
		inline float dot(Vector2 a, Vector2 b)
		{
			float dtp = (a.x * b.x) + (a.y * b.y);

			return dtp;
		};

		inline float dot(float ax, float ay, float bx, float by)
		{
			return (ax * bx) + (ay + by);
		};

		inline float distance(Vector2 a, Vector2 b)
		{
			operations* oprt = new operations();
			float distX = a.x - b.x;
			float distY = a.y - b.y;

			return oprt->inv_sqrt((distY * distY) + (distX * distX));
		};
	}
}
