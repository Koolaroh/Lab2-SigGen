// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VSINEGEN_DUAL__SYMS_H_
#define VERILATED_VSINEGEN_DUAL__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vsinegen_dual.h"

// INCLUDE MODULE CLASSES
#include "Vsinegen_dual___024root.h"

// SYMS CLASS (contains all model state)
class Vsinegen_dual__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vsinegen_dual* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vsinegen_dual___024root        TOP;

    // CONSTRUCTORS
    Vsinegen_dual__Syms(VerilatedContext* contextp, const char* namep, Vsinegen_dual* modelp);
    ~Vsinegen_dual__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
