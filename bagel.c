#include <stdio.h>
#include <kipr/botball.h>
#include <create_lib.h>
#include <bagel_functions.h>

int main() {
    create_disconnect();
    create_connect();

    // Move forward until a bumper is collided
    while(get_create_lbump() == 0 && get_create_lbump() == 0) {
        create_drive_straight(100);
    }

    // just add a basic comment over each section describing WHY it 
    // is doing what it is doing
    create_turn(4,-1);
    msleep(10);

    set_servo_position(0,0);
    enable_servos();
    msleep(10);

    move_servo(0, 1800, fast);
    motor(0,-44);
    msleep(3275);
    ao();
    msleep(10);
    
    move_servo(0, 750, slow);
    msleep(100);
    move_servo(0, 900, slow);
    msleep(1000);
    create_turn(1, -1);
    create_drive_straight(-50);
    
    move_servo(0,50,fast);
    msleep(1000);
    
    // Raise winch
    // while(right_button() != 1){msleep(10);}
    // msleep(1000);
    
    motor(0,100);
    msleep(1000);
    motor(0,2);
    
    // no function named right button ??
    while(right_button() != 0) {
        msleep(10);
    }

    printf("Battery: %d,%d", get_create_battery_charge(), get_create_battery_capacity());
    create_disconnect();

    return 0; 
}
