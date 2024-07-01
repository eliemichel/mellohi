#include <mellohi.h>

#include "imgui.h"
#include "learn_mesh.h"

using namespace mellohi;

int main()
{
    const Game game("sandbox");

    auto &world = game.get_world();

    learn_mesh::init_systems(world);

    world.system()
        .iter([](const flecs::iter &it)
        {
            ImGui::ShowMetricsWindow();
        });

    learn_mesh::create(world, 0.0, 1.0, 0.0, 0.0, 0.75);
    learn_mesh::create(world, 2.0, 0.0, 1.0, 0.0, 0.75);
    learn_mesh::create(world, 4.0, 0.0, 0.0, 1.0, 0.75);

    game.run();
}
