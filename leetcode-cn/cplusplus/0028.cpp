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

/*
class Solution {
public:
		void kmpNext(vector<int>& next, const std::string& pattern)
		{
			next.resize(pattern.size());
			next[0] = -1;
			int j = -1 , i = 0;
			while (i < (int)pattern.size() - 1 )
			{
				if(j == -1)
				{
					 i++;
					 j++;
					 next[i] = j;
				}
				else if(pattern[i] == pattern[j])
				{
					 i++;
					 j++;
					 next[i] = j;
				}
				else 
				{
					 j = next[j];
				}
			}
		}

		int kmpSearch(const std::string&  text, const string& pattern)
		{
			 vector<int> next;
			 kmpNext(next,pattern);
			 int i = 0 , j = 0;

			 while( i < (int)text.size() && j < (int)pattern.size())
			 {
				  if(j == -1 )
					{
						 i++;
						 j++;
					}
					else if(text[i] == pattern[j])
					{
						 i++;
						 j++;
					}
					else 
					{
						 j = next[j];
					}
			 }
			 if(j == (int)pattern.size())
			 {
				  return i-j;
			 }
			 else 
			 {
				  return -1;
			 }
		}


    int strStr(string haystack, string needle) 
		{
			if(needle.empty())
			{
				 return 0;
			}
			if(haystack.empty())
			{
				 return -1;
			}

			return kmpSearch(haystack,needle);
    }

		
};

*/

int kmpNext(vector<int>& next,const std::string& pattern)
{
	 int len = pattern.size();

	 next.resize(len);
	 next[0] = -1;
	 int i = 0, j = -1;
	 
	 while( i < len-1 )
	 {
		  if(j == -1 || pattern[i] == pattern[j])
			{
				 i++;
				 j++;
				 if(pattern[i] != pattern[j])
				 {
					  next[i] = j;
				 }
				 else 
				 {
					 	next[i] = next[j];
				 }
				 
			}
			else 
			{
				 j = next[j];
			}
	 }
}

int kmpSearch(const std::string& text, const std::string& pattern)
{
	 if(pattern.empty()) 
	 {
		 return 0;
	 }
	 if(text.empty())
	 {
		  return -1;			
	 }
	 vector<int> next;
	 kmpNext(next,pattern);
	 printT(next);

	 int i = 0, j = 0;
	 
   while(i < (int)text.size() && j < (int)pattern.size())
	 {
		  if(j == -1 || text[i] == pattern[j])
			{
				 i++;
				 j++;
			}
			else 
			{
				 j = next[j];
			}
	 }
	 if(j == (int)pattern.size())
	 {
		  return i - j;
	 }
	 return -1;
}


int main(int argc, char ** argv)
{
	/*
	Solution s;

	auto temp = s.strStr("hello","ll");
	printT(temp);
	*/
   cout << kmpSearch("hello","ll") << endl;
	 return 0;
}