vlib work
vmap work work

vlog -sv ../rtl/uart_tx.sv
vlog -sv ../rtl/uart_rx.sv
vlog -sv ../rtl/uart_top.sv
vlog -sv ../tb/tb_uart_random.sv

vsim -c -do "run -all; quit -f" work.tb_uart_random

