#include "main.h"
#include "ARMS/chassis.h"
#include "ARMS/flags.h"
#include "okapi/api/device/motor/abstractMotor.hpp"
#include "gif-pros/gifclass.hpp"
#include "okapi/impl/device/button/controllerButton.hpp"
#include "okapi/impl/device/controllerUtil.hpp"
#include "okapi/impl/device/distanceSensor.hpp"
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

using arms::chassis::move;

void initialize() {
  arms::init();
 // pros::lcd::initialize();
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
//Gif gif("/usd/bk.gif", lv_scr_act());
}

Motor cataMotor(8);
Motor intakeMotor(-7);
ADIButton cataLimit('A');
pros::ADIDigitalOut flap('B');
pros::ADIDigitalOut hangLeft('C');
pros::ADIDigitalOut hangRight('D');


Controller controller;        //Defines the controller for Okapi
pros::Controller master (pros::E_CONTROLLER_MASTER);    //Defines the controller for driving

ControllerButton cataShoot(ControllerDigital::R1);
ControllerButton cataShootManual(ControllerDigital::R2);
//
ControllerButton intakeIN(ControllerDigital::L1);
ControllerButton intakeOUT(ControllerDigital::L2);
//
ControllerButton flapToggle(ControllerDigital::down);

ControllerButton hang(ControllerDigital::B);



void CloseSideAWP() {
  arms::odom::reset({0, 0}, 225);   //Reset

  move({22, 12}, 100, arms::REVERSE);   //Push preload into goal
  move({30, 12}, 100, arms::REVERSE);   //Push preload into goal

  move({1, 1}, 40, arms::ASYNC);    //Drive to matchload bar  ACTUAL WORKING LINE

  pros::delay(500);
  flap.set_value(true);               //Open flaps

  arms::chassis::waitUntilFinished(1);
  pros::delay(250);
  arms::chassis::turn(-90, 45);   //Remove triball from match load area
  flap.set_value(false);             //Close flaps
  intakeMotor.moveVoltage(-12000);
  pros::delay(250);

  move({-5,-39.2, -90}, 80);   //Drive to elevation bar
}


void FarSideAWP() {
//arms::odom::reset({0, 0}, 90);
arms::odom::reset({-4, 14.4}, 90);

intakeMotor.moveVoltage(12000);

arms::chassis::move({-4, 28}, 60);    //Pick up triball

pros::delay(350);
intakeMotor.moveVoltage(3000);
arms::chassis::turn(90, 50);

arms::chassis::move({-4, 12}, 50, arms::REVERSE);    //Driving to goal
arms::chassis::turn(-90, arms::ASYNC);
arms::chassis::waitUntilFinished(0);
pros::delay(500);

arms::chassis::move({0,-27}, 50, arms::ASYNC);   //Drive to matchload zone
pros::delay(500);
intakeMotor.moveVoltage(-12000);
flap.set_value(true);

arms::chassis::waitUntilFinished(1);
pros::delay(500);

arms::chassis::turn(-10, arms::ASYNC);
arms::chassis::waitUntilFinished(0);
flap.set_value(false);
pros::delay(150);

arms::chassis::move({24,-27, 0}, 80);   //Drive into goal

//arms::chassis::move({31,-33, 0}, 80, arms::ASYNC);   //Drive into goal    WORKING
arms::chassis::turn(0, arms::ASYNC);
arms::chassis::waitUntilFinished(0);
flap.set_value(false);

arms::chassis::move({-16,0, 0}, 80, arms::RELATIVE | arms::REVERSE);    //Back away


pros::delay(5000);

////////////////////
intakeMotor.moveVoltage(12000);
arms::chassis::move({36,26, 90}, 80);

pros::delay(250);
intakeMotor.moveVoltage(1000);

arms::chassis::turn(-75, 80);
intakeMotor.moveVoltage(-12000);

arms::chassis::move({6, 0}, 90, arms::RELATIVE);
intakeMotor.moveVoltage(0);

arms::chassis::move({60,26}, 80, arms::ASYNC);

intakeMotor.moveVoltage(12000);

arms::chassis::waitUntilFinished(1);
pros::delay(100);
intakeMotor.moveVoltage(3000);

arms::chassis::turn(-90, 90);


arms::chassis::move({32,0}, 100, arms::THRU | arms::RELATIVE | arms::ASYNC);
intakeMotor.moveVoltage(-12000);
flap.set_value(true);

arms::chassis::waitUntilFinished(2);
arms::chassis::move({-10,0}, 100, arms::RELATIVE | arms:: THRU);
}


