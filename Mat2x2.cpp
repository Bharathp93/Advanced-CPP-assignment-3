#include "Mat2x2.h"
#include<iostream>
#include<iomanip>

/*
* Parameterised constructor initializes the 4 values in 
	the 2x2 matrix

* @param  takes in the 4 values as parameters
*/
Mat2x2::Mat2x2(double a, double b, double c, double d)
{
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
}

/*
* copy constructor, copies the contents of one matrix to the the current matrix

* @param  a referrence to a 2x2 matrix from which the values are to be copied
*/
Mat2x2::Mat2x2(const Mat2x2& m)
{
	this->a = m.a;
	this->b = m.b;
	this->c = m.c;
	this->d = m.d;
}

/*
* Assignment operato overloading to copy one matrix to another

* @param  a referrence to a 2x2 matrix from which the values are to be copied
*/
Mat2x2& Mat2x2::operator=(const Mat2x2& m)
{
	if (this == &m)
		return *this;
	this->a = m.a;
	this->b = m.b;
	this->c = m.c;
	this->d = m.d;
	return *this;
}

/*
* to find the determinant of the matrix
	(ad - bc)

* @return a double value of the determinant calculated
*/
const double Mat2x2::determinant() const
{
	return ((a*d) - (b*c));
}

/*
* to find the trace of the matrix
(a + d)

* @return a double value of the trace calculated
*/
const double Mat2x2::trace() const
{
	return a + d;
}

/*
* to check if the matrix is symmetric
	(b == c)

* @return a boolean value if it is symmetric or not
*/
bool Mat2x2::isSymmetric() const
{
	if (b == c)
		return true;
	return false;
}

/*
* to check if two matrices are similar or not

* @param  a referrence to a 2x2 matrix with which the current matrix has to be compared

* @return a boolean value if it is similar or not
*/
bool Mat2x2::isSimilar(Mat2x2& m) const
{
	if (this->determinant() == m.determinant() && this->trace() == m.trace())
		return true;
	return false;
}

/*
* to give the transpose of a matrix

* @return a copy of the transpose of the current matrix
*/
Mat2x2 Mat2x2::transpose()
{
	Mat2x2 temp = *this;
	temp.b = this->c;
	temp.c = this->b;
	return temp;
}

/*
* to give the inverse of a matrix

* @return a copy of the inverse of the current matrix
*/
Mat2x2 Mat2x2::inverse()
{
	if (this->determinant() != 0)
	{
		if (abs(this->determinant()) <= exp(-6))
			throw std::overflow_error("Inverse undefined");
		Mat2x2 temp = *this;
		temp.a = this->d * (1 / this->determinant());
		temp.b = -this->b * (1 / this->determinant());
		temp.c = -this->c * (1 / this->determinant());
		temp.d = this->a * (1 / this->determinant());
		return temp;
	}
	else
		throw std::overflow_error("Divide by zero");
}

/*
* operator overiding function for the += operator

* @param  a referrence to a 2x2 matrix with 
	which the operation has to be executed

* @return a referrence to the current matrix 
	after the execution of the operation
*/
Mat2x2& Mat2x2::operator+=(Mat2x2& m)
{
	this->a = this->a + m.a;
	this->b = this->b + m.b;
	this->c = this->c + m.c;
	this->d = this->d + m.d;

	return *this;
}

/*
* operator overiding function for the -= operator

* @param  a referrence to a 2x2 matrix with
which the operation has to be executed

* @return a referrence to the current matrix
after the execution of the operation
*/
Mat2x2& Mat2x2::operator-=( Mat2x2& m)
{
	this->a = this->a - m.a;
	this->b = this->b - m.b;
	this->c = this->c - m.c;
	this->d = this->d - m.d;

	return *this;
}

/*
* operator overiding function for the *= operator

* @param  a referrence to a 2x2 matrix with
which the operation has to be executed

* @return a referrence to the current matrix
after the execution of the operation
*/
Mat2x2& Mat2x2::operator*=(Mat2x2& m)	
{
	Mat2x2 temp = *this;
	temp.a = this->a * m.a + this->b * m.c;
	temp.b = this->a * m.b + this->b * m.d;
	temp.c = this->c * m.a + this->d * m.c;
	temp.d = this->c * m.b + this->d * m.d;
	*this = temp;
	return *this;
}

/*
* operator overiding function for the /= operator

* @param  a referrence to a 2x2 matrix with
which the operation has to be executed

* @return a referrence to the current matrix
after the execution of the operation
*/
Mat2x2& Mat2x2::operator/=(Mat2x2& m)
{
	return *this *= m.inverse();
}

