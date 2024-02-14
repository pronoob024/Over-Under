#include "main.h"


void skillsroutine() {

arms::odom::reset({0, 0}, 225);   //Reset

arms::chassis::move({22, 11}, 100, arms::REVERSE);   //Push preload into goal
arms::chassis::move({32, 11}, 100, arms::REVERSE);   //Push preload into goal

//arms::chassis::move({13, 14, 122}, 80);    //Move to loading position 123 REAL

arms::chassis::move({13, 15.5, 110}, 80);    //Move to loading position 123

arms::chassis::turn(122, 80);           /////////123

flapL.set_value(true);   //Open flap for match loading

cataMotor.moveVoltage(12000);   //Match loading
pros::delay(28000);         //30 seconds
//pros::delay(1000);         //1 second for testing

cataMotor.moveVoltage(0);       //Stop catapult
flapL.set_value(false);
intakeMotor.moveVoltage(-12000);

//arms::chassis::turn(45, 90);


arms::chassis::move({4, -17}, 90, arms::REVERSE);      //Drive to other side
arms::chassis::move({3, -77}, 90, arms::REVERSE);      //Drive to other side
pros::delay(50); 

arms::chassis::move({22, -100}, 90, arms::REVERSE);      //Side goal slam
arms::chassis::move({40, -100}, 90, arms::REVERSE);      //Side goal slam

pros::delay(100);
arms::chassis::move({29, -90}, 80);     //Drive away from goal

arms::chassis::move({46, -56}, 85);    //Drive to center bar //55 to 43



arms::chassis::turn(-80, 80);   //Turn to slam 1
       // flapL.set_value(true);
flapR.set_value(true);

//arms::chassis::move({55, -85}, 100);    //Goal slam 1 63 REAL

arms::chassis::move({50, -62}, 90);    //Goal slam 1
arms::chassis::move({57, -89}, 90);    //Goal slam 1


pros::delay(100);
flapR.set_value(false);
flapL.set_value(false);
pros::delay(100);
arms::chassis::move({60, -56}, 90, arms::REVERSE); //Back up
arms::chassis::move({95, -56}, 90, arms::REVERSE); //Back up //100,-55   95

arms::chassis::turn(-110, 80);  //Turn to slam 2

flapR.set_value(true);
flapL.set_value(true);
arms::chassis::move({90, -62}, 90);    //Goal slam 2
arms::chassis::move({80, -89}, 90);    //Goal slam 2 80
flapL.set_value(false);
flapR.set_value(false);
pros::delay(500);

arms::chassis::move({70, -62}, 90, arms::REVERSE);   //Back up -60
arms::chassis::move({57, -62}, 90, arms::REVERSE);   //Back up-60
arms::chassis::turn(-90);       //Turn to slam 3

flapL.set_value(true);
flapR.set_value(true);
arms::chassis::move({60, -92}, 100, arms::THRU);    //Goal slam 3
flapL.set_value(false);
flapR.set_value(false);

arms::chassis::move({57, -70}, 90, arms::REVERSE | arms::ASYNC);   //Back up to far position

while (!cataLimit.isPressed()) {        //Lowering cata to prepart for hang
    cataMotor.moveVoltage(10000);
}
cataMotor.moveVoltage(0);
arms::chassis::waitUntilFinished(0);

//arms::chassis::move({10, -100}, 90);      //Drive to elevation bar 130 REAL
arms::chassis::move({18, -110}, 90);      //Drive to elevation bar


arms::chassis::move({1, -97}, 90);      //Drive to elevation bar
arms::chassis::turn(120, 80);   //Turn to elevation bar
pros::delay(150);

hangLeft.set_value(true);
hangRight.set_value(true);

arms::chassis::move({-5, -47.5}, 90);      //Drive to elevate
hangLeft.set_value(false);
hangRight.set_value(false);

}