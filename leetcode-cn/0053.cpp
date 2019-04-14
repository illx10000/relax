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
    //cout << endl;
}

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty())    return 0;

        int lastElement  = nums[0] ;
        int maxElement   = lastElement;

        for(int i = 1; i < nums.size(); ++ i)
        {
            lastElement = ( (lastElement > 0) ? (lastElement + nums[i]) :  nums[i] ); //选或者不选择
            if ( lastElement > maxElement ) {
                maxElement = lastElement;
            }
            
        }

        return maxElement;
    }
};

int main(int argc,char** argv)
{

    /*Solution a;

    string s = "busvutpwmu";
    cout << a.lengthOfLongestSubstring(s) << endl;*/

    //int a[]={1,8,6,2,5,4,8,3,7};
    //int a[]={-1, 0, 1, 2, -1, -4};
    int a[]={-2,1,-3,4,-1,2,1,-5,4};
    //int b[]={2,3,4}1


    vector<int> va(a,a+sizeof(a)/sizeof(a[0]));
    //vector<int> vb(b,b+sizeof(b)/sizeof(b[0]));

    vector<vector<int> > vvResult;


    Solution sssss;



    cout << sssss.maxSubArray(va) << endl;

    //printT(ss);
	//cout << (
	
    //va.clear(); for(int i = 10; i >=1 ;i--) va.push_back(i); va.push_back(1); va.push_back(0);
	//cout  << sssss.rotate(va) << endl;
		//) << endl;
	//printVector(va);

	//printT(sssss.removeDuplicates(va));
}

