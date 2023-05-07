
if (CMAKE_SYSTEM MATCHES Windows)
	message (STATUS "Target system is Windows")
elseif (CMAKE_SYSTEM MATCHES Linux)
	message (STATUS "Target system is Linux")
	include (FindPkgConfig)

	pkg_check_modules (SDL REQUIRED sdl2)
endif()

if (DEFINED GRAPHICS_BACKEND)
	message (STATUS "Graphics backend: " ${GRAPHICS_BACKEND})
else()
	set (GRAPHICS_BACKEND OpenGLES)
	message (STATUS "Graphics backend by default: " ${GRAPHICS_BACKEND})
endif()

set (INCLUDE_GRAPHICS
	BackendGraphics/${GRAPHICS_BACKEND}
	)

if (GRAPHICS_BACKEND MATCHES OpenGLES)
	pkg_check_modules (GRAPHICS REQUIRED glesv2)
	add_definitions (-DOPENGLES)
	set (SOURCES_GRAPHICS
		BackendGraphics/OpenGLES/Graphics.cpp
		BackendGraphics/OpenGLES/Shader.cpp
		)
elseif (GRAPHICS_BACKEND MATCHES OpenGL)
	set (SOURCES_GRAPHICS
		BackendGraphics/OpenGL/Graphics.cpp
		)
elseif (GRAPHICS_BACKEND MATCHES Vulkan)
	set (SOURCES_GRAPHICS
		BackendGraphics/Vulkan/Graphics.cpp
		)
endif()

set (EVENT_SYSTEM
	EventSystem/EventSystem.cpp
	)

set (UI
	UI/Widget.cpp
	)

set (SOURCES
	Main.cpp
	${UI}
	${EVENT_SYSTEM}
	)

add_executable (modern_3d_engine ${SOURCES} ${SOURCES_GRAPHICS})

target_include_directories (modern_3d_engine PRIVATE
	${SDL_INCLUDE_DIRS}
	${GRAPHICS_INCLUDE_DIRS}
	${INCLUDE_GRAPHICS}
	"."
	)

target_link_libraries (modern_3d_engine PRIVATE
	${SDL_LIBRARIES}
	${GRAPHICS_LIBRARIES}
	)

set (EXECUTABLE_OUTPUT_PATH ..)
