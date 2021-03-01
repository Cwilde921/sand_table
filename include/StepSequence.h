#ifndef __step_sequence_h
#define __step_sequence_h

#include <stdexcept>

class StepSequence
{
    public:
        StepSequence(int num_steps=4) 
        {
            if(num_steps==8) { use_8_step(); }
            else if(num_steps==4) { use_4_step(); }
            else { throw std::invalid_argument("Step Sequence recieved bad value"); }
        }
        int size() { return (m_step_size==1) ? 8 : 4; }
        int operator [] (int idx) { return m_seq[idx*m_step_size]; }
        int full_rot() { return (m_step_size==1) ? 4096 : 2048; }
    
    private:
        void use_4_step() { m_step_size = 2; }
        void use_8_step() { m_step_size = 1; }
        const int m_seq[8] = {0x01, 0x03, 0x02, 0x06, 0x04, 0x12, 0x08, 0x09};
        int m_step_size;

};

#endif