/*
* operator overiding function for the += operator

* @param  a value that has to be added to the matrix

* @return a referrence to the current matrix
after the execution of the operation
*/
Mat2x2& Mat2x2::operator+=(const double x)
{
	this->a = this->a + x;
	this->b = this->b + x;
	this->c = this->c + x;
	this->d = this->d + x;

	return *this;
}

/*
* operator overiding function for the -= operator

* @param  a value that has to be subtracted from the matrix

* @return a referrence to the current matrix
after the execution of the operation
*/
Mat2x2& Mat2x2::operator-=(const double x)
{
	this->a = this->a - x;
	this->b = this->b - x;
	this->c = this->c - x;
	this->d = this->d - x;

	return *this;
}

/*
* operator overiding function for the *= operator

* @param  a value that has to be multiplied to the matrix

* @return a referrence to the current matrix
after the execution of the operation
*/
Mat2x2& Mat2x2::operator*=(const double x)
{
	this->a = this->a * x;
	if (this->a == -0)
		this->a = 0;
	this->b = this->b * x;
	if (this->b == -0)
		this->b = 0;
	this->c = this->c * x;
	if (this->c == -0)
		this->c = 0;
	this->d = this->d * x;
	if (this->d == -0)
		this->d = 0;

	return *this;
}

/*
* operator overiding function for the /= operator

* @param  a value that has to be divided by the matrix

* @return a referrence to the current matrix
after the execution of the operation
*/
Mat2x2& Mat2x2::operator/=(const double x)
{
	if (abs(x) < exp(-6))
	{
		throw std::overflow_error("Division by zero");
	}
	this->a = this->a / x;
	this->b = this->b / x;
	this->c = this->c / x;
	this->d = this->d / x;

	return *this;
}

/*
* operator overiding function for the + operator

* @param  lhs - a referrence to a 2x2 matrix with
	which the operation has to be executed

* @param  rhs - a referrence to a 2x2 matrix with
which the operation has to be executed

* @return a copy of the matrix
after the execution of the operation
*/
Mat2x2 operator+(Mat2x2& lhs, Mat2x2& rhs)
{
	Mat2x2 temp = lhs;
	return temp += rhs;
}

/*
* operator overiding function for the - operator

* @param  lhs - a referrence to a 2x2 matrix with
which the operation has to be executed

* @param  rhs - a referrence to a 2x2 matrix with
which the operation has to be executed

* @return a copy of the matrix
after the execution of the operation
*/
Mat2x2 operator-(Mat2x2& lhs, Mat2x2& rhs)
{
	Mat2x2 temp = lhs;
	return temp -= rhs;
}

/*
* operator overiding function for the * operator

* @param  lhs - a referrence to a 2x2 matrix with
which the operation has to be executed

* @param  rhs - a referrence to a 2x2 matrix with
which the operation has to be executed

* @return a copy of the matrix
after the execution of the operation
*/
Mat2x2 operator*(Mat2x2& lhs, Mat2x2& rhs)
{
	Mat2x2 temp = lhs;
	return temp *= rhs;
}

/*
* operator overiding function for the / operator

* @param  lhs - a referrence to a 2x2 matrix with
which the operation has to be executed

* @param  rhs - a referrence to a 2x2 matrix with
which the operation has to be executed

* @return a copy of the matrix
after the execution of the operation
*/
Mat2x2 operator/(Mat2x2& lhs, Mat2x2& rhs)
{
	Mat2x2 temp = lhs;
	return temp /= rhs;
}


/*
* operator overiding function for the + operator

* @param  lhs - a referrence to a 2x2 matrix with
which the operation has to be executed

* @param  rhs - a value that has to be added to lhs

* @return a copy of the matrix
after the execution of the operation
*/
Mat2x2 operator+(Mat2x2& lhs, double rhs)
{
	Mat2x2 temp = lhs;
	return temp += rhs;
}

/*
* operator overiding function for the - operator

* @param  lhs - a referrence to a 2x2 matrix with
which the operation has to be executed

* @param  rhs - a value that has to be subtracted from lhs

* @return a copy of the matrix
after the execution of the operation
*/
Mat2x2 operator-(Mat2x2& lhs, double rhs)
{
	Mat2x2 temp = lhs;
	return temp -= rhs;
}

/*
* operator overiding function for the * operator

* @param  lhs - a referrence to a 2x2 matrix with
which the operation has to be executed

* @param  rhs - a value that has to be multiplied to lhs

* @return a copy of the matrix
after the execution of the operation
*/
Mat2x2 operator*(Mat2x2& lhs, double rhs)
{
	Mat2x2 temp = lhs;
	return temp *= rhs;
}

