#ifndef __hardware_config_h
#define __hardware_config_h


const bool use_4_step = true;
const int gear_ratio = 6;

const int pins_th[] = {4,5,6,10};
const int pins_r[] = {0,2,3,12};

const int 4_step_seq[] = {0x01, 0x02, 0x04, 0x08};
const int 8_step_seq[] = {0x01, 0x03, 0x02, 0x06, 0x04, 0x12, 0x08, 0x09};

const int steps_in_4_step_rotation = 2048;
const int steps_in_8_step_rotation = 4096

#endif