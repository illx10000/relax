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
void printR(vector<T> &arr)
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

template<typename T>
void printR(const T& t)
{
    cout << "result:" << t << endl;
}


void printR( vector< vector<int> > &arr)
{
    for (size_t i = 0; i < arr.size(); i++)
    {
        printR(arr[i]);
    }
    //cout << endl;
}

/**
 * Definition for an interval.
 */
 struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };
 
 void printR(const vector<Interval>& s)
 {
     for(size_t i = 0; i < s.size(); ++i)
     {
         cout << "i:" << i << ",[" << s[i].start << "," << s[i].end << "]" << "\n";
     }
 }


#include <map>
#include <utility>
#include <algorithm>
#include <stack>

/**
 * 
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
 * ( 例如，数组 [0,0,1,2,2,5,6] 可能变为 [2,5,6,0,0,1,2] )。
 *
 * 编写一个函数来判断给定的目标值是否存在于数组中。若存在返回 true，否则返回 false。

 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


//https://illx.ink/article/21
//有序数组整体思路应该是应用二分查找加速查找速率；


class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.empty()) 
        {
            return false;
        }

        if(nums[0] == target || nums[nums.size() - 1] == target) 
        {
            return true;
        }

        int low  = 0;
        int high = (int)nums.size() - 1;

        while (low <= high)
        {
            int middle = (low+high)/2;

            if( nums[middle] == target)
            {
                return true;
            }

            if(nums[middle] == nums[low])
            {
                low++;
            }
            else if( nums[middle] > nums[low] ) //前半部分有序
            {
                if( target < nums[middle]  && target >= nums[low])
                {
                    high = middle - 1;
                }
                else
                {
                    low = middle + 1;
                }
                
            }
            else //后半部分有序
            {
                if( target > nums[middle] && target <= nums[high] )
                {
                    low = middle + 1;
                }
                else
                {
                    high = middle - 1;
                }
                
            }
            
        }
        if(low >= nums.size())
        {
            return false;
        }

        return nums[low] == target;      
    }
};


int main(int argc,char** argv)
{

    /*Solution a;

    string s = "busvutpwmu";
    cout << a.lengthOfLongestSubstring(s) << endl;*/

    //int a[]={1,8,6,2,5,4,8,3,7};
    //int a[]={-1, 0, 1, 2, -1, -4};
    //int a[]={2,1,2};
    //int a[]={2,1,5,6,100000,3};
    //int b[]={2,3,4}1
    //int a[]={4,5,6,7,0,1,2};
    int a[]={2,2,2,2,2};
    //int a[] = {1};

    vector<int> va(a,a+sizeof(a)/sizeof(a[0]));
    //vector<int> vb(b,b+sizeof(b)/sizeof(b[0]));
    Solution s;

    auto r = s.search(va,2);
    //printR(r);
    cout << (bool)r << endl;
    //vector<vector<int> > xx = sssss.generateMatrix(1);
    //printVV(xx);
	//printR(sssss.removeDuplicates(va));
}

