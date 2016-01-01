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
	快排，交换排序的一种  时间复杂度O(n* lg n)

	分三步：
		1.选取枢轴
		2.用枢轴把元素分开，  左边比他小，右边比他大
		3.递归排序，左，右两部分
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
		冒泡 交换排序  时间复杂度O（n^2）

		分三部：
			1.从起始位置开始，选取两个元素， 比较次序，不满足约定（升序或降序）
					则交换（保证第i趟，把第i大（小）的元素放到指定位置）

			2.边界后移

			3.重复操作（元素个数为跑的趟数）
*/

void BubbleSort(Node* pBegin)
{
	if (pBegin == NULL)
		return;
	Node* tail = NULL;

		/*优化： 形如 1，2，3，4，5，0，9，7的数列，前五个（已经有序）不必重复操作*/
	bool flag = true;/*默认有序*/

	while (tail != pBegin)
	{
		Node* prev = pBegin;
		Node* cur = prev->next;
		while (cur != tail)
		{
			if (prev->key > cur->key)
			{
				swap(prev->key, cur->key);
				flag = false;/*一旦交换，则无序*/
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