void CloseSideBlitz() {
  arms::odom::reset({0, -18}, 0);   //Reset

  move({48, -30, 0}, 100);   //Push preload into goal
  flap.set_value(true);
  pros::delay(75);
  flap.set_value(false);

  move({0,-7}, 80, arms::REVERSE);
  arms::chassis::turn(225);

  move({22, 12}, 100, arms::REVERSE);   //Push preload into goal
  move({30, 12}, 100, arms::REVERSE);   //Push preload into goal

  //move({1, 1}, 40, arms::ASYNC);    //Drive to matchload bar  ACTUAL WORKING LINE
    move({1, 1, 225}, 40, arms::ASYNC);    //Drive to matchload bar

  pros::delay(500);
    flap.set_value(true);               //Open flaps

  arms::chassis::waitUntilFinished(1);
  pros::delay(250);
  arms::chassis::turn(-90, 45);   //Remove triball from match load area
  flap.set_value(false);             //Close flaps
  intakeMotor.moveVoltage(-12000);
  pros::delay(50);

  move({-5,-37, -90}, 80);   //Drive to elevation bar
}


void FarSideBlitz() {
arms::odom::reset({0, -5});

flap.set_value(true);
pros::delay(100);
//flap.set_value(false);


intakeMotor.moveVoltage(12000);


arms::chassis::move({51,28}, 100, arms::ASYNC);  //Far triball
flap.set_value(false);

intakeMotor.moveVoltage(12000);

arms::chassis::waitUntilFinished(0);
pros::delay(100);
intakeMotor.moveVoltage(1000);

arms::chassis::turn(-90, 90);
//arms::chassis::waitUntilFinished(0);
//pros::delay(100);
flap.set_value(true);
intakeMotor.moveVoltage(-12000);
pros::delay(75);

arms::chassis::move({47,-6}, 100, arms::ASYNC);    //GOAL
arms::chassis::waitUntilFinished(1);

arms::chassis::move({50,5}, 100, arms::REVERSE);    //back away
flap.set_value(false);

intakeMotor.moveVoltage(12000);

arms::chassis::move({31,35, 90}, 60);   //Close triball
pros::delay(10);
intakeMotor.moveVoltage(3000);

arms::chassis::move({20,5}, 90, arms::REVERSE);    //back away

arms::chassis::move({2,-6}, 90, arms::REVERSE);    //position next to bar

arms::chassis::turn(-45, 50);
pros::delay(500);
flap.set_value(true);
intakeMotor.moveVoltage(-12000);
arms::chassis::move({11, -17}, 50);

arms::chassis::turn(-0);

flap.set_value(false);
arms::chassis::turn(-45);

arms::chassis::move({7, -2.5}, 100, arms::RELATIVE);   
arms::chassis::turn(-0);


pros::delay(500);
arms::chassis::move({25, -2}, 100, arms::RELATIVE);   //Score
arms::chassis::move({-15,0}, 100, arms::RELATIVE | arms::REVERSE);   //Score

}


