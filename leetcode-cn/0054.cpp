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
    //cout << endl;
}

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
		vector<int> result;

		if(matrix.empty())		return result;
		if(matrix[0].empty())	return result;
		
		travel(result,matrix, 0, matrix.size(), 0 , matrix[0].size());
		return result;
    }

	//АўбѓДа
	void travel( vector<int>& result, 
		vector<vector<int> >& matrix,
		int startX, int lenX, 
		int startY,	int lenY)
	{
		if(lenX <= 0 || lenY <= 0) return;

		if (lenX == 1)
		{
			for( int y = startY; y < lenY + startY; y++)
			{
				result.push_back( matrix[startX][y]);
			}
			return;
		}
		else if(lenY == 1)
		{
			for( int x = startX; x < lenX + startX; x++)
			{
				result.push_back( matrix[x][startY]);
			}
			return;
		}

		int x = startX ,y = startY;

		for( y = startY; y < lenY - 1 + startY ; y++)	result.push_back( matrix[x][y]);  
		for( x = startX; x < lenX - 1 + startX ; x++)	result.push_back( matrix[x][y]);
		for(       ;     y > startY  ; y--)				result.push_back( matrix[x][y]);
		for(       ;     x > startX  ; x--)				result.push_back( matrix[x][y]);
		
		
		travel(result, matrix, startX + 1, lenX - 2, startY + 1, lenY - 2);
	}
};

int main(int argc,char** argv)
{

    /*Solution a;

    string s = "busvutpwmu";
    cout << a.lengthOfLongestSubstring(s) << endl;*/

    //int a[]={1,8,6,2,5,4,8,3,7};
    //int a[]={-1, 0, 1, 2, -1, -4};
    int a[]={-2,1,-3,4,-1,2,1,-5,4};
    //int b[]={2,3,4}1


    vector<int> va(a,a+sizeof(a)/sizeof(a[0]));
    //vector<int> vb(b,b+sizeof(b)/sizeof(b[0]));

    vector<vector<int> > vvResult;


    Solution sssss;


	vector< vector<int> > ss ;
    const int N = 4;

    for(int i = 0; i < N; i++)
    {
        vector<int> vvvv;
        for(int j = 0; j < N + 2; j++)
        {
            vvvv.push_back( i * (N + 2) + j  + 1);
        }
        ss.push_back(vvvv);
    }
    printT(ss);
    cout << endl;

	vector<int> vb = sssss.spiralOrder(ss);
	printVector(vb);


	//printT(sssss.removeDuplicates(va));
}

