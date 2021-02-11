#pragma once
namespace mathfs
{
	class operations
	{
	public:

		operations() {};
		~operations() {};

		float inv_sqrt(float number)
		{
			long i;
			float x2, y;
			const float threehalves = 1.5f;

			x2 = number * 0.5f;
			y = number;
			i = *(long*)&y;			   // C++ floating point hack
			i = 0x5f3759df - (i >> 1); // what the fuck
			y = *(float*)&i;
			y = y * (threehalves - (x2 * y * y)); // 1st iteration
			y = y * (threehalves - (x2 * y * y)); // 2nd iteration

			return 1 / y;
		}

		float sqrt(float number)
		{
			long i;
			float x2, y;
			const float threehalves = 1.5f;

			x2 = number * 0.5f;
			y = number;
			i = *(long*)&y;			   // why
			i = 0x5f3759df - (i >> 1); // what the fuck
			y = *(float*)&i;
			y = y * (threehalves - (x2 * y * y)); // 1st iteration
			y = y * (threehalves - (x2 * y * y)); // 2nd iteration

			return y;
		}
	};
}
