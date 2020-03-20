set(SRCS buffer.c hook.c trampoline.c hde/hde32.c hde/hde64.c)

# libMinHook.a
add_library(MinHook_static STATIC ${SRCS})
if(NOT MSVC)
    set_target_properties(MinHook_static PROPERTIES OUTPUT_NAME "MinHook")
endif()
target_compile_definitions(MinHook_static PRIVATE -DMH_BUILD)

# libMinHook.dll.a
add_library(MinHook SHARED ${SRCS} MinHook.rc MinHook.def)
set_target_properties(MinHook PROPERTIES PREFIX "")
target_compile_definitions(MinHook PRIVATE -DMH_DLL -DMH_BUILD)
