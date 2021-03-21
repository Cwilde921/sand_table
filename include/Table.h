#ifndef __table_h
#define __table_h

#include <mutex>
#include <thread>
#include <iostream>
#include <memory>
#include <string>
#include <functional>
#include <wiringPi.h>
#include <stdexcept>

#include "config.h"
#include "Motor.h"
#include "StepSequence.h"
#include "PatternReader.h"

class Table
{
    public:
        Table();
        void operator() (std::mutex &mtx);

    private:
        // void home();
        // void lin_steps(int steps_th, int steps_r);
        void make_move(PatternReader::PCMD cmd);
        void step(int step_th, int step_r);
        int heuristic(int step_th, int step_r, PatternReader::PCMD dest);
        // void interpret_gcode_file(std::string file);
        // void interpret_gcode_line(std::string cmd);

        Motor m_motor_th;
        Motor m_motor_r;
        GCReader m_gcreader;

        // int m_offset_counter;
        double m_d_pos_th;
        double m_d_pos_r;
        double m_d_pos_r_from_th;
        int m_steps_in_full_rotation;
        int m_delay_ms;
        double m_pos_th;
        double m_pos_r;
};

#endif