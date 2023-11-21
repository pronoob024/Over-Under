#include "main.h"
#include "ARMS/chassis.h"
#include "ARMS/flags.h"
#include "okapi/api/device/motor/abstractMotor.hpp"
#include "gif-pros/gifclass.hpp"
#include "okapi/impl/control/async/asyncMotionProfileControllerBuilder.hpp"
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
DistanceSensor intakeSensor(9);
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

ControllerButton hang(ControllerDigital::X);



void CloseSideAWP() {
arms::odom::reset({0, 0}, 25);

arms::chassis::move({23,16, 180}, 80); //Push preload to goal
intakeMotor.moveVoltage(-12000);
arms::chassis::move({-4, 0}, 75, arms::RELATIVE | arms::REVERSE);

arms::chassis::turn(180, 80);
arms::chassis::move({-5, 0}, 80,arms::RELATIVE | arms::REVERSE);

arms::chassis::move({5, 0}, 80, arms::RELATIVE);

arms::chassis::turn(-135, 80);

arms::chassis::move({-1,4}, 80, arms::ASYNC); //Drive to match load zone
pros::delay(500);
flap.set_value(true);
arms::chassis::waitUntilFinished(2);
arms::chassis::turn(-90);                 //Remove match load
flap.set_value(false);

arms::chassis::move({-1,-39, -90}, 80); //Drive to contact elevation bar

}


void FarSideAWP() {
arms::odom::reset({-4, 24}, 90);

arms::chassis::move({-4, 26}, 60);    //Pick up triball

intakeMotor.moveVoltage(12000);
pros::delay(750);
intakeMotor.moveVoltage(0);

arms::chassis::move({-4, 0}, 80, arms::REVERSE);    //Driving to goal

arms::chassis::move({22,-24, 180}, 80, arms::REVERSE);   //Drive into goal

arms::chassis::move({-2,0}, 80, arms::RELATIVE);    //Back away

arms::chassis::move({4,0}, 80, arms::RELATIVE | arms::ASYNC);
intakeMotor.moveVoltage(-12000);

arms::chassis::waitUntilFinished(2);


arms::chassis::move({-5, 0}, 80, arms::REVERSE | arms::RELATIVE);
intakeMotor.moveVoltage(0);

////////////////////

arms::chassis::move({28,30, 90}, 80);

intakeMotor.moveVoltage(12000);
pros::delay(750);
intakeMotor.moveVoltage(0);

arms::chassis::turn(-75, 80);

arms::chassis::move({6, 0}, 90, arms::RELATIVE);
intakeMotor.moveVoltage(-12000);
arms::chassis::waitUntilFinished(1);
intakeMotor.moveVoltage(0);

arms::chassis::move({52,30}, 80, arms::ASYNC);

intakeMotor.moveVoltage(12000);

arms::chassis::waitUntilFinished(1);
pros::delay(100);
intakeMotor.moveVoltage(0);

arms::chassis::turn(-90, 90);


arms::chassis::move({2,32}, 100, arms::THRU | arms::RELATIVE | arms::ASYNC);
flap.set_value(true);
flap.set_value(true);

intakeMotor.moveVoltage(-12000);

arms::chassis::waitUntilFinished(2);
arms::chassis::move({-10,0}, 100, arms::RELATIVE | arms:: THRU);
}


void CloseSideBlitz() {

}


void FarSideBlitz() {
arms::odom::reset({-4, 0});

flap.set_value(true);
pros::delay(500);
flap.set_value(false);


arms::chassis::move({28,30, 90}, 80);

intakeMotor.moveVoltage(12000);
pros::delay(750);
intakeMotor.moveVoltage(0);

arms::chassis::turn(-75, 80);

arms::chassis::move({6, 0}, 90, arms::RELATIVE);
intakeMotor.moveVoltage(-12000);
arms::chassis::waitUntilFinished(1);
intakeMotor.moveVoltage(0);

arms::chassis::move({52,30}, 80, arms::ASYNC);

intakeMotor.moveVoltage(12000);

arms::chassis::waitUntilFinished(1);
pros::delay(100);
intakeMotor.moveVoltage(0);

arms::chassis::turn(-90, 90);


arms::chassis::move({2,32}, 100, arms::THRU | arms::RELATIVE | arms::ASYNC);
flap.set_value(true);
flap.set_value(true);

intakeMotor.moveVoltage(-12000);

arms::chassis::waitUntilFinished(2);
arms::chassis::move({-10,0}, 100, arms::RELATIVE | arms:: THRU);

}


void skillsroutine() {
  arms::odom::reset({0, 0}, 225);

  move({24, 12, 180}, 80, arms::REVERSE);

  move({12, 12, 110}, 80);

  flap.set_value(true);

  int cataCounter = 0;
  while (cataCounter < 46) {
    cataMotor.moveVoltage(12000);
    if (cataLimit.isPressed()) {
      cataCounter += 1;
      pros::delay(400);
    }
    pros::delay(10);
}
cataMotor.moveVoltage(0);
flap.set_value(false);
intakeMotor.setVoltageLimit(-12000);

  move({-2, -40}, 100, arms::REVERSE);
  move({-2, -96}, arms::REVERSE);

  move({48, -60}, 100);
  flap.set_value(true);
  move({60, -96}, 100);
  pros::delay(100);
  move({75, -60}, 100, arms::REVERSE);
  move({80, -96}, 100);

  move({70, -60}, 100, arms::REVERSE);

  move({70, -96}, 100);

  arms::chassis::tank(-100,-100);
  intakeMotor.moveVoltage(0);
  pros::delay(500);
  arms::chassis::tank(0,0);

}




void autonomous() {
if(arms::selector::auton == 1) {
  CloseSideAWP();
}
if(arms::selector::auton == 2) {
  CloseSideBlitz();
}
if(arms::selector::auton == 3) {
  skillsroutine();
}

if(arms::selector::auton == -1) {
  FarSideAWP();
}
if(arms::selector::auton == -2) {
  FarSideBlitz();
}
if(arms::selector::auton == -3) {
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
	  intakeMotor.moveVoltage(000);   //By default keep intake 
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
void oOpcontrol() {
  while (true) {
    // insert other opcontrol code here
    pros::lcd::set_text(0, "X: " + std::to_string(arms::odom::getPosition().x));
    pros::lcd::set_text(1, "Y: " + std::to_string(arms::odom::getPosition().y));
    pros::lcd::set_text(2, "H: " + std::to_string(arms::odom::getHeading()));
    pros::lcd::set_text(3, "Left: " + std::to_string(arms::odom::getLeftEncoder()));
    pros::lcd::set_text(4, "Right: " + std::to_string(arms::odom::getRightEncoder()));
    pros::lcd::set_text(5, "Middle: " + std::to_string(arms::odom::getMiddleEncoder()));
    pros::delay(10);
  }
}