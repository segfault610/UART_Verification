// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vuart_top.h for the primary calling header

#include "Vuart_top__pch.h"

void Vuart_top___024root___eval_triggers_vec__act(Vuart_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart_top___024root___eval_triggers_vec__act\n"); );
    Vuart_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    ((IData)(vlSelfRef.clk) 
                                                     & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0)))));
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
}

bool Vuart_top___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart_top___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Vuart_top___024root___nba_sequent__TOP__0(Vuart_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart_top___024root___nba_sequent__TOP__0\n"); );
    Vuart_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*2:0*/ __Vdly__uart_top__DOT__tx_inst__DOT__state;
    __Vdly__uart_top__DOT__tx_inst__DOT__state = 0;
    IData/*31:0*/ __Vdly__uart_top__DOT__tx_inst__DOT__count;
    __Vdly__uart_top__DOT__tx_inst__DOT__count = 0;
    CData/*2:0*/ __Vdly__uart_top__DOT__tx_inst__DOT__bit_idx;
    __Vdly__uart_top__DOT__tx_inst__DOT__bit_idx = 0;
    CData/*2:0*/ __Vdly__uart_top__DOT__rx_inst__DOT__state;
    __Vdly__uart_top__DOT__rx_inst__DOT__state = 0;
    IData/*31:0*/ __Vdly__uart_top__DOT__rx_inst__DOT__count;
    __Vdly__uart_top__DOT__rx_inst__DOT__count = 0;
    CData/*2:0*/ __Vdly__uart_top__DOT__rx_inst__DOT__bit_idx;
    __Vdly__uart_top__DOT__rx_inst__DOT__bit_idx = 0;
    // Body
    __Vdly__uart_top__DOT__tx_inst__DOT__state = vlSelfRef.uart_top__DOT__tx_inst__DOT__state;
    __Vdly__uart_top__DOT__tx_inst__DOT__count = vlSelfRef.uart_top__DOT__tx_inst__DOT__count;
    __Vdly__uart_top__DOT__tx_inst__DOT__bit_idx = vlSelfRef.uart_top__DOT__tx_inst__DOT__bit_idx;
    __Vdly__uart_top__DOT__rx_inst__DOT__state = vlSelfRef.uart_top__DOT__rx_inst__DOT__state;
    __Vdly__uart_top__DOT__rx_inst__DOT__count = vlSelfRef.uart_top__DOT__rx_inst__DOT__count;
    __Vdly__uart_top__DOT__rx_inst__DOT__bit_idx = vlSelfRef.uart_top__DOT__rx_inst__DOT__bit_idx;
    if ((4U & (IData)(vlSelfRef.uart_top__DOT__rx_inst__DOT__state))) {
        if ((2U & (IData)(vlSelfRef.uart_top__DOT__rx_inst__DOT__state))) {
            __Vdly__uart_top__DOT__rx_inst__DOT__state = 0U;
        } else if ((1U & (IData)(vlSelfRef.uart_top__DOT__rx_inst__DOT__state))) {
            __Vdly__uart_top__DOT__rx_inst__DOT__state = 0U;
        } else if ((0x000000e9U == vlSelfRef.uart_top__DOT__rx_inst__DOT__count)) {
            vlSelfRef.rx_data = vlSelfRef.uart_top__DOT__rx_inst__DOT__shift_reg;
            vlSelfRef.rx_ready = 1U;
            vlSelfRef.parity_err = ((IData)(vlSelfRef.uart_top__DOT__rx_inst__DOT__rx_parity) 
                                    != (1U & VL_REDXOR_8(vlSelfRef.uart_top__DOT__rx_inst__DOT__shift_reg)));
            __Vdly__uart_top__DOT__rx_inst__DOT__state = 0U;
        } else {
            __Vdly__uart_top__DOT__rx_inst__DOT__count 
                = ((IData)(1U) + vlSelfRef.uart_top__DOT__rx_inst__DOT__count);
        }
    } else if ((2U & (IData)(vlSelfRef.uart_top__DOT__rx_inst__DOT__state))) {
        if ((1U & (IData)(vlSelfRef.uart_top__DOT__rx_inst__DOT__state))) {
            if ((0x000000e9U == vlSelfRef.uart_top__DOT__rx_inst__DOT__count)) {
                __Vdly__uart_top__DOT__rx_inst__DOT__count = 0U;
                vlSelfRef.uart_top__DOT__rx_inst__DOT__rx_parity 
                    = vlSelfRef.uart_top__DOT__serial_wire;
                __Vdly__uart_top__DOT__rx_inst__DOT__state = 4U;
            } else {
                __Vdly__uart_top__DOT__rx_inst__DOT__count 
                    = ((IData)(1U) + vlSelfRef.uart_top__DOT__rx_inst__DOT__count);
            }
        } else if ((0x000000e9U == vlSelfRef.uart_top__DOT__rx_inst__DOT__count)) {
            __Vdly__uart_top__DOT__rx_inst__DOT__count = 0U;
            vlSelfRef.uart_top__DOT__rx_inst__DOT__shift_reg 
                = (((~ ((IData)(1U) << (IData)(vlSelfRef.uart_top__DOT__rx_inst__DOT__bit_idx))) 
                    & (IData)(vlSelfRef.uart_top__DOT__rx_inst__DOT__shift_reg)) 
                   | (0x00ffU & ((IData)(vlSelfRef.uart_top__DOT__serial_wire) 
                                 << (IData)(vlSelfRef.uart_top__DOT__rx_inst__DOT__bit_idx))));
            if ((7U == (IData)(vlSelfRef.uart_top__DOT__rx_inst__DOT__bit_idx))) {
                __Vdly__uart_top__DOT__rx_inst__DOT__bit_idx = 0U;
                __Vdly__uart_top__DOT__rx_inst__DOT__state = 3U;
            } else {
                __Vdly__uart_top__DOT__rx_inst__DOT__bit_idx 
                    = (7U & ((IData)(1U) + (IData)(vlSelfRef.uart_top__DOT__rx_inst__DOT__bit_idx)));
            }
        } else {
            __Vdly__uart_top__DOT__rx_inst__DOT__count 
                = ((IData)(1U) + vlSelfRef.uart_top__DOT__rx_inst__DOT__count);
        }
    } else if ((1U & (IData)(vlSelfRef.uart_top__DOT__rx_inst__DOT__state))) {
        if ((0x00000075U == vlSelfRef.uart_top__DOT__rx_inst__DOT__count)) {
            __Vdly__uart_top__DOT__rx_inst__DOT__count = 0U;
            __Vdly__uart_top__DOT__rx_inst__DOT__state = 2U;
        } else {
            __Vdly__uart_top__DOT__rx_inst__DOT__count 
                = ((IData)(1U) + vlSelfRef.uart_top__DOT__rx_inst__DOT__count);
        }
    } else {
        vlSelfRef.rx_ready = 0U;
        vlSelfRef.parity_err = 0U;
        __Vdly__uart_top__DOT__rx_inst__DOT__count = 0U;
        if ((1U & (~ (IData)(vlSelfRef.uart_top__DOT__serial_wire)))) {
            __Vdly__uart_top__DOT__rx_inst__DOT__state = 1U;
        }
    }
    vlSelfRef.uart_top__DOT__rx_inst__DOT__state = __Vdly__uart_top__DOT__rx_inst__DOT__state;
    vlSelfRef.uart_top__DOT__rx_inst__DOT__count = __Vdly__uart_top__DOT__rx_inst__DOT__count;
    vlSelfRef.uart_top__DOT__rx_inst__DOT__bit_idx 
        = __Vdly__uart_top__DOT__rx_inst__DOT__bit_idx;
    if ((4U & (IData)(vlSelfRef.uart_top__DOT__tx_inst__DOT__state))) {
        if ((2U & (IData)(vlSelfRef.uart_top__DOT__tx_inst__DOT__state))) {
            __Vdly__uart_top__DOT__tx_inst__DOT__state = 0U;
        } else if ((1U & (IData)(vlSelfRef.uart_top__DOT__tx_inst__DOT__state))) {
            __Vdly__uart_top__DOT__tx_inst__DOT__state = 0U;
        } else {
            vlSelfRef.uart_top__DOT__serial_wire = 1U;
            if ((0x000000e9U == vlSelfRef.uart_top__DOT__tx_inst__DOT__count)) {
                __Vdly__uart_top__DOT__tx_inst__DOT__state = 0U;
            } else {
                __Vdly__uart_top__DOT__tx_inst__DOT__count 
                    = ((IData)(1U) + vlSelfRef.uart_top__DOT__tx_inst__DOT__count);
            }
        }
    } else if ((2U & (IData)(vlSelfRef.uart_top__DOT__tx_inst__DOT__state))) {
        if ((1U & (IData)(vlSelfRef.uart_top__DOT__tx_inst__DOT__state))) {
            vlSelfRef.uart_top__DOT__serial_wire = vlSelfRef.uart_top__DOT__tx_inst__DOT__parity_bit;
            if ((0x000000e9U == vlSelfRef.uart_top__DOT__tx_inst__DOT__count)) {
                __Vdly__uart_top__DOT__tx_inst__DOT__count = 0U;
                __Vdly__uart_top__DOT__tx_inst__DOT__state = 4U;
            } else {
                __Vdly__uart_top__DOT__tx_inst__DOT__count 
                    = ((IData)(1U) + vlSelfRef.uart_top__DOT__tx_inst__DOT__count);
            }
        } else {
            vlSelfRef.uart_top__DOT__serial_wire = 
                (1U & ((IData)(vlSelfRef.uart_top__DOT__tx_inst__DOT__data_reg) 
                       >> (IData)(vlSelfRef.uart_top__DOT__tx_inst__DOT__bit_idx)));
            if ((0x000000e9U == vlSelfRef.uart_top__DOT__tx_inst__DOT__count)) {
                __Vdly__uart_top__DOT__tx_inst__DOT__count = 0U;
                if ((7U == (IData)(vlSelfRef.uart_top__DOT__tx_inst__DOT__bit_idx))) {
                    __Vdly__uart_top__DOT__tx_inst__DOT__bit_idx = 0U;
                    __Vdly__uart_top__DOT__tx_inst__DOT__state = 3U;
                } else {
                    __Vdly__uart_top__DOT__tx_inst__DOT__bit_idx 
                        = (7U & ((IData)(1U) + (IData)(vlSelfRef.uart_top__DOT__tx_inst__DOT__bit_idx)));
                }
            } else {
                __Vdly__uart_top__DOT__tx_inst__DOT__count 
                    = ((IData)(1U) + vlSelfRef.uart_top__DOT__tx_inst__DOT__count);
            }
        }
    } else if ((1U & (IData)(vlSelfRef.uart_top__DOT__tx_inst__DOT__state))) {
        vlSelfRef.uart_top__DOT__serial_wire = 0U;
        if ((0x000000e9U == vlSelfRef.uart_top__DOT__tx_inst__DOT__count)) {
            __Vdly__uart_top__DOT__tx_inst__DOT__count = 0U;
            __Vdly__uart_top__DOT__tx_inst__DOT__state = 2U;
        } else {
            __Vdly__uart_top__DOT__tx_inst__DOT__count 
                = ((IData)(1U) + vlSelfRef.uart_top__DOT__tx_inst__DOT__count);
        }
    } else {
        vlSelfRef.uart_top__DOT__serial_wire = 1U;
        vlSelfRef.tx_busy = 0U;
        if (vlSelfRef.tx_start) {
            __Vdly__uart_top__DOT__tx_inst__DOT__count = 0U;
            vlSelfRef.uart_top__DOT__tx_inst__DOT__data_reg 
                = vlSelfRef.tx_data;
            vlSelfRef.uart_top__DOT__tx_inst__DOT__parity_bit 
                = (1U & VL_REDXOR_8(vlSelfRef.tx_data));
            __Vdly__uart_top__DOT__tx_inst__DOT__state = 1U;
            vlSelfRef.tx_busy = 1U;
        }
    }
    vlSelfRef.uart_top__DOT__tx_inst__DOT__state = __Vdly__uart_top__DOT__tx_inst__DOT__state;
    vlSelfRef.uart_top__DOT__tx_inst__DOT__count = __Vdly__uart_top__DOT__tx_inst__DOT__count;
    vlSelfRef.uart_top__DOT__tx_inst__DOT__bit_idx 
        = __Vdly__uart_top__DOT__tx_inst__DOT__bit_idx;
}

