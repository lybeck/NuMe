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
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/eps.o \
	${OBJECTDIR}/src/w1/w1e1.o \
	${OBJECTDIR}/src/w1/w1e2.o \
	${OBJECTDIR}/src/w1/w1e3.o \
	${OBJECTDIR}/src/w1/w1e4.o \
	${OBJECTDIR}/src/w1/w1e5.o \
	${OBJECTDIR}/src/w1/w1e6.o \
	${OBJECTDIR}/src/w2/w2e1.o \
	${OBJECTDIR}/src/w2/w2e2.o


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

${OBJECTDIR}/src/eps.o: src/eps.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/eps.o src/eps.cpp

${OBJECTDIR}/src/w1/w1e1.o: src/w1/w1e1.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w1
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w1/w1e1.o src/w1/w1e1.cpp

${OBJECTDIR}/src/w1/w1e2.o: src/w1/w1e2.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w1
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w1/w1e2.o src/w1/w1e2.cpp

${OBJECTDIR}/src/w1/w1e3.o: src/w1/w1e3.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w1
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w1/w1e3.o src/w1/w1e3.cpp

${OBJECTDIR}/src/w1/w1e4.o: src/w1/w1e4.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w1
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w1/w1e4.o src/w1/w1e4.cpp

${OBJECTDIR}/src/w1/w1e5.o: src/w1/w1e5.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w1
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w1/w1e5.o src/w1/w1e5.cpp

${OBJECTDIR}/src/w1/w1e6.o: src/w1/w1e6.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w1
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w1/w1e6.o src/w1/w1e6.cpp

${OBJECTDIR}/src/w2/w2e1.o: src/w2/w2e1.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w2
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w2/w2e1.o src/w2/w2e1.cpp

${OBJECTDIR}/src/w2/w2e2.o: src/w2/w2e2.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/w2
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/w2/w2e2.o src/w2/w2e2.cpp

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
