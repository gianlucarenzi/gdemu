
FILE(GLOB SRCS *.cpp)
FILE(GLOB HDRS *.h)

ADD_EXECUTABLE(gdinvaders
	${SRCS}
	${HDRS}
	)

target_link_libraries(gdinvaders
	libgdemu
	)
