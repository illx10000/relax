﻿#include <iostream>
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
#include <queue>
#include <stack>

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


using namespace std;

void printT(TreeNode* root)
{
	if (root)
	{
		
		cout << root->val << " ";
		printT(root->left);
		printT(root->right);
	}
}

void printT(vector<TreeNode*> t)
{
	for_each(t.begin(),t.end(), [](TreeNode* temp){ printT(temp); cout << endl;});
}

class Solution {
public:
    int numTrees(int n) 
		{
			//递归超时
			/*
        if(n == 0)
				{
					 return 0;
				}
				return helper(1,n);
				*/
			 vector<long> result; //result 数组存储的是长度为 n的二叉搜索树的个数
			 result.resize(n+2);
			 result[0] = 1;
			 result[1] = 1;

			 //长度为i的二叉搜索树的个数应该是，长度为 [1,j-1],[j+1,n] 的二叉树积

			 for(int i = 2; i <= n; i++)
			 {
				  for(int j = 1; j <= i; j++)
					{
						 result[i] += (result[j-1] * result[i-j]);
					}
			 }
			 return result[n];
    }

		
		int helper(int low, int high)
		{
			 int cnt = 0;
			 if( high < low )
			 {
				  return 1;
			 }
			 else 
			 {
				  for(int i = low; i<= high; i++)
					{
						 int leftCnt = helper(low, i - 1);
						 int rightCnt = helper(i+1, high);
						 cnt += leftCnt*rightCnt;
					}
			 }
			 return cnt;
		}
};

int main(int argc, char** argv)
{
	int a[] = { 1,2,3,4,5 };
	//int a[] = { 1,2,3,3,4,4,5 };
	vector<int> va(a, a + sizeof(a) / sizeof(a[0]));
	
	TreeNode* root = new TreeNode(12);

	Solution s;

    auto t = s.numTrees(3);
	printT(t);

}

