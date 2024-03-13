#include "main.h"

void CloseSideAWP() {
arms::odom::reset({0, 0}, 45);   //Reset
intakeMotor.moveVoltage(6000);
cataMotor.moveVoltage(6000);
arms::chassis::move({7,7}, 75);
cataMotor.moveVoltage(0);
backFlap.set_value(true);
pros::delay(500);
arms::chassis::move({0,0}, 80, arms::REVERSE);
arms::chassis::turn(90, 80);
backFlap.set_value(false);

arms::chassis::move({22, 13}, 90);   //
arms::chassis::turn(0, 90);
intakeMotor.moveVoltage(-12000);
pros::delay(1000);
arms::chassis::move({15, 13}, 80, arms::REVERSE);   //

arms::chassis::turn(180, 80);

arms::chassis::move({37, 13}, 80, arms::REVERSE);   //Push preload into goal

arms::chassis::move({0, 0.0}, 80);    //Drive to elevation bar

arms::chassis::move({-1, -34.0}, 70);    //Drive to elevation bar
arms::chassis::move({-1, -33.0}, 65, arms::REVERSE);    //Slightly back away from elevation bar
flapL.set_value(true);
}