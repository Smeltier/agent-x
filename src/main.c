#include "../includes/agent.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char const *argv[]){

    int ambient_size;
    scanf("%d", &ambient_size);

    Ambient* ambient = create_environment(ambient_size);

    create_obstacles(ambient);
    choose_start_position(ambient);
    create_objective(ambient);

    while (1){

        show_environment(ambient);

        int var = move_randomly();
        switch (tolower(var)){
            case 'w':
                move_up(ambient);
                show_environment(ambient);
                break;
            case 's':
                move_down(ambient);
                show_environment(ambient);
                break;
            case 'd':
                move_right(ambient);
                show_environment(ambient);
                break;
            case 'a':
                move_left(ambient);
                show_environment(ambient);
                break;
        }
    }

    return 0;
}