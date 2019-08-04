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
    int maximalRectangle(vector<int> & heights){
        stack<int> s;
        int maxArea = 0;
        heights.push_back(0);

        for(int i = 0; i < heights.size(); i++)
        {
            while( !s.empty() && heights[s.top()] >= heights[i] )
            {
                int height = heights[s.top()];
                s.pop();
                int startPos = (s.empty() ? -1 : s.top()) + 1;
                int width = i - startPos;
                int area = height * width;
                if(area > maxArea)
                {
                    maxArea = area;
                }  
            }
            s.push(i);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char> >& matrix) {
        if (matrix.empty() || matrix[0].empty())
        {
            return 0;
        }
        
        int maxarea = 0;
        vector<int> height(matrix[0].size());

        for (size_t i = 0; i < matrix.size(); i++)
        {
            for (size_t j = 0; j < matrix[0].size(); j++)
            {
                height[j] = ((matrix[i][j] == '1') ? height[j]+1 : 0); 
            }
            int area = maximalRectangle(height);
            if ( area > maxarea )
            {
                maxarea = area;
            }
            
        }
        return maxarea;
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

    vector<vector<char> > vChar;
    auto r = s.maximalRectangle(va);
    printT(r);
    //vector<vector<int> > xx = sssss.generateMatrix(1);
    //printVV(xx);
	//printT(sssss.removeDuplicates(va));
}

