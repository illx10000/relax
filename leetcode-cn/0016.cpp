#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int min_diff = INT_MAX - 1;
        int sum  = 0;
        
        sort(nums.begin(), nums.end());
        for(size_t i = 0; i < nums.size() - 2; i++)
        {
            for(size_t j = i+1; j <  nums.size() - 1; j++)
            {
                int num_to_find = target - nums[i] - nums[j];

                std::vector<int>::iterator new_begin = (nums.begin() + j + 1);

                int pos = std::lower_bound( new_begin, nums.end() , num_to_find ) - nums.begin() ;
                
                if ( pos == nums.size() ) //比最后一个数还要大 
                {
                    int cur_sum  = nums[i] + nums[j] + nums[nums.size()-1];
                    int cur_diff = std::abs( cur_sum - target ); //计算当前的差值
                    if(cur_diff == 0)   return target; //刚好相等

                    if ( cur_diff < min_diff ) {
                        min_diff = cur_diff; 
                        sum = cur_sum;
                    }
                }
                else if(pos == j + 1) //
                {
                    int cur_sum  = nums[i] + nums[j] + nums[pos];
                    int cur_diff = std::abs( cur_sum - target ); //计算当前的差值
                    if(cur_diff == 0)   return target; //刚好相等

                    if ( cur_diff < min_diff ) {
                        min_diff = cur_diff; 
                        sum = cur_sum;
                    }
                }
                
                else 
                {
                    for(int k = -1; k < 2; k++)
                    {
                        int index = pos + k;
                        if(index <= j || index >= nums.size()) continue;

                        int cur_sum  = nums[i] + nums[j] + nums[index];
                        int cur_diff = std::abs( cur_sum - target ); //计算当前的差值
                        if(cur_diff == 0)   return target; //刚好相等

                        if ( cur_diff < min_diff ) {
                            min_diff = cur_diff; 
                            sum = cur_sum;
                        }
                    }
                    
                }
                
            }
        }
        return sum;
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



int main(int argc,char** argv)
{

    /*Solution a;

    string s = "busvutpwmu";
    cout << a.lengthOfLongestSubstring(s) << endl;*/

    //int a[]={1,8,6,2,5,4,8,3,7};
    //int a[]={-1, 0, 1, 2, -1, -4};
    int a[]={-1,2,1,-4};
    //int b[]={2,3,4};

    vector<int> va(a,a+sizeof(a)/sizeof(a[0]));
    //vector<int> vb(b,b+sizeof(b)/sizeof(b[0]));

    //vector<vector<int> > vvResult;
    Solution sssss;
    cout << sssss.threeSumClosest(va,1) << endl;
}


