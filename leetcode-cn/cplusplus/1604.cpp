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
	
	string tictactoe(vector<string>& board) {
		if (board.empty()) {
			return "Draw";
		}

		const int kSize = board.size();
		bool isEmpty = false;

		string result ;

		for (int i = 0; i < kSize; i++) {
			map<char, int> rowCount, colCount;
			for (int j = 0; j < kSize; j++) {
				rowCount[board[i][j]]++;
				colCount[board[j][i]]++;

				if (board[i][j] == ' ') {
					isEmpty = true;
				}
			}
			if (checkMap(rowCount, kSize, result)) return result;
			if (checkMap(colCount, kSize, result)) return result;
			
		}

		map<char, int> leftCount, rightCount;
		for (int i = 0; i < kSize; i++) {
			leftCount[board[i][i]]++;
			rightCount[board[i][kSize - 1 - i]]++;
		}
		if (checkMap(leftCount, kSize, result)) return result;
		if (checkMap(rightCount, kSize, result)) return result;

		return isEmpty ? "Pending":"Draw";
	}

	bool checkMap(map<char, int>& ch, int size, string& result) {
		if (ch['X'] == size) {
			result = "X";
			return true;
		}
		if (ch['O'] == size) {
			result = "O";
			return true;
		}
		return false;
	}




};


int main(int argc, char** argv)
{
	//int a[] = { 2,2,2,2,5,5,5,8  };
	int a[] = { 11,13,17,23,29,31,7,5,2,3 };

	//int a[] = { 1,2,3,2,3,1 };
	vector<int> va(a, a + sizeof(a) / sizeof(a[0]));

	int k = 3;
	int threshold = 4;

	Solution s;
	//cout << s.numOfSubarrays(va, k , threshold);
	//cout << s.numOfSubarrays(va, 3, 5);

	vector<string>  board = { "OOX","XXO","OX " };

	cout << s.tictactoe(board) << endl;

	return 0;

}

