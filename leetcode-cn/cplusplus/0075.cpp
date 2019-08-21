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

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int counter[3] = { 0 };
        for (size_t i = 0; i < nums.size(); i++)
        {
            counter[nums[i]]++;
        }

        int base = 0;
        for (size_t i = 0; i < 3; i++)
        {
            for (size_t j = 0; i < counter[i]; i++)
            {
                nums[base + j] = i;
            }
            base += counter[i];
            
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
    int a[]={};
    //int b[]={2,3,4}1


    vector<int> va(a,a+sizeof(a)/sizeof(a[0]));
    //vector<int> vb(b,b+sizeof(b)/sizeof(b[0]));

    vector<vector<int> > vvResult;


    Solution sssss;


	vector< vector<int> > ss ;
    const int N = 4;
/*
    for(int i = 0; i < N; i++)
    {
        vector<int> vvvv;
        for(int j = 0; j < N + 2; j++)
        {
            vvvv.push_back( i * (N + 2) + j  + 1);
        }
        ss.push_back(vvvv);
    }
    */
    //printT(ss);
    //cout << endl;

	//vector<int> vb = sssss.spiralOrder(ss);
	//cout << sssss.canJump(va) << endl;
	//printVector(vb);
    vector<Interval> v;
    v.push_back(Interval(1,3));
    //v.push_back(Interval(0,5));
    //v.push_back(Interval(9,12));
    v.push_back(Interval(6,9));
    //v.push_back(Interval(6,9));
    //v.push_back(Interval(10,11));

    //printVInterval(sssss.insert(v,Interval(2,5)));

    

    vector<int> vR =  sssss.plusOne(va);
    printVector(vR);
    //vector<vector<int> > xx = sssss.generateMatrix(1);
    //printVV(xx);
	//printT(sssss.removeDuplicates(va));
}

