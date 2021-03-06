/* 
 * This file is part of Redqueen.
 *
 * Sergej Schumilo, 2019 <sergej@schumilo.de>
 * Cornelius Aschermann, 2019 <cornelius.aschermann@rub.de>
 *
 * SPDX-License-Identifier: GPL-2.0-or-later 
 */



#pragma once

#include "qemu/osdep.h"
#include "qemu-common.h"
#include "qemu/log.h"

#define QEMU_PT_PREFIX		    "[QEMU-PT] "
#define CORE_PREFIX			    "Core:  "
#define MEM_PREFIX			    "Mem:   "
#define RELOAD_PREFIX		    "Reload:"
#define PT_PREFIX			    "PT:    "
#define INTERFACE_PREFIX	    "Iface: "
#define REDQUEEN_PREFIX		    "Redq.: "
#define DISASM_PREFIX		    "Diasm: "

#define COLOR	                "\033[1;35m"
#define ENDC	                "\033[0m"

/* debug color */
#define QEMU_DEBUG_RED          "\033[1;31m"
#define QEMU_DEBUG_GREEN        "\033[1;32m"
#define QEMU_DEBUG_YELLOW       "\033[1;33m"
#define QEMU_DEBUG_BLUE         "\033[1;34m"
#define QEMU_DEBUG_MAGENTA      "\033[1;35m"
#define QEMU_DEBUG_CYAN         "\033[1;36m"
#define QEMU_DEBUG_ENDC         "\033[0m"

/* debug flag */
#define QEMU_DEBUG              1
#define QEMU_DEBUG_PKT			1
/* #define QEMU_DEBUG_DUMP         1 */
#define QEMU_DEBUG_FLOW         1
#define QEMU_DEBUG_DISASS		1

/* debug */
#define FLOW_PREFIX             "[FLOW] "
#define DISASS_PREFIX           "[DISASS] "

#define debug(format, ...)      fprintf(stderr, QEMU_DEBUG_YELLOW QEMU_PT_PREFIX QEMU_DEBUG_ENDC format "\n", ##__VA_ARGS__)
#define debug_flow(format, ...)      fprintf(stderr, QEMU_DEBUG_RED FLOW_PREFIX QEMU_DEBUG_ENDC format "\n", ##__VA_ARGS__)
#define debug_disass(format, ...)      fprintf(stderr, QEMU_DEBUG_CYAN DISASS_PREFIX QEMU_DEBUG_ENDC format "\n", ##__VA_ARGS__)

/* _PRINTF is the standard logging enabled with -D */
/* _DEBUG is activated with -d kafl cmdline */
/* _ERROR is printed to stdout (or logged if logging is enabled) */
#define QEMU_PT_PRINTF(PREFIX, format, ...) qemu_log(QEMU_PT_PREFIX PREFIX format "\n", ##__VA_ARGS__)
#define QEMU_PT_DEBUG(PREFIX, format, ...)  qemu_log_mask(LOG_KAFL, QEMU_PT_PREFIX PREFIX format "\n", ##__VA_ARGS__)
//#define QEMU_PT_DEBUG(PREFIX, format, ...) qemu_log_mask(LOG_KAFL, PREFIX "(%s#:%d)\t"format, __BASE_FILE__, __LINE__, ##__VA_ARGS__)
#define QEMU_PT_ERROR(PREFIX, format, ...)  printf(QEMU_PT_PREFIX PREFIX format "\n", ##__VA_ARGS__)