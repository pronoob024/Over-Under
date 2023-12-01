#include "main.h"

void CloseSideBlitz() {
  arms::odom::reset({0, -18}, 0);   //Reset

  arms::chassis::move({48, -30, 0}, 100);   
  flap.set_value(true);
  pros::delay(75);
  flap.set_value(false);

  arms::chassis::move({0,-7}, 80, arms::REVERSE);
  arms::chassis::turn(225);

  arms::chassis::move({22, 12}, 100, arms::REVERSE);   //Push preload into goal
  arms::chassis::move({30, 12}, 100, arms::REVERSE);   //Push preload into goal

  //move({1, 1}, 40, arms::ASYNC);    //Drive to matchload bar  ACTUAL WORKING LINE
    arms::chassis::move({1, 1, 225}, 40, arms::ASYNC);    //Drive to matchload bar

  pros::delay(500);
    flap.set_value(true);               //Open flaps

  arms::chassis::waitUntilFinished(1);
  pros::delay(250);
  arms::chassis::turn(-90, 45);   //Remove triball from match load area
  flap.set_value(false);             //Close flaps
  intakeMotor.moveVoltage(-12000);
  pros::delay(50);

  arms::chassis::move({-5,-37, -90}, 80);   //Drive to elevation bar
}