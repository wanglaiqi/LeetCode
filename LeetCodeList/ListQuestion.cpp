#include<iostream>
#include<stack>
using namespace std;

//define struct about list
typedef struct ListNode
{
	int data;
	struct ListNode *next;
}ListNode,*LinkList;

class Solution
{
public:
	Solution();
	~Solution();
	//01 create singly linked list
	void createList(ListNode *head);
	//02 print list
	void printList(ListNode *head);
	//03 reverse singly linked list
	ListNode* reverseList(ListNode* head);
	//04 reverse between m and n
	ListNode* reverseBetween(ListNode* head, int m, int n);
	//05 print reverseListNode
	void printReverseList(ListNode *head);
	//0600 sort List
	ListNode* sortList(ListNode* head);
	//0601 mergerSort
	ListNode* mergeSort(ListNode *head);
	//0602 merge
	ListNode* Merge(ListNode *lhalf,ListNode *rhalf);
	//07 judge whether two list has the same data
	ListNode *findNode(ListNode *head1, ListNode *head2);
private:

};

Solution::Solution()
{
}

Solution::~Solution()
{
}

void Solution::createList(ListNode *head)
{
	int number = 0;
	cout << "input the number of linkedList" << endl;
	cin >> number;
	ListNode *p;
	for (int i = 0; i < number; i++)
	{
		p = (ListNode*)malloc(sizeof(ListNode));
		cin >> p->data;
		p->next = head->next;
		head->next = p;
	}
}

void Solution::printList(ListNode *head)
{
	ListNode *p = head;
	p = p->next;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

ListNode* Solution::reverseList(ListNode* head)
{
	ListNode *p = head;
	if (p==NULL)
	{
		return NULL;
	}
	ListNode *q = p->next;
	if (q == NULL)
	{
		return p;
	}
	else
	{
		head = reverseList(q);
		q->next = p;
		p->next = NULL;
	}
	return head;
}

ListNode* Solution::reverseBetween(ListNode* head, int m, int n)
{
	return head;
}

void Solution::printReverseList(ListNode *head)
{
	stack<ListNode *> stackNode;
	ListNode *pNode = head->next;
	while (pNode)
	{
		stackNode.push(pNode);
		pNode = pNode->next;
	}

	while (!stackNode.empty())
	{
		pNode = stackNode.top();
		cout << pNode->data << " ";
		stackNode.pop();
	}
	cout << endl;
}

ListNode* Solution::sortList(ListNode* head)
{
	if (head == NULL)
	{
		return NULL;
	}

	if (!head&&!head->next)
	{
		return head;
	}
	return mergeSort(head);
}

ListNode* Solution::mergeSort(ListNode *head)
{
	if (!head&&!head->next)
	{
		return head;
	}
	ListNode *p = head, *q = head, *pre = NULL;
	while (q&&q->next!=NULL)
	{
		q = q->next->next;
		pre = p;
		p = p->next;
	}
	pre->next = NULL;
	ListNode *lhalf = mergeSort(head);
	ListNode *rhalf = mergeSort(p);
	return Merge(lhalf,rhalf);
}

ListNode* Solution::Merge(ListNode *lhalf, ListNode *rhalf)
{
	ListNode *temp = new ListNode(0);
	ListNode *p = temp;
	while (lhalf && rhalf)
	{
		if (lhalf->data<rhalf->data)
		{
			p->next = lhalf;
			lhalf = lhalf->next;
		}
		else
		{
			p->next = rhalf;
			rhalf = rhalf->next;
		}
		p = p->next;
	}
	if (!lhalf)
	{
		p->next = rhalf;
	}
	else
	{
		p->next = lhalf;
	}
	p = temp->next;
	delete temp;
	return p;
}

ListNode * Solution::findNode(ListNode *head1, ListNode *head2)
{
	if (head1 == NULL || head2 == NULL)
	{
		return NULL;
	}
	ListNode *p1, *p2;
	p1 = head1;
	p2 = head2;
	int length1 = 0;
	int length2 = 0;
	int diff = 0;
	while (NULL!=p1->next)
	{
		p1 = p1->next;
		length1++;
	}

	while (NULL != p2->next)
	{
		p2 = p2->next;
		length2++;
	}
	if (p1 != p2)
	{
		return NULL;
	}
	diff = abs(length1-length2);
	if (length1 > length2)
	{
		p1 = head1;
		p2 = head2;
	}
	else
	{
		p1 = head2;
		p2 = head1;
	}

	for (int i = 0; i < diff; i++)
	{
		p1 = p1->next;
	}
	while (p1!=p2)
	{
		p1 = p1->next;
		p2 = p2->next;
	}
	return p1;
}

int main()
{	
	Solution solution;
	ListNode *head = (ListNode *)malloc(sizeof(ListNode));
	head->data = -1;
	head->next = NULL;
	//01
	solution.createList(head);
	//02
	solution.printList(head);
	//03
	//ListNode *head1 = solution.reverseList(head);
	//04
	//ListNdoe *head2 = solution.reverseBetween(head,2,4);
	//05
	solution.printReverseList(head);
	//06
	solution.sortList(head);
	solution.printList(head);
	system("pause");
	return 0;
}