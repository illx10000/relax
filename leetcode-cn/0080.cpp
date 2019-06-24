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

//应用于dfs
class Solution {
public:

    typedef pair<int,int> Pos;

   
    set< Pos > visited; //访问过的位置

    bool dfs(vector<vector<char>>& board, Pos p, string word, int curIndex)
    {
        if( curIndex == (int)word.size())   return true;
        if(p.first < 0 || p.first >= board.size() ||  p.second < 0 || p.second >= board[0].size())   return false;
        if(visited.find(p) != visited.end() ) return false;
        if(word[curIndex] != board[p.first][p.second]) return false; 

        visited.insert(p); //避免重复利用该位置
        
        if(dfs(board,Pos(p.first+1,p.second),word,curIndex+1)) return true;   
        if(dfs(board,Pos(p.first-1,p.second),word,curIndex+1)) return true;
        if(dfs(board,Pos(p.first,p.second+1),word,curIndex+1)) return true;
        if(dfs(board,Pos(p.first,p.second-1),word,curIndex+1)) return true;
        
        visited.erase(p);

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty() || board[0].empty() || word.empty())
        {
            return false;
        }
        
        int rows = (int)board.size();
        int cols = (int)board[0].size();

        for (size_t i = 0; i < rows; i++)
        {
            for(int j = 0 ; j < cols; j++)
            {
                visited.clear();
                if(dfs(board,Pos(i,j),word,0))
                {
                    return true;
                }
            }
        }
        return false;
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

