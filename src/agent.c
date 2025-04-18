#include "includes/agent.h"

struct Ambient{
    char **environment;
    int environment_size;
    int position_x, position_y;
};

void announce_arrival(){

}

struct Agent* create_agent(int environment_size){

}

void create_obstacles(const int environment_size, char (*environment)[environment_size + 1]){

}

void create_objective(const int environment_size, char (*environment)[environment_size + 1]){

}


void choose_start_position(const int environment_size, int *x_position, int *y_position, char (*environment)[environment_size + 1]){

}

void release_agent(struct Agent *agent){

}

void show_environment(struct Agent *agent){

}

char move_randomly(){

}

void move_down(const int room_size, char (*room)[room_size + 1], int *x_position, int *y_position){

}

void move_up(const int room_size, char (*room)[room_size + 1], int *x_position, int *y_position){

}

void move_right(const int room_size, char (*room)[room_size + 1], int *x_position, int *y_position){

}

void move_left(const int room_size, char (*room)[room_size + 1], int *x_position, int *y_position){

}