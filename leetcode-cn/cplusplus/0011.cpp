#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int maxArea(vector<int>& height) {
        //用两个游标，一个从前到后，一个从后向前；
		int startIndex = 0				  ,endIndex = (int)height.size() -1  ;
		int startMax = -1 ,endMax = -1;


		int maxArea = 0;
		while (startIndex < endIndex) 
		{
			int curArea = std::min(height[startIndex], height[endIndex]) * (endIndex - startIndex); //当前区块的面积
			if (curArea > maxArea) maxArea = curArea;
			
			if ( height[startIndex]     < height[endIndex] )        startIndex++;
			else if(height[startIndex]  > height[endIndex])         endIndex--;
            else { startIndex++; endIndex--;}
		}

		return maxArea;
    }
};

int main(int argc,char** argv)
{

	/*Solution a;

	string s = "busvutpwmu";
	cout << a.lengthOfLongestSubstring(s) << endl;*/
	
	//int a[]={1,8,6,2,5,4,8,3,7};
    int a[]={1,1,1,1,1};
	//int b[]={2,3,4};

	vector<int> va(a,a+sizeof(a)/sizeof(a[0]));
	//vector<int> vb(b,b+sizeof(b)/sizeof(b[0]));
	Solution sssss;
	cout << sssss.maxArea(va)  << endl;
}

