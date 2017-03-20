#include <stdio.h>
#include <kipr/botball.h>
#include <bagel_functions.h>

int main() {
    create_disconnect();
    create_connect();
    
    set_servo_position(0, 700);
    enable_servos();
    
    set_lifter(high - 100, 100);
    set_lifter(high + 50, 30);
    
    create_turn(45, 100, clockwise);
    create_drive_straight(100);
    msleep(1700);
    create_stop();
    
    create_turn(45, 100, counter_clockwise);

    while(get_create_lbump() == 0 && get_create_lbump() == 0) { create_drive_straight(100); }
    create_stop();

    create_drive_straight(0);
    msleep(200);
	create_turn(5,100, clockwise);//aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
    create_stop();
    
    set_claw(1550, fast);
    msleep(500);

    set_lifter(mid, 100);
    set_lifter(low + 20, 20);
    msleep(500);
    
    set_claw(800, fast);
    msleep(500);
    set_claw(1400, fast);
    msleep(500);
    
    set_lifter(low + 10, 20);
    
    set_claw(600, fast);
    msleep(500);
    set_claw(1200, fast);
    msleep(500);
    set_claw(200, fast);
    msleep(500);
    set_claw(1000, fast);
    msleep(500);
    set_claw(100, fast);
    msleep(200);

    set_lifter(high + 50, 100);
    
	create_turn(5,100, counter_clockwise);//aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa

    create_drive_straight(-100);
    msleep(700);

    create_turn(88,100,clockwise);
    //create_turn(490, 60, counter_clockwise);
    msleep(500);

    //drive forward and lower claw
    create_drive_distance(150, 600);
    msleep(200);
    set_lifter(mid, 70);
    create_drive_distance(100, 600);
    msleep(100);
    create_drive_straight(0);
    msleep(100);
    create_stop();

    //Turn right into the drop location
    create_turn(80, 100, clockwise);

    //drive backward, lower claw, drive foreard and open servor to drop hay bales
    create_drive_straight(-100);
    msleep(1400);    
    create_stop();
    create_drive_straight(100);
    msleep(1200);
    create_stop();
    set_lifter(-220, 100);
    set_lifter(-280, 100);
    set_claw(1000, slow);  
    set_lifter(420, 100);
    create_drive_straight(-100);
    msleep(1400);  
    create_stop();  
    set_claw(600, slow);
    create_drive_straight(100);
    msleep(400);
    
    //Second Set of Hay Bales
    
    //raise claw, turn back, drive forward, and turn towards the next bale group
   
    create_stop();
    create_turn(80, 100, counter_clockwise);
    create_drive_straight(100);
    msleep(2200);
    create_stop();
    set_claw(2400, fast);
    create_turn(93, 100, counter_clockwise);
    create_drive_straight(-100);
    msleep(2800);
    create_stop();

    //back up, open claw, lower the claw, grab a single cube
    set_claw(500, medium);
    set_lifter(low - 20, 50);
    create_stop();
    set_claw(100, fast);
    
    //raise claw, and reverse previous commands
    set_lifter(medium + 200, 70);
    
    create_drive_straight(100);
    msleep(1000);
    create_turn(90, 100, clockwise);
    create_drive_straight(-200);
    msleep(1500);
    create_stop();

    //turn towards drop location again and drop
    create_turn(65, 100, clockwise);
    create_drive_straight(-100);
    msleep(1700);
    create_stop();
    create_turn(5, 100, clockwise);
    set_lifter(-20, 50);
    set_lifter(-100, 50);
    set_claw(1000, slow); 
    set_lifter(420, 100);
    create_turn(5, 100, counter_clockwise);
    create_drive_straight(-100);
    msleep(300);
    create_stop();
    
    while(a_button() == 1){msleep(10);}
    
    set_claw(2400, fast);
    
    create_turn(215, 100, counter_clockwise);
    
    while(a_button() == 1){msleep(10);}
    create_drive_straight(-100);
    msleep(2000);
    create_stop();
    
    set_lifter(950, 100);
    
    set_claw(500, fast);
    
    create_drive_straight(100);
    msleep(2650);    
    
    set_claw(100, fast);
    msleep(550);
    
    create_drive_straight(-100);
    msleep(2650);    
    
    create_turn(175, 100, counter_clockwise);
    
    set_lifter(950, 100);
    freeze(0);
    
    create_drive_straight(100);
    msleep(3650);
        
    set_claw(800, fast);
    
    msleep(200);
    
    
    create_drive_straight(-100);
    msleep(3000);
    
    create_disconnect();

    return 0; 
}
