include(CTest)
link_libraries(${PROJECT_NAME})
set(E2ETEST ${PROJECT_NAME}_e2etest)

add_executable(${E2ETEST} test_main.cc)

target_link_libraries(${E2ETEST} PRIVATE Drogon::Drogon gtest gtest_main pthread)
add_test(e2etest ${E2ETEST})