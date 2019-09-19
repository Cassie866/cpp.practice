#include <iostream>
#include <cmath>
using namespace std;

double X[1000];//�������ɵĽڵ������
double Y[1000];//�������ɵĽڵ�������

//����һ����ѧ����
double fun(double x)
{
	return 4 / (1 + x * x);
}

//�ָ�����
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

//�����������
double GetIntegralValue(double a, double b, int N)
{
	double sum = 0;
	double value;
	//��2*f(xk)���ܺͣ�1<= k <= n-1
	for (int i = 1; i <= N - 1; i++)
	{
		sum += 2 * Y[i];
	}
	value = 0.5 * ((b - a) / N) * (Y[0] + sum + Y[N]);
	return value;
}

int main()
{
	//�����Ľڵ���
	double a = 0;
	double b = 1;
	int N=10;
	cout << "�������� f = 4 / (1 + x * x)" << endl;
	cout << "����ȷ���Ϊ 10" << endl;
	cout << "��������Ϊ��0��1��" << endl;
	Devide(a, b, N);
	cout << "����ֵΪ��" << GetIntegralValue(a, b, N) << endl;
	return 0;
}