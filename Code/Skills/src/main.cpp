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
  //pros::lcd::initialize();    //Kept in case of debugging
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

void autonomous() {
skillsroutine();
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

driverSkills();
//arms::chassis::turn(90);

//arms::chassis::waitUntilFinished(0);
//pros::delay(1000);
//arms::chassis::move({0,0}, 100, arms::ASYNC);
//arms::odom::reset({0,0}, 0);
//arms::chassis::turn(90);
//arms::chassis::move({24,-24, -90}, 90);
//driverSkills();
//  while (true) {
//    // insert other opcontrol code here
//    pros::lcd::set_text(0, "X: " + std::to_string(arms::odom::getPosition().x));
//    pros::lcd::set_text(1, "Y: " + std::to_string(arms::odom::getPosition().y));
//    pros::lcd::set_text(2, "H: " + std::to_string(arms::odom::getHeading()));
//    pros::lcd::set_text(3, "Left: " + std::to_string(arms::odom::getLeftEncoder()));
//    pros::lcd::set_text(4, "Right: " + std::to_string(arms::odom::getRightEncoder()));
//    pros::lcd::set_text(5, "Middle: " + std::to_string(arms::odom::getMiddleEncoder()));
//    pros::delay(10);
//  }
}
