#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
		Solution()
		{
			 dig_map[0] = {"a","b","c"};
			 dig_map[1] = {"d","e","f"};
			 dig_map[2] = {"g","h","i"};
			 dig_map[3] = {"j","k","l"};
			 dig_map[4] = {"m","n","o"};
			 dig_map[5] = {"p","q","r","s"};
			 dig_map[6] = {"t","u","v"};
			 dig_map[7] = {"w","x","y","z"};
		}

		void getNew(vector<string>& before, vector<string>& dig)
		{
			 if(before.empty())
			 {
				  before = dig;
					return ;
			 }

			 vector<string> result;
			 for(int j = 0; j < dig.size(); j++)
			 {
					for(int i = 0 ; i< before.size(); i++)
			 		{
							result.push_back(before[i] + dig[j]);	
			 		}
			 }
			 
			 result.swap(before);
		}
    vector<string> letterCombinations(string digits) 
		{
			 vector<string> result;
			 for(int i = 0; i<digits.size();i++)
			 {
				  getNew(result, dig_map[ digits[i] - '0' - 2 ] );
			 }
			 return result;
    }
private:
		map<int, vector<string> > dig_map;
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

	vector<string> strs = s.letterCombinations("23");
	printT(strs);
}