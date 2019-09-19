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
	cout << "�󷽳�  x * x * x - 3 * x - 1 = 0  �ĸ�" << endl;
	cout << "�������Ϊ��1��2��������Ϊ0.05" << endl;
	cout <<  endl;
	cout << "������Ƹ�Ϊ: " << Result << endl;
	return 0;
}


















































