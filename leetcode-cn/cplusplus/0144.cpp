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
		printT(root->left);
		cout << root->val << endl;
		printT(root->right);
	}

}

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) 
		{
        vector<int> result;
				preorderTraversal_NR(result, root);
				return result;
    }

		struct node
		{
			 TreeNode* _node;
			 int 			 _visited; //是否访问过0,1;
			 node(TreeNode* node, int v):_node(node),_visited(v){};
		};

		void preorderTraversal_NR(vector<int>& result, TreeNode* root)
		{
			 stack<node> st;
			 st.push(node(root,0));
			 while(!st.empty())
			 {
				  node temp = st.top();
					st.pop();


					if(temp._node == NULL)
					{
						 continue;
					}
					//cout << temp._node->val << "," << temp._visited << endl;
					

					if(temp._visited == 0)
					{
						st.push(node(temp._node->right, 0));
						st.push(node(temp._node->left, 	0));
						st.push(node(temp._node, 				1));
					}
					else 
					{
						 result.push_back(temp._node->val);
					}
			 }
		}
};


int main(int argc, char** argv)
{
	int a[] = { 1,2,3,4,5 };
	//int a[] = { 1,2,3,3,4,4,5 };
	vector<int> va(a, a + sizeof(a) / sizeof(a[0]));
	
	TreeNode* root = new TreeNode(1);
	root->right = new TreeNode(2);
	root->right->left = new TreeNode(3);

	Solution s;

    auto t = s.preorderTraversal(root);
	printT(t);

}

