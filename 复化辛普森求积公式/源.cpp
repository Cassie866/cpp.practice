#include<iostream>
using namespace std;

double f(double x) 
{
	return 4 / (1 + x * x);
}

double Simpson(double a, double b, int n) 
{
	double h = (b - a) / n, s1 = f(a + h / 2), s2 = 0;
	for (int i = 1; i < n; i++) {  //1 <= k <= n - 1
		s1 += f(a + i * h + h / 2);
		s2 += f(a + i * h);
	}
	return h * (f(a) + 4 * s1 + 2 * s2 + f(b)) / 6;
}

int main() 
{
	int n = 10;  //����ȷ���
	double a = 0, b = 1;  //������
	cout << "���� 4 / (1 + x * x)     ����ȷ���Ϊ10����������Ϊ��0��1��" << endl;
	cout << "����ֵΪ��" << Simpson(a, b, n) << endl;
	return 0;
}