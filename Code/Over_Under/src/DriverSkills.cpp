#include "main.h"

void setFlapSkills() {
  if (flapToggle.isPressed()) {   //If flap button is pressed
    flap.set_value(true);   //Extend flap
  }
  else {
    flap.set_value(false);      //Otherwise keep flap closed
  }
}

void driverSkills() {
arms::odom::reset({0, 0}, 225);   //Reset

arms::chassis::move({22, 12}, 100, arms::REVERSE);   //Push preload into goal
arms::chassis::move({30, 12}, 100, arms::REVERSE);   //Push preload into goal

arms::chassis::move({14, 13, 120}, 70);    //Move to loading position

//arms::chassis::turn(123);           /////////
arms::chassis::turn(120, 80);           /////////

flap.set_value(true);   //Open flap for match loading

cataMotor.moveVoltage(12000);   //Match loading
pros::delay(30000);         //30 seconds
//pros::delay(1000);         //1 second //for testing

cataMotor.moveVoltage(0);       //Stop catapult

flap.set_value(false);
intakeMotor.moveVoltage(-4000);

arms::chassis::turn(45, 75);


arms::chassis::move({6, -25}, 80, arms::REVERSE);      //Drive to other side
arms::chassis::move({6, -82}, 80, arms::REVERSE);      //Drive to other side
pros::delay(50); 

arms::chassis::move({22, -102}, 80, arms::REVERSE);      //Side goal slam
arms::chassis::move({40, -102}, 80, arms::REVERSE);      //Side goal slam

pros::delay(250);

arms::chassis::move({33, -90}, 80);     //Drive away from goal

arms::chassis::move({55, -55});    //Drive to center bar

intakeMotor.moveVoltage(-12000);


arms::chassis::turn(-80, 80);
flap.set_value(true);

arms::chassis::move({63, -90}, 90);    //Goal slam 1
pros::delay(100);
flap.set_value(false);
pros::delay(200);
arms::chassis::move({60, -66}, 90, arms::REVERSE); //Back up
arms::chassis::move({95, -60}, 90, arms::REVERSE); //Back up

flap.set_value(true);
arms::chassis::move({85, -95}, 90);    //Goal slam 2
pros::delay(100);
flap.set_value(false);

arms::chassis::move({70, -60}, 90, arms::REVERSE);   //Back up

flap.set_value(true);
arms::chassis::move({70, -94}, 90);    //Goal slam 3
flap.set_value(false);
arms::chassis::move({70, -70}, 80, arms::REVERSE);   //Back up to far position

intakeMotor.moveVoltage(-10000);

while (true){       //Start manual control
    arms::chassis::tank(master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y),
                      master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y));
  setFlapSkills();
  pros::delay(10);
}
}