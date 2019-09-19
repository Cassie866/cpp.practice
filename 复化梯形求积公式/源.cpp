#include <iostream>
#include <cmath>
using namespace std;

double X[1000];//保存生成的节点横坐标
double Y[1000];//保存生成的节点纵坐标

//定义一个数学函数
double fun(double x)
{
	return 4 / (1 + x * x);
}

//分割区间
void Devide(double a, double b, int N)
{
	double x;
	double dx= (b - a) / (N);
	for (int i = 0; i <= N; i++)
	{
		x = a + i * dx;
		X[i] = x;
		Y[i] = fun(x);
	}
}

//复化梯形求积
double GetIntegralValue(double a, double b, int N)
{
	double sum = 0;
	double value;
	//求2*f(xk)的总和，1<= k <= n-1
	for (int i = 1; i <= N - 1; i++)
	{
		sum += 2 * Y[i];
	}
	value = 0.5 * ((b - a) / N) * (Y[0] + sum + Y[N]);
	return value;
}

int main()
{
	//产生的节点数
	double a = 0;
	double b = 1;
	int N=10;
	cout << "被积函数 f = 4 / (1 + x * x)" << endl;
	cout << "区间等分数为 10" << endl;
	cout << "积分区间为（0，1）" << endl;
	Devide(a, b, N);
	cout << "积分值为：" << GetIntegralValue(a, b, N) << endl;
	return 0;
}