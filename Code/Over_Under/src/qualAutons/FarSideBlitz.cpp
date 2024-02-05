#include "main.h"

void FarSideBlitz() {
arms::odom::reset({0, 0}, 0);   //Reset

flapR.set_value(true);    //Slap

arms::chassis::move({46, 26}, 100, arms::ASYNC);  //Far triball
pros::delay(75);
flapR.set_value(false);
intakeMotor.moveVoltage(12000);
arms::chassis::waitUntilFinished(0);
intakeMotor.moveVoltage(5000);    //Finish picking up Far triball

arms::chassis::turn(-90, 100);   //Turn to goal
flapL.set_value(true);
flapR.set_value(true);

intakeMotor.moveVoltage(-12000);

arms::chassis::move({46,-5}, 100);    //Goal slam

flapL.set_value(false);
flapR.set_value(false);

arms::chassis::move({40,5}, 100);    //Back away from goal
intakeMotor.moveVoltage(12000);

arms::chassis::move({31, 25}, 100);    //Close triball
pros::delay(10);
intakeMotor.moveVoltage(9000);

arms::chassis::move({12, -9, 90}, 100, arms::REVERSE);      //Move away from close triball
arms::turn({-90, 100});
intakeMotor.moveVoltage(-12000);

arms::chassis::move({-8, 7}, 90);    //Move to elevation bar alignment
intakeMotor.moveVoltage(12000);
arms::chassis::move({-7, 28}, 80);    //Elevation bar triball
intakeMotor.moveVoltage(5000);

arms::chassis::move({-3.0, -18.0}, 100, arms::REVERSE);     //Position next to match load bar
backFlap.set_value(true);
arms::chassis::move({5.0, -27.0}, 100, arms::REVERSE);      //Remove match load triball
backFlap.set_value(false);
arms::chassis::move({21.0, -26.0}, 100, arms::REVERSE);     //Back goal slam

arms::chassis::move({14.0, -26.0}, 100);
arms::chassis::turn({0, 100});
intakeMotor.moveVoltage(-12000);
arms::chassis::move({21.0, -26.0}, 100);        //Final goal slam

arms::chassis::tank(-100, -100);   //Back up
intakeMotor.moveVoltage(0);
pros::delay(400);
arms::chassis::tank(0,0);   //Stop backing up
}