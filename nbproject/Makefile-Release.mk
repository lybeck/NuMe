#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/test/jam.o \
	${OBJECTDIR}/src/test/polytest.o \
	${OBJECTDIR}/src/test/segfault.o \
	${OBJECTDIR}/src/test/t1.o \
	${OBJECTDIR}/src/test/testSurf.o \
	${OBJECTDIR}/src/w1/w1e1.o \
	${OBJECTDIR}/src/w1/w1e2.o \
	${OBJECTDIR}/src/w1/w1e3.o \
	${OBJECTDIR}/src/w1/w1e4.o \
	${OBJECTDIR}/src/w1/w1e5.o \
	${OBJECTDIR}/src/w1/w1e6.o \
	${OBJECTDIR}/src/w2/w2e1-plot.o \
	${OBJECTDIR}/src/w2/w2e1.o \
	${OBJECTDIR}/src/w2/w2e2.o \
	${OBJECTDIR}/src/w2/w2e3.o \
	${OBJECTDIR}/src/w2/w2e4.o \
	${OBJECTDIR}/src/w2/w2e5.o \
	${OBJECTDIR}/src/w3/w3e1.o \
	${OBJECTDIR}/src/w3/w3e2.o \
	${OBJECTDIR}/src/w3/w3e3.o \
	${OBJECTDIR}/src/w3/w3e4.o \
	${OBJECTDIR}/src/w3/w3e5.o \
	${OBJECTDIR}/src/w4/w4e1.o \
	${OBJECTDIR}/src/w4/w4e2.o \
	${OBJECTDIR}/src/w4/w4e4.o \
	${OBJECTDIR}/src/w4/w4e5.o \
	${OBJECTDIR}/src/w5/w5e1.o \
	${OBJECTDIR}/src/w5/w5e2.o \
	${OBJECTDIR}/src/w5/w5e3.o \
	${OBJECTDIR}/src/w5/w5e4.o \
	${OBJECTDIR}/src/w5/w5e5.o \
	${OBJECTDIR}/src/w5/w5e6.o \
	${OBJECTDIR}/src/w6/w6e1.o \
	${OBJECTDIR}/src/w6/w6e2.o \
	${OBJECTDIR}/src/w6/w6e3.o \
	${OBJECTDIR}/src/w6/w6e4.o \
	${OBJECTDIR}/src/w6/w6e5.o \
	${OBJECTDIR}/src/w7/w7e1.o \
	${OBJECTDIR}/src/w7/w7e5.o \
	${OBJECTDIR}/src/w8/w8e1.o \
	${OBJECTDIR}/src/w8/w8e5.o \
	${OBJECTDIR}/src/w9/w9e1.o \
	${OBJECTDIR}/src/w9/w9e4.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/nume

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/nume: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/nume ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/src/test/jam.o: src/test/jam.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/test
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/test/jam.o src/test/jam.cpp

${OBJECTDIR}/src/test/polytest.o: src/test/polytest.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/test
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/test/polytest.o src/test/polytest.cpp

${OBJECTDIR}/src/test/segfault.o: src/test/segfault.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/test
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/test/segfault.o src/test/segfault.cpp

${OBJECTDIR}/src/test/t1.o: src/test/t1.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/test
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/test/t1.o src/test/t1.cpp

${OBJECTDIR}/src/test/testSurf.o: src/test/testSurf.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/test
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/test/testSurf.o src/test/testSurf.cpp

${OBJECTDIR}/src/w1/w1e1.o: src/w1/w1e1.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w1
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w1/w1e1.o src/w1/w1e1.cpp

${OBJECTDIR}/src/w1/w1e2.o: src/w1/w1e2.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w1
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w1/w1e2.o src/w1/w1e2.cpp

${OBJECTDIR}/src/w1/w1e3.o: src/w1/w1e3.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w1
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w1/w1e3.o src/w1/w1e3.cpp

${OBJECTDIR}/src/w1/w1e4.o: src/w1/w1e4.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w1
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w1/w1e4.o src/w1/w1e4.cpp

${OBJECTDIR}/src/w1/w1e5.o: src/w1/w1e5.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w1
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w1/w1e5.o src/w1/w1e5.cpp

${OBJECTDIR}/src/w1/w1e6.o: src/w1/w1e6.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w1
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w1/w1e6.o src/w1/w1e6.cpp

${OBJECTDIR}/src/w2/w2e1-plot.o: src/w2/w2e1-plot.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w2
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w2/w2e1-plot.o src/w2/w2e1-plot.cpp

${OBJECTDIR}/src/w2/w2e1.o: src/w2/w2e1.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w2
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w2/w2e1.o src/w2/w2e1.cpp

