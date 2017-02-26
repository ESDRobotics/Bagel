// ports
#define lifter 1
#define claw 0

// servo positions
#define high -860
#define mid -72
#define low 160

// delays
#define slow 30
#define medium 15
#define fast 10

// directions
#define forward 1
#define backward -1
#define clockwise 1
#define counter_clockwise -1

/* 
    NOTE: THIS FUNCTION DOES NOT WORK CORRECTLY ON BAGEL
    Purpose: drives create given distance (cm) at given speed
    Arguments: speed to travel at, distance to travel (cm)
*/
void create_drive_distance(int speed, double target_distance) {
    int current_distance = 0;

    // convert distance to values that work for create
    if(target_distance<=50)
        target_distance*=1.1424; // 1.12
    else if(target_distance<=100)
        target_distance*=1.1688; // 1.1459
    else if(target_distance<=150) 
        target_distance*=1.1867; // 1.1634
    else if(target_distance<=200)
        target_distance*=1.1863; // 1.163
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
void create_turn(int degrees, int speed, int direction) {
    // converts degrees to msleep time
    double turn_time = degrees * 18.125;
    int speed = speed * direction;
    
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
        current_pos -= 10;
    }

    while(current_pos < position) {
        set_servo_position(claw, current_pos);
        msleep(delay);
        current_pos += 10;
    }
}

/* 
    Purpose: sets lifter to given position
    Arguments: position to go to (bigger values == lower), speed of motor
*/
void set_lifter(int position, int speed) {
    while(accel_y() > position) {
        motor(lifter, speed);
        msleep(10);
    }

    while(accel_y() < position) {
        motor(lifter, -speed);
        msleep(10);
    }

    // holds lifter still
    motor(lifter, 1);
}
