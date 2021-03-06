/*
 * Copyright (c) 2014, Linaro Limited
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef PLATFORM_CONFIG_H
#define PLATFORM_CONFIG_H

#define PLATFORM_FLAVOR_ID_virt		0
#define PLATFORM_FLAVOR_IS(flav) \
        (PLATFORM_FLAVOR == PLATFORM_FLAVOR_ID_ ## flav)


#define PLATFORM_LINKER_FORMAT	"elf32-littlearm"
#define PLATFORM_LINKER_ARCH	arm

#if PLATFORM_FLAVOR_IS(virt)
#define SECURE_RAM_START	0x0e000000
#define SECURE_RAM_SIZE		0x01000000

#define DRAM_START		0x40000000

#define UART0_BASE		0x09000000
#define UART1_BASE		0x09040000


#else
#error "Unknown platform flavor"
#endif

#define CONSOLE_UART_BASE	UART0_BASE

#define DTB_MAX_SIZE		0x10000

/* secure RAM is 16MByte but reserve the last 4MB to SDP memory pool */
#define TZ_RES_MEM_START	SECURE_RAM_START
#define TZ_RES_MEM_SIZE		(SECURE_RAM_SIZE - 0x00400000)

#define DTB_START		DRAM_START
#define BIOS_RAM_START		(DRAM_START + 0x100000)

#endif /*PLATFORM_CONFIG_H*/
