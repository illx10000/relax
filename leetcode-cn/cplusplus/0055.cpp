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
    bool canJump(vector<int>& nums) {
		if(nums.empty()) return false;

		vector<int> reach; reach.resize( nums.size());
		for( int i = 0; i < nums.size(); i ++)
		{
			reach[i] = ( (nums[i] + i ) >= nums.size() - 1) ? 1 : 0;
		}

		for( int i = nums.size() - 2 ; i >= 0; i--)
		{
			for(int j = 1 ; j <= nums[i]; j++)
			{
				if(i+j >= nums.size() - 1)
				{
					reach[i] = 1;
					break;
				}

				if( reach[i+j] ) 
				{
					reach[i] = 1;
					break;
				}
			}
		}

		return reach[0];
    }
};
int main(int argc,char** argv)
{

    /*Solution a;

    string s = "busvutpwmu";
    cout << a.lengthOfLongestSubstring(s) << endl;*/

    //int a[]={1,8,6,2,5,4,8,3,7};
    //int a[]={-1, 0, 1, 2, -1, -4};
    int a[]={3,2,1,0,4};
    //int b[]={2,3,4}1


    vector<int> va(a,a+sizeof(a)/sizeof(a[0]));
    //vector<int> vb(b,b+sizeof(b)/sizeof(b[0]));

    vector<vector<int> > vvResult;


    Solution sssss;


	vector< vector<int> > ss ;
    const int N = 4;

    for(int i = 0; i < N; i++)
    {
        vector<int> vvvv;
        for(int j = 0; j < N + 2; j++)
        {
            vvvv.push_back( i * (N + 2) + j  + 1);
        }
        ss.push_back(vvvv);
    }
    //printT(ss);
    //cout << endl;

	//vector<int> vb = sssss.spiralOrder(ss);
	cout << sssss.canJump(va) << endl;
	//printVector(vb);


	//printT(sssss.removeDuplicates(va));
}

