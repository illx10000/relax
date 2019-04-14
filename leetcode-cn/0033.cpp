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
    //思路：假设定义分割点partition，partition的索引为index，  
    //则：nums[index] < nums[index+1] < nums[index-1]（题目中说无重复）
    // 先找到转点，然后在转点前后进行二分查找；

	//二分查找partitionPosition;
    int serachPartitionPosition(vector<int>& nums){	
		int low = 1, high = nums.size() -1 ;

		int middle = 0;
		while (low <= high)
		{
			middle = (low + high) / 2;
			if (nums[middle] < nums[0] ) //分割点在靠前的位置   
			{
				high = middle - 1;
			}
			else
			{
				low = middle + 1;
			}
		}
		return low ;
	}

	//在[begin_index,end_index中搜索target;
	int searchPosition(vector<int>& nums, int begin_index, int end_index, int target)
	{
		vector<int>::iterator it = std::lower_bound(nums.begin() + begin_index, nums.begin() + end_index, target) ;
		
		if ( it == nums.begin() + end_index ) //找不到
		{
			return -1;
		}
		else
		{
			if( *(it) != target ) return -1;
			else
			{
				return it - (nums.begin());
			}
		}
	}

    int search(vector<int>& nums, int target) {
		if (nums.empty())
		{
			return -1;
		}

		int partionPostion = serachPartitionPosition(nums);
		if (partionPostion ==  nums.size() ) //完全升序;
		{
			return searchPosition(nums,0,(int)nums.size(),target); 
		}
		else //判断是在拐点之前还是之后
		{
			if (target <= nums[nums.size()-1]) //后面查找
			{
				return searchPosition( nums, partionPostion, (int)nums.size(), target);
			}
			else
			{
				return searchPosition( nums, 0, partionPostion, target);
			}
		}
		return -1;
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
    int a[]={4,5,6,7,0,1,2};
    //int b[]={2,3,4};

    vector<int> va(a,a+sizeof(a)/sizeof(a[0]));
    //vector<int> vb(b,b+sizeof(b)/sizeof(b[0]));

    vector<vector<int> > vvResult;
    Solution sssss;
	//cout << (
	cout <<	sssss.search(va,0) << endl;
		//) << endl;
	//printVector(va);

	//printT(sssss.removeDuplicates(va));
}

