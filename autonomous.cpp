#include "main.h"
#include "init.h"
/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
 int rb = -1; // 1 for blue; -1 for red

 void movebase(int l, int r) {
  mtr3.move(l);
  mtr4.move(l);
  mtr1.move(r);
  mtr2.move(r);
 }

 void moveticks(int l, int vl, int r, int vr) {
  mtr3.move_relative(l, vl);
  mtr4.move_relative(l, vl);
  mtr1.move_relative(r, vr);
  mtr2.move_relative(r, vr);
 }

 void Flag() {
   pwrup.suspend();
   pwrdwn.suspend();
   pros::delay(25);

//shoots top flag
   pwrup.resume();
   pros::delay(4000);
   intake.move_velocity(-200);
   pros::delay(1000);
   intake.move(0);
   pros::delay(1);

//turns toward cap
   moveticks(-880 * rb, -100 * rb, 880 * rb, 100 * rb);
   pros::delay(1500);
//goes forward
   moveticks(3000, 150, 3000, 150);
   intake.move(-50);
   pros::delay(2000);
//drive stops moving and gets ball
   intake.move_velocity(-170);
   pros::delay(700);
   intake.move_velocity(0);
   pros::delay(1);
//goes backward
   moveticks(-3000, -150, -3000, -150);
   pros::delay(1500);

   moveticks(1000 * rb, 100 * rb, -1000 * rb, -100 * rb);
   pros::delay(1300);

   moveticks(1600, 150, 1600, 150);
   pros::delay(1500);

   intake.move_velocity(-200);
   pros::delay(1100);
   intake.move(0);

   moveticks(1000, 200, 1000, 200);
   pros::delay(1000);
   movebase(0, 0);
   intake.move(0);

   pwrup.suspend();
   pwrdwn.resume();
 }

 void blueAlliance() {
   pwrup.resume();
   pros::delay(4000);
   intake.move(-120);
   pros::delay(2000);
   pwrup.suspend();
   pwrdwn.resume();
   pros::delay(1000);
   pwrdwn.suspend();
   if(true) {
     moveticks(-900, -100, 900, 100);
     pros::delay(1500);
     moveticks(3000, 100, 3000, 100);
     pros::delay(3000);
     moveticks(900, 100, -900, -100);
     pros::delay(1500);
     moveticks(-1500, -100, -1500, -100);
     movebase(0, 0);
   }
 }

//blue side
 /*void skills() {
   pwrup.suspend();
   pwrdwn.suspend();
   pros::delay(25);

   pwrup.resume();
   pros::delay(4000);
   intake.move_velocity(-200);
   pros::delay(1000);
   intake.move(0);
   pros::delay(1);

   moveticks(-880 * rb, -100 * rb, 880 * rb, 100 * rb);
   pros::delay(1500);

   moveticks(3000, 150, 3000, 150);
   intake.move(-50);
   pros::delay(2000);

   intake.move_velocity(-170);
   pros::delay(700);
   intake.move_velocity(0);
   pros::delay(1);

   moveticks(-2900, -150, -2900, -150);
   pros::delay(1600);

   moveticks(900 * rb, 100 * rb, -900 * rb, -100 * rb);
   pros::delay(1300);

   moveticks(1600, 150, 1600, 150);
   pros::delay(1500);

   intake.move_velocity(-200);
   pros::delay(1100);
   intake.move(0);

   moveticks(1000 * rb, 100 * rb, -1000 * rb, -100 * rb);
   pros::delay(1300);

   moveticks(500, 100, 500, 100);
   pros::delay(700);

   flipper.move(-100);
   pros::delay(500);

   moveticks(-800, -100, -800, -100);
   pros::delay(800);

   flipper.move(127);
   pros::delay(1000);

   moveticks(0, 0, 800, 100);
   pros::delay(800);

   moveticks(-800, -100, -800, -100);
   pros::delay(800);

   moveticks(900, 100, -900, -100);
   pros::delay(1200);

   moveticks(1500, 150, 1500, 150);
   pros::delay(1500);

   moveticks(900, 100, -900, -100);
   pros::delay(1200);

   moveticks(3000, 150, 3000, 150);
   intake.move(127);
   pros::delay(2000);

   moveticks(-3000, -150, -3000, -150);
   pros::delay(2000);

   moveticks(800, 100, 800, 100);
   pros::delay(800);

   moveticks(-900, -100, 900, 100);
   pros::delay(1200);

   moveticks(1500, 150, 1500, 150);
   pros::delay(1500);

   moveticks(1000, 100, -1000, -100);
   pros::delay(1300);

   moveticks(3000, 150, 3000, 150);
   intake.move(127);
   pros::delay(2000);

 }*/
 //red side
 void skills() {
   pwrup.suspend();
   pwrdwn.suspend();
   pros::delay(25);

   pwrup.resume();
   pros::delay(4000);
   intake.move_velocity(-200);
   pros::delay(1000);
   intake.move(0);
   pros::delay(1);

   moveticks(-880 * rb, -100 * rb, 880 * rb, 100 * rb);
   pros::delay(1500);

   moveticks(3000, 150, 3000, 150);
   intake.move(-50);
   pros::delay(2000);

   intake.move_velocity(-170);
   pros::delay(700);
   intake.move_velocity(0);
   pros::delay(1);

   moveticks(-2900, -150, -2900, -150);
   pros::delay(1600);

   moveticks(-900 * rb, -100 * rb, 900 * rb, 100 * rb);
   pros::delay(1300);

   moveticks(1600, 150, 1600, 150);
   pros::delay(1500);

   intake.move_velocity(-200);
   pros::delay(1100);
   intake.move(0);

   moveticks(-1000 * rb, -100 * rb, 1000 * rb, 100 * rb);
   pros::delay(1300);

   moveticks(500, 100, 500, 100);
   pros::delay(700);

   flipper.move(-100);
   pros::delay(500);

   moveticks(-800, -100, -800, -100);
   pros::delay(800);

   flipper.move(127);
   pros::delay(1000);

   moveticks(0, 0, 800, 100);
   pros::delay(800);

   moveticks(-800, -100, -800, -100);
   pros::delay(800);

   moveticks(-900, -100, 900, 100);
   pros::delay(1200);

   moveticks(1500, 150, 1500, 150);
   pros::delay(1500);

   moveticks(-900, -100, 900, 100);
   pros::delay(1200);

   moveticks(3000, 150, 3000, 150);
   intake.move(127);
   pros::delay(2000);

   moveticks(-3000, -150, -3000, -150);
   pros::delay(2000);

   moveticks(800, 100, 800, 100);
   pros::delay(800);

   moveticks(900, 100, -900, -100);
   pros::delay(1200);

   moveticks(1500, 150, 1500, 150);
   pros::delay(1500);

   moveticks(-1000, -100, 1000, 100);
   pros::delay(1300);

   moveticks(3000, 150, 3000, 150);
   intake.move(127);
   pros::delay(2000);

 }

 void no_auton() {}

void autonomous() {
  rpm = 200;
  //skills();
  Flag();
}
