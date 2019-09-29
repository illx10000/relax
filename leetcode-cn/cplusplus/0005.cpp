#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
		int getMinAndMax(const std::string& s,int& start, int& end)
		{
			while(start >= 0 && end < s.size())
			{
				if(s[start] == s[end])
				{
					start--;
					end++;
				}
				else 
				{
					return (end-start-1);
				}
			}
			return end-start-1;
		}

    string longestPalindrome(string s) {
				if(s.empty())
				{
					return s;
				}

        int minIndex = -1, maxIndex = -1, maxLength = INT32_MIN;
				int beginIndex = 0, endIndex = 0;

				std::string result;

				for(int i = 0; i < s.size(); i++)
				{
						minIndex = i, maxIndex = i+1;
						int len = getMinAndMax(s,minIndex,maxIndex);
						if(len > maxLength)
						{
							maxLength = len;
							beginIndex = minIndex;
							endIndex = maxIndex;
						}

						//cout << "begin:" << beginIndex << ",endIndex:" << endIndex << ",length:" << len << endl;
						minIndex = i-1, maxIndex = i+1;

						len = getMinAndMax(s,minIndex,maxIndex);
						if(len > maxLength)
						{
							maxLength = len;
							beginIndex = minIndex;
							endIndex = maxIndex;
						}

						//cout << "begin:" << beginIndex << ",endIndex:" << endIndex << ",length:" << len << endl;
				}
				if(maxLength == 0)
				{
					return string(1,s[0]);
				}
				else 
				{
					return s.substr(beginIndex+1, maxLength);
				}
    }
};

int main(int argc, char ** argv)
{
	string str = "bbad";
	Solution s;
	cout << s.longestPalindrome(str) << endl;
}