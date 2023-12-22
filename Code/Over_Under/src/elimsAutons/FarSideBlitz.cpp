#include "main.h"

void ElimsFarSideBlitz() {
arms::odom::reset({0, -5});   //Reset

flap.set_value(true);    //Slap
pros::delay(100);

intakeMotor.moveVoltage(12000);

arms::chassis::move({51,28}, 100, arms::ASYNC);  //Far triball
flap.set_value(false);
intakeMotor.moveVoltage(12000);
arms::chassis::waitUntilFinished(0);
pros::delay(100);
intakeMotor.moveVoltage(1000);    //Finish picking up Far triball

arms::chassis::turn(-90, 90);   //Turn to goal
flap.set_value(true);
intakeMotor.moveVoltage(-12000);
pros::delay(75);

arms::chassis::move({47,-6}, 100, arms::ASYNC);    //Goal slam
arms::chassis::waitUntilFinished(1);

arms::chassis::move({50,5}, 100, arms::REVERSE);    //Back away from goal
flap.set_value(false);
intakeMotor.moveVoltage(12000);

arms::chassis::move({31,35, 90}, 60);   //Close triball
pros::delay(10);
intakeMotor.moveVoltage(9000);    //Finish picking up close triball

arms::chassis::move({20,5}, 80, 5, arms::REVERSE);    //Back away from close triball
arms::chassis::move({2,-6}, 80, arms::REVERSE);    //Position next to match load bar

arms::chassis::turn(-45, 50);   //Turn parallel to match load bar
pros::delay(300);
flap.set_value(true);
intakeMotor.moveVoltage(-12000);
arms::chassis::move({11, -17}, 50);   //Drive to match load triball

arms::chassis::turn(-0);    //Remove match load triball

flap.set_value(false);
arms::chassis::turn(-45);   //Turn parallel to match load bar

arms::chassis::move({7, -2.5}, 100, arms::RELATIVE);    //Drive closer to fleld perimiter
arms::chassis::turn(0);   //Turn to goal

pros::delay(500);
arms::chassis::move({25, -2}, 100, arms::RELATIVE);   //Score
arms::chassis::tank(-100,-100);   //Back up
intakeMotor.moveVoltage(0);
pros::delay(500);
arms::chassis::tank(0,0);   //Stop backing up
}