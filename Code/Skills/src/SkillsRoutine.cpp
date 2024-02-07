#include "main.h"




void skillsroutine() {
arms::odom::reset({0, 0}, 225);   //Reset

arms::chassis::move({20, 11}, 100, 6, arms::REVERSE);
arms::chassis::move({26, 11}, 100, arms::REVERSE | arms::THRU);

arms::chassis::move({16.5, 11}, 100);    //Move to loading position

arms::chassis::turn(114, 100);           /////////121 111 114 118
flapL.set_value(true);   //Open flap for match loading
cataMotor.moveVoltage(12000);   //Match loading

pros::delay(28000);         //28 seconds
//pros::delay(1000);         //1 second //for testing
cataMotor.moveVoltage(0);       //Stop catapult

flapL.set_value(false);
arms::chassis::turn(0, 100);
intakeMotor.moveVoltage(-12000);


//arms::chassis::turn(45, 90);

arms::chassis::move({8, -15}, 100, 6, arms::REVERSE | arms::THRU);      //Drive to other side

arms::chassis::move({4, -25}, 100, 6, arms::REVERSE | arms::THRU);      //Drive to other side
arms::chassis::move({4, -82}, 100, 6, arms::REVERSE | arms::THRU);      //Drive to other side
//pros::delay(50); 

arms::chassis::move({22, -101}, 100,6, arms::REVERSE | arms::THRU);      //Side goal slam
arms::chassis::move({35, -101}, 100, arms::REVERSE);      //Side goal slam


arms::chassis::move({20, -90}, 80);     //Drive away from goal
arms::chassis::move({40, -58});    //Drive to center bar //55 to 43
arms::chassis::move({50, -56});    //Drive to center bar //55 to 43

intakeMotor.moveVoltage(-12000);
arms::chassis::turn(-85, 80);
//flapL.set_value(true);
// flapR.set_value(true);

arms::chassis::move({50, -90}, 100);    //Goal slam 1  87

//flapR.set_value(false);
//flapL.set_value(false);
pros::delay(100);
arms::chassis::move({54, -58}, 90, arms::REVERSE); //Back up

//arms::chassis::move({70, -58}, 90, arms::REVERSE); //Back up
//flapR.set_value(true);
//arms::chassis::move({56, -89}, 100);    //Goal slam 2
//flapR.set_value(false);

arms::chassis::move({65, -58}, 90, arms::REVERSE); //Back up
flapL.set_value(true);
flapR.set_value(true);
arms::chassis::move({56, -89}, 100);    //Goal slam 2
flapR.set_value(false);
flapL.set_value(false);

arms::chassis::move({70, -58}, 90, arms::REVERSE); //Back up //100,-55

arms::chassis::move({85, -58}, 90, arms::REVERSE); //Back up //100,-55

arms::chassis::turn(-110, 80);

flapL.set_value(true);
flapR.set_value(true);

arms::chassis::move({73, -88}, 100);    //Goal slam 3
flapL.set_value(false);
flapR.set_value(false);
pros::delay(50);

arms::chassis::move({70, -50}, 90, arms::REVERSE);   //Back up
arms::chassis::move({50, -50}, 90, arms::REVERSE);   //Back up

flapL.set_value(true);
flapR.set_value(true);
arms::chassis::move({50, -89}, 100);    //Goal slam 4
flapL.set_value(false);
flapR.set_value(false);
//arms::chassis::move({90, -80}, 90, arms::REVERSE);   //Back up to far position
//arms::chassis::move({130, -80}, 90, arms::REVERSE);   //Back up to far position

arms::chassis::move({40, -70}, 90, arms::REVERSE);   //Back up to far position
arms::chassis::move({4, -80}, 90, arms::REVERSE);   //Back up to far position

pros::Task lowerCata( []{
    while (!cataLimit.isPressed()) {
    cataMotor.moveVoltage(12000);
    pros::delay(20);
    }
cataMotor.moveVoltage(0);
});

arms::chassis::turn(90);
arms::chassis::move({2, -52}, 100);      //Drive to elevation bar 130
hangLeft.set_value(true);
hangRight.set_value(true);

arms::chassis::move({2, -32}, 100);      //Drive to elevate 131
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