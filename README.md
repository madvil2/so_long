# so_long

*Survive the zombies and collect your loot! 🧟‍♂️*

<div align="center">
  <img src="game.png" />
</div>

### Table of Contents
- [Introduction](#introduction)
- [How It Works](#how-it-works)
- [Features](#features)
- [Gameplay](#gameplay)
- [Maps and Customization](#maps-and-customization)
- [Installation](#installation)
- [Controls and Interaction](#controls-and-interaction)
- [Challenges](#challenges)
- [Summary](#summary)

## Introduction
The `so_long` project at 42 involves coding a simple yet challenging 2D game to familiarize students with graphical applications using the `minilibx` library. In this variant, players navigate a Minecraft-styled world, dodging zombies and collecting items to survive.

### Game Requirements
The game adheres to specific criteria:
- Map format: `.ber`
- Valid map entities: `P` (player), `1` (wall), `0` (empty), `C` (collectible), `E` (exit), plus enemies
- Rectangular map configuration enclosed by walls
- Minimum content: one player, one exit, one collectible
- Custom behavior: zombies can spawn via a special button

## How It Works

### Initialization and Validation
The game begins by initializing the gaming environment and validating the map input for proper format and content. This includes setting up the main window based on the map size and ensuring all game textures are loaded correctly.

### Event Handling
- **Mouse Hooks**: Handle in-game mouse interactions, primarily for spawning zombies.
- **Key Hooks**: Manage player movements and interactions with the game environment.
- **Exit Hook**: Ensures a clean exit upon closing the window.

### Main Game Loop
The game continually checks and updates the state based on player actions, enemy movements, and other game events through the `mlx_loop`.

## Features

- **Enemy Logic**: Zombies move with a basic AI that targets the player's last known position.
- **Interactive Gameplay**: Players can spawn zombies at will, increasing the game's difficulty and unpredictability.
- **Custom Graphics**: All graphics are tailored to a Minecraft theme, enhancing the visual experience.

## Gameplay

Players navigate through various maps, avoiding or confronting zombies, and collecting necessary items before making their escape through the designated exit.

## Maps and Customization

The game includes several pre-designed maps, each offering unique challenges and layouts. Players can also create custom maps by following the provided map guidelines.

## Installation

### Dependencies
Ensure `minilibx` is installed and configured correctly on your system. 

### Building the Game
```shell
git clone https://github.com/madvil2/so_long.git
cd so_long
make
```

## Controls and Interaction

- **Movement**: Use arrow keys or `W`, `A`, `S`, `D`.
- **Spawn Zombies**: Click within the game window.
- **Exit Game**: Press `ESC`.

## Challenges

Developing this game provided insights into graphical programming, event handling, and the utilization of game loops. Balancing gameplay and implementing effective enemy AI were particularly challenging aspects.

## Summary

This project not only demonstrates proficiency in using the `minilibx` library but also in designing engaging gameplay mechanics within the constraints of the assignment. It has been an invaluable learning experience, blending creativity with technical skills.
