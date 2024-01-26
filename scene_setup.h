#pragma once

#include <igl/readMESH.h>
#include <igl/readOBJ.h>
#include <igl/writeOBJ.h>
#include <igl/readOFF.h>
#include <igl/boundary_facets.h>

#include "visualization.h"

// variables for skinning
Eigen::MatrixXd V_bunny;
Eigen::MatrixXi F_bunny;

inline void scene_setup(int argc, char **argv, Eigen::VectorXd &q, Eigen::VectorXd &qdot)
{
    igl::readOBJ("../data/coarse_bunny.obj", V_bunny, F_bunny);
    // igl::readOBJ("../data/stanford-bunny.obj", V_bunny, F_bunny);

    q.resize(1);
    qdot.resize(1);

    q(0) = 1;
    qdot(0) = 0;

    Visualize::add_object_to_scene(V_bunny, F_bunny, Eigen::RowVector3d(30, 60, 224) / 255.);
}