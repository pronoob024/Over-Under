#include "main.h"

pros::ADIDigitalOut flapL('D');
pros::ADIDigitalOut flapR('C');
pros::ADIDigitalOut backFlap('E');

pros::ADIDigitalOut hangLeft('A');
pros::ADIDigitalOut hangRight('B');

Motor cataMotor(8);
Motor intakeMotor(7);
ADIButton cataLimit('F');

Controller controller;        //Defines the controller for Okapi
pros::Controller master (pros::E_CONTROLLER_MASTER);    //Defines the controller for driving

ControllerButton shootCata(ControllerDigital::R1);

ControllerButton intakeOUT(ControllerDigital::L1);

ControllerButton flapToggle(ControllerDigital::down);
ControllerButton Lflap(ControllerDigital::L2);
ControllerButton Rflap(ControllerDigital::R2);
ControllerButton backFlapToggle(ControllerDigital::Y);

ControllerButton hang(ControllerDigital::B);