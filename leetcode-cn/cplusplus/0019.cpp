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
}

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        stack<ListNode*> node;
		
		ListNode* newHead = new ListNode(-1); newHead->next = head;
		ListNode* temp = newHead;

		while(temp != NULL)
		{
			node.push(temp);
			temp = temp->next;
		}

		ListNode* nodeToDelete = NULL;

		int cnt = 0;
		while(cnt < n && !node.empty())
		{
			nodeToDelete = node.top();
			node.pop();
			cnt++;
		}

		ListNode* prevNode = node.top();
		prevNode->next = nodeToDelete->next;

		//delete nodeToDelete;
		ListNode* result = newHead->next;
		delete newHead;
		return result;
    }
};



int main(int argc, char** argv)
{
	int a[] = { 1,2,3,4,5 };
	vector<int> va(a, a + sizeof(a) / sizeof(a[0]));

	ListNode* head = constrctList(va);

	Solution s;

	head = s.removeNthFromEnd(head,2);
	
	printList(head);
	
}

