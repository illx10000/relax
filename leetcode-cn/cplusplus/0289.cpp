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
#include <unordered_set >
#include <unordered_map >


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

#include <unordered_set>

class Solution {
public:
	/*
	 * 判断某一个点的细胞是否存活
	*/

	int liveCount(vector<vector<int> >& board, int x, int y)
	{
		int count = 0;

		for (int i = -1; i <= 1; i++)
		{
			for (int j = -1; j <= 1; j++)
			{
				int xPos = x + i;
				int yPos = y + j;

				if (xPos >= 0 && xPos < board.size() && yPos >= 0 && yPos < board[0].size() && !(i == 0 && j == 0) )
				{
					count += board[x+i][y+j];
					//cout << "(" << x << "," << y << ") ++>" << "(" << xPos << "," << yPos << ") ++>" << board[x + i][y + j] << endl;
				}
			}
		}
		return count;
	}

	int isLive(vector<vector<int> >& board, int x, int y)
	{
		int count = liveCount(board,x,y);
		//cout << "(" << x <<"," << y << ") -->" << count << endl;

		if (board[x][y]) //活细胞
		{
			return (count == 2 || count == 3) ? 1 : 0;
		}
		else
		{
			return (count == 3) ? 1 : 0;
		}
		return 0;
	}

	void gameOfLife(vector<vector<int> >& board) {
		if (board.empty() || board[0].empty())
		{
			return ;
		}

		vector<vector<int>> result(board);
		for (size_t i = 0; i < board.size(); i++)
		{
			for (size_t j = 0; j < board[i].size(); j++)
			{
				result[i][j] = isLive(board, i, j);
			}
		}
		board.swap(result);
	}
};

int main(int argc, char** argv)
{

	/*Solution a;

	string s = "busvutpwmu";
	cout << a.lengthOfLongestSubstring(s) << endl;*/

	//int a[]={1,8,6,2,5,4,8,3,7};
	//int a[]={-1, 0, 1, 2, -1, -4};
	//int a[]={2,1,2};
	//int a[]={2,1,5,6,100000,3};
	int a[] = { 1,3,4,2,2 };
	int b[] = { 9,15,7,20,3 };


	vector<int> va(a, a + sizeof(a) / sizeof(a[0]));
	vector<int> vb(b, b + sizeof(b) / sizeof(b[0]));

	Solution s;

	vector<vector<int> > v = {
		{0,1,0},
		{0,0,1},
		{1,1,1},
		{0,0,0}
	};

	s.gameOfLife(v);
	printT(v);

	//auto r = s.majorityElement(va);
	//auto r = FindIdx(a,0, );

	//printT(va);
	//vector<vector<int> > xx = sssss.generateMatrix(1);
	//printVV(xx);
	//printT(sssss.removeDuplicates(va));
}

