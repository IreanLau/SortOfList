#include<iostream>
using namespace std;


struct Node
{
	int key;
	Node* next;
	Node(int nKey, Node* pNext)
		: key(nKey)
		, next(pNext)
	{}
};

void show(Node* pBeign)
{
	Node* cur = pBeign;
	while (cur)
	{
		cout << cur->key << " ";
		cur = cur->next;
	}
}

/***********************************************************************/


/*
	���ţ����������һ��  ʱ�临�Ӷ�O(n* lg n)

	��������
		1.ѡȡ����
		2.�������Ԫ�طֿ���  ��߱���С���ұ߱�����
		3.�ݹ���������������
*/

Node* GetPartion(Node* pBegin, Node* pEnd)
{
	Node* _key = pBegin;
	Node* prev = pBegin;
	Node* cur = prev->next;
	while (cur != pEnd)
	{
		if (cur->key < _key->key)
		{
			prev = prev->next;
			std::swap(prev->key, cur->key);
		}
		cur = cur->next;
	}
	std::swap(prev->key, pBegin->key);
	return prev;
}

void QuickSort(Node* pBeign, Node* pEnd)
{
	if (pBeign->next == pEnd || pBeign == NULL)
		return;
	if (pBeign != pEnd)
	{
		Node* partion = GetPartion(pBeign, pEnd);
		QuickSort(pBeign, partion);
		QuickSort(partion->next, pEnd);
	}
}

/********************************************************************************/


/*
		ð�� ��������  ʱ�临�Ӷ�O��n^2��

		��������
			1.����ʼλ�ÿ�ʼ��ѡȡ����Ԫ�أ� �Ƚϴ��򣬲�����Լ�����������
					�򽻻�����֤��i�ˣ��ѵ�i��С����Ԫ�طŵ�ָ��λ�ã�

			2.�߽����

			3.�ظ�������Ԫ�ظ���Ϊ�ܵ�������
*/

void BubbleSort(Node* pBegin)
{
	if (pBegin == NULL)
		return;
	Node* tail = NULL;

		/*�Ż��� ���� 1��2��3��4��5��0��9��7�����У�ǰ������Ѿ����򣩲����ظ�����*/
	bool flag = true;/*Ĭ������*/

	while (tail != pBegin)
	{
		Node* prev = pBegin;
		Node* cur = prev->next;
		while (cur != tail)
		{
			if (prev->key > cur->key)
			{
				swap(prev->key, cur->key);
				flag = false;/*һ��������������*/
			}
			prev = cur;
			cur = cur->next;
		}
		if (flag)
			return;

		tail = prev;
	}

}
/***********************************************************************************/

void main()
{
	Node *h = new Node(1, NULL);
	Node *g = new Node(0, h);
	Node *f = new Node(9, g);
	Node *e = new Node(7, f);

	Node *d = new Node(5, e);
	Node *c = new Node(3, d);
	Node *b = new Node(2, c);
	Node *a = new Node(4, b);
	/*	4 2 3 5 7 9 0 1	*/
	show(a);

	cout << endl;
	Node* pBeign = a;

	/*
	cout << "QuickSort:> \t" << endl;
	QuickSort(pBeign, NULL);
	show(a);
	cout << endl;
	*/

	cout << "BubbleSort:> \t" << endl;
	BubbleSort(pBeign);
	show(a);
	cout << endl;

}