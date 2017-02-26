#include <stdio.h>
#include <kipr/botball.h>
#include <bagel_functions.h>

int main() {
    create_disconnect();
    create_connect();
    set_lifter(high, 50);

    set_servo_position(0, 700);
    enable_servos();

    while(get_create_lbump() == 0 && get_create_lbump() == 0) { create_drive_straight(75); }
    create_stop();

    create_drive_straight(-100);
    msleep(200);
    create_stop();

    create_turn(15, 100, clockwise);

    set_claw(1550, fast);
    msleep(500);

    set_lifter(mid, 50);
    set_lifter(low + 70, 20);
    msleep(500);
    
    set_claw(800, fast);
    msleep(500);
    set_claw(1200, fast);
    msleep(500);

    set_claw(800-(1*160), fast);
    msleep(500);
    set_claw(1200, fast);
    msleep(500); 
    create_turn(5, 100, counter_clockwise);

    set_claw(800-(1*160), fast);
    msleep(500);
    set_claw(1200, fast);
    msleep(500); 
    create_turn(5, 100, counter_clockwise);

    set_claw(800-(2*160), fast);
    msleep(500);
    set_claw(1200, fast);
    msleep(500); 

    return 0; 
}
