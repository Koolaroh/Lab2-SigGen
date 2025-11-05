module sinegen #(
    parameter A_WIDTH = 8,
    parameter D_WIDTH = 8
)(
    input  logic clk,       // Clock
    input  logic rst,       // Reset
    input  logic en,        // Enable
    input  logic [A_WIDTH-1:0] incr, // Increment step
    output logic [D_WIDTH-1:0] dout  // Sine output
);

    // Internal signal: address output from counter, used as ROM address
    logic [A_WIDTH-1:0] address;

    // Instantiate the counter module
    counter addrCounter (
        .clk (clk),
        .rst (rst),
        .en  (en),
        .incr(incr),
        .count(address)
    );

    // Instantiate the ROM module
    rom sineRom (
        .clk (clk),
        .addr(address),
        .dout(dout)
    );

endmodule
