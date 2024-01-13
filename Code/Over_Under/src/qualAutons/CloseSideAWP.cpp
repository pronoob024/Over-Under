#include "main.h"

void CloseSideAWP() {
arms::odom::reset({0, 0}, 225);   //Reset

arms::chassis::move({22, 11}, 100, 1, arms::REVERSE);   //Push preload into goal
arms::chassis::move({32, 11, 180}, 60, arms::REVERSE);   //Push preload into goal

arms::chassis::move({1, 1}, 65, arms::ASYNC);    //Drive to matchload bar

pros::delay(500);
//flap.set_value(true);               //Open flaps
arms::chassis::waitUntilFinished(0);

pros::delay(250);
arms::chassis::turn(-90, 65);   //Remove triball from match load area
//flap.set_value(false);             //Close flaps
intakeMotor.moveVoltage(-12000);
pros::delay(250);

arms::chassis::move({-5,-34}, 80);   //Drive to elevation bar

arms::chassis::move({-5,-39}, 80);   //Drive to elevation bar
}