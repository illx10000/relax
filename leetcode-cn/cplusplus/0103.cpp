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
		TreeNode* _node;
		int _level;
		levelNode(TreeNode* node, int level):_node(node),_level(level){};
	};
	
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
	{
		vector< vector<int> > result;
		if(NULL == root)
		{
			 return result;
		}
		
		queue<levelNode> st;
		vector<int> tempRow;
		int lastlevel = 1;
		st.push(levelNode(root,1));

		while (!st.empty())
		{
			levelNode tempNode = st.front(); st.pop();
			if(tempNode._node == NULL)
			{
				continue;
			}

			if(lastlevel == tempNode._level)
			{
				tempRow.push_back(tempNode._node->val);
			}
			else 
			{
				result.push_back(tempRow);
				tempRow.clear();
				tempRow.push_back(tempNode._node->val);
				lastlevel = tempNode._level;
			}

			st.push(levelNode(tempNode._node->left, tempNode._level+1));
			st.push(levelNode(tempNode._node->right,tempNode._level+1));
		}
		result.push_back(tempRow);
		
		for(int i = 1; i < result.size(); i+=2)
		{
			std::reverse(result[i].begin(),result[i].end());
		}
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

    auto t = s.zigzagLevelOrder(root);
	printT(t);

}

