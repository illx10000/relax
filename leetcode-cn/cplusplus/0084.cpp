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

class Solution {
public:

    int largestRectangleArea(vector<int>& heights) //[2,1,5,6,2,3]
    {
        heights.push_back(0);

        stack<int> stackIndex;
        int maxArea = 0;
        for (size_t i = 0; i < heights.size(); i++)
        { 
            //弹出的元素，说明以他的高度为高的矩形无法向右再扩充面积了
            while (!stackIndex.empty() && heights[stackIndex.top()] >= heights[i]) 
            {
                int height = heights[stackIndex.top()]; //当前矩形的高度
                stackIndex.pop();

                int startPos = (stackIndex.empty() ? -1 :  stackIndex.top() ) + 1; //startPos是第一个位置比heiigth高的位置

                int width  =  i - startPos;

                int area = height * width;

                if( area > maxArea )
                {
                    maxArea = area;
                }
            }
            stackIndex.push(i); //stackIndex内的每一元素单调增加 
        }
        return maxArea;
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
    int a[]={2,1,5,6,2,3};

    vector<int> va(a,a+sizeof(a)/sizeof(a[0]));
    //vector<int> vb(b,b+sizeof(b)/sizeof(b[0]));
    Solution s;

    auto r = s.largestRectangleArea(va);
    printT(r);
    //vector<vector<int> > xx = sssss.generateMatrix(1);
    //printVV(xx);
	//printT(sssss.removeDuplicates(va));
}

