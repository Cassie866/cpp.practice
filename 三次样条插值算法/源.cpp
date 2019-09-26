#include<iostream>
#include<iomanip> 
using namespace std;
#define MAX 4

double *Diff(double X[], int n)
{
	int i = 0;
	double* H = NULL;
	H = (double*)malloc((n - 1) * sizeof(double));
	for (i = 1; i <= n - 1; i++)
		H[i - 1] = X[i] - X[i - 1];
	return H;
}

double* Divide(double Y[], int N, double H[])
{
	int i = 0;
	double* D = NULL;
	D = (double*)malloc(N * sizeof(double));
	for (i = 0; i < N; i++)
		D[i] = Y[i] / H[i];
	return D;
}

int main() 
{
	double X[MAX] = { 0,1,2,3 },
		Y[MAX] = { 0,0.5,2.0,1.5 },
		S[MAX][MAX] = { 0 },
		temp = 0.0, M[MAX] = { 0 };
	int N = MAX - 1, i = 0, k = 0;
	double A[MAX - 3] = { 0 },
		B[MAX - 2] = { 0 },
		C[MAX - 2] = { 0 };
	double dx0 = 0.2, dxn = 1;
	double* H = NULL, * D = NULL, * U = NULL;
	cout << "求解过点(0,0.0), (1,0.5), (2,2.0)和(3,1.5) 且一阶导数边界条件S'(0)=0.2 和S'(2)=1 的三样条曲线" << endl;
	H = Diff(X, MAX);
	D = Divide(Diff(Y, MAX), N, H);
	for (i = 1; i < N - 2; i++)
	{
		A[i] = H[i + 1];
	}
	for (i = 0; i < N - 1; i++)
	{
		B[i] = 2 * (H[i] + H[i + 1]);
	}
	for (i = 1; i < N - 1; i++)
	{
		C[i] = H[i + 1];
	}
	U = Diff(D, N);
	for (i = 0; i < N; i++)
	{
		U[i] = U[i] * 6;
	}
	B[0] = B[0] - H[0] / 2;
	U[0] = U[0] - 3 * (D[0] - dx0);
	B[N - 2] = B[N - 2] - H[N - 1] / 2;
	U[N - 2] = U[N - 2] - 3 * (dxn - D[N - 1]);
	for (k = 2; k <= N - 1; k++)
	{
		temp = A[k - 2] / B[k - 2];
		B[k - 1] = B[k - 1] - temp * C[k - 2];
		U[k - 1] = U[k - 1] - temp * U[k - 2];
	}
	M[N - 1] = U[N - 2] / B[N - 2];
	for (k = N - 2; k >= 1; k--)
	{
		M[k] = (U[k - 1] - C[k - 1] * M[k + 1]) / B[k - 1];
	}
	M[0] = 3 * (D[0] - dx0) / H[0] - M[0] / 2;
	M[N] = 3 * (dxn - D[N - 1]) / H[N - 1] - M[N - 1] / 2;
	for (k = 0; k <= N - 1; k++)
	{
		S[k][0] = (M[k + 1] - M[k]) / (6 * H[k]);
		S[k][1] = M[k] / 2;
		S[k][2] = D[k] - H[k] * (2 * M[k] + M[k + 1]) / 6;
		S[k][3] = Y[k];
	}
	cout << "求得的三样条曲线的矩阵S为：" << endl;
	for (i = 0; i < MAX - 1; i++)
	{
		for (k = 0; k < MAX; k++)
		{
			cout <<setw(10)<< S[i][k] << " ";
		}
		cout << endl;
	}
	for (i = 0; i < N; i++)
	{
		cout << "y=" << S[i][0] << "*x^3" << "+"<< S[i][1] << "*x^2" << "+"<< S[i][2] << "*x" << "+"<< S[i][3] << endl;
	}
	return 0;
}
