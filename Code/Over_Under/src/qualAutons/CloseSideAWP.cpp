#include "main.h"

void CloseSideAWP() {
arms::odom::reset({0, 0}, 225);   //Reset

arms::chassis::move({22, 11}, 100, 1, arms::REVERSE);   //Push preload into goal
arms::chassis::move({32, 11}, 100, arms::REVERSE);   //Push preload into goal

arms::chassis::move({-4, 11}, 90);    //Drive to matchload bar

backFlap.set_value(true);
arms::chassis::move({-9.0, 6.0}, 100, arms::REVERSE);  //Remove matchload triball
backFlap.set_value(false);
intakeMotor.moveVoltage(-12000);

arms::chassis::move({-5.0, -36.0}, 100);    //Drive to elevation bar

}