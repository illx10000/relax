#ifndef __SORT_ALGORITHM__
#define __SORT_ALGORITHM__

#include <vector>
using std::vector;

class SortAlg
{
public:
    static void travel(vector<int>& arr);
    static void bubbleSort( vector<int>& arr );
    
    static void mergeSortR(vector<int>& arr);
    static void mergeSort(vector<int>& arr);
    static void mergeSortInner(vector<int>& arr, int low ,int high,vector<int>& temp);

    static void quickSortR(vector<int>& arr);
    static void quickSort(vector<int>& arr);

    static void quickSortInner(vector<int>& arr,int low, int high);
    static int  partitionInner(vector<int>& arr,int low, int high);

};

#endif