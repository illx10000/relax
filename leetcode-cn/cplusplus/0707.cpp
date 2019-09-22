#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstdint>
#include <set>
#include <string>

using namespace std;

#include <set>
#include <string>
#include <sstream>


template<typename T>
void printT(vector<T>& arr)
{
	cout << "[";
	for (int i = 0; i < (int)arr.size(); i++)
	{
		if (i)
		{
			cout << ",";
		}
		cout << arr[i];
	}
	cout << "]" << endl;
}


void printT(vector< vector<int> >& arr)
{
	for (size_t i = 0; i < arr.size(); i++)
	{
		printT(arr[i]);
	}
}

void printT(vector< vector<string> >& arr)
{
	for (size_t i = 0; i < arr.size(); i++)
	{
		printT(arr[i]);
	}
}

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

void printT(const vector<Interval>& s)
{
	for (size_t i = 0; i < s.size(); ++i)
	{
		cout << "i:" << i << ",[" << s[i].start << "," << s[i].end << "]" << "\n";
	}
}

template<typename T>
void printT(const T& t)
{
	cout << t;
}


struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include <map>
#include <utility>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <hash_map>

using namespace std;

void printT(TreeNode* root)
{
	if (root)
	{
		printT(root->left);
		cout << root->val << endl;
		printT(root->right);
	}

}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* constrctList(vector<int>& num)
{
	ListNode* head = new ListNode(-1);
	ListNode* tail = NULL;

	for (int i = 0; i < num.size(); i++)
	{
		if (NULL == tail)
		{
			tail = new ListNode(num[i]);
			head->next = tail;
		}
		else
		{
			tail->next = new ListNode(num[i]);
			tail = tail->next;
		}
	}

	ListNode* result = head->next;
	delete head;
	return result;
}

void printT(ListNode* head)
{
	while (head != NULL)
	{
		cout << head->val << " ->";
		head = head->next;
	}
	cout << endl;
}


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};


class MyLinkedList {
public:
	struct ListNodeInner {
		int val;
		ListNodeInner* next;
		ListNodeInner(int x) : val(x), next(NULL) {}
	};


    /** Initialize your data structure here. */
    MyLinkedList() {
        _head = new ListNodeInner(-1);
		_tail = NULL;
		_size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
		if(index <0 || index >= _size)
		{
			return -1;
		}
		
        int cnt = 0;
		ListNodeInner* innerHead = _head->next;
		ListNodeInner* temp = _head->next;

		// 0,1,2

		while (cnt < index && innerHead != NULL)
		{
			cnt++;
			innerHead = innerHead->next;
		}
		
		if(innerHead != NULL)
		{
			return innerHead->val;
		}
		return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNodeInner* newNode = new ListNodeInner(val);
		newNode->next = _head->next;
		_head->next = newNode;
		if(_tail == NULL)
		{
			_tail = newNode;
		}
		_size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        if(_tail == NULL)
		{
			addAtHead(val);
		}
		else 
		{
			ListNodeInner* newNode = new ListNodeInner(val);
			_tail->next = newNode;
			_tail = newNode;
			_size++;
		}
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(0 == index)
		{
			addAtHead(val);
		}
		else if(_size == index)
		{
			addAtTail(val);
		}
		else if(index < _size)
		{
			ListNodeInner* prev = _head, *curr = _head->next;
			int cnt = 0;
			while (cnt < index) //0,3
			{
				prev = curr;
				curr = curr->next;
				cnt++;
			}
			ListNodeInner* newNode = new ListNodeInner(val);
			newNode->next = curr;
			prev->next = newNode;
			_size++;
		}
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index >= 0 && index < _size)
		{
			ListNodeInner* prev = _head, *curr = _head->next;
			int cnt = 0;
			while (cnt < index) //0,1,3
			{
				prev = curr;
				curr = curr->next;
				cnt++;
			}
			//index == 1 ==> curr -> 1
			prev->next = curr->next;
			_size--;

			if(curr->next == NULL)
			{
				_tail = prev;
			}
			delete curr;
		}
    }

private:
	ListNodeInner* _head,*_tail;
	int _size;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main(int argc, char** argv)
{
	int a[] = { 0,1,2,3,4 };
	//int a[] = { 1,2,3,2,3,1 };
	vector<int> va(a, a + sizeof(a) / sizeof(a[0]));
	ListNode* l1 = constrctList(va);
	

	int b[] = { 6 };
	//int a[] = { 1,2,3,2,3,1 };
	vector<int> vb(b, b + sizeof(b) / sizeof(b[0]));
	ListNode* l2 = constrctList(vb);
	
	
	MyLinkedList linkedList;
	linkedList.addAtHead(1);
	linkedList.addAtTail(3);
	linkedList.addAtIndex(1,2);   //链表变为1-> 2-> 3
	linkedList.get(-1);            //返回2
	linkedList.deleteAtIndex(1);  //现在链表是1-> 3
	cout << linkedList.get(1) << endl ;             //返回3


}

