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
void printT(vector<T> &arr)
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
        printT(arr[i]);
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
 
 void printT(const vector<Interval>& s){
     for(size_t i = 0; i < s.size(); ++i)
     {
         cout << "i:" << i << ",[" << s[i].start << "," << s[i].end << "]" << "\n";
     }
 }

template<typename T>
void printT(const T& t)
{
    cout << t << endl;
}

#include <map>
#include <utility>
#include <algorithm>
#include <stack>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int index_num1 = m-1;
        int index_num2 = n-1;
        int index_result = m+n-1;

        while ( index_result >=0  )
        {
            if(index_num1 < 0)
            {
                nums1[index_result--] = nums2[index_num2--];
            }
            else if(index_num2 < 0)
            {
                nums1[index_result--] = nums1[index_num1--];
            }
            else if( nums1[index_num1] > nums2[index_num2] )
            {
                nums1[index_result--] = nums1[index_num1--];
            }
            else 
            {
                nums1[index_result--] = nums2[index_num2--];
            }
        }
        
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
    int a[]={1,2,3,0,0,0};
    int b[]={2,5,6};

    vector<int> va(a,a+sizeof(a)/sizeof(a[0]));
    vector<int> vb(b,a+sizeof(b)/sizeof(b[0]));
    //vector<int> vb(b,b+sizeof(b)/sizeof(b[0]));
    Solution s;
    s.merge(va,3,vb,3);

    printT(va);
    //vector<vector<int> > xx = sssss.generateMatrix(1);
    //printVV(xx);
	//printT(sssss.removeDuplicates(va));
}

