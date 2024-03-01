#pragma once

#include <cmath>
#include <format>
#include <string>

namespace Nebula
{

	struct Vector4D
	{

	public:

		//Constructors

		Vector4D() = default;

		Vector4D(float X, float Y, float Z, float W)
			:X(X), Y(Y), Z(Z), W(W)
		{}

		Vector4D(float V)
			:X(V), Y(V), Z(V), W(V)
		{}

		//Functions

		float Magnitude() const
		{
			return sqrt(X*X + Y*Y + Z*Z + W*W);
		}

		void Normalize()
		{
			const float Length = Magnitude();

			X /= Length;
			Y /= Length;
			Z /= Length;
			W /= Length;
		}

		Vector4D GetNormal() const
		{
			Vector4D NewVector = *this;
			NewVector.Normalize();

			return NewVector;
		}

		std::string ToString() const
		{
			return std::format("X: {}, Y: {}, Z: {}, W: {}", X, Y, Z, W);
		}

		//Operators

		Vector4D operator+(const Vector4D& Other) const
		{
			return Vector4D(X + Other.X, Y + Other.Y, Z + Other.Z, W + Other.W);
		}

		Vector4D operator+(float V) const
		{
			return Vector4D(X + V, Y + V, Z + V, W + V);
		}

		Vector4D operator-(const Vector4D& Other) const
		{
			return Vector4D(X - Other.X, Y - Other.Y, Z - Other.Z, W - Other.W);
		}

		Vector4D operator-(float V) const
		{
			return Vector4D(X - V, Y - V, Z - V, W - V);
		}

		Vector4D operator*(const Vector4D& Other) const
		{
			return Vector4D(X * Other.X, Y * Other.Y, Z * Other.Z, W * Other.W);
		}

		Vector4D operator*(float V) const
		{
			return Vector4D(X * V, Y * V, Z * V, W * V);
		}

		Vector4D operator/(const Vector4D& Other) const
		{
			return Vector4D(X / Other.X, Y / Other.Y, Z / Other.Z, W / Other.W);
		}

		Vector4D operator/(float V) const
		{
			return Vector4D(X / V, Y / V, Z / V, W / V);
		}

		void operator+=(const Vector4D& Other)
		{
			X += Other.X;
			Y += Other.Y;
			Z += Other.Z;
			W += Other.W;
		}

		void operator+=(float V)
		{
			X += V;
			Y += V;
			Z += V;
			W += V;
		}

		void operator-=(const Vector4D& Other)
		{
			X -= Other.X;
			Y -= Other.Y;
			Z -= Other.Z;
			W -= Other.W;
		}

		void operator-=(float V)
		{
			X -= V;
			Y -= V;
			Z -= V;
			W -= V;
		}

		void operator*=(const Vector4D& Other)
		{
			X *= Other.X;
			Y *= Other.Y;
			Z *= Other.Z;
			W *= Other.W;
		}

		void operator*=(float V)
		{
			X *= V;
			Y *= V;
			Z *= V;
			W *= V;
		}

		void operator/=(const Vector4D& Other)
		{
			X /= Other.X;
			Y /= Other.Y;
			Z /= Other.Z;
			W /= Other.W;
		}

		void operator/=(float V)
		{
			X /= V;
			Y /= V;
			Z /= V;
			W /= V;
		}

		//Static Constructors

		static Vector4D ZeroVector;
		static Vector4D OneVector;

		//Variables

		float X = 0.0f;
		float Y = 0.0f;
		float Z = 0.0f;
		float W = 0.0f;

	};

	struct Vector3D
	{

	public:

		//Constructors

		Vector3D() = default;

		Vector3D(float X, float Y, float Z)
			:X(X), Y(Y), Z(Z)
		{}

		Vector3D(float V)
			:X(V), Y(V), Z(V)
		{}

		//Functions

		float Magnitude() const
		{
			return sqrt(X * X + Y * Y + Z * Z);
		}

		void Normalize()
		{
			const float Length = Magnitude();

			X /= Length;
			Y /= Length;
			Z /= Length;
		}

		Vector3D GetNormal() const
		{
			Vector3D NewVector = *this;
			NewVector.Normalize();

			return NewVector;
		}

		std::string ToString() const
		{
			return std::format("X: {}, Y: {}, Z: {}", X, Y, Z);
		}

		//Operators

		Vector3D operator+(const Vector3D& Other) const
		{
			return Vector3D(X + Other.X, Y + Other.Y, Z + Other.Z);
		}

		Vector3D operator+(float V) const
		{
			return Vector3D(X + V, Y + V, Z + V);
		}

