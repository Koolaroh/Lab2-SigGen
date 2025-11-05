#include "verilated.h"          // Verilator simulation header
#include "verilated_vcd_c.h"    // For waveform tracing
#include "Vsinegen_dual.h"      // Auto-generated header for dual sine generator
#include "vbuddy.cpp"           // Include Vbuddy helper functions

#define MAX_SIM_CYC 1000000     // Run simulation for 1 million cycles

int main(int argc, char **argv, char **env) {
    int simcyc, tick;           // simcyc = cycle count, tick = clock edge counter

    // Initialise Verilator and top-level module
    Verilated::commandArgs(argc, argv);
    Vsinegen_dual* top = new Vsinegen_dual;

    // Enable waveform tracing
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("sinegen_dual.vcd");

    // Initialise Vbuddy interface
    if (vbdOpen() != 1) return -1;
    vbdHeader("Lab 2: Dual Sine & Cosine Generator");
    vbdSetMode(1);    // One-shot mode for smoother plots

    // Apply reset for a few clock cycles
    top->clk = 0;
    top->rst = 1;
    top->en  = 1;
    for (int i = 0; i < 5; i++) {
        top->clk = !top->clk;
        top->eval();
        tfp->dump(i);
    }
    top->rst = 0;  // Release reset

    // Main simulation loop
    for (simcyc = 0; simcyc < MAX_SIM_CYC; simcyc++) {

        // Each full cycle = 2 clock ticks (posedge + negedge)
        for (tick = 0; tick < 2; tick++) {
            tfp->dump(2*simcyc + tick);
            top->clk = !top->clk;
            top->eval();
        }

        // Control inputs via Vbuddy rotary encoder
        // incr  controls frequency
        // offset controls phase
        top->incr   = 1;             // Keep frequency constant (or use vbdValue())
        top->offset = vbdValue();    // Use rotary knob for phase offset (0–255)

        // Display results on Vbuddy
        vbdPlot(int(top->data1), 0, 255);   // Plot first waveform
        vbdPlot(int(top->data2), 0, 255);   // Plot second waveform]
        vbdCycle(simcyc);                   // Display cycle counter

        // Exit simulation when 'q' is pressed or Verilator stops
        if ((Verilated::gotFinish()) || (vbdGetkey() == 'q')) break;
    }

    // Clean-up
    vbdClose();
    tfp->close();
    delete top;
    return 0;
}
