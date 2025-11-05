module rom2ports #(
    parameter ADDRESS_WIDTH = 8,
    parameter DATA_WIDTH    = 8
)(
    input  logic clk,
    input  logic [ADDRESS_WIDTH-1:0] addr1,   // Port 1 address
    input  logic [ADDRESS_WIDTH-1:0] addr2,   // Port 2 address
    output logic [DATA_WIDTH-1:0]    dout1,   // Port 1 data
    output logic [DATA_WIDTH-1:0]    dout2    // Port 2 data
);

    // 256 × 8 ROM array
    logic [DATA_WIDTH-1:0] rom_array [2**ADDRESS_WIDTH-1:0];

    // Load lookup table from file (same sine data as Task 1)
    initial begin
        $display("Loading ROM contents from sinerom.mem ...");
        $readmemh("sinerom.mem", rom_array);
    end

    // Synchronous read – both ports read on same clock edge
    always_ff @(posedge clk) begin
        dout1 <= rom_array[addr1];
        dout2 <= rom_array[addr2];
    end
endmodule
