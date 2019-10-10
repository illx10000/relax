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
#include <queue>
#include <stack>

template<typename T>
void printT(vector<T>& arr)
{
	cout << "[";
	for (int i = 0; i < (int)arr.size(); i++)
	{
		if (i)
		{
			cout << ",";
		}
		cout << arr[i];
	}
	cout << "]" << endl;
}


void printT(vector< vector<int> >& arr)
{
	for (size_t i = 0; i < arr.size(); i++)
	{
		printT(arr[i]);
	}
}

void printT(vector< vector<string> >& arr)
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
	for (size_t i = 0; i < s.size(); ++i)
	{
		cout << "i:" << i << ",[" << s[i].start << "," << s[i].end << "]" << "\n";
	}
}

template<typename T>
void printT(const T& t)
{
	cout << t;
}


struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


using namespace std;

void printT(TreeNode* root)
{
	if (root)
	{
		
		cout << root->val << " ";
		printT(root->left);
		printT(root->right);
	}
}

void printT(vector<TreeNode*> t)
{
	for_each(t.begin(),t.end(), [](TreeNode* temp){ printT(temp); cout << endl;});
}

class Solution {
public:
    bool isSymmetric(TreeNode* root) 
	{
		if(root == NULL)
		{
			return true;
		}
		
		//return isSymmetricR(root->left, root->right);
		return isSymmetricNR(root->left, root->right);
    }

	bool isSymmetricR(TreeNode* left,TreeNode* right)
	{
		if( (left != NULL && right == NULL) || (left == NULL && right != NULL) )
		{
			return false;
		}
		if(left == right)
		{
			 return true;
		}
		if(left->val != right->val)
		{
			 return false;
		}

		return isSymmetricR(left->left, right->right) && isSymmetricR(left->right, right->left);
	}
	
	bool isSymmetricNR(TreeNode* left,TreeNode* right)
	{
		 queue<TreeNode*> lq,rq;
		 lq.push(left);
		 rq.push(right);

		 while(!lq.empty() && !rq.empty())
		 {
			 TreeNode* t1 = lq.front(); lq.pop();
			 TreeNode* t2 = rq.front(); rq.pop();

			 if(  (t1 == NULL && t2 != NULL) || (t1 != NULL && t2 == NULL) )
			 {
				return false;
			 }
			 if(t1 == t2 && t2 == NULL)
			 {
				continue;
			 }
			 
			 if(t1->val != t2->val)
			 {
				 return false;
			 }

			lq.push(t1->left);  lq.push(t1->right); 
			rq.push(t2->right); rq.push(t2->left);
		 }
		 return true;
	}

};

int main(int argc, char** argv)
{
	int a[] = { 1,2,3,4,5 };
	//int a[] = { 1,2,3,3,4,4,5 };
	vector<int> va(a, a + sizeof(a) / sizeof(a[0]));
	
	TreeNode* root = new TreeNode(12);

	Solution s;

    auto t = s.isSymmetric(root);
	printT(t);

}

