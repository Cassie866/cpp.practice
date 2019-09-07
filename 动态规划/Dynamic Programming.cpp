/*01.青蛙跳台阶

题目描述：
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。

方法一：动态规划

状态：
子状态：跳上1级，2级，3级，…，n级台阶的跳法数
f(n)：还剩n个台阶的跳法数
状态递推：
n级台阶，第一步有n种跳法：跳1级、跳2级、到跳n级
跳1级，剩下n - 1级，则剩下跳法是f(n - 1)
跳2级，剩下n - 2级，则剩下跳法是f(n - 2)
f(n) = f(n - 1) + f(n - 2) + … + f(n - n)
f(n) = f(n - 1) + f(n - 2) + … + f(0)
f(n - 1) = f(n - 2) + … + f(0)
f(n) = 2 * f(n - 1)
初始值：
f(1) = 1
f(n)是一个首项为1，公比为2的等比数列
返回结果：
f(n）
*/

//递归
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

//动态规划
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
		//申请一个数组保存子问题的解
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

//上述解法的空间复杂度为O(n) 
//其实f(n)只与它相邻的前一项有关，只需要保存一个子问题的解就可以 
//下面方法的空间复杂度将为O(1) 
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

/*方法二：排列
以台阶为研究对象，除了最后一个台阶只有一种情况，即必须到达，
其它台阶都有两种可能性，即青蛙跳到这个台阶或者不跳到这个台阶，
所以总的排列数为2^(n-1)。*/

//排列
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

//降低时间复杂度     
//上述实现的时间复杂度:O(N)     
//O(1)的实现：使用移位操作
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

/*题目描述:
HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。今天测试组开完会后，他又发话了：
在古老的一维模式识别中，常常需要计算连续子向量的最大和，当向量全为正数的时候，问题很好解决。
但是，如果向量中包含负数，是否应该包含某个负数，并期望旁边的正数会弥补它呢？
例如：{6,-3,-2,7,-15,1,2,2}，连续子向量的最大和为8(从第0个开始，到第3个为止)。
给一个数组，返回它的最大连续子序列的和，你会不会被他忽悠住？(子向量的长度至少是1)

方法：动态规划

状态：
子状态：长度为1，2，3，…，n 的子数组和的大值
F(i)：长度为 i 的子数组和的大值，这种定义不能形成递推关系，舍弃
F(i)：以 array[i] 为末尾元素的子数组和的大值
状态递推：
F(i) = max(F(i-1) + array[i]，array[i])
F(i) = （F(i-1) > 0）? F(i-1) + array[i] : array[i]
初始值：
F(0) = array[0]
返回结果：
maxsum：所有F(i)中的大值
maxsum = max(maxsum，F(i))
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

