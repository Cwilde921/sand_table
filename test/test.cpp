#include "config.h"
// #include "../include/StepSequence.h"
#include <iostream>
#include <array>

int main()
{

    // std::cout << config::pattern_dir << std::endl;
    // std::cout << config::step_seq.full_rot() <<std::endl;
    // std::cout << config::step_seq.size() <<std::endl;
    
    // // StepSequence s = StepSequence();
    // // s.use_8_step();
    // for(int i=0; i<config::step_seq.size(); i++)
    // {
    //     std::cout << config::step_seq[i] <<std::endl;
    // }
    int a[4] = {1,2,3,4};
    std::array<int, 4> b;
    b[0] = a[0];
    std::cout << b[0];

    return 0;
}