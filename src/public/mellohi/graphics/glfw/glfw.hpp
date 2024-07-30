#pragma once

namespace mellohi::glfw
{
    class Glfw
    {
    public:
        ~Glfw();
        Glfw(const Glfw &other) = delete;
        Glfw(Glfw &&other) = delete;
        auto operator=(const Glfw &other) -> Glfw & = delete;
        auto operator=(Glfw &&other) -> Glfw & = delete;

        static auto get_instance() -> Glfw &;

        auto poll_events() const -> void;

    private:
        Glfw();
    };
}