/*
* operator overiding function for the / operator

* @param  lhs - a referrence to a 2x2 matrix with
which the operation has to be executed

* @param  rhs - a value that has to be devided from lhs

* @return a copy of the matrix
after the execution of the operation
*/
Mat2x2 operator/(Mat2x2& lhs, double rhs)
{
	Mat2x2 temp = lhs;
	return temp /= rhs;
}

/*
* operator overiding function for the + operator

* @param  lhs - a value that has to be added to rhs

* @param  rhs - a referrence to a 2x2 matrix with
which the operation has to be executed

* @return a copy of the matrix
after the execution of the operation
*/
Mat2x2 operator+(double lhs, Mat2x2& rhs)
{
	return rhs + lhs;
}

/*
* operator overiding function for the - operator

* @param  lhs - a value that has to be subtracted with rhs

* @param  rhs - a referrence to a 2x2 matrix with
which the operation has to be executed

* @return a copy of the matrix
after the execution of the operation
*/
Mat2x2 operator-(double lhs, Mat2x2& rhs)
{
	return (-1 * rhs) + lhs;
}

/*
* operator overiding function for the + operator

* @param  lhs - a value that has to be multiplied to rhs

* @param  rhs - a referrence to a 2x2 matrix with
which the operation has to be executed

* @return a copy of the matrix
after the execution of the operation
*/
Mat2x2 operator*(double lhs, Mat2x2& rhs)
{
	return rhs * lhs;
}

/*
* operator overiding function for the + operator

* @param  lhs - a value that has to be divided by rhs

* @param  rhs - a referrence to a 2x2 matrix with
which the operation has to be executed

* @return a copy of the matrix
after the execution of the operation
*/
Mat2x2 operator/(double lhs, Mat2x2& rhs)
{
	return lhs * rhs.inverse();
}

/*
* operator overiding function for the == operator

* @param  lhs - a referrence to a 2x2 matrix with
which the comparison has to be made

* @param  rhs - a referrence to a 2x2 matrix with
which the comparison has to be made

* @return a boolean value specifying if the two matrices are equal or not
*/
bool operator==(const Mat2x2& lhs, const Mat2x2& rhs)
{
	if (lhs.a == rhs.a && lhs.b == rhs.b && lhs.c == rhs.c && lhs.d == rhs.d)
	{
		return true;
	}
	return false;
}

/*
* operator overiding function for the != operator

* @param  lhs - a referrence to a 2x2 matrix with
which the comparison has to be made

* @param  rhs - a referrence to a 2x2 matrix with
which the comparison has to be made

* @return a boolean value specifying if the two matrices are not equal or equal
*/
bool operator!=(const Mat2x2& lhs, const Mat2x2& rhs)
{
	if (lhs == rhs)
		return false;
	return true;
}

/*
* operator overiding function for preincrement

* @return a referrence of the matrix
after the values are incremented by 1
*/
Mat2x2& Mat2x2::operator++()
{
	return *this += 1;
}

/*
* operator overiding function for predecrement

* @return a referrence of the matrix
after the values are decremented by 1
*/
Mat2x2& Mat2x2::operator--()
{
	return *this -= 1;
}

/*
* operator overiding function for postincrement

* @return a copy of the matrix
before the values are increased by 1
*/
Mat2x2 Mat2x2::operator++(int)
{
	Mat2x2 temp = *this;
	*this += 1;
	return temp;
}

/*
* operator overiding function for postdecrement

* @return a copy of the matrix
before the values are decreased by 1
*/
Mat2x2 Mat2x2::operator--(int)
{
	Mat2x2 temp = *this;
	*this -= 1;
	return temp;
}

/*
* operator overiding function for the [] operator

* @param  i - the index of the the matrix whose 
	value we are trying to access

* @return a referrence to the double value
*/
double& Mat2x2::operator[](const int i)
{
	if (i < 0 || i > 3)
		throw std::invalid_argument("index out of bound");
	if (i == 0)
		return this->a;
	if (i == 1)
		return this->b;
	if (i == 2)
		return this->c;
	if (i == 3)
		return this->d;
}

/*
* operator overiding function for the [] operator

* @param  i - the index of the the matrix whose
value we are trying to access

* @return a const to the double value
*/
const double Mat2x2::operator[](const int i) const
{
	if (i < 0 || i > 3)
		throw std::invalid_argument("index out of bound");
	if (i == 0)
		return this->a;
	if (i == 1)
		return this->b;
	if (i == 2)
		return this->c;
	if (i == 3)
		return this->d;
}

