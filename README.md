# Dungeon-in-terminal-c-game

A simple dungeon crawler written in C++ that runs entirely in the terminal. Made with love.

## Building

On Fedora, install the required build tools if they are not already present:

```bash
sudo dnf install cmake make gcc-c++
```

Use CMake to configure and build the project:

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

Run the game from the build directory:

```bash
./ZOO_projekt
```

## Fun fact

Enemies are spawned through factory classes, allowing the game to easily create foes of varying strength depending on the chosen difficulty.

