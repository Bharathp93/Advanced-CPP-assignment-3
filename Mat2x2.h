#ifndef MAT2X2_H
#define MAT2X2_H
#include<iostream>
#include<vector>

class Mat2x2
{
private:
	double a, b, c, d;
	int numberOfDigits() const;
	double maximum() const;
public:
	Mat2x2();
	Mat2x2(double, double, double, double);
	Mat2x2(const Mat2x2&);
	Mat2x2& operator=(const Mat2x2&);
	//~Mat2x2();
	friend std::ostream& operator<<(std::ostream&, const Mat2x2&);
	friend std::ostream& operator<<(std::ostream&, std::vector<double>&);
	friend std::istream& operator>>(std::istream&, Mat2x2&);

	const double determinant() const;
	const double trace() const;
	bool isSymmetric() const;
	bool isSimilar(Mat2x2& ) const;
	Mat2x2 transpose();
	Mat2x2 inverse();

	//Compound assignments
	Mat2x2& operator+=(Mat2x2&);
	Mat2x2& operator-=(Mat2x2&);
	Mat2x2& operator*=(Mat2x2&);
	Mat2x2& operator/=(Mat2x2&);
	Mat2x2& operator+=(const double);
	Mat2x2& operator-=(const double);
	Mat2x2& operator*=(const double);
	Mat2x2& operator/=(const double);

	//Unary operators
	Mat2x2 operator-();
	Mat2x2 operator+();

	//Simple assignments
	friend Mat2x2 operator+(Mat2x2&, Mat2x2&);
	friend Mat2x2 operator-(Mat2x2&, Mat2x2&);
	friend Mat2x2 operator*(Mat2x2&, Mat2x2&);
	friend Mat2x2 operator/(Mat2x2&, Mat2x2&);
	friend Mat2x2 operator+(Mat2x2&, double);
	friend Mat2x2 operator-(Mat2x2&, double);
	friend Mat2x2 operator*(Mat2x2&, double);
	friend Mat2x2 operator/(Mat2x2&, double);
	friend Mat2x2 operator+(double, Mat2x2&);
	friend Mat2x2 operator-(double, Mat2x2&);
	friend Mat2x2 operator*(double, Mat2x2&);
	friend Mat2x2 operator/(double, Mat2x2&);

	//Relational
	friend bool operator==(const Mat2x2&, const Mat2x2&);
	friend bool operator!=(const Mat2x2&, const Mat2x2&);

	//pre/post increment/decrement
	Mat2x2& operator++();
	Mat2x2& operator--();
	Mat2x2 operator++(int);
	Mat2x2 operator--(int);

	//Subscript
	double& operator[](const int);
	const double operator[](const int) const;

	std::vector<double> operator()(int = 0) const;

	friend void printEigenvalues(std::vector<double>& v, int i);
};
inline Mat2x2::Mat2x2() : a{ 0 }, b{ 0 }, c{ 0 }, d{ 0 } {}
#endif