#include<iostream>
#include<iomanip>
#include<string>
#include<cassert>
#include"Mat2x2.h"
using namespace std;

int main()
{
	Mat2x2 m1(2, -1, 1, 2);
	cout << "m1\n" << m1 << endl;

	Mat2x2 m1Inv = m1.inverse();
	cout << "m1.invers()\n" << m1Inv << endl;

	Mat2x2 m1Inv_times_m1 = m1Inv*m1;
	cout << "m1 * m1.invers()\n" << m1Inv_times_m1 << endl;
	assert(m1Inv_times_m1 == Mat2x2(1, 0, 0, 1));

	Mat2x2 m1_times_m1Inv = m1 * m1Inv;
	cout << "m1.invers() * m1\n" << m1_times_m1Inv << endl;
	assert(m1_times_m1Inv == Mat2x2(1, 0, 0, 1));

	cout << "det(m1) = " << m1.determinant() << endl;
	cout << "trace(m1) = " << m1.trace() << "\n" << endl;

	std::vector<double> root1 = m1(1);
	assert(std::abs(root1[0] - 2) < 1.e-6);
	assert(std::abs(root1[1] - 1) < 1.e-6);
	printEigenvalues(root1, 1);

	std::vector<double> root2 = m1(2);
	assert(std::abs(root2[0] - 2) < 1.e-6);
	assert(std::abs(root2[1] - (-1)) < 1.e-6);
	printEigenvalues(root2, 2);

	cout << "\n";

	Mat2x2 m2 = m1 + 1;
	assert(m2 == Mat2x2(3, 0, 2, 3));
	cout << "m2\n" << m2 << endl;

	m2 = 1 + m1;
	assert(m2 == Mat2x2(3, 0, 2, 3));

	Mat2x2 m3 = m2 - 1;
	assert(m3 == m1);
	cout << "m3\n" << m3 << endl;

	Mat2x2 m4 = 1 - m3;
	assert(m4 == Mat2x2(-1, 2, 0, -1));
	cout << "m4\n" << m4 << endl;

	Mat2x2 m5 = m4 * 5;
	cout << "m5\n" << m5 << endl;
	assert(m5 == Mat2x2(-5, 10, 0, -5));

	Mat2x2 m6 = 10 * m5;
	cout << "m6\n" << m6 << endl;
	assert(m6 == Mat2x2(-50, 100, 0, -50));
	assert(m6 / 10 == m5);
	assert(10 / m6 == 10 * m6.inverse());
	assert(5 * m4 * 10 == m6);
	
	Mat2x2 m7 = m1++;
	cout << "m1\n" << m1 << endl;
	cout << "m7\n" << m7 << endl;
	assert(5 * m4 * 10 == m6);

	Mat2x2 m8 = --m1;
	cout << "m1\n" << m1 << endl;
	cout << "m8\n" << m8 << endl;
	assert(m8 == m1);
	m8--;
	cout << "m8\n" << m8 << endl;
	assert(m1 == 1 + m8);
	assert(m1 - 1 == m8);
	assert(-m1 + 1 == -m8);
	assert(2 * m1 == m8 + m1 + 1);
	assert(m1 * m1 == m1 *(1 + m8));
	cout << "m8 is " << (m8.isSymmetric() ? "" : "not") << " symmetric\n";
	Mat2x2 m9(123, 6, 6, 4567.89);
	cout << "m9\n" << m9 << endl;
	cout << "m9 is " << (m9.isSymmetric() ? "" : "not") << " symmetric\n";

	m9[0] = 3;
	m9[1] = 1;
	m9[2] = 7;
	m9[3] = 4;
	cout << "m9\n" << m9 << endl;
	assert(m9 == Mat2x2(3, 1, 7, 4));
	cout << "det(m1) =  " << m1() << "\ntrace(m1) = " << m1.trace() << "\n\n";
	cout << "det(m9) =  " << m9() << "\ntrace(m1) = " << m9.trace() << "\n\n";
	cout << "m9 is " << (m9.isSimilar(m1) ? "" : "not ") << "similar to m1\n";

	const Mat2x2 cm9{ m9 };
	cout << "cm9\n" << cm9 << endl;

	m9 += m9;
	cout << "m9\n" << m9 << endl;
	assert(m9 == 2 * Mat2x2(3, 1, 7, 4));

	Mat2x2 m10;
	m10 += (m9 / 2);
	cout << "m10\n" << m10 << endl;
	assert(m10 == Mat2x2(3, 1, 7, 4));

	m10 *= 2;
	cout << "m10\n" << m10 << endl;
	assert(m10 == m9);

	m10 /= 2;
	cout << "m10\n" << m10 << endl;
	assert(m10 == m9/2);

	m10 += 10;
	cout << "m10\n" << m10 << endl;
	assert(m10 == (m9 + 20) / 2);

	m10 -= 10;
	cout << "m10\n" << m10 << endl;
	assert(m10 == 0.5 * m9);

	Mat2x2 m11 = m10.transpose();
	cout << "m11\n" << m11 << endl;
	assert(m10 == m11.transpose());

	Mat2x2 m12;
	cout << "In response to the following prompt\n";
	cout << "enter the numbers 10, 20, 30, 40 in that order\n\n";

	cin >> m12;
	cout << "m12\n" << m12 << endl;
	assert(m12 == Mat2x2(10, 20, 30, 40));

	Mat2x2 m13 = -m11;
	cout << "m13\n" << m13 << endl;
	assert(+m11 == -m13);

	cout << "Test completed successfully!" << endl;
	//return 0;
	system("pause");
}
