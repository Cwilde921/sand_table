#ifndef __motor_h
#define __motor_h

#include <iostream>
#include <wiringPi.h>

#include "hardware_config.h"

class Motor
{
    public:
        Motor(int pins[]);
        ~Motor();
        void step(bool dir, uint steps=1, bool do_delay=false);
        void release_break();
        void apply_break();
        void set_delay(int ms);
    
    private:
        bool get_bit(int num, int loc);
        void update_step_ctr(bool dir);

        int m_step_ctr;
        int m_delay_ms;
        int m_pins[];
        int m_step_seq[];
};

#endif