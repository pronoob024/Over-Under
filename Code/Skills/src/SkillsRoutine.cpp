#include "main.h"


void skillsroutine() {

arms::odom::reset({0, 0}, 225);   //Reset

arms::chassis::move({22, 11}, 100, arms::REVERSE);   //Push preload into goal
arms::chassis::move({32, 11}, 100, arms::REVERSE);   //Push preload into goal

arms::chassis::move({13, 14, 123}, 90);    //Move to loading position

//arms::chassis::move({13, 14}, 90);    //Move to loading position
arms::chassis::turn(122, 80);           /////////123

flapL.set_value(true);   //Open flap for match loading

cataMotor.moveVoltage(12000);   //Match loading
//pros::delay(28000);         //30 seconds
pros::delay(1000);         //1 second //for testing

cataMotor.moveVoltage(0);       //Stop catapult
flapL.set_value(false);
intakeMotor.moveVoltage(-12000);

//arms::chassis::turn(45, 90);


arms::chassis::move({0, -20}, 90, arms::REVERSE);      //Drive to other side
arms::chassis::move({0, -77}, 90, arms::REVERSE);      //Drive to other side
pros::delay(50); 

arms::chassis::move({22, -100}, 90, arms::REVERSE);      //Side goal slam
arms::chassis::move({40, -100}, 90, arms::REVERSE);      //Side goal slam

pros::delay(100);
arms::chassis::move({29, -90}, 80);     //Drive away from goal

//arms::chassis::move({50, -57});    //Drive to center bar //55 to 43
//arms::chassis::move({58, -56});    //Drive to center bar //55 to 43
        arms::chassis::move({54, -56}, 85);    //Drive to center bar //55 to 43



arms::chassis::turn(-80, 80);
        flapL.set_value(true);
flapR.set_value(true);

//arms::chassis::move({55, -89}, 100);    //Goal slam 1 63
arms::chassis::move({55, -85}, 100);    //Goal slam 1 63

pros::delay(100);
flapR.set_value(false);
flapL.set_value(false);
pros::delay(100);
arms::chassis::move({60, -55}, 90, arms::REVERSE); //Back up
arms::chassis::move({95, -55}, 90, arms::REVERSE); //Back up //100,-55

arms::chassis::turn(-110, 80);

//flapL.set_value(true);
flapR.set_value(true);
arms::chassis::move({72, -78}, 90);    //Goal slam 2
arms::chassis::move({74, -88}, 90);    //Goal slam 2 80
pros::delay(100);
flapL.set_value(false);
flapR.set_value(false);
arms::chassis::move({70, -60}, 90, arms::REVERSE);   //Back up

arms::chassis::move({57, -60}, 90, arms::REVERSE);   //Back up

flapL.set_value(true);
flapR.set_value(true);
arms::chassis::move({57, -90}, 100);    //Goal slam 3 64
flapL.set_value(false);
flapR.set_value(false);

arms::chassis::move({57, -70}, 90, arms::REVERSE | arms::ASYNC);   //Back up to far position

//arms::chassis::move({40, -95}, 90, arms::REVERSE | arms::ASYNC);   //Back up to far position
while (!cataLimit.isPressed()) {
    cataMotor.moveVoltage(10000);
}
cataMotor.moveVoltage(0);
arms::chassis::waitUntilFinished(0);


arms::chassis::move({3, -93}, 90);      //Drive to elevation bar 130
arms::chassis::turn(90, 80);
pros::delay(150);
///////////

//arms::chassis::move({40, -70}, 90, arms::REVERSE);   //Back up to far position
//arms::chassis::move({4, -95}, 90, arms::REVERSE | arms::ASYNC);   //Back up to far position
//while (!cataLimit.isPressed()) {
//    cataMotor.moveVoltage(10000);
//}
//cataMotor.moveVoltage(0);
//arms::chassis::waitUntilFinished(0);


//arms::chassis::turn(90);
//arms::chassis::move({0, -70}, 100);      //Drive to elevation bar 130
hangLeft.set_value(true);
hangRight.set_value(true);

arms::chassis::move({2, -33}, 100);      //Drive to elevate 131
hangLeft.set_value(false);
hangRight.set_value(false);

}