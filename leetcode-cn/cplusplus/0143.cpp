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


class Solution {
public:
	ListNode* reverseList(ListNode* head, ListNode* tail = NULL)
	{
		if( head == tail || head->next == tail )
		{
			return head;
		}

		ListNode* prev = head;
		ListNode* curr = head->next;
		while (curr != tail)
		{
			ListNode* next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		
		head->next = tail;
		return prev;
	}

	ListNode* mergeList(ListNode* head1, ListNode* tail1, ListNode* head2, ListNode* tail2)
	{
		ListNode* dummyHead = new ListNode(-1);
		ListNode* tail = dummyHead;
		
		int cnt = 0;

		while (head1 != tail1 || head2 != tail2)
		{
			if(cnt % 2 == 0  || head2 == tail2 )
			{
				ListNode* nxt = head1->next;
				tail->next = head1;
				tail = tail->next;
				head1 = nxt;
			}	
			else
			{
				ListNode* nxt = head2->next;
				tail->next = head2;
				tail = tail->next;
				head2 = nxt;
			}
			cnt++;
		}
		tail->next = NULL;

		ListNode* result = dummyHead->next;
		delete dummyHead;
		return result;
	}

	int countList(ListNode* head)
	{
		int cnt = 0;
		while (head)
		{
			cnt++;
			head =  head->next;
		}
		return cnt;
	}

    void reorderList(ListNode* head) 
	{
		ListNode* cur = head,*prev = NULL;
		int list_cnt = countList(cur);

		int cnt = 0;
		while (cnt < (list_cnt+1)/2)
		{
			prev = cur;
			cur = cur->next;
			cnt++;
		}
		//1,2,3,4 ==> prev -> 2, cur -> 3
		
		ListNode* l1Begin = head, *l1end = cur;
		ListNode* l2Begin = reverseList(cur,NULL);

		head = mergeList(l1Begin, l1end,l2Begin,NULL);
    }
};


int main(int argc, char** argv)
{
	int a[] = { 1,2,3,4,5 };
	vector<int> va(a, a + sizeof(a) / sizeof(a[0]));
	ListNode* l1 = constrctList(va);
	
	/*
	int b[] = { 6,7,8 };
	vector<int> vb(b, b + sizeof(b) / sizeof(b[0]));
	ListNode* l2 = constrctList(vb);
	*/

	Solution s;

	s.reorderList(l1);

	printT(l1);
}

