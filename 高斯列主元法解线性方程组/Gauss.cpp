#include <iostream>
#include <iomanip>
using namespace std;
#define e     0.00000001
#define maxn 50

int n;//��ģn
double a[maxn][maxn];//ϵ������
double b[maxn];//b����
double m[maxn][maxn];//�м��������
double x[maxn];//���ս�
int    H = 1;//����H�����㣨�Ż���

void read()
{
	cout << "������ϵ�������ģ n: ";
	cin >> n;
	cout << "--------------------------------" << endl;
	cout << "������ϵ�������磺" << endl;
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
	cout << "������b�����磺" << endl;
	cout << "9.5342 6.3941 18.4231 16.9237" << endl;
	cout << "--------------------------------" << endl;
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
		b[i] *= H;
	}
}

/*
�м�������
��������Ԫ����
*/
void PrintProc(int cases)
{
	cout << endl;
	cout << "��" << cases << "����Ԫ������£�" << endl;
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
void LieZhuXiaoYuan()
{
	for (int k = 1; k < n; k++)
	{
		//ѡ��Ԫ[��һ�еľ���ֵ���ֵ]
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
		//�����д���[���ж��Ƿ�Ϊ0����]
		if (ab_max < e)
		{//0�������
			cout << "det A=0\n";
			break;
		}
		else if (max_ik != k)
		{//�Ƿ��ǵ�ǰ�У����ǽ���
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
		PrintProc(k);//����м�������
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
	read();
	LieZhuXiaoYuan();
	return 0;
}