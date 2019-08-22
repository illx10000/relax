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



class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> v1,v2,result;

		if (nums.empty())
		{
			return result;
		}
		

		v1.push_back(nums[0]);
		for (int i = 1; i < nums.size(); i++)
		{
			v1.push_back(nums[i] * v1.back());
		}

		v2.resize(nums.size());
		v2[v2.size()-1] = nums.back();

		for (int i = nums.size() - 2; i >= 0; i--)
		{
			v2[i] = v2[i+1] * nums[i];
		}

		printT(v1);
		printT(v2);

		result.resize(nums.size());
		for (int i = 0; i < nums.size(); i++)
		{
			if (i == 0)
			{
				result[i] = v2[1];
			}
			else if (i == nums.size() - 1)
			{
				result[i] = v1[nums.size()-2];
			}
			else
			{
				result[i] = v1[i-1] * v2[i+1]; 
			}
		}

		return result;
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
	int a[] = { 1,2,3,4 };
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

	auto r = s.productExceptSelf(va);
	//auto r = s.majorityElement(va);
	//auto r = FindIdx(a,0, );

	printT(r);
	//vector<vector<int> > xx = sssss.generateMatrix(1);
	//printVV(xx);
	//printT(sssss.removeDuplicates(va));
}

