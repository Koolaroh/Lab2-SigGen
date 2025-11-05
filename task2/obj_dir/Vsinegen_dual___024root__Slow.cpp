// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsinegen_dual.h for the primary calling header

#include "verilated.h"

#include "Vsinegen_dual__Syms.h"
#include "Vsinegen_dual___024root.h"

void Vsinegen_dual___024root___ctor_var_reset(Vsinegen_dual___024root* vlSelf);

Vsinegen_dual___024root::Vsinegen_dual___024root(Vsinegen_dual__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vsinegen_dual___024root___ctor_var_reset(this);
}

void Vsinegen_dual___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vsinegen_dual___024root::~Vsinegen_dual___024root() {
}
