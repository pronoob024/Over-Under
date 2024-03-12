#include "main.h"

void CloseSideBlitz() {
arms::odom::reset({0, 0}, 0);   //Reset
intakeMotor.moveVoltage(12000);
//flapR.set_value(true);      //Slap Preload
//pros::delay(75);
//flapR.set_value(false);
cataMotor.moveVoltage(8000);
arms::chassis::move({47, -5.0}, 100); //Rush center triball
cataMotor.moveVoltage(0);
//pros::delay(50);
arms::chassis::move({29.0, -0.0}, 100, arms::REVERSE); //Move away from center

arms::chassis::move({2, 18.0}, 80, arms::REVERSE); //Go to matchload bar

backFlap.set_value(true);   //Remove match load triball
arms::chassis::turn(110, 80);
pros::delay(200);
backFlap.set_value(false);
arms::chassis::turn(-90, 80);   //Turn to elevation bar
pros::delay(200);

arms::chassis::move({-6.0, 4.0}, 80);  //Align to elevation bar
intakeMotor.moveVoltage(-12000);

arms::chassis::move({-6.0, -19.0}, 75);    //Go to elevation bar
arms::chassis::move({-6.0, -18}, 80);    //Slightly back away from elevation bar
}