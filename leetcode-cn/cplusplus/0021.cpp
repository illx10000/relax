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
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* constrctList(vector<int> &num)
{
	ListNode* head = new ListNode(-1);
	ListNode* tail = NULL;

	for(int i = 0; i < num.size();i++)
	{
		if(NULL == tail)
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
	
	ListNode* result =  head->next;
	delete head;
	return result;
}

void printList(ListNode* head)
{
	while (head != NULL)
	{
		cout << head->val << " ->" ;
		head = head->next;
	}
	cout << endl;
}

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* head = new ListNode(-1);
		ListNode* tail = head;

		while(l1 != NULL && l2 != NULL)
		{
			if(l1->val < l2->val)
			{
				tail->next = l1;
				l1 = l1->next;
				tail = tail->next;
			}
			else 
			{
				tail->next = l2;
				l2 = l2->next;
				tail = tail->next;
			}
		}
		tail->next = (l1 == NULL) ? l2 : l1;

		ListNode* result = head->next;
		delete head;
		return result;
    }
};


int main(int argc, char** argv)
{
	int a[] = { 1,2,3,7,8 };
	vector<int> va(a, a + sizeof(a) / sizeof(a[0]));

	int b[] = { 4,5,9 };
	vector<int> vb(b, b + sizeof(b) / sizeof(b[0]));


	ListNode* l1 = constrctList(va);
	printList(l1);

	ListNode* l2 = constrctList(vb);
	printList(l2);

	Solution s;

	ListNode* temp = s.mergeTwoLists(l1,l2);
	
	printList(temp);
	
}

