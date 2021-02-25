#include <iostream>
#include "config.h"

class A
{
    public :
        int m_a;
        int m_b;

        A(int a, int b)
            : m_a (a), m_b (b)
        {
        }

        void operator()() const 
        {
            std::cout<< "a: " << m_a
                     << " b: " << m_b
                     << std::endl;
        }
};

int main() 
{
    A my_a(3,5);
    std::cout<< "created object" << std::endl;
    my_a();
    std::cout<< "myvar: " << myvar << std::endl;
    return 0;
}