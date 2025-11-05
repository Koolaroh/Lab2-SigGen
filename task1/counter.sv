// 8-bit programmable binary counter
module counter #(
    parameter WIDTH = 8
)(
    input  logic clk,                      // Clock signal
    input  logic rst,                      // Synchronous reset
    input  logic en,                       // Enable counter
    input  logic [WIDTH-1:0] incr,         // Increment value
    output logic [WIDTH-1:0] count         // Counter output
);

    // Trigger on the rising edge of the clock
    always_ff @(posedge clk) begin
        if (rst)
            count <= {WIDTH{1'b0}};        // Reset to 0
        else if (en)
            count <= count + incr;         // Increment by incr value
    end

endmodule
