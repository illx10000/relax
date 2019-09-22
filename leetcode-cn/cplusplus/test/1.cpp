#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstdint>
#include <set>
#include <string>
#include <random>

using namespace std;

#include <set>
#include <string>
#include <sstream>


template<typename T>
void printT(vector<T>& arr)
{
	cout << "[";
	for (int i = 0; i < (int)arr.size(); i++)
	{
		if (i)
		{
			cout << ",";
		}
		cout << arr[i];
	}
	cout << "]" << endl;
}


void printT(vector< vector<int> >& arr)
{
	for (size_t i = 0; i < arr.size(); i++)
	{
		printT(arr[i]);
	}
}

void printT(vector< vector<string> >& arr)
{
	for (size_t i = 0; i < arr.size(); i++)
	{
		printT(arr[i]);
	}
}

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

void printT(const vector<Interval>& s)
{
	for (size_t i = 0; i < s.size(); ++i)
	{
		cout << "i:" << i << ",[" << s[i].start << "," << s[i].end << "]" << "\n";
	}
}

template<typename T>
void printT(const T& t)
{
	cout << t;
}


struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include <map>
#include <utility>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <hash_map>
#include <cstdlib>
#include <cstring>

using namespace std;

void printT(TreeNode* root)
{
	if (root)
	{
		printT(root->left);
		cout << root->val << endl;
		printT(root->right);
	}

}



char * reverse(char *s)
{
	if(NULL == s || strlen(s) <= 0)
	{
		return s;
	}

	int low = 0, high = strlen(s) - 1;
	while(low < high)
	{
		swap(*(s+low),*(s+high));
		low++;
		high--;
	}
	return s;
}


struct LinkNode
{
	int value;
	struct LinkNode* next;
	LinkNode()
	{
		next = NULL;
	}	
};

LinkNode* merge(LinkNode* firstLink, LinkNode* secondLink)
{
	LinkNode* linkHead = NULL,*linkTail = NULL;

	while( firstLink != NULL && secondLink != NULL )
	{
		LinkNode* newNode = new LinkNode;
		if(firstLink->value < secondLink->value)
		{
			newNode->value = firstLink->value;	
			firstLink = firstLink->next;
		}
		else
		{
			newNode->value = secondLink->value;
			secondLink = secondLink->next;
		}

		if(linkHead == NULL)
		{
			linkHead = linkTail = newNode;
		}
		else
		{
			linkTail->next = newNode;
			linkTail = linkTail->next;
		}
	}

	LinkNode* leftLink = NULL;
	if( firstLink != NULL )
	{
		leftLink = firstLink;
	}
	else
	{
		leftLink = secondLink;
	}

	while ( leftLink != NULL )
	{
		LinkNode* newNode = new LinkNode;
		newNode->value = leftLink->value;
		linkTail->next = newNode;
		linkTail = linkTail->next;
		leftLink = leftLink->next;
	}
	
	
	return linkHead;
}

void traval(LinkNode* node)
{
	while (node != NULL)
	{
		cout << "node:" << node->value ;
		node = node->next;
	}
	cout << endl;
}

struct A
{
	char a;
	int b;
	char c;
	char d;
};

struct B
{
		char a;
	
	char c;
	char d;
	int b;
};

static int g_cnt = 0;

class CSortAlg
{
public:
	static void travel(vector<int>& arr);
public:
	static void mergeSortRecursive(vector<int>& arr); 	//递归方式的归并排序
	static void mergeSort(vector<int>& arr); 			//非递归形式的归并排序
private:
	static int mergeSortInner (vector<int>& arr, vector<int>& temp_arr, int low ,int high);

public:
	static void bububleSort(vector<int>& arr);

public:
	static void quickSortRecursive(vector<int>& arr);

};


void CSortAlg::travel(vector<int>& arr)
{
	for (size_t i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " " ;
	}
	cout << endl;
}

void CSortAlg::mergeSortRecursive(vector<int>& arr)
{
	if(arr.size() > 1)
	{
		int low = 0, high = arr.size()-1;
		vector<int> temp_arr;
		temp_arr.resize(arr.size());
		
		g_cnt = mergeSortInner(arr,temp_arr,low, high);

	}
}


