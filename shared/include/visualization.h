#pragma once

#define IMGUI_DEFINE_MATH_OPERATORS

#include <igl/opengl/glfw/Viewer.h>
#include <igl/opengl/glfw/imgui/ImGuiPlugin.h>
#include <igl/opengl/glfw/imgui/ImGuiMenu.h>
#include <igl/opengl/glfw/imgui/ImGuiHelpers.h>

#include <imgui.h>
#include <imgui_internal.h>

// stl
#include <deque>

// Eigen
#include <Eigen/Dense>

namespace Visualize
{
    void setup(
        const Eigen::VectorXd &q,
        const Eigen::VectorXd &qdot);

    void add_object_to_scene(
        const Eigen::MatrixXd &V,
        const Eigen::MatrixXi &F,
        Eigen::RowVector3d color);

    igl::opengl::glfw::Viewer &viewer();

}