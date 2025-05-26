[!/*
    @file    Lin_BaudRate_Comp.m
    @version 1.0.1

    @brief   AUTOSAR Lin - Baud rate computation for Lin_Cfg.c, Lin_PBcfg.c.
    @details Baud rate computation for Lin_Cfg.c, Lin_PBcfg.c
    
    Project AUTOSAR 4.4 MCAL
    Patform PA
    Peripheral LLDrivers
    Dependencies 
    
    ARVersion 4.4.0
*/!]
[!/*==================================================================================================
==================================================================================================
*/!]
[!VAR "ClockFrequencyFromMcu" = "McuClockReferencePointFrequency"!]
    [!VAR "LFDIV" = "($ClockFrequencyFromMcu div ($linBaudrate * 16))"!][//
    [!VAR "temp1" = "num:i($LFDIV)"!][!//
    [!VAR "temp2" = "$LFDIV - $temp1"!][!//
    [!VAR "LINFBRR" = "round($temp2 * 16)"!][!//
    [!VAR "LINFBRR" = "num:inttohex($LINFBRR,8)"!][!//
    [!VAR "LINIBRR" = "num:inttohex($temp1,8)"!][!//
    [!VAR "LINIBRR" = "num:hextoint($LINIBRR)"!][!//
    [!VAR "LINFBRR" = "num:hextoint($LINFBRR)"!][!//
    [!VAR "LINIBRR" = "bit:shl($LINIBRR,8)"!][!//
    [!VAR "LINIBRR_LINFBRR" = "bit:or($LINIBRR,$LINFBRR)"!][!//
    [!VAR "LINIBRR_LINFBRR" = "num:inttohex($LINIBRR_LINFBRR,8)"!][!//
