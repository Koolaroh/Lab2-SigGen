// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vsinegen_dual.h"
#include "Vsinegen_dual__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vsinegen_dual::Vsinegen_dual(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vsinegen_dual__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , en{vlSymsp->TOP.en}
    , incr{vlSymsp->TOP.incr}
    , offset{vlSymsp->TOP.offset}
    , data1{vlSymsp->TOP.data1}
    , data2{vlSymsp->TOP.data2}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vsinegen_dual::Vsinegen_dual(const char* _vcname__)
    : Vsinegen_dual(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vsinegen_dual::~Vsinegen_dual() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vsinegen_dual___024root___eval_initial(Vsinegen_dual___024root* vlSelf);
void Vsinegen_dual___024root___eval_settle(Vsinegen_dual___024root* vlSelf);
void Vsinegen_dual___024root___eval(Vsinegen_dual___024root* vlSelf);
#ifdef VL_DEBUG
void Vsinegen_dual___024root___eval_debug_assertions(Vsinegen_dual___024root* vlSelf);
#endif  // VL_DEBUG
void Vsinegen_dual___024root___final(Vsinegen_dual___024root* vlSelf);

static void _eval_initial_loop(Vsinegen_dual__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vsinegen_dual___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vsinegen_dual___024root___eval_settle(&(vlSymsp->TOP));
        Vsinegen_dual___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void Vsinegen_dual::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vsinegen_dual::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vsinegen_dual___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vsinegen_dual___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

const char* Vsinegen_dual::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vsinegen_dual::final() {
    Vsinegen_dual___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vsinegen_dual::hierName() const { return vlSymsp->name(); }
const char* Vsinegen_dual::modelName() const { return "Vsinegen_dual"; }
unsigned Vsinegen_dual::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> Vsinegen_dual::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vsinegen_dual___024root__trace_init_top(Vsinegen_dual___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vsinegen_dual___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsinegen_dual___024root*>(voidSelf);
    Vsinegen_dual__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vsinegen_dual___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vsinegen_dual___024root__trace_register(Vsinegen_dual___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vsinegen_dual::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vsinegen_dual___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
