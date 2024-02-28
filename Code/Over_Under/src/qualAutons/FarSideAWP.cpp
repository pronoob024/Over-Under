#include "main.h"

void FarSideAWP() {
arms::odom::reset({0, 0}, 90);   //Reset
intakeMotor.moveVoltage(12000);

arms::chassis::move({0, 3}, 100);   //Pick up elevation bar triball
pros::delay(350);
arms::chassis::move({4, -36}, 80, arms::REVERSE);   //Move to match load bar


arms::chassis::turn(135, 90);   //Align to match load bar
backFlap.set_value(true);
arms::chassis::move({10, -46}, 80, arms::REVERSE);   //Move to remove triball
arms::chassis::turn(180);       //Remove triball

backFlap.set_value(false);
arms::chassis::move({20, -55}, 85, arms::REVERSE);     //Move to goal slam position

arms::chassis::turn(0, 90);     //Turn to goal
intakeMotor.moveVoltage(-12000);
pros::delay(75);
arms::chassis::move({37, -58});     //Score intake triball
arms::chassis::move({20, -50}, 80, arms::REVERSE);     //Move away from goal
intakeMotor.moveVoltage(12000);

arms::chassis::move({36,-3, 90}, 87);   //Close triball
pros::delay(100);

arms::chassis::move({40, -20}, 95, arms::REVERSE);   //Close triball back up
arms::chassis::turn(-58);
intakeMotor.moveVoltage(-12000);    //Deposit triball at goal
pros::delay(250);
intakeMotor.moveVoltage(12000);

arms::chassis::turn(-45, 80);  //Turn to far triball
arms::chassis::move({63,-10}, 85);   //Far triball

arms::chassis::turn(-90);       //Turn to goal
flapL.set_value(true);
flapR.set_value(true);
intakeMotor.moveVoltage(-12000);

arms::chassis::move({58,-46}, 100);    //Goal slam

flapL.set_value(false);
flapR.set_value(false);
arms::chassis::move({50,-10}, 100, arms::REVERSE);    //Back away from goal
}