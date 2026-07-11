# Terminal Roguelike (C++ / OOP)

A console-based roguelike built in pure C++ using OOP fundamentals — no STL containers, no external libraries. Designed to grow version by version.

## v1 — Current
- `Entity` abstract base class (encapsulation, pure virtual functions)
- `Player` class inherits `Entity` (inheritance + polymorphism via `takeDamage()`)
- `Dungeon` class manages a 2D grid using raw arrays, renders the map
- `Game` class runs the main loop and handles WASD input + wall collision

## Build & Run
```
make run
```
or manually:
```
g++ -std=c++11 -Iinclude src/main.cpp -o roguelike
./roguelike
```

## Controls
- `w` / `a` / `s` / `d` — move
- `q` — quit

## Roadmap
- [x] v1: Player movement, walls, rendering
- [ ] v2: Randomized dungeon generation
- [ ] v3: Enemy base class + combat
- [ ] v4: Item class hierarchy + inventory
- [ ] v5: Polymorphic abilities per class
- [ ] v6: Save/load via file I/O
- [ ] v7: Boss fight + win/lose conditions
