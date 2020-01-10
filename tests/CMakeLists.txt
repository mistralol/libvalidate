
add_executable(TestValidator TestValidator.cpp)
target_link_libraries(TestValidator PRIVATE validate ${JSONCPP_LIBRARIES})
add_test(TestValidator "./TestValidator")
