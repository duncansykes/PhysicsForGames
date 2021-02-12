#pragma once
#include <math.h>
#include <glm/glm.hpp>
template <typename T> class tVector2;
template <typename T> class tVector3;
template <typename T> class tVector4;
template <typename T> class tMatrix2;
template <typename T> class tMatrix3;
template <typename T> class tMatrix4;
namespace mathfs
{
	template <typename T>
	class tVector2
	{
	public:
		T i, j;
		tVector2();
		tVector2(T i, T j);
		tVector2(const tVector3<T>& v3);

		glm::vec2 vectorToglm() { return glm::vec2(i, j); }
		tVector2 operator  +(const tVector2<T>& v2) const;
		tVector2 operator  -(const tVector2<T>& v2) const;
		tVector2 operator  *(float f)               const;
		float    operator  *(const tVector2<T>& v2) const;

		tVector2 operator +=(const tVector2<T>& v2);
		tVector2 operator -=(const tVector2<T>& v2);
		tVector2 operator *=(float f);

		operator tVector2<int>()    const { return tVector2<int>((int)i, (int)j); }
		operator tVector2<float>()  const { return tVector2<float>((float)i, (float)j); }
		operator tVector2<double>() const { return tVector2<double>((double)i, (double)j); }

		tVector2 Normalise();
		float    Magnitude();
		float    MagnitudeSqrd();
	};

	template <typename T>
	class tVector3
	{
	public:
		T i, j, k;
		tVector3();
		tVector3(T i, T j, T k);
		tVector3(const tVector2<T>& v2);
		tVector3(const tVector4<T>& v4);

		tVector3 operator  +(const tVector3<T>& v3) const;
		tVector3 operator  -(const tVector3<T>& v3) const;
		tVector3 operator  *(float f)               const;
		float    operator  *(const tVector3<T>& v3) const;
		tVector3 operator  %(const tVector3<T>& v3) const;

		tVector3 operator +=(const tVector3<T>& v3);
		tVector3 operator -=(const tVector3<T>& v3);
		tVector3 operator *=(float f);

		operator tVector3<int>()    const { return tVector3<int>((int)i, (int)j, (int)k); }
		operator tVector3<float>()  const { return tVector3<float>((float)i, (float)j, (float)k); }
		operator tVector3<double>() const { return tVector3<double>((double)i, (double)j, (double)k); }

		tVector3 Normalise();
		float    Magnitude();
		float    MagnitudeSqrd();
		void     PerspectiveDiv();
	};

	template <typename T>
	class tVector4
	{
	public:
		T i, j, k, w;
		tVector4();
		tVector4(T i, T j, T k, T w);
		tVector4(const tVector3<T>& v3);

		glm::vec4 vectortoglm() { return glm::vec4(i, j, k, w); }

		tVector4 operator  +(const tVector4<T>& v4) const;
		tVector4 operator  -(const tVector4<T>& v4) const;
		tVector4 operator  *(float f)               const;
		tVector4 operator  *(const tMatrix4<T>& m4) const;
		float    operator  *(const tVector4<T>& v4) const;
		tVector4 operator  %(const tVector4<T>& v4) const;

		tVector4 operator +=(const tVector4<T>& v4);
		tVector4 operator -=(const tVector4<T>& v4);
		tVector4 operator *=(float f);

		operator tVector4<int>()    const { return tVector4<int>((int)i, (int)j, (int)k, (int)w); }
		operator tVector4<float>()  const { return tVector4<float>((float)i, (float)j, (float)k, (float)w); }
		operator tVector4<double>() const { return tVector4<double>((double)i, (double)j, (double)k, (double)w); }

		tVector4 Normalise();
		float    Magnitude();
		float    MagnitudeSqrd();
		void     PerspectiveDiv();
	};

	template <typename T>
	class tMatrix2
	{
	public:
		T i1, j1,
			i2, j2;
		tMatrix2();
		tMatrix2(T i1, T j1,
			T i2, T j2);

		tMatrix2    operator  +(const tMatrix2<T>& m2) const;
		tMatrix2    operator  -(const tMatrix2<T>& m2) const;
		tMatrix2    operator  *(float f)               const;
		tVector2<T> operator  *(const tVector2<T>& v2) const;
		tMatrix2    operator  *(const tMatrix2<T>& m2) const;

		tMatrix2    operator +=(const tMatrix2<T>& m2);
		tMatrix2    operator -=(const tMatrix2<T>& m2);
		tMatrix2    operator *=(float f);

		operator tMatrix2<int>()    const
		{
			return tMatrix2<int>
				((int)i1, (int)j1,
				(int)i2, (int)j2);
		}
		operator tMatrix2<float>()  const
		{
			return tMatrix2<float>
				((float)i1, (float)j1,
				(float)i2, (float)j2);
		}
		operator tMatrix2<double>() const
		{
			return tMatrix2<double>
				((double)i1, (double)j1,
				(double)i2, (double)j2);
		}

		static tMatrix2 CreateRotation(float radians);
	};

	template <typename T>
	class tMatrix3
	{
	public:
		T i1, j1, k1,
			i2, j2, k2,
			i3, j3, k3;
		tMatrix3();
		tMatrix3(T i1, T j1, T k1,
			T i2, T j2, T k2,
			T i3, T j3, T k3);
		tMatrix3(const tMatrix2<T>& m2);
		tMatrix3(const tMatrix4<T>& m4);

