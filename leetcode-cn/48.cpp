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
    void rotate(vector<vector<int> >& matrix) {
        if(matrix.size() <= 1)  return;

        int max_rotate_size = matrix.size() / 2;
        int n = matrix.size() - 1;
        for(int i = 0; i < max_rotate_size; i++)
        {
            int inner_size = matrix.size() - i * 2 - 1;
            for(int j = i; j < inner_size + i ; j++)
            {
                /* code */
                    int LL = matrix[i][j]; //保存左上角的数据
                    

                    matrix[i][j]            = matrix[n-j][i];
                    matrix[n-j][i]          = matrix[n-i][n-j];
                    matrix[n-i][n-j]        =  matrix[j][n-i];
                    matrix[j][n-i]          = LL;
            }
            
        }
    }
};



int main(int argc,char** argv)
{

    /*Solution a;

    string s = "busvutpwmu";
    cout << a.lengthOfLongestSubstring(s) << endl;*/

    //int a[]={1,8,6,2,5,4,8,3,7};
    //int a[]={-1, 0, 1, 2, -1, -4};
    int a[]={2,3,0,1,4};
    //int b[]={2,3,4}1


    vector<int> va(a,a+sizeof(a)/sizeof(a[0]));
    //vector<int> vb(b,b+sizeof(b)/sizeof(b[0]));

    vector<vector<int> > vvResult;


    Solution sssss;


    vector< vector<int> > ss ;
    const int N = 3;

    for(int i = 0; i < N; i++)
    {
        vector<int> vvvv;
        for(int j = 0; j < N; j++)
        {
            vvvv.push_back( i * N + j  + 1);
        }
        ss.push_back(vvvv);
    }
    printT(ss);
    cout << endl;

    sssss.rotate(ss);

    printT(ss);
	//cout << (
	
    //va.clear(); for(int i = 10; i >=1 ;i--) va.push_back(i); va.push_back(1); va.push_back(0);
	//cout  << sssss.rotate(va) << endl;
		//) << endl;
	//printVector(va);

	//printT(sssss.removeDuplicates(va));
}

