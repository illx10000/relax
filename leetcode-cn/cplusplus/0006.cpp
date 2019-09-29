#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
		//获取一行的字符串
		void getRow(const std::string& s, int curRow, int totalRow, std::string& result)
		{
				int start = curRow, totalLen = s.size() , totalSteps = 2 * (totalRow-1) ;
				while(start < totalLen )
				{
						result += s[start];
						int step1 = (totalRow-curRow-1)*2;
						if(step1 != 0)
						{
							 start += step1;
							 result += s[start];
						}

						int step2 = totalSteps - step1;
						if(step2 == 0)
						{
							start += totalSteps;
						}
						else 
						{
							start += step2;
							result + s[start];
						}
						//cout << curRow << "," << totalSteps << "," << step1 << "," << step2 << endl;
				}
		}

    //获取每一行的字符串
		void getEveryRows(const std::string& s, int numRows, vector<string>& rows )
		{
				for( int i = 0; i < numRows; i++)
				{
					 string row;
					 getRow(s,i,numRows,row);
					 rows.push_back(row);
				}
				
		}

		string convert(string s, int numRows) 
		{
				if(s.empty() || numRows <= 0)
				{
					 return s;
				}

				if(numRows > s.size())
				{
					numRows = s.size();
				}

				vector<string> result;
				getEveryRows(s,numRows,result);
				string str = "";
				for(int i = 0; i< result.size();i++)
				{
					str += result[i];
				}
				return str;
    }
		
};

int main(int argc, char ** argv)
{
	string str = "LEETCODEISHIRING";
	Solution s;
	cout << s.convert(str,str.size()) << endl;
}