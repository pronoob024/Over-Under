#include "main.h"

void FarSideAWP() {
arms::odom::reset({0, 0}, 90);   //Reset

arms::chassis::move({0, 3}, 100);   //Pick up elevation bar triball
intakeMotor.moveVoltage(12000);
pros::delay(500);
arms::chassis::move({4, -36}, 80, arms::REVERSE);   //Move to match load bar
arms::chassis::turn(135, 80);
backFlap.set_value(true);
pros::delay(350);
arms::chassis::move({7, -45}, 80, arms::REVERSE);   //Align to matchload bar -48
arms::chassis::turn(180);

backFlap.set_value(false);
arms::chassis::turn(90);

arms::chassis::turn(180);


arms::chassis::move({30, -57}, arms::REVERSE);     //Remove match load triball
arms::chassis::move({18, -57});         //Goal slam
arms::chassis::turn(0, 80);
intakeMotor.moveVoltage(-12000);
arms::chassis::move({33, -57});     //Score intake triball
arms::chassis::move({16, -57}, arms::REVERSE);     //Move away from goal


arms::chassis::move({36,-0}, 90);   //Close triball
pros::delay(150);
intakeMotor.moveVoltage(8000);    //Finish picking up close triball

arms::chassis::move({44, -16}, 90, arms::REVERSE);   //Close triball back up
arms::chassis::turn(-70);
intakeMotor.moveVoltage(-12000);    //Deposit triball at goal
pros::delay(400);
intakeMotor.moveVoltage(12000);

arms::chassis::turn({62, -2}, 90);  //Turn to far triball
arms::chassis::move({62,-2}, 90);   //Far triball

arms::chassis::turn(-90);
flapL.set_value(true);
flapR.set_value(true);
intakeMotor.moveVoltage(-12000);

arms::chassis::move({62,10}, 100);    //Goal slam

flapL.set_value(false);
flapR.set_value(false);
arms::chassis::move({55,5}, 100, arms::REVERSE);    //Back away from goal
}