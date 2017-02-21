#include <kipr/botball.h>
#include <create_lib.h>
void move_servo();
int main()
{
    // Connect to the create
    printf("run");
    create_disconnect();
    create_connect();
    //high_claw(50);
    
    //Engage the servos
   	set_servo_position(0,700);
    enable_servos();
    
    // Move forward until a bumper is collided
    while(get_create_lbump() == 0 && get_create_lbump() == 0){create_drive_straight(100);}
    // Angle slightly right
    create_turn(10,1);
    
    //Open claw
    msleep(10);
    move_servo(0, 1250, fast);
    
    //Lower Claw
    low_claw(50, 0);
    
    
    // Close claw, open slightly, angle slightly left, and back up
    msleep(10);
    move_servo(0,750,fast);
    msleep(100);
    move_servo(0, 800,medium);
    msleep(1000);
    create_turn(1,-1);
    create_drive_straight(-50);
    
    msleep(900);
    
    create_drive_straight(0);
    
    //Close claw
    move_servo(0,600,fast);
    msleep(500);
    move_servo(0,150,slow);
    msleep(2000);
    // Raise winch
    high_claw(40);
    //Back up
    create_drive_straight(-100);
    msleep(500);
    //turn towards drop location
    create_turn(84,1);
    msleep(500);
    //drive forward
    create_drive_distance(150, 1200);
    msleep(500);
    //lower claw and turn right into the drop location
    mid_claw(60);
    create_turn(90, 1);
    //drive backward, lower claw, and open servor to drop hay bales
    create_drive_straight(-100);
    msleep(750);
    create_stop();
    msleep(500);
    low_claw(20, 0);
    move_servo(0,900,slow);  
    //raise claw, turn back, drive forward, and turn towards the next bale group
    mid_claw(40);
    move_servo(0,700, slow);
    create_drive_straight(100);
    msleep(550);
    create_stop();
    create_turn(90, -1);
    create_drive_straight(200);
    msleep(2100);
    create_stop();
    create_turn(90, -1);
    //back up, open claw, lower the claw, open and close repeatedly in order to push the cubes closer together.
    create_drive_straight(-100);
    msleep(950);
    create_stop();
    move_servo(0,1200,medium);
    msleep(500);
    low_claw(20, -20);
    msleep(500);
    int times = 0;
    for( ; times < 3 ; times++){
        set_servo_position(0,400);
        msleep(500);
        move_servo(0,1200,fast);
        msleep(300);
    }

    //Open claw a little and drive backwards in order to pull the hay bales closer together.
    move_servo(0,750, slow);
    msleep(500);
    create_drive_straight(-50);
    msleep(1000);
    create_stop();
    
   //Raise claw, open all the way, drive forward, lower the claw and close the claw.
    mid_claw(40);
    move_servo(0,1210, fast);
    create_drive_straight(50);
    msleep(1000);
    create_stop();
    low_claw(20,50);
    msleep(500);
    set_servo_position(0,500);
    move_servo(0,300,slow);
    msleep(1000);
    
    //raise claw, and reverse previous commands
    mid_claw(30);
    create_turn(90,1);
    create_drive_straight(-200);
    msleep(2100);
    create_stop();
    //turn towards drop location again and drop
    create_turn(90,1);
    create_drive_straight(-100);
    msleep(1500);
    create_stop();
    move_servo(0,1000,slow);
    
    create_disconnect();
    return 0; 
}
