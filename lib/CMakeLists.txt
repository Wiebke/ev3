
set (headers src/auxiliary.h src/common.h src/exceptions.h  src/expression.h src/operand.h src/parser.h src/tree.h)
set (sources src/parser.cxx src/expression.cxx src/operand.cxx)

add_library (ev3 ${sources} ${headers})

if (BUILD_SHARED_LIBS)
	add_compile_definitions (EV3_DLL)
endif()

install (TARGETS ev3
         RUNTIME DESTINATION bin
         LIBRARY DESTINATION lib${LIB_SUFFIX}
         ARCHIVE DESTINATION lib${LIB_SUFFIX})

install (FILES ${headers} DESTINATION include/ev3)

add_subdirectory (test)

