#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default_id1.mk)" "nbproject/Makefile-local-default_id1.mk"
include nbproject/Makefile-local-default_id1.mk
endif
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default_id1
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/XModBus.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/XModBus.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=--mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=mcos/chips/pic16f688/pic16f688_interrupt.c mcos/chips/pic16f688/pic16f688_uart.c mcos/chips/pic16f688/board_manager_generic.c mcos/application.c mcos/fifo.c mcos/myeeprom.c mcos/myuart.c mcos/myiostream.c main.c id_1.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/mcos/chips/pic16f688/pic16f688_interrupt.p1 ${OBJECTDIR}/mcos/chips/pic16f688/pic16f688_uart.p1 ${OBJECTDIR}/mcos/chips/pic16f688/board_manager_generic.p1 ${OBJECTDIR}/mcos/application.p1 ${OBJECTDIR}/mcos/fifo.p1 ${OBJECTDIR}/mcos/myeeprom.p1 ${OBJECTDIR}/mcos/myuart.p1 ${OBJECTDIR}/mcos/myiostream.p1 ${OBJECTDIR}/main.p1 ${OBJECTDIR}/id_1.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/mcos/chips/pic16f688/pic16f688_interrupt.p1.d ${OBJECTDIR}/mcos/chips/pic16f688/pic16f688_uart.p1.d ${OBJECTDIR}/mcos/chips/pic16f688/board_manager_generic.p1.d ${OBJECTDIR}/mcos/application.p1.d ${OBJECTDIR}/mcos/fifo.p1.d ${OBJECTDIR}/mcos/myeeprom.p1.d ${OBJECTDIR}/mcos/myuart.p1.d ${OBJECTDIR}/mcos/myiostream.p1.d ${OBJECTDIR}/main.p1.d ${OBJECTDIR}/id_1.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/mcos/chips/pic16f688/pic16f688_interrupt.p1 ${OBJECTDIR}/mcos/chips/pic16f688/pic16f688_uart.p1 ${OBJECTDIR}/mcos/chips/pic16f688/board_manager_generic.p1 ${OBJECTDIR}/mcos/application.p1 ${OBJECTDIR}/mcos/fifo.p1 ${OBJECTDIR}/mcos/myeeprom.p1 ${OBJECTDIR}/mcos/myuart.p1 ${OBJECTDIR}/mcos/myiostream.p1 ${OBJECTDIR}/main.p1 ${OBJECTDIR}/id_1.p1

