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
    vector<string> generateParenthesis(int n) {
		vector<string> result, validResult;
		generateAll(n, result);

		for (size_t i = 0; i < result.size(); i++){
			if (isMatch(result[i])){
				validResult.push_back(result[i]);
			}
		}
		//printT(result);

		return validResult;
    }

	void generateAll(int n, vector<string>& result){
		string str[] = { "((", "()", ")(", "))" };
		vector<string> arr (str, str + 4);

		if (n <= 0) {
			return ;
		}
		else if (n == 1){
			result = arr;
		}
		else if(n > 1) {
			generateAll( n - 1, result);
			vector<string> newResult;
			for (size_t i = 0; i < result.size(); i++){
				for (size_t j = 0; j < 4; j++){
					newResult.push_back( result[i] + arr[j] );
				}
			}
			result = newResult;
		}
	}

	bool isMatch(const std::string& str){
		if (str.empty()){
			return false;
		}

		int counter = 0;
		for (size_t i = 0 ;i <str.size(); i++){
			if( str[i] == '(' ) {
				counter ++ ;
			}
			else if(str[i] == ')'){
				counter -- ;
			}
			else {
				return false;
			}
			if (counter < 0){
				return false;
			}
		}

		return counter == 0;

	}
};


int main(int argc, char** argv)
{
	Solution s;
	vector<string> result = s.generateParenthesis(3);
	printT(result);
}

