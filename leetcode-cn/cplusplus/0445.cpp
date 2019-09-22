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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1,s2;
		ListNode* head1 = l1, *head2 = l2;
		while(head1)
		{
			s1.push( head1->val );
			head1 = head1->next;
		}

		while (head2)
		{
			s2.push(head2->val);
			head2 = head2->next;
		}
		
		stack<int> result;

		int carrybit = 0;
		while( !s1.empty() || !s2.empty() )
		{
			if(s1.empty())
			{
				int value= (s2.top() + carrybit) % 10;
				carrybit = (s2.top() + carrybit) / 10;
				result.push(value);
				s2.pop();
			}
			else if(s2.empty())
			{
				int value= (s1.top() + carrybit) % 10;
				carrybit = (s1.top() + carrybit) / 10;
			
				result.push(value);
				s1.pop();
			}
			else 
			{
				int value = (s1.top()+s2.top()+ carrybit)%10;
				carrybit = (s1.top()+s2.top()+carrybit)/10;
				
				result.push(value);
				s1.pop();
				s2.pop();
			}
		}
		if(carrybit != 0)
		{
			result.push(carrybit);
		}

		ListNode* dummyHead = new ListNode(-1);
		ListNode* curr = dummyHead;
		while(!result.empty())
		{
			curr->next = new ListNode(result.top());
			curr = curr->next;
			result.pop();
		}
		
		ListNode* t = dummyHead->next;
		delete dummyHead;
		return t;
    }
};

int main(int argc, char** argv)
{
	int a[] = { 7,2,4,3 };
	//int a[] = { 1,2,3,2,3,1 };
	vector<int> va(a, a + sizeof(a) / sizeof(a[0]));
	ListNode* l1 = constrctList(va);
	

	int b[] = { 5,6,4 };
	//int a[] = { 1,2,3,2,3,1 };
	vector<int> vb(b, b + sizeof(b) / sizeof(b[0]));
	ListNode* l2 = constrctList(vb);
	
	

	Solution s;

	auto temp =  s.addTwoNumbers(l1,l2);

	printT(temp);
}

