module sinegen_dual #(
    parameter A_WIDTH = 8,   // Address width
    parameter D_WIDTH = 8    // Data width
)(
    input  logic clk,                 // Clock
    input  logic rst,                 // Reset
    input  logic en,                  // Enable
    input  logic [A_WIDTH-1:0] incr,  // Frequency control
    input  logic [A_WIDTH-1:0] offset,// Phase offset control
    output logic [D_WIDTH-1:0] data1, // First sine output
    output logic [D_WIDTH-1:0] data2  // Second phase-shifted output
);

    // Internal address signal from counter
    logic [A_WIDTH-1:0] address1;

    // Counter produces base address
    counter addrCounter (
        .clk   (clk),
        .rst   (rst),
        .en    (en),
        .incr  (incr),
        .count (address1)
    );

    // Compute second address with phase offset
    // Wrap-around occurs automatically due to 8-bit addition
    logic [A_WIDTH-1:0] address2;
    assign address2 = address1 + offset;

    // Dual-port ROM outputs two samples each clock
    rom2ports sineRom (
        .clk   (clk),
        .addr1 (address1),
        .addr2 (address2),
        .dout1 (data1),
        .dout2 (data2)
    );

endmodule
