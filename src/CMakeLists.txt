
set(VALIDATE_SOURCES
    Validator.cpp
    ValidateException.cpp
    ValidateRegex.cpp
    ValidateIntRange.cpp
    ValidateString.cpp
    ValidateBool.cpp
    ValidateOptional.cpp
    ValidateCustom.cpp
)

add_library(validate SHARED ${VALIDATE_SOURCES})
add_library(validatestatic STATIC ${VALIDATE_SOURCES})
set_target_properties(validatestatic PROPERTIES OUTPUT_NAME validate)

target_include_directories(validate PUBLIC
    .
    ${JSONCPP_INCLUDE_DIRS}
)

target_include_directories(validatestatic PUBLIC
    .
    ${JSONCPP_INCLUDE_DIRS}
)

install(TARGETS validate validatestatic
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)

install(FILES libvalidate.h
    DESTINATION include
)

install(DIRECTORY libvalidate
    DESTINATION include
)

