#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstdint>
#include <set>
#include <string>

using namespace std;

#include <set>
#include <string>
#include <sstream>

class Solution {
public:
    int trap(vector<int>& height) {
		if(height.size() <= 2)	return 0;

		int l = 0, r = height.size()-1;
		while( l < r && height[l] == 0 ) l++;
		while( r > l && height[r] == 0 ) r--;
		
		if( l >= r)	return 0;

		//cout << l << "," << r << endl;

		return calcArea(l,r,height);	
			
    }

	
	int calcArea(int l,int r, vector<int>& height) //calc area of [l-r]
	{
		if(l + 1 >= r) return 0;
		
		const int INVALID_VALUE_CURR = -1;
		vector<int> maxHeightIndex; //store indeces of the number has max height

	 	int maxHeight = INVALID_VALUE_CURR;

		for(size_t i = l+1; i < r; ++i)
		{
			if(height[i]>maxHeight)
			{
				maxHeightIndex.clear();
				maxHeightIndex.push_back(i);
				maxHeight = height[i];
			}
			else if(height[i] == maxHeight)
			{
				maxHeightIndex.push_back(i);
			}
		}

		//cout << "l:" << l << "\nr:" << r << "\nmaxHeight:" << maxHeight << endl << endl;

		if(maxHeight < std::min(height[l],height[r]) ) //edge 
		{
			return calcAreaReal(l,r,height);
		}

		int area = 0;
		area += calcArea(l,  maxHeightIndex[0], height);
		area += calcArea(maxHeightIndex[maxHeightIndex.size()-1],  r, height);
		for(size_t i = 0; i < maxHeightIndex.size() - 1; i++)
		{
			area += calcAreaReal(maxHeightIndex[i],maxHeightIndex[i+1],height);
		}
		return area;
	}

	int calcAreaReal(int l,int r, vector<int>& height)
	{
		int area = 0;
		int minHeightInLR = std::min( height[l], height[r]);

		for(int i = l+1; i < r; i++)
		{
			area += (minHeightInLR- height[i]); 
		}
		return area;
	}
};

template<typename T>
void printVector(vector<T> &arr)
{
    cout << "[";
    for (int i = 0; i < arr.size(); i++)
    {
        if (i)
        {
            cout << ",";
        }
        cout << arr[i] ;
    }
    cout << "]" << endl;
}


void printT( vector< vector<int> > &arr)
{
    for (size_t i = 0; i < arr.size(); i++)
    {
        printVector(arr[i]);
    }
}

int main(int argc,char** argv)
{

    /*Solution a;

    string s = "busvutpwmu";
    cout << a.lengthOfLongestSubstring(s) << endl;*/

    //int a[]={1,8,6,2,5,4,8,3,7};
    //int a[]={-1, 0, 1, 2, -1, -4};
    int a[]={0,1,0,2,1,0,1,3,2,1,2,1};
    //int b[]={2,3,4};

    vector<int> va(a,a+sizeof(a)/sizeof(a[0]));
    //vector<int> vb(b,b+sizeof(b)/sizeof(b[0]));

    vector<vector<int> > vvResult;
    Solution sssss;
	//cout << (
	
	cout  << sssss.trap(va) << endl;
		//) << endl;
	//printVector(va);

	//printT(sssss.removeDuplicates(va));
}

