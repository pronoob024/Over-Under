#include "main.h"

void ElimsCloseSideSAFE() {
arms::odom::reset({0, 0}, 225);   //Reset

arms::chassis::move({22, 11}, 100, 1, arms::REVERSE);   //Push preload into goal
arms::chassis::move({32, 11, 180}, 60, arms::REVERSE);   //Push preload into goal

arms::chassis::move({1, 1}, 65, arms::ASYNC);    //Drive to matchload bar
}