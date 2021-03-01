#include "config.h"
// #include "../include/StepSequence.h"
#include <iostream>

int main()
{

    std::cout << config::pattern_dir << std::endl;
    std::cout << config::step_seq.full_rot() <<std::endl;
    std::cout << config::step_seq.size() <<std::endl;
    
    // StepSequence s = StepSequence();
    // s.use_8_step();
    for(int i=0; i<config::step_seq.size(); i++)
    {
        std::cout << config::step_seq[i] <<std::endl;
    }


    return 0;
}