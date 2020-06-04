#ifndef __KMP__H__
#define __KMP__H__

#include <string>
#include <vector>

using std::string;
using std::vector;

struct KMP
{
    static int   searchString(const std::string& text,const std::string& pattern);
    static void  getNext(const std::string& parttern, vector<int>& next );
    int kmpSearch(const std::string& text,const std::string& patten, vector<int>& next);
};

#endif