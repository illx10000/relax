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

//https://www.cnblogs.com/ECJTUACM-873284962/p/6935506.html
//参考基数排序

class Solution {
public:
	
	int replace(vector<int>& nums,int index)
	{
		//(假设index上的数nums[index]，则应该将这个数set到num的 （nums[index]-1)的位置上)
		//例如a[1] = 3; 这应该将a[3-1]设置为3，如果a[3-1]非法直接换，否则需要先换 3-1的位置
		//

		int next_index	= nums[index] - 1;
		int next_n		= nums[ next_index ];

		if( next_n <= 0 || next_n > nums.size() )//待替换的位置是非法数直接替换；
		{
			swap(nums[index], nums[ next_index ]); 
		}
		else //先要将该位置上合法的数替换掉
		{
			if( nums[next_index] == next_index + 1 ) return index; //过滤重复

			int cur_num = nums[index];
			nums[index] = 0; //先标记为非法的数字,避免死循环
			int last_index = replace( nums, next_index  ); //下一个非法数索引的位置
			nums[last_index] = cur_num; //恢复
		}
		return index; //next_index的值是OK的，空缺是index
	}

    int firstMissingPositive(vector<int>& nums) {
		int n_size = nums.size();

		for (int i = 0; i < n_size; i++)
		{
			//int cur_num = nums[i];
			if( nums[i] == i+1 )	continue;
			else if( nums[i] <= 0 || nums[i] > nums.size() ) continue; 
			else replace(nums,i);	
			
		}
		
		int k = 0;
		for (; k < (int)nums.size(); k++)
		{
			if(nums[k] != k +1) break;
		}
		return k+1;
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
    int a[]={1,2,-1};
    //int b[]={2,3,4};

    vector<int> va(a,a+sizeof(a)/sizeof(a[0]));
    //vector<int> vb(b,b+sizeof(b)/sizeof(b[0]));

    vector<vector<int> > vvResult;
    Solution sssss;
	//cout << (
	
	cout  << sssss.firstMissingPositive(va) << endl;
		//) << endl;
	//printVector(va);

	//printT(sssss.removeDuplicates(va));
}

