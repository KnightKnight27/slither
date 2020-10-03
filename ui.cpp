#include "ui.h"

// modularizing the code
// breaking the code down into functions and modules


// install ncurses
// ubuntu: sudo apt-get install libncurses6 libncurses-dev
// macos: brew install ncurses
// google - install homebrew

void print_border() {
    for(int i = 0; i < COLS; i++) {
        move(0, i);
        addstr("\u2588");
        move(LINES - 1, i);
        addstr("\u2588");
    }

    for(int i = 0; i < LINES; i++) {
        move(i, 0);
        addstr("\u2588");
        move(i, COLS - 1);
        addstr("\u2588");
    }

    refresh();
}

void init_ui() {
    setlocale(LC_ALL, ""); // override the default locale
    initscr(); // initilizes the ncurses mode
    curs_set(0); // hide the cursor
    noecho();  // prevents printing out whatever you typed
    cbreak(); // generate an interrupt on ctrl+c
}


void tear_down_ui() {
    endwin(); // exits the ncurses mode, and restore the previous terminal
}


/*
1980s 
DOS - 80x40 (80 chars in width and 40 in height)
terminals
(change color
move to a location) - control bytes

virtual terminals
terminal emulator


ncurses - standardizes across terminals
- create some basic UI

- entry point
- UI - user interface (graphics)
- controls
- event loop - is a loop that sits and 
               processes events

*/