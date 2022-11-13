#pragma once

#include <cmath>
#include <corecrt_math_defines.h>
#include <string>
#include <iostream>

#include "Vector3.hpp"
#include "Vector4.hpp"
#include "Utils.hpp"

namespace Math
{
	template<typename T = float>
	class Mat4x4
	{
	public:
		float data[4][4];

		Mat4x4<T>(const T p_value = 0)
		{
			for (unsigned int i = 0; i < 4; i++)
			{
				for (unsigned int j = 0; j < 4; j++)
				{
					data[i][j] = p_value;
				}
			}
		}

		Mat4x4<T>(const Mat4x4<T>& p_other)
		{
			for (unsigned int i = 0; i < 4; i++)
			{
				for (unsigned int j = 0; j < 4; j++)
				{
					data[i][j] = p_other.data[i][j];
				}
			}
		}

		Mat4x4<T>(const T f1, const T f2, const T f3, const T f4,
			   const T f5, const T f6, const T f7, const T f8,
			   const T f9, const T f10, const T f11, const T f12,
			   const T f13, const T f14, const T f15, const T f16)
		{
			data[0][0] = f1;  data[0][1] = f2;  data[0][2] = f3;  data[0][3] = f4;
			data[1][0] = f5;  data[1][1] = f6;  data[1][2] = f7;  data[1][3] = f8;
			data[2][0] = f9;  data[2][1] = f10; data[2][2] = f11; data[2][3] = f12;
			data[3][0] = f13; data[3][1] = f14; data[3][2] = f15; data[3][3] = f16;
		}

