#include "main.h"

void CloseSideBlitz() {
arms::odom::reset({0, 5}, 0);   //Reset

flap.set_value(true);    //Slap
pros::delay(75);
flap.set_value(false);

arms::chassis::move({8, 5}, 90);   //Get around bar


  arms::chassis::move({42, -16}, 90);   //go to center
  arms::chassis::move({47.3, -16}, 70);   
  arms::chassis::turn(0);
pros::delay(55);

  flap.set_value(true);   //Disrupt
  pros::delay(75);
  flap.set_value(false);

  arms::chassis::move({0,12}, 80, arms::REVERSE);   //Move back to goal area
  arms::chassis::turn(225);

  arms::chassis::move({22, 33}, 80, arms::REVERSE);   //Push preload into goal
  arms::chassis::move({30, 33}, 90, arms::REVERSE);   //Push preload into goal

arms::chassis::move({1, 22}, 40, arms::ASYNC);    //Drive to matchload bar

  pros::delay(500);
  flap.set_value(true);               //Open flaps

  arms::chassis::waitUntilFinished(1);
  pros::delay(250);
  arms::chassis::turn(-90, 45);   //Remove triball from match load area
  flap.set_value(false);             //Close flaps
  intakeMotor.moveVoltage(-12000);
  pros::delay(500);

  arms::chassis::move({-5,-18}, 70);   //Drive to elevation bar
}