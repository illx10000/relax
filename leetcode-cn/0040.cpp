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
using std::set;
using std::stringstream;

//https://www.cnblogs.com/ECJTUACM-873284962/p/6935506.html
//参考基数排序

class Solution {
public:

	//深度优先搜索
	void dfs(vector<int>& v,
			int startIndex,
			int targetSum,
			string& path,

			vector<vector<int> >& vResult,
			set<string>& s
			)
	{
		if (targetSum == 0)
		{
			if(s.find(path) == s.end())
			{
				s.insert(path);
				vector<int> cc;
				for(int i = 0 ;i<path.size();++i)
				{
					cc.push_back( path[i] - '0');
				}
				vResult.push_back(cc);
			}
		}

		if ( startIndex == v.size() || targetSum < 0) return;
		
		//int MAX_USE_N = targetSum / v[startIndex];
		for (int i = 0; i <= 1; i++)
		{
			if(targetSum >= v[startIndex]* i)
			{
				if(i!=0) path += ( v[startIndex] + '0');
				dfs(v, startIndex + 1, (targetSum - v[startIndex]* i), path, vResult,s);
				if(i!=0) path.pop_back();
			}
			else 
			{
				break;
			}
		}
	}

    vector<vector<int>> combinationSum2(vector<int>& v, int target) {
		vector<vector<int>> vRRr;
		if (v.empty())
		{
			return vRRr;
		}
		set<string> s;
		
		std::sort(v.begin(),v.end());

		string strPath;

		dfs(v,0,target,strPath,vRRr,s);

		return vRRr;
    }
};

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
}

int main(int argc,char** argv)
{

    /*Solution a;

    string s = "busvutpwmu";
    cout << a.lengthOfLongestSubstring(s) << endl;*/

    //int a[]={1,8,6,2,5,4,8,3,7};
    //int a[]={-1, 0, 1, 2, -1, -4};
    int a[]={10,1,2,7,6,1,5};
    //int b[]={2,3,4};

    vector<int> va(a,a+sizeof(a)/sizeof(a[0]));
    //vector<int> vb(b,b+sizeof(b)/sizeof(b[0]));

    vector<vector<int> > vvResult;
    Solution sssss;
	//cout << (
	
	printT( sssss.combinationSum2(va,8) ) ;//<< endl;
		//) << endl;
	//printVector(va);

	//printT(sssss.removeDuplicates(va));
}