//sort temp_arr[low,high]
int CSortAlg::mergeSortInner(vector<int>& arr, vector<int>& temp_arr, int low ,int high)
{
	int cnt = 0;

	if(high > low )
	{
		int len = high - low, middle = (len >> 1)+low;
		int start1 = low, start2 = middle+1, end1 = middle, end2 = high;

		cnt += mergeSortInner (arr,temp_arr,start1,		end1);
		cnt += mergeSortInner (arr,temp_arr,start2, 	end2);

		int k = low;
		while(start1 <= end1 && start2 <= end2)
		{
			if(arr[start1] < arr[start2])
			{
				temp_arr[k++] = arr[start1++];
			}
			else
			{
				cnt+= (middle-start1+1); //说明此时要进来的n应该比
				temp_arr[k++] = arr[start2++];
			}
		}

		while (start1 <= end1) //左边数组没有走完，说明剩下的左边数字比右边所有的数都大
		{
			temp_arr[k++] = arr[start1++];
		}
		
		while (start2 <= end2)
		{
			temp_arr[k++] = arr[start2++];
		}
		
		for(int i = low; i <= high; i++)
		{
			arr[i] = temp_arr[i];
		}
	}

	return cnt;
}

//参考https://zh.wikipedia.org/wiki/%E5%BD%92%E5%B9%B6%E6%8E%92%E5%BA%8F
void CSortAlg::mergeSort(vector<int>& arr)
{
	int cnt = 0;
	if(arr.size() > 1)
	{
		vector<int> temp_arr;
		temp_arr.resize(arr.size());

		for(int seg = 1; seg < (int) arr.size(); seg *= 2) //每次处理的长度（递增）
		{
			for (int start = 0; start < (int)arr.size() ;  start += 2 * seg ) //每次处理位置
			{
				int low = start, middle = std::min((int)arr.size(),start+seg), high = std::min((int)arr.size(), start + seg*2);
				int start1 = low, end1 = middle - 1;
				int start2 = middle, end2 = high - 1;
				
				int k = start;

				while(start1 <= end1 && start2 <= end2)
				{
					if(arr[start1] < arr[start2])
					{
						temp_arr[k++] = arr[start1++];
					}
					else
					{
						cnt += (end1 - start1 + 1);
						//cout << "end:" << end1 << ",start1:" << start1 << endl;

						temp_arr[k++] = arr[start2++];
					}
				}
				while(start1 <= end1)
				{
					temp_arr[k++] = arr[start1++];
				}
				while(start2 <= end2)
				{
					temp_arr[k++] = arr[start2++];
				}

				for(int i = low; i < high; i++)
				{
				 	arr[i] = temp_arr[i];
				}
			}
			
		}
	}
	g_cnt = cnt;
}

void CSortAlg::bububleSort(vector<int>& arr)
{
	if(arr.size() > 1)
	{
		int len = arr.size();
		for(int i = 0; i < len - 1; i++)
		{
			for (int j = 0; j < len - 1 -i  ; j++)
			{
				if(arr[j] > arr[j+1])
				{
					swap(arr[j],arr[j+1]);
				}
			}
		}
	}
}

int main(int argc, char** argv)
{
	std::default_random_engine random;
	std::uniform_int_distribution<int> dis1(1,1000);

	int a[] = { -1, 3, 3, 5, 5, 41, 5435, -11, 3423, 4432, -4421, 34432 };
	//int a[] = { 1,7,8,5 };
	
	int b[] = { 9,15,7,20,3 };


	vector<int> arr(a, a + sizeof(a) / sizeof(a[0]));

	
	CSortAlg::travel(arr);

	//CSortAlg::mergeSort(arr);
	CSortAlg::mergeSort(arr);

	//cout << g_cnt << endl;

	CSortAlg::travel(arr);
	
/*
	LinkNode *p1 = new LinkNode; p1->value = 1;
	LinkNode *p2 = new LinkNode; p2->value = 2; p1->next = p2;
	

	LinkNode *p3 = new LinkNode; p3->value = 3;
	LinkNode *p4 = new LinkNode; p4->value = 4; p3->next = p4;

	LinkNode* result = merge(p1,p3);
	traval(result);
	*/
}

