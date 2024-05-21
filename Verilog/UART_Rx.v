`timescale 1ns/1ns

module UART_Rx (
    parameter UART_CLK_CNT = , 
) 
(
    input wire rst,
    input wire clk,
    input wire uart_rx_pin,
    output reg [7:0] uart_rx_data,
);

    parameter UART_CLK_CNT_HALF = UART_CLK_CNT / 2;
    reg [16:0] clk_cnt;
    reg [1:0] bit_cnt;
    reg receive_begin;
    reg start_signal;

    always @(posedge clk or negedge rst) begin
        if (!rst) begin
            uart_rx_data <= 8'b0;
            start_signal <= 0;
            clk_cnt <= 0;
        end else begin
            if (!receive_begin) begin
                if (!uart_rx_pin) begin
                    receive_begin <= 1;
                    clk_cnt <= 0;
                    bit_cnt <= 0;
                    start_signal <= 1;
                end
            end else begin
                clk_cnt <= clk_cnt + 1;

                if (clk_cnt == UART_CLK_CNT_HALF && start_signal == 1) begin
                    start_signal <= 0; 
                    clk_cnt <= 0;
                end else if (clk_cnt == UART_CLK_CNT) begin
                    if (bit_cnt < data_width) begin
                        uart_rx_data[bit_cnt] <= uart_rx_pin;
                        bit_cnt <= bit_cnt + 1;
                    end else begin
                        receive_begin <= 0;
                    end
                    clk_cnt <= 0;
                end
            end
        end
    end

endmodule