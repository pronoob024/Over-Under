#include "main.h"

void CloseSideAWP() {
arms::odom::reset({0, 0}, 225);   //Reset

arms::chassis::move({22, 12}, 100, 1, arms::REVERSE);   //Push preload into goal        //TEST WITH EXIT ERROR
arms::chassis::move({30, 12}, 100, arms::REVERSE);   //Push preload into goal

arms::chassis::move({1, 1}, 40, arms::ASYNC);    //Drive to matchload bar

pros::delay(500);
flap.set_value(true);               //Open flaps
arms::chassis::waitUntilFinished(1);

pros::delay(250);
arms::chassis::turn(-90, 45);   //Remove triball from match load area
flap.set_value(false);             //Close flaps
intakeMotor.moveVoltage(-12000);
pros::delay(250);

arms::chassis::move({-5,-34}, 80);   //Drive to elevation bar

arms::chassis::move({-5,-39}, 80);   //Drive to elevation bar
}