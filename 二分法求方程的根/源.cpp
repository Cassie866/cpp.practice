#include <iostream>
using namespace std;

double func(double x)
{
	return (x * x * x - 3 * x - 1);
}

void root(double a, double b, double e, double* pResult)
{
	while (b - a >= e)
	{
		*pResult = (a + b) / 2;
		if (func(*pResult) * func(a) < 0)
		{
			b = *pResult;
		}
		else if (func(*pResult) * func(a) > 0)
		{
			a = *pResult;
		}
		else
		{
			break;
		}
	}
}

int main()
{
	double e = 0.05;
	double a = 1;
	double b = 2;
	double Result;
	root(a, b, e, &Result);
	cout << endl;
	cout << "求方程  x * x * x - 3 * x - 1 = 0  的根" << endl;
	cout << "求根区间为（1，2），精度为0.05" << endl;
	cout <<  endl;
	cout << "所求近似根为: " << Result << endl;
	return 0;
}


















































