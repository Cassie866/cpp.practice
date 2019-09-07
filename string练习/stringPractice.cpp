/*
给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。
注意：
    num1 和num2 的长度都小于 5100.
	num1 和num2 都只包含数字 0-9.
	num1 和num2 都不包含任何前导零。
	你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。
*/
#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
	string addStrings(string num1, string num2)
	{
		int len1 = num1.size() - 1;
		int len2 = num2.size() - 1;
		string ret;
		int capacity = (len1 > len2 ? len1 + 1 : len2 + 1);
		ret.reserve(capacity);
		int step = 0;
		while (len1 >= 0 || len2 >= 0)
		{
			int curSum = 0;
			curSum += step;
			if (len1 >= 0)
			{
				curSum += num1[len1] - '0';
			}
			if (len2 >= 0)
			{
				curSum += num2[len2] - '0';
			}
			if (curSum > 9)
			{
				curSum -= 10;
				step = 1;
			}
			else
			{
				step = 0;
			}
			ret += curSum + '0';
			len1--;
			len2--;
		}
		if (step == 1)
		{
			ret += '1';
		}
		reverse(ret.begin(), ret.end());
		return ret;
	}
};

/*
编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出。
不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
你可以假设数组中的所有字符都是 ASCII 码表中的可打印字符。
*/

#include <vector>
class Solution
{
public:
	void reverseString(vector<char>& s)
	{
		int begin = 0;
		int end = s.size() - 1;
		while (begin < end)
		{
			swap(s[begin], s[end]);
			++begin;
			--end;
		}
	}
};

/*
给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
*/

class Solution
{
public:
	int firstUniqChar(string s)
	{
		int count[256] = { 0 };
		int size = s.size();
		for (int i = 0; i < size; ++i)
		{
			count[s[i]] += 1;
		}
		for (int i = 0; i < size; ++i)
		{
			if (count[s[i]] == 1)
			{
				return i;
			}
		}
		return -1;
	}
};

/*
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
说明：本题中，我们将空字符串定义为有效的回文串。

示例 1:
输入: "A man, a plan, a canal: Panama"
输出: true

示例 2:
输入: "race a car"
输出: false
*/

class Solution
{
public:
	bool isNumberLetter(char c)
	{
		return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
	}
	bool isPalindrome(string s)
	{
		int begin = 0;
		int end = s.size() - 1;
		for (auto& e : s)
		{
			if (e >= 'a')
			{
				e -= 32;
			}
		}
		while (begin < end)
		{
			while (begin < end)
			{
				if (isNumberLetter(s[begin]))
					break;
				begin++;
			}
			while (begin < end)
			{
				if (isNumberLetter(s[end]))
					break;
				end--;
			}
			if (s[begin] != s[end])
			{
				return false;
			}
			begin++;
			end--;
		}
		return true;
	}
};

