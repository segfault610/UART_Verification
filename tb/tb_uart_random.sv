`timescale 1ns/1ps
module tb_uart_random();
    // Testbench signals
    logic clk = 0;
    logic tx_start = 0;
    logic [7:0] tx_data;
    logic [7:0] rx_data;
    logic rx_ready, parity_err, tx_busy;

    logic [7:0] scoreboard[$]; 
    integer pass_count = 0;
    integer fail_count = 0;

    // Instantiate DUT
    uart_top #(.SIM_SPEED(1)) dut (.*);

    always #5 clk = ~clk; 

    initial begin
        // --- SELECTIVE VCD GENERATION ---
        $dumpfile("uart_sim.vcd");
        
        // $dumpvars arguments: (level, signal1, signal2, ...)
        // Level 0 ensures we only get the specific signals listed
        $dumpvars(0, clk);
        $dumpvars(0, tx_start);
        $dumpvars(0, tx_data);
        $dumpvars(0, dut.serial_wire); // The internal connection between TX and RX
        $dumpvars(0, rx_data);
        $dumpvars(0, rx_ready);
        $dumpvars(0, parity_err);
        $dumpvars(0, tx_busy);
        
        $display("--- Starting Fast Random Testbench (Essential VCD) ---");
        #100;

        for (int i = 0; i < 50; i++) begin
            wait(!tx_busy);
            
            tx_data = $urandom_range(0, 255);
            scoreboard.push_back(tx_data);
            
            @(posedge clk);
            tx_start = 1;
            @(posedge clk);
            tx_start = 0;

            fork : timeout_block
                begin
                    wait(rx_ready);
                    disable timeout_block;
                end
                begin
                    #2000;
                    $display("[FAIL] Transaction %0d: TIMEOUT", i);
                    $finish;
                end
            join

            if (rx_data === scoreboard.pop_front()) begin
                $display("[PASS] Transaction %0d: Sent 0x%h, Received 0x%h", i, tx_data, rx_data);
                pass_count++;
            end else begin
                $display("[FAIL] Transaction %0d: MISMATCH", i);
                fail_count++;
            end
            
            repeat(5) @(posedge clk);
        end

        $display("--- Final Results ---");
        $display("Total Passed: %0d | Total Failed: %0d", pass_count, fail_count);
        
        $dumpoff; 
        $finish;
    end
endmodule

