include_directories(. ../include)

set(SRCS buffer.c hook.c trampoline.c hde/hde32.c hde/hde64.c)

# libMinHook.a
add_library(MinHook_static STATIC ${SRCS})

# libMinHook.dll.a
add_library(MinHook SHARED ${SRCS} MinHook.rc MinHook.def)
set_target_properties(MinHook PROPERTIES PREFIX "")
