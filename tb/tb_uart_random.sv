`timescale 1ns/1ps
module tb_uart_random();
    logic clk = 0;
    logic tx_start = 0;
    logic [7:0] tx_data;
    logic [7:0] rx_data;
    logic rx_ready, parity_err, tx_busy;

    logic [7:0] scoreboard[$]; 
    integer pass_count = 0;
    integer fail_count = 0;

    // Use SIM_SPEED = 1 for instant simulation
    uart_top #(.SIM_SPEED(1)) dut (.*);

    // 100MHz simulation clock (10ns period)
    always #5 clk = ~clk; 

    initial begin
        $display("--- Starting Fast Random Testbench ---");
        #100;

        for (int i = 0; i < 50; i++) begin
            // 1. Ensure TX is ready
            wait(!tx_busy);
            
            // 2. Prepare Data
            tx_data = $urandom_range(0, 255);
            scoreboard.push_back(tx_data);
            
            // 3. Send Data
            @(posedge clk);
            tx_start = 1;
            @(posedge clk);
            tx_start = 0;

            // 4. Wait for Receive with a timeout
            fork : timeout_block
                begin
                    wait(rx_ready);
                    disable timeout_block;
                end
                begin
                    #2000; // If it doesn't receive in 2000ns, something is wrong
                    $display("[FAIL] Transaction %0d: TIMEOUT", i);
                    $finish;
                end
            join

            // 5. Verify Scoreboard
            if (rx_data === scoreboard.pop_front()) begin
                $display("[PASS] Transaction %0d: Sent 0x%h, Received 0x%h", i, tx_data, rx_data);
                pass_count++;
            end else begin
                $display("[FAIL] Transaction %0d: MISMATCH", i);
                fail_count++;
            end
            
            // 6. Mandatory gap for State Machine reset
            repeat(5) @(posedge clk);
        end

        $display("--- Final Results ---");
        $display("Total Passed: %0d | Total Failed: %0d", pass_count, fail_count);
        $finish;
    end
endmodule

