#include "main.h"

void FarSideAWP() {
arms::odom::reset({0, -12}, 135);   //Reset

move({22, -24}, 100, arms::REVERSE);   //Push preload into goal
move({30, -24}, 100, arms::REVERSE);   //Push preload into goal

arms::chassis::move({31,35, 90}, 60);   //Close triball
pros::delay(10);
intakeMotor.moveVoltage(3000);    //Finish picking up Close triball

arms::chassis::move({37,-6}, 100, arms::ASYNC);    //Goal slam
pros::delay(500);
intakeMotor.moveVoltage(-12000);
arms::chassis::waitUntilFinished(1);

arms::chassis::move({50,5}, 100, arms::REVERSE);    //Back away from goal
}