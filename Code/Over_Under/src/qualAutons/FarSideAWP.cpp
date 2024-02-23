#include "main.h"

void FarSideAWP() {
arms::odom::reset({0, 0}, 90);   //Reset

arms::chassis::move({0, 3}, 100);   //Pick up elevation bar triball
intakeMotor.moveVoltage(12000);
pros::delay(250);
arms::chassis::move({4, -36}, 70, arms::REVERSE);   //Move to match load bar


arms::chassis::turn(135, 80);
backFlap.set_value(true);
pros::delay(150);
arms::chassis::move({10, -46}, 80, arms::REVERSE);   //Move to remove triball
arms::chassis::turn(180);       //Remove triball

backFlap.set_value(false);
//arms::chassis::turn(180);
arms::chassis::move({20, -55}, 85, arms::REVERSE);     //Move to goal slam position
//arms::chassis::turn(180);
//arms::chassis::move({33, -55}, arms::REVERSE);     //Back goal slam
//arms::chassis::move({20, -57}, 80);         //Move away from goal
arms::chassis::turn(0, 90);
intakeMotor.moveVoltage(-12000);
pros::delay(250);
arms::chassis::move({37, -57});     //Score intake triball
arms::chassis::move({23, -50}, 80, arms::REVERSE);     //Move away from goal
intakeMotor.moveVoltage(12000);

arms::chassis::move({36,-1.5, 90}, 80);   //Close triball
pros::delay(150);
intakeMotor.moveVoltage(8000);    //Finish picking up close triball

arms::chassis::move({43, -10}, 90, arms::REVERSE);   //Close triball back up
arms::chassis::turn(-60);
intakeMotor.moveVoltage(-12000);    //Deposit triball at goal
pros::delay(250);
intakeMotor.moveVoltage(12000);

//arms::chassis::turn({62, 10}, 90);  //Turn to far triball
arms::chassis::move({60,1}, 90);   //Far triball

arms::chassis::turn(-90);
flapL.set_value(true);
flapR.set_value(true);
intakeMotor.moveVoltage(-12000);

arms::chassis::move({60,-40}, 100);    //Goal slam

flapL.set_value(false);
flapR.set_value(false);
arms::chassis::move({55,-5}, 100, arms::REVERSE);    //Back away from goal
}