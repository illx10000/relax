#include <vector>
#include <string>
#include <iostream>
#include <cstdint>
#include <cmath>

using namespace std;

class Solution {
public:
    int reverse(int x) {
		unsigned int result = 0;
		unsigned int positive_x = std::abs(x);

		int is_positive = (x >= 0) ? 1 : -1;
		
		while( positive_x != 0 ){
			// INT_MIN <= (is_positive * result) * 10 + (positive_x % 10) * is_positive  <= INT_MAX  
			// 满足这个等式即可

			if(is_positive) // 如果x是正数，result * 10 + positive_x % 10 > INT_MAX 就会溢出
			{  
				if( (INT_MAX - positive_x % 10) / 10 < result )
				{
					return 0;
				}
			}
			else // 如果x是负数，result * 10 * -1 + positive_x % 10 * -1 < INT_MIN 就会溢出
			{
				if( (INT_MIN + positive_x % 10) / (-10) > result )
				{
					return 0;
				}
			}
			result = result * 10 + positive_x % 10;
			positive_x = positive_x / 10;

			//cout << result  << endl;
		}

		return (int)result * is_positive;
    }
};

int main(int argc, char ** argv)
{
	Solution s;
	//cout << s.convert(str,str.size()) << endl;
	cout << s.reverse(123) << endl;
	cout << s.reverse(1230) << endl;
	cout << s.reverse(-1250) << endl;
	cout << s.reverse(1534236469) << endl;
}