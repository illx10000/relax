#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstdint>
#include <set>
using namespace std;

#include <set>
using std::set;

class Solution {
public:

    //从vA中取出两个数，从vB中取出一个数使得数值和为0
    void threeSum(vector<vector<int> >& result,
        const vector<int64_t> & vA,
        const vector<int64_t> & vB
        )
    {
        set< pair<int,int> > s;

        for (int i = 0; i < (int)vA.size()-1; i++)
        {
            for (int j = i+1; j < (int)vA.size(); j++)
            {
                pair<int,int> p = std::make_pair((int)vA[i],(int)vA[j]);
                if (s.find(p) != s.end())
                {
                    continue;
                }

                int64_t curSum = 0 - (vA[i] + vA[j]);
                //if (curSum > vB[vB.size()-1] ) break;

                if (binary_search( vB.begin(), vB.end(), curSum ))
                {
                    vector<int> v; 
                    v.push_back((int)vA[i]);
                    v.push_back((int)vA[j]);
                    v.push_back((int)curSum);
                    s.insert(p);
                    result.push_back(v);
                }         
            }
        }
        result;
    }

 
    vector< vector<int> > threeSum(vector<int>& nums) {
        //思路，先分为两个组，一个小于0,一个不小于0，然后在
        vector<int64_t> vLessThanZero, vNotLessThanZero;
        for (int i = 0; i < (int)nums.size(); i++)
        {
            if(nums[i]<0) vLessThanZero.push_back(nums[i]);
            else vNotLessThanZero.push_back(nums[i]);
        }
        vector<vector<int> > vvResult;
        if (vNotLessThanZero.empty())  return vvResult;
        if (vLessThanZero.empty())
        {
            if (vNotLessThanZero.size() < 3)
            {
                return vvResult;
            }
            else 
            {
                sort(vNotLessThanZero.begin(),  vNotLessThanZero.end());
                if( vNotLessThanZero[0] + vNotLessThanZero[1] + vNotLessThanZero[2] == 0 )
                {
                    vector<int> v; 
                    v.push_back(0);
                    v.push_back(0);
                    v.push_back(0);
                    vvResult.push_back(v);
                }
                return vvResult;
            }
        }
        sort(vLessThanZero.begin(),     vLessThanZero.end());
        sort(vNotLessThanZero.begin(),  vNotLessThanZero.end());
        if (vNotLessThanZero.size()>=3)
        {
            if( vNotLessThanZero[0] + vNotLessThanZero[1] + vNotLessThanZero[2] == 0 )
            {
                vector<int> v; 
                v.push_back(0);
                v.push_back(0);
                v.push_back(0);
                vvResult.push_back(v);
            }
        }
        threeSum(vvResult,vLessThanZero,vNotLessThanZero);
        threeSum(vvResult,vNotLessThanZero,vLessThanZero);
        return vvResult;
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
    int a[]={-4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0};
    //int b[]={2,3,4};

    vector<int> va(a,a+sizeof(a)/sizeof(a[0]));
    //vector<int> vb(b,b+sizeof(b)/sizeof(b[0]));

    vector<vector<int> > vvResult;
    Solution sssss;
    printT(sssss.threeSum(va));
}

