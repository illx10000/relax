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


struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#include <map>
#include <utility>
#include <algorithm>
#include <stack>
using namespace std;

void printT(TreeNode* root)
{
    if(root)
    {
        printT(root->left);
        cout << root->val << endl;
        printT(root->right);
    }

}


class Solution {
public:
    int minimumTotal(vector< vector<int > >& triangle) 
    {
        vector<int> minPath;
        
        for (size_t i = 0; i < triangle.size() ; i++)
        {
            vector<int> curPath; 
            curPath.resize(triangle[i].size());

            for (size_t j = 0; j < triangle[i].size(); j++)
            {
                curPath[j] = triangle[i][j] ;
                if(i != 0)
                {
                    if(j == 0) curPath[j] += minPath[j];
                    else if(j == curPath.size()-1) curPath[j] += minPath[j-1];
                    else curPath[j] += std::min(minPath[j],minPath[j-1]) ;
                }
                
            }

            minPath.swap(curPath);

            //printT(minPath);
            //cout << endl << endl;
        }
        return *std::min_element( minPath.begin(), minPath.end() );
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
    int a[]={9,3,15,20,7};
    int b[]={9,15,7,20,3};
    

    vector<int> va(a,a+sizeof(a)/sizeof(a[0]));
    vector<int> vb(b,b+sizeof(b)/sizeof(b[0]));

    Solution s;

    vector<vector<int> > v = {
        {2},
        {3,4},
        {6,5,7},
        {4,1,8,3}
    };

    auto r = s.minimumTotal(v);

    printT(r);
    //vector<vector<int> > xx = sssss.generateMatrix(1);
    //printVV(xx);
	//printT(sssss.removeDuplicates(va));
}

