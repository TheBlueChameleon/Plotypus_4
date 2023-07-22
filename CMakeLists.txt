cmake_minimum_required(VERSION 3.5)

# ============================================================================ #
# lanugage definition

project(Plotypus_4
    VERSION 4.0.1
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ============================================================================ #
# library definition

add_library(Plotypus-lib SHARED
    src/plotypus.h src/plotypus.cpp

    src/typesystem/concepts.h
    src/typesystem/constants.h
    src/typesystem/errors.h src/typesystem/errors.cpp
    src/typesystem/enums.h
    src/typesystem/types.h

    src/interface/collection.h
    src/interface/fragment.h
    src/interface/persistable.h
    src/interface/namedtype.h
    src/interface/nonAssignable.h
    src/interface/scriptable.h
    src/interface/serializable.h
    src/interface/terminalInfoProvider.h
    src/interface/textable.h

    src/base/userCodeFragment.h src/base/userCodeFragment.cpp
    src/base/persistableimpl.h src/base/persistableimpl.cpp
    src/base/polymorphiclist.h src/base/polymorphiclist.txx
    src/base/validationresult.h src/base/validationresult.txx src/base/validationresult.cpp

    src/base/terminalInfoProvider/abstractterminalinfoprovider.h src/base/terminalInfoProvider/abstractterminalinfoprovider.cpp
    src/base/terminalInfoProvider/backgroundfragment.h src/base/terminalInfoProvider/backgroundfragment.cpp
    src/base/terminalInfoProvider/colorfragment.h src/base/terminalInfoProvider/colorfragment.cpp
    src/base/terminalInfoProvider/continuoussizefragment.h src/base/terminalInfoProvider/continuoussizefragment.cpp
    src/base/terminalInfoProvider/enhancedfragment.h src/base/terminalInfoProvider/enhancedfragment.cpp
    src/base/terminalInfoProvider/fontfragment.h src/base/terminalInfoProvider/fontfragment.cpp
    src/base/terminalInfoProvider/lineendsfragment.h src/base/terminalInfoProvider/lineendsfragment.cpp

    src/report/outputPathProvider.h src/report/outputPathProvider.cpp
    src/report/report.h src/report/report.txx src/report/report.cpp

    src/report/terminalInfoProvider/pdfcairo.h src/report/terminalInfoProvider/pdfcairo.cpp
)

set_target_properties(Plotypus-lib PROPERTIES
    VERSION   ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION}
    PUBLIC_HEADER src/plotypus.h
)

target_precompile_headers(Plotypus-lib PUBLIC
  src/plotypus.h
)

add_executable(Plotypus-showcase
    src/main.cpp
)

target_link_libraries(Plotypus-showcase
    Plotypus-lib
)

# ============================================================================ #
# unit test

enable_testing()
add_definitions(-DGTEST_LANGUAGE_CXX11)

find_package(Threads REQUIRED)

if ($ENV{GOOGLETEST_DIR})
    set(GOOGLETEST_DIR $ENV{GOOGLETEST_DIR})
else ()
    if (NOT "" STREQUAL "")
        message(WARNING "Using googletest src dir specified at Qt Creator wizard")
    endif ()
    set(GOOGLETEST_DIR "")
endif ()

if (EXISTS ${GOOGLETEST_DIR})
    set(GTestSrc ${GOOGLETEST_DIR}/googletest)
    set(GMockSrc ${GOOGLETEST_DIR}/googlemock)
elseif (UNIX AND EXISTS /usr/src/gtest)
    set(GTestSrc /usr/src/gtest)
    message(WARNING "Using gtest from system")
    if (EXISTS /usr/src/gmock)
        set(GMockSrc /usr/src/gmock)
    endif ()
else ()
    message( FATAL_ERROR "No googletest src dir found - set GOOGLETEST_DIR to enable!")
endif ()

set(GTestFiles ${GTestSrc}/src/gtest-all.cc)
set(GTestIncludes ${GTestSrc} ${GTestSrc}/include)
if (NOT ${GMockSrc} STREQUAL "")
    list(APPEND GTestFiles ${GMockSrc}/src/gmock-all.cc)
    list(APPEND GTestIncludes ${GMockSrc} ${GMockSrc}/include)
endif ()

include_directories(${GTestIncludes})

# ============================================================================ #
# test files

add_executable(Plotypus_Test
    unittest/src/main.cpp
    unittest/src/tst_collection.cpp
    unittest/src/tst_filesystem.cpp

    unittest/src/TerminalInfoProvider/tst_PdfCairo.cpp

    ${GTestFiles}
)

add_test(NAME Plotypus_Test COMMAND Collection_Test)

target_include_directories(Plotypus_Test
    # paths relative to build directory
    PRIVATE src/
)
target_link_libraries(Plotypus_Test
    PRIVATE Threads::Threads
    PRIVATE Plotypus-lib
)

