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

#if 0
class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		vector<int> result;
		if (nums.empty())
		{
			return result;
		}

		int topA = nums[0], topB = nums[0], countA = 0, countB = 0;
		
		for (size_t i = 0; i < nums.size(); i++)
		{
			if (nums[i] == topA)
			{
				countA++;
				continue;
			}
			if (nums[i] == topB)
			{
				countB++;
				continue;
			}

			if (countA == 0)
			{
				topA = nums[i];
				countA++;
				continue;
			}

			if (countB == 0)
			{
				topB = nums[i];
				countB++;
				continue;
			}

			countA--;
			countB--;
		}

		countA = countB = 0;
		for (size_t i = 0; i < nums.size(); i++)
		{
			if (nums[i] == topA)
			{
				countA++;
			}
			else if (nums[i] == topB)
			{
				countB++;
			}
		}

		if (countA > nums.size() / 3)
		{
			result.push_back(topA);
		}
		if (countB > nums.size() / 3)
		{
			result.push_back(topB);
		}
		return result;
	}
};
#endif

class Solution {
public:

	vector<int> majorityElement(vector<int>& nums) {
		vector<int> v;
		unordered_set<int> s;

		if (nums.empty())
		{
			return v;
		}

		int flow = nums.size() / 3;
		unordered_map<int, int> mp;
		for (int i = 0; i < nums.size(); i++)
		{
			if (++mp[nums[i]] > flow && s.find(nums[i]) == s.end())
			{
				v.push_back(nums[i]);
				s.insert(nums[i]);
			}
		}
		return v;
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
	int a[] = { 1,1,1,3,3,2,2,2 };
	int b[] = { 9,15,7,20,3 };


	vector<int> va(a, a + sizeof(a) / sizeof(a[0]));
	vector<int> vb(b, b + sizeof(b) / sizeof(b[0]));

	Solution s;

	vector<vector<int> > v = {
		{2},
		{3,4},
		{6,5,7},
		{4,1,8,3}
	};

	auto r = s.majorityElement(va);
	//auto r = s.majorityElement(va);
	//auto r = FindIdx(a,0, );

	printT(r);
	//vector<vector<int> > xx = sssss.generateMatrix(1);
	//printVV(xx);
	//printT(sssss.removeDuplicates(va));
}

