
FILE(GLOB SRCS *.cpp)
FILE(GLOB HDRS *.h)

ADD_EXECUTABLE(gdchopper
	${SRCS}
	${HDRS}
	)

target_link_libraries(gdchopper
	libgdemu
	)
