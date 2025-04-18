#ifndef AGENT_H
#define AGENT_H

#define WALLS_DENSITY 30 

typedef struct Ambient Ambient;


void announce_arrival();


struct Agent* create_environment(int environment_size);

/*
 * Description: Creates obstacles, blocking the agent's passage.
 * Input: 
 * Output: None.
 */
void create_obstacles(const int environment_size, char (*environment)[environment_size + 1]);


void create_objective(const int environment_size, char (*environment)[environment_size + 1]);

/*
 * Description: Chooses a random position within the limits of the n x n environment.
 * Input: Receives the size of the environment, the environment itself (in matrix form), the current X position and the current Y position.
 * Output: None.
 * Note: It is recommended to use this function after generating the obstacles.
 */
void choose_start_position(Ambient* ambient);


void release_agent(Ambient* ambient);

/*
 * Description: Shows an n x n environment for your agent to move around in.
 * Input: Receives the size of the environment and the environment matrix.
 * Output: None.
 */
void show_environment(Ambient* ambient);


char move_randomly();


void move_down(const int room_size, char (*room)[room_size + 1], int *x_position, int *y_position);


void move_up(const int room_size, char (*room)[room_size + 1], int *x_position, int *y_position);


void move_right(const int room_size, char (*room)[room_size + 1], int *x_position, int *y_position);


void move_left(const int room_size, char (*room)[room_size + 1], int *x_position, int *y_position);

#endif