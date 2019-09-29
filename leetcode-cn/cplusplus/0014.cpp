#include <vector>
#include <string>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
		{
			 if(strs.empty())
			 { 
				  return "";
			 }
			 int j , i = 0;
			 string prefix = "";
			 
			 char tempCh ;
			 do
			 {
				 for(j = 0; j < strs.size(); j++)
			 	 {
						if(strs[j].size() <= i)
						{
						 	return prefix;
						}   
          	if(j == 0)
						{
							tempCh = strs[j][i];
						}
						else 
						{
						  if(strs[j][i] != tempCh)
							{
								 return prefix;
							}
						}
			 		}
					i++;
					prefix += tempCh;
			 } while (true);

			 return prefix;
    }
};




int main(int argc, char ** argv)
{
	Solution s;

	vector<string> strs  = {};

	cout << s.longestCommonPrefix(strs) << endl;
}