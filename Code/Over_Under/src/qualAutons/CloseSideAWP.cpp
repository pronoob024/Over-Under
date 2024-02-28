#include "main.h"

void CloseSideAWP() {
arms::odom::reset({0, 0}, 225);   //Reset

arms::chassis::move({22, 11}, 100, arms::REVERSE);   //Push preload into goal
arms::chassis::move({32, 11}, 100, arms::REVERSE);   //Push preload into goal

arms::chassis::move({18, 11}, 90);    //Drive to matchload bar

arms::chassis::turn(45);    //Align to match load bar

backFlap.set_value(true);
arms::chassis::move({6, 0}, 80, arms::REVERSE);  //Remove matchload triball
arms::chassis::turn(90);
pros::delay(200);
arms::chassis::turn(-90);       //Turn to elevation bar
backFlap.set_value(false);
intakeMotor.moveVoltage(-12000);

arms::chassis::move({3, -20.0}, 80);    //Drive to elevation bar

arms::chassis::move({3, -43.0}, 70);    //Drive to elevation bar
arms::chassis::move({3, -41.0}, 65, arms::REVERSE);    //Slightly back away from elevation bar
}