#include "main.h"

void FarSideBlitz() {
arms::odom::reset({0, -5});   //Reset

flapR.set_value(true);    //Slap
//pros::delay(75);

intakeMotor.moveVoltage(12000);

arms::chassis::move({56,27}, 100, arms::ASYNC);  //Far triball
pros::delay(75);
flapR.set_value(false);
intakeMotor.moveVoltage(12000);
arms::chassis::waitUntilFinished(0);
//pros::delay(100);
intakeMotor.moveVoltage(1000);    //Finish picking up Far triball

arms::chassis::turn(-90, 90);   //Turn to goal
flapL.set_value(true);
flapR.set_value(true);

intakeMotor.moveVoltage(-12000);
pros::delay(75);

arms::chassis::move({47,-6}, 100, arms::ASYNC);    //Goal slam
arms::chassis::waitUntilFinished(1);

arms::chassis::move({50,5}, 100, arms::REVERSE);    //Back away from goal
flapL.set_value(false);
flapR.set_value(false);

intakeMotor.moveVoltage(12000);

arms::chassis::move({28,33, 90}, 60);   //Close triball
pros::delay(10);
intakeMotor.moveVoltage(9000);    //Finish picking up close triball

arms::chassis::move({20,5}, 80, 5, arms::REVERSE);    //Back away from close triball
arms::chassis::move({3,-7}, 80, arms::REVERSE);    //Position next to match load bar

arms::chassis::turn(-45, 70);   //Turn parallel to match load bar
pros::delay(300);
flapR.set_value(true);
intakeMotor.moveVoltage(-12000);
arms::chassis::move({13, -1.5}, 70, arms::RELATIVE);   //Drive to match load triball



//arms::chassis::turn(-0);    //Remove match load triball

flapR.set_value(false);
//arms::chassis::turn(-45);   //Turn parallel to match load bar

arms::chassis::move({7, -2.5}, 100, arms::RELATIVE);    //Drive closer to fleld perimiter
arms::chassis::turn(0);   //Turn to goal

pros::delay(500);
arms::chassis::move({21, -2}, 100, arms::RELATIVE);   //Score
arms::chassis::move({-15, 0}, 100, arms::RELATIVE | arms::REVERSE);   //Score
arms::chassis::turn(180);
arms::chassis::move({-25, 5}, 100, arms::RELATIVE | arms::REVERSE);   //Score

arms::chassis::tank(100,100);   //Back up
intakeMotor.moveVoltage(0);
pros::delay(400);
arms::chassis::tank(0,0);   //Stop backing up
}