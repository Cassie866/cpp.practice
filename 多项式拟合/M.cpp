#include <iostream>
#include <cmath>
using namespace std;

void  Inv(double X[20][20], int n, double E[20][20])
{
	int i = 0, j = 0, k = 0;
	double temp = 0.0;
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 20; j++)
		{
			if (i == j)
			{
				E[i][j] = 1;
			}
		}
	}
	for (i = 0; i < n - 1; i++)
	{
		temp = X[i][i];
		for (j = 0; j < n; j++)
		{
			X[i][j] = X[i][j] / temp;
			E[i][j] = E[i][j] / temp;
		}
		for (k = 0; k < n; k++)
		{
			if (k == i)
			{
				continue;
			}
			temp = -X[i][i] * X[k][i];
			for (j = 0; j < n; j++)
			{
				X[k][j] = X[k][j] + temp * X[i][j];
				E[k][j] = E[k][j] + temp * E[i][j];
			}
		}
	}
}

int main()
{
	int n = 0, m = 0, i, j, k;
	double X[20] = { 0 }, Y[20] = { 0 }, F[20][20] = { 0 }, B[20] = { 0 }, A[20][20] = { 0 }, BF[20][20] = { 0 }, E[20][20] = { 0 }, C[20] = { 0 };
	cout << "M次多项式拟合" << endl;
	cout << "请输入拟合点的个数：";
	cin >> n;
	cout << "请输入" << n << "个点的x坐标序列：" << endl;
	for (i = 0; i < n; i++)
	{
		cin >> X[i];
	}
	cout << "请输入" << n << "个点的y坐标序列：" << endl;
	for (i = 0; i < n; i++)
	{
		cin >> Y[i];
	}
	cout << "请输入拟合次数：";
	cin >> m;
	for (i = 0; i < n; i++)
	{
		for (k = 1; k <= m + 1; k++)
		{
			F[i][k - 1] = pow(X[i], k - 1);
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m + 1; j++)
		{
			BF[j][i] = F[i][j];
		}
	}
	for (i = 0; i < m + 1; i++)
	{
		for (j = 0; j < m + 1; j++)
		{
			for (k = 0; k < n; k++)
			{
				A[i][j] += BF[i][k] * F[k][j];
			}
		}
	}
	for (i = 0; i < m + 1; i++)
	{
		for (j = 0; j < n; j++)
		{
			B[i] += BF[i][j] * Y[j];
		}
	}
	Inv(A, n, E);
	for (i = 0; i < m + 1; i++)
	{
		for (j = 0; j < n; j++)
		{
			C[i] += E[i][j] * B[j];
		}
	}
	cout << "拟合后的多项式系数：" << endl;
	for (i = m; i >= 0; i--)
	{
		cout << C[i] << "  ";
	}
	cout << endl;
	cout << "拟合后的" << m << "次多项式为：" << endl;
	cout << "P(x) = ";
	for (i = m; i >= 0; i--)
	{
		if (i == 0)
		{
			cout << "+" << C[i] << " ";
		}
		else
		{
			cout << "+" << C[i] << "*x^" << i;
		}
	}
	cout << endl;
	return 0;
}
