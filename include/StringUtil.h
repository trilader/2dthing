#ifndef STRING_UTIL_H
#define STRING_UTIL_H

#include <iostream>
#include <vector>

class StringUtil
{
public:
    static std::vector<std::string> split(std::string str, const char c='\n')
    {
        std::string tmp=str;
        std::vector<std::string> res;
        size_t pos=std::string::npos;
        while((pos=tmp.find_first_of(c))!=std::string::npos)
        {
            res.push_back(tmp.substr(0,pos));
            tmp=tmp.substr(pos+1);
        }
        res.push_back(tmp);
        return res;
    }

    static int count(std::string str, const char c)
    {
        int res=0;
        while(str.find(c)!=std::string::npos) ++res;
        return res;
    }
};

#endif // STRING_UTIL_H
