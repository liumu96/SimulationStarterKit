#include "visualization.h"

namespace Visualize
{
    igl::opengl::glfw::Viewer g_viewer;

    igl::opengl::glfw::imgui::ImGuiMenu menu;
    igl::opengl::glfw::imgui::ImGuiPlugin plugin;

    // meshes in the scene
    std::vector<std::pair<Eigen::MatrixXd, Eigen::MatrixXi>> g_geometry;
    std::vector<unsigned int> g_id; // id into libigl for these meshes

    // pointers to q and qdot
    Eigen::VectorXd const *g_q;
    Eigen::VectorXd const *g_qdot;
}

igl::opengl::glfw::Viewer &Visualize::viewer()
{
    return g_viewer;
}

void Visualize::setup(const Eigen::VectorXd &q,
                      const Eigen::VectorXd &qdot)
{
    g_q = &q;
    g_qdot = &qdot;

    // add new menu for phase space plotting
    Visualize::g_viewer.plugins.push_back(&plugin);
    plugin.widgets.push_back(&menu);

    menu.callback_draw_viewer_menu = [&]()
    {
        menu.draw_viewer_menu();
    };

    Visualize::g_viewer.core().background_color.setConstant(1.0);
    Visualize::g_viewer.core().is_animating = false;
}

void Visualize::add_object_to_scene(
    const Eigen::MatrixXd &V,
    const Eigen::MatrixXi &F,
    Eigen::RowVector3d color)
{
    // add mesh to libigl and store id for access later
    if (g_geometry.size() == 0)
    {
        g_id.push_back(0);
    }
    else
    {
        g_id.push_back(g_viewer.append_mesh());
    }

    g_viewer.data().set_mesh(V, F);
    g_viewer.data().set_colors(color);

    // add mesh to geometry vector
    g_geometry.push_back(std::make_pair(V, F));
}