#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Î»Í¼
class BitSet
{
public:
	BitSet(size_t range)
	{
		_bs.resize((range >> 5) + 1, 0);
	}
	//´æ´¢
	void Set(int number)
	{
		int id = number >> 5;
		int bitid = number % 32;
		_bs[id] |= (1 << bitid);
	}
	//ËÑË÷
	int Find(int number)
	{
		int id = number >> 5;
		int bitid = number % 32;
		return (_bs[id] >> bitid )& 1;
	}
	//É¾³ı
	void ReSet(int number)
	{
		int id = number >> 5;
		int bitid = number % 32;
		_bs[id] &= (~(1 << bitid));
	}
private:
	vector<int> _bs;
};

int main()
{
	return 0;
}
