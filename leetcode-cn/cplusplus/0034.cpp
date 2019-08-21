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
using std::set;
using std::stringstream;

class Solution {
public:
	//实现一个equal_range;
	//二分查找lower_bound,upper_bound

	int searchFirst(vector<int>& nums,int target)
	{
		int low = 0, high = nums.size() -1 ;

		while (low <= high)
		{
			int middle = (low+high)/2;
			if ( nums[middle] > target  )
			{
				high = middle -1;
			}
			else if( nums[middle] < target)
			{
				low = middle + 1;
			}
			else
			{
				if(low == high) return middle;
				else high = middle;
			}
		}
		return -1;
	}

	int searchLast(vector<int>& nums, int firstPos ,int target)
	{
		return std::upper_bound(nums.begin()+firstPos,nums.end(), target) - nums.begin() -1;
	}

    vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> v;

		if (nums.empty())
		{
			v.push_back(-1);v.push_back(-1);
			return v;
		}
		

		int firstPos = searchFirst(nums,target);
		if (-1 == firstPos)
		{
			v.push_back(-1);v.push_back(-1);
		}
		else
		{
			int lastPos = searchLast(nums,firstPos,target);
			v.push_back(firstPos);
			v.push_back(lastPos );
		}
		return v;
    }
};


template<typename T>
void printVector(vector<T> &arr)
{
    cout << "[";
    for (int i = 0; i < arr.size(); i++)
    {
        if (i)
        {
            cout << ",";
        }
        cout << arr[i] ;
    }
    cout << "]" << endl;
}


void printT( vector< vector<int> > &arr)
{
    for (size_t i = 0; i < arr.size(); i++)
    {
        printVector(arr[i]);
    }
}

int main(int argc,char** argv)
{

    /*Solution a;

    string s = "busvutpwmu";
    cout << a.lengthOfLongestSubstring(s) << endl;*/

    //int a[]={1,8,6,2,5,4,8,3,7};
    //int a[]={-1, 0, 1, 2, -1, -4};
    int a[]={8};
    //int b[]={2,3,4};

    vector<int> va(a,a+sizeof(a)/sizeof(a[0]));
    //vector<int> vb(b,b+sizeof(b)/sizeof(b[0]));

    vector<vector<int> > vvResult;
    Solution sssss;
	//cout << (
	printVector(sssss.searchRange(va,8));;
		//) << endl;
	//printVector(va);

	//printT(sssss.removeDuplicates(va));
}

