#include <stdio.h>
#include <kipr/botball.h>

#define slow 20
#define medium 15
#define fast 10
#define lift_motor 1
#define claw_motor 0

/* 
Function Purpose: This function turns the create in either clockwise or 
counter-clockwise directions for a specific number of degrees.

Arguments: degrees to turn, direction to turn
*/
void create_turn(int degrees, int direction) {
    double turn_time = degrees * 18.125; //Converts the angle into the turn_time
    int speed = 100 * direction;
    
    create_spin_CW(speed); 
    msleep(turn_time);
    create_stop();
}

/* 
Function Pupose: This function moves the create forward a certain distance 
fairly accurately in centimeters at a certain speed.

Arguments: speed to travel at, distance to travel in cm
*/
void create_drive_distance(int speed, double target_distance) {
    int current_distance = 0;

    if(target_distance<=50)
        target_distance*=1.1424; // used to be: 1.12
    else if(target_distance<=100)
        target_distance*=1.1688; // used to be: 1.1459
    else if(target_distance<=150)            
        target_distance*=1.1867; // used to be: 1.1634   
    else if(target_distance<=200)
        target_distance*=1.1863; // used to be: 1.163
    else
        target_distance*=1.2059; // used to be: 1.1823
    
    set_create_distance(0);
    while(current_distance < target_distance) {
        create_drive_straight(speed);
        msleep(10);
        current_distance = get_create_distance();
    }
    
    create_stop();
}

/* 
Function Purpose: This function moves a specific servo to a certain position 
at the desired speed.

Arguments: port number of servo, position to go to, speed of servo movement
*/
void move_servo(int port, int position, int speed){
    int current_pos = get_servo_position(port);
    if(position < current_pos) { 
        for(current_pos; current_pos > position; current_pos -= 10) {
            set_servo_position(port,current_pos);
            msleep(speed);
        }
    }

    if(position > current_pos) {
        for(current_pos; current_pos < position; current_pos += 10) {
            set_servo_position(port,current_pos);
            msleep(speed);
        }
    }
}

/* 
Function Purpose: This function lowers the claw.

Arguments: speed of claw movement
*/
void high_claw(int speed) {
    while(accel_x() < 800) {
        motor(lift_motor, speed);
        msleep(10);
    }

    motor(lift_motor, 1);
}

/* 
Function Purpose: This function returns the claw to the middle.

Arguments: speed of claw movement
*/
void mid_claw(int speed) {
    // raises claw if lower than desired position
    while(accel_x() < 0) {
        motor(lift_motor, speed);
        msleep(10);
    }

    // lowers claw if higher than desired position
    while (accel_x() > 5) {
        motor(lift_motor, speed*-1);
        msleep(10);
    }

    motor(lift_motor,1);
}

/* 
Function Name: Low_claw
Function Purpose: This function lowers the claw.

Arguments: speed of claw movement
*/
void low_claw(int speed) {
    // lowers claw until at desired position
    while(accel_x() > -400) {
        motor(lift_motor, speed*-1);
        msleep(10);
    }
    
    motor(lift_motor,1);
}