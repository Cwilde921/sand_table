#ifndef __table_h
#define __table_h

#include <mutex>
#include <thread>
#include <iostream>
#include <memory>
#include <string>
#include <functional>
#include <wiringPi.h>

#include "hardware_config.h"
#include "Motor.h"

class Table
{
    public:
        Table();
        void operator() (std::mutex &mtx);

    private:
        void home();
        void lin_move(int steps_th, int steps_r);
        void interpret_gcode_file(std::string file);
        void interpret_gcode_line(std::string cmd);

        Motor m_motor_th;
        Motor m_motor_r;

        int m_offset_counter;
        int m_steps_in_full_rotation;
        int m_delay_ms;
        double m_pos_th;
        double m_pos_r;
};

#endif