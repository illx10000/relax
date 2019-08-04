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
    /* 
     * the first element of preorder is root of binary tree
    */
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        if(preorder.empty() || inorder.empty() || preorder.size() != inorder.size())
        {
            return NULL;
        }
        
        return buildTree(
            preorder, 0, preorder.size() ,
            inorder, 0,  inorder.size() 
        );
    }

    TreeNode* buildTree(
        vector<int>& preorder, int preBegin, int preSize,
        vector<int>& inorder, int inBegin,int inSize
    )
    {
        if ( preSize <=0 || inSize <= 0 || preSize != inSize )
        {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[preBegin]);
        if(preSize == 1) // only one element
        {
            return root;
        }
        else 
        {
            int counter = 0;
            while ( counter < inSize && 
                    inorder[inBegin + counter] != preorder[preBegin] )
            {
                counter++;
            }
            

            root->left = buildTree(
                    preorder, preBegin + 1, counter,
                    inorder, inBegin ,  counter
                    ) ;

            root->right = buildTree(
                    preorder, preBegin + counter + 1 , preSize - counter -1 ,
                    inorder, inBegin  + counter + 1, inSize - counter - 1
                    );

        }

        return root;
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
    int a[]={3,9,20,15,7};
    int b[]={9,3,15,20,7};
    

    vector<int> va(a,a+sizeof(a)/sizeof(a[0]));
    vector<int> vb(b,b+sizeof(b)/sizeof(b[0]));

    Solution s;

    auto r = s.buildTree(va,vb);

    printT(r);
    //vector<vector<int> > xx = sssss.generateMatrix(1);
    //printVV(xx);
	//printT(sssss.removeDuplicates(va));
}

