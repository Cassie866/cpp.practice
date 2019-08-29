#include "RBTree.h"
#include <iostream>
using namespace std;

template <class K,class V>
class Map
{
private:
	struct MapKeyOfValue
	{
		const  K& operator()(const pair<K, V>& data)
		{
			return data.first;
		}
	};
public:
	typedef typename RBTree<K, pair<K, V>, MapKeyOfValue>::iterator iterator;
	
	pair<iterator, bool> Insert(const pair<K, V>& data)
	{
		return _rbt.Insert(data);
	}
	iterator begin()
	{
		return _rbt.begin();
	}
	iterator end()
	{
		return _rbt.end();
	}
	V& operator[](const K& key)
	{
		pair<iterator, bool>ret = _rbt.Insert(make_pair(key, V()));
		return ret.first->second;
	}
private:
	RBTree<K, pair<K, V>,MapKeyOfValue> _rbt;
};

template <class K>
class Set
{
	struct SetKeyOfValue
	{
		const K& operator()(const K& data)
		{
			return data;
		}
	};
public:
	typedef typename RBTree<K, K, SetKeyOfValue>::iterator iterator;
	pair<iterator, bool>Insert(const K& data)
	{
		return _rbt.Insert(data);
	}
	iterator begin()
	{
		return _rbt.begin();
	}
	iterator end()
	{
		return _rbt.end();
	}
private:
	RBTree<K, K, SetKeyOfValue> _rbt;
};

int main()
{
	return 0;
}