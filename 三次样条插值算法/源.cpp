#include<iostream>
#include<iomanip>
using namespace std;

const int  MAX = 50;
//变量设置：x为各点横坐标；y为各点纵坐标；h为步长
float x[MAX], y[MAX], h[MAX];
float c[MAX], a[MAX], fxym[MAX];

//差分函数
float f(int x1, int x2, int x3)
{
	float a = (y[x3] - y[x2]) / (x[x3] - x[x2]);
	float b = (y[x2] - y[x1]) / (x[x2] - x[x1]);
	return (a - b) / (x[x3] - x[x1]);
}

//追赶法
void cal_m(int n)
{
	float B[MAX];
	B[0] = c[0] / 2;
	for (int i = 1; i < n; i++)
	{
		B[i] = c[i] / (2 - a[i] * B[i - 1]);
	}
	fxym[0] = fxym[0] / 2;
	for (int i = 1; i <= n; i++)
	{
		fxym[i] = (fxym[i] - a[i] * fxym[i - 1]) / (2 - a[i] * B[i - 1]);
	}
	for (int i = n - 1; i >= 0; i--)
	{
		fxym[i] = fxym[i] - B[i] * fxym[i + 1];
	}
}

void Print(int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ": (" << x[i] << " , " << x[i + 1] << ")\n" << "\t";
		cout << "S" << i + 1 << "=";
		float t = fxym[i] / (6 * h[i]);
		if (t > 0)
		{
			cout << -t << "*(x-" << x[i + 1] << ")^3";
		}
		else
		{
			cout << -t << "*(x-" << x[i + 1] << ")^3";
		}

		t = fxym[i + 1] / (6 * h[i]);
		if (t > 0)
		{
			cout << " + " << t << "*(x-" << x[i] << ")^3";
		}
		else
		{
			cout << " - " << t << "*(x-" << x[i] << ")^3";
		}
		cout << "\n\t";
		t = (y[i] - fxym[i] * h[i] * h[i] / 6) / h[i];
		if (t > 0)
		{
			cout << "- " << t << "*(x-" << x[i + 1] << ")";
		}
		else
		{
			cout << "- " << -t << "*(x-" << x[i + 1] << ")";
		}
		t = (y[i + 1] - fxym[i + 1] * h[i] * h[i] / 6) / h[i];
		if (t > 0)
		{
			cout << " + " << t << "*(x-" << x[i] << ")";
		}
		else
		{
			cout << " - " << -t << "*(x-" << x[i] << ")";
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	int n, i; 
	cout << "请输入点的个数:";
	cin >> n;
	for (i = 0; i <= n; i++)
	{
		cout << "请输入X" << i << ':';
		cin >> x[i];
		cout << "请输入Y" << i << ':';
		cin >> y[i];
	}
	for (i = 0; i < n; i++) //求步长
	{
		h[i] = x[i + 1] - x[i];
	}
	float f0, f1;
	cout << "请输入两端的一阶导数：";
	cin >> f0 >> f1;
	c[0] = 1; a[n] = 1;
	fxym[0] = 6 * ((y[1] - y[0]) / (x[1] - x[0]) - f0) / h[0];
	fxym[n] = 6 * (f1 - (y[n] - y[n - 1]) / (x[n] - x[n - 1])) / h[n - 1];

	for (i = 1; i < n; i++)
	{
		fxym[i] = 6 * f(i - 1, i, i + 1);
	}
	for (i = 1; i < n; i++)
	{
		a[i] = h[i - 1] / (h[i] + h[i - 1]);
		c[i] = 1 - a[i];
	}
	a[n] = h[n - 1] / (h[n - 1] + h[n]);
	cal_m(n);
	cout << "输出三次样条插值函数：" << endl;
	Print(n);
	return 0;
}

