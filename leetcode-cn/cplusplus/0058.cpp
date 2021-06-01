#include <string>
using namespace std;

class Solution {
public:
	int lengthOfLastWord(string s) {
		if (s.empty()) {
			return 0;
		}

		int i = (int)s.length() - 1, space_count = 0, no_space_count = 0;
		for (; i >= 0; i--) {
			if (s[i] != ' ') {
				no_space_count++;
			}
			else {
				space_count ++;
				if (no_space_count != 0) {
					return no_space_count;
				}
			}
		}
		return no_space_count;
		
	}
};