		tMatrix3    operator  +(const tMatrix3<T>& m3) const;
		tMatrix3    operator  -(const tMatrix3<T>& m3) const;
		tMatrix3    operator  *(float f)               const;
		tVector3<T> operator  *(const tVector3<T>& v3) const;
		tMatrix3    operator  *(const tMatrix3<T>& m3) const;

		tMatrix3    operator +=(const tMatrix3<T>& m3);
		tMatrix3    operator -=(const tMatrix3<T>& m3);
		tMatrix3    operator *=(float f);

		operator tMatrix3<int>()    const
		{
			return tMatrix3<int>
				((int)i1, (int)j1, (int)k1,
				(int)i2, (int)j2, (int)k2,
					(int)i3, (int)j3, (int)k3);
		}
		operator tMatrix3<float>()  const
		{
			return tMatrix3<float>
				((float)i1, (float)j1, (float)k1,
				(float)i2, (float)j2, (float)k2,
					(float)i3, (float)j3, (float)k3);
		}
		operator tMatrix3<double>() const
		{
			return tMatrix3<double>
				((double)i1, (double)j1, (double)k1,
				(double)i2, (double)j2, (double)k2,
					(double)i3, (double)j3, (double)k3);
		}

		static tMatrix3 CreateRotationX(float radians);
		static tMatrix3 CreateRotationY(float radians);
		static tMatrix3 CreateRotationZ(float radians);
		static tMatrix3 CreateTranslate(const tVector3<T>& translation);
		static tMatrix3 CreateScale(const tVector3<T>& scale);
		float Determinant(const tMatrix3<T>& m3);
		tMatrix3 Inverse(const tMatrix3<T>& m3);
	};

	template <typename T>
	class tMatrix4
	{
	public:
		T i1, j1, k1, w1,
			i2, j2, k2, w2,
			i3, j3, k3, w3,
			i4, j4, k4, w4;
		tMatrix4();
		tMatrix4(T i1, T j1, T k1, T w1,
			T i2, T j2, T k2, T w2,
			T i3, T j3, T k3, T w3,
			T i4, T j4, T k4, T w4);
		tMatrix4(const tMatrix3<T>& m3);

		tMatrix4    operator  +(const tMatrix4<T>& m4) const;
		tMatrix4    operator  -(const tMatrix4<T>& m4) const;
		tMatrix4    operator  *(float f)     	       const;
		tVector4<T> operator  *(const tVector4<T>& v4) const;
		tMatrix4    operator  *(const tMatrix4<T>& m4) const;

		tMatrix4    operator +=(const tMatrix4<T>& m4);
		tMatrix4    operator -=(const tMatrix4<T>& m4);
		tMatrix4    operator *=(float f);

		operator tMatrix4<int>()    const
		{
			return tMatrix4<int>
				((int)i1, (int)j1, (int)k1, (int)w1,
				(int)i2, (int)j2, (int)k2, (int)w2,
					(int)i3, (int)j3, (int)k3, (int)w3,
					(int)i4, (int)j4, (int)k4, (int)w4);
		}
		operator tMatrix4<float>()  const
		{
			return tMatrix4<float>
				((float)i1, (float)j1, (float)k1, (float)w1,
				(float)i2, (float)j2, (float)k2, (float)w2,
					(float)i3, (float)j3, (float)k3, (float)w3,
					(float)i4, (float)j4, (float)k4, (float)w4);
		}
		operator tMatrix4<double>() const
		{
			return tMatrix4<double>
				((double)i1, (double)j1, (double)k1, (double)w1,
				(double)i2, (double)j2, (double)k2, (double)w2,
					(double)i3, (double)j3, (double)k3, (double)w3,
					(double)i4, (double)j4, (double)k4, (double)w4);
		}

		static tMatrix4 CreateRotationX(float radians);
		static tMatrix4 CreateRotationY(float radians);
		static tMatrix4 CreateRotationZ(float radians);
		static tMatrix4 CreateTranslate(const tVector3<T>& translation);
		static tMatrix4 CreateScale(const tVector3<T>& scale);
		float    Determinant(const tMatrix4<T>& m4);
		tMatrix4 Inverse(const tMatrix4<T>& m4);

		static tMatrix4 CreateProjMatrix(float aspectRatio, float fov, float nearZ, float farZ);
		static tMatrix4 CreateRescale(float screenWidth, float screenHeight);
	};

	typedef tVector2<float> Vector2;
	typedef tVector3<float> Vector3;
	typedef tVector4<float> Vector4;
	typedef tMatrix2<float> Matrix2;
	typedef tMatrix3<float> Matrix3;
	typedef tMatrix4<float> Matrix4;

#pragma region tVector2
	template <typename T>
	tVector2<T>::tVector2()
	{
		i = 0; j = 0;
	}
	template <typename T>
	tVector2<T>::tVector2(T i, T j)
	{
		this->i = i; this->j = j;
	}

