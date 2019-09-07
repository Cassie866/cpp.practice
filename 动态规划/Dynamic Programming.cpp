/*01.������̨��

��Ŀ������
һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n���������������һ��n����̨���ܹ��ж�����������

����һ����̬�滮

״̬��
��״̬������1����2����3��������n��̨�׵�������
f(n)����ʣn��̨�׵�������
״̬���ƣ�
n��̨�ף���һ����n����������1������2��������n��
��1����ʣ��n - 1������ʣ��������f(n - 1)
��2����ʣ��n - 2������ʣ��������f(n - 2)
f(n) = f(n - 1) + f(n - 2) + �� + f(n - n)
f(n) = f(n - 1) + f(n - 2) + �� + f(0)
f(n - 1) = f(n - 2) + �� + f(0)
f(n) = 2 * f(n - 1)
��ʼֵ��
f(1) = 1
f(n)��һ������Ϊ1������Ϊ2�ĵȱ�����
���ؽ����
f(n��
*/

//�ݹ�
class Solution 
{
public:
	int jumpFloorII(int number) 
	{
		if (number <= 0)
		{
			return 0;
		}
		else if (number == 1)
		{
			return 1;
		}
		else
		{
			return 2 * jumpFloorII(number - 1);
		}
	}
};

//��̬�滮
class Solution 
{
public:
	int jumpFloorII(int number) 
	{
		if (number <= 0)
		{
			return 0;
		}
		if (number == 1)
		{
			return 1;
		}
		//����һ�����鱣��������Ľ�
		int* record = new int[number - 1];
		record[0] = 1;
		for (int i = 1; i <= number; i++)
		{
			record[i] = 2 * record[i - 1];
		}
		return record[number - 1];
		delete[] record;
	}
};

//�����ⷨ�Ŀռ临�Ӷ�ΪO(n) 
//��ʵf(n)ֻ�������ڵ�ǰһ���йأ�ֻ��Ҫ����һ��������Ľ�Ϳ��� 
//���淽���Ŀռ临�ӶȽ�ΪO(1) 
class Solution 
{
public:
	int jumpFloorII(int number) 
	{
		if (number <= 0)
		{
			return 0;
		}
		if (number == 1)
		{
			return 1;
		}
		int fn = 1;
		int result = 0;
		for (int i = 2; i <= number; i++)
		{
			result = 2 * fn;
			fn = result;
		}
		return result;
	}
};

/*������������
��̨��Ϊ�о����󣬳������һ��̨��ֻ��һ������������뵽�
����̨�׶������ֿ����ԣ��������������̨�׻��߲��������̨�ף�
�����ܵ�������Ϊ2^(n-1)��*/

//����
class Solution 
{
public:
	int jumpFloorII(int number) 
	{
		if (number <= 0)
		{
			return 0;
		}
		int total = 1;
		for (int i = 1; i < number; i++)
		{
			total *= 2;
		}
		return total;
	}
};

//����ʱ�临�Ӷ�     
//����ʵ�ֵ�ʱ�临�Ӷ�:O(N)     
//O(1)��ʵ�֣�ʹ����λ����
class Solution 
{
public:
	int jumpFloorII(int number) 
	{
		if (number <= 0)
		{
			return 0;
		}
		return 1 << (number - 1);
	}
};

/*��Ŀ����:
HZż������Щרҵ������������Щ�Ǽ����רҵ��ͬѧ����������鿪�������ַ����ˣ�
�ڹ��ϵ�һάģʽʶ���У�������Ҫ�������������������ͣ�������ȫΪ������ʱ������ܺý����
���ǣ���������а����������Ƿ�Ӧ�ð���ĳ���������������Աߵ��������ֲ����أ�
���磺{6,-3,-2,7,-15,1,2,2}������������������Ϊ8(�ӵ�0����ʼ������3��Ϊֹ)��
��һ�����飬��������������������еĺͣ���᲻�ᱻ������ס��(�������ĳ���������1)

��������̬�滮

״̬��
��״̬������Ϊ1��2��3������n ��������͵Ĵ�ֵ
F(i)������Ϊ i ��������͵Ĵ�ֵ�����ֶ��岻���γɵ��ƹ�ϵ������
F(i)���� array[i] ΪĩβԪ�ص�������͵Ĵ�ֵ
״̬���ƣ�
F(i) = max(F(i-1) + array[i]��array[i])
F(i) = ��F(i-1) > 0��? F(i-1) + array[i] : array[i]
��ʼֵ��
F(0) = array[0]
���ؽ����
maxsum������F(i)�еĴ�ֵ
maxsum = max(maxsum��F(i))
*/

class Solution 
{
public:
	int FindGreatestSumOfSubArray(vector<int> array)
	{
		if (array.empty())
		{
			return -1;
		}
		int sum = array[0];
		int maxsum = array[0];
		for (int i = 1; i < array.size(); i++)
		{
			sum = (sum > 0) ? sum + array[i] : array[i];
			maxsum = (sum < maxsum) ? maxsum : sum;
		}
		return maxsum;
	}
};

