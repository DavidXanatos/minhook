# sample.exe
add_executable(sample sample.c)

if(1)
    # use static library
    target_link_libraries(sample PRIVATE MinHook_static)
else()
    # use shared library
    target_link_libraries(sample PRIVATE MinHook)
    target_compile_definitions(sample PRIVATE -DMH_DLL)
endif()
