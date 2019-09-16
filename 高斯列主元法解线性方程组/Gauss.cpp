#include <iostream>
#include <iomanip>
using namespace std;
#define e     0.00000001
#define maxn 50

int n;//规模n
double a[maxn][maxn];//系数矩阵
double b[maxn];//b矩阵
double m[maxn][maxn];//中间变量矩阵
double x[maxn];//最终解
int    H = 1;//扩大H被结算（优化）

void read()
{
	cout << "请输入系数矩阵规模 n: ";
	cin >> n;
	cout << "--------------------------------" << endl;
	cout << "请输入系数矩阵，如：" << endl;
	cout << "1.1348 3.8326 1.1651 3.4017" << endl;
	cout << "0.5301 1.7875 2.5330 1.5435" << endl;
	cout << "3.4129 4.9317 8.7643 1.3142" << endl;
	cout << "1.2371 4.9998 10.6721 0.0147" << endl;
	cout << "--------------------------------" << endl;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
			a[i][j] *= H;
		}
	}
	cout << "--------------------------------" << endl;
	cout << "请输入b矩阵，如：" << endl;
	cout << "9.5342 6.3941 18.4231 16.9237" << endl;
	cout << "--------------------------------" << endl;
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
		b[i] *= H;
	}
}

/*
中间矩阵输出
参数：消元次数
*/
void PrintProc(int cases)
{
	cout << endl;
	cout << "第" << cases << "次消元结果如下：" << endl;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << setw(10) << a[i][j] << ' ';
		}
		cout << setw(10) << b[i] << endl;
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
void LieZhuXiaoYuan()
{
	for (int k = 1; k < n; k++)
	{
		//选主元[这一列的绝对值最大值]
		double ab_max = -1;
		int  max_ik;
		for (int i = k; i <= n; i++)
		{
			if (abs(a[i][k]) > ab_max)
			{
				ab_max = abs(a[i][k]);
				max_ik = i;
			}
		}
		//交换行处理[先判断是否为0矩阵]
		if (ab_max < e)
		{//0矩阵情况
			cout << "det A=0\n";
			break;
		}
		else if (max_ik != k)
		{//是否是当前行，不是交换
			double temp;
			for (int j = 1; j <= n; j++)
			{
				temp = a[max_ik][j];
				a[max_ik][j] = a[k][j];
				a[k][j] = temp;
			}
			temp = b[max_ik];
			b[max_ik] = b[k];
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
		PrintProc(k);//输出中间计算过程
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
	read();
	LieZhuXiaoYuan();
	return 0;
}