void Vuart_top___024root___eval_nba(Vuart_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart_top___024root___eval_nba\n"); );
    Vuart_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vuart_top___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vuart_top___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart_top___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vuart_top___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vuart_top___024root___eval_phase__act(Vuart_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart_top___024root___eval_phase__act\n"); );
    Vuart_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vuart_top___024root___eval_triggers_vec__act(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vuart_top___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vuart_top___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

void Vuart_top___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart_top___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vuart_top___024root___eval_phase__nba(Vuart_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart_top___024root___eval_phase__nba\n"); );
    Vuart_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vuart_top___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vuart_top___024root___eval_nba(vlSelf);
        Vuart_top___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vuart_top___024root___eval(Vuart_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart_top___024root___eval\n"); );
    Vuart_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vuart_top___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("rtl/uart_top.sv", 3, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 10000 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vuart_top___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("rtl/uart_top.sv", 3, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 10000 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactPhaseResult = Vuart_top___024root___eval_phase__act(vlSelf);
        } while (vlSelfRef.__VactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = Vuart_top___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
}

#ifdef VL_DEBUG
void Vuart_top___024root___eval_debug_assertions(Vuart_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart_top___024root___eval_debug_assertions\n"); );
    Vuart_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");
    }
    if (VL_UNLIKELY(((vlSelfRef.tx_start & 0xfeU)))) {
        Verilated::overWidthError("tx_start");
    }
}
#endif  // VL_DEBUG
