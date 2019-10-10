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
	struct levelNode
	{
		int _level;
		TreeNode* _node;
		levelNode(int level, TreeNode* node):_level(level),_node(node){};
	};
	
    vector<vector<int> > levelOrder(TreeNode* root) 
	{
		vector<vector<int> > result;
		if(root == NULL)
		{
			 return result;
		}

		int lastLevel = 1;
		vector<int> curRow;

		queue<levelNode> q;
		q.push(levelNode(1,root));
		

		while(!q.empty())
		{
			levelNode temp = q.front(); q.pop();
			if(temp._node == NULL)
			{
				continue;
			}
			if( lastLevel == temp._level )
			{
				curRow.push_back( temp._node->val );
			}
			else 
			{
				lastLevel = temp._level;
				result.push_back(curRow);
				curRow.clear();
				curRow.push_back(temp._node->val);
			}
			q.push( levelNode(temp._level+1, temp._node->left) );
			q.push( levelNode(temp._level+1, temp._node->right) );
		}
		result.push_back(curRow);

		return result;
    }
};

int main(int argc, char** argv)
{
	int a[] = { 1,2,3,4,5 };
	//int a[] = { 1,2,3,3,4,4,5 };
	vector<int> va(a, a + sizeof(a) / sizeof(a[0]));
	
	TreeNode* root = new TreeNode(12);

	Solution s;

    auto t = s.levelOrder(root);
	printT(t);

}

