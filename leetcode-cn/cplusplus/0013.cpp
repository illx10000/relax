#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
		
    string intToRoman(int num) 
		{
			  const int N = 13;

			  const static string ROMAN[N]  = {"M",  "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV" , "I" };
				const static int VALUE[N] 		= { 1000, 900, 500, 400, 100,  90,   50,  40,   10,  9,     5,  4,     1};

        string result = "";

				while(num > 0)
				{
					 for(int i = 0; i < N; i++)
					 {
						  if(num >= VALUE[i])
							{
								 result += ROMAN[i];
								 num -= VALUE[i];
								 break;
							}
					 }
				}
				return result;
    }
};

int main(int argc, char ** argv)
{
	Solution s;
	cout << s.intToRoman(3) << endl;
}