#include "../includes/agent.h"
#include "../includes/color.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Ambient {
    char **environment;
    int environment_size;
    int position_x, position_y;
};

void announce_arrival(void) {
    printf("You reached your goal, congratulations!\n");
    exit(1);
}

Ambient* create_environment(int environment_size) {
    Ambient *ambient = (struct Ambient*)malloc(sizeof(struct Ambient));
    if (!ambient) {
        perror("Failed to allocate agent");
        exit(1);
    }

    ambient->environment_size = environment_size;
    ambient->position_x = 0;
    ambient->position_y = 0;

    ambient->environment = (char**)malloc((environment_size + 1) * sizeof(char*));
    if (!ambient->environment) {
        perror("Failed to allocate environment rows");
        free(ambient);
        exit(1);
    }

    for (int index = 0; index <= environment_size; ++index) {
        ambient->environment[index] = (char*)malloc((environment_size + 1) * sizeof(char));
        if (!ambient->environment[index]) {
            perror("Failed to allocate environment columns");
            for (int j_index = 0; j_index < index; j_index++)
                free(ambient->environment[j_index]);
            free(ambient->environment);
            free(ambient);
            exit(1);
        }

        for (int j_index = 0; j_index <= environment_size; ++j_index)
            ambient->environment[index][j_index] = ' ';
    }

    return ambient;
}

void create_obstacles(Ambient* ambient) {
    srand(time(NULL));

    int percentage_of_obstacles = ((ambient->environment_size * ambient->environment_size * WALLS_DENSITY) / 100);

    while (percentage_of_obstacles > 0) {
        int position_x = rand() % ambient->environment_size + 1;
        int position_y = rand() % ambient->environment_size + 1;

        if (ambient->environment[position_x][position_y] != 'X' && ambient->environment[position_x][position_y] != '*')
            ambient->environment[position_x][position_y] = '#';

        percentage_of_obstacles--;
    }
}

void create_objective(Ambient* ambient) {
    srand(time(NULL));
    int position_x, position_y;
    do {
        position_x = rand() % ambient->environment_size + 1;
        position_y = rand() % ambient->environment_size + 1;
    } while (ambient->environment[position_x][position_y] == 'X' || ambient->environment[position_x][position_y] == '#');

    ambient->environment[position_x][position_y] = '*';
}

void choose_start_position(Ambient* ambient) {
    srand(time(NULL));
    ambient->position_x = rand() % ambient->environment_size + 1;
    ambient->position_y = rand() % ambient->environment_size + 1;

    ambient->environment[ambient->position_x][ambient->position_y] = 'X';

    for (int index = 1; index <= ambient->environment_size; ++index)
        for (int j_index = 1; j_index <= ambient->environment_size; ++j_index)
            if (ambient->environment[index][j_index] != 'X' && ambient->environment[index][j_index] != '#')
                ambient->environment[index][j_index] = ' ';
}

void release_agent(Ambient* ambient) {
    if (!ambient)
        return;
    for (int index = 0; index <= ambient->environment_size; ++index)
        free(ambient->environment[index]);
    free(ambient->environment);
    free(ambient);
}

void show_environment(Ambient* ambient) {
    system("clear");

    for (int index = 1; index <= ambient->environment_size; ++index) {
        for (int j_index = 1; j_index <= ambient->environment_size; ++j_index)
            printf("+---");
        printf("+\n");

        for (int j_index = 1; j_index <= ambient->environment_size; ++j_index) {
            if (ambient->environment[index][j_index] == 'X')
                printf("| " GREEN "%c " RESET, ambient->environment[index][j_index]);
            else if (ambient->environment[index][j_index] == '#')
                printf("| " RED "%c " RESET, ambient->environment[index][j_index]);
            else if (ambient->environment[index][j_index] == '*')
                printf("| " YELLOW "%c " RESET, ambient->environment[index][j_index]);
            else
                printf("| %c ", ambient->environment[index][j_index]);
        }
        printf("|\n");
    }
    for (int index = 1; index <= ambient->environment_size; ++index)
        printf("+---");
    printf("+\n");
}

char move_randomly(void) {
    int value = rand() % 4;
    switch (value) {
        case 0: return 'w';
        case 1: return 's';
        case 2: return 'a';
        case 3: return 'd';
        default: return 'w';
    }
}

void move_down(Ambient* ambient) {
    if ((ambient->position_x) + 1 <= ambient->environment_size && ambient->environment[(ambient->position_x) + 1][ambient->position_y] != '#') {
        if (ambient->environment[(ambient->position_x) + 1][ambient->position_y] == '*') {
            ambient->environment[ambient->position_x][ambient->position_y] = ' ';
            (ambient->position_x)++;
            ambient->environment[ambient->position_x][ambient->position_y] = 'X';
            show_environment(ambient);
            announce_arrival();
        }

        ambient->environment[ambient->position_x][ambient->position_y] = ' ';
        (ambient->position_x)++;
        ambient->environment[ambient->position_x][ambient->position_y] = 'X';
    }
}

void move_up(Ambient* ambient) {
    if ((ambient->position_x) - 1 >= 1 && ambient->environment[(ambient->position_x) - 1][ambient->position_y] != '#') {
        if (ambient->environment[(ambient->position_x) - 1][ambient->position_y] == '*') {
            ambient->environment[ambient->position_x][ambient->position_y] = ' ';
            (ambient->position_x)--;
            ambient->environment[ambient->position_x][ambient->position_y] = 'X';
            show_environment(ambient);
            announce_arrival();
        }

        ambient->environment[ambient->position_x][ambient->position_y] = ' ';
        (ambient->position_x)--;
        ambient->environment[ambient->position_x][ambient->position_y] = 'X';
    }
}

void move_right(Ambient* ambient) {
    if ((ambient->position_y) + 1 <= ambient->environment_size && ambient->environment[ambient->position_x][(ambient->position_y) + 1] != '#') {
        if (ambient->environment[ambient->position_x][(ambient->position_y) + 1] == '*') {
            ambient->environment[ambient->position_x][ambient->position_y] = ' ';
            (ambient->position_y)++;
            ambient->environment[ambient->position_x][ambient->position_y] = 'X';
            show_environment(ambient);
            announce_arrival();
        }

        ambient->environment[ambient->position_x][ambient->position_y] = ' ';
        (ambient->position_y)++;
        ambient->environment[ambient->position_x][ambient->position_y] = 'X';
    }
}

void move_left(Ambient* ambient) {
    if ((ambient->position_y) - 1 >= 1 && ambient->environment[ambient->position_x][(ambient->position_y) - 1] != '#') {
        if (ambient->environment[ambient->position_x][(ambient->position_y) - 1] == '*') {
            ambient->environment[ambient->position_x][ambient->position_y] = ' ';
            (ambient->position_y)--;
            ambient->environment[ambient->position_x][ambient->position_y] = 'X';
            show_environment(ambient);
            announce_arrival();
        }

        ambient->environment[ambient->position_x][ambient->position_y] = ' ';
        (ambient->position_y)--;
        ambient->environment[ambient->position_x][ambient->position_y] = 'X';
    }
}