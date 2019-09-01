#include <iostream>
#include <vector>
using namespace std;

//线性探测的哈希表
enum State { EMPTY, EXIST, DELETE };

template <class K, class V>
struct HashNode
{
	pair<K, V> _data;
	State _state = EMPTY;
};

template <class K, class V>
class HashTable
{
public:
	typedef HashNode<K, V> Node;
	typedef Node* pNode;
	HashTable(const int n = 10)
	{
		_hs.resize(n);
		_size = 0;
	}
	bool Insert(const pair<K, V>& data);
	void CheckCapacity();
	pNode find(const K& key);
	bool Erase(const K& key);
private:
	vector<Node> _hs;
	size_t _size;
};


template<class K, class V>
bool HashTable<K, V>::Insert(const pair<K, V>& data)
{
	CheckCapacity();
	int id = data.first % _hs.size();//计算索引
	while (_hs[id]._state == EXIST)//当前位置有元素
	{
		if (_hs[id]._data.first == data.first)//判读当前位置的元素的key是否和插入的数据相同
			return false;
		++id;       //key不同，继续向后遍历，找一个空的位置
		if (id == _hs.size())
			id = 0;
	}
	_hs[id]._data = data;//元素插入
	_hs[id]._state = EXIST;
	++_size;
	return true;
}

template<class K, class V>
void HashTable<K, V>::CheckCapacity()
{
	if (_hs.size() == 0 || _size * 10 / _hs.size() >= 8)
	{
		int capacity = _hs.size() == 0 ? 10 : 2 * _hs.size();
		HashTable<K, V> newhs(capacity);
		for (size_t i = 0; i < _hs.size(); ++i)
		{
			if (_hs[i]._state == EXIST)
				newhs.Insert(_hs[i]._data);
		}
		swap(_hs, newhs._hs);
	}
}

template<class K, class V>
typename HashTable<K, V>::pNode HashTable<K, V>::find(const K& key)
{
	int id = key % _hs.size();
	while (_hs[id]._state != EMPTY)
	{
		if (_hs[id]._state == EXIST)
		{
			if (_hs[id]._data.first == key)
				return &_hs[id];
		}
		++id;
		if (id == _hs.size())
			id = 0;
	}
	return nullptr;
}

template<class K, class V>
bool HashTable<K, V>::Erase(const K& key)
{
	pNode pos = find(key);
	if (pos)
	{
		pos->_state = DELETE;
		--_size;
		return true;
	}
	return false;
}

int main()
{
	HashTable<int, int>  ht;
	ht.Insert(make_pair(5, 5));
	ht.Insert(make_pair(1, 1));
	ht.Insert(make_pair(0, 0));
	ht.Insert(make_pair(10, 10));
	ht.Insert(make_pair(3, 3));
	ht.Insert(make_pair(30, 30));
	ht.Insert(make_pair(32, 32));
	ht.Insert(make_pair(8, 8));
	ht.Insert(make_pair(110, 110));
	ht.Insert(make_pair(23, 23));

	HashTable<int, int>::Node* pos = ht.find(110);
	pos = ht.find(130);
	return 0;
}
