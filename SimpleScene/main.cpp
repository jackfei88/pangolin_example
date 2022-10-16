#include <pangolin/display/display.h>
#include <pangolin/display/view.h>
#include <pangolin/scene/axis.h>
#include <pangolin/scene/scenehandler.h>

int main(int /*argc*/, char ** /*argv*/)
{
    pangolin::CreateWindowAndBind("Main", 640, 480);
    glEnable(GL_DEPTH_TEST);

    // Define Projection and initial ModelView matrix
    pangolin::OpenGlRenderState s_cam(
        pangolin::ProjectionMatrix(640, 480, 420, 420, 320, 240, 0.2, 100),
        pangolin::ModelViewLookAt(-2, 2, -2, 0, 0, 0, pangolin::AxisY));

    // Renderable 是一个容器，用来存储绘制的对象
    // 内部用的map容器，每个对象有一个id
    pangolin::Renderable tree;
    for (size_t i = 0; i < 10; ++i)
    {
        auto axis_i = std::make_shared<pangolin::Axis>();
        axis_i->T_pc = pangolin::OpenGlMatrix::Translate(i * 2.0, i * 0.5 /*0.1*/, 0.0); // 改成0.5，为了让y轴的移动更明显
        tree.Add(axis_i);
    }

    // Create Interactive View in window
    pangolin::SceneHandler handler(tree, s_cam);
    pangolin::View &d_cam = pangolin::CreateDisplay()
                                .SetBounds(0.0, 1.0, 0.0, 1.0, -640.0f / 480.0f)
                                .SetHandler(&handler);

    // 激活相机，同时绘制tree容器中绘图对象
    d_cam.SetDrawFunction([&](pangolin::View &view)
                          {
        view.Activate(s_cam);       // 激活相机
        tree.Render(); });

    while (!pangolin::ShouldQuit())
    {
        // Clear screen and activate view to render into
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Swap frames and Process Events
        pangolin::FinishFrame();
    }

    return 0;
}