	template <typename T>
	tVector2<T> tVector2<T>::operator +(const tVector2& v2) const
	{
		return tVector2(i + v2.i, j + v2.j);
	}
	template <typename T>
	tVector2<T> tVector2<T>::operator -(const tVector2& v2) const
	{
		return tVector2(i - v2.i, j - v2.j);
	}
	template <typename T>
	tVector2<T> tVector2<T>::operator *(float f) const
	{
		return tVector2(f * i, f * j);
	}
	template <typename T>
	float tVector2<T>::operator *(const tVector2& v3) const
	{
		return i * v3.i + j * v3.j;
	}
	template <typename T>
	tVector2<T> tVector2<T>::operator +=(const tVector2<T>& v2)
	{
		i += v2.i; j += v2.j;
		return *this;
	}
	template <typename T>
	tVector2<T> tVector2<T>::operator -=(const tVector2<T>& v2)
	{
		i -= v2.i; j -= v2.j;
		return *this;
	}
	template <typename T>
	tVector2<T> tVector2<T>::operator *=(float f)
	{
		i *= f;  j *= f;
		return *this;
	}
	template <typename T>
	tVector2<T> tVector2<T>::Normalise()
	{
		float f = 1.0f / sqrtf(i * i + j * j);
		return tVector2(this->i * f, this->j * f);
	}
	template <typename T>
	float tVector2<T>::Magnitude()
	{
		return sqrt(i * i + j * j);
	}
	template <typename T>
	float tVector2<T>::MagnitudeSqrd()
	{
		return i * i + j * j;
	}
#pragma endregion

#pragma region tVector3
	template <typename T>
	tVector3<T>::tVector3()
	{
		i = 0; j = 0; k = 0;
	}
	template <typename T>
	tVector3<T>::tVector3(T i, T j, T k)
	{
		this->i = i; this->j = j; this->k = k;
	}
	template <typename T>
	tVector3<T>::tVector3(const tVector2<T>& v2)
	{
		i = v2.i; j = v2.j; k = 0;
	}

	template <typename T>
	tVector3<T> tVector3<T>::operator +(const tVector3<T>& v3) const
	{
		return tVector3(i + v3.i, j + v3.j, k + v3.k);
	}
	template <typename T>
	tVector3<T> tVector3<T>::operator -(const tVector3<T>& v3) const
	{
		return tVector3(i - v3.i, j - v3.j, k - v3.k);
	}
	template <typename T>
	tVector3<T> tVector3<T>::operator *(float f) const
	{
		return tVector3(f * i, f * j, f * k);
	}
	template <typename T>
	float tVector3<T>::operator *(const tVector3<T>& v3) const
	{
		return i * v3.i + j * v3.j + k * v3.k;
	}
	template <typename T>
	tVector3<T> tVector3<T>::operator %(const tVector3<T>& v3) const
	{
		return tVector3(j * v3.k - k * v3.j, k * v3.i - i * v3.k, i * v3.j - j * v3.i);
	}
	template <typename T>
	tVector3<T> tVector3<T>::operator +=(const tVector3<T>& v3)
	{
		i += v3.i; j += v3.j; k += v3.k;
		return *this;
	}
	template <typename T>
	tVector3<T> tVector3<T>::operator -=(const tVector3<T>& v3)
	{
		i -= v3.i; j -= v3.j; k -= v3.k;
		return *this;
	}
	template <typename T>
	tVector3<T> tVector3<T>::operator *=(float f)
	{
		i *= f;  j *= f; k *= f;
		return *this;
	}
	template <typename T>
	tVector3<T> tVector3<T>::Normalise()
	{
		float f = 1.0f / sqrt(i * i + j * j + k * k);
		return tVector3(this->i * f, this->j * f, this->k * f);
	}
	template <typename T>
	float tVector3<T>::Magnitude()
	{
		return sqrt(i * i + j * j + k * k);
	}
	template <typename T>
	float tVector3<T>::MagnitudeSqrd()
	{
		return i * i + j * j + k * k;
	}
	template <typename T>
	void tVector3<T>::PerspectiveDiv()
	{
		float f = 1.0f / k;
		i *= f;
		j *= f;
	}
#pragma endregion

#pragma region tVector4
	template <typename T>
	tVector4<T>::tVector4()
	{
		i = 0; j = 0; k = 0; w = 0;
	}
	template <typename T>
	tVector4<T>::tVector4(T i, T j, T k, T w)
	{
		this->i = i; this->j = j; this->k = k; this->w = w;
	}
	template <typename T>
	tVector4<T>::tVector4(const tVector3<T>& v3)
	{
		i = v3.i; j = v3.j; k = v3.k; w = 1;
	}
	template <typename T>
	tVector4<T> tVector4<T>::operator +(const tVector4<T>& v4) const
	{
		return tVector4(i + v4.i, j + v4.j, k + v4.k, w + v4.w);
	}
	template <typename T>
	tVector4<T> tVector4<T>::operator -(const tVector4<T>& v4) const
	{
		return tVector4(i - v4.i, j - v4.j, k - v4.k, w - v4.w);
	}
	template <typename T>
	tVector4<T> tVector4<T>::operator *(float f) const
	{
		return tVector4(f * i, f * j, f * k, f * w);
	}

