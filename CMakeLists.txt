cmake_minimum_required(VERSION 3.5)

project(sparcematrix   VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

add_executable(sparcematrix main.cpp)
set_target_properties(sparcematrix PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)


if (MSVC)
    target_compile_options(sparcematrix PRIVATE
        /W4
    )
else ()
    target_compile_options(sparcematrix PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

install(TARGETS sparcematrix RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)

