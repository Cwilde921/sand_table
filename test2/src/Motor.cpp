#include "Motor.h"

// ===== Motor implimentation =====
Motor::Motor(int pins[4])
    :   m_pins(pins), 
        m_delay_ms() 
    {
        for (int i=0; i<4; i++)
        {
            pinMode(m_pins[i], OUTPUT);
        }
    }

Motor::~Motor()
{
    release_break();
    for (int i=0; i<4; i++)
    {
        pinMode(m_pins[i], INPUT);
    }
}

void Motor::step(int step){
    switch(step)
    {
        case 1:
            step_inner(true, 1, false);
            break;
        case -1:
            step_inner(false, 1, false);
            break;
        case 0:
        default:
            break;
    }
}

void Motor::step_inner(bool dir, uint steps, bool do_delay)
{
    for(int i=0; i<steps; i++)
    {
        update_step_ctr(dir);
        for(int j=0; j<4; j++)
        {
            digitalWrite(m_pins[j], get_bit(m_step_seq[m_step_ctr], j) ? HIGH : LOW );
        }
    }
    if(do_delay)
    {
        delay(m_delay_ms);
    }
}

void Motor::release_break()
{
    for(int i=0; i<4; i++)
    {
        digitalWrite(m_pins[i], LOW);
    }
}

void Motor::apply_break()
{
    for(int i=0; i<4; i++)
    {
        digitalWrite(m_pins[i], get_bit( m_step_seq[m_step_ctr], i ) ? HIGH : LOW );
    }
}

void Motor::set_delay(int ms)
{
    m_delay_ms = ms;
}

int Motor::get_steps_in_full_rotation()
{
    return m_step_seq.full_rot();
}

bool Motor::get_bit(int num, int loc)
{
    return (num & ( 1 << loc )) >> loc;
}

void Motor::update_step_ctr(bool dir)
{
    if(dir){
        m_step_ctr ++;
        if( m_step_ctr >= m_step_seq.size() )
        {
            m_step_ctr = 0;
        }
    }
    else
    {
        m_step_ctr --;
        if( m_step_ctr < 0 )
        {
            m_step_ctr = m_step_seq.size()-1;
        }
    }
}
