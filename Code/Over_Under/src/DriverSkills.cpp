#include "main.h"

//void setFlapSkills() {
//  if (flapToggle.isPressed()) {   //If flap button is pressed
//    flapL.set_value(true);   //Extend flap
//  }
//  else {
//    flapL.set_value(false);      //Otherwise keep flap closed
//  }
//}

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

arms::chassis::move({13, 13, 117}, 70);    //Move to loading position

arms::chassis::turn(117, 80);           /////////

////flap.set_value(true);   //Open flap for match loading

cataMotor.moveVoltage(12000);   //Match loading
pros::delay(29000);         //30 seconds
//pros::delay(1000);         //1 second //for testing

cataMotor.moveVoltage(0);       //Stop catapult

////flap.set_value(false);
intakeMotor.moveVoltage(-4000);

arms::chassis::turn(45, 75);


arms::chassis::move({2, -25}, 80, arms::REVERSE);      //Drive to other side
arms::chassis::move({4, -82}, 80, arms::REVERSE);      //Drive to other side

intakeMotor.moveVoltage(-10000);

while (true){       //Start manual control
  arms::chassis::tank(getLeftJoystickSkills(master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y)),
                      getRightJoystickSkills(master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y)));
//  setFlapSkills();
  pros::delay(10);
}
}