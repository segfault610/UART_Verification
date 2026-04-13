// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vuart_top.h for the primary calling header

#ifndef VERILATED_VUART_TOP___024ROOT_H_
#define VERILATED_VUART_TOP___024ROOT_H_  // guard

#include "verilated.h"


class Vuart_top__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vuart_top___024root final {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(tx_start,0,0);
    VL_IN8(tx_data,7,0);
    VL_OUT8(rx_data,7,0);
    VL_OUT8(rx_ready,0,0);
    VL_OUT8(parity_err,0,0);
    VL_OUT8(tx_busy,0,0);
    CData/*0:0*/ uart_top__DOT__serial_wire;
    CData/*2:0*/ uart_top__DOT__tx_inst__DOT__state;
    CData/*2:0*/ uart_top__DOT__tx_inst__DOT__bit_idx;
    CData/*7:0*/ uart_top__DOT__tx_inst__DOT__data_reg;
    CData/*0:0*/ uart_top__DOT__tx_inst__DOT__parity_bit;
    CData/*2:0*/ uart_top__DOT__rx_inst__DOT__state;
    CData/*2:0*/ uart_top__DOT__rx_inst__DOT__bit_idx;
    CData/*7:0*/ uart_top__DOT__rx_inst__DOT__shift_reg;
    CData/*0:0*/ uart_top__DOT__rx_inst__DOT__rx_parity;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __VactPhaseResult;
    CData/*0:0*/ __VnbaPhaseResult;
    IData/*31:0*/ uart_top__DOT__tx_inst__DOT__count;
    IData/*31:0*/ uart_top__DOT__rx_inst__DOT__count;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vuart_top__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vuart_top___024root(Vuart_top__Syms* symsp, const char* namep);
    ~Vuart_top___024root();
    VL_UNCOPYABLE(Vuart_top___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
