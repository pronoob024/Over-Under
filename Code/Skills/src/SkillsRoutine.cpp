#include "main.h"



void skillsroutine() {

arms::odom::reset({0, 0}, 45);   //Reset

arms::chassis::move({15, 12}, 100);    //Move to loading position

arms::chassis::turn(118, 100);           /////////121 111 114
//arms::chassis::turn({65, -88}, 90);
flapL.set_value(true);   //Open flap for match loading

cataMotor.moveVoltage(12000);   //Match loading

pros::delay(28000);         //28 seconds
//pros::delay(1000);         //1 second //for testing
cataMotor.moveVoltage(0);       //Stop catapult

flapL.set_value(false);
//arms::chassis::move({33, 12}, 100, arms::ASYNC);
//pros::delay(250);
intakeMotor.moveVoltage(-12000);
//arms::chassis::waitUntilFinished();

//arms::chassis::move({32, 11}, 100, arms::REVERSE);   //Push preload into goal


arms::chassis::turn(45, 90);

arms::chassis::move({5, -15}, 100, 6, arms::REVERSE | arms::THRU);      //Drive to other side

arms::chassis::move({3, -25}, 100, 6, arms::REVERSE | arms::THRU);      //Drive to other side
arms::chassis::move({3, -82}, 100,6, arms::REVERSE | arms::THRU);      //Drive to other side
//pros::delay(50); 

arms::chassis::move({22, -104}, 100,6, arms::REVERSE | arms::THRU);      //Side goal slam
arms::chassis::move({35, -104}, 100, arms::REVERSE);      //Side goal slam


//arms::chassis::move({30, -104}, 80);      //Side goal slam
//arms::chassis::move({40, -104}, 80, arms::REVERSE);      //Side goal slam

pros::delay(50);

arms::chassis::move({22, -90}, 80);     //Drive away from goal

//flapR.set_value(true);
arms::chassis::move({40, -58});    //Drive to center bar //55 to 43
arms::chassis::move({50, -56});    //Drive to center bar //55 to 43

intakeMotor.moveVoltage(-12000);


arms::chassis::turn(-85, 80);
//flapL.set_value(true);
  flapR.set_value(true);

arms::chassis::move({59, -90}, 100);    //Goal slam 1  87
//arms::chassis::move({62 -89}, 70);    //Goal slam 1
//arms::chassis::move({62 -86}, 70, arms::REVERSE);    //Goal slam 1
//arms::chassis::move({62 -89}, 100);    //Goal slam 1

pros::delay(50);
flapR.set_value(false);
flapL.set_value(false);
pros::delay(250);
arms::chassis::move({54, -58}, 90, arms::REVERSE); //Back up
//flapL.set_value(true);
//arms::chassis::move({75, -58}, 90); //Back up //100,-55
arms::chassis::move({70, -58}, 90, arms::REVERSE); //Back up

//backFlap.set_value(true);
flapR.set_value(true);
arms::chassis::move({70, -87}, 100);    //Goal slam 2
flapR.set_value(true);

arms::chassis::move({70, -58}, 90, arms::REVERSE); //Back up //100,-55
//backFlap.set_value(false);

arms::chassis::move({85, -58}, 90, arms::REVERSE); //Back up //100,-55

arms::chassis::turn(-110, 80);

flapL.set_value(true);
flapR.set_value(true);

arms::chassis::move({80, -88}, 100);    //Goal slam 3
pros::delay(50);
flapL.set_value(false);
flapR.set_value(false);

arms::chassis::move({90, -80}, 80, arms::REVERSE);   //Back up to far position
arms::chassis::move({130, -80}, 80, arms::REVERSE);   //Back up to far position



        cataMotor.moveVoltage(6000);

arms::chassis::move({130, -52}, 100);      //Drive to other side
hangLeft.set_value(true);
hangRight.set_value(true);
    cataMotor.moveVoltage(0);

arms::chassis::move({131, -32}, 100);      //Drive to other side
hangLeft.set_value(false);
hangRight.set_value(false);

}

//arms::chassis::turn(135);
//pros::delay(75);
//arms::chassis::move({120, -75}, 90, arms::REVERSE);   //Push triballs
//arms::chassis::turn(180);
//pros::delay(150);
//arms::chassis::move({134, -75}, 90, arms::REVERSE);   //Back up to wall

//arms::chassis::turn(55);

//arms::chassis::move({110, -107}, 90, arms::REVERSE);   //Back up to goal position
//arms::chassis::turn(0, 90);
//arms::chassis::move({100, -111}, 100, arms::REVERSE);   //Back up to goal position