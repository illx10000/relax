#include "kmp.h"



void KMP::getNext(const std::string& pattern, vector<int>& next)
{
    next.reserve(pattern.size());
    next[0] = -1;
    int j = 0, k = -1;
    while (j < pattern.size() - 1)
    {
        //p[k]表示前缀,p[j]表示后缀
        if(k == -1 || pattern[j] == pattern[k])
        {
            ++k;
            ++j;
            next[j] = k;
        }
        else 
        {
            k = next[k];
        }
    }
}

int KMP::kmpSearch(const std::string& text,const std::string& patten, vector<int>& next)
{
    int i = 0 ,j = 0;
    while (i < text.size())
    {
        if( patten[j] == text[i] )
        {
            j++;
            i++;
        }
        else 
        {
            j = next[j];
        }
    }
    
}