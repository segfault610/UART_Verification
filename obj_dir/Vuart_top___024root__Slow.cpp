// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vuart_top.h for the primary calling header

#include "Vuart_top__pch.h"

void Vuart_top___024root___ctor_var_reset(Vuart_top___024root* vlSelf);

Vuart_top___024root::Vuart_top___024root(Vuart_top__Syms* symsp, const char* namep)
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vuart_top___024root___ctor_var_reset(this);
}

void Vuart_top___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vuart_top___024root::~Vuart_top___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
