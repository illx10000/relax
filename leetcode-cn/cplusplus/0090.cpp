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
}

 struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };
 
 void printT(const vector<Interval>& s)
 {
     for(size_t i = 0; i < s.size(); ++i)
     {
         cout << "i:" << i << ",[" << s[i].start << "," << s[i].end << "]" << "\n";
     }
 }

template<typename T>
void printT(const T& t)
{
    cout << t ;
}


#include <map>
#include <utility>
#include <algorithm>
#include <stack>
using namespace std;

class Solution {
public:

    typedef vector<int> vInt;
    typedef vector< vector<int> > vvInt;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        map<int,int> mp;
        for(int i = 0; (int) i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }    
        
        vvInt vvResult;
        subsetsWithDup(mp,vvResult);
        return vvResult;
    }


    void subsetsWithDup(map<int,int>& numCnt, vvInt &resultSet)
    {
        vInt emptySet;

        for(map<int,int>::iterator it = numCnt.begin(); it != numCnt.end(); it++)
        {
            vvInt vvTemp,vvTempResult;
            makeSetFromNum(it->first, it->second, vvTemp);
            //printT(vvTemp);
            mergeSet(resultSet, vvTemp, vvTempResult); // merge resulstSet and vvTemp ==> vvTempResult
            resultSet.swap(vvTempResult);
        }
        resultSet.push_back(emptySet);
    }

    void makeSetFromNum(int num,int cnt, vvInt& vResult)
    {
        vector<int> vTemp;

        for (size_t i = 0; i < cnt; i++)
        {
            vTemp.push_back(num);
            vResult.push_back(vTemp);
        }
    }
    
    void mergeSet(vvInt& vSet1, vvInt& vSet2, vvInt& vSet3)
    {
       vSet3.clear();
       vSet3.insert(vSet3.end(), vSet1.begin(), vSet1.end());
       vSet3.insert(vSet3.end(), vSet2.begin(), vSet2.end());
       for( int i = 0; i < vSet1.size(); i ++)
       {
           for(int j = 0; j < vSet2.size(); j++)
           {
               vInt vt;
               mergeSet(vSet1[i],vSet2[j],vt);
               vSet3.push_back(vt);
           }
       }
    }

    void mergeSet(vInt& vSet1, vInt& vSet2, vInt& vSet3)
    {
        vSet3.clear();
        vSet3.insert(vSet3.end(), vSet1.begin(), vSet1.end());
        vSet3.insert(vSet3.end(), vSet2.begin(), vSet2.end());
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
    int a[]={1,2,2,2,3};

    vector<int> va(a,a+sizeof(a)/sizeof(a[0]));
    //vector<int> vb(b,b+sizeof(b)/sizeof(b[0]));
    Solution s;
    auto r = s.subsetsWithDup(va);

    printT(r);
    //vector<vector<int> > xx = sssss.generateMatrix(1);
    //printVV(xx);
	//printT(sssss.removeDuplicates(va));
}

