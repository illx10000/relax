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
	void moveZeroes(vector<int>& nums) {
		if (nums.empty())
		{
			return ;
		}

		int low = 0, high = 0; //low第一为0的位置，high为第一个非0的位置

		do
		{
			while (low < nums.size() && nums[low] != 0)
			{
				low++;
			}

			high = low + 1;

			while (high < nums.size() && nums[high] == 0)
			{
				high++;
			}
			//cout << "high:" << high << ",low:" << low << endl;

			if (high < nums.size() && low < nums.size() )
			{
				swap(nums[low],nums[high]);
				high++;
				low++;
			}
			else
			{
				break;
			}

		} while (true);
		
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
	int a[] = { 0,1,0,3,12 };
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

	s.moveZeroes(va);
	//auto r = s.majorityElement(va);
	//auto r = FindIdx(a,0, );

	printT(va);
	//vector<vector<int> > xx = sssss.generateMatrix(1);
	//printVV(xx);
	//printT(sssss.removeDuplicates(va));
}

