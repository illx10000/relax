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

class Solution {
public:

	//深度优先搜索

	struct XXValue
	{
		int value;
		int num;
		XXValue():value(0),num(0){};
		XXValue(int v,int n):value(v), num(n){};
		//vector<int> toVec() { return vector<int>(num,value);}
		int			sum()	{ return value*num;}
		
		static vector<int> toVec( const vector<XXValue>& other)
		{
			vector<int> result;

			for( int i = 0; i < other.size(); i++)
			{
				for(int j = 0; j < other[i].num; j++)
				{
					result.push_back(other[i].value);
				}
			}
			return result;
		}
	};

	void dfs(vector<int>& v,
			int startIndex,
			int targetSum,
			vector<XXValue>& path,
			vector<vector<int> >& vResult,
			set<string>& s
			)
	{
		if (targetSum == 0)
		{
			string str;
			for(int i = 0 ; (int)i < path.size(); i++)
			{
				if(path[i].num != 0)
				{
					str += (char)path[i].num	+ '0';	
					str += (char)path[i].value	+ '0';	
					str += ",";
				}
			}
			if(s.find(str) == s.end())
			{
				s.insert(str);
				vResult.push_back( XXValue::toVec(path));
			}
		}

		if ( startIndex == v.size() || targetSum < 0) return;
		
		int MAX_USE_N = targetSum / v[startIndex];
		for (int i = 0; i <= (int)MAX_USE_N; i++)
		{
			if(targetSum >= v[startIndex]* i)
			{
				path.push_back( XXValue(v[startIndex],i));
				dfs(v, startIndex + 1, (targetSum - v[startIndex]* i), path, vResult,s);
				path.pop_back();
			}
			else 
			{
				break;
			}
		}
	}

    vector<vector<int>> combinationSum(vector<int>& v, int target) {
		vector<vector<int>> vRRr;
		if (v.empty())
		{
			return vRRr;
		}
		set<string> s;

		std::sort(v.begin(),v.end());
		
		vector<XXValue> vPath;
		dfs(v,0,target,vPath,vRRr,s);

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
    int a[]={2,3,6,7};
    //int b[]={2,3,4};

    vector<int> va(a,a+sizeof(a)/sizeof(a[0]));
    //vector<int> vb(b,b+sizeof(b)/sizeof(b[0]));

    vector<vector<int> > vvResult;
    Solution sssss;
	//cout << (
	
	printT (sssss.combinationSum(va,7));;
		//) << endl;
	//printVector(va);

	//printT(sssss.removeDuplicates(va));
}

