// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vsinegen_dual__Syms.h"
#include "Vsinegen_dual.h"
#include "Vsinegen_dual___024root.h"

// FUNCTIONS
Vsinegen_dual__Syms::~Vsinegen_dual__Syms()
{
}

Vsinegen_dual__Syms::Vsinegen_dual__Syms(VerilatedContext* contextp, const char* namep, Vsinegen_dual* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
}
