add_library(rvr-producer SHARED
  src/producer.cpp
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
