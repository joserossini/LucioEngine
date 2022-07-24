#pragma once

struct SDL_Window;
typedef void * SDL_GLContext;
union SDL_Event;

namespace lucio{

    template<typename T, typename... Args>
	class CallBack;

    class Window;
	class Event;
	
    class Renderer;
    class Shader;
    class Mesh;

    struct vertex_t;
	struct view_t;
	struct perspective_t;
}

namespace lucio::util{
    class FileManager;
}