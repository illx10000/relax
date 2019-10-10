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

    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        vector< vector<int> > result;
        if(root == NULL)
        {
            return result;
        }
        travel(root,0,result);

        std::reverse(result.begin(),result.end());

        return result;
    }

    void travel(TreeNode* root, int level,vector< vector<int> > & result)
    {
        if(root != NULL)
        {
            if(result.size() <= level)
            {
                result.push_back(vector<int>());
            }
            
            result[level].push_back(root->val);
            
            travel(root->left,  level+1 ,result);
            travel(root->right, level+1, result);
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
    //int a[]={2,1,2};
    //int a[]={2,1,5,6,100000,3};
    int a[]={9,3,15,20,7};
    int b[]={9,15,7,20,3};
    

    vector<int> va(a,a+sizeof(a)/sizeof(a[0]));
    vector<int> vb(b,b+sizeof(b)/sizeof(b[0]));

    Solution s;
    TreeNode * root = new TreeNode(12);

    auto r = s.levelOrderBottom(root);

    printT(r);
    //vector<vector<int> > xx = sssss.generateMatrix(1);
    //printVV(xx);
	//printT(sssss.removeDuplicates(va));
}

