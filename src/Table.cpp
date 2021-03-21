#include "Table.h"

// ===== Table implimentation =====
Table::Table()
    : m_delay_ms(config::init_delay_ms)
{
    if (wiringPiSetup() == -1)
    {
        throw std::exception("wiringPi setup failed");
        return;
    }
    m_motor_th = Motor(pins_th);
    m_motor_r = Motor(pins_r);

    m_steps_in_full_rotation = config::use_4_step ? steps_in_8_step_rotation : steps_in_8_step_rotation;
    
    m_d_pos_th = config::gear_ratio_turn_table * m_steps_in_full_rotation;
    m_d_pos_r = config::gear_ratio_rack_pinion * m_steps_in_full_rotation;
    m_d_pos_r_from_th = m_pos_r / config::gear_ratio_turn_table;
    home();
}

void Table::operator() (std::mutex &mtx)
{
    // std::cout<< "looping" << gear_ratio << std::endl;
    if( !m_gcreader.is_next() )
    {
        m_gcreader.get_file();
    }
    GCReader::GCcmd cmd = m_gcreader.next();
    make_move(cmd);
}

void Table::home()
{
    std::cout<< "homing" << std::endl;
    m_pos_th = 0;
    m_pos_r = 0;
    // m_offset_counter = 0;
}

void Table::step(int step_th, int step_r)
{   
    if(abs(step_th) > 1 || abs(step_r) > 1)
    {
        throw std::exception("step out of range")
    }
    m_motor_th.step(step_th);
    m_pos_th += m_d_pos_th * step_th;
    m_pos_r += m_d_pos_r_from_th * step_th;

    m_motor_r.step(step_r);
    m_pos_r += m_d_pos_r * step_r;
    delay(m_delay_ms);
}

Table::heuristic(int step_th, int step_r, PatternReader::PCMD dest)
{

}


// void Table::lin_steps(int steps_th, int steps_r)
// {
//     bool dir_th = true;
//     if(steps_th < 0)
//     {
//         steps_th = steps_th * -1;
//         dir_th = ! dir_th;   
//     }
//     bool dir_r = true;
//     if(steps_r < 0)
//     {
//         steps_r = steps_r * -1;
//         dir_r = ! dir_r;   
//     }

//     bool large_dir = dir_th;
//     bool small_dir = dir_r;
//     int large_steps = steps_th;
//     int small_steps = steps_r;
//     std::function<void(bool)> large_fun = m_motor_th.step;
//     std::function<void(bool)> small_fun = m_motor_r.step;

//     if(small_steps > large_steps)
//     {
//         swap(large_dir, small_dir);
//         swap(large_steps, small_steps);
//         swap(large_fun, small_fun);
//     }

//     double rato = large_steps / small_steps;
//     int ratio_ct = 0;

//     while(large_steps > 0) //maybe include && small_steps > 0
//     {
//         large_fun(large_dir);
//         large_steps --;
//         m_offset_counter ++;
//         ratio_ct ++;
//         if(m_offset_counter >= gear_ratio)
//         {
//             m_offset_counter = m_offset_counter-gear_ratio;
//         }
//         if(ratio_ct >= ratio)
//         {
//             small_fun(small_dir);
//             ratio_ct = ratio_ct-ratio;
//         }

//         delay(m_delay_ms);
//     }
// }

// void Table::interpret_gcode_file(std::string file)
// {
//     std::cout << "file: " << file << std::endl;
// }

// void Table::interpret_gcode_line(std::string cmd)
// {
//     std::cout << "command: " << cmd << std::endl;
// }

