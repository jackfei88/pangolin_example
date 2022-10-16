// 视图相机与世界坐标系的关系

#include <pangolin/pangolin.h>

int main()
{
    // 创建窗口
    pangolin::CreateWindowAndBind("Main", 640, 480);

    // 启动深度测试，只绘制相机观察到的一侧
    glEnable(GL_DEPTH_TEST);

    // 创建观察相机，需要设置两方面参数
    // 1. 相机参数
    //  1.1 图像尺寸
    //  1.2 相机内参
    //  1.3 近点/远点距离
    // 2. 在世界坐标系中位置与姿态
    //  2.1 位置
    //  2.2 相机z轴的指向，一般指向世界坐标系原点
    //  2.3 世界坐标系的哪个轴朝上
    pangolin::OpenGlRenderState s_cam(
        pangolin::ProjectionMatrix(640, 480, 420, 420, 320, 320, 0.2, 100),
        pangolin::ModelViewLookAt(2, 0, 2, 0, 0, 0, pangolin::AxisY)); // 改一下试试 AxisX AxisY AxisZ

    // 如果不设置交互视窗，就无法交互
    pangolin::Handler3D handler(s_cam);
    pangolin::View &d_cam = pangolin::CreateDisplay()
                                .SetBounds(0.0, 1.0, 0.0, 1.0, -640.f / 480.f)
                                .SetHandler(&handler);

    while (!pangolin::ShouldQuit())
    {
        // 清空颜色和深度缓存
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // 激活相机
        // 注释掉看看会发生什么
        d_cam.Activate(s_cam);

        // 绘制坐标系
        glLineWidth(3); // 线宽，量纲是什么？
        glBegin(GL_LINES);

        // x轴，AxisX设置时，显示是向上的
        glColor3f(0.8f, 0.f, 0.f);
        glVertex3f(0, 0, 0); // 坐标原点
        glVertex3f(1, 0, 0); // 轴的长度

        // y轴，AxisY设置时，显示是向上的
        glColor3f(0.f, 0.8f, 0.f);
        glVertex3f(0, 0, 0); // 坐标原点
        glVertex3f(0, 1, 0); // 轴的长度

        // z轴，AxisZ设置时，显示是向上的
        glColor3f(0.2f, 0.2f, 1.f);
        glVertex3f(0, 0, 0); // 坐标原点
        glVertex3f(0, 0, 1); // 轴的长度

        glEnd();

        // 刷新视窗
        pangolin::FinishFrame();
    }

    return 0;
}