# Agent X

Welcome to **Agent X**, a C-based terminal game where an agent navigates a 2D grid to reach a goal while avoiding obstacles. The game features a colorful grid displayed in the terminal, offering a retro-style experience.

## Description

In **Agent X**, an agent (`X`) moves through a square grid (`n x n`) to reach a goal (`*`) while avoiding obstacles (`#`). The environment includes:
- **Agent** (`X`, in green): The character you control.
- **Goal** (`*`, in yellow): The target to reach.
- **Obstacles** (`#`, in red): Blocks that prevent movement.

The agent's movement can be random (choosing up, down, left, or right) or controlled by other methods, depending on the implementation. The game ends with a victory message when the agent reaches the goal.

## Prerequisites

To run the game, you need:
- A C compiler (e.g., `gcc`).
- A terminal or command-line interface (Linux, macOS, or Windows with WSL recommended).
- Git (to clone the repository).

## How to Clone

To clone the repository to your local machine:

1. Open your terminal.
2. Run the following command:
   ```bash
   git clone https://github.com/Smeltier/agent-x.git
   ```
3. Navigate to the project directory:
   ```bash
   cd agent-x
   ```

## How to Compile and Run

1. Ensure you are in the project directory (`agent-x`).
2. Compile the game using `gcc`:
   ```bash
   gcc -Iincludes -o game src/agent.c
   ```
   The `-Iincludes` flag specifies the `includes` directory for header files.
3. Run the game:
   ```bash
   ./game
   ```

**Note**: The game requires a terminal that supports ANSI color codes for proper visualization (most modern terminals do).

## How to Play

- Upon starting, the game generates a square grid (`n x n`, size defined in the code).
- The grid contains:
  - The agent (`X`, green), starting at a random position.
  - Obstacles (`#`, red), randomly placed (30% density by default).
  - A goal (`*`, yellow), placed at a random valid position.
- The agent moves through the grid to reach the goal. Movements can be:
  - **Random**: The agent chooses a direction (up, down, left, right) randomly each step.
  - **Other Methods**: Depending on the implementation, movements may be controlled manually (e.g., via keyboard input) or through other strategies.
- If the agent reaches the goal (`*`), the game displays "You reached your goal, congratulations!" and exits.
- The environment is updated and displayed in the terminal after each move.

**Tip**: For the best experience, play the game in a terminal to enjoy the colored grid and smooth updates. Maximize your terminal window or use a larger font size for better visibility.

## Project Structure

```
agent-x/
├── includes/
│   ├── agent.h     # Header file with game structure and function declarations
│   ├── color.h     # Header file with ANSI color codes
├── src/
│   ├── agent.c     # Main game logic
├── README.md       # This file
```

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.