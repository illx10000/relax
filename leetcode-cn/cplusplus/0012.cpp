#include <vector>
#include <string>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    Solution()
		{
			  const int N = 13;
				const static string ROMAN[N]  = {"M",  "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV" , "I" };
				const static int VALUE[N] 		= { 1000, 900, 500, 400, 100,  90,   50,  40,   10,  9,     5,  4,     1};
				for(int i = 0; i < N; i++)
				{
					 m_value[ROMAN[i]] = VALUE[i];
				}
		}
    int romanToInt(string s) 
		{    
			  int i = 0, counter = 0;
				while( i < s.size() )
				{
					  string temp;
						temp += s[i];
						if(i < s.size() - 1 )
						{
							 string temp2 = temp + s[i+1];
							 if(m_value.find(temp2) != m_value.end())
							 {
								 	counter += m_value[temp2];
									 i += 2;
							 }
							 else 
							 {
								  counter += m_value[temp];
									i += 1;
							 }
						}
						else 
						{
							 counter += m_value[temp];
							i += 1;
						}
				}
				return counter;
    }
private:
	  map<string,int> m_value;
};



int main(int argc, char ** argv)
{
	Solution s;
	
	cout << s.romanToInt("MCMXCIV") << endl;
}