#include "main.h"

void CloseSideBlitz() {
  //arms::odom::reset({0, -18}, 0);   //Reset
arms::odom::reset({0, 5, 0});   //Reset

flap.set_value(true);    //Slap
pros::delay(100);
flap.set_value(false);

arms::chassis::move({8, 5}, 90);   


  arms::chassis::move({38, -30}, 90);   
  arms::chassis::move({48, -30}, 80);   

  flap.set_value(true);   //Disrupt
  pros::delay(75);
  flap.set_value(false);

  arms::chassis::move({0,12}, 80, arms::REVERSE);   //Move back to goal area
  arms::chassis::turn(225);

  arms::chassis::move({22, 28}, 80, arms::REVERSE);   //Push preload into goal
  arms::chassis::move({30, 28}, 90, arms::REVERSE);   //Push preload into goal

arms::chassis::move({1, 1}, 40, arms::ASYNC);    //Drive to matchload bar

  pros::delay(500);
  flap.set_value(true);               //Open flaps

  arms::chassis::waitUntilFinished(1);
  pros::delay(250);
  arms::chassis::turn(-90, 45);   //Remove triball from match load area
  flap.set_value(false);             //Close flaps
  intakeMotor.moveVoltage(-12000);
  pros::delay(500);

  arms::chassis::move({-5,-37, -90}, 80);   //Drive to elevation bar
}