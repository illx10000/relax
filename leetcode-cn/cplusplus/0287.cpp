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
	int findDuplicate(vector<int>& nums) {
		if (nums.empty()) {
			return 0;
		}

		int slow_index = nums[0];
		int fast_index = nums[0];

		do
		{
			slow_index = nums[slow_index] ;
			fast_index = nums[nums[fast_index] ] ;

		}while(nums[slow_index] != nums[fast_index]);

		fast_index = nums[0];

		while (fast_index != slow_index)
		{
			slow_index = nums[slow_index];
			fast_index = nums[fast_index];
		}

		return fast_index;
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
		{2},
		{3,4},
		{6,5,7},
		{4,1,8,3}
	};

	auto r = s.findDuplicate(va);
	printT(r);

	//auto r = s.majorityElement(va);
	//auto r = FindIdx(a,0, );

	printT(va);
	//vector<vector<int> > xx = sssss.generateMatrix(1);
	//printVV(xx);
	//printT(sssss.removeDuplicates(va));
}

