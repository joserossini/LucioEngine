project (Sandbox VERSION 0.0.1 LANGUAGES C CXX)
add_executable(Sandbox "main.cpp")
target_link_libraries(Sandbox Lucio)
target_include_directories(Sandbox PUBLIC ${LUCIO_INLCUDE_DIR})
