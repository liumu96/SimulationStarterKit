#include <iostream>

#include "scene_setup.h"
#include "visualization.h"

// Simulate State
Eigen::VectorXd q;
Eigen::VectorXd qdot;

bool key_down(igl::opengl::glfw::Viewer &viewer, unsigned char key, int mods);
bool simulate(igl::opengl::glfw::Viewer &viewer);

int main(int argc, char **argv)
{
    scene_setup(argc, argv, q, qdot);

    Visualize::setup(q, qdot);

    Visualize::viewer().callback_post_draw = &simulate;
    Visualize::viewer().callback_key_down = &key_down;

    Visualize::viewer().launch();

    std::cout << "Simulation Starter Kit" << std::endl;
    return 0;
}

bool key_down(igl::opengl::glfw::Viewer &viewer, unsigned char key, int mods)
{
    switch (key)
    {
    case ' ':
        // Add your custom key down event here
        return true;
    }
    return false;
}

bool simulate(igl::opengl::glfw::Viewer &viewer)
{
    // Add you simulate algorithm here
    return false;
}
