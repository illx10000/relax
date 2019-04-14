#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() <= 1 ) return s.size();

        const int ARR_LEN = 256;
        int last_index[ARR_LEN]; 
        
        for (int i = 0; i < ARR_LEN; i++)   last_index[i] = -1;

        int iHighIndex = 1, iLowIndex =0, iMaxLen = -1;

        unsigned char low  = (unsigned char)s[iLowIndex];
        unsigned char high = (unsigned char)s[iHighIndex];

        while (iHighIndex < (int)s.size())
        {
            high = (unsigned char)s[iHighIndex];
            low  = (unsigned char)s[iLowIndex];

            if ( high != low ) //没有与当前字符相同的，前进
            {
                if (-1 != last_index[high]) //遇到非本身重复，跳过重复
                {
                    int iCurLen = iHighIndex - iLowIndex;
                    if (iCurLen > iMaxLen) iMaxLen = iCurLen;
					
					for(int k = iLowIndex; k < last_index[high]; k++) 
						last_index[(unsigned char)s[k]] = -1;

					iLowIndex   = last_index[high]+1; //越过重复的左边
					last_index[high] = iHighIndex;
                }
                else
                {
                    last_index[high] = iHighIndex;
                }
            }
            else //如果high==low
            {
                int iCurLen = iHighIndex - iLowIndex;
                if (iCurLen > iMaxLen) iMaxLen = iCurLen;
                
                last_index[high] = iHighIndex;

                iLowIndex   = iLowIndex+1;//越过左边的重复
            }
            iHighIndex++;
        }

        if (iLowIndex < (int)s.size())
        {
            int iCurLen = (int)s.size() - iLowIndex;
            if (iCurLen > iMaxLen) iMaxLen = iCurLen;
        }

        return iMaxLen;
    }
};

