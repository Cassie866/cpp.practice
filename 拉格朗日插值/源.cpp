#include<iostream>
using namespace std;

int main()
{
	int C, i, j;
	double x;
	double y = 0.0;
	double t = 1.0;
	cout << "��������֪��Ը�����" ;
	cin >> C;
	double(*p)[2] = new double[C][2];
	cout << "���������Ե�ֵ" << endl;
	for (i = 0; i < C; i++)
	{
		for ( j= 0; j < 2; j++)
		{
			cin >> p[i][j];
		}
	}
	cout << "������Ҫ�����x��ֵ��";
	cin >> x;
	for (j = 0; j < C; j++)
	{
		for (i = 0; i < C; i++)
		{
			if (i == j)
			{
				continue;
			}
			t = (x - p[i][0]) / (p[j][0] - p[i][0]) * t;
		}
		y = y + t * p[j][1];
		t = 1;
	}
	cout << "��x=" << x << " ʱ�����ƵĽ��Ϊ��" << y << endl;
	delete[] p;
	return 0;
}
