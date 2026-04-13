#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include "Vuart_top.h"
#include "verilated.h"

void set_nonblocking(bool enable) {
    struct termios ttystate;
    tcgetattr(STDIN_FILENO, &ttystate);
    if (enable) {
        ttystate.c_lflag &= ~(ICANON | ECHO);
        ttystate.c_cc[VMIN] = 0;
    } else {
        ttystate.c_lflag |= (ICANON | ECHO);
    }
    tcsetattr(STDIN_FILENO, TCSANOW, &ttystate);
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vuart_top* top = new Vuart_top;

    set_nonblocking(true);
    printf("--- UART Logic Robust Interactive Mode ---\n");

    uint64_t main_time = 0;
    char input_char;

    while (!Verilated::gotFinish()) {
        // 1. Read input
        if (read(STDIN_FILENO, &input_char, 1) > 0) {
            if (input_char == 27) break; // ESC

            // FLOW CONTROL: If hardware is busy, churn the clock until it's not
            while (top->tx_busy) {
                top->clk = !top->clk;
                top->eval();
                main_time++;
            }

            // Start transmission
            top->tx_data = input_char;
            top->tx_start = 1;
            
            // Give it one clock cycle to register the start
            top->clk = !top->clk; top->eval();
            top->clk = !top->clk; top->eval();
            top->tx_start = 0;
        }

        // 2. Continuous Simulation Step
        top->clk = !top->clk;
        top->eval();

        // 3. Capture output
        if (top->rx_ready && top->clk) {
            printf("%c", (char)top->rx_data);
            fflush(stdout);
        }

        main_time++;
    }

    set_nonblocking(false);
    delete top;
    return 0;
}

