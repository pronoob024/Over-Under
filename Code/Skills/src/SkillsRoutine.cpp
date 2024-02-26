#include "main.h"


void skillsroutine() {

arms::odom::reset({0, 0}, 225);   //Reset

arms::chassis::move({22, 11}, 100, arms::REVERSE);   //Push preload into goal
arms::chassis::move({32, 11}, 100, arms::REVERSE);   //Push preload into goal

arms::chassis::move({13, 11, 123}, 70);    //Move to loading position
//arms::chassis::move({13, 12, 123}, 70);    //Move to loading position

arms::chassis::turn(122.5, 80);           /////////

flapL.set_value(true);   //Open flap for match loading

cataMotor.moveVoltage(12000);   //Match loading
//pros::delay(28000);         //30 seconds
pros::delay(3000);         //1 second //for testing

cataMotor.moveVoltage(0);       //Stop catapult

flapL.set_value(false);
intakeMotor.moveVoltage(-12000);

arms::chassis::turn(45, 75);
arms::chassis::move({3, -25}, 70, arms::REVERSE);      //Drive to other side
arms::chassis::move({4, -80}, 80, arms::REVERSE);      //Drive to other side
pros::delay(50); 

arms::chassis::move({22, -102}, 80, arms::REVERSE);      //Side goal slam
arms::chassis::move({40, -102}, 90, arms::REVERSE);      //Side goal slam


pros::delay(150);

arms::chassis::move({28, -90}, 80);     //Drive away from goal
intakeMotor.moveVoltage(-4000);

arms::chassis::move({46, -59});    //Drive to center bar //55 to 43

intakeMotor.moveVoltage(-12000);

//arms::chassis::turn(-80, 80);
arms::chassis::turn(-90, 80);

flapR.set_value(true);

//arms::chassis::move({50, -75}, 90);    //Goal slam 1
arms::chassis::move({57, -89}, 90);    //Goal slam 1

pros::delay(100);
flapR.set_value(false);
flapL.set_value(false);
pros::delay(250);

arms::chassis::move({54, -62}, 90, arms::REVERSE);   //Back up
arms::chassis::move({68, -62}, 90);   //Back up
arms::chassis::turn(-90);
flapR.set_value(true);

arms::chassis::move({68, -93}, 100);    //Goal slam 2
flapL.set_value(false);
flapR.set_value(false);
pros::delay(100);

arms::chassis::move({66, -62}, 90, arms::REVERSE); //Back up
arms::chassis::move({79, -65}, 90); //Back up //100,-55

//arms::chassis::move({95, -70}, 90); //Back up //100,-55

arms::chassis::turn(-110, 80);

flapL.set_value(true);
flapR.set_value(true);


arms::chassis::move({72, -103}, 100);    //Goal slam 3
flapL.set_value(false);
flapR.set_value(false);
pros::delay(100);

//arms::chassis::move({60, -60}, 90, arms::REVERSE);   //Back up



arms::chassis::move({72, -90}, 90, arms::REVERSE);   //Back up to far position



arms::chassis::move({125, -96}, 100);      //Drive to match load bar
arms::chassis::turn(-45);
flapR.set_value(true);
arms::chassis::move({110, -117}, 100);    //Goal slam side
arms::chassis::move({92, -117}, 100);    //Goal slam side
arms::chassis::move({110, -117}, 100, arms::REVERSE);    //Goal slam side
arms::chassis::move({92, -117}, 100);    //Goal slam side

flapR.set_value(false);
arms::chassis::move({120, -80}, 100, arms::REVERSE | arms::ASYNC);      //Drive to elevate
while (!cataLimit.isPressed()) {        //Lowering cata to prepare for hang
    cataMotor.moveVoltage(10000);
}
cataMotor.moveVoltage(0);
arms::chassis::waitUntilFinished(0);


arms::chassis::turn(120, 80);   //Turn to elevation bar
pros::delay(80);

hangLeft.set_value(true);
hangRight.set_value(true);

arms::chassis::move({114, -44}, 100);      //Drive to elevate
hangLeft.set_value(false);
hangRight.set_value(false);

}