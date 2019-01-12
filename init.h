#include "api.h"
#include "main.h"
#pragma once
extern int rpm;
extern pros::Controller master;
extern pros::Motor mtr1;
extern pros::Motor mtr2;
extern pros::Motor mtr3;
extern pros::Motor mtr4;
extern pros::Motor fly1;
extern pros::Motor fly2;
extern pros::Motor intake;
extern pros::Motor flipper;
extern pros::Vision vision_sensor;
extern pros::ADIDigitalIn limit;
void power_down_flywheel();
void power_up_flywheel();
void sensor();
extern pros::Task pwrup;
extern pros::Task pwrdwn;
