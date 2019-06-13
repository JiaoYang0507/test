#include<iostream>
using namespace std;
class Complex {
public:
	double real, imag;
	Complex(double r = 0, double i = 0) :real(r), imag(i) {}
	Complex operator+(const Complex &c) {
		return Complex(real + c.real, imag + c.imag);
	}
	Complex operator-(const Complex &c) {
		return Complex(real - c.real, imag - c.imag);
	}
};
int main()
{
	Complex c1(6, 7), c2(7, 8);
	cout << "(6+7i)+(7+8i)=" << (c1 + c2).real;
	(c1 + c2).imag > 0 ? cout << "+" << (c1 + c2).imag : cout << (c1 + c2).imag;
	cout << "i" << endl;
	cout << "(6+7i)-(7+8i)=" << (c1 - c2).real;
	(c1 - c2).imag > 0 ? cout << "+" << (c1 - c2).imag : cout << (c1 - c2).imag;
	cout << "i" << endl;
	return 0;
}
