GCC		= g++ -g -O0 -Wall -Wextra -std=gnu++14
MKDEP		= g++ -MM -std=gnu++14 
VALGRIND	= valgrind --leak-check=full --show-reachable=yes

MKFILE		= Makefile
DEPFILE		= Makefile.dep 
SOURCES		= qattr.cpp gfunc.cpp main.cpp
HEADERS		= qattr.h gfunc.h
EXECBIN		= tree
OBJECTS		= ${SOURCES:.cpp=.o} 
SRCFILES	= ${HEADERS} ${SOURCES} ${MKFILE}

all : ${EXECBIN}

${EXECBIN} : ${OBJECTS}
	${GCC} -o${EXECBIN} ${OBJECTS}

${OBJECTS} : ${SOURCES}
	${GCC} -c ${SOURCES}
      

%.o : %.cpp
	${GCC} -c $<

clean :
	- rm ${OBJECTS}

${DEPFILE} :
	${MKDEP} ${SOURCES} >${DEPFILE}

dep :
	- rm ${DEPFILE}
	${MAKE} --no-print-directory ${DEPFILE}

