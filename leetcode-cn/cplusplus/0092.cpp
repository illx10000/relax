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

void printList(ListNode* head)
{
	while (head != NULL)
	{
		cout << head->val << " ->";
		head = head->next;
	}
	cout << endl;
}


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

	ListNode* reserver(ListNode* head, ListNode* tail)
	{
		if(head == tail || head->next == tail)
		{
			return head;
		}

		ListNode* prev = head;
		ListNode* curr = head->next;

		// 1 -> 2 -> 3 -> 4
		// 1 <- 2 -> 3 -> 4 
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

    ListNode* reverseBetween(ListNode* head, int m, int n) 
	{
		ListNode* dummyHead = new ListNode(-1);
		dummyHead->next = head;

		ListNode* mPrev = dummyHead,*nPrev = dummyHead, *mCurr = head, *nCurr = head;

		int mCnt = 1, nCnt = 1;
		
		while (mCnt < m)
		{
			mPrev = mCurr;
			mCurr = mCurr->next;
			mCnt++;
		}
		
		while ( nCnt < n )
		{
			nPrev = nCurr;
			nCurr = nCurr->next;
			nCnt++;
		}

		ListNode* nxt = nCurr->next;

		ListNode* newHead = reserver(mCurr,nCurr->next);	
		mPrev->next = newHead;
		
		ListNode* result = dummyHead->next;
		delete dummyHead;
		return result;
    }
};


int main(int argc, char** argv)
{
	int a[] = { 1,2,3,4,5 };
	//int a[] = { 1,2,3,3,4,4,5 };
	vector<int> va(a, a + sizeof(a) / sizeof(a[0]));
	ListNode* l1 = constrctList(va);
	printList(l1);

	/*
	int b[] = { 1,3,4 };
	vector<int> vb(b, b + sizeof(b) / sizeof(b[0]));

	int c[] = { 2,6 };
	vector<int> vc(c, c + sizeof(c) / sizeof(c[0]));



	ListNode* l2 = constrctList(vb);
	printList(l2);

		ListNode* l3 = constrctList(vc);
	printList(l3);
	vector<ListNode*> nodes;
	nodes.push_back(l1);
nodes.push_back(l2);
nodes.push_back(l3);
*/
	Solution s;

	ListNode* temp = s.reverseBetween(l1,2,4);

	printList(temp);

}

