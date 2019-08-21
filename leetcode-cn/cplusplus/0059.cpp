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


class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        
        vector<vector<int> > matrix;
        if (n <= 0) {
            return matrix;
        }
        
        matrix.resize(n);
        for(int i = 0; i < n; i++) matrix[i].resize(n);
        

        int counter = 1;
        
		for(size_t i = 0; i < (n+1) / 2; i++)
        {
            travel(matrix, i , n - i * 2, counter);
        }
        
        return matrix;
    }

    void travel(vector< vector<int>  >& matrix, int start,int len,  int &counter)
    {
        if(len == 0)
        {
            return ;
        }
        if(len == 1)
        {
            matrix[start][start] = counter++;
            return;
        }

        
        for(int j = start;          j < start+len - 1; j++) matrix[start][j]        = counter++;
        for(int i = start;          i < start+len - 1; i++) matrix[i][start+len-1]  = counter++;

        for(int j = start+len-1;    j > start;    j--) matrix[start+len-1][j]       = counter++;
        for(int i = start+len-1;    i > start;    i--) matrix[i][start]             = counter++;

        //travel(matrix, start + 1, len - 2, counter);
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

    vector<vector<int> > xx = sssss.generateMatrix(1);
    printVV(xx);
	//printT(sssss.removeDuplicates(va));
}

