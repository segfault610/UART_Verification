// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vuart_top__pch.h"

//============================================================
// Constructors

Vuart_top::Vuart_top(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vuart_top__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , tx_start{vlSymsp->TOP.tx_start}
    , tx_data{vlSymsp->TOP.tx_data}
    , rx_data{vlSymsp->TOP.rx_data}
    , rx_ready{vlSymsp->TOP.rx_ready}
    , parity_err{vlSymsp->TOP.parity_err}
    , tx_busy{vlSymsp->TOP.tx_busy}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vuart_top::Vuart_top(const char* _vcname__)
    : Vuart_top(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vuart_top::~Vuart_top() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vuart_top___024root___eval_debug_assertions(Vuart_top___024root* vlSelf);
#endif  // VL_DEBUG
void Vuart_top___024root___eval_static(Vuart_top___024root* vlSelf);
void Vuart_top___024root___eval_initial(Vuart_top___024root* vlSelf);
void Vuart_top___024root___eval_settle(Vuart_top___024root* vlSelf);
void Vuart_top___024root___eval(Vuart_top___024root* vlSelf);

void Vuart_top::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vuart_top::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vuart_top___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vuart_top___024root___eval_static(&(vlSymsp->TOP));
        Vuart_top___024root___eval_initial(&(vlSymsp->TOP));
        Vuart_top___024root___eval_settle(&(vlSymsp->TOP));
        vlSymsp->__Vm_didInit = true;
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vuart_top___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vuart_top::eventsPending() { return false; }

uint64_t Vuart_top::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vuart_top::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vuart_top___024root___eval_final(Vuart_top___024root* vlSelf);

VL_ATTR_COLD void Vuart_top::final() {
    Vuart_top___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vuart_top::hierName() const { return vlSymsp->name(); }
const char* Vuart_top::modelName() const { return "Vuart_top"; }
unsigned Vuart_top::threads() const { return 1; }
void Vuart_top::prepareClone() const { contextp()->prepareClone(); }
void Vuart_top::atClone() const {
    contextp()->threadPoolpOnClone();
}
