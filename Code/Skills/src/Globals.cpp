#include "main.h"

pros::ADIDigitalOut flapL('D');
pros::ADIDigitalOut flapR('C');
pros::ADIDigitalOut backFlap('E');


pros::ADIDigitalOut hangLeft('A');
pros::ADIDigitalOut hangRight('B');

Motor cataMotor(-17);
Motor intakeMotor(7);
ADIButton cataLimit('F');

pros::Distance distanceSensor(19);

Controller controller;        //Defines the controller for Okapi
//Controller controller2;
pros::Controller master (pros::E_CONTROLLER_MASTER);    //Defines the controller for driving
//pros::Controller partner (pros::E_CONTROLLER_PARTNER);

ControllerButton cataShootFast(ControllerDigital::R1);
ControllerButton cataShootSlow(ControllerDigital::R2);

ControllerButton intakeOUT(ControllerDigital::L1);

ControllerButton flapToggle(ControllerDigital::down);
ControllerButton Lflap(ControllerDigital::L2);
ControllerButton Rflap(ControllerDigital::R2);

ControllerButton hang(ControllerDigital::B);
//ControllerButton hangDOWN(partner ControllerDigital::R2)