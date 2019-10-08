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
    vector<int> inorderTraversal(TreeNode* root) 
	{
		vector<int> result;
		inorderTraversal_NR_2(result, root);
		return result;
    }
	void inorderTraversal_R(vector<int>& result, TreeNode* root)
	{
		 if(root != NULL)
		 {
			  if(root->left != NULL)
			  {
				inorderTraversal_R(result, root->left);
			  }
			  
			  result.push_back( root->val);

			  if(root->right != NULL)
			  {
				   inorderTraversal_R(result, root->right);
			  }
		 }
	}
	void inorderTraversal_NR(vector<int>& result, TreeNode* root)
	{
		if(root != NULL)
		{
			stack<TreeNode*> st;
			TreeNode* current = root;

			while(current != NULL || !st.empty())
			{
				while(current != NULL)
				{
					st.push(current);
					current = current->left;
				}

				TreeNode* temp = st.top();
				st.pop();
				result.push_back(temp->val);
				current = temp->right;
			}
		}
	}

	struct Node4Travel
	{
		TreeNode* _node;
		int 	  _is_visited; //是否遍历过
		Node4Travel(TreeNode* node, int c):_node(node),_is_visited(c){};
	};
	
	void inorderTraversal_NR_2(vector<int>& result, TreeNode* root)
	{
		stack<Node4Travel> st;
		st.push(Node4Travel(root,0));
		while(!st.empty())
		{
			Node4Travel temp = st.top();
			st.pop();

			if(temp._node == NULL)
			{
				continue;
			} 
			if(0 == temp._is_visited) //没有使用过
			{
				st.push(Node4Travel(temp._node->right, 0));
				st.push(Node4Travel(temp._node, 1));
				st.push(Node4Travel(temp._node->left, 0 ));
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
	
	TreeNode* root = new TreeNode(12);

	Solution s;

    auto t = s.inorderTraversal(root);
	printT(t);

}

