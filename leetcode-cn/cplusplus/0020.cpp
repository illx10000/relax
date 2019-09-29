#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:

		bool isMatch(char left, char right)
		{
			 if(left == '(' && right == ')')
			 {
				  return true;
			 }
			 if(left == '{' && right == '}')
			 {
				  return true;
			 }
			 if(left == '[' && right == ']')
			 {
				  return true;
			 }
			 return false;
		}
    bool isValid(string s) 
		{
			 if(s.empty())
			 {
				  return true;
			 }

			 stack<char> st;
			 st.push(s[0]);

			 for(int i = 1; i < s.size(); i++)
			 {
				  if(st.empty()) 
					{
						 st.push(s[i]);
					}
					else 
					{
						 char topCh = st.top();
						 if(isMatch(topCh, s[i]))
						 {
							  st.pop();
						 }
						 else
						 {
							 st.push(s[i]);
						 }
					}
			 }
			 return st.empty();
    }
};


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


int main(int argc, char ** argv)
{
	Solution s;

	auto temp = s.isValid("([)]");
	printT(temp);
}