// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vsinegen_dual.h for the primary calling header

#ifndef VERILATED_VSINEGEN_DUAL___024ROOT_H_
#define VERILATED_VSINEGEN_DUAL___024ROOT_H_  // guard

#include "verilated.h"

class Vsinegen_dual__Syms;

class Vsinegen_dual___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(en,0,0);
    VL_IN8(incr,7,0);
    VL_IN8(offset,7,0);
    VL_OUT8(data1,7,0);
    VL_OUT8(data2,7,0);
    CData/*7:0*/ sinegen_dual__DOT__address1;
    CData/*0:0*/ __Vclklast__TOP__clk;
    VlUnpacked<CData/*7:0*/, 256> sinegen_dual__DOT__sineRom__DOT__rom_array;

    // INTERNAL VARIABLES
    Vsinegen_dual__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vsinegen_dual___024root(Vsinegen_dual__Syms* symsp, const char* name);
    ~Vsinegen_dual___024root();
    VL_UNCOPYABLE(Vsinegen_dual___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
