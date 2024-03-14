#include "main.h"

void FarSideBlitz() {
arms::odom::reset({0, 0}, 0);   //Reset

flapR.set_value(true);    //Slap preload
cataMotor.moveVoltage(7000);
arms::chassis::move({54, 28}, 100, arms::ASYNC);  //Rush far triball
pros::delay(150);
flapR.set_value(false);
intakeMotor.moveVoltage(12000);
arms::chassis::waitUntilFinished(0);
cataMotor.moveVoltage(0);
arms::chassis::turn(-90, 100);   //Turn to goal
flapL.set_value(true);
flapR.set_value(true);

intakeMotor.moveVoltage(-12000);

arms::chassis::move({54,-11}, 100);    //Goal slam

flapL.set_value(false);
flapR.set_value(false);

arms::chassis::move({35,5}, 100, arms::REVERSE);    //Back away from goal
intakeMotor.moveVoltage(12000);

arms::chassis::move({35, 25}, 90);    //Close triball
pros::delay(10);

arms::chassis::move({9, -24}, 80, arms::REVERSE);      //Move to match load bar

backFlap.set_value(true);
arms::chassis::turn(185, 90);   //Remove match load triball

backFlap.set_value(false);
arms::chassis::move({26.0, -31.0}, 90, arms::REVERSE);     //Back goal slam

arms::chassis::move({10.0, -38.0}, 100);    //Move away from goal
arms::chassis::turn(0, 85);
intakeMotor.moveVoltage(-12000);
pros::delay(300);
arms::chassis::move({32.0, -38.0}, 100);        //Final goal slam

arms::chassis::tank(-100, -100);   //Back up
intakeMotor.moveVoltage(0);
pros::delay(200);
arms::chassis::tank(0,0);   //Stop backing up
}