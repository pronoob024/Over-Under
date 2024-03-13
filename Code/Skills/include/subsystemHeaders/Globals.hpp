#pragma once
#include "main.h"

extern pros::ADIDigitalOut flapL;
extern pros::ADIDigitalOut flapR;
extern pros::ADIDigitalOut backFlap;


extern pros::ADIDigitalOut hangLeft;
extern pros::ADIDigitalOut hangRight;

extern Motor cataMotor;
extern Motor intakeMotor;


extern Controller controller;        //Defines the controller for Okapi
extern pros::Controller master;    //Defines the controller for driving

extern ControllerButton cataShootFast;
extern ControllerButton cataShootSlow;
//
extern ControllerButton intakeOUT;
//
extern ControllerButton flapToggle;
extern ControllerButton Lflap;
extern ControllerButton Rflap;

extern ControllerButton hang;
