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

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval)  {
        vector<Interval> result;
        if(intervals.empty())
        {
            result.push_back(newInterval);
            return result;
        }

        //std::sort(intervals.begin(), intervals.end(), [](const Interval& l, const Interval& r){return l.start < r.start;});

        if(intervals[0].start > newInterval.end) //比当前区间都小
        {
            result.resize(intervals.size() + 1);
            result[0] = newInterval;
            std::copy(intervals.begin(),intervals.end(),result.begin() + 1);
            return result;
        }

        else if(intervals[0].start == newInterval.end) //可以合并到第一个区间
        {
            result.swap(intervals);
            result[0].start = newInterval.start;
            return result;
        }

        if(intervals[intervals.size()-1].end < newInterval.start) //比所有区间都大
        {
            result.swap(intervals);
            result.push_back(newInterval);
            return result;
        }

        else if(intervals[intervals.size()-1].end == newInterval.start)
        {
            result.swap(intervals);
            result[result.size()-1].end = newInterval.end;
            return result;
        }

        if(intervals[0].start > newInterval.start && intervals[intervals.size()-1].end < newInterval.end)
        {
            result.push_back(newInterval);
            return result;
        }

        int low = -1, high = -1, lresult = -1, hresult = -1;
        for(size_t i = 0; i < intervals.size(); i++)
        {
            if( intervals[i].start  <=  newInterval.start && 
                intervals[i].end    >=  newInterval.start)
            {
                low = i;
            }
            if( intervals[i].start  <=  newInterval.end && 
                intervals[i].end    >= newInterval.end)
            {
                high = i;
            }
        }

        if(low != -1 && high != -1)
        {
            for(size_t i = 0 ; i < low; i++)
            { 
                result.push_back(intervals[i]);
            }

            result.push_back(Interval(intervals[low].start,intervals[high].end));

            for(size_t i = high + 1 ; i < intervals.size(); i++)
            { 
                result.push_back(intervals[i]);
            }
        }
        else
        {
            result.swap(intervals);
            if(low != -1) result[low].end = newInterval.end; 
            if(high!= -1) result[high].start = newInterval.start;
        }
        
        //cout << low << "," << high << endl;

        

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
	//cout << sssss.canJump(va) << endl;
	//printVector(vb);
    vector<Interval> v;
    //v.push_back(Interval(-1,0));
    v.push_back(Interval(1,5));
    //v.push_back(Interval(6,9));
    //v.push_back(Interval(10,11));

    printVInterval(sssss.insert(v,Interval(0,6)));

	//printT(sssss.removeDuplicates(va));
}