void skillsroutine() {
  arms::odom::reset({0, 0}, 225);   //Reset

  move({22, 12}, 100, arms::REVERSE);   //Push preload into goal
  move({30, 12}, 100, arms::REVERSE);   //Push preload into goal

  move({14, 12, 120}, 80);    //Move to loading position

  flap.set_value(true);

  int cataCounter = 0;
//  while (cataCounter < 46) {
//    cataMotor.moveVoltage(12000);
//    if (cataLimit.isPressed()) {
//      cataCounter += 1;
//      pros::delay(400);
//    }
//    pros::delay(10);
//  }

cataMotor.moveVoltage(12000);
pros::delay(30000);
cataMotor.moveVoltage(0);
//pros::delay(5000);

  cataMotor.moveVoltage(0);
  flap.set_value(false);
  intakeMotor.setVoltageLimit(-12000);
  pros::delay(50);

  move({5, -25}, 70, arms::REVERSE); //Drive to other side
  move({5, -85}, 70, arms::REVERSE);          //Drive to other side
  pros::delay(50); 

  move({55, -56}, 90);
  flap.set_value(true);
  move({60, -90}, 90);
  pros::delay(100);
  flap.set_value(false);

  move({80, -60}, 90, arms::REVERSE);

  flap.set_value(true);
  move({75, -96}, 90);

  move({70, -60}, 90, arms::REVERSE);

  move({70, -96}, 90);

  arms::chassis::tank(-100,-100);
  intakeMotor.moveVoltage(0);
  pros::delay(500);
  arms::chassis::tank(0,0);
}


void autonomous1() {
    arms::odom::reset({0, 0}, 0);
  arms::chassis::turn(90, 100);
}

void autonomous() {
if(arms::selector::auton == 1) {
 // FarSideBlitz();
 //CloseSideAWP();
 skillsroutine();
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
  FarSideAWP();
}
if(arms::selector::auton == -2) {
  CloseSideBlitz();
}
if(arms::selector::auton == -3) {
  FarSideAWP();
}
if(arms::selector::auton == -4) {
  FarSideBlitz();
}
if(arms::selector::auton == -5) {
}

if(arms::selector::auton == 0) {
  skillsroutine();
}
} 



void resetCata() {
if (cataShoot.isPressed()){                           //If catapult shoot button is pressed
  while (cataLimit.isPressed()) {                     //If the catapult is pushing down the limit switch
    cataMotor.moveVoltage(12000);       //Move the catapult to shoot it
    pros::delay(350);               //Delay to ensure catapult shoots
    }
  while (!cataLimit.isPressed()) {                //While the catapult limit switch is not pressed
    cataMotor.moveVoltage(10000);    //Move the catapult down
      arms::chassis::tank(master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y),
                        master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y));
  pros::delay(10);      // ^ Allows for driving while the catapult is going down
  }
cataMotor.moveVoltage(0);   //Stop the catapult once the limit switch is pressed
  }
}


void setCata() {
    if (cataShootManual.isPressed()) {            
        cataMotor.moveVoltage(12000);
    }
    else {
      cataMotor.moveVoltage(0);
    }
}


void setIntake() {
	if (intakeIN.isPressed()) {
		intakeMotor.moveVoltage(12000);   //If intake button is pressed then intake
	}
	else if (intakeOUT.isPressed()) {             //If outtake button is pressed then outtake
		intakeMotor.moveVoltage(-12000);
	}
	else {
	  intakeMotor.moveVoltage(0);   //By default keep intake off
	  }

}


void setFlap() {
  if (flapToggle.isPressed()) {   //If flap button is pressed
    flap.set_value(true);   //Extend flap
  }
  else {
    flap.set_value(false);      //Otherwise keep flap closed
  }
}


void setHang() {
  if (hang.isPressed()) {
    hangLeft.set_value(true);
    hangRight.set_value(true);
  }
  else {
    hangLeft.set_value(false);
    hangRight.set_value(false);
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


void opcontrol() {
if(arms::selector::auton == 0) {
}
	while (true) {
    arms::chassis::tank(master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y),
                        master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y));
    resetCata();
    setCata();
    setIntake();
    setFlap();
    setHang();
    pros::lcd::set_text(0, "X: " + std::to_string(arms::odom::getPosition().x));
    pros::lcd::set_text(1, "Y: " + std::to_string(arms::odom::getPosition().y));
    pros::lcd::set_text(2, "H: " + std::to_string(arms::odom::getHeading()));
    pros::lcd::set_text(3, "Left: " + std::to_string(arms::odom::getLeftEncoder()));
    pros::lcd::set_text(4, "Right: " + std::to_string(arms::odom::getRightEncoder()));

    pros::delay(10);
}
}