${OBJECTDIR}/src/w2/w2e2.o: src/w2/w2e2.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w2
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w2/w2e2.o src/w2/w2e2.cpp

${OBJECTDIR}/src/w2/w2e3.o: src/w2/w2e3.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w2
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w2/w2e3.o src/w2/w2e3.cpp

${OBJECTDIR}/src/w2/w2e4.o: src/w2/w2e4.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w2
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w2/w2e4.o src/w2/w2e4.cpp

${OBJECTDIR}/src/w2/w2e5.o: src/w2/w2e5.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w2
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w2/w2e5.o src/w2/w2e5.cpp

${OBJECTDIR}/src/w3/w3e1.o: src/w3/w3e1.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w3
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w3/w3e1.o src/w3/w3e1.cpp

${OBJECTDIR}/src/w3/w3e2.o: src/w3/w3e2.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w3
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w3/w3e2.o src/w3/w3e2.cpp

${OBJECTDIR}/src/w3/w3e3.o: src/w3/w3e3.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w3
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w3/w3e3.o src/w3/w3e3.cpp

${OBJECTDIR}/src/w3/w3e4.o: src/w3/w3e4.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w3
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w3/w3e4.o src/w3/w3e4.cpp

${OBJECTDIR}/src/w3/w3e5.o: src/w3/w3e5.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w3
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w3/w3e5.o src/w3/w3e5.cpp

${OBJECTDIR}/src/w4/w4e1.o: src/w4/w4e1.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w4
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w4/w4e1.o src/w4/w4e1.cpp

${OBJECTDIR}/src/w4/w4e2.o: src/w4/w4e2.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w4
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w4/w4e2.o src/w4/w4e2.cpp

${OBJECTDIR}/src/w4/w4e4.o: src/w4/w4e4.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w4
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w4/w4e4.o src/w4/w4e4.cpp

${OBJECTDIR}/src/w4/w4e5.o: src/w4/w4e5.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w4
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w4/w4e5.o src/w4/w4e5.cpp

${OBJECTDIR}/src/w5/w5e1.o: src/w5/w5e1.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w5
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w5/w5e1.o src/w5/w5e1.cpp

${OBJECTDIR}/src/w5/w5e2.o: src/w5/w5e2.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w5
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w5/w5e2.o src/w5/w5e2.cpp

${OBJECTDIR}/src/w5/w5e3.o: src/w5/w5e3.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w5
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w5/w5e3.o src/w5/w5e3.cpp

${OBJECTDIR}/src/w5/w5e4.o: src/w5/w5e4.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w5
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w5/w5e4.o src/w5/w5e4.cpp

${OBJECTDIR}/src/w5/w5e5.o: src/w5/w5e5.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w5
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w5/w5e5.o src/w5/w5e5.cpp

${OBJECTDIR}/src/w5/w5e6.o: src/w5/w5e6.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w5
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w5/w5e6.o src/w5/w5e6.cpp

${OBJECTDIR}/src/w6/w6e1.o: src/w6/w6e1.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w6
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w6/w6e1.o src/w6/w6e1.cpp

${OBJECTDIR}/src/w6/w6e2.o: src/w6/w6e2.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w6
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w6/w6e2.o src/w6/w6e2.cpp

${OBJECTDIR}/src/w6/w6e3.o: src/w6/w6e3.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w6
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w6/w6e3.o src/w6/w6e3.cpp

${OBJECTDIR}/src/w6/w6e4.o: src/w6/w6e4.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w6
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w6/w6e4.o src/w6/w6e4.cpp

${OBJECTDIR}/src/w6/w6e5.o: src/w6/w6e5.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w6
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w6/w6e5.o src/w6/w6e5.cpp

${OBJECTDIR}/src/w7/w7e1.o: src/w7/w7e1.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w7
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w7/w7e1.o src/w7/w7e1.cpp

${OBJECTDIR}/src/w7/w7e5.o: src/w7/w7e5.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w7
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w7/w7e5.o src/w7/w7e5.cpp

${OBJECTDIR}/src/w8/w8e1.o: src/w8/w8e1.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w8
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w8/w8e1.o src/w8/w8e1.cpp

${OBJECTDIR}/src/w8/w8e5.o: src/w8/w8e5.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w8
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w8/w8e5.o src/w8/w8e5.cpp

${OBJECTDIR}/src/w9/w9e1.o: src/w9/w9e1.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w9
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w9/w9e1.o src/w9/w9e1.cpp

${OBJECTDIR}/src/w9/w9e4.o: src/w9/w9e4.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w9
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w9/w9e4.o src/w9/w9e4.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/nume

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
