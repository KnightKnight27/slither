// library that provides some functions and datatypes for working with time
#include <chrono> 

#include "constants.h"
#include "ui.h"
#include "game.h"
using namespace std; 


void event_loop() {
    auto last_time = chrono::system_clock::now();
    auto current_time = chrono::system_clock::now();
    int delta_t;
    while(true) {
        current_time = chrono::system_clock::now();
        delta_t = chrono::duration_cast<chrono::milliseconds>(
                      current_time - last_time
                  ).count(); // count the number of units that have passed
        if(delta_t > TICK_INTERVAL) {
            tick();
            refresh();
            last_time = current_time;
        }
    }
}

int main() {
    init_ui();
    event_loop();
    tear_down_ui();
    return 0;
}
