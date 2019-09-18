#include <iostream>
#include <cmath>
#define N 2  //�����Է������з��̸�����δ֪������
#define Max  50  //����������
using namespace std;

const int N2 = 2 * N;

void FF(double xx[N], double yy[N])//�����������������������yy[N]
{
	double x, y;
	int i;
	x = xx[0];
	y = xx[1];
	yy[0] = x * x - 2 * x - y + 0.5;
	yy[1] = x * x + 4 * y * y - 4;
	cout << "��������������������ǣ� " << endl;
	for (i = 0; i < N; i++)
	{
		cout << yy[i] << " ";
	}
	cout << endl;
	cout << endl;
}

void FFjacobian(double xx[N], double yy[N][N])//�����ſ˱Ⱦ���yy[N][N]
{
	double x, y;
	int i, j;
	x = xx[0];
	y = xx[1];
	yy[0][0] = 2 * x - 2;
	yy[0][1] = -1;
	yy[1][0] = 2 * x;
	yy[1][1] = 8 * y;
	cout << "�ſɱȾ����ǣ� " << endl;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			cout << yy[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void Inv_jacobian(double yy[N][N], double inv[N][N])//�����ſ˱Ⱦ���������inv
{
	double aug[N][N2], L;
	int i, j, k;
	cout << "��ʼ�����ſɱȾ���������" << endl;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			aug[i][j] = yy[i][j];
		}
		for (j = N; j < N2; j++)
		{
			if (j == i + N)
			{
				aug[i][j] = 1;
			}
			else
			{
				aug[i][j] = 0;
			}
		}
	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N2; j++)
		{
			cout << aug[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (i = 0; i < N; i++)
	{
		for (k = i + 1; k < N; k++)
		{
			L = -aug[k][i] / aug[i][i];
			for (j = i; j < N2; j++)
			{
				aug[k][j] = aug[k][j] + L * aug[i][j];
			}
		}
	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N2; j++)
		{
			cout << aug[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (i = N - 1; i > 0; i--)
	{
		for (k = i - 1; k >= 0; k--)
		{
			L = -aug[k][i] / aug[i][i];
			for (j = N2 - 1; j >= 0; j--)
			{
				aug[k][j] = aug[k][j] + L * aug[i][j];
			}
		}
	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N2; j++)
		{
			cout << aug[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (i = N - 1; i >= 0; i--)
	{
		for (j = N2 - 1; j >= 0; j--)
		{
			aug[i][j] = aug[i][j] / aug[i][i];
		}
	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N2; j++)
		{
			cout << aug[i][j] << " ";
		}
		cout << endl;
		for (j = N; j < N2; j++)
		{
			inv[i][j - N] = aug[i][j];
		}
	}
	cout << endl;
	cout << "�ſɱȾ���������" << endl;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			cout << inv[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void newdundiedai(double x0[N], double inv[N][N], double y0[N], double x1[N])//�ɽ��ƽ�����x0������ƽ�����x1
{
	int i, j;
	double sum = 0;
	for (i = 0; i < N; i++)
	{
		sum = 0;
		for (j = 0; j < N; j++)
		{
			sum = sum + inv[i][j] * y0[j];
		}
		x1[i] = x0[i] - sum;
	}
	cout << "���ƽ�������" << endl;
	for (i = 0; i < N; i++)
	{
		cout << x1[i] << " ";
	}
	cout << endl;
	cout << endl;
}

int main()
{
	double x0[N] = {2,0.25}, y0[N], jacobian[N][N], inv_jacobian[N][N], x1[N], errornorm;
	int i, j, iter = 0;
	cout << "��ʼ���ƽ�����: " << endl;
	for (i = 0; i < N; i++)
	{
		cout << x0[i] << " ";
	}
	cout << endl;
	cout << endl;

	do
	{
		iter = iter + 1;
		cout << "��" << iter << "�ε�����ʼ" << endl;//�����������������������y0
		FF(x0, y0) ;
		FFjacobian(x0, jacobian);//�����ſ˱Ⱦ���jacobian
		Inv_jacobian(jacobian, inv_jacobian);//�����ſ˱Ⱦ���������inv_jacobian
		newdundiedai(x0, inv_jacobian, y0, x1);
		errornorm = 0;

		for (i = 0; i < N; i++)
		{
			errornorm = errornorm + fabs(x1[i] - x0[i]);
		}
		if (errornorm < 0.001)
		{
			break;
		}
		for (i = 0; i < N; i++)
		{
			x0[i] = x1[i];
		}
	} while (iter < Max);
	return 0;
}
