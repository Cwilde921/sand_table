#ifndef __config_h
#define __config_h

#include <string>
// #include "StepSequence.h"

namespace config
{
    // const bool use_8_pin = false;
    
    const std::string pattern_dir = "~/Desktop/sand_table/patterns";

    const int gear_ratio = 6;

    const int pins_th[] = {4,5,6,10};
    const int pins_r[] = {0,2,3,12};

    const int init_delay_ms = 3;
    const int init_step_seq_len = 4;
    // StepSequence step_seq = StepSequence(4);
}

#endif