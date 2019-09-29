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
	int countList(ListNode* head)
	{
		int cnt = 0; 
		while (head)
		{
			cnt++;
			head = head->next;
		}
		return cnt;
	}

    vector<ListNode*> splitListToParts(ListNode* root, int k) {
		vector<ListNode*> result;
	
		ListNode* curr = root;
		int cnt = countList(curr);

		if(k >= cnt) //不够切分
		{
			ListNode* temp = root;
			for (int i = 0; i < k; i++)
			{
				if(temp)
				{
					ListNode* t = temp->next;
					temp->next = NULL;
					result.push_back(temp);
					temp = t; 
				}
				else
				{
					result.push_back(NULL);
				}
			}
		}
		else 
		{
			int divide =  cnt / k; //vector每一个的元素需要填充的个数
			int left   =  cnt % k; //多出来的个数

			for(int i = 0; i<k;i++)
			{
				int curCount = divide;
				if(left>0)
				{
					curCount++;
					left--;
				}

				ListNode* tempHead = curr,*prev = curr;
				while (curCount--)
				{
					prev = curr;
					curr = curr->next;
				}
				
				prev->next = NULL;
				result.push_back(tempHead);
			}
		}
		return result;
    }
};

int main(int argc, char** argv)
{
	int a[] = { 1,2,3,4,5,9 };
	//int a[] = { 1,2,3,2,3,1 };
	vector<int> va(a, a + sizeof(a) / sizeof(a[0]));
	ListNode* l1 = constrctList(va);
	

	int b[] = { 5,6,4 };
	//int a[] = { 1,2,3,2,3,1 };
	vector<int> vb(b, b + sizeof(b) / sizeof(b[0]));
	ListNode* l2 = constrctList(vb);
	
	

	Solution s;

	auto temp =  s.splitListToParts(NULL,8);

	for(int i = 0; i< temp.size();i ++)
	{
		printT(temp[i]);
		cout << endl;
	}
}

