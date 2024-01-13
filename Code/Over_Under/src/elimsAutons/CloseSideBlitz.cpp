#include "main.h"

void ElimsCloseSideBlitz() {
arms::odom::reset({0, 5}, 0);   //Reset

//flap.set_value(true);    //Slap
pros::delay(75);

//flap.set_value(true);
arms::chassis::move({42,-6}, 100, 0);   //go to center
arms::chassis::turn(-90);
arms::chassis::move({42, -30}, 1000);   
pros::delay(55);

//flap.set_value(false);

arms::chassis::move({0,12}, 80, arms::REVERSE);   //Move back to goal area

}