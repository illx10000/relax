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
    int removeDuplicates(vector<int>& nums) {
		//  思路：result只有等到cur不和result一样的时候才前移 
		//
		//  template <class ForwardIterator>
		//  ForwardIterator unique (ForwardIterator first, ForwardIterator last)
		//  {
		//    if (first==last) return last;
		//  
		//    ForwardIterator result = first;
		//    while (++first != last)
		//    {
		//      if (!(*result == *first))  // or: if (!pred(*result,*first)) for version (2)
		//        *(++result)=*first;
		//    }
		//    return ++result;
		//  }
		//
		return std::unique(nums.begin(),nums.end()) - nums.begin() ;
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
    int a[]={0,0,1,1,1,2,2,3,3,4};
    //int b[]={2,3,4};

    vector<int> va(a,a+sizeof(a)/sizeof(a[0]));
    //vector<int> vb(b,b+sizeof(b)/sizeof(b[0]));

    vector<vector<int> > vvResult;
    Solution sssss;
	cout << (sssss.removeDuplicates(va)) << endl;
	printVector(va);

	//printT(sssss.removeDuplicates(va));
}