		Vector3D operator-(const Vector3D& Other) const
		{
			return Vector3D(X - Other.X, Y - Other.Y, Z - Other.Z);
		}

		Vector3D operator-(float V) const
		{
			return Vector3D(X - V, Y - V, Z - V);
		}

		Vector3D operator*(const Vector3D& Other) const
		{
			return Vector3D(X * Other.X, Y * Other.Y, Z * Other.Z);
		}

		Vector3D operator*(float V) const
		{
			return Vector3D(X * V, Y * V, Z * V);
		}

		Vector3D operator/(const Vector3D& Other) const
		{
			return Vector3D(X / Other.X, Y / Other.Y, Z / Other.Z);
		}

		Vector3D operator/(float V) const
		{
			return Vector3D(X / V, Y / V, Z / V);
		}

		void operator+=(const Vector3D& Other)
		{
			X += Other.X;
			Y += Other.Y;
			Z += Other.Z;
		}

		void operator+=(float V)
		{
			X += V;
			Y += V;
			Z += V;
		}

		void operator-=(const Vector3D& Other)
		{
			X -= Other.X;
			Y -= Other.Y;
			Z -= Other.Z;
		}

		void operator-=(float V)
		{
			X -= V;
			Y -= V;
			Z -= V;
		}

		void operator*=(const Vector3D& Other)
		{
			X *= Other.X;
			Y *= Other.Y;
			Z *= Other.Z;
		}

		void operator*=(float V)
		{
			X *= V;
			Y *= V;
			Z *= V;
		}

		void operator/=(const Vector3D& Other)
		{
			X /= Other.X;
			Y /= Other.Y;
			Z /= Other.Z;
		}

		void operator/=(float V)
		{
			X /= V;
			Y /= V;
			Z /= V;
		}

		//Static Constructors

		static Vector3D ZeroVector;
		static Vector3D OneVector;

		//Variables

		float X = 0.0f;
		float Y = 0.0f;
		float Z = 0.0f;
		
	};

	struct Vector2D
	{

	public:

		//Constructors

		Vector2D() = default;

		Vector2D(float X, float Y)
			:X(X), Y(Y)
		{}

		Vector2D(float V)
			:X(V), Y(V)
		{}

		//Functions

		float Magnitude() const
		{
			return sqrt(X * X + Y * Y);
		}

		void Normalize()
		{
			const float Length = Magnitude();

			X /= Length;
			Y /= Length;
		}

		Vector2D GetNormal() const
		{
			Vector2D NewVector = *this;
			NewVector.Normalize();

			return NewVector;
		}

		std::string ToString() const
		{
			return std::format("X: {}, Y: {}", X, Y);
		}

		//Operators

		Vector2D operator+(const Vector2D& Other) const
		{
			return Vector2D(X + Other.X, Y + Other.Y);
		}

		Vector2D operator+(float V) const
		{
			return Vector2D(X + V, Y + V);
		}

		Vector2D operator-(const Vector2D& Other) const
		{
			return Vector2D(X - Other.X, Y - Other.Y);
		}

		Vector2D operator-(float V) const
		{
			return Vector2D(X - V, Y - V);
		}

		Vector2D operator*(const Vector2D& Other) const
		{
			return Vector2D(X * Other.X, Y * Other.Y);
		}

		Vector2D operator*(float V) const
		{
			return Vector2D(X * V, Y * V);
		}

		Vector2D operator/(const Vector2D& Other) const
		{
			return Vector2D(X / Other.X, Y / Other.Y);
		}

		Vector2D operator/(float V) const
		{
			return Vector2D(X / V, Y / V);
		}

		void operator+=(const Vector2D& Other)
		{
			X += Other.X;
			Y += Other.Y;
		}

		void operator+=(float V)
		{
			X += V;
			Y += V;
		}

		void operator-=(const Vector2D& Other)
		{
			X -= Other.X;
			Y -= Other.Y;
		}

		void operator-=(float V)
		{
			X -= V;
			Y -= V;
		}

		void operator*=(const Vector2D& Other)
		{
			X *= Other.X;
			Y *= Other.Y;
		}

		void operator*=(float V)
		{
			X *= V;
			Y *= V;
		}

		void operator/=(const Vector2D& Other)
		{
			X /= Other.X;
			Y /= Other.Y;
		}

		void operator/=(float V)
		{
			X /= V;
			Y /= V;
		}

		//Static Constructors

		static Vector2D ZeroVector;
		static Vector2D OneVector;

		//Variables

		float X = 0.0f;
		float Y = 0.0f;

	};

}
