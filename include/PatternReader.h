#ifndef __pattern_reader_h
#define __pattern_reader_h

#include <string>
#include <memory>
#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
// #include <array>

#include "config.h"

class PatternReader
{
    public:
        PatternReader();

        struct PCMD
        {
            PCMD();
            int g;
            float x;
            float y;
            float r;
            float th;
            void set(char s, float value);
        };

        void get_file();
        void get_file(std::string filename);
        void clear_file();
        bool is_next();
        PCMD next();


    private:
        PCMD read_line(std::string line);

        std::shared_ptr<std::vector<std::string>> m_file_cont;
        const std::string m_cmds[] = {"G01"};
        const std::string m_flags[] = {"X", "Y", "R", "T"};
        int m_line_ct;
};

#endif