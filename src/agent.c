#include "../includes/agent.h"
#include "../includes/color.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Ambient{
    char **environment;
    int environment_size;
    int position_x, position_y;
};

void announce_arrival(){

}

struct Agent* create_environment(int environment_size){
    Ambient *ambient = (struct Ambient*)malloc(sizeof(struct Ambient));
    if(!ambient){
        perror("Failed to allocate agent");
        exit(1);
    }

    ambient->environment_size = environment_size;
    ambient->position_x = 0;
    ambient->position_y = 0;

    ambient->environment = (char**)malloc((environment_size + 1) * sizeof(char*));
    if(!ambient->environment){
        perror("Failed to allocate environment rows");
        free(ambient);
        exit(1);
    }

    for(int index = 0; index <= environment_size; ++index){
        ambient->environment[index] = (char*)malloc((environment_size + 1) * sizeof(char));
        if(!ambient->environment[index]){
            perror("Failed to allocate environment columns");
            for(int j_index = 0; j_index < index; j_index++)
                free(ambient->environment[j_index]);
            free(ambient->environment);
            free(ambient);
            exit(1);            
        }

        for(int j_index = 0; j_index <= environment_size; ++j_index)
            ambient->environment[index][j_index] = ' ';
    }

    return ambient;
}

void create_obstacles(const int environment_size, char (*environment)[environment_size + 1]){

}

void create_objective(const int environment_size, char (*environment)[environment_size + 1]){

}

void choose_start_position(Ambient* ambient){
    ambient->position_x = rand() % ambient->environment_size + 1;
    ambient->position_y = rand() % ambient->environment_size + 1;

    ambient->environment[ambient->position_x][ambient->position_y] = 'X';

    for(int index = 1; index <= ambient->environment_size; ++index)
        for(int j_index = 1; j_index <= ambient->environment_size; ++index)
            if(ambient->environment[index][j_index] != 'X' && ambient->environment[index][j_index] != '#')
                ambient->environment[index][j_index] = ' ';
}

void release_agent(Ambient* ambient){
    if(!ambient)
        return;
    for(int index = 0; index <= ambient->environment_size; ++index)
        free(ambient->environment[index]);
    free(ambient->environment);
    free(ambient);
}

void show_environment(Ambient* ambient){
    system("clear");

    for(int index = 1; index <= ambient->environment_size; ++index){
        for(int j_index = 1; j_index <= ambient->environment_size; ++j_index)
            printf("+---");
        printf("+\n");

        for(int j_index = 1; j_index <= ambient->environment_size; ++j_index){
            if(ambient->environment[index][j_index] == 'X')
                printf("| " GREEN "%c " RESET, ambient->environment[index][j_index]);
            else if(ambient->environment[index][j_index] == '#')
                printf("| " RED "%c " RESET, ambient->environment[index][j_index]);
            else if(ambient->environment[index][j_index] == '*')
                printf("| " YELLOW "%c " RESET, ambient->environment[index][j_index]);
            else
                printf("| %c ", ambient->environment[index][j_index]);
        }
        printf("|\n");
    }
    for(int index = 1; index <= ambient->environment_size; ++index)
        printf("+---");
    printf("+\n");
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