/*
* operator overiding function for the () operator
	to obtain the eigen values of the matrix

* @param  x - whic specifies which lambda we are trying to find

* @return a vector of double values
*/
std::vector<double> Mat2x2::operator()(int x) const
{
	std::vector<double> y;
	if (x == 0)
	{
		y.push_back(this->determinant());
		return y;
	}
	else if (x == 1)
	{
		double z = pow(this->trace(), 2.0) - 4 * (this->determinant());
		if (z >= 0)
		{
			y.push_back((this->trace() + sqrt(z)) / 2);
		}
		else
		{
			y.push_back((this->trace()) / 2);
			y.push_back(sqrt(-1 * z) / 2);
		}
	}
	else if (x == 2)
	{
		double z = pow(this->trace(), 2.0) - 4 * (this->determinant());
		if (z >= 0)
		{
			y.push_back((this->trace() - sqrt(z)) / 2);
		}
		else
		{
			y.push_back((this->trace()) / 2);
			y.push_back(-1 * sqrt(-1 * z) / 2);
		}
	}
	else
	{
		throw std::invalid_argument("Invalid arguments");
	}
	return y;
}

/*
* operator overiding function for the output << operator
	to print out the referred matrix

* @param  a referrence to ostream
* @param  a referrence to a 2x2 matrix

* @return a referrence to ostream
*/
std::ostream& operator<<(std::ostream& out, const Mat2x2& m)
{
	out << "|" << std::setw(m.numberOfDigits()) << std::fixed << std::setprecision(2) << m.a << " " << std::setw(m.numberOfDigits()) << std::fixed << std::setprecision(2) << m.b << "|" << std::endl;
	out << "|" << std::setw(m.numberOfDigits()) <<  " " << std::setw(m.numberOfDigits()) <<  "|" << std::endl;
	out << "|" << std::setw(m.numberOfDigits()) << std::fixed << std::setprecision(2) << m.c << " " << std::setw(m.numberOfDigits()) << std::fixed << std::setprecision(2) << m.d << "|" << std::endl;
	return out;
}

/*
* operator overiding function for the input >> operator
	to read the user specified input for the matrix in
	|a b|
	|   |
	|c d| format

* @param  a referrence to istream
* @param  a referrence to a 2x2 matrix

* @return a referrence to istream
*/
std::istream& operator>>(std::istream& in, Mat2x2& m)
{
	std::cout << "To create the following 2x2 matrix:\n";
	std::cout << "|a b|\n|   |\n|c d|\n";
	std::cout << "enter four numbers a, b, c, d in that order:\n";

	in >> m.a >> m.b >> m.c >> m.d;
	return in;
}

/*a function to print the eigrn values in a perticular format

* @param  a referrence to ostream
* @param  a referrence to a 2x2 matrix

* @return a referrence to ostream
*/
void printEigenvalues(std::vector<double>& v, int i)
{
	if (v.size() == 1)
	{
		std::cout << "root " << i << ": " << v[0] << std::endl;
	}
	else if (v.size() == 2)
	{
		if(v[1] >= 0)
			std::cout << "root " << i << ": " << v[0] << " +" << v[1] << "i" << std::endl;
		else
			std::cout << "root " << i << ": " << v[0] << " " << v[1] << "i" << std::endl;
	}
}

/*
* operator overiding function for the output << operator
	to print the determinant of a matrix

* @param  a referrence to ostream
* @param  a referrence to a vector of doubles

* @return a referrence to ostream
*/
std::ostream& operator<<(std::ostream& out, std::vector<double>& v)
{
	out << v[0];
	return out;
}

/*
* operator overiding function for the unary operator -
	it multiplies -1 to the matrix

* @return a copy of the resultant matrix
*/
Mat2x2 Mat2x2::operator-()
{
	Mat2x2 temp = *this;
	temp *= -1;
	return temp;
}

/*
* operator overiding function for the unary operator +
it multiplies +1 to the matrix

* @return a copy of the resultant matrix
*/
Mat2x2 Mat2x2::operator+()
{
	Mat2x2 temp = *this;
	temp *= 1;
	return temp;
}

/*
* afunction which finds the number of digits in a number with the sign

* @return a integer value of the length
*/
int Mat2x2::numberOfDigits() const
{
	double number = this->maximum();
	int length = 4;
	while (abs(number) >= 1)
	{
		number = abs(number) / 10;
		length++;
	}
	return length;
}

/*
* a function which maximum of all the values in the matrix

* @return a double value that is the maximum
*/
double Mat2x2::maximum() const
{
	if (this->a >= this->b && this->a >= this->c && this->a >= this->d)
		return this->a;
	if (this->b >= this->a && this->b >= this->c && this->b >= this->d)
		return this->b;
	if (this->c >= this->b && this->c >= this->a && this->c >= this->d)
		return this->c;
	if (this->d >= this->b && this->d >= this->c && this->d >= this->a)
		return this->d;
}