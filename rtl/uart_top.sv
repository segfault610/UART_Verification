module uart_top #(parameter SIM_SPEED = 1) (
    input  logic clk,
    input  logic tx_start,
    input  logic [7:0] tx_data,
    output logic [7:0] rx_data,
    output logic rx_ready,
    output logic parity_err,
    output logic tx_busy
);
    logic serial_wire;

    uart_tx #(.SIM_SPEED(SIM_SPEED)) tx_inst (
        .clk(clk), .tx_start(tx_start), .tx_data(tx_data),
        .tx_pin(serial_wire), .tx_busy(tx_busy)
    );

    uart_rx #(.SIM_SPEED(SIM_SPEED)) rx_inst (
        .clk(clk), .rx(serial_wire), .data_out(rx_data),
        .data_ready(rx_ready), .parity_err(parity_err)
    );
endmodule