		static Mat4x4<T> Identity()
		{
			Mat4x4<T> identity;
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					if (i == j)
						identity.data[i][j] = 1;
				}
			}
			return identity;
		}

		Mat4x4<T> Transpose()
		{
			Mat4x4<T> transpose;
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					transpose.data[i][j] = data[j][i];
				}
			}
			return transpose;
		}

		Mat4x4<T> GetInverse() const
		{
			Mat4x4<T> inverse;
			float determinant = Determinant();
			if (determinant == 0)
				return Mat4x4<T>::Identity();
			Mat4x4<T> cofactorMatrix = CofactorMatrix();
			cofactorMatrix.Transpose();
			cofactorMatrix = cofactorMatrix * (1.f / determinant);
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					inverse.data[i][j] = cofactorMatrix.data[i][j];
				}
			}
			return inverse;
		}

		float Determinant() const
		{
			return data[0][0] * (data[1][1] * (data[2][2] * data[3][3] - data[2][3] * data[3][2]) - data[1][2] * (data[2][1] * data[3][3] - data[3][1] * data[2][3]) + data[1][3] * (data[2][1] * data[3][2] - data[2][2] * data[3][1]))
				- data[0][1] * (data[1][0] * (data[2][2] * data[3][3] - data[2][3] * data[3][2]) - data[1][2] * (data[2][0] * data[3][3] - data[3][0] * data[2][3]) + data[1][3] * (data[2][0] * data[3][2] - data[2][2] * data[3][0]))
				+ data[0][2] * (data[1][0] * (data[2][1] * data[3][3] - data[2][3] * data[3][1]) - data[1][1] * (data[2][0] * data[3][3] - data[3][0] * data[2][3]) + data[1][3] * (data[2][0] * data[3][1] - data[2][1] * data[3][0]))
				- data[0][3] * (data[1][0] * (data[2][1] * data[3][2] - data[2][2] * data[3][1]) - data[1][1] * (data[2][0] * data[3][2] - data[3][0] * data[2][2]) + data[1][2] * (data[2][0] * data[3][1] - data[2][1] * data[3][0]));
		}

		Mat4x4<T> CofactorMatrix() const
		{
			Mat4x4<T> Cof;

			Cof.data[0][0] = data[1][1] * (data[2][2] * data[3][3] - data[3][2] * data[2][3]) - data[1][2] * (data[2][1] * data[3][3] - data[3][1] * data[2][3]) + data[1][3] * (data[2][1] * data[3][2] - data[2][2] * data[3][1]);
			Cof.data[0][1] = -(data[1][0] * (data[2][2] * data[3][3] - data[2][3] * data[3][2]) - data[1][2] * (data[2][0] * data[3][3] - data[3][0] * data[2][3]) + data[1][3] * (data[2][0] * data[3][2] - data[2][2] * data[3][0]));
			Cof.data[0][2] = data[1][0] * (data[2][1] * data[3][3] - data[2][3] * data[3][1]) - data[1][1] * (data[2][0] * data[3][3] - data[3][0] * data[2][3]) + data[1][3] * (data[2][0] * data[3][1] - data[2][1] * data[3][0]);
			Cof.data[0][3] = -(data[1][0] * (data[2][1] * data[3][2] - data[2][2] * data[3][1]) - data[1][1] * (data[2][0] * data[3][2] - data[3][0] * data[2][2]) + data[1][2] * (data[2][0] * data[3][1] - data[2][1] * data[3][0]));

			Cof.data[1][0] = -(data[0][1] * (data[2][2] * data[3][3] - data[3][2] * data[2][3]) - data[0][2] * (data[2][1] * data[3][3] - data[3][1] * data[2][3]) + data[0][3] * (data[2][1] * data[3][2] - data[2][2] * data[3][1]));
			Cof.data[1][1] = data[0][0] * (data[2][2] * data[3][3] - data[2][3] * data[3][2]) - data[0][2] * (data[2][0] * data[3][3] - data[3][0] * data[2][3]) + data[0][3] * (data[2][0] * data[3][2] - data[2][2] * data[3][0]);
			Cof.data[1][2] = -(data[0][0] * (data[2][1] * data[3][3] - data[2][3] * data[3][1]) - data[0][1] * (data[2][0] * data[3][3] - data[3][0] * data[2][3]) + data[0][3] * (data[2][0] * data[3][1] - data[2][1] * data[3][0]));
			Cof.data[1][3] = data[0][0] * (data[2][1] * data[3][2] - data[2][2] * data[3][1]) - data[0][1] * (data[2][0] * data[3][2] - data[3][0] * data[2][2]) + data[0][2] * (data[2][0] * data[3][1] - data[2][1] * data[3][0]);
			Cof.data[2][0] = data[0][1] * (data[1][2] * data[3][3] - data[3][2] * data[1][3]) - data[0][2] * (data[1][1] * data[3][3] - data[3][1] * data[1][3]) + data[0][3] * (data[1][1] * data[3][2] - data[1][2] * data[3][1]);
			Cof.data[2][1] = -(data[0][0] * (data[1][2] * data[3][3] - data[1][3] * data[3][2]) - data[0][2] * (data[1][0] * data[3][3] - data[3][0] * data[1][3]) + data[0][3] * (data[1][0] * data[3][2] - data[1][2] * data[3][0]));
			Cof.data[2][2] = data[0][0] * (data[1][1] * data[3][3] - data[1][3] * data[3][1]) - data[0][1] * (data[1][0] * data[3][3] - data[3][0] * data[1][3]) + data[0][3] * (data[1][0] * data[3][1] - data[1][1] * data[3][0]);
			Cof.data[2][3] = -(data[0][0] * (data[1][1] * data[3][2] - data[1][2] * data[3][1]) - data[0][1] * (data[1][0] * data[3][2] - data[3][0] * data[1][2]) + data[0][2] * (data[1][0] * data[3][1] - data[1][1] * data[3][0]));

			Cof.data[3][0] = -(data[0][1] * (data[1][2] * data[2][3] - data[2][2] * data[1][3]) - data[0][2] * (data[1][1] * data[2][3] - data[2][1] * data[1][3]) + data[0][3] * (data[1][1] * data[2][2] - data[1][2] * data[2][1]));
			Cof.data[3][1] = data[0][0] * (data[1][2] * data[2][3] - data[1][3] * data[2][2]) - data[0][2] * (data[1][0] * data[2][3] - data[2][0] * data[1][3]) + data[0][3] * (data[1][0] * data[2][2] - data[1][2] * data[2][0]);
			Cof.data[3][2] = -(data[0][0] * (data[1][1] * data[2][3] - data[1][3] * data[2][1]) - data[0][1] * (data[1][0] * data[2][3] - data[2][0] * data[1][3]) + data[0][3] * (data[1][0] * data[2][1] - data[1][1] * data[2][0]));
			Cof.data[3][3] = data[0][0] * (data[1][1] * data[2][2] - data[1][2] * data[2][1]) - data[0][1] * (data[1][0] * data[2][2] - data[2][0] * data[1][2]) + data[0][2] * (data[1][0] * data[2][1] - data[1][1] * data[2][0]);

			return Cof;
		}

		static Mat4x4<T> CreateTranslationMatrix(const Vector3<T>& p_translation)
		{
			Mat4x4<T> translationMatrix = Mat4x4::Identity();
			if (p_translation.x != 0.f)
				translationMatrix.data[0][3] = p_translation.x;
			if (p_translation.y != 0.f)
				translationMatrix.data[1][3] = p_translation.y;
			if (p_translation.z != 0.f)
				translationMatrix.data[2][3] = p_translation.z;
			return translationMatrix;
		}

		static Mat4x4<T> CreateScaleMatrix(const Vector3<T>& p_scale)
		{
			Mat4x4<T> scaleMatrix;
			scaleMatrix.data[0][0] = p_scale.x;
			scaleMatrix.data[1][1] = p_scale.y;
			scaleMatrix.data[2][2] = p_scale.z;
			scaleMatrix.data[3][3] = 1.f;
			return scaleMatrix;
		}

		static Mat4x4<T> CreateXRotationMatrix(float p_angleDegree)
		{
			p_angleDegree *= M_PI / 180.f; // To radians
			Mat4x4<T> xRotationMatrix = Mat4x4::Identity();
			xRotationMatrix.data[1][1] = cosf(p_angleDegree);
			xRotationMatrix.data[1][2] = -sinf(p_angleDegree);
			xRotationMatrix.data[2][1] = sinf(p_angleDegree);
			xRotationMatrix.data[2][2] = cosf(p_angleDegree);
			return xRotationMatrix;
		}

		static Mat4x4<T> CreateYRotationMatrix(float p_angleDegree)
		{
			p_angleDegree *= M_PI / 180.f; // To radians
			Mat4x4<T> yRotationMatrix = Mat4x4<T>::Identity();
			yRotationMatrix.data[0][0] = cosf(p_angleDegree);
			yRotationMatrix.data[0][2] = sinf(p_angleDegree);
			yRotationMatrix.data[2][0] = -sinf(p_angleDegree);
			yRotationMatrix.data[2][2] = cosf(p_angleDegree);
			return yRotationMatrix;
		}

		static Mat4x4<T> CreateZRotationMatrix(float p_angleDegree)
		{
			p_angleDegree *= M_PI / 180.f; // To radians
			Mat4x4 zRotationMatrix = Mat4x4::Identity();
			zRotationMatrix.data[0][0] = cosf(p_angleDegree);
			zRotationMatrix.data[0][1] = -sinf(p_angleDegree);
			zRotationMatrix.data[1][0] = sinf(p_angleDegree);
			zRotationMatrix.data[1][1] = cosf(p_angleDegree);
			return zRotationMatrix;
		}

		static Mat4x4<T> CreateRotationMatrix(const Vector3<T>& p_angleDegree)
		{
			return CreateYRotationMatrix(p_angleDegree.y) * CreateXRotationMatrix(p_angleDegree.x) * CreateZRotationMatrix(p_angleDegree.z);
		}

		static Mat4x4<T> CreateTransformationMatrix(const Vector3<T>& p_translation, const Vector3<T>& p_scale, const Vector3<T>& p_rotationDegree)
		{
			return CreateTranslationMatrix(p_translation) * CreateYRotationMatrix(p_rotationDegree.y) * CreateXRotationMatrix(p_rotationDegree.x) * CreateZRotationMatrix(p_rotationDegree.z) * CreateScaleMatrix(p_scale);
		}

		static Vector3 <T>GetPositionFromMatrix(const Mat4x4<T>& p_matrix)
		{
			Vector3 <T>position;

			position.x = p_matrix.data[0][3];
			position.y = p_matrix.data[1][3];
			position.z = p_matrix.data[2][3];

			return position;
		}

		static Vector3<T> GetScaleFromMatrix(const Mat4x4<T>& p_matrix)
		{
			Vector3<T> scale;
			for (unsigned int i = 0; i < 3; i++)
			{
				Vector3 xScale = Vector3(p_matrix.data[0][i], p_matrix.data[1][i], p_matrix.data[2][i]);
				float length = xScale.Magnitude();
				scale.coord[i] = xScale.Magnitude();
				p_matrix.data[0][i] = p_matrix.data[0][i] / length;
				p_matrix.data[1][i] = p_matrix.data[1][i] / length;
				p_matrix.data[2][i] = p_matrix.data[2][i] / length;
			}
			return scale;
		}

		void Display() const
		{
			for (unsigned int i = 0; i < 4; i++)
			{
				std::cout << "| ";
				for (unsigned int j = 0; j < 4; j++)
				{
					std::cout << data[i][j] << " ";
				}
				std::cout << "|" << std::endl;
			}
			std::cout << std::endl;
		}

		const std::string& ToString() const
		{
			std::string result;
			for (unsigned int i = 0; i < 4; i++)
			{
				result += "| ";
				for (unsigned int j = 0; j < 4; j++)
				{
					result += std::to_string(data[i][j]) + " ";
				}
				result += "|\n";
			}
			return result;
		}

		Mat4x4<T> operator+(const Mat4x4<T>& p_right)
		{
			Mat4x4<T> result;
			for (unsigned int i = 0; i < 4; i++)
			{
				for (unsigned int j = 0; j < 4; j++)
				{
					result.data[i][j] = data[i][j] + p_right.data[i][j];
				}
			}
			return result;
		}

		Mat4x4<T> operator-(const Mat4x4<T>& p_right)
		{
			Mat4x4<T> result;
			for (unsigned int i = 0; i < 4; i++)
			{
				for (unsigned int j = 0; j < 4; j++)
				{
					result.data[i][j] = data[i][j] - p_right.data[i][j];
				}
			}
			return result;
		}

		const Mat4x4<T> operator*(const Mat4x4<T>& other) const
		{
			Mat4x4<T> result;
			for (unsigned int i = 0; i < 4; i++)
			{
				for (unsigned int j = 0; j < 4; j++)
				{
					for (unsigned int k = 0; k < 4; k++)
					{
						result.data[i][j] += data[i][k] * other.data[k][j];
					}
				}
			}
			return result;
		}

		Vector4<T> operator*(const Vector4<T>& p_right)
		{
			Vector4<T> result;
			result.x = data[0][0] * p_right.x + data[0][1] * p_right.y + data[0][2] * p_right.z + data[0][3] * p_right.w;
			result.y = data[1][0] * p_right.x + data[1][1] * p_right.y + data[1][2] * p_right.z + data[1][3] * p_right.w;
			result.z = data[2][0] * p_right.x + data[2][1] * p_right.y + data[2][2] * p_right.z + data[2][3] * p_right.w;
			result.w = data[3][0] * p_right.x + data[3][1] * p_right.y + data[3][2] * p_right.z + data[3][3] * p_right.w;
			return result;
		}

		Mat4x4<T> operator*(const T p_left)
		{
			Mat4x4<T> result;
			for (unsigned int i = 0; i < 4; i++)
			{
				for (unsigned int j = 0; j < 4; j++)
				{
					result.data[i][j] = data[i][j] * p_left;
				}
			}
			return result;
		}

	};

	template<typename T = float>
	bool operator==(const Mat4x4<T>& p_left, const Mat4x4<T>& p_right)
	{
		float margin = 0.000001f;
		bool result = true;

		for (unsigned int i = 0; i < 4; ++i)
		{
			for (unsigned int j = 0; j < 4; ++j)
			{
				if (p_left.data[i][j] > p_right.data[i][j] + margin || p_left.data[i][j] < p_right.data[i][j] - margin)
				{
					result = false;
					break;
				}
			}
			if (!result)
				break;
		}
		return result;
	}
}