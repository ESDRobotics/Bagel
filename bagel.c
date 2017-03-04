#include <stdio.h>
#include <kipr/botball.h>
#include <bagel_functions.h>

int main() {
    create_disconnect();
    create_connect();
    
    set_servo_position(0, 700);
    enable_servos();
    
    set_lifter(high - 50, 50);
    
    //create_turn(5, 100, counter_clockwise);

    while(get_create_lbump() == 0 && get_create_lbump() == 0) { create_drive_straight(100); }
    create_stop();

    create_drive_straight(0);
    msleep(200);
	create_turn(10,100, counter_clockwise);
    create_stop();
    
    set_claw(1550, fast);
    msleep(500);

    set_lifter(mid, 50);
    set_lifter(low - 20, 20);
    msleep(500);
    
    set_claw(800, fast);
    msleep(500);
    set_claw(1200, fast);
    msleep(500);
    create_turn(5, 100, counter_clockwise);

   set_claw(800-(1*160), fast);
    msleep(500);
    set_claw(1200, fast);
    msleep(500);

    /*set_claw(800-(1*160), fast);
    msleep(500);
    set_claw(1200, fast);
    msleep(500); 

    set_claw(800-(2*160), fast);
    msleep(500);
    set_claw(1200, fast);
    msleep(500); */

    set_lifter(low+40, 20);
    set_claw(600, fast);
    msleep(500);
    set_claw(200, fast);
    msleep(1000);
    //set_claw(100, fast);
    //msleep(2000);

    set_lifter(high - 50, 20);

    create_drive_straight(-100);
    msleep(1500);

    create_turn(155,60,clockwise);
    //create_turn(490, 60, counter_clockwise);
    msleep(500);

    //drive forward and lower claw
    create_drive_distance(150, 600);
    msleep(200);
    create_turn(20, 100, counter_clockwise);
    msleep(200);
    set_lifter(mid, 40);
    create_drive_distance(100, 600);
    msleep(500);

    //Turn right into the drop location
    create_turn(80, 100, clockwise);

    //drive backward, lower claw, and open servor to drop hay bales
    create_drive_straight(-100);
    msleep(900);    
    create_stop();
    msleep(500);
    set_lifter(low, 20);
    set_claw(mid, slow);  
    msleep(1000);
    create_drive_straight(100);
    msleep(300);    
    set_claw(500, fast);
    
    /*
    //Get blue ball
    create_drive_straight(100);
    msleep(550);
    create_stop();
    set_lifter(-400, 70);
    msleep(500);
    set_claw(500, fast);
    create_turn(270, 100, counter_clockwise);
    create_drive_straight(130);
    msleep(2000);
    create_stop();
    set_lifter(high - 100, 70);
    msleep(500);
    set_claw(1000, fast);
    create_turn(90, 100, clockwise);
    set_claw(500, fast);
    */

    //Second Set of Hay Bales
    
    //raise claw, turn back, drive forward, and turn towards the next bale group
   
    create_stop();
    set_lifter(-450, 70);
    msleep(500);
    create_turn(100, 100, counter_clockwise);
    create_drive_straight(100);
    msleep(2200);
    create_stop();
    create_turn(80, 100, counter_clockwise);
    create_drive_straight(-100);
    msleep(1500);
    create_stop();

    //back up, open claw, lower the claw, grab a single cube
    msleep(100);
    set_claw(750, medium);
    msleep(500);
    set_lifter(low+20, 20);
    msleep(500);
    create_stop();
    set_claw(100, fast);
    
    //raise claw, and reverse previous commands
    set_lifter(medium - 200, 40);

    msleep(500);
    
    create_drive_straight(-100);
    msleep(200);
    create_turn(90, 100, clockwise);
    create_drive_straight(-200);
    msleep(1500);
    create_stop();

    //turn towards drop location again and drop
    create_turn(95, 100, clockwise);
    create_drive_straight(-100);
    msleep(1500);
    create_stop();
    set_claw(1000, slow); 
    
    create_disconnect();

    return 0; 
}
