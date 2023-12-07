#include "main.h"

void skillsroutine() {
arms::odom::reset({0, 0}, 225);   //Reset

arms::chassis::move({22, 12}, 100, arms::REVERSE);   //Push preload into goal
arms::chassis::move({30, 12}, 100, arms::REVERSE);   //Push preload into goal

arms::chassis::move({14, 13, 120}, 70);    //Move to loading position
flap.set_value(true);   //Open flap for match loading

cataMotor.moveVoltage(12000);   //Match loading
pros::delay(28500);         //28.5 seconds
//pros::delay(1000);         //30 seconds

cataMotor.moveVoltage(0);       //Stop catapult

flap.set_value(false);
intakeMotor.moveVoltage(-12000);

arms::chassis::move({8, -25}, 80, arms::REVERSE);      //Drive to other side //prev 6
arms::chassis::move({8, -82}, 80, arms::REVERSE);      //Drive to other side
pros::delay(50); 

arms::chassis::move({22, -100}, 80, arms::REVERSE);      //Side goal slam
arms::chassis::move({40, -100}, 80, arms::REVERSE);      //Side goal slam

arms::chassis::move({22, -100}, 60, arms::REVERSE);      //DOUBLE SLAM RAAAAAAAHHHHH
arms::chassis::move({30, -100}, 80, arms::REVERSE);      


arms::chassis::move({35, -90}, 80); //, arms::ASYNC);      //Drive away from goal, 35 prev 30 90 prev 88
flap.set_value(true);
//arms::chassis::waitUntilFinished(0);
arms::chassis::move({55, -55}, arms::ASYNC);    //Drive to center bar
pros::delay(300);
flap.set_value(false);
arms::chassis::waitUntilFinished(0);

flap.set_value(true);

arms::chassis::move({63, -90}, 90);    //Goal slam 1
pros::delay(100);
flap.set_value(false);
pros::delay(250);
arms::chassis::move({60, -66}, 90, arms::REVERSE); //Back up
arms::chassis::move({95, -60}, 90, arms::REVERSE); //Back up

flap.set_value(true);
arms::chassis::move({85, -95}, 90);    //Goal slam 2

arms::chassis::move({70, -60}, 90, arms::REVERSE);   //Back up

arms::chassis::move({70, -96}, 90);    //Goal slam 3

arms::chassis::move({64, -60}, 90, arms::REVERSE);   //Back up

arms::chassis::move({60, -96}, 90);    //Goal slam 4

arms::chassis::tank(-100,-100);   //Back up
intakeMotor.moveVoltage(0);
pros::delay(500);
arms::chassis::tank(0,0);   //Stop backing up
}