	template<typename T>
	inline float tVector4<T>::operator*(const tVector4<T>& v4) const
	{
		return 0.0f;
	}
	template <typename T>
	tVector4<T> tVector4<T>::operator %(const tVector4<T>& v4) const
	{
		return tVector4(j * v4.k - k * v4.j, k * v4.i - i * v4.k, i * v4.j - j * v4.i, 0);
	}
	template <typename T>
	tVector4<T> tVector4<T>::operator +=(const tVector4<T>& v4)
	{
		i += v4.i; j += v4.j; k += v4.k; w += v4.w;
		return *this;
	}
	template <typename T>
	tVector4<T> tVector4<T>::operator -=(const tVector4<T>& v4)
	{
		i -= v4.i; j -= v4.j; k -= v4.k; w -= v4.w;
		return *this;
	}
	template <typename T>
	tVector4<T> tVector4<T>::operator *=(float f)
	{
		i *= f;  j *= f; k *= f; w *= f;
		return *this;
	}
	template <typename T>
	tVector4<T> tVector4<T>::Normalise()
	{
		float f = 1.0f / sqrt(i * i + j * j + k * k);
		return tVector4(this->i * f, this->j * f, this->k * f, this->w);
	}
	template <typename T>
	float tVector4<T>::Magnitude()
	{
		return sqrt(i * i + j * j + k * k);
	}
	template <typename T>
	float tVector4<T>::MagnitudeSqrd()
	{
		return i * i + j * j + k * k;
	}
	template <typename T>
	void tVector4<T>::PerspectiveDiv()
	{
		float f = 1.0f / w;
		i *= f;
		j *= f;
		k *= f;
	}
#pragma endregion

#pragma region tMatrix2
	template <typename T>
	tMatrix2<T>::tMatrix2()
	{
		i1 = 1; j1 = 0;
		i2 = 0; j2 = 1;
	}
	template <typename T>
	tMatrix2<T>::tMatrix2(T i1, T j1,
		T i2, T j2)
	{
		this->i1 = i1; this->j1 = j1;
		this->i2 = i2; this->j2 = j2;
	}
	template <typename T>
	tMatrix2<T> tMatrix2<T>::operator +(const tMatrix2<T>& m2) const
	{
		return tMatrix2(i1 + m2.i1, j1 + m2.j1,
			i2 + m2.i2, j2 + m2.j2);
	}
	template <typename T>
	tMatrix2<T> tMatrix2<T>::operator -(const tMatrix2<T>& m2) const
	{
		return tMatrix2(i1 - m2.i1, j1 - m2.j1,
			i2 - m2.i2, j2 - m2.j2);
	}
	template <typename T>
	tMatrix2<T> tMatrix2<T>::operator *(float f) const
	{
		return tMatrix2(f * i1, f * j1,
			f * i2, f * j2);
	}
	template <typename T>
	tVector2<T> tMatrix2<T>::operator *(const tVector2<T>& v2) const
	{
		return tVector2<T>(i1 * v2.i + j1 * v2.j, i2 * v2.i + j2 * v2.j);
	}
	template <typename T>
	tMatrix2<T> tMatrix2<T>::operator *(const tMatrix2<T>& m2) const
	{
		return tMatrix2(i1 * m2.i1 + j1 * m2.i2, i1 * m2.j1 + j1 * m2.j2,
			i2 * m2.i1 + j2 * m2.i2, i2 * m2.j1 + j2 * m2.j2);
	}
	template <typename T>
	tMatrix2<T> tMatrix2<T>::operator +=(const tMatrix2<T>& m2)
	{
		i1 += m2.i1; j1 += m2.j1; i2 += m2.i2; j2 += m2.j2;
		return *this;
	}
	template <typename T>
	tMatrix2<T> tMatrix2<T>::operator -=(const tMatrix2<T>& m2)
	{
		i1 -= m2.i1; j1 -= m2.j1; i2 -= m2.i2; j2 -= m2.j2;
		return *this;
	}
	template <typename T>
	tMatrix2<T> tMatrix2<T>::operator *=(float f)
	{
		i1 *= f;  j1 *= f; i2 *= f; j2 *= f;
		return *this;
	}
	template <typename T>
	tMatrix2<T> tMatrix2<T>::CreateRotation(float radians)
	{
		float c = cos(radians), s = sin(radians);
		return tMatrix2(c, s, -s, c);
	}
#pragma endregion

#pragma region tMatrix3
	template <typename T>
	tMatrix3<T>::tMatrix3()
	{
		i1 = 1; j1 = 0; k1 = 0;
		i2 = 0; j2 = 1; k2 = 0;
		i3 = 0; j3 = 0; k3 = 1;
	}
	template <typename T>
	tMatrix3<T>::tMatrix3(T i1, T j1, T k1,
		T i2, T j2, T k2,
		T i3, T j3, T k3)
	{
		this->i1 = i1; this->j1 = j1; this->k1 = k1;
		this->i2 = i2; this->j2 = j2; this->k2 = k2;
		this->i3 = i3; this->j3 = j3; this->k3 = k3;
	}
	template <typename T>
	tMatrix3<T>::tMatrix3(const tMatrix2<T>& m2)
	{
		i1 = m2.i1; j1 = m2.j1;  k1 = 0;
		i2 = m2.i2; j2 = m2.j2;  k2 = 0;
		i3 = 0;     j3 = 0;      k3 = 1;
	}

	template <typename T>
	tMatrix3<T> tMatrix3<T>::operator +(const tMatrix3<T>& m3) const
	{
		return tMatrix3(i1 + m3.i1, j1 + m3.j1, k1 + m3.k1,
			i2 + m3.i2, j2 + m3.j2, k2 + m3.k2,
			i3 + m3.i3, j3 + m3.j3, k3 + m3.k3);
	}
	template <typename T>
	tMatrix3<T> tMatrix3<T>::operator -(const tMatrix3<T>& m3) const
	{
		return tMatrix3(i1 - m3.i1, j1 - m3.j1, k1 - m3.k1,
			i2 - m3.i2, j2 - m3.j2, k2 - m3.k2,
			i3 - m3.i3, j3 - m3.j3, k3 - m3.k3);
	}
	template <typename T>
	tMatrix3<T> tMatrix3<T>::operator *(float f) const
	{
		return tMatrix3(f * i1, f * j1, f * k1,
			f * i2, f * j2, f * k2,
			f * i3, f * j3, f * k3);
	}
	template <typename T>
	tVector3<T> tMatrix3<T>::operator *(const tVector3<T>& v3) const
	{
		return tVector3<T>(i1 * v3.i + j1 * v3.j + k1 * v3.k,
			i2 * v3.i + j2 * v3.j + k2 * v3.k,
			i3 * v3.i + j3 * v3.j + k3 * v3.k);
	}
	template <typename T>
	tMatrix3<T> tMatrix3<T>::operator *(const tMatrix3<T>& m3) const
	{
		return tMatrix3<T>(i1 * m3.i1 + j1 * m3.i2 + k1 * m3.i3,
			i1 * m3.j1 + j1 * m3.j2 + k1 * m3.j3,
			i1 * m3.k1 + j1 * m3.k2 + k1 * m3.k3,

			i2 * m3.i1 + j2 * m3.i2 + k2 * m3.i3,
			i2 * m3.j1 + j2 * m3.j2 + k2 * m3.j3,
			i2 * m3.k1 + j2 * m3.k2 + k2 * m3.k3,

			i3 * m3.i1 + j3 * m3.i2 + k3 * m3.i3,
			i3 * m3.j1 + j3 * m3.j2 + k3 * m3.j3,
			i3 * m3.k1 + j3 * m3.k2 + k3 * m3.k3);
	}
	template <typename T>
	tMatrix3<T> tMatrix3<T>::operator +=(const tMatrix3<T>& m3)
	{
		i1 += m3.i1; j1 += m3.j1; k1 += m3.k1; i2 += m3.i2; j2 += m3.j2; k2 += m3.k2; i3 += m3.i3; j3 += m3.j3; k3 += m3.k3;
		return *this;
	}
	template <typename T>
	tMatrix3<T> tMatrix3<T>::operator -=(const tMatrix3<T>& m3)
	{
		i1 -= m3.i1; j1 -= m3.j1; k1 -= m3.k1; i2 -= m3.i2; j2 -= m3.j2; k2 -= m3.k2; i3 -= m3.i3; j3 -= m3.j3; k3 -= m3.k3;
		return *this;
	}
	template <typename T>
	tMatrix3<T> tMatrix3<T>::operator *=(float f)
	{
		i1 *= f;  j1 *= f; k1 *= f; i2 *= f; j2 *= f; k2 *= f; i3 *= f; j3 *= f; k3 *= f;
		return *this;
	}
	template <typename T>
	tMatrix3<T> tMatrix3<T>::CreateRotationX(float radians)
	{
		float c = cos(radians), s = sin(radians);
		return tMatrix3(1, 0, 0, 0, c, -s, 0, s, c);
	}
	template <typename T>
	tMatrix3<T> tMatrix3<T>::CreateRotationY(float radians)
	{
		float c = cos(radians), s = sin(radians);
		return tMatrix3(c, 0, s, 0, 1, 0, -s, 0, c);
	}
	template <typename T>
	tMatrix3<T> tMatrix3<T>::CreateRotationZ(float radians)
	{
		float c = cos(radians), s = sin(radians);
		return tMatrix3(c, -s, 0, s, c, 0, 0, 0, 1);
	}
	template <typename T>
	tMatrix3<T> tMatrix3<T>::CreateTranslate(const tVector3<T>& translation)
	{
		return tMatrix3(1, 0, 0, 0, 1, 0, translation.i, translation.j, translation.k);
	}
	template <typename T>
	tMatrix3<T> tMatrix3<T>::CreateScale(const tVector3<T>& scale)
	{
		return tMatrix3(scale.i, 0, 0, 0, scale.j, 0, 0, 0, scale.k);
	}
	template <typename T>
	float tMatrix3<T>::Determinant(const tMatrix3<T>& m3)
	{
		return m3.i1 * (m3.j2 * m3.k3 - m3.j3 * m3.k2)
			- m3.j1 * (m3.i2 * m3.k3 - m3.i3 * m3.k2)
			+ m3.k1 * (m3.i2 * m3.j3 - m3.i3 * m3.j2);
	}
	template <typename T>
	tMatrix3<T> tMatrix3<T>::Inverse(const tMatrix3<T>& m3)
	{
		return tMatrix3(
			+m3.j2 * m3.k3 - m3.j3 * m3.k2,
			-m3.j1 * m3.k3 + m3.j3 * m3.k1,
			+m3.j1 * m3.k2 - m3.j2 * m3.k1,

			-m3.i2 * m3.k3 + m3.i3 * m3.k2,
			+m3.i1 * m3.k3 - m3.i3 * m3.k1,
			-m3.i1 * m3.k2 + m3.i2 * m3.k1,

			+m3.i2 * m3.j3 - m3.i3 * m3.j2,
			-m3.i1 * m3.j3 + m3.i3 * m3.j1,
			+m3.i1 * m3.j2 - m3.i2 * m3.j1)
			* (1.0f / Determinant(m3));
	}
#pragma endregion

#pragma region tMatrix4
	template <typename T>
	tMatrix4<T>::tMatrix4()
	{
		i1 = 1; j1 = 0; k1 = 0; w1 = 0;
		i2 = 0; j2 = 1; k2 = 0; w2 = 0;
		i3 = 0; j3 = 0; k3 = 1; w3 = 0;
		i4 = 0; j4 = 0; k4 = 0; w4 = 1;
	}
	template <typename T>
	tMatrix4<T>::tMatrix4(T i1, T j1, T k1, T w1,
		T i2, T j2, T k2, T w2,
		T i3, T j3, T k3, T w3,
		T i4, T j4, T k4, T w4)
	{
		this->i1 = i1; this->j1 = j1; this->k1 = k1; this->w1 = w1;
		this->i2 = i2; this->j2 = j2; this->k2 = k2; this->w2 = w2;
		this->i3 = i3; this->j3 = j3; this->k3 = k3; this->w3 = w3;
		this->i4 = i4; this->j4 = j4; this->k4 = k4; this->w4 = w4;
	}
	template <typename T>
	tMatrix4<T>::tMatrix4(const tMatrix3<T>& m3)
	{
		i1 = m3.i1; j1 = m3.j1; k1 = m3.k1; w1 = 0;
		i2 = m3.i2; j2 = m3.j2; k2 = m3.k2; w2 = 0;
		i3 = m3.i3; j3 = m3.j3; k3 = m3.k3; w3 = 0;
		i4 = 0;     j4 = 0;     k4 = 0;     w4 = 1;
	}
	template <typename T>
	tMatrix4<T> tMatrix4<T>::operator +(const tMatrix4<T>& m4) const
	{
		return tMatrix4(i1 + m4.i1, j1 + m4.j1, k1 + m4.k1, w1 + m4.w1,
			i2 + m4.i2, j2 + m4.j2, k2 + m4.k2, w2 + m4.w2,
			i3 + m4.i3, j3 + m4.j3, k3 + m4.k3, w3 + m4.w3,
			i4 + m4.i4, j4 + m4.j4, k4 + m4.k4, w4 + m4.w4);
	}
	template <typename T>
	tMatrix4<T> tMatrix4<T>::operator -(const tMatrix4<T>& m4) const
	{
		return tMatrix4(i1 - m4.i1, j1 - m4.j1, k1 - m4.k1, w1 - m4.w1,
			i2 - m4.i2, j2 - m4.j2, k2 - m4.k2, w2 - m4.w2,
			i3 - m4.i3, j3 - m4.j3, k3 - m4.k3, w3 - m4.w3,
			i4 - m4.i4, j4 - m4.j4, k4 - m4.k4, w4 - m4.w4);
	}
	template <typename T>
	tMatrix4<T> tMatrix4<T>::operator *(float f) const
	{
		return tMatrix4(f * i1, f * j1, f * k1, f * w1,
			f * i2, f * j2, f * k2, f * w2,
			f * i3, f * j3, f * k3, f * w3,
			f * i4, f * j4, f * k4, f * w4);
	}
	template <typename T>
	tVector4<T> tMatrix4<T>::operator *(const tVector4<T>& v4) const
	{
		return tVector4<T>(i1 * v4.i + j1 * v4.j + k1 * v4.k + w1 * v4.w,
			i2 * v4.i + j2 * v4.j + k2 * v4.k + w2 * v4.w,
			i3 * v4.i + j3 * v4.j + k3 * v4.k + w3 * v4.w,
			i4 * v4.i + j4 * v4.j + k4 * v4.k + w4 * v4.w);
	}
	template <typename T>
	tMatrix4<T> tMatrix4<T>::operator *(const tMatrix4<T>& m4) const
	{
		return tMatrix4(i1 * m4.i1 + j1 * m4.i2 + k1 * m4.i3 + w1 * m4.i4,
			i1 * m4.j1 + j1 * m4.j2 + k1 * m4.j3 + w1 * m4.j4,
			i1 * m4.k1 + j1 * m4.k2 + k1 * m4.k3 + w1 * m4.k4,
			i1 * m4.w1 + j1 * m4.w2 + k1 * m4.w3 + w1 * m4.w4,

			i2 * m4.i1 + j2 * m4.i2 + k2 * m4.i3 + w2 * m4.i4,
			i2 * m4.j1 + j2 * m4.j2 + k2 * m4.j3 + w2 * m4.j4,
			i2 * m4.k1 + j2 * m4.k2 + k2 * m4.k3 + w2 * m4.k4,
			i2 * m4.w1 + j2 * m4.w2 + k2 * m4.w3 + w2 * m4.w4,

			i3 * m4.i1 + j3 * m4.i2 + k3 * m4.i3 + w3 * m4.i4,
			i3 * m4.j1 + j3 * m4.j2 + k3 * m4.j3 + w3 * m4.j4,
			i3 * m4.k1 + j3 * m4.k2 + k3 * m4.k3 + w3 * m4.k4,
			i3 * m4.w1 + j3 * m4.w2 + k3 * m4.w3 + w3 * m4.w4,

			i4 * m4.i1 + j4 * m4.i2 + k4 * m4.i3 + w4 * m4.i4,
			i4 * m4.j1 + j4 * m4.j2 + k4 * m4.j3 + w4 * m4.j4,
			i4 * m4.k1 + j4 * m4.k2 + k4 * m4.k3 + w4 * m4.k4,
			i4 * m4.w1 + j4 * m4.w2 + k4 * m4.w3 + w4 * m4.w4);
	}
	template <typename T>
	tMatrix4<T> tMatrix4<T>::operator +=(const tMatrix4<T>& m4)
	{
		i1 += m4.i1; j1 += m4.j1; k1 += m4.k1; w1 += m4.w1; i2 += m4.i2; j2 += m4.j2; k2 += m4.k2; w2 += m4.w2; i3 += m4.i3; j3 += m4.j3; k3 += m4.k3; w3 += m4.w3; i4 += m4.i4; j4 += m4.j4; k4 += m4.k4; w4 += m4.w4;
		return *this;
	}
	template <typename T>
	tMatrix4<T> tMatrix4<T>::operator -=(const tMatrix4<T>& m4)
	{
		i1 -= m4.i1; j1 -= m4.j1; k1 -= m4.k1; w1 -= m4.w1; i2 -= m4.i2; j2 -= m4.j2; k2 -= m4.k2; w2 -= m4.w2; i3 -= m4.i3; j3 -= m4.j3; k3 -= m4.k3; w3 -= m4.w3; i4 -= m4.i4; j4 -= m4.j4; k4 -= m4.k4; w4 -= m4.w4;
		return *this;
	}
	template <typename T>
	tMatrix4<T> tMatrix4<T>::operator *=(float f)
	{
		i1 *= f;  j1 *= f; k1 *= f; w1 *= f; i2 *= f; j2 *= f; k2 *= f; w2 *= f; i3 *= f; j3 *= f; k3 *= f; w3 *= f; i4 *= f; j4 *= f; k4 *= f; w4 *= f;
		return *this;
	}
	template <typename T>
	tMatrix4<T> tMatrix4<T>::CreateRotationX(float radians)
	{
		float c = cos(radians), s = sin(radians);
		return tMatrix4(1, 0, 0, 0, 0, c, -s, 0, 0, s, c, 0, 0, 0, 0, 1);
	}
	template <typename T>
	tMatrix4<T> tMatrix4<T>::CreateRotationY(float radians)
	{
		float c = cos(radians), s = sin(radians);
		return tMatrix4(c, 0, s, 0, 0, 1, 0, 0, -s, 0, c, 0, 0, 0, 0, 1);
	}
	template <typename T>
	tMatrix4<T> tMatrix4<T>::CreateRotationZ(float radians)
	{
		float c = cos(radians), s = sin(radians);
		return tMatrix4(c, -s, 0, 0, s, c, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
	}
	template <typename T>
	tMatrix4<T> tMatrix4<T>::CreateTranslate(const tVector3<T>& translation)
	{
		return tMatrix4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, translation.i, translation.j, translation.k, 1);
	}
	template <typename T>
	tMatrix4<T> tMatrix4<T>::CreateScale(const tVector3<T>& scale)
	{
		return tMatrix4(scale.i, 0, 0, 0, 0, scale.j, 0, 0, 0, 0, scale.k, 0, 0, 0, 0, 1);
	}
	template <typename T>
	float tMatrix4<T>::Determinant(const tMatrix4<T>& m4)
	{
		return +m4.i1 * (m4.j2 * (m4.k3 * m4.w4 - m4.k4 * m4.w3) - m4.k2 * (m4.j3 * m4.w4 - m4.j4 * m4.w3) + m4.w2 * (m4.j3 * m4.k4 - m4.k4 * m4.j3))
			- m4.j1 * (m4.i2 * (m4.k3 * m4.w4 - m4.k4 * m4.w3) - m4.k2 * (m4.i3 * m4.w4 - m4.i4 * m4.w3) + m4.w2 * (m4.i3 * m4.k4 - m4.i4 * m4.k3))
			+ m4.k1 * (m4.i2 * (m4.j3 * m4.w4 - m4.j4 * m4.w3) - m4.j2 * (m4.i3 * m4.w4 - m4.i4 * m4.w3) + m4.w2 * (m4.i3 * m4.j4 - m4.i4 * m4.j3))
			- m4.w1 * (m4.i2 * (m4.j3 * m4.k4 - m4.j4 * m4.k3) - m4.j2 * (m4.i3 * m4.k4 - m4.i4 * m4.k3) + m4.k2 * (m4.i3 * m4.j4 - m4.i4 * m4.j3));
	}
	template <typename T>
	tMatrix4<T> tMatrix4<T>::Inverse(const tMatrix4<T>& m4)
	{
		return tMatrix4(
			+m4.j2 * (m4.k3 * m4.w4 - m4.k4 * m4.w3) - m4.j3 * (m4.k2 * m4.w4 - m4.k4 * m4.w2) + m4.j4 * (m4.k2 * m4.w3 - m4.k3 * m4.w2),
			-m4.j1 * (m4.k3 * m4.w4 - m4.k4 * m4.w3) + m4.j3 * (m4.k1 * m4.w4 - m4.k4 * m4.w1) - m4.j4 * (m4.k1 * m4.w3 - m4.k3 * m4.w1),
			+m4.j1 * (m4.k2 * m4.w4 - m4.k4 * m4.w2) - m4.j2 * (m4.k1 * m4.w4 - m4.k4 * m4.w1) + m4.j4 * (m4.k1 * m4.w2 - m4.k2 * m4.w1),
			-m4.j1 * (m4.k2 * m4.w3 - m4.k3 * m4.w2) + m4.j2 * (m4.k1 * m4.w3 - m4.k3 * m4.w1) - m4.j3 * (m4.k1 * m4.w2 - m4.k2 * m4.w1),

			-m4.i2 * (m4.k3 * m4.w4 - m4.k4 * m4.w3) + m4.i3 * (m4.k2 * m4.w4 - m4.k4 * m4.w2) - m4.i4 * (m4.k2 * m4.w3 - m4.k3 * m4.w2),
			+m4.i1 * (m4.k3 * m4.w4 - m4.k4 * m4.w3) - m4.i3 * (m4.k1 * m4.w4 - m4.k4 * m4.w1) + m4.i4 * (m4.k1 * m4.w3 - m4.k3 * m4.w1),
			-m4.i1 * (m4.k2 * m4.w4 - m4.k4 * m4.w2) + m4.i2 * (m4.k1 * m4.w4 - m4.k4 * m4.w1) - m4.i4 * (m4.k1 * m4.w2 - m4.k2 * m4.w1),
			+m4.i1 * (m4.k2 * m4.w3 - m4.k3 * m4.w2) - m4.i2 * (m4.k1 * m4.w3 - m4.k3 * m4.w1) + m4.i3 * (m4.k1 * m4.w2 - m4.k2 * m4.w1),

			+m4.i2 * (m4.j3 * m4.w4 - m4.j4 * m4.w3) - m4.i3 * (m4.j2 * m4.w4 - m4.j4 * m4.w2) + m4.i4 * (m4.j2 * m4.w3 - m4.j3 * m4.w2),
			-m4.i1 * (m4.j3 * m4.w4 - m4.j4 * m4.w3) + m4.i3 * (m4.j1 * m4.w4 - m4.j4 * m4.w1) - m4.i4 * (m4.j1 * m4.w3 - m4.j3 * m4.w1),
			+m4.i1 * (m4.j2 * m4.w4 - m4.j4 * m4.w2) - m4.i2 * (m4.j1 * m4.w4 - m4.j4 * m4.w1) + m4.i4 * (m4.j1 * m4.w2 - m4.j2 * m4.w1),
			-m4.i1 * (m4.j2 * m4.w3 - m4.j3 * m4.w2) + m4.i2 * (m4.j1 * m4.w3 - m4.j3 * m4.w1) - m4.i3 * (m4.j1 * m4.w2 - m4.j2 * m4.w1),

			-m4.i2 * (m4.j3 * m4.k4 - m4.j4 * m4.k3) + m4.i3 * (m4.j2 * m4.k4 - m4.j4 * m4.k2) - m4.i4 * (m4.j2 * m4.k3 - m4.j3 * m4.k2),
			+m4.i1 * (m4.j3 * m4.k4 - m4.j4 * m4.k3) - m4.i3 * (m4.j1 * m4.k4 - m4.j4 * m4.k1) + m4.i4 * (m4.j1 * m4.k3 - m4.j3 * m4.k1),
			-m4.i1 * (m4.j2 * m4.k4 - m4.j4 * m4.k2) + m4.i2 * (m4.j1 * m4.k4 - m4.j4 * m4.k1) - m4.i4 * (m4.j1 * m4.k2 - m4.j2 * m4.k1),
			+m4.i1 * (m4.j2 * m4.k3 - m4.j3 * m4.k2) - m4.i2 * (m4.j1 * m4.k3 - m4.j3 * m4.k1) + m4.i3 * (m4.j1 * m4.k2 - m4.j2 * m4.k1))
			* (1.0f / Determinant(m4));
	}
	template <typename T>
	tMatrix4<T> tMatrix4<T>::CreateProjMatrix(float aspectRatio, float fov, float zNear, float zFar)
	{
		float t = 1.0f / tan(fov * 0.5f), z = zFar / (zFar - zNear);
		return tMatrix4(aspectRatio * t, 0, 0, 0, 0, t, 0, 0, 0, 0, z, 1, 0, 0, -zNear * z, 0);
	}
	template <typename T>
	tMatrix4<T> tMatrix4<T>::CreateRescale(float screenWidth, float screenHeight)
	{
		float w = screenWidth * 0.5f;
		float h = screenHeight * 0.5f;
		return tMatrix4(w, 0, 0, 0, 0, h, 0, 0, 0, 0, 1, 0, w, h, 0, 1);
	}
}
#pragma endregion
