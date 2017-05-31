#include <kipr/botball.h>
#include <stdio.h>

// ports
#define lifter 1
#define claw 0

// servo positions
#define grab 440
#define drop 820
#define carry 900
#define open_claw 900
#define close_claw 1900

// delays
#define slow 50
#define medium 30
#define fast 20

// directions
#define clockwise 1
#define counter_clockwise -1

/* 
    NOTE: THIS FUNCTION DOES NOT WORK CORRECTLY ON BAGEL
    Purpose: drives create given distance (cm) at given speed
    Arguments: speed to travel at, distance to travel (cm)
*/
void create_drive_distance(double target_distance) {
    int current_distance = 0;
    int speed = 0;

    // convert distance to values that work for create
    if(target_distance<=50){
        target_distance*=10.5132; // 1.12
    	speed = 100; }
    else if(target_distance<=100){
        target_distance*=9.9103; // 1.1459
        speed = 200; }
    else if(target_distance<=150){ 
        target_distance*=10.0654; // 1.1634
        speed = 300; }
    else if(target_distance<=200){
        target_distance*=9.9437; // 1.163
    	speed = 500; }
    else
        target_distance*=1.2059; // 1.1823
    
    set_create_distance(0);
    while(current_distance < target_distance) {
        create_drive_straight(speed);
        msleep(10);
        current_distance = get_create_distance();
    }
    
    create_stop();
}
/* 
    Purpose: turns create for given degrees in given direction
    Arguments: degrees to turn, speed of turn, direction of turn
*/
void create_turn(int degrees, int direction) {
    // converts degrees to msleep time
    double turn_time = degrees * 18.125;
    int speed = 100 * direction;
    
    create_spin_CW(speed); 
    msleep(turn_time);

    create_stop();
}

/* 
    Purpose: sets claw to given position
    Arguments: position to go to, travel delay (bigger values == bigger delay/slower)
*/
void set_claw(int position, int delay) {
    int current_pos = get_servo_position(claw);
    while(current_pos > position) {
        set_servo_position(claw, current_pos);
        msleep(delay);
        current_pos -= 5;
    }

    while(current_pos < position) {
        set_servo_position(claw, current_pos);
        msleep(delay);
        current_pos += 5;
    }
    set_servo_position(claw, position);
}

/* 
    Purpose: sets lifter to given position
    Arguments: position to go to, travel delay (bigger values == bigger delay/slower)
*/
void set_lifter(int position, int delay) {
    int current_pos = get_servo_position(lifter);
    while(current_pos > position) {
        set_servo_position(lifter, current_pos);
        msleep(delay);
        current_pos -= 5;
    }

    while(current_pos < position) {
        set_servo_position(lifter, current_pos);
        msleep(delay);
        current_pos += 5;
    }
    set_servo_position(lifter, position);
}

void create_drive_distance_back(double distance){
    distance *= 1000;
    distance = distance/11.4;
    create_drive_straight(-100);
    msleep(distance);
    create_stop();
}

void grab_cube(){
   set_lifter(grab, 10);
	set_claw(close_claw, 10);
    create_drive_distance(2);
    set_lifter(carry, 10);
}

void drop_cube(){
    set_lifter(drop, 25);
    set_claw(open_claw, 10);
}

void setup(){
    create_disconnect();
    create_connect();
    create_drive_distance(5);
    create_turn(180, clockwise);
    set_servo_position(lifter, 2047);
    set_servo_position(claw, open_claw);
    enable_servos();
    //wait_for_light(5);
    shut_down_in(119);
    set_lifter(grab, 25);
	set_claw(close_claw, 25);
    set_lifter(carry, 25);
    create_turn(93, clockwise);
    create_drive_straight(-100);
    msleep(1000);
    create_stop();
}

void grab234(){
    create_drive_distance_back(10);
    while(analog(0) < 2100){
    create_drive_straight(-100);
    }
    create_stop();
    create_turn(5, clockwise);
    drop_cube();
    create_turn(5, clockwise);
    msleep(200);
    set_lifter(grab, 25);
    create_drive_straight(-100);
    msleep(350);
    create_stop();
    create_turn(5, counter_clockwise);
    grab_cube();
    create_turn(5, counter_clockwise);
    create_drive_distance(5); 
}


void get_cube(){
    create_drive_distance(63);
    create_turn(88, clockwise);
    create_drive_straight(-100);
    msleep(2000);
    create_drive_distance(5);
    create_turn(5, counter_clockwise);
    create_drive_distance(185);
    create_turn(176, clockwise);
    create_drive_straight(-100);
    msleep(3000);
    create_stop();
    create_drive_distance(5);
    create_turn(90, counter_clockwise);
    create_drive_distance(40);
    grab234();
}

void cube34(){
    create_drive_distance(10);
    create_turn(90, clockwise);
    create_drive_distance(18);
    create_turn(90, counter_clockwise);
    grab234();
}   
    
void setup_mod(){
    create_disconnect();
    create_connect();
    create_drive_distance(6.5);
    create_turn(180, clockwise);
    set_servo_position(lifter, carry);
    set_servo_position(claw, 1200);
    enable_servos();
    //wait_for_light(5);
    msleep(2000);
    grab_cube();
    create_turn(88, clockwise);
}

void drop_cubes(){
    create_drive_distance(40);
    create_turn(180, clockwise);
    set_lifter(grab, 25);
    set_claw(open_claw, 25);
    create_turn(5, clockwise);
    create_drive_distance(20);
    create_turn(85, clockwise);
    create_stop();
}
    
void main_program(){
    setup();
    get_cube();
    cube34();
    cube34();
    drop_cubes();
    create_disconnect();
}
