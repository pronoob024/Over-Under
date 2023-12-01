#include "main.h"

void skillsroutine() {
arms::odom::reset({0, 0}, 225);   //Reset

arms::chassis::move({22, 12}, 100, arms::REVERSE);   //Push preload into goal
arms::chassis::move({30, 12}, 100, arms::REVERSE);   //Push preload into goal

arms::chassis::move({14, 12, 120}, 80);    //Move to loading position
flap.set_value(true);   //Open flap for match loading

cataMotor.moveVoltage(12000);   //Match loading
pros::delay(30000);         //30 seconds
cataMotor.moveVoltage(0);       //Stop catapult

flap.set_value(false);
intakeMotor.setVoltageLimit(-12000);

arms::chassis::move({5, -25}, 70, arms::REVERSE);      //Drive to other side
arms::chassis::move({5, -85}, 70, arms::REVERSE);      //Drive to other side
pros::delay(50); 

arms::chassis::move({55, -54}, 90);    //Drive to center bar
flap.set_value(true);

arms::chassis::move({60, -90}, 90);    //Goal slam 1
pros::delay(100);
flap.set_value(false);

arms::chassis::move({80, -60}, 90, arms::REVERSE); //Back up

flap.set_value(true);
arms::chassis::move({75, -95}, 90);    //Goal slam 2

arms::chassis::move({70, -60}, 90, arms::REVERSE);   //Back up

arms::chassis::move({70, -96}, 90);    //Goal slam 3

arms::chassis::tank(-100,-100);   //Back up
intakeMotor.moveVoltage(0);
pros::delay(500);
arms::chassis::tank(0,0);   //Stop backing up
}