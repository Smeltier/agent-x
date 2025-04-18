#ifndef AGENT_H
#define AGENT_H

#define WALLS_DENSITY 30

typedef struct Ambient Ambient;

/*
 * Description: Announces that the agent has reached the objective and terminates the program.
 * Input: None.
 * Output: None.
 */
void announce_arrival(void);

/*
 * Description: Creates a new environment of size n x n, initializing the matrix and agent's position.
 * Input: Integer representing the size of the environment (n).
 * Output: Pointer to the created Ambient structure.
 */
Ambient* create_environment(int environment_size);

/*
 * Description: Creates obstacles, blocking the agent's passage.
 * Input: Pointer to the Ambient structure.
 * Output: None.
 */
void create_obstacles(Ambient* ambient);

/*
 * Description: Places an objective ('*') at a random valid position in the environment.
 * Input: Pointer to the Ambient structure.
 * Output: None.
 */
void create_objective(Ambient* ambient);

/*
 * Description: Chooses a random starting position for the agent within the environment.
 * Input: Pointer to the Ambient structure.
 * Output: None.
 * Note: It is recommended to use this function after generating the obstacles.
 */
void choose_start_position(Ambient* ambient);

/*
 * Description: Frees the memory allocated for the environment and the Ambient structure.
 * Input: Pointer to the Ambient structure.
 * Output: None.
 */
void release_agent(Ambient* ambient);

/*
 * Description: Displays the n x n environment with the agent, obstacles, and objective.
 * Input: Pointer to the Ambient structure.
 * Output: None.
 */
void show_environment(Ambient* ambient);

/*
 * Description: Generates a random movement direction for the agent.
 * Input: None.
 * Output: Character representing the direction ('w' for up, 's' for down, 'a' for left, 'd' for right).
 */
char move_randomly(void);

/*
 * Description: Moves the agent down in the environment if the move is valid.
 * Input: Pointer to the Ambient structure.
 * Output: None.
 */
void move_down(Ambient* ambient);

/*
 * Description: Moves the agent up in the environment if the move is valid.
 * Input: Pointer to the Ambient structure.
 * Output: None.
 */
void move_up(Ambient* ambient);

/*
 * Description: Moves the agent right in the environment if the move is valid.
 * Input: Pointer to the Ambient structure.
 * Output: None.
 */
void move_right(Ambient* ambient);

/*
 * Description: Moves the agent left in the environment if the move is valid.
 * Input: Pointer to the Ambient structure.
 * Output: None.
 */
void move_left(Ambient* ambient);

#endif