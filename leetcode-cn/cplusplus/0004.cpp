#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:

	double findMedianSortedArrays(vector<int>& nums)
	{
		if (nums.empty())		return 0.0;
		if (0 == (nums.size() % 2) )	return ( (double)(nums[nums.size()/2] + nums[nums.size()/2-1] ) / 2.0);
		else return (double)( nums[nums.size()/2]);
	}

	//求在两个合并数组中第targeIndex+1的元素
	double findMedianSortedArrays(vector<int>& nx,vector<int>& ny, int targetIndex)
	{
		//假设nx+ny合并为一个数组，假设为nz,则应该是取nz[targetIndex]的值
		//转换一下思路;
		// 从nx中任意取出一个数（假设从中间取）value_x，位置为index_x 取值范围为[0,nx.size())，则应该有index_x个数值不大于value_x(在nr数组中);
		// 用value_x在ny中中查找顺序，可以得到 index_y;
		// 判断index_x+index_y和targetIndex的值大小，来调节index_x的取值;

		int high_index_x = nx.size() - 1, low_index_x = 0, index_x , index_y ,value_x ,index_y_max ;
		
		while (low_index_x <= high_index_x)
		{
			index_x = ( low_index_x + high_index_x) / 2; //数组nx中有index_x个数不大于value_x;
			value_x = nx[index_x]; //for debug
			
			index_y		= std::lower_bound( ny.begin(), ny.end(), value_x) - ny.begin(); //数组ny中有index_y个数不大于nx[index_x]
			index_y_max = std::upper_bound( ny.begin(), ny.end(), value_x) - ny.begin(); //数组ny中有index_y个数不大于nx[index_x]

			int sumIndex = index_x + index_y;
			for (; index_y <= index_y_max; index_y++)
			{
				sumIndex = index_x + index_y;
				if ( sumIndex  == targetIndex)
				{
					return  (double)nx[index_x];
				}
			}

			if ( sumIndex  == targetIndex)
			{
				return  (double)nx[index_x];
			}
			if(sumIndex < targetIndex ) //选取的数字过小
			{
				low_index_x = index_x + 1;
			}
			else //选取的数过大
			{
				high_index_x = index_x - 1;
			}
		}

		return findMedianSortedArrays(ny,nx,targetIndex);
	}

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        /*
		* 思路：题目中要求是log(M+N)，并且是有序数组，我第一感觉应该是二分查找
		*       再想一下：从nums1中任意选取一个数，应该知道他的下标（顺序），使用二分查找判断在nums2的位置
		*		他在nums1的位置+在nums2的位置之和应该是在整个数组中的位置；
		*/
		if (nums1.empty())	return findMedianSortedArrays(nums2);
		if (nums2.empty())	return findMedianSortedArrays(nums1);
		
		int totalSize = (int)(nums1.size() + nums2.size());
		if (totalSize % 2 == 0) //偶数，应该取两个数字
		{
			//例如数组arr一共有6个元素，取arr[2],arr[3]; (0,1,2,3,4,5)
			return (	findMedianSortedArrays(nums1,nums2, totalSize / 2 - 1)  + 
						findMedianSortedArrays(nums1,nums2, totalSize / 2 )
				   ) / 2.0;
		}
		else //奇数取一个数字
		{
			//例如数组arr一共有5个元素，取arr[2]，要找到2个数不小于result; (0,1,2,3,4)
			return findMedianSortedArrays(nums1,nums2,totalSize/2);
		}
    }
};


int main(int argc,char** argv)
{

	/*Solution a;

	string s = "busvutpwmu";
	cout << a.lengthOfLongestSubstring(s) << endl;*/
	
	int a[]={1};
	int b[]={2,3,4};

	vector<int> va(a,a+sizeof(a)/sizeof(a[0]));
	vector<int> vb(b,b+sizeof(b)/sizeof(b[0]));
	Solution sssss;
	cout << sssss.findMedianSortedArrays(va,vb)  << endl;
}

