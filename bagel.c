#include <stdio.h>
#include <kipr/botball.h>
#include <bagel_functions.h>

int main() {
    create_disconnect();
    create_connect();
    shut_down_in(119);
    set_servo_position(0, 700);
    enable_servos();
    
    set_lifter(high, 100);
    
    create_turn(45, 100, clockwise);
    create_drive_straight(100);
    msleep(1850);
    create_stop();
    
    create_turn(45, 100, counter_clockwise);

    while((get_create_lbump() == 0 && get_create_lbump() == 0) && (get_create_rbump() == 0 && get_create_rbump() == 0)) { create_drive_straight(100); }
    create_stop();

    create_drive_straight(0);
    msleep(200);
	create_turn(7,100, clockwise);//Begin picking up the three haybales//////////////
    create_stop();
    
    set_claw(1550, fast);
    
    set_lifter(mid - 300, 100);
    set_lifter(low+60, 70);
    msleep(10);
    
    set_claw(800, fast);
    msleep(10);
    
    set_claw(1400, fast);
    msleep(100);
    //set_lifter(low+40, 70);
    set_claw(600, fast);
    msleep(10);
    create_drive_straight(-100);//drive backwards//////////////////
    msleep(400);
    create_stop();
    
    set_claw(1200, fast);
    set_lifter(low+20, 100);
    msleep(100);
    set_claw(200, fast);
    msleep(10);
    set_claw(1200, fast);
    set_lifter(low, 100);
    msleep(100);
    set_claw(100, fast);
    msleep(400);

    set_lifter(high + 30, 100);
    //create_drive_straight(0);
    //msleep(400);
    create_stop();
    
	create_turn(7,100, counter_clockwise);//Finished picking up the three haybales, back up and turn///////

    create_drive_straight(-100);
    msleep(700);

    create_turn(88,100,clockwise);
    //create_turn(490, 60, counter_clockwise);
    msleep(10);

    //drive forward and lower claw
    create_drive_distance(150, 1200);
    msleep(100);
    set_lifter(mid, 100);
    msleep(10);
    create_drive_straight(0);
    msleep(100);
    create_stop();

    //Turn right into the drop location
    create_turn(82, 100, clockwise);

    //drive backward, lower claw, drive foreard and open servor to drop hay bales
    create_drive_straight(-100);
    msleep(1400);    
    create_stop();
    create_drive_straight(100);
    msleep(1200);
    create_stop();
    set_lifter(-180, 100);
    set_lifter(-220, 100);
    set_claw(1000, fast);  
    set_lifter(420, 100);
    create_drive_straight(-100);
    msleep(1400);  
    create_stop();  
    set_claw(600, fast);
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
    set_lifter(low - 50, 100);
    create_stop();
    set_claw(100, fast);
    
    //raise claw, and reverse previous commands
    set_lifter(medium + 200, 700);
    
    create_drive_straight(100);
    msleep(1000);
    create_turn(90, 100, clockwise);
    create_drive_straight(-200);
    msleep(1500);
    create_stop();

    //turn towards drop location again and drop
    create_turn(70, 100, clockwise);
    create_drive_straight(-100);
    msleep(1700);
    create_stop();
    //create_turn(10, 100, clockwise);
    set_lifter(60, 100);
    set_claw(1000, fast); 
    set_lifter(420, 100);
    create_turn(5, 100, counter_clockwise);
    set_claw(2400, fast);
    create_drive_straight(-100);
    msleep(300);
    create_stop();//go get blue ball
    
    create_turn(216, 100, counter_clockwise);
    
    create_drive_straight(-100);
    msleep(1500);
    create_stop();
    set_lifter(850, 100);
    set_lifter(910, 100);
    
    set_claw(500, fast);
    
    create_drive_straight(100);
    msleep(2500);    
    
    set_claw(100, fast);
    msleep(10);
    
    create_drive_straight(-100);
    msleep(2500);    
    
    create_turn(167, 100, counter_clockwise);
    
    create_drive_straight(100);
    msleep(3300);
    
        
    set_claw(1400, fast);
    
    msleep(200);
    
    
    create_drive_straight(-100);
    msleep(400);
    
    create_disconnect();

    return 0; 
}
