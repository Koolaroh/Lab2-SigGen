// Top-level module to capture and Delay Audio Signal
module sigdelay #(
    parameter ADDRESS_WIDTH = 9,  // 2^9 = 512 memory locations
    parameter DATA_WIDTH = 8      // 8-bit audio samples
)(
    input  logic clk,                               // Clock
    input  logic rst,                               // Reset
    input  logic en,                                // Enable (for counter)
    input  logic wr,              // write enable
    input  logic rd,              // read enable
    input  logic [DATA_WIDTH-1:0] mic_signal,       // Input audio from mic
    input  logic [ADDRESS_WIDTH-1:0] offset,        // Delay offset (from rotary encoder)
    output logic [DATA_WIDTH-1:0] delayed_signal    // Output delayed audio
);

    // Internal Signals
    logic [ADDRESS_WIDTH-1:0] wr_addr;   // Write address from counter
    logic [ADDRESS_WIDTH-1:0] rd_addr;   // Read address (write - offset)

    // 9-bit "1" for the increment
    // localparam logic [ADDRESS_WIDTH-1:0] ONE = {{(ADDRESS_WIDTH-1){1'b0}}, 1'b1};

    // 1. Instantiate Counter
    counter #(.WIDTH(ADDRESS_WIDTH)) addrCounter (
        .clk(clk),
        .rst(rst),
        .en(en),
        .incr(9'd1),             // Always increment by 1 each cycle
        .count(wr_addr)          // Output address
    );

    // 2. Compute Read Address (wr_addr - offset)
    // Subtract offset to create the delay effect
    assign rd_addr = wr_addr - offset;

    // 3. Instantiate Dual-Port RAM
    ram2ports #(
        .ADDRESS_WIDTH(ADDRESS_WIDTH),
        .DATA_WIDTH(DATA_WIDTH)
    ) signalRAM (
        .clk(clk),
        .wr_en(wr),            // Always write every clock
        .rd_en(rd),            // Always read every clock
        .wr_addr(wr_addr),       // Write address
        .rd_addr(rd_addr),       // Read address (delayed)
        .din(mic_signal),        // Input data from mic
        .dout(delayed_signal)    // Output delayed data
    );

endmodule
