#include "main.h"

void FarSideBlitz() {
arms::odom::reset({0, 0}, 0);   //Reset

flapR.set_value(true);    //Slap

arms::chassis::move({53, 27}, 100, arms::ASYNC);  //Far triball
pros::delay(75);
flapR.set_value(false);
intakeMotor.moveVoltage(12000);
arms::chassis::waitUntilFinished(0);
intakeMotor.moveVoltage(5000);    //Finish picking up Far triball

arms::chassis::turn(-90, 100);   //Turn to goal
flapL.set_value(true);
flapR.set_value(true);

intakeMotor.moveVoltage(-12000);

arms::chassis::move({46,-6}, 100);    //Goal slam

flapL.set_value(false);
flapR.set_value(false);

arms::chassis::move({35,5}, 100, arms::REVERSE);    //Back away from goal
intakeMotor.moveVoltage(12000);

arms::chassis::move({35, 25}, 90);    //Close triball
pros::delay(10);
intakeMotor.moveVoltage(9000);

//arms::chassis::move({-4, -14}, 90, arms::REVERSE);      //Move away from close triball
//arms::chassis::turn(-90);
//intakeMotor.moveVoltage(-12000);
//pros::delay(500);
//arms::chassis::turn(90);
//arms::chassis::move({-4, 7}, 90);    //Move to elevation bar alignment
//intakeMotor.moveVoltage(12000);
//arms::chassis::move({-4, 28}, 80);    //Elevation bar triball
//intakeMotor.moveVoltage(5000);
//pros::delay(500);
arms::chassis::move({-3.0, -12.0}, 90, arms::REVERSE);     //Position next to match load bar
arms::chassis::turn(135);
backFlap.set_value(true);
arms::chassis::move({5.0, -27.0}, 90, arms::REVERSE);      //Remove match load triball
backFlap.set_value(false);
arms::chassis::move({21.0, -26.0}, 90, arms::REVERSE);     //Back goal slam

arms::chassis::move({10.0, -26.0}, 100);
arms::chassis::turn(0, 100);
intakeMotor.moveVoltage(-12000);
arms::chassis::move({21.0, -26.0}, 100);        //Final goal slam

arms::chassis::tank(-100, -100);   //Back up
intakeMotor.moveVoltage(0);
pros::delay(400);
arms::chassis::tank(0,0);   //Stop backing up
}