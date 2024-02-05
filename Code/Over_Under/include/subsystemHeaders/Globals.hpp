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

extern Controller controller;        //Defines the controller for Okapi
extern pros::Controller master;    //Defines the controller for driving

extern ControllerButton shootCata;
//
extern ControllerButton intakeIN;
extern ControllerButton intakeOUT;
//
extern ControllerButton flapToggle;
extern ControllerButton backFlapToggle;

extern ControllerButton hang;