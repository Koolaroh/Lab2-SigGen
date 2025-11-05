// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsinegen_dual.h for the primary calling header

#include "verilated.h"

#include "Vsinegen_dual___024root.h"

VL_INLINE_OPT void Vsinegen_dual___024root___sequent__TOP__0(Vsinegen_dual___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsinegen_dual__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsinegen_dual___024root___sequent__TOP__0\n"); );
    // Init
    CData/*7:0*/ __Vdly__sinegen_dual__DOT__address1;
    // Body
    __Vdly__sinegen_dual__DOT__address1 = vlSelf->sinegen_dual__DOT__address1;
    if (vlSelf->rst) {
        __Vdly__sinegen_dual__DOT__address1 = 0U;
    } else if (vlSelf->en) {
        __Vdly__sinegen_dual__DOT__address1 = (0xffU 
                                               & ((IData)(vlSelf->sinegen_dual__DOT__address1) 
                                                  + (IData)(vlSelf->incr)));
    }
    vlSelf->data1 = vlSelf->sinegen_dual__DOT__sineRom__DOT__rom_array
        [vlSelf->sinegen_dual__DOT__address1];
    vlSelf->data2 = vlSelf->sinegen_dual__DOT__sineRom__DOT__rom_array
        [(0xffU & ((IData)(vlSelf->sinegen_dual__DOT__address1) 
                   + (IData)(vlSelf->offset)))];
    vlSelf->sinegen_dual__DOT__address1 = __Vdly__sinegen_dual__DOT__address1;
}

void Vsinegen_dual___024root___eval(Vsinegen_dual___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsinegen_dual__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsinegen_dual___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vsinegen_dual___024root___sequent__TOP__0(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

#ifdef VL_DEBUG
void Vsinegen_dual___024root___eval_debug_assertions(Vsinegen_dual___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsinegen_dual__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsinegen_dual___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->en & 0xfeU))) {
        Verilated::overWidthError("en");}
}
#endif  // VL_DEBUG
