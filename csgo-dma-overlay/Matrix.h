#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <Windows.h>
#include <iostream>
#include <math.h>
#endif

struct Matrix;
#define NULLMATRIX Matrix(0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0);

struct Matrix
{
    float a1, a2, a3, a4;
    float b1, b2, b3, b4;
    float c1, c2, c3, c4;
    float d1, d2, d3, d4;

    inline Matrix(void) {}
    inline Matrix(const float _11, const float _12, const float _13, const float _14,
        const float _21, const float _22, const float _23, const float _24,
        const float _31, const float _32, const float _33, const float _34,
        const float _41, const float _42, const float _43, const float _44)
    {
        a1 = _11; a2 = _12; a3 = _13; a4 = _14;
        b1 = _21; b2 = _22; b3 = _23; b4 = _24;
        c1 = _31; c2 = _32; c3 = _33; c4 = _34;
        d1 = _41; d2 = _42; d3 = _43; d4 = _44;
    }


    inline Matrix operator * (const Matrix& A) const
    {
        return Matrix(a1 * A.a1 + a2 * A.b1 + a3 * A.c1 + a4 * A.d1, a1 * A.a2 + a2 * A.b2 + a3 * A.c2 + a4 * A.d2, a1 * A.a3 + a2 * A.b3 + a3 * A.c3 + a4 * A.d3, a1 * A.a4 + a2 * A.b4 + a3 * A.c4 + a4 * A.d4, b1 * A.a1 + b2 * A.b1 + b3 * A.c1 + b4 * A.d1, b1 * A.a2 + b2 * A.b2 + b3 * A.c2 + b4 * A.d2, b1 * A.a3 + b2 * A.b3 + b3 * A.c3 + b4 * A.d3, b1 * A.a4 + b2 * A.b4 + b3 * A.c4 + b4 * A.d4, c1 * A.a1 + c2 * A.b1 + c3 * A.c1 + c4 * A.d1, c1 * A.a2 + c2 * A.b2 + c3 * A.c2 + c4 * A.d2, c1 * A.a3 + c2 * A.b3 + c3 * A.c3 + c4 * A.d3, c1 * A.a4 + c2 * A.b4 + c3 * A.c4 + c4 * A.d4, d1 * A.a1 + d2 * A.b1 + d3 * A.c1 + d4 * A.d1, d1 * A.a2 + d2 * A.b2 + d3 * A.c2 + d4 * A.d2, d1 * A.a3 + d2 * A.b3 + d3 * A.c3 + d4 * A.d3, d1 * A.a4 + d2 * A.b4 + d3 * A.c4 + d4 * A.d4);
    }
    /*
    // access grants
    float& operator () (unsigned int Row, unsigned int Col);
    float  operator () (unsigned int Row, unsigned int Col) const;

    // casting operators
    operator float* ();
    operator const float* () const;

    // assignment operators
    Matrix& operator *= (const Matrix&);
    Matrix& operator += (const Matrix&);
    Matrix& operator -= (const Matrix&);
    Matrix& operator *= (float);
    Matrix& operator /= (float);

    // unary operators
    Matrix operator + () const;
    Matrix operator - () const;

    // binary operators
    Matrix operator * (const Matrix&) const;
    Matrix operator + (const Matrix&) const;
    Matrix operator - (const Matrix&) const;
    Matrix operator * (float) const;
    Matrix operator / (float) const;

    friend Matrix operator * (float, const Matrix&);

    bool operator == (const Matrix&) const;
    bool operator != (const Matrix&) const;
    */
} typedef Matrix;