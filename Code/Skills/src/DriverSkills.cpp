#include "main.h"

void setFlapSkills() {
  if (flapToggle.isPressed()) {   //If flap button is pressed
    flapL.set_value(true);   //Extend flap
    flapR.set_value(true);   //Extend flap

  }
  else if (Lflap.isPressed()) {
    flapL.set_value(true);
  }
  else {
    flapL.set_value(false);      //Otherwise keep flap closed
    flapR.set_value(false);      //Otherwise keep flap closed
  }
}

void setHangSkills() {
  if (hang.isPressed()) {
    hangLeft.set_value(true);   //Raise left hang
    hangRight.set_value(true);  //Raise right hang
      if (!cataLimit.isPressed()) {
      cataMotor.moveVoltage(12000);
    }
      else {cataMotor.moveVoltage(0);}
  }
  else {
    hangLeft.set_value(false);  //Lower left hang
    hangRight.set_value(false); //Lower right hang
  }
}





void setCataSkills() {
  if (cataShootFast.isPressed()) {        //Run catapult motor while button is pressed
    cataMotor.moveVoltage(12000);
  }
  else {
    cataMotor.moveVoltage(0);
  }
}

void setIntakeSkills() {
  if (intakeOUT.isPressed()) {
    intakeMotor.moveVoltage(-12000);
  }
}

int getLeftJoystickSkills(int leftVal) {
  return leftVal * 0.79;
}

int getRightJoystickSkills(int rightVal) {
  return rightVal * 0.79;
}

void driverSkills() {
arms::odom::reset({0, 0}, 225);   //Reset

arms::chassis::move({22, 11}, 100, arms::REVERSE);   //Push preload into goal
arms::chassis::move({32, 11}, 100, arms::REVERSE);   //Push preload into goal

arms::chassis::move({13, 11, 123}, 75);    //Move to loading position

arms::chassis::turn(121, 80);           /////////123

flapL.set_value(true);   //Open flap for match loading

cataMotor.moveVoltage(12000);   //Match loading
pros::delay(2000);         //Start Shooting
while(cataShootFast.isPressed()) {        //Run catapult motor while button is pressed
    arms::chassis::tank(getLeftJoystickSkills(master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y) * 0.4),
                      getRightJoystickSkills(master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y) * 0.4));
    cataMotor.moveVoltage(12000);
    pros::delay(10);
  }
cataMotor.moveVoltage(0);       //Stop catapult

flapL.set_value(false);
intakeMotor.moveVoltage(-12000);

//arms::chassis::turn(-75, arms::THRU);
arms::chassis::turn(180, arms::THRU | arms::RELATIVE);

while (true){       //Start manual control
  arms::chassis::tank(getLeftJoystickSkills(master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y)),
                      getRightJoystickSkills(master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y)));
  setFlapSkills();
  setHangSkills();
  setCataSkills();
  setIntakeSkills();
  pros::delay(10);
}
}