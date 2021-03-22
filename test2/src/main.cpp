#include "Motor.h"
#include "config.h"

int main()
{
    wiringPiSetup();

    Motor mtr = Motor(config::pins_th);

    mtr.step_inner(true, mtr.get_steps_in_full_rotation(), true);

    mtr.step_inner(false, mtr.get_steps_in_full_rotation(), true);

    // delete mtr;

    return 0;
}