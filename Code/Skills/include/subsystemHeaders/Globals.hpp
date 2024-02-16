#pragma once
#include "main.h"

extern pros::ADIDigitalOut flapL;
extern pros::ADIDigitalOut flapR;
extern pros::ADIDigitalOut backFlap;


extern pros::ADIDigitalOut hangLeft;
extern pros::ADIDigitalOut hangRight;

extern Motor cataMotor;
extern Motor intakeMotor;
extern ADIButton cataLimit;

extern pros::Distance distanceSensor;

extern Controller controller;        //Defines the controller for Okapi
extern Controller controller2;
extern pros::Controller master;    //Defines the controller for driving
extern pros::Controller partner;

extern ControllerButton cataShootFast;
extern ControllerButton cataShootSlow;
//
extern ControllerButton intakeOUT;
//
extern ControllerButton flapToggle;

extern ControllerButton hang;
//extern ControllerDigital hangDOWN;