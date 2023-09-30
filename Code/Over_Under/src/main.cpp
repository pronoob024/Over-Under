#include "main.h"
#include "okapi/api/chassis/controller/chassisController.hpp"
#include "okapi/api/control/async/asyncMotionProfileController.hpp"
#include "okapi/api/device/motor/abstractMotor.hpp"
//#include "gif-pros/gifclass.hpp"
#include "okapi/impl/control/async/asyncMotionProfileControllerBuilder.hpp"
#include "okapi/impl/device/button/controllerButton.hpp"
#include "okapi/impl/device/controllerUtil.hpp"
#include "okapi/impl/device/distanceSensor.hpp"
#include "pros/adi.hpp"

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {}

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
void competition_initialize() {}

Motor cataMotor(9);
Motor intakeMotor(-3);
ADIButton cataLimit('B');
DistanceSensor intakeSensor(10);
pros::ADIDigitalOut piston('A');


Controller controller;        //Defines the controller
//
ControllerButton cataShoot(ControllerDigital::R1);
ControllerButton cataShootManual(ControllerDigital::R2);
//
ControllerButton intakeIN(ControllerDigital::L1);
ControllerButton intakeOUT(ControllerDigital::L2);

ControllerButton flapOUT(ControllerDigital::up);
ControllerButton flapIN(ControllerDigital::down);


std::shared_ptr<ChassisController> chassis =
ChassisControllerBuilder()
    .withMotors({-1, -2, -8}, {4, 5, 6})
    // Green gearset, 3.25 in wheel diam, 9.4 in wheel track
    .withDimensions({AbstractMotor::gearset::blue , (60.0 / 36.0)}, {{3.25_in, 11_in}, imev5BlueTPR})
    .build();

std::shared_ptr<AsyncMotionProfileController> profileController =
AsyncMotionProfileControllerBuilder()
  .withLimits({
    0.5, //max linear velocity
    2.0, //max linear acceleration
    10.0 //max jerk
  })
.withOutput(chassis)
.buildMotionProfileController();

void autonomous() {
  chassis->setMaxVelocity(75);

  piston.set_value(true);
  chassis->moveDistance(-5_in);
  piston.set_value(false);

  chassis->turnAngle(-135_deg);
  chassis->moveDistanceAsync(8_in);
  pros::delay(500);
  intakeMotor.moveVoltage(-12000);
  //pros::delay(1000);
  chassis->waitUntilSettled();
  intakeMotor.moveVoltage(0);
  chassis->moveDistance(-2_in);
  chassis->turnAngle(180_deg);

  chassis->setMaxVelocity(100);
  chassis->moveDistance(-7_in);

  //chassis->setMaxVelocity(100);
  chassis->moveDistance(8_in);
  chassis->turnAngle(-45_deg);
  //chassis->moveDistance(34_in);
  //chassis->turnAngle(-45_deg);
  //chassis->moveDistance(24_in);

//profileController->tarePosition();
profileController->generatePath({
  {0_ft, 0_ft, 45_deg},
  {15_in, 24_in, 45_deg},
  {60_in, 24_in, 0_deg}},
  "A" );
profileController->setTarget("A");

}

void resetCata() {
if (cataShoot.isPressed()){                           //If catapult shoot button is pressed
  while (cataLimit.isPressed()) {                     //If the catapult is pushing down the limit switch
    cataMotor.moveVoltage(12000);       //Move the catapult to shoot it
    pros::delay(350);               //Delay to ensure catapult shoots
    }
  while (!cataLimit.isPressed()) {                //While the catapult limit switch is not pressed
    cataMotor.moveVoltage(8000);    //Move the catapult down
     chassis->getModel()->tank(controller.getAnalog(ControllerAnalog::leftY),
                                 controller.getAnalog(ControllerAnalog::rightY));
  pros::delay(10);      // ^ Allows for driving while the catapult is going down
  }
cataMotor.moveVoltage(0);   //Stop the catapult once the limit switch is pressed
  }
}

void setCata() {
    if (cataShootManual.isPressed()) {
        cataMotor.moveVoltage(12000);
    }
}

//bool currState = false;
//bool prevState = false;

void setIntake() {
	if (intakeIN.isPressed()) {
		intakeMotor.moveVoltage(12000);
	}
	else if (intakeOUT.isPressed()) {
		intakeMotor.moveVoltage(-12000);
	}
	else {
		if (intakeSensor.get() < 50) {
			intakeMotor.moveVoltage(0);
		}
  else {
	  intakeMotor.moveVoltage(12000);
	  }
	}
}


void setFlap() {
  if (flapOUT.isPressed()) {
    piston.set_value(true);
  }
  if (flapIN.isPressed()) {
    piston.set_value(false);
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


    chassis->getModel()->tank(controller.getAnalog(ControllerAnalog::leftY),
                            controller.getAnalog(ControllerAnalog::rightY));
    resetCata();
    setCata();
	setIntake();
  setFlap();
	pros::delay(10);
}
}