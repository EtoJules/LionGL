add_library(Core STATIC
        Renderer/Renderer.cpp Renderer/Renderer.h
        Renderer/Shader/Shader.h Renderer/Shader/Shader.cpp
        Renderer/VertexBuffer/VertexBuffer.h Renderer/VertexBuffer/VertexBuffer.cpp
        Renderer/VertexBuffer/VertexLayout.h Renderer/VertexBuffer/VertexLayout.cpp
        Renderer/VertexArray/VertexArray.h Renderer/VertexArray/VertexArray.cpp
        Renderer/IndexBuffer/IndexBuffer.h Renderer/IndexBuffer/IndexBuffer.cpp
        Renderer/Model/Model.h Renderer/Model/Model.cpp)