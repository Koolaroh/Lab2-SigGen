module rom #(
    parameter ADDRESS_WIDTH = 8,
              DATA_WIDTH = 8
)(
    input  logic clk,
    input  logic [ADDRESS_WIDTH-1:0] addr,
    output logic [DATA_WIDTH-1:0] dout
);

    // Declare ROM array
    logic [DATA_WIDTH-1:0] rom_array [2**ADDRESS_WIDTH-1:0];

    // Initialize ROM contents from file
    initial begin
        $display("Loading ROM contents from sinerom.mem...");
        $readmemh("sinerom.mem", rom_array);
    end

    // Synchronous read
    always_ff @(posedge clk) begin
        dout <= rom_array[addr];
    end

endmodule
