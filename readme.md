
# Pangolin例子

Pangolin 0.8版本的例子

- HelloCameraView：测试观察相机与世界坐标系的关系
- SharedMemoryCamera和SimpleVideo没有测试通过，SimpleVideo找不到共享存，不知道是不是SharedMemoryCamera给的uri不对
  - TODO
- VBODisplay：用到GPU，但报“Segmentation fault”错误，GlBufferCudaPtr没过，大概是分配GPU显存时出错
  - TODO
- BasicOpenGL 包含OpenGL实现和pangolin实现的对比例子
  - 5_gl_intro_view_transforms 立方体旋转，转动的是相机

基础教程可参考：https://github.com/yuntianli91/pangolin_tutorial



