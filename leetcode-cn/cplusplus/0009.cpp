#include <vector>
#include <string>
#include <iostream>
#include <cstdint>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
		if (x < 0){ //如果x<0，因为符号的原因一定不是回文数字
			return false;
		}
		
		unsigned result = 0;
		int tempx = x;
		while( x != 0 ){
			result = result * 10 + x % 10;
			x = x / 10;
		}
		//cout << "result:" << result << ",x:" << x << endl;

		return result == tempx;
    }
};

int main(int argc, char ** argv)
{
	Solution s;
	//cout << s.convert(str,str.size()) << endl;
	cout << s.isPalindrome(123) << endl;
	cout << s.isPalindrome(121) << endl;
	cout << s.isPalindrome(-121) << endl;
}