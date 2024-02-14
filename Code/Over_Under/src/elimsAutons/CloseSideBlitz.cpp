#include "main.h"

void ElimsCloseSideBlitz() {
arms::odom::reset({0, 0}, 0);   //Reset
intakeMotor.moveVoltage(12000);
arms::chassis::move({47, -5.0}, 100, 6, arms::THRU); //Rush center triball
arms::chassis::move({23, -5.0}, 100); //Rush center triball

pros::delay(100);
arms::chassis::move({29.0, -0.0}, 100, arms::REVERSE); //Move away from center

arms::chassis::move({0.0, 18.0}, 80, arms::REVERSE); //Go to matchload bar

backFlap.set_value(true);   //Remove match load triball
arms::chassis::turn(110, 90);
pros::delay(200);
backFlap.set_value(false);
arms::chassis::turn(-90, 90);   //Turn to elevation bar
pros::delay(200);

arms::chassis::move({-8.0, 4.0}, 80);  //Align to elevation bar
intakeMotor.moveVoltage(-12000);

arms::chassis::move({-6.0, -19.0}, 75);    //Go to elevation bar
arms::chassis::move({-6.0, 20}, 70);    //Go to elevation bar

}