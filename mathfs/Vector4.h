#pragma once
#include "operations.h"
namespace mathfs
{
	class Vector4
	{
	public:
		Vector4(float x, float y, float z, float w);
		Vector4();
		~Vector4();


		Vector4 Add(Vector4 one, Vector4 two);
		Vector4 Subtract(Vector4 one, Vector4 two);
		Vector4 Devide(Vector4 one, Vector4 two);
		Vector4 Dot(Vector4 one, Vector4 two);

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