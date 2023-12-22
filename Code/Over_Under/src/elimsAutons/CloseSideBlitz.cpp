#include "main.h"

void ElimsCloseSideBlitz() {
arms::odom::reset({0, 5}, 0);   //Reset

flap.set_value(true);    //Slap
pros::delay(75);
flap.set_value(false);

arms::chassis::move({8, 5}, 90, 2);   //Get around bar

arms::chassis::move({42, -16}, 90, 2);   //go to center
arms::chassis::move({47.3, -16}, 70);   
arms::chassis::turn(0);   //Align to center
pros::delay(55);

flap.set_value(true);   //Disrupt
pros::delay(75);
flap.set_value(false);

arms::chassis::move({0,12}, 80, arms::REVERSE);   //Move back to goal area

}