//
// Copyright 2016 riteme
//

#ifndef RSRL_MATH_H_
#define RSRL_MATH_H_

#include <cmath>

struct Vector {
    Vector();
    Vector(const float _x, const float _y, const float _z);
    Vector(const float _x, const float _y, const float _z, const float _w);

    float x;
    float y;
    float z;
    float w;

    Vector operator+(const Vector &b) const;
    Vector operator-(const Vector &b) const;
    Vector operator*(const float b) const;
    Vector operator-() const;

    Vector &operator+=(const Vector &b);
    Vector &operator-=(const Vector &b);
    Vector &operator*=(const float b);

    float length() const {
        return sqrt(x * x + y * y + z * z);
    }
};

struct Matrix {
    Matrix();
    Matrix(const float m00, const float m01, const float m02, const float m03,
           const float m10, const float m11, const float m12, const float m13,
           const float m20, const float m21, const float m22, const float m23,
           const float m30, const float m31, const float m32, const float m33);

    Matrix operator+(const Matrix &b) const;
    Matrix operator-(const Matrix &b) const;
    Matrix operator*(const Matrix &b) const;
    Matrix operator*(const float b) const;
    Vector operator*(const Vector &b) const;
    Matrix operator-() const;
    friend Matrix operator*(const float b, const Matrix &a);

    Matrix &operator+=(const Matrix &b);
    Matrix &operator-=(const Matrix &b);
    Matrix &operator*=(const Matrix &b);
    Matrix &operator*=(const float b);

 private:
    float _mat[4][4];
};

inline Vector normalize(const Vector &a) {
    return a * (1.0f / a.length());
}

#endif