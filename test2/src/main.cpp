#include "Motor.h"
#include "config.h"

int main()
{
    Motor mtr = Motor(config::pins_th);

    mtr.step(true, mtr.get_steps_in_full_rotation(), true);

    mtr.step(false, mtr.get_steps_in_full_rotation(), true);

    delete mtr;

    return 0;
}