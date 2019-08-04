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
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > result;
        if(numRows <= 0)
        {
            return result;
        }

        if(numRows == 1)
        {
            vector<int> v; v.push_back(1);
            result.push_back(v);
            return result;
        }

        else if(numRows >= 2)
        {
            vector<int> v; 
            v.push_back(1);
            result.push_back(v);
            v.push_back(1);
            result.push_back(v);
            if(numRows == 2)
            {
                return result;
            }
        }

        for (size_t i = 0; i < numRows - 2; i++)
        {
            vector<int> v;
            v.resize(i+3); 
            v[0] = v[v.size()-1] = 1;

            vector<int> &vLast = result[result.size()-1];

            for(int j = 1; j < v.size() - 1; j++)
            {
                v[j] = vLast[j-1] + vLast[j];
            }
            result.push_back(v);
        }
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
    //int a[]={2,1,2};
    //int a[]={2,1,5,6,100000,3};
    int a[]={9,3,15,20,7};
    int b[]={9,15,7,20,3};
    

    vector<int> va(a,a+sizeof(a)/sizeof(a[0]));
    vector<int> vb(b,b+sizeof(b)/sizeof(b[0]));

    Solution s;

    auto r = s.generate(5);

    printT(r);
    //vector<vector<int> > xx = sssss.generateMatrix(1);
    //printVV(xx);
	//printT(sssss.removeDuplicates(va));
}

