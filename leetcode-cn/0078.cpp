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

/**
 * Definition for an interval.
 */
 struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };
 
 void printVInterval(const vector<Interval>& s){
     for(size_t i = 0; i < s.size(); ++i)
     {
         cout << "i:" << i << ",[" << s[i].start << "," << s[i].end << "]" << "\n";
     }
 }

void printVV(vector<vector<int> >& v)
{
    for(size_t i = 0; i < v.size(); i++)
    {
        cout << "[";
        for(size_t j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << "]" << endl;
    }
    
}

#include <map>
#include <utility>

//[1,2,3,4] --> 
class Solution {
public:
    void dfs( vector<int>& nums, vector<vector<int>> &result, vector<int>& base ,int cur , bool bPush)
    {
        if (bPush)  base.push_back( nums[cur] );
        
        if ( cur == nums.size() - 1)
        {
            result.push_back(base);
        }
        else
        {
            dfs(nums, result, base, cur+1, false);
            dfs(nums, result, base, cur+1, true);
        }
        
        if(bPush)
        {
            base.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > result;
        vector<int> base;

        dfs(nums,result,base, 0, false);
        dfs(nums,result,base, 0, true);

        return result;
    }
};

int main(int argc,char** argv)
{

    /*Solution a;

    string s = "busvutpwmu";
    cout << a.lengthOfLongestSubstring(s) << endl;*/

    //int a[]={1,8,6,2,5,4,8,3,7};
    //int a[]={-1, 0, 1, 2, -1, -4};
    int a[]={1,2,3};
    //int b[]={2,3,4}1


    vector<int> va(a,a+sizeof(a)/sizeof(a[0]));
    //vector<int> vb(b,b+sizeof(b)/sizeof(b[0]));
    Solution s;

    auto r = s.subsets(va);
    printVV(r);
    //vector<vector<int> > xx = sssss.generateMatrix(1);
    //printVV(xx);
	//printT(sssss.removeDuplicates(va));
}

