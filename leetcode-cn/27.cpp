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
    int removeElement(vector<int>& nums, int val) {
		int low = 0, high = (int)nums.size() - 1;

		while (low <= high)
		{
			if(val == nums[low])	 //需要找一个不等于val的值替换
			{
				while (nums[high] == val && high > low)
				{
					high--;
				}

				if(high == low) return low;
				if(nums[high] != val) 
				{ 
					swap( nums[low], nums[high]); 
					high --;  
					low++;
				}
			}
			else
			{
				low++;
			}
			//停下来交换
		}
		return low;
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
    int a[]={3,2,2,3};
    //int b[]={2,3,4};

    vector<int> va(a,a+sizeof(a)/sizeof(a[0]));
    //vector<int> vb(b,b+sizeof(b)/sizeof(b[0]));

    vector<vector<int> > vvResult;
    Solution sssss;
	cout << (sssss.removeElement(va,2)) << endl;
	printVector(va);

	//printT(sssss.removeDuplicates(va));
}

