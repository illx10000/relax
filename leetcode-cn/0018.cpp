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
	string tostr(int t)
	{
		stringstream s;
		s << t;
		return s.str();
	};

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
         vector<vector<int>> result;
		 if( nums.size() < 4) return result;

		 sort(nums.begin(), nums.end());
		 
		 set<string> u;

		 for (int i = 0; i < (int)nums.size() -  3; i++)
		 {
			 for (int j = i + 1; j < (int)nums.size() - 2; j++)
			 {
				 for (int k = j + 1; k < (int)nums.size() - 1; k++)
				 {
					 int z = target - (nums[i] + nums[j] + nums[k]);

					 if ( binary_search( nums.begin() + k + 1, nums.end(), z ) )
					 {
						 string strGG = tostr(nums[i]) + tostr(nums[j]) + tostr(nums[k]);
						 if ( u.find(strGG) == u.end() )
						 {
							 u.insert(strGG);

							 vector<int> v;
							 v.push_back( nums[i]);
							 v.push_back( nums[j]);
							 v.push_back( nums[k]);
							 v.push_back( z );



							 result.push_back(v);
						 }

						 
					 }
				 }
			 }
		 }
		 return result;
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
    int a[]={-3,-2,-1,0,0,1,2,3};
    //int b[]={2,3,4};

    vector<int> va(a,a+sizeof(a)/sizeof(a[0]));
    //vector<int> vb(b,b+sizeof(b)/sizeof(b[0]));

    vector<vector<int> > vvResult;
    Solution sssss;
	printT(sssss.fourSum(va,0));
}

