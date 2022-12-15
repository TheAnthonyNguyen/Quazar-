# Last updated: 2022-09-11 Nicole Wilson <n.wilson@uleth.ca>
# The targets in this file are used in .gitlab-ci.yml and 
# the files created are found in the .gitignore
# Changing any names below can change the target names which 
# will require that you update .gitlab_ci.yml and .gitignore
PROJECT = quazar

# Compilation command and flags
CXX=g++
CXXVERSION= -std=c++11
CXXFLAGS= ${CXXVERSION} -g -fprofile-arcs -ftest-coverage
LINKFLAGS= -lgtest

# Directories
SRC_DIR = src
SRC_INCLUDE = include
INCLUDE = -I ${SRC_INCLUDE}

STATIC_ANALYSIS = cppcheck

# The variable STYLE_CHECK is dependant on whether make is called from Ubuntu,
# the lab machines and office machines (this includes student0, student1,
# student2, and faculty0), or from gitlab which uses Centos.
# OS is a variable set and exported when .bashrc is run (found in etc/bashrc}
ifeq (${OS},ubuntu)
	STYLE_CHECK = cpplint
else
	STYLE_CHECK = cpplint.py
endif

# Default goal, used by Atom for local compilation
.DEFAULT_GOAL := compileProject

# default rule for compiling .cc to .o
%.o: %.cpp
	${CXX} ${CXXFLAGS} -c $< -o $@

# clean up all files that should NOT be submitted
.PHONY: clean
clean:
	rm -rf *~ ${SRC}/*.o ${GTEST_DIR}/output/*.dat \
	*.gcov *.gcda *.gcno \
	${PROJECT} ${COVERAGE_RESULTS} \
	${GTEST} ${MEMCHECK_RESULTS} ${COVERAGE_DIR}  \
	${PROJECT}.exe ${GTEST}.exe

# compilation using the files in include, src, and src/project, but not test
compileProject: ${SRC_DIR}/*.cpp 
	${CXX} ${CXXVERSION} -o ${PROJECT} ${INCLUDE} ${SRC_DIR}/*.cpp

# To perform all tests
all: static style

.PHONY: static
static: ${SRC_DIR}
	${STATIC_ANALYSIS} --std=c++11 --verbose --enable=all ${SRC_DIR} ${SRC_INCLUDE} --suppress=missingInclude --error-exitcode=1

.PHONY: style
style: ${SRC_DIR} ${SRC_INCLUDE}
	${STYLE_CHECK} ${SRC_DIR}/*  ${SRC_INCLUDE}/* ${PROJECT_SRC_DIR}/*
	
