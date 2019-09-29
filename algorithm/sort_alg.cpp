#include "sort_alg.h"
#include <algorithm>
#include <iostream>
#include <time.h>
#include <random>
#include <stack>

using namespace std;

void SortAlg::travel(vector<int>& arr)
{
    std::for_each(arr.begin(),arr.end(),[](int i){  std::cout << i << " "; });    
    cout << endl;
}

void SortAlg::bubbleSort(vector<int>& arr)
{
    int len = arr.size();
    for (int i = 0; i < len; i++)
    {
        for(int j = 0; j < len-1 ; j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

int  SortAlg::partitionInner(vector<int>& arr,int low,int high)
{
    int pivot = arr[low];
    while (low < high)
    {
        while(low < high && arr[high] >= pivot) 
        {
            high--;
        }    
        arr[low] = arr[high];

        while (low < high && arr[low] <= pivot)
        {
            low++;
        }
        arr[high] = arr[low];
    }
    
    arr[low] = pivot;
    return low;
}

void SortAlg::quickSortInner(vector<int>& arr,int low, int high)
{
    if(low < high)
    {
        int j = partitionInner(arr,low,high);
        quickSortInner(arr, low, j -1);
        quickSortInner(arr, j+1, high);
    }
}

void SortAlg::quickSortR(vector<int>& arr)
{
    quickSortInner(arr, 0 , arr.size() - 1);
}

void SortAlg::quickSort(vector<int>& arr)
{
    int len = arr.size();
    if(len <= 1)
    {
        return ;
    }

    stack<pair<int,int> > s;
    s.push(std::pair<int,int>(0,len-1) );
    while (!s.empty())
    {
        std::pair<int,int> p = s.top();
        s.pop();

        int j = partitionInner(arr, p.first, p.second);
        if( j -1  > p.first )
        {
            s.push( std::pair<int,int>(p.first, j - 1) );
        }
        if(p.second > j+1)
        {
            s.push(std::pair<int,int>(j+1,p.second));
        }
    }
}

void SortAlg::mergeSortR(vector<int>& arr)
{
    vector<int> temp; temp.resize(arr.size());
    mergeSortInner(arr,0 ,temp.size()-1, temp);
}

void SortAlg::mergeSortInner(vector<int>& arr, int low ,int high,vector<int>& temp)
{
    if(low < high)
    {
        int middle = (low+high)/2;
        int start1 = low ,end1 = middle;
        int start2 = middle+1, end2 = high;

        mergeSortInner(arr, start1,   end1, temp);
        mergeSortInner(arr, start2,   end2, temp);

        int k = start1, start = start1, end = end2;
        while(start1 <= end1 && start2 <= end2)
        {
            if(arr[start1] < arr[start2])
            {
                temp[k++] = arr[start1++];
            }
            else
            {
                temp[k++] = arr[start2++];
            }
        }
        while( start1 <= end1 ) temp[k++] = arr[start1++];
        while( start2 <= end2 ) temp[k++] = arr[start2++];

        for(int i = start; i <= end; i++ )
        {
            arr[i] = temp[i];
        }   
    }
}

void SortAlg::mergeSort(vector<int>& arr)
{
    vector<int> temp;
    temp.resize(arr.size());

    int len = arr.size();

    for(int seg = 1; seg < len; seg *= 2 )
    {
        for( int start = 0; start < len; start += 2*seg )
        {
            int low = start, middle = std::min(len, start+seg), high = std::min(len, start+2*seg);
            int start1 = low, end1 = middle;
            int start2 = middle, end2 =high;
            int k = start;

            while(start1 < end1 && start2 < end2)
            {
                if(arr[start1] < arr[start2])
                {
                    temp[k++] = arr[start1++];
                }
                else 
                {
                    temp[k++] = arr[start2++];
                }
            }

            while(start1 < end1) temp[k++] = arr[start1++];
            while(start2 < end2) temp[k++] = arr[start2++];
            for(int i = start; i < high; i++)
            {
                arr[i] = temp[i];
            } 
        }
    }
}

int main(int argc,char** argv)
{
    srand(time(NULL));
    vector<int> vec;
    for(int i = 0; i<20;i++)
    {
        vec.push_back(rand()%100);
    }

    SortAlg::travel(vec);
    SortAlg::bubbleSort(vec);
    SortAlg::travel(vec);

    std::random_shuffle(vec.begin(),vec.end());
    SortAlg::quickSortR(vec);
    SortAlg::travel(vec);

    std::random_shuffle(vec.begin(),vec.end());
    SortAlg::quickSort(vec);
    SortAlg::travel(vec);
    

    std::random_shuffle(vec.begin(),vec.end());
    SortAlg::mergeSortR(vec);
    SortAlg::travel(vec);
    
    std::random_shuffle(vec.begin(),vec.end());
    SortAlg::mergeSort(vec);
    SortAlg::travel(vec);
    
    
}


