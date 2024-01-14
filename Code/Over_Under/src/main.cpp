#include "main.h"
#include "ARMS/chassis.h"
#include "ARMS/flags.h"
#include "okapi/api/device/motor/abstractMotor.hpp"
//#include "gif-pros/gifclass.hpp"    //Kept for future use
#include "okapi/impl/device/button/controllerButton.hpp"
#include "okapi/impl/device/controllerUtil.hpp"
#include "pros/adi.hpp"
#include "pros/misc.h"
#include "pros/rtos.hpp"
#include <cstdlib>
#include "ARMS/config.h"



/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */

//using arms::chassis::move;
void initialize() {
  arms::init();
 // pros::lcd::initialize();    //Kept in case of debugging
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {
}

//void autonomous() {    //FOR AUTON SKILLS IF NO FIELD CONTROLLER IS AVAILABLE, CONFIRM COMMENTED OR DELETED AFTER AUTON SKILLS IS RUN
//  skillsroutine();
//}

void autonomous() {
if(arms::selector::auton == 1) {
 CloseSideAWP();
}
if(arms::selector::auton == 2) {
  CloseSideBlitz();
}
if(arms::selector::auton == 3) {
  FarSideAWP();
}
if(arms::selector::auton == 4) {
  FarSideBlitz();
}
if(arms::selector::auton == 5) {
}

if(arms::selector::auton == -1) {
  ElimsFarSideSAFE();
}
if(arms::selector::auton == -2) {
  ElimsCloseSideBlitz();
}
if(arms::selector::auton == -3) {
  ElimsFarSideSAFE();
}
if(arms::selector::auton == -4) {
  ElimsFarSideBlitz();
}
if(arms::selector::auton == -5) {
}

if(arms::selector::auton == 0) {
  skillsroutine();
}
} 



void setCataFast() {
  if (cataShootFast.isPressed()) {        //Run catapult motor while button is pressed
    cataMotor.moveVoltage(12000);
  }
  else {
    cataMotor.moveVoltage(0);
  }
}


//void setCataSlow() {
//  if (cataShootSlow.isPressed()) {        //Run catapult motor while button is pressed
//    cataMotor.moveVoltage(10000);
//  }
//  else {
//    cataMotor.moveVoltage(0);
//  }
//}


void setIntake() {
	if (intakeIN.isPressed()) {
		intakeMotor.moveVoltage(-12000);   //If intake button is pressed then intake
	}
	else if (intakeOUT.isPressed()) {             //If outtake button is pressed then outtake
		intakeMotor.moveVoltage(12000);
	}
	else {
	  intakeMotor.moveVoltage(-6000);   //By default keep intake off
	  }
}

void setFlaps() {
  if (flapToggle.isPressed()) {   //If flap button is pressed
    flapL.set_value(true);   //Extend flap
    flapR.set_value(true);   //Extend flap

  }
  else {
    flapL.set_value(false);      //Otherwise keep flap closed
    flapR.set_value(false);   //Extend flap

  }
}


void setHang() {
  if (hang.isPressed()) {
    hangLeft.set_value(true);   //Raise left hang
    hangRight.set_value(true);  //Raise right hang
    if (!cataLimit.isPressed()) {
      cataMotor.moveVoltage(7500);
    }
    else {
      cataMotor.moveVoltage(0);
    }
  }
  else {
    hangLeft.set_value(false);  //Lower left hang
    hangRight.set_value(false); //Lower right hang
  }
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */


//void opcontrol() {    //FOR DRIVER SKILLS ONLY, CONFIRM COMMENTED OR DELETED AFTER DRIVER SKILLS IS RUN
//  driverSkills();
//}

int getLeftJoystick(int leftVal) {
//  return (pow(leftVal, 3) / 20500);
return (leftVal * .79);
}

int getRightJoystick(int rightVal) {
//  return (pow(rightVal, 3) / 20500);
return (rightVal * .79);
}


//void opcontrol() {
//  driverSkills();
//}

void opcontrol() {
while (true) {
  arms::chassis::tank(getLeftJoystick(master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y)),
                      getRightJoystick(master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y)));
  setCataFast();
  setIntake();
  setFlaps();
  setHang();
//  pros::lcd::set_text(0, "X: " + std::to_string(arms::odom::getPosition().x));    //Kept for debugging
//  pros::lcd::set_text(1, "Y: " + std::to_string(arms::odom::getPosition().y));
//  pros::lcd::set_text(2, "H: " + std::to_string(arms::odom::getHeading()));
//  pros::lcd::set_text(3, "Left: " + std::to_string(arms::odom::getLeftEncoder()));
//  pros::lcd::set_text(4, "Right: " + std::to_string(arms::odom::getRightEncoder()));
  pros::delay(10);
}
}