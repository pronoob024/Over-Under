#include "main.h"

void ElimsFarSideSAFE() {
arms::odom::reset({0, -12}, 135);   //Reset

arms::chassis::move({22, -21}, 100, arms::REVERSE);   //Push preload into goal
arms::chassis::move({33, -21}, 100, arms::REVERSE);   //Push preload into goal

arms::chassis::move({22, -4});     //Move away from goal

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
flap.set_value(true);

arms::chassis::move({57,-10}, 70, arms::ASYNC);    //Goal slam
pros::delay(500);
intakeMotor.moveVoltage(-12000);
arms::chassis::waitUntilFinished(1);

arms::chassis::move({50,5}, 100, arms::REVERSE);    //Back away from goal
flap.set_value(false);
}