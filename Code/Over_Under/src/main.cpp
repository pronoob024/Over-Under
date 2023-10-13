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

Motor cataMotor(8);
Motor intakeMotor(-7);
ADIButton cataLimit('B');
DistanceSensor intakeSensor(9);
pros::ADIDigitalOut flap('A');


Controller controller;        //Defines the controller
//
ControllerButton cataShoot(ControllerDigital::R1);
ControllerButton cataShootManual(ControllerDigital::R2);
//
ControllerButton intakeIN(ControllerDigital::L1);
ControllerButton intakeOUT(ControllerDigital::L2);

//ControllerButton flapOUT(ControllerDigital::up);
//ControllerButton flapIN(ControllerDigital::down);
ControllerButton flapToggle(ControllerDigital::down);


std::shared_ptr<ChassisController> chassis =
ChassisControllerBuilder()
    .withMotors({-1, -2, -3}, {4, 5, 6})
    // Green gearset, 3.25 in wheel diam, 9.4 in wheel track
    .withDimensions({AbstractMotor::gearset::blue , (60.0 / 36.0)}, {{3.25_in, 11_in}, imev5BlueTPR})
    .withMaxVelocity(600)
    .build();

std::shared_ptr<AsyncMotionProfileController> profileController =
AsyncMotionProfileControllerBuilder()
  .withLimits({
    1, //max linear velocity
    2.0, //max linear acceleration
    10.0 //max jerk
  })
.withOutput(chassis)
.buildMotionProfileController();


void autonomousroutine1() {
  chassis->setMaxVelocity(250);

chassis->moveDistance(18_in);

chassis->turnAngle(45_deg);
chassis->moveDistance(7_in);
intakeMotor.moveVoltage(-12000);
pros::delay(500);

intakeMotor.moveVoltage(0);
chassis->moveDistance(-7_in);

chassis->turnAngle(180_deg);
chassis->moveDistance(-13_in);
chassis->moveDistance(12_in);

chassis->turnAngle(-40_deg);


chassis->moveDistanceAsync(19_in);
flap.set_value(true);
chassis->waitUntilSettled();

chassis->turnAngleAsync(-50_deg);
flap.set_value(false);
chassis->waitUntilSettled();

chassis->setMaxVelocity(350);

intakeMotor.moveVoltage(-12000);
chassis->moveDistance(37_in);

pros::delay(2000);
intakeMotor.moveVoltage(0);

}

void autonomousroutine2() { //flap slap preload, go to pick up one and grab other with flap, go for third
//cata thing

profileController->generatePath({
    {0_ft, 0_ft, 0_deg},
    {32_ft, 0_ft, 0_deg}},
    "A"
    );
    profileController->setTarget("A");
    profileController->waitUntilSettled();

chassis->moveDistance(-12_in);

chassis->turnAngle(75_deg);
intakeMotor.moveVoltage(-12000);
pros::delay(1000);
intakeMotor.moveVoltage(0);
chassis->turnAngle(-165_deg);
chassis->moveDistance(15_in);

flap.set_value(true);
chassis->moveDistance(-32_in);

chassis->moveDistance(5_in);
flap.set_value(false);

chassis->turnAngle(15_deg);
chassis->moveDistance(36_in);

//intake motor thing

chassis->moveDistance(-36_in);
chassis->turnAngle(75_deg);
chassis->moveDistanceAsync(5_in);
intakeMotor.moveVoltage(-12000);

chassis->waitUntilSettled();
chassis->moveDistance(-4_in);

}


void skillsroutine() {
flap.set_value(true);

chassis->moveDistanceAsync(-10_in);
pros::delay(250);
flap.set_value(false);
chassis->waitUntilSettled();

chassis->turnAngle(90_deg);
chassis->moveDistance(4_in);

int cataCounter = 0;
while (cataCounter < 46) {
  cataMotor.moveVoltage(12000);
  if (cataLimit.isPressed()) {
    cataCounter += 1;
  }
  pros::delay(10);
}
  //cata thing

chassis->turnAngle(-75_deg);



flap.set_value(true);
chassis->moveDistance(-24_in);
flap.set_value(false);
chassis->turnAngle(-10_deg);
chassis->moveDistance(10_in);
chassis->turnAngle(10_deg);
chassis->moveDistance(-9_in);


};

void autonTesting() {
  profileController->generatePath({
    {0_ft, 0_ft, 0_deg},
    {2_ft, 1_ft, 90_deg}},
    "A"
    );

  //  profileController->setTarget("A");
    //profileController->waitUntilSettled();

    //pros::delay(3000);

  profileController->generatePath({
    {0_ft, 0_ft, 0_deg},
    {2_ft, -1_ft, -90_deg},
    {2_ft, -2_ft, -90_deg}},
    "B"
    );

    profileController->setTarget("B");
    profileController->waitUntilSettled();
}

void autonomous() {
  autonomousroutine1();
//autonTesting();
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
  if (flapToggle.isPressed()) {
    flap.set_value(true);
  }
  else {
    flap.set_value(false);
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