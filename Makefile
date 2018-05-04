export LD_LIBRARY_PATH="${PWD}/lib"

BIN = ./bin
LIB = ./lib
OBJ = ./build
SRC = ./src
INC = ./include
TESTDIR = ./ut


CXX = g++
CFLAGS = -g -Wall -fPIC -I${INC}

GTEST_LIB = /usr/local/bin
GTEST_INC = /usr/local/include/gtest

TARGET = run_test
BIN_TARGET = ${BIN}/${TARGET}
TESTRCES = $(wildcard ${TESTDIR}/*.cc)
TESTOBJ = $(patsubst %.cc, ${TESTDIR}/%.o, $(notdir ${TESTRCES}))
all:${BIN_TARGET}

SOURCES = $(wildcard ${SRC}/*.cc)
OBJECT = $(patsubst %.cc, ${OBJ}/%.o, $(notdir ${SOURCES}))

STUMGRLIB = libstudentMgr.so
SHARED_LIB = ${LIB}/${STUMGRLIB}

${SHARED_LIB}:
	$(CXX) $(CFLAGS) ${SOURCES} -shared -o $@ 

${OBJ}/%.o : ${SRC}/%.cc 
	$(CXX) ${CFLAGS}-o $@ -c $<

${BIN_TARGET}: ${TESTOBJ} ${SHARED_LIB}
	$(CXX)  -o ${BIN_TARGET} ${TESTRCES} -I${INC} -lgtest -lpthread -L${GTEST_LIB} -I${GTEST_INC} -L${LIB} -lstudentMgr

${TESTDIR}/%.o : ${TESTDIR}/%.cc 
	$(CXX) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf ${BIN_TARGET}
	rm -rf ${OBJECT}
	rm -rf ${TESTOBJ}
	rm -rf ${SHARED_LIB}

