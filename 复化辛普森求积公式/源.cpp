#include<iostream>
using namespace std;

double fun(double x) 
{
	return 4 / (1 + x * x);
}

double Simpson(double a, double b, int n) 
{
	double h = (b - a) / n;
	double s1 = fun(a + h / 2);
	double s2 = 0;
	for (int i = 1; i < n; i++) 
	{  
		s1 += fun(a + i * h + h / 2);
		s2 += fun(a + i * h);
	}
	return h * (fun(a) + 4 * s1 + 2 * s2 + fun(b)) / 6;
}

int main() 
{
	int n = 10;  //����ȷ���
	double a = 0, b = 1;  //������
	cout << "�������� f = 4 / (1 + x * x)" << endl;
	cout << "����ȷ���Ϊ 10" << endl;
	cout << "��������Ϊ��0��1��" << endl;
	cout << "����ֵΪ��" << Simpson(a, b, n) << endl;
	return 0;
}