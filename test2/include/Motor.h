#ifndef __motor_h
#define __motor_h

#include <iostream>
#include <wiringPi.h>

#include "config.h"
#include "StepSequence.h"

class Motor
{
    public:
        Motor(int pins[]);
        ~Motor();
        void step(bool dir, uint steps=1, bool do_delay=false);
        void step(int step);
        void release_break();
        void apply_break();
        void set_delay(int ms);
        int get_steps_in_full_rotation();

    
    private:
        bool get_bit(int num, int loc);
        void update_step_ctr(bool dir);

        double pos_step_size;
        double pos_step_size_2;
        double pos;
        double max_pos;
        double min_pos;

        StepSequence m_step_seq = StepSequence(config::init_step_seq_len);

        // int m_step_ctr = 1;
        // int m_delay_ms = config::init_delay_ms;
        int m_pins[];
};

#endif