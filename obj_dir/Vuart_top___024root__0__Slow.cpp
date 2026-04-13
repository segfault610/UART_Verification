// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vuart_top.h for the primary calling header

#include "Vuart_top__pch.h"

VL_ATTR_COLD void Vuart_top___024root___eval_static(Vuart_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart_top___024root___eval_static\n"); );
    Vuart_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.uart_top__DOT__tx_inst__DOT__state = 0U;
    vlSelfRef.uart_top__DOT__tx_inst__DOT__count = 0U;
    vlSelfRef.uart_top__DOT__tx_inst__DOT__bit_idx = 0U;
    vlSelfRef.uart_top__DOT__tx_inst__DOT__data_reg = 0U;
    vlSelfRef.uart_top__DOT__tx_inst__DOT__parity_bit = 0U;
    vlSelfRef.uart_top__DOT__rx_inst__DOT__state = 0U;
    vlSelfRef.uart_top__DOT__rx_inst__DOT__count = 0U;
    vlSelfRef.uart_top__DOT__rx_inst__DOT__bit_idx = 0U;
    vlSelfRef.uart_top__DOT__rx_inst__DOT__shift_reg = 0U;
    vlSelfRef.uart_top__DOT__rx_inst__DOT__rx_parity = 0U;
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
}

VL_ATTR_COLD void Vuart_top___024root___eval_static__TOP(Vuart_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart_top___024root___eval_static__TOP\n"); );
    Vuart_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.uart_top__DOT__tx_inst__DOT__state = 0U;
    vlSelfRef.uart_top__DOT__tx_inst__DOT__count = 0U;
    vlSelfRef.uart_top__DOT__tx_inst__DOT__bit_idx = 0U;
    vlSelfRef.uart_top__DOT__tx_inst__DOT__data_reg = 0U;
    vlSelfRef.uart_top__DOT__tx_inst__DOT__parity_bit = 0U;
    vlSelfRef.uart_top__DOT__rx_inst__DOT__state = 0U;
    vlSelfRef.uart_top__DOT__rx_inst__DOT__count = 0U;
    vlSelfRef.uart_top__DOT__rx_inst__DOT__bit_idx = 0U;
    vlSelfRef.uart_top__DOT__rx_inst__DOT__shift_reg = 0U;
    vlSelfRef.uart_top__DOT__rx_inst__DOT__rx_parity = 0U;
}

VL_ATTR_COLD void Vuart_top___024root___eval_initial(Vuart_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart_top___024root___eval_initial\n"); );
    Vuart_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vuart_top___024root___eval_final(Vuart_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart_top___024root___eval_final\n"); );
    Vuart_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vuart_top___024root___eval_settle(Vuart_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart_top___024root___eval_settle\n"); );
    Vuart_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

bool Vuart_top___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vuart_top___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart_top___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vuart_top___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vuart_top___024root___ctor_var_reset(Vuart_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart_top___024root___ctor_var_reset\n"); );
    Vuart_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->tx_start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10922211238440073863ull);
    vlSelf->tx_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14770307426006424685ull);
    vlSelf->rx_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15001017414173623810ull);
    vlSelf->rx_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11148549331561456454ull);
    vlSelf->parity_err = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2005957896020366822ull);
    vlSelf->tx_busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1130330860826808631ull);
    vlSelf->uart_top__DOT__serial_wire = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18399672372510789066ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
}
