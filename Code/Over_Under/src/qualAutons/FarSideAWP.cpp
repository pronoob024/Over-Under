#include "main.h"

void FarSideAWP() {
arms::odom::reset({0, 0}, 90);   //Reset

arms::chassis::move({0, 3}, 100);
intakeMotor.moveVoltage(12000);
pros::delay(500);
arms::chassis::move({4, -36}, 90, arms::REVERSE);   //
arms::chassis::turn(135, 80);
backFlap.set_value(true);
pros::delay(500);
arms::chassis::move({16, -48}, 80, arms::REVERSE);   //
arms::chassis::turn(180);

backFlap.set_value(false);

arms::chassis::move({30, -53}, arms::REVERSE);     //Move away from goal
arms::chassis::move({18, -57});
arms::chassis::turn(0, 80);
intakeMotor.moveVoltage(0);
arms::chassis::move({30, -57});     //Move away from goal
arms::chassis::move({18, -57}, arms::REVERSE);     //Move away from goal

pros::delay(5000);

arms::chassis::move({41,31, 90}, 70);   //Close triball
pros::delay(150);
intakeMotor.moveVoltage(3000);    //Finish picking up close triball

arms::chassis::move({41,30}, 70, arms::REVERSE);   //Close triball back up
arms::chassis::turn(-70);
arms::chassis::move({51, 10}, 90, arms::ASYNC);     //Deposit at goal
intakeMotor.moveVoltage(-12000);
arms::chassis::waitUntilFinished(1);

intakeMotor.moveVoltage(12000);
arms::chassis::move({62,32}, 70);   //Far triball

arms::chassis::move({62,29, 90}, 70, arms::REVERSE);   //Far triball back up
arms::chassis::turn(-90);
//flap.set_value(true);

arms::chassis::move({57,-10}, 70, arms::ASYNC);    //Goal slam
pros::delay(500);
intakeMotor.moveVoltage(-12000);
arms::chassis::waitUntilFinished(1);

arms::chassis::move({50,5}, 100, arms::REVERSE);    //Back away from goal
//flap.set_value(false);
}