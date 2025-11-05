#include "verilated.h"          // Verilator simulation header
#include "verilated_vcd_c.h"    // For waveform tracing (VCD)
#include "Vsinegen.h"           // Auto-generated header for top-level module
#include "vbuddy.cpp"           // Include Vbuddy helper functions

#define MAX_SIM_CYC 1000000     // Run simulation for 1 million cycles

int main(int argc, char **argv, char **env) {
    int simcyc, tick;           // simcyc = cycle counter, tick = clock edge tracker


    Verilated::commandArgs(argc, argv);   // Pass command line args to Verilator
    Vsinegen* top = new Vsinegen;         // Create instance of the DUT (Device Under Test)

    // Enable waveform tracing
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 99);                  // Trace up to 99 levels of hierarchy
    tfp->open("sinegen.vcd");             // Output waveform file (view in GTKWave)


    if (vbdOpen() != 1) return -1;        // Connect to Vbuddy device
    vbdHeader("Lab 2: Sinewave Generator"); // Display header text on Vbuddy screen
    vbdSetMode(1);                        // One-shot plotting mode (no flickering)


    // Start with reset active for a few clock cycles to ensure
    // all registers and memories are initialised correctly.
    top->clk = 0;                         // Initial clock value
    top->rst = 1;                         // Assert reset
    top->en  = 1;                         // Enable the counter
    for (int i = 0; i < 5; i++) {         // Hold reset for 5 cycles
        top->clk = !top->clk;             // Toggle clock
        top->eval();                      // Evaluate the model
        tfp->dump(i);                     // Record the waveform state
    }
    top->rst = 0;                         // Release reset

    // Main simulation loop
    for (simcyc = 0; simcyc < MAX_SIM_CYC; simcyc++) {

        // Each cycle has two ticks — one for rising edge, one for falling edge.
        // This keeps waveform timing precise (so each simcyc = 1 full clock cycle).
        for (tick = 0; tick < 2; tick++) {
            tfp->dump(2*simcyc + tick);   // Log timepoint to waveform
            top->clk = !top->clk;         // Toggle clock signal
            top->eval();                  // Evaluate the design for this edge
        }

        // Dynamic frequency control
        // The rotary encoder on Vbuddy sets 'incr' dynamically.
        // Changing 'incr' chaqnges how quickly the address in the ROM advances,
        // which in turn changes the sinewave frequency.
        top->incr = vbdValue();

        // Display and plot output
        // Plot the current output sample (dout) scaled between 0 and 255.
        // This displays a continuous sinewave on the Vbuddy TFT screen.
        vbdPlot(int(top->dout), 0, 255);

        // Show current simulation cycle count on screen.
        vbdCycle(simcyc);

        // Exit condition
        if ((Verilated::gotFinish()) || (vbdGetkey() == 'q')) break;
    }

    vbdClose();       // Close connection to Vbuddy
    tfp->close();     // Close waveform trace file
    delete top;       // Free the model instance

    return 0;         // Exit program cleanly
}
