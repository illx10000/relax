#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int myAtoi(string str) 
		{
			 int result = 0;
			 int i = 0;
			 while( i < str.size())
			 {
				 	if(str[i] != ' ')
					{
						 break;
					}
					else
					{
						 i++;
					} 
			 }

			 if(i == str.size())
			 {
				  return result;
			 }

			 if(str[i] != '-' && str[i] != '+' && (str[i] < '0' || str[i] > '9') )
			 {
				 return result;
			 }

			 int base = 1;
			 if( str[i] == '-')
			 {
				 base = -1;
				 i++;
			 }
			 else if(str[i] == '+')
			 {
				 base = 1;
				 i++;
			 }
			 
			 int64_t total = 0;
			 while(i < str.size())
			 {
				  if( str[i] < '0' || str[i] > '9' )
					{
						 break;
					}
					else 
					{
						total = total * 10 + (str[i] - '0');
						int64_t tempResult = total * base;

						if( tempResult < INT32_MIN)
						{
							return INT32_MIN;
						}
						if(tempResult > INT32_MAX)
						{
							return INT32_MAX;
						}
						i++;
					}
			 }
			 return total*base;
    }
};

int main(int argc, char ** argv)
{
	Solution s;
	cout << s.myAtoi("+1") << endl;
}