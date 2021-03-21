#ifndef __config_h
#define __config_h

#include <string>
// #include "StepSequence.h"

namespace config
{
    // const bool use_8_pin = false;
    
    const std::string pattern_dir = "~/Desktop/sand_table/patterns";

    const double gear_ratio_turn_table = 20;  //defined by turntable gear / theta stepper gear
    const double gear_ratio_rack_pinion = 10;  //defined by rack / pinion

    const int pins_th[4] = {4,5,6,10};
    const int pins_r[4] = {0,2,3,12};

    const int init_delay_ms = 3; //recommended max 3 for 4 step or 2 for 8 step
    const int init_step_seq_len = 4;
    // const bool use_4_step = true;
    // StepSequence step_seq = StepSequence(4);
}

#endif