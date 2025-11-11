# Cube_3D

## 🧱 cub3D

A first-person pseudo-3D maze explorer built with the MiniLibX graphical library.

Inspired by Wolfenstein 3D, this project implements a simple raycasting engine to render a 3D illusion from a 2D map, with wall textures, smooth movement, and real-time rendering.

---

## 🚀 Features

- **Custom Scene Loading:**
Parses .cub configuration files defining textures, floor/ceiling colors, and map layout.

- **Comprehensive Map Validation:**

Ensures textures and color definitions are present and valid.

Verifies the map is fully enclosed by walls (1).

Guarantees exactly one player starting position (N, S, E, W).

- **Raycasting Engine:**
Uses the DDA algorithm to cast rays and render walls with realistic perspective.

- **Mini Map (Bonus):**
Displays a 2D top-down representation of the player’s surroundings.

- **Player Movement:**
Move and rotate smoothly using W, A, S, D, and arrow keys.

- **Wall Collision:**
Prevents the player from walking through walls.

- **Textured Rendering:**
Loads .xpm textures for walls in each direction (NO, SO, WE, EA).

- **Clean Exit & Error Handling:**
Robust error management, freeing all resources before exit or on invalid input.

---

## 🛠️ Technologies & Tools

**C Language** — Core development language (Norm-compliant).

**MiniLibX (X11)** — Lightweight graphics library for window management and drawing.

**libft (custom)** — Utility library for string, memory, and I/O functions.

**Math Library (-lm)** — Used for trigonometric functions in raycasting.

**Makefile** — Handles compilation, cleaning, and linking of dependencies.

**Valgrind-friendly Code** — Designed for memory safety and leak-free execution.

---

## ⚙️ Installation & Setup

1. Clone the repository:

    ```bash
    git clone https://github.com/yourusername/cub3D.git
    cd cub3D
    ```

2. Compile the project:
    ```bash
    make
    ```

This will also compile libft and MiniLibX automatically if included as submodules.

--- 

## 💡 Usage

Run the program with a valid .cub configuration file:

    ```bash
    ./cub3D maps/good/example.cub
    ```

### Controls:

| Key       | Action                   |
| --------- | ------------------------ |
| **W / S** | Move forward / backward  |
| **A / D** | Strafe left / right      |
| **← / →** | Rotate view left / right |
| **ESC**   | Exit the game            |

### Map Files:

Valid maps: maps/good/

Invalid maps (for testing): maps/bad/

Example:

    ```bash
        ./cub3D maps/bad/open_map.cub
    ```

---

## 🧠 Development & Challenges

- **Parsing & Validation:**
Implementing a robust parser to ensure .cub files are consistent and playable.

- **Raycasting Logic:**
Understanding and coding the DDA algorithm for efficient wall projection and texture sampling.

- **Rendering Optimization:**
Drawing walls column by column using MiniLibX image buffers.

- **Memory & Resource Management:**
Avoiding leaks and double-frees by centralizing allocations and cleanups.

- **Event Handling:**
Managing smooth movement and rotation using MLX hooks and key states.

--- 


## 🧩 Bonuses (optional)

| Bonus               | Description                                      |
| ------------------- | ------------------------------------------------ |
| 🗺️ Mini Map        | Visualize player position and nearby walls in 2D |
| 🚪 Doors            | Open/close interactive elements                  |
| 🧍 Animated Sprites | Moving or rotating enemies/objects               |
| 🖱️ Mouse Rotation  | Rotate camera using mouse movement               |
| 🧱 Wall Collisions  | Physically block movement through walls          |

---

## 📂 File Structure

    ```bash
        .
        ├── assets/                  # Texture and sprite assets (.xpm)
        ├── libft/                   # Custom utility library
        ├── maps/                    # Example maps (good/bad)
        │   ├── good/
        │   └── bad/
        ├── src/
        │   ├── parsing/             # .cub file parsing & validation
        │   ├── raycasting/          # DDA algorithm & rendering
        │   ├── render/              # Image drawing and display
        │   ├── events/              # Keyboard & mouse handling
        │   ├── bonus/               # Optional features (mini map, doors)
        │   └── main.c               # Entry point
        ├── includes/
        │   └── cub3d.h              # Global structs, constants, prototypes
        ├── Makefile                 # Build system
        └── README.md

    ```

    ---

    ## 
👤 Author