# Source Files
SOURCEFILES=mcos/chips/pic16f688/pic16f688_interrupt.c mcos/chips/pic16f688/pic16f688_uart.c mcos/chips/pic16f688/board_manager_generic.c mcos/application.c mcos/fifo.c mcos/myeeprom.c mcos/myuart.c mcos/myiostream.c main.c id_1.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default_id1.mk dist/${CND_CONF}/${IMAGE_TYPE}/XModBus.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=16F688
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/mcos/chips/pic16f688/pic16f688_interrupt.p1: mcos/chips/pic16f688/pic16f688_interrupt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcos/chips/pic16f688" 
	@${RM} ${OBJECTDIR}/mcos/chips/pic16f688/pic16f688_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/mcos/chips/pic16f688/pic16f688_interrupt.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1  --debugger=pickit3  --double=24 --float=24 --opt=+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=-3 --asmlist -DXPRJ_default_id1=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-osccal,-resetbits,-download,-stackcall,+clib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"     -o${OBJECTDIR}/mcos/chips/pic16f688/pic16f688_interrupt.p1 mcos/chips/pic16f688/pic16f688_interrupt.c 
	@-${MV} ${OBJECTDIR}/mcos/chips/pic16f688/pic16f688_interrupt.d ${OBJECTDIR}/mcos/chips/pic16f688/pic16f688_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcos/chips/pic16f688/pic16f688_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcos/chips/pic16f688/pic16f688_uart.p1: mcos/chips/pic16f688/pic16f688_uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcos/chips/pic16f688" 
	@${RM} ${OBJECTDIR}/mcos/chips/pic16f688/pic16f688_uart.p1.d 
	@${RM} ${OBJECTDIR}/mcos/chips/pic16f688/pic16f688_uart.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1  --debugger=pickit3  --double=24 --float=24 --opt=+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=-3 --asmlist -DXPRJ_default_id1=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-osccal,-resetbits,-download,-stackcall,+clib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"     -o${OBJECTDIR}/mcos/chips/pic16f688/pic16f688_uart.p1 mcos/chips/pic16f688/pic16f688_uart.c 
	@-${MV} ${OBJECTDIR}/mcos/chips/pic16f688/pic16f688_uart.d ${OBJECTDIR}/mcos/chips/pic16f688/pic16f688_uart.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcos/chips/pic16f688/pic16f688_uart.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcos/chips/pic16f688/board_manager_generic.p1: mcos/chips/pic16f688/board_manager_generic.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcos/chips/pic16f688" 
	@${RM} ${OBJECTDIR}/mcos/chips/pic16f688/board_manager_generic.p1.d 
	@${RM} ${OBJECTDIR}/mcos/chips/pic16f688/board_manager_generic.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1  --debugger=pickit3  --double=24 --float=24 --opt=+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=-3 --asmlist -DXPRJ_default_id1=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-osccal,-resetbits,-download,-stackcall,+clib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"     -o${OBJECTDIR}/mcos/chips/pic16f688/board_manager_generic.p1 mcos/chips/pic16f688/board_manager_generic.c 
	@-${MV} ${OBJECTDIR}/mcos/chips/pic16f688/board_manager_generic.d ${OBJECTDIR}/mcos/chips/pic16f688/board_manager_generic.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcos/chips/pic16f688/board_manager_generic.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcos/application.p1: mcos/application.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcos" 
	@${RM} ${OBJECTDIR}/mcos/application.p1.d 
	@${RM} ${OBJECTDIR}/mcos/application.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1  --debugger=pickit3  --double=24 --float=24 --opt=+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=-3 --asmlist -DXPRJ_default_id1=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-osccal,-resetbits,-download,-stackcall,+clib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"     -o${OBJECTDIR}/mcos/application.p1 mcos/application.c 
	@-${MV} ${OBJECTDIR}/mcos/application.d ${OBJECTDIR}/mcos/application.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcos/application.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcos/fifo.p1: mcos/fifo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcos" 
	@${RM} ${OBJECTDIR}/mcos/fifo.p1.d 
	@${RM} ${OBJECTDIR}/mcos/fifo.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1  --debugger=pickit3  --double=24 --float=24 --opt=+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=-3 --asmlist -DXPRJ_default_id1=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-osccal,-resetbits,-download,-stackcall,+clib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"     -o${OBJECTDIR}/mcos/fifo.p1 mcos/fifo.c 
	@-${MV} ${OBJECTDIR}/mcos/fifo.d ${OBJECTDIR}/mcos/fifo.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcos/fifo.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcos/myeeprom.p1: mcos/myeeprom.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcos" 
	@${RM} ${OBJECTDIR}/mcos/myeeprom.p1.d 
	@${RM} ${OBJECTDIR}/mcos/myeeprom.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1  --debugger=pickit3  --double=24 --float=24 --opt=+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=-3 --asmlist -DXPRJ_default_id1=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-osccal,-resetbits,-download,-stackcall,+clib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"     -o${OBJECTDIR}/mcos/myeeprom.p1 mcos/myeeprom.c 
	@-${MV} ${OBJECTDIR}/mcos/myeeprom.d ${OBJECTDIR}/mcos/myeeprom.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcos/myeeprom.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcos/myuart.p1: mcos/myuart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcos" 
	@${RM} ${OBJECTDIR}/mcos/myuart.p1.d 
	@${RM} ${OBJECTDIR}/mcos/myuart.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1  --debugger=pickit3  --double=24 --float=24 --opt=+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=-3 --asmlist -DXPRJ_default_id1=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-osccal,-resetbits,-download,-stackcall,+clib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"     -o${OBJECTDIR}/mcos/myuart.p1 mcos/myuart.c 
	@-${MV} ${OBJECTDIR}/mcos/myuart.d ${OBJECTDIR}/mcos/myuart.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcos/myuart.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcos/myiostream.p1: mcos/myiostream.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcos" 
	@${RM} ${OBJECTDIR}/mcos/myiostream.p1.d 
	@${RM} ${OBJECTDIR}/mcos/myiostream.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1  --debugger=pickit3  --double=24 --float=24 --opt=+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=-3 --asmlist -DXPRJ_default_id1=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-osccal,-resetbits,-download,-stackcall,+clib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"     -o${OBJECTDIR}/mcos/myiostream.p1 mcos/myiostream.c 
	@-${MV} ${OBJECTDIR}/mcos/myiostream.d ${OBJECTDIR}/mcos/myiostream.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcos/myiostream.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/main.p1: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.p1.d 
	@${RM} ${OBJECTDIR}/main.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1  --debugger=pickit3  --double=24 --float=24 --opt=+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=-3 --asmlist -DXPRJ_default_id1=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-osccal,-resetbits,-download,-stackcall,+clib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"     -o${OBJECTDIR}/main.p1 main.c 
	@-${MV} ${OBJECTDIR}/main.d ${OBJECTDIR}/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/id_1.p1: id_1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/id_1.p1.d 
	@${RM} ${OBJECTDIR}/id_1.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1  --debugger=pickit3  --double=24 --float=24 --opt=+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=-3 --asmlist -DXPRJ_default_id1=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-osccal,-resetbits,-download,-stackcall,+clib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"     -o${OBJECTDIR}/id_1.p1 id_1.c 
	@-${MV} ${OBJECTDIR}/id_1.d ${OBJECTDIR}/id_1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/id_1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/mcos/chips/pic16f688/pic16f688_interrupt.p1: mcos/chips/pic16f688/pic16f688_interrupt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcos/chips/pic16f688" 
	@${RM} ${OBJECTDIR}/mcos/chips/pic16f688/pic16f688_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/mcos/chips/pic16f688/pic16f688_interrupt.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --opt=+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=-3 --asmlist -DXPRJ_default_id1=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-osccal,-resetbits,-download,-stackcall,+clib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"     -o${OBJECTDIR}/mcos/chips/pic16f688/pic16f688_interrupt.p1 mcos/chips/pic16f688/pic16f688_interrupt.c 
	@-${MV} ${OBJECTDIR}/mcos/chips/pic16f688/pic16f688_interrupt.d ${OBJECTDIR}/mcos/chips/pic16f688/pic16f688_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcos/chips/pic16f688/pic16f688_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcos/chips/pic16f688/pic16f688_uart.p1: mcos/chips/pic16f688/pic16f688_uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcos/chips/pic16f688" 
	@${RM} ${OBJECTDIR}/mcos/chips/pic16f688/pic16f688_uart.p1.d 
	@${RM} ${OBJECTDIR}/mcos/chips/pic16f688/pic16f688_uart.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --opt=+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=-3 --asmlist -DXPRJ_default_id1=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-osccal,-resetbits,-download,-stackcall,+clib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"     -o${OBJECTDIR}/mcos/chips/pic16f688/pic16f688_uart.p1 mcos/chips/pic16f688/pic16f688_uart.c 
	@-${MV} ${OBJECTDIR}/mcos/chips/pic16f688/pic16f688_uart.d ${OBJECTDIR}/mcos/chips/pic16f688/pic16f688_uart.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcos/chips/pic16f688/pic16f688_uart.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcos/chips/pic16f688/board_manager_generic.p1: mcos/chips/pic16f688/board_manager_generic.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcos/chips/pic16f688" 
	@${RM} ${OBJECTDIR}/mcos/chips/pic16f688/board_manager_generic.p1.d 
	@${RM} ${OBJECTDIR}/mcos/chips/pic16f688/board_manager_generic.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --opt=+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=-3 --asmlist -DXPRJ_default_id1=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-osccal,-resetbits,-download,-stackcall,+clib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"     -o${OBJECTDIR}/mcos/chips/pic16f688/board_manager_generic.p1 mcos/chips/pic16f688/board_manager_generic.c 
	@-${MV} ${OBJECTDIR}/mcos/chips/pic16f688/board_manager_generic.d ${OBJECTDIR}/mcos/chips/pic16f688/board_manager_generic.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcos/chips/pic16f688/board_manager_generic.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcos/application.p1: mcos/application.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcos" 
	@${RM} ${OBJECTDIR}/mcos/application.p1.d 
	@${RM} ${OBJECTDIR}/mcos/application.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --opt=+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=-3 --asmlist -DXPRJ_default_id1=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-osccal,-resetbits,-download,-stackcall,+clib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"     -o${OBJECTDIR}/mcos/application.p1 mcos/application.c 
	@-${MV} ${OBJECTDIR}/mcos/application.d ${OBJECTDIR}/mcos/application.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcos/application.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcos/fifo.p1: mcos/fifo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcos" 
	@${RM} ${OBJECTDIR}/mcos/fifo.p1.d 
	@${RM} ${OBJECTDIR}/mcos/fifo.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --opt=+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=-3 --asmlist -DXPRJ_default_id1=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-osccal,-resetbits,-download,-stackcall,+clib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"     -o${OBJECTDIR}/mcos/fifo.p1 mcos/fifo.c 
	@-${MV} ${OBJECTDIR}/mcos/fifo.d ${OBJECTDIR}/mcos/fifo.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcos/fifo.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcos/myeeprom.p1: mcos/myeeprom.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcos" 
	@${RM} ${OBJECTDIR}/mcos/myeeprom.p1.d 
	@${RM} ${OBJECTDIR}/mcos/myeeprom.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --opt=+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=-3 --asmlist -DXPRJ_default_id1=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-osccal,-resetbits,-download,-stackcall,+clib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"     -o${OBJECTDIR}/mcos/myeeprom.p1 mcos/myeeprom.c 
	@-${MV} ${OBJECTDIR}/mcos/myeeprom.d ${OBJECTDIR}/mcos/myeeprom.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcos/myeeprom.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcos/myuart.p1: mcos/myuart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcos" 
	@${RM} ${OBJECTDIR}/mcos/myuart.p1.d 
	@${RM} ${OBJECTDIR}/mcos/myuart.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --opt=+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=-3 --asmlist -DXPRJ_default_id1=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-osccal,-resetbits,-download,-stackcall,+clib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"     -o${OBJECTDIR}/mcos/myuart.p1 mcos/myuart.c 
	@-${MV} ${OBJECTDIR}/mcos/myuart.d ${OBJECTDIR}/mcos/myuart.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcos/myuart.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcos/myiostream.p1: mcos/myiostream.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcos" 
	@${RM} ${OBJECTDIR}/mcos/myiostream.p1.d 
	@${RM} ${OBJECTDIR}/mcos/myiostream.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --opt=+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=-3 --asmlist -DXPRJ_default_id1=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-osccal,-resetbits,-download,-stackcall,+clib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"     -o${OBJECTDIR}/mcos/myiostream.p1 mcos/myiostream.c 
	@-${MV} ${OBJECTDIR}/mcos/myiostream.d ${OBJECTDIR}/mcos/myiostream.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcos/myiostream.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/main.p1: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.p1.d 
	@${RM} ${OBJECTDIR}/main.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --opt=+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=-3 --asmlist -DXPRJ_default_id1=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-osccal,-resetbits,-download,-stackcall,+clib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"     -o${OBJECTDIR}/main.p1 main.c 
	@-${MV} ${OBJECTDIR}/main.d ${OBJECTDIR}/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/id_1.p1: id_1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/id_1.p1.d 
	@${RM} ${OBJECTDIR}/id_1.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --opt=+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=-3 --asmlist -DXPRJ_default_id1=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-osccal,-resetbits,-download,-stackcall,+clib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"     -o${OBJECTDIR}/id_1.p1 id_1.c 
	@-${MV} ${OBJECTDIR}/id_1.d ${OBJECTDIR}/id_1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/id_1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/XModBus.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) --chip=$(MP_PROCESSOR_OPTION) -G -mdist/${CND_CONF}/${IMAGE_TYPE}/XModBus.X.${IMAGE_TYPE}.map  -D__DEBUG=1  --debugger=pickit3  -DXPRJ_default_id1=$(CND_CONF)  --double=24 --float=24 --opt=+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=-3 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-osccal,-resetbits,-download,-stackcall,+clib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"     --rom=default,-f00-fff --ram=default,-0-0,-70-70,-80-80,-f0-f0,-100-100,-165-170,-180-180,-1f0-1f0  $(COMPARISON_BUILD) --memorysummary dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -odist/${CND_CONF}/${IMAGE_TYPE}/XModBus.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} dist/${CND_CONF}/${IMAGE_TYPE}/XModBus.X.${IMAGE_TYPE}.hex 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/XModBus.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) --chip=$(MP_PROCESSOR_OPTION) -G -mdist/${CND_CONF}/${IMAGE_TYPE}/XModBus.X.${IMAGE_TYPE}.map  -DXPRJ_default_id1=$(CND_CONF)  --double=24 --float=24 --opt=+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=-3 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-osccal,-resetbits,-download,-stackcall,+clib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"     $(COMPARISON_BUILD) --memorysummary dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -odist/${CND_CONF}/${IMAGE_TYPE}/XModBus.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default_id1
	${RM} -r dist/default_id1

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
