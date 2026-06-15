set(RVR_REMOTE_FRAME_PRODUCER_HEADERS
	include/rvr/producer/producer.h
	include/rvr/producer/producer_export.h
)

set(RVR_REMOTE_FRAME_PRODUCER_SOURCES
	src/producer.cpp
)

add_library(rvr-producer SHARED
	${RVR_REMOTE_FRAME_PRODUCER_HEADERS}
	${RVR_REMOTE_FRAME_PRODUCER_SOURCES}
)

add_library(RVR::Producer
	ALIAS
	rvr-producer
)

target_include_directories(rvr-producer
	PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE:include>
)

target_compile_definitions(rvr-producer
	PRIVATE RVR_PRODUCER_BUILD
)

install(TARGETS rvr-producer
	RUNTIME DESTINATION bin
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
)

install(
	DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
	DESTINATION include
)
