#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>

using namespace std;
template<typename T>
void printT(const T& t, const std::string& sep = "")
{
	cout << t << sep;
}

template<typename T>
void printT(const vector<T>& vec)
{
	 for_each(vec.begin(), vec.end(), [](const T& t){ printT(t, " "); });
	 cout << endl;
}


class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
    }
};

int main(int argc, char ** argv)
{
	/*
	Solution s;

	auto temp = s.strStr("hello","ll");
	printT(temp);
	*/
	Solution s;

	vector<string> vs;

  printT(s.findSubstring("",vs));
	return 0;
}