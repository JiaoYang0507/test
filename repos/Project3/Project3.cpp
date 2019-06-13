//#include "pch.h"
#include <iostream>
using namespace std;
class Vector
{
private:
	double *v;
	int len;
public:
	Vector(int size);
	Vector(double *, int);
	~Vector();
	double &operator[](int i);
	Vector  operator =(Vector X);
	friend Vector operator +(Vector &, Vector &);
	friend Vector operator -(Vector &, Vector &);
	friend double operator *(Vector &, Vector &);
	friend ostream & operator <<(ostream &output, Vector &);
	friend istream & operator >>(istream &input, Vector &);
};
Vector::Vector(int size)
{
	if (size <= 0 || size >= 2147483647)
	{
		cout << "The size of " << size << "is overflow!\n";
		abort();
	}
	v = new double[size];
	len = size;
}
Vector::Vector(double *C, int size)
{
	if (size <= 0 || size >= 2147483647)
	{
		cout << "The size of" << size << "is overflow!\n" << endl;
		abort();
	}
	v = new double[size];
	len = size;
	for (int i = 0; i < len; i++) v[i] = C[i];
}
Vector::~Vector()
{
	delete[]v;
	v = NULL;  len = 0;
}
double &Vector::operator[](int i)
{
	if (i >= 0 && i < len)
		return v[i];
	else
	{
		cout << "The size of" << i << "is overflow!\n";
		abort();
	}
}
Vector Vector::operator=(Vector X)
{
	if (len == X.len)
	{
		for (int i = 0; i < len; i++)
			v[i] = X[i];
		return *this;
	}
	else
	{
		cout << "Operator = fail!\n";
		abort();
	}
}
Vector operator +(Vector &A, Vector &B)            // 向量相加
{
	int size = A.len;
	double *T = new double[size];
	if (size == B.len)
	{
		for (int i = 0; i < size; i++)
			T[i] = A[i] + B[i];
		return Vector(T, size);
	}
	else
	{
		cout << "Operator + fail!\n";
		abort();
	}
}
Vector operator -(Vector &A, Vector &B)             //向量相减
{
	int size = A.len;
	double *T = new double[size];
	if (size == B.len)
	{
		for (int i = 0; i < size; i++)
			T[i] = A[i] - B[i];
		return Vector(T, size);
	}
	else
	{
		cout << "Operator - fail!\n";
		abort();
	}
}
double operator *(Vector &A, Vector &B)              //向量相乘
{
	int size = A.len;
	double s = 0;
	if (size == B.len)
	{
		for (int i = 0; i < size; i++)
			s += A[i] * B[i];
		return s;
	}
	else
	{
		cout << "Operator * fail!\n";
		abort();
	}
}
ostream & operator <<(ostream &output, Vector &A)     //输出
{
	int i;
	output << '(';
	for (i = 0; i < A.len - 1; i++)
		output << A[i] << ',';
	output << A[i] << ')';
	return output;
}
istream & operator >>(istream &input, Vector &A)     //输入
{
	for (int i = 0; i < A.len; i++)
		input >> A.v[i];
	return input;
}
int main()
{
	int k1, k2, k3; double t;
	cout << "Input the length of Vector A:\n";
	cin >> k1;
	Vector A(k1);
	cout << "Input the elements of Vector A:\n";
	cin >> A;
	cout << "Input the length of Vector B:\n";
	cin >> k2;
	Vector B(k2);
	cout << "Input the elements of Vector B:\n";
	cin >> B;
	cout << "Input the length of Vector C:\n";
	cin >> k3;
	Vector C(k3);
	cout << "A=" << A << endl;
	cout << "B=" << B << endl;
	C = (A + B);
	cout << "A+B=" << A << "+" << B << "=" << C << endl;
	C = A - B;
	cout << "A-B=" << A << "-" << B << "=" << C << endl;
	t = A * B;
	cout << "A*B=" << A << "*" << B << "=" << t << endl;
}