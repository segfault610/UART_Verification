`timescale 1ns/1ps
module uart_rx #(
    parameter CLK_FREQ = 27000000,
    parameter BAUD_RATE = 115200,
    parameter SIM_SPEED = 0
)(
    input  logic        clk,
    input  logic        rx,
    output logic [7:0]  data_out,
    output logic        data_ready,
    output logic        parity_err
);
    localparam integer REAL_WAIT = CLK_FREQ / BAUD_RATE;
    localparam integer WAIT_TIME = (SIM_SPEED) ? 10 : REAL_WAIT; 

    typedef enum logic [2:0] {IDLE, START, DATA, PARITY, STOP} state_t;
    state_t state = IDLE;
    logic [31:0] count = 0;
    logic [2:0]  bit_idx = 0;
    logic [7:0]  shift_reg = 0;
    logic        rx_parity;

    always_ff @(posedge clk) begin
        case (state)
            IDLE: begin
                data_ready <= 0;
                parity_err <= 0;
                count <= 0;
                if (rx == 0) state <= START;
            end
            START: begin
                if (count == (WAIT_TIME / 2)) begin 
                    count <= 0; 
                    state <= DATA; 
                end else count <= count + 1;
            end
            DATA: begin
                if (count == (WAIT_TIME - 1)) begin
                    count <= 0;
                    shift_reg[bit_idx] <= rx;
                    if (bit_idx == 7) begin 
                        bit_idx <= 0; 
                        state <= PARITY; 
                    end else bit_idx <= bit_idx + 1;
                end else count <= count + 1;
            end
            PARITY: begin
                if (count == (WAIT_TIME - 1)) begin
                    count <= 0;
                    rx_parity <= rx;
                    state <= STOP;
                end else count <= count + 1;
            end
            STOP: begin
                if (count == (WAIT_TIME - 1)) begin
                    data_out   <= shift_reg;
                    data_ready <= 1;
                    parity_err <= (rx_parity !== ^shift_reg);
                    state      <= IDLE;
                end else count <= count + 1;
            end
            default: state <= IDLE;
        endcase
    end
endmodule

