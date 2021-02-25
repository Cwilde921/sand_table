#include "Motor.h"

// ===== Motor implimentation =====
Motor::Motor(int pins[])
    :   m_pins(pins), 
        m_step_ctr(1),
        m_delay_ms(3) 
    {
        m_step_seq = use_4_step ? steps_in_4_step_rotation : steps_in_8_step_rotation;
        for (int i=0; i<4; i++)
        {
            pinMode(motorPins[i], OUTPUT);
        }
    }

Motor::~Motor()
{
    release_break();
}

void Motor::step(bool dir, uint steps=1, bool do_delay=false)
{
    for(int i=0; i<steps; i++)
    {
        update_step_ctr(dir);
        for(int j=0; j<4; j++)
        {
            digitalWrite(m_pins[j], get_bit( m_step_seq[m_step_ctr], j ) ? HIGH : LOW );
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
        digitalWrite(m_pins[i], LOW)
    }
}

void Motor::apply_break()
{
    for(int i=0; i<4; i++)
    {
        digitalWrite(m_pins[j], get_bit( m_step_seq[m_step_ctr], i ) ? HIGH : LOW );
    }
}

void Motor::set_delay(int ms)
{
    m_delay_ms = ms;
}

bool Motor::get_bit(int num, int loc)
{
    return (num & ( 1 << loc )) >> loc;
}

void Motor::update_step_ctr(bool dir)
{
    if(dir){
        m_step_ctr ++;
        if( m_step_ctr >= sizeof(m_step_seq) )
        {
            m_step_ctr = 0;
        }
    }
    else
    {
        m_step_ctr --;
        if( m_step_ctr < 0 )
        {
            m_strp_ctr = sizeof(m_step_seq);
        }
    }
}
