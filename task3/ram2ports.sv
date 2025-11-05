// Dual-Port RAM (512 x 8)
module ram2ports #(
    parameter ADDRESS_WIDTH = 9,    // 2^9 = 512 memory locations
    parameter DATA_WIDTH = 8        // Each location is 8 bits wide
)(
    input  logic clk,                              // Clock signal
    input  logic wr_en,                            // Write enable
    input  logic rd_en,                            // Read enable
    input  logic [ADDRESS_WIDTH-1:0] wr_addr,      // Write address
    input  logic [ADDRESS_WIDTH-1:0] rd_addr,      // Read address
    input  logic [DATA_WIDTH-1:0] din,             // Data input (to write)
    output logic [DATA_WIDTH-1:0] dout             // Data output (read)
);

    // Declare the actual memory array: 512 rows, each 8 bits wide
    logic [DATA_WIDTH-1:0] ram_array [2**ADDRESS_WIDTH-1:0];

    // Synchronous operations (triggered on rising clock edge)
    always_ff @(posedge clk) begin
        // Write operation
        if (wr_en)
            ram_array[wr_addr] <= din;

        // Read operation
        if (rd_en)
            dout <= ram_array[rd_addr];
    end

endmodule
