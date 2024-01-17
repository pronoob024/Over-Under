#include "main.h"


void skillsroutine() {

arms::odom::reset({0, 0}, 225);   //Reset

arms::chassis::move({22, 11}, 100, arms::REVERSE);   //Push preload into goal
arms::chassis::move({32, 11}, 100, arms::REVERSE);   //Push preload into goal

arms::chassis::move({13, 12, 123}, 70);    //Move to loading position

arms::chassis::turn(123, 80);           /////////

flapL.set_value(true);   //Open flap for match loading

cataMotor.moveVoltage(12000);   //Match loading
pros::delay(28000);         //30 seconds
//pros::delay(1000);         //1 second //for testing

cataMotor.moveVoltage(0);       //Stop catapult

flapL.set_value(false);
intakeMotor.moveVoltage(-12000);

arms::chassis::turn(45, 75);


arms::chassis::move({3, -25}, 70, arms::REVERSE);      //Drive to other side
arms::chassis::move({4, -82}, 80, arms::REVERSE);      //Drive to other side
pros::delay(50); 

arms::chassis::move({22, -104}, 80, arms::REVERSE);      //Side goal slam
arms::chassis::move({40, -104}, 80, arms::REVERSE);      //Side goal slam

arms::chassis::move({30, -104}, 80);      //Side goal slam
arms::chassis::move({40, -104}, 80, arms::REVERSE);      //Side goal slam

pros::delay(250);

arms::chassis::move({33, -90}, 80);     //Drive away from goal

//flapR.set_value(true);
arms::chassis::move({50, -57});    //Drive to center bar //55 to 43
arms::chassis::move({62, -56});    //Drive to center bar //55 to 43

intakeMotor.moveVoltage(-12000);


arms::chassis::turn(-80, 80);
//flapL.set_value(true);
flapR.set_value(true);

arms::chassis::move({62, -87}, 100);    //Goal slam 1
arms::chassis::move({62 -89}, 70);    //Goal slam 1
//arms::chassis::move({62 -86}, 70, arms::REVERSE);    //Goal slam 1
//arms::chassis::move({62 -89}, 100);    //Goal slam 1

pros::delay(100);
flapR.set_value(false);
flapL.set_value(false);
arms::chassis::move({60, -55}, 90, arms::REVERSE); //Back up
flapL.set_value(true);
arms::chassis::move({95, -55}, 90); //Back up //100,-55

arms::chassis::turn(-110, 80);

flapL.set_value(true);
flapR.set_value(true);

arms::chassis::move({80, -62}, 70);    //Goal slam 2
arms::chassis::move({80, -88}, 90);    //Goal slam 2
pros::delay(100);
flapL.set_value(false);
flapR.set_value(false);

arms::chassis::move({65, -60}, 90, arms::REVERSE);   //Back up

flapL.set_value(true);
flapR.set_value(true);

arms::chassis::move({64, -90}, 100);    //Goal slam 3
flapL.set_value(false);
flapR.set_value(false);

arms::chassis::move({100, -55}, 80, arms::REVERSE);   //Back up to far position

arms::chassis::turn(135);
pros::delay(75);
arms::chassis::move({120, -75}, 80, arms::REVERSE);   //Push triballs
arms::chassis::turn(180);
pros::delay(150);
arms::chassis::move({142, -75}, 80, arms::REVERSE);   //Back up to wall

arms::chassis::turn(45);

arms::chassis::move({130, -111}, 80, arms::REVERSE);   //Back up to goal position
arms::chassis::turn(0, 70);

arms::chassis::tank(-100,-100);   //Slam into side of goal
intakeMotor.moveVoltage(0);
pros::delay(800);

arms::chassis::tank(100,100);   //Move away from goal
pros::delay(500);
arms::chassis::tank(0,0);   //Stop moving away
}

