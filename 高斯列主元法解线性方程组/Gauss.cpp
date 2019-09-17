#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

#define e 0.00000001
#define MAX 50

int n;//��ģn
double a[MAX][MAX];//ϵ������
double b[MAX];//b����
double x[MAX];//��

void Read()
{
	cout << "������ϵ�������ģ n: ";
	cin >> n;
	cout << "������"<<n<<"*"<<n<<"ϵ������" << endl;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
		}
	}
	cout << "������b����" << endl;
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
	}
}

/*
�м�����������������Ԫ����
*/
void MPrint(int m)
{
	cout << endl;
	cout << "��" << m << "����Ԫ������£�" << endl;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout  <<setw(10)<< a[i][j] << ' ';
		}
		cout  << setw(10)<<b[i] << endl;
	}
	cout << "-------------------------------------------------------------------" << endl;
}

/*
��ʾ���
*/
void Print()
{
	cout << endl;
	cout << "���ս��Ϊ��" << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << 'x' << i << " = " << x[i] << endl;
	}
	cout << endl;
}

/*
������Ԫ
*/
void XiaoYuan()
{
	for (int k = 1; k < n; k++)
	{
		//ѡ��Ԫ[��һ�еľ���ֵ���ֵ]
		double ab_max = -1;
		int  max;
		for (int i = k; i <= n; i++)
		{
			if (abs(a[i][k]) > ab_max)
			{
				ab_max = abs(a[i][k]);
				max = i;
			}
		}
		//�����д���[���ж��Ƿ�Ϊ0����]
		if (ab_max < e)
		{//0�������
			cout << "det A=0\n";
			break;
		}
		else if (max != k)
		{//�Ƿ��ǵ�ǰ�У����ǽ���
			double temp;
			for (int j = 1; j <= n; j++)
			{
				temp = a[max][j];
				a[max][j] = a[k][j];
				a[k][j] = temp;
			}
			temp = b[max];
			b[max] = b[k];
			b[k] = temp;
		}
		//��Ԫ����
		for (int i = k + 1; i <= n; i++)
		{
			a[i][k] /= a[k][k];
			for (int j = k + 1; j <= n; j++)
			{
				a[i][j] -= a[i][k] * a[k][j];
			}
			b[i] -= a[i][k] * b[k];
		}
		MPrint(k);//����м�������
		if (k < n - 1)
		{
			continue;
		}
		else
		{
			if (abs(a[n][n]) < e)
			{
				cout << "det A=0\n";
				break;
			}
			else
			{//�ش����
				x[n] = b[n] / a[n][n];
				for (int i = n - 1; i > 0; i--)
				{
					x[i] = b[i];
					for (int j = i + 1; j <= n; j++)
					{
						x[i] -= a[i][j] * x[j];
					}
					x[i] /= a[i][i];
				}
				//������ս��
				Print();
			}
		}
	}
}

int main()
{
	Read();
	XiaoYuan();
	return 0;
}
