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
void printT(vector<T>& arr)
{
	cout << "[\n";
	for (int i = 0; i < (int)arr.size(); i++)
	{
		if (i)
		{
			cout << "\n";
		}
		cout << arr[i];
	}
	cout << "\n]" << endl;
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

class Solution {
public:
    int divide(int dividend, int divisor) {
		int shift_time = 0;
		int cur_sor = divisor;
		while( cur_sor )
    }

};

int main(int argc, char** argv)
{
	Solution s;
	vector<string> result = s.generateParenthesis(3);
	printT(result);
}

