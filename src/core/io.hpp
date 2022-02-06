#ifndef _IO_HPP_
#define _IO_HPP_

#include <zlib.h>
#include <fstream>
#include <spdlog/spdlog.h>

namespace ARAS::IO
{
    /*实验性功能，在确定稳定之前请勿使用*/
    bool Compress(const char * name,const char * dest)
    {
        std::ifstream tmp(name,std::ios::binary);
        if(!tmp.is_open())
        {
            spdlog::error("Could not open {}",name);
            return false;
        }
        std::string line,str;
        while(getline(tmp,line))
            str.append(line);
        tmp.close();
        uLong comlen = str.length()*sizeof(int);
        Byte * comptr;
        comptr = (Byte*)calloc((uInt)comlen,1);
        if(comptr == Z_NULL)
        {
            spdlog::error("Out of memory");
            return false;
        }
        if(compress(comptr,&comlen,(const Bytef*)str.c_str(),str.length()+1) != Z_OK)
        {
            spdlog::error("Compress error");
            return false;
        }
    }
    
            bool Delete(const char *name)
        {
            return true;
        }

        bool Move(const char *name, const char *target_pos)
        {
            return true;
        }

        bool Copy(const char *name, const char *target_pos)
        {
            return true;
        }

        bool Cut(const char *name, const char *target_pos)
        {
            return true;
        }
}

#endif
