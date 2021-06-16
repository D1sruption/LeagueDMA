#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <math.h>
#include <Windows.h>

#define NULLVECTOR2 Vector2(0, 0)
#define NULLVECTOR3 Vector3(0, 0, 0)
#define NULLVECTOR4 Vector4(0, 0, 0, 0)

struct Vector2 {
	float X, Y;

	inline Vector2(void) {}
	inline Vector2(const float x, const float y) {
		X = x; Y = y;
	}

	inline Vector2 operator + (const Vector2& A) const {
		return Vector2(X + A.X, Y + A.Y);
	}

	inline Vector2 operator + (const float A) const {
		return Vector2(X + A, Y + A);
	}

	inline Vector2 operator * (const float A) const {
		return Vector2(A * X, A * Y);
	}

	inline Vector2 operator * (const Vector2& A) const {
		return Vector2(A.X * X, A.Y * Y);
	}

	inline Vector2 operator - (const float A) const {
		return Vector2(A * X, A * Y);
	}

	inline Vector2 operator - (const Vector2& A) const
	{
		return Vector2(A.X - X, A.Y - Y);
	}

	inline Vector2 operator / (const float A) const {
		return Vector2(A / X, A / Y);
	}

	inline Vector2 operator / (const Vector2& A) const {
		return Vector2(A.X / X, A.Y / Y);
	}

	float dot(const Vector2& vec) const {
		return X * vec.X + Y * vec.Y;
	}

	inline float lengthSquared() {
		return X * X + Y * Y;
	}

	inline float length() {
		return (float)sqrt(lengthSquared());
	}

	inline Vector2 perpendicularTo() {
		return Vector2(Y, -X);
	}

	inline Vector2 Normalize() {
		float length = this->length();
		if (length != 0) {
			float inv = 1.0f / length;
			X *= inv;
			Y *= inv;
		}
		return Vector2(X, Y);
	}

	inline float DistTo(const Vector2& A) {
		float out = sqrtf(powf(X - A.X, 2) + powf(Y - A.Y, 2));
		return out < 0 ? out * -1 : out;
	}
}typedef Vector2;

struct Vector3 {
	float X, Y, Z;

	inline Vector3(void) {}
	inline Vector3(const float x, const float y, const float z) {
		X = x; Y = y; Z = z;
	}

	inline Vector3 operator + (const Vector3& A) const {
		return Vector3(X + A.X, Y + A.Y, Z + A.Z);
	}

	inline Vector3 operator + (const float A) const {
		return Vector3(X + A, Y + A, Z + A);
	}

	inline Vector3 operator * (const float A) const {
		return Vector3(A * X, A * Y, A * Z);
	}

	inline Vector3 operator * (const Vector3& A) const {
		return Vector3(A.X * X, A.Y * Y, A.Z * Z);
	}

	inline Vector3 operator - (const float A) const {
		return Vector3(A * X, A * Y, A * Z);
	}

	inline Vector3 operator - (const Vector3& A) const {
		return Vector3(A.X - X, A.Y - Y, A.Z - Z);
	}

	inline Vector3 operator / (const float A) const {
		return Vector3(A / X, A / Y, A / Z);
	}

	inline Vector3 operator / (const Vector3& A) const {
		return Vector3(A.X / X, A.Y / Y, A.Z / Z);
	}

	float dot(const Vector3& vec) const {
		return X * vec.X + Y * vec.Y + Z * vec.Z;
	}

	inline float lengthSquared() {
		return X * X + Y * Y + Z * Z;
	}

	inline float length() {
		return (float)sqrt(lengthSquared());
	}

	inline Vector3 perpendicularTo() {
		return Vector3(Z, Y, -X);
	}

	inline Vector3 Normalize() {
		float length = this->length();
		if (length != 0)
		{
			float inv = 1.0f / length;
			X *= inv;
			Y *= inv;
			Z *= inv;
		}
		return Vector3(X, Y, Z);
	}

	inline float DistTo(const Vector3& A) {
		float out = sqrtf(powf(X - A.X, 2) + powf(Y - A.Y, 2) + powf(Z - A.Z, 2));
		return out < 0 ? out * -1 : out;
	}
}typedef Vector3;

struct Vector4 {
	float X, Y, Z, W;

	inline Vector4(void) {}
	inline Vector4(const float x, const float y, const float z, const float w) {
		X = x; Y = y; Z = z; W = w;
	}

	inline Vector4 operator + (const Vector4& A) const {
		return Vector4(X + A.X, Y + A.Y, Z + A.Z, W + A.W);
	}

	inline Vector4 operator + (const float A) const {
		return Vector4(X + A, Y + A, Z + A, W + A);
	}

	inline Vector4 operator * (const float A) const {
		return Vector4(A * X, A * Y, A * Z, A * W);
	}

	inline Vector4 operator * (const Vector4& A) const {
		return Vector4(A.X * X, A.Y * Y, A.Z * Z, A.W * W);
	}

	inline Vector4 operator - (const float A) const {
		return Vector4(A * X, A * Y, A * Z, A * W);
	}

	inline Vector4 operator - (const Vector4& A) const {
		return Vector4(A.X - X, A.Y - Y, A.Z - Z, A.W - W);
	}

	inline Vector4 operator / (const float A) const {
		return Vector4(A / X, A / Y, A / Z, A / W);
	}

	inline Vector4 operator / (const Vector4& A) const {
		return Vector4(A.X / X, A.Y / Y, A.Z / Z, A.W / W);
	}

	float dot(const Vector4& vec) const {
		return X * vec.X + Y * vec.Y + Z * vec.Z + W * vec.W;
	}

	inline float lengthSquared() {
		return X * X + Y * Y + Z * Z + W * W;
	}

	inline float length() {
		return (float)sqrt(lengthSquared());
	}

	inline Vector4 perpendicularTo() {
		return Vector4(Z, W, -X, -Y);
	}

	inline Vector4 Normalize() {
		float length = this->length();
		if (length != 0) {
			float inv = 1.0f / length;
			X *= inv;
			Y *= inv;
			Z *= inv;
			W *= inv;
		}
		return Vector4(X, Y, Z, W);
	}

	inline float DistTo(const Vector4& A) {
		float out = sqrtf(powf(X - A.X, 2) + powf(Y - A.Y, 2) + powf(Z - A.Z, 2) + powf(W - A.W, 2));
		return out < 0 ? out * -1 : out;
	}
}typedef Vector4;
#endif