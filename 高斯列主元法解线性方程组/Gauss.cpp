#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

#define e 0.00000001
#define MAX 50

int n;//规模n
double a[MAX][MAX];//系数矩阵
double b[MAX];//b矩阵
double x[MAX];//解

void Read()
{
	cout << "请输入系数矩阵规模 n: ";
	cin >> n;
	cout << "请输入"<<n<<"*"<<n<<"系数矩阵：" << endl;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
		}
	}
	cout << "请输入b矩阵：" << endl;
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
	}
}

/*
中间矩阵输出，参数：消元次数
*/
void MPrint(int m)
{
	cout << endl;
	cout << "第" << m << "次消元结果如下：" << endl;
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
显示结果
*/
void Print()
{
	cout << endl;
	cout << "最终结果为：" << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << 'x' << i << " = " << x[i] << endl;
	}
	cout << endl;
}

/*
列主消元
*/
void XiaoYuan()
{
	for (int k = 1; k < n; k++)
	{
		//选主元[这一列的绝对值最大值]
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
		//交换行处理[先判断是否为0矩阵]
		if (ab_max < e)
		{//0矩阵情况
			cout << "det A=0\n";
			break;
		}
		else if (max != k)
		{//是否是当前行，不是交换
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
		//消元计算
		for (int i = k + 1; i <= n; i++)
		{
			a[i][k] /= a[k][k];
			for (int j = k + 1; j <= n; j++)
			{
				a[i][j] -= a[i][k] * a[k][j];
			}
			b[i] -= a[i][k] * b[k];
		}
		MPrint(k);//输出中间计算过程
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
			{//回代求解
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
				//输出最终结果
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
