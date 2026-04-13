`timescale 1ns/1ps
/* verilator lint_off PROCASSINIT */

module uart_tx #(
    parameter CLK_FREQ = 27000000,
    parameter BAUD_RATE = 115200,
    parameter SIM_SPEED = 0
)(
    input  logic       clk,
    input  logic       tx_start,
    input  logic [7:0] tx_data,
    output logic       tx_pin,
    output logic       tx_busy
);
    localparam integer REAL_WAIT = CLK_FREQ / BAUD_RATE;
    localparam integer WAIT_TIME = (SIM_SPEED) ? 10 : REAL_WAIT; 

    typedef enum logic [2:0] {IDLE, START, DATA, PARITY, STOP} state_t;
    
    // Initialized at declaration: Supported by ModelSim & Verilator (with lint off)
    state_t state      = IDLE;
    logic [31:0] count = 0;
    logic [2:0]  bit_idx = 0;
    logic [7:0]  data_reg = 0;
    logic        parity_bit = 0;

    always_ff @(posedge clk) begin
        case (state)
            IDLE: begin
                tx_pin  <= 1;
                tx_busy <= 0;
                if (tx_start) begin
                    data_reg   <= tx_data;
                    parity_bit <= ^tx_data; 
                    state      <= START;
                    tx_busy    <= 1;
                    count      <= 0;
                end
            end
            START: begin
                tx_pin <= 0;
                if (count == WAIT_TIME[31:0] - 1) begin 
                    count <= 0; 
                    state <= DATA; 
                end else count <= count + 1;
            end
            DATA: begin
                tx_pin <= data_reg[bit_idx];
                if (count == WAIT_TIME[31:0] - 1) begin
                    count <= 0;
                    if (bit_idx == 7) begin 
                        bit_idx <= 0; 
                        state   <= PARITY; 
                    end else bit_idx <= bit_idx + 1;
                end else count <= count + 1;
            end
            PARITY: begin
                tx_pin <= parity_bit;
                if (count == WAIT_TIME[31:0] - 1) begin 
                    count <= 0; 
                    state <= STOP; 
                end else count <= count + 1;
            end
            STOP: begin
                tx_pin <= 1;
                if (count == WAIT_TIME[31:0] - 1) state <= IDLE;
                else count <= count + 1;
            end
            default: state <= IDLE;
        endcase
    end
endmodule

