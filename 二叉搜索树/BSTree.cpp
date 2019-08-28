#include <iostream>
using namespace std;

//二叉搜索树
//节点定义
template <class T>
struct BSTNode
{
	BSTNode(const T& data = T())
		:_left(nullptr)
		, _right(nullptr)
		, _data(data)
	{}

	BSTNode<T>* _left;
	BSTNode<T>* _right;
	T _data;
};

//结构
template <class T>
class BSTree
{
public:
	typedef BSTNode<T> Node;
	typedef Node* pNode;

	BSTree();//构造函数
	BSTree(const BSTree<T>& bst);//拷贝构造函数
	pNode Copy(pNode root);
	void Destroy(pNode root);
	BSTree& operator == (const BSTree<T>& bst);//赋值运算符重载
	~BSTree();//析构函数
	pNode Find(const T& data);//搜索，返回值为data的节点的地址	
	bool Insert(const T& data);//插入值为data的节点
	bool Erase(const T& data);//删除值为data的节点
	void _Inorder(pNode root);//中序遍历打印节点的值
	void Inorder();

private:
	pNode _root = nullptr;
};

template<class T>
BSTree<T>::BSTree()
	:_root(nullptr)
{}

template<class T>
BSTree<T>::BSTree(const BSTree<T>& bst)
{
	_root = Copy(bst._root);
}

template<class T>
void BSTree<T>::Destroy(pNode root)
{
	if (root == nullptr)
		return;
	Destroy(root->_left);
	Destroy(root->_right);
	delete root;
	root = nullptr;
}

template<class T>
bool BSTree<T>::Insert(const T& data)
{
	if (_root == nullptr)
	{
		_root = new Node(data);
		return true;
	}
	pNode cur = _root;
	pNode parent = nullptr;
	while (cur)
	{
		parent = cur;
		if (data > cur->_data)
			cur = cur->_right;
		else if (data < cur->_data)
			cur = cur->_left;
		else
			return false;
	}
	cur = new Node(data);
	if (data > parent->_data)
		parent->_right = cur;
	else
		parent->_left = cur;
	return true;
}

template<class T>
bool BSTree<T>::Erase(const T& data)
{
	if (_root == nullptr)
		return false;
	pNode cur = _root;
	pNode parent = nullptr;
	while (cur)
	{
		if (data == cur->_data)
			break;
		parent = cur;
		if (data > cur->_data)
			cur = cur->_right;
		else if (data < cur->_data)
			cur = cur->_left;
	}
	if (cur == nullptr)
		return false;
	if (cur->_left == nullptr && cur->_right == nullptr)
	{
		if (cur != _root)
		{
			if (cur == parent->_left)
				parent->_left = nullptr;
			else
				parent->_right = nullptr;
		}
		else
			_root = nullptr;
		delete cur;
		cur = nullptr;
	}
	else if (cur->_left == nullptr)
	{
		if (cur != _root)
		{
			if (cur == parent->_left)
				parent->_left = cur->_right;
			else
				parent->_right = cur->_right;
		}
		else
			_root = cur->_right;
		delete cur;
		cur = nullptr;
	}
	else if (cur->_right == nullptr)
	{
		if (cur != _root)
		{
			if (cur == parent->_left)
				parent->_left = cur->_left;
			else
				parent->_right = cur->_left;
		}
		else
			_root = cur->_left;
		delete cur;
		cur = nullptr;
	}
	else
	{
		pNode next = cur->_left;
		parent = cur;
		while (next->_right)
		{
			parent = next;
			next = next->_right;
		}
		cur->_data = next->_data;
		if (next == parent->_right)
			parent->_right = next->_left;
		else
			parent->_left = next->_left;
		delete next;
		next = nullptr;
	}
	return true;
}

template<class T>
void BSTree<T>::_Inorder(pNode root)
{
	if (root == nullptr)
		return;
	_Inorder(root->_left);
	cout << root->_data << " ";
	_Inorder(root->_right);
}

template<class T>
void BSTree<T>::Inorder()
{
	_Inorder(_root);
	cout << endl;
}

template<class T>
typename BSTree<T>::pNode BSTree<T>::Copy(BSTree<T>::pNode root)
{
	if (root == nullptr)
		return nullptr;
	pNode newroot = new Node(root->_data);
	newroot->_left = Copy(root->_left);
	newroot->_right = Copy(root->_right);
	return newroot;
}

template<class T>
BSTree<T>& BSTree<T>::operator==(const BSTree<T>& bst)
{
	if (this != bst)
	{
		if (_root)
			Destory(_root);
		_root = Copy(bst._root);
	}
	return *this;
}

template<class T>
typename BSTree<T>::pNode BSTree<T>::Find(const T& data)
{
	if (_root == nullptr)
		return nullptr;
	pNode cur = _root;
	while (cur)
	{
		if (data > cur->_data)
			cur = cur->_right;
		else if (data < cur->_data)
			cur = cur->_left;
		else
			return cur;
	}
	return nullptr;
}

template <class T>
BSTree<T>::~BSTree()
{
	Destroy(_root);
}


int main()
{
	BSTree<int> bst;
	bst.Insert(5);
	bst.Insert(3);
	bst.Insert(7);
	bst.Insert(1);
	bst.Insert(4);
	bst.Insert(6);
	bst.Insert(8);
	bst.Insert(0);
	bst.Insert(2);
	bst.Insert(9);
	bst.Inorder();

	BSTree<int> cpy(bst);
	cpy.Inorder();

	BSTree<int> bst2;
	bst2.Insert(100);
	bst2.Insert(200);
	bst2.Insert(300);
	bst2.Insert(400);
	bst2.Inorder();

	BSTNode<int>* find1 = bst2.Find(500);
	BSTNode<int>* find2 = bst2.Find(200);
	cout << find1 << "  " << find2 << endl;

	bst2 = bst;
	bst2.Inorder();

	bst.Erase(9);
	bst.Inorder();
	bst.Erase(8);
	bst.Inorder();
	bst.Erase(5);
	bst.Inorder();
	bst.Erase(3);
	bst.Inorder();
	bst.Erase(0);
	bst.Inorder();
	bst.Erase(1);
	bst.Inorder();
	bst.Erase(2);
	bst.Inorder();
	bst.Erase(4);
	bst.Inorder();
	bst.Erase(6);
	bst.Inorder();
	bst.Erase(7);
	bst.Inorder();

	return 0;
}
