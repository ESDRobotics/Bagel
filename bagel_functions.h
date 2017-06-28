#include <kipr/botball.h>
#include <stdio.h>

// ports
#define lifter 1
#define claw 0


// servo positions
#define grab 420
#define drop 690 //780 to 690 -wm
#define carry 900
#define open_claw 900 //900
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
        speed = 150; }
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
    double turn_time = degrees*18.125;
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
   set_lifter(grab, 5);
	set_claw(close_claw, 10);
    create_drive_distance(2);
    set_lifter(carry, 5);
}

void setup(){
    printf("Setup\n");
    create_disconnect();
    create_connect();
    create_drive_distance(5);
    create_turn(183, clockwise); //180 to 183 -wm
    set_servo_position(lifter, 2047);
    set_servo_position(claw, open_claw);
    set_servo_position(2, 703);
    enable_servos();
    msleep(1000);
    //wait_for_light(5);
    shut_down_in(119);
    set_lifter(grab, 5); //10 to 5
	set_claw(close_claw, 12); //25 to 12
    set_lifter(carry, 5); // 10 to 5
    create_turn(93, clockwise);
    create_drive_straight(-100);
    msleep(1000);
    create_stop();
}
int segment = 2;
void grab234(){
    printf("Grab234\n");
    create_drive_distance_back(10);
    int dist = 2100;
    if(segment == 3){
      printf("Closer!");
      dist == 2000;
    }
    while(analog(0) < dist){ //2100 to 2300
    create_drive_straight(-100);
    segment++;
    }
    create_stop();
    create_turn(2.5, clockwise);
    msleep(400);
    set_lifter(drop, 10);
    set_claw(open_claw, 10);
    create_turn(5, clockwise);
    msleep(200);
    set_lifter(grab, 10);
    printf("CDS(-100)");
    create_drive_straight(-100);
    msleep(350);
    create_stop();
    create_turn(5, counter_clockwise);
    grab_cube();
    create_turn(5, counter_clockwise);
    create_drive_distance(5);
}


void get_cube(){
    printf("Get_Cube\n");
    create_drive_distance(53); //56 to 53
    create_turn(80, clockwise); //88 to 80 -wm
    create_drive_straight(-100);
    msleep(2000);
    create_drive_distance(4); //was 5
    msleep(200); //added
    create_drive_straight(90); //added
    msleep(1000); //added
    create_turn(4, counter_clockwise);
    create_drive_distance(185);
    create_turn(180, clockwise); // 170 to 180
    create_drive_straight(-100);
    msleep(3000);
    create_stop();
    create_drive_distance(5);
    create_turn(85, counter_clockwise); //80 to 85
    create_drive_distance(15); //40 to 15 -wm
    grab234();
}
int has_three = 0;
void cube34(){
    printf("Cube34\n");
    create_drive_distance(10);
    create_turn(90, clockwise);
    create_drive_distance(15); // 18 to 15
    create_turn(90, counter_clockwise);
    if(has_three==0){
   		grab234();
  		has_three = 1;
    }
}

void drop_cubes(){
    printf("Drop_cubes\n");
    create_drive_distance(30); //40 to 30 -wm (in order to avoid stuff)
    create_turn(180, clockwise);
    set_lifter(grab, 10);
    set_claw(open_claw, 25);
    create_turn(5, clockwise);
    create_drive_distance(25);//20 to 25 -wm
    create_turn(90, clockwise); //85 to 90
    create_stop();
}

void create_dump_water(double target_distance, int power) {
    int current_distance = 0;
    int speed = 0;

    // convert distance to values that work for create
    if(target_distance<=50){
        target_distance*=10.5132; // 1.12
    	speed = power; }
    else if(target_distance<=100){
        target_distance*=9.9103; // 1.1459
        speed = power; }
    else if(target_distance<=150){
        target_distance*=10.0654; // 1.1634
        speed = power; }
    else if(target_distance<=200){
        target_distance*=9.9437; // 1.163
    	speed = power; }
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

void shoot(){
    msleep(1500);
	  set_servo_position(2, 1437);
    msleep(1000);
    create_dump_water(5, 300);
    create_drive_distance_back(25);
    create_dump_water(15, 300);
    create_drive_distance_back(25);
    create_dump_water(15, 300);
}

void bully_the_other_team(){
    set_lifter(carry,10);
	create_drive_distance_back(59); //65 to 58 to 53 to 59
 	create_turn(90,clockwise);
    create_drive_distance_back(35);
    create_drive_distance(6);
    create_turn(140,clockwise);
}
