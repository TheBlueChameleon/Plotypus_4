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

    # typesystem
    src/typesystem/concepts.h
    src/typesystem/constants.h
    src/typesystem/errors.h src/typesystem/errors.cpp
    src/typesystem/enums.h
    src/typesystem/types.h

    # base
    src/base/baseproperties/collection.h
    src/base/baseproperties/mutable.h
    src/base/baseproperties/namedtype.h
    src/base/baseproperties/nonassignable.h
    src/base/baseproperties/persistable.h
    src/base/baseproperties/propagatingpersistable.h
    src/base/baseproperties/validatable.h

    src/base/baseproperties/collection/array.h src/base/baseproperties/collection/array.txx
    src/base/baseproperties/collection/arrayiterable.h src/base/baseproperties/collection/arrayiterable.txx
    src/base/baseproperties/collection/arrayconstiterable.h src/base/baseproperties/collection/arrayconstiterable.txx
    src/base/baseproperties/collection/fifo.h src/base/baseproperties/collection/fifo.txx
    src/base/baseproperties/collection/fifoiterable.h src/base/baseproperties/collection/fifoiterable.txx
    src/base/baseproperties/collection/fifoconstiterable.h src/base/baseproperties/collection/fifoconstiterable.txx

    src/base/baseproperties/persistable/defaultpersistable.h src/base/baseproperties/persistable/defaultpersistable.cpp
    src/base/baseproperties/persistable/defaultpropagatingpersistable.h src/base/baseproperties/persistable/defaultpropagatingpersistable.cpp

    src/base/groupedproperties/scriptfragment.h src/base/groupedproperties/scriptfragment.cpp
    src/base/groupedproperties/scriptable.h
    src/base/groupedproperties/serializable.h
    src/base/groupedproperties/numbereditem.h
    src/base/groupedproperties/userscriptinjectable.h

    src/base/groupedproperties/defaultImpl/defaultnumbereditem.h src/base/groupedproperties/defaultImpl/defaultnumbereditem.cpp
    src/base/groupedproperties/defaultImpl/defaultuserscriptinjectable.h src/base/groupedproperties/defaultImpl/defaultuserscriptinjectable.cpp

    src/base/fragments/genericfontfragment.h src/base/fragments/genericfontfragment.cpp
    src/base/fragments/usercodefragment.h src/base/fragments/usercodefragment.cpp

    src/base/validationresult/validationresult.h src/base/validationresult/validationresult.txx src/base/validationresult/validationresult.cpp

    # report
    src/report/outputpathprovider.h src/report/outputpathprovider.cpp
    src/report/report.h src/report/report.txx src/report/report.cpp

    src/report/terminalinfoprovider/terminalinfoprovider.h
    src/report/terminalinfoprovider/pdfcairo.h src/report/terminalinfoprovider/pdfcairo.cpp

    src/report/terminalinfoprovider/fragments/backgroundfragment.h src/report/terminalinfoprovider/fragments/backgroundfragment.cpp
    src/report/terminalinfoprovider/fragments/colorfragment.h src/report/terminalinfoprovider/fragments/colorfragment.cpp
    src/report/terminalinfoprovider/fragments/continuoussizefragment.h src/report/terminalinfoprovider/fragments/continuoussizefragment.cpp
    src/report/terminalinfoprovider/fragments/enhancedfragment.h src/report/terminalinfoprovider/fragments/enhancedfragment.cpp
    src/report/terminalinfoprovider/fragments/fontfragment.h src/report/terminalinfoprovider/fragments/fontfragment.cpp
    src/report/terminalinfoprovider/fragments/lineendsfragment.h src/report/terminalinfoprovider/fragments/lineendsfragment.cpp

    # sheet
    src/sheet/sheet.h src/sheet/sheet.cpp
    src/sheet/emptysheet.h src/sheet/emptysheet.cpp

    src/sheet/fragments/cleansheetfragment.h src/sheet/fragments/cleansheetfragment.cpp
    src/sheet/fragments/fontfragment.h src/sheet/fragments/fontfragment.cpp
    src/sheet/fragments/titlefragment.h src/sheet/fragments/titlefragment.cpp
)

target_include_directories(Plotypus-lib PUBLIC
    src/
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
    unittest/src/tst_validation.cpp

    unittest/src/report/tst_outputpathprovider.cpp

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

