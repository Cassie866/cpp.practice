#include <iostream>
#include <cmath>
using namespace std;

#define N 20
#define MAX 10     //�������������
#define a 0    //��������
#define b 1      //��������
#define eps 1e-6 //����

double f(double x)//������ֹ�ʽ
{
	return 4 / (1 + x * x);
}

double ComputeT(double aa, double bb, long int n)//�������ι�ʽ
{
	int i;
	double sum = 0, h = (bb - aa) / n;
	for (i = 1; i < n; i++)
	{
		sum += f(aa + i * h);
	}
	sum += (f(aa) + f(bb)) / 2;
	return h * sum;
}

double f2(double x)
{
	return x * x;
}

int main()
{
	cout << "�������� f = 4 / (1 + x * x)" << endl;
	cout << "��������Ϊ��0��1��" << endl;
	cout << "����Ϊ1e-6" << endl;
	int i;
	long int n = N, m = 0;
	double T[MAX + 1][2];
	T[0][1] = ComputeT(a, b, n);
	n *= 2;
	for (m = 1; m < MAX; m++)
	{
		for (i = 0; i < m; i++)
		{
			T[i][0] = T[i][1];
		}
		T[0][1] = ComputeT(a, b, n);
		n *= 2;
		for (i = 1; i <= m; i++) //T��m(h)
		{
			T[i][1] = T[i - 1][1] + (T[i - 1][1] - T[i - 1][0]) / (pow(2, 2 * m) - 1);
		}
		if ((T[m - 1][1] < T[m][1] + eps) && (T[m - 1][1] > T[m][1] - eps))
		{
			cout << "����ֵΪ��" << T[m][1] << endl;
			return 0;
		}
	}
	cout << "�����޽⣡" << endl;
	return 0;
}
 