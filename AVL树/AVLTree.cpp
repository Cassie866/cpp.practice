#include <iostream>
using namespace std;

//AVL��
template<class T>
struct AVLNode
{
	AVLNode(const T& data)
		: _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _data(data)
		, _bf(0)
	{}
	AVLNode<T>* _left; // �ýڵ������
	AVLNode<T>* _right; // �ýڵ���Һ���
	AVLNode<T>* _parent; // �ýڵ��˫��
	T _data;
	int _bf; // �ýڵ��ƽ������
};

template <class T>
class AVLTree
{
public:
	typedef AVLNode<T> Node;
	typedef Node* pNode;
	bool Insert(const T& date);//����
	void RotateRight(pNode cur); //����
	void RotateLeft(pNode cur);//����
	void _Inorder(pNode root);
	void Inorder();//���������ӡ
	int Height(pNode root);
	bool _isBalance(pNode root);
	bool isBalance();//�ж��Ƿ�ƽ��
private:
	pNode _root = nullptr;
};

template<class T>
bool AVLTree<T>::Insert(const T& data)
{
	if (_root == nullptr)
	{
		_root = new Node(data);
		return true;
	}
	//���ն�����������������data��AVL�еĲ���λ��
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
	//�����½ڵ�
	cur = new Node(data);
	if (data > parent->_data)
		parent->_right = cur;
	else
		parent->_left = cur;
	cur->_parent = parent;
	//����ƽ������
	while (parent)
	{
		// ����˫�׵�ƽ������
		if (cur == parent->_left)
			parent->_bf--;
		else
			parent->_bf++;
		// ���º���˫�׵�ƽ������
		if (parent->_bf == 0)
			break;
		else if (parent->_bf == 1 || parent->_bf == -1)
		{
			// ����ǰ˫�׵�ƽ��������0�������˫�׵�ƽ������Ϊ1 ���� -1 ��˵����˫��Ϊ���Ķ������ĸ߶�������һ�㣬�����Ҫ�������ϵ���
			cur = parent;
			parent = parent->_parent;
		}
		else if (parent->_bf == 2 || parent->_bf == -2)
		{
			// ˫�׵�ƽ������Ϊ����2��Υ����AVL����ƽ���ԣ���Ҫ����parentΪ������������ת����
			//��ߵ���߸�
			if (parent->_bf == -2 && cur->_bf == -1)
			{
				RotateRight(parent);
			}
			//�ұߵ��ұ߸�
			else if (parent->_bf == 2 && cur->_bf == 1)
			{
				RotateLeft(parent);
			}
			//�ұߵ���߸�
			else if (parent->_bf == 2 && cur->_bf == -1)
			{
				pNode subR = parent->_right;
				pNode subRL = subR->_left;
				RotateRight(subR);
				RotateLeft(parent);
				if (subRL->_bf == 1)
				{
					subR->_bf = 0;
					parent->_bf = -1;
				}
				else if (subRL->_bf == -1)
				{
					subR->_bf = 1;
					parent->_bf = 0;
				}
			}
			//��ߵ��ұ߸ߣ���������
			else if (parent->_bf == -2 && cur->_bf == 1)
			{
				pNode subL = parent->_left;
				pNode subLR = subL->_right;
				RotateLeft(subL);
				RotateRight(parent);
				if (subLR->_bf == 1)
				{
					parent->_bf = 0;
					subL->_bf = -1;
				}
				else if (subL->_bf == -1)
				{
					parent->_bf = 1;
					subL->_bf = 0;
				}
			}
			break;
		}
	}
	return true;
}

template<class T>
void AVLTree<T>::RotateRight(pNode cur)
{
	pNode subL = cur->_left;
	pNode subLR = subL->_right;
	subL->_right = cur;
	cur->_left = subLR;
	if (subLR)
		subLR->_parent = cur;
	if (cur != _root)
	{
		if (cur->_parent->_left == cur)
		{
			cur->_parent->_left = subL;
		}
		else
		{
			cur->_parent->_right = subL;
		}
		subL->_parent = cur->_parent;
	}
	else
	{
		_root = subL;
		subL->_parent = nullptr;
	}
	cur->_parent = subL;
	subL->_bf = cur->_bf = 0;
}

template<class T>
void AVLTree<T>::RotateLeft(pNode cur)
{
	pNode subR = cur->_right;
	pNode subRL = subR->_left;
	subR->_left = cur;
	cur->_right = subRL;
	if (subRL)
		subRL->_parent = cur;
	if (cur != _root)
	{
		if (cur->_parent->_left == cur)
			cur->_parent->_left = subR;
		else
			cur->_parent->_right = subR;
		subR->_parent = cur->_parent;
	}
	else
	{
		_root = subR;
		subR->_parent = nullptr;
	}
	cur->_parent = subR;
	subR->_bf = cur->_bf = 0;
}

template<class T>
void AVLTree<T>::_Inorder(pNode root)
{
	if (root)
	{
		_Inorder(root->_left);
		cout << root->_data << " ";
		_Inorder(root->_right);
	}
}
template<class T>
void AVLTree<T>::Inorder()
{
	_Inorder(_root);
	cout << endl;
}

template<class T>
int AVLTree<T>::Height(pNode root)
{
	if (root == nullptr)
		return 0;
	int Lh = Height(root->_left);
	int Rh = Height(root->_right);
	return Lh > Rh ? Lh + 1 : Rh + 1;
}
template<class T>
bool AVLTree<T>::_isBalance(pNode root)
{
	if (root == nullptr)
		return true;
	int Rh = Height(root->_right);
	int Lh = Height(root->_left);
	if (root->_bf != Rh - Lh)
	{
		cout << root->_data << "��ƽ��" << endl;
		cout << "ƽ�����ӣ�" << root->_bf << "�߶Ȳ" << Rh - Lh << endl;
		return false;
	}
	return abs(root->_bf) < 2 && _isBalance(root->_left) && _isBalance(root->_right);
}
template<class T>
bool AVLTree<T>::isBalance()
{
	return _isBalance(_root);
}

int main()
{
	AVLTree<int> avl;
	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
		avl.Insert(a[i]);
	avl.Inorder();
	cout << avl.isBalance() << endl;
	return 0;
}

