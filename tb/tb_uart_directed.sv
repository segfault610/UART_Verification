module tb_uart_directed();
    logic clk = 0;
    logic rx_wire;
    logic [7:0] rx_data;
    logic rx_ready, parity_err;
    
    // Instantiate RX for testing
    uart_rx dut (.clk(clk), .rx(rx_wire), .data_out(rx_data), .data_ready(rx_ready), .parity_err(parity_err));

    always #18.5 clk = ~clk; // ~27MHz

    // Task to simulate a UART frame being sent to the RX
    task send_byte(input [7:0] data);
        integer i;
        logic p;
        p = ^data;
        rx_wire = 0; #34722; // Start (Baud 115200 timing)
        for(i=0; i<8; i++) begin rx_wire = data[i]; #34722; end
        rx_wire = p; #34722; // Parity
        rx_wire = 1; #34722; // Stop
        $display("[TB] Sent: 0x%h", data);
    endtask

    initial begin
        rx_wire = 1;
        #100;
        send_byte(8'h41); // 'A'
        send_byte(8'h5A); // 'Z'
        #100;
        $stop;
    end
endmodule

