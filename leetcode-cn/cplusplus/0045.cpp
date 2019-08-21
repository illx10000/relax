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
}

class Solution {
public:
    int jump(vector<int>& nums) {
    
        if(nums.size() < 2) return 0;
        //printVector(nums);
        
        vector<int> v; v.resize(nums.size());
        
        for(size_t i = 0; i < nums.size(); i++)
        {
            if( i + nums[i] + 1 >= nums.size() ) //可达终点
            {
                v[i] = 1;
            }
            else
            {
                v[i] = -1;
            }
        }
        if(v[0] == 1)   return 1;

        v[nums.size()-1] = 0; //((nums[nums.size()-1] > 0) ? -1 : 0); 

        //printVector(nums);
        //printVector(v);
        
        for(int i = nums.size() - 2; i >= 0; i--)
        {
            //cout << i << " ";
            //printVector(v);

            if(v[i] == 1) continue;

            int MIN_STEP = INT32_MAX;

            int m = std::min((int)nums[i],(int)nums.size() - i -1);
            for(int j = m; j > 0 ; j--)
            {
                //cout << "j:" << j << endl;
                if( v[i+j] <= MIN_STEP && v[i+j] >= 0) 
                {
                    MIN_STEP = v[i+j];
                    v[i] = MIN_STEP + 1;
                    if(v[i] == 1 || v[i] == 2) break; //已经最快到达了
                }
            }

        }
        //printVector(v);
        return v[0];
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
	//cout << (
	
    //va.clear(); for(int i = 10; i >=1 ;i--) va.push_back(i); va.push_back(1); va.push_back(0);
	cout  << sssss.jump(va) << endl;
		//) << endl;
	//printVector(va);

	//printT(sssss.removeDuplicates(va));
}

