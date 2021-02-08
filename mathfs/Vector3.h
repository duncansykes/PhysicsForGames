#pragma once
#include "operations.h"
namespace mathfs
{
	class Vector3
	{
	public:

		Vector3(float x, float y, float z);
		Vector3();

		~Vector3();

		Vector3 Add(Vector3 vector1, Vector3 vector2);
		
		

		Vector3 Subtract(Vector3 vector1, Vector3 vector2);

		Vector3 Dot(Vector3 vector1, Vector3 vector2);
		Vector3 Normalize();

		float Magnitude();

		float x;
		float y;
		float z;


	private:
		operations* oprt = new operations();
	};

}