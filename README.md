# interstellar
### An Intergalactic Missile Defense System Game
_Programmed in C++ using CilkPlus for parallelization and SFML for graphics_
## Design/Architecture
Current project file structure is broken up into subdirectories:

```
.
├── build
├── docs
├── src
│   ├── main
│   ├── objects
│   └── view
├── styles
│   ├── font
│   └── images
└── test
    ├── Jack_Test
    ├── Jim_Test
    ├── Lucas_Test
    ├── Old
    └── Tallack_Test
```
###Each directory has a different purpose:
- build: Where makefiles, *.o files and .exe and built
- docs: Where documentation can be found
- src: Where objects for the game and views are put. It contains game objects (space objects.cpp) in the objects directory, view objects (background.cpp), and the main.cpp in the main directory
- styles: Where images and fonts are put for game aesthetics
- test: Where each one of our test cases are put

###Sequence of Events
```
main.cpp => start.cpp => game.cpp
```
The main.cpp will create a start menu for the game. The start menu will continue to draw until a user clicks on the window. Once a user clicks, it will then create a game.cpp which will then draw objects passed on the user button actions. The window will be passed from the start.cpp to game.cpp once the game.cpp is initiated.

## Data Model Design
```
src
├── main
├── objects
│   ├── helper.cpp
│   ├── helper.h
│   ├── planet.cpp
│   ├── planet.h
│   ├── satellite.h
│   ├── spaceobject.cpp
│   └── spaceobject.h
└── view
    ├── background.cpp
    ├── background.h
    ├── title.cpp
    └── title.h
```
## Prezi
http://prezi.com/wnnquwgmqqfc/interstellar/
## Docs
http://rucas.github.io/interstellar/
