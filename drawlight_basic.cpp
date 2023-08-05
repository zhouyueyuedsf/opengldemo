//#include <iostream>
//
//#define GLEW_STATIC
//
//
//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
//#include <SOIL.h>
//
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//#include "Shader.h"
//
//
//GLuint createSimpleVBO();
//
//GLuint createSimpleVertexShader(GLchar *source);
//
//GLuint createSimpleFragShader(GLchar *source);
//
//GLuint linkProgram(GLuint *shaders);
//
//namespace DRAW_LIGHT {
//    void key_callback(GLFWwindow *window, int key, int scancode, int action, int mode) {
//        // 当用户按下ESC键,我们设置window窗口的WindowShouldClose属性为true
//        // 关闭应用程序
//        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
//            glfwSetWindowShouldClose(window, GL_TRUE);
//    }
//
//    GLfloat vertices[] = {
//            -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//            0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//            0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//            0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//            -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//            -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//
//            -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//            0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//            0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//            0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//            -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//            -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//
//            -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//            -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//            -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//            -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//            -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//            -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//
//            0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//            0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//            0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//            0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//            0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//            0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//
//            -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//            0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//            0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//            0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//            -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//            -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//
//            -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
//            0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
//            0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//            0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//            -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//            -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
//    };
//}
//
//int main() {
//    std::cout << "Hello, World!" << std::endl;
//    glfwInit();
//    glfwSetTime(1681185154);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
//    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//
//    GLFWwindow *window = glfwCreateWindow(800, 600, "LearnOpenGL", nullptr, nullptr);
//    if (window == nullptr) {
//        std::cout << "Failed to create GLFW window" << std::endl;
//        glfwTerminate();
//        return -1;
//    }
//    glfwMakeContextCurrent(window);
//    glewExperimental = GL_TRUE;
//    if (glewInit() != GLEW_OK) {
//        std::cout << "Failed to initialize GLEW" << std::endl;
//        return -1;
//    }
//
//    int width, height;
//    glfwGetFramebufferSize(window, &width, &height);
//    printf("width=%i", width);
////    glViewport(0, 0, 800, 600);
//
//    // 创建VAO对象
//    GLuint cubeVAO;
//    glGenVertexArrays(1, &cubeVAO);
//    glBindVertexArray(cubeVAO);
//    // 创建vbo
//    GLuint VBO;
//    // 1. 分配起始地址
//    glGenBuffers(1, &VBO);
//    // 2. 绑定其实是指定到GPU
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    // 3. 分配内存大小
//    glBufferData(GL_ARRAY_BUFFER, sizeof(DRAW_LIGHT::vertices), DRAW_LIGHT::vertices, GL_STATIC_DRAW);
//    // 4. 配置内存定义
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)0);
//    glEnableVertexAttribArray(0);
//    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)(3 * sizeof(GLfloat)));
//    glEnableVertexAttribArray(1);
//
//    // Then, we set the light's cubeVAO (VBO stays the same. After all, the vertices are the same for the light object (also a 3D cube))
//    GLuint lampVAO;
//    glGenVertexArrays(1, &lampVAO);
//    glBindVertexArray(lampVAO);
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(DRAW_LIGHT::vertices), DRAW_LIGHT::vertices, GL_STATIC_DRAW);
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)0);
//    glEnableVertexAttribArray(0);
//    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)(3 * sizeof(GLfloat)));
//    glEnableVertexAttribArray(1);
//
//    // 创建VBO对象
//    // shaders
//    Shader cubeShader("/Users/bytedance/CLionProjects/untitled/shaders/light_diffuse_cube.vs", "/Users/bytedance/CLionProjects/untitled/shaders/light_diffuse_cube.frag");
//    Shader lampShader("/Users/bytedance/CLionProjects/untitled/shaders/light_diffuse_lamp.vs", "/Users/bytedance/CLionProjects/untitled/shaders/light_diffuse_lamp.frag");
//
//    glBindBuffer(GL_ARRAY_BUFFER, 0);
//    glBindVertexArray(0);
//
//    glm::vec3 lampPos(1.2f, 1.0f, 1.0f);
//    glm::vec3 deltaPos = lampPos - glm::vec3 (1.0f);
//    // 应用纹理
//    while (!glfwWindowShouldClose(window)) {
//        // 输入事件
//        glfwPollEvents();
//        // Render
//        // Clear the colorbuffer
//        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//        cubeShader.Use();
//        GLint objectColorLoc = glGetUniformLocation(cubeShader.Program, "objectColor");
//        GLint lampColorLoc  = glGetUniformLocation(cubeShader.Program, "lightColor");
//        GLint lampPosLoc    = glGetUniformLocation(cubeShader.Program, "lightPos");
//        glUniform3f(objectColorLoc, 1.0f, 0.5f, 0.31f);
//        glUniform3f(lampColorLoc, 1.0f, 1.0f, 1.0f);
//        glUniform3f(lampPosLoc, lampPos.x, lampPos.y, lampPos.z);
//
////        glBindVertexArray(cubeVAO);
////        glm::mat4 cubeModel(glm::mat4(1.0f));
////        cubeModel = glm::rotate(cubeModel, glm::radians(15.0f), glm::vec3(1.0f, 0.0f, 0.0f));
////        cubeModel = glm::rotate(cubeModel,  glm::radians(-15.0f), glm::vec3(0.0f, 1.0f, 0.0f));
////        glm::mat4 cubeView(glm::translate(glm::mat4(1.0f), glm::vec3(-0.5f, 0.0f, -5.0f)));
////        glm::mat4 cubeProjection(glm::perspective(glm::radians(45.0f), width * 1.0f / height, 0.1f, 100.0f));
////        // Get the uniform locations
////        GLint modelLoc = glGetUniformLocation(cubeShader.Program, "model");
////        GLint viewLoc  = glGetUniformLocation(cubeShader.Program,  "view");
////        GLint projLoc  = glGetUniformLocation(cubeShader.Program,  "projection");
////        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(cubeModel));
////        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(cubeView));
////        glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(cubeProjection));
////        glDrawArrays(GL_TRIANGLES, 0, 36);
////        glBindVertexArray(0);
////
////
////        lampShader.Use();
////        glBindVertexArray(lampVAO);
////        glm::mat4 lampModel(glm::mat4(1.0f));
////        lampModel = glm::translate(lampModel, deltaPos);
////        lampModel = glm::rotate(lampModel, glm::radians(15.0f), glm::vec3(1.0f, 0.0f, 0.0f));
////        lampModel = glm::rotate(lampModel, glm::radians(-15.0f), glm::vec3(0.0f, 1.0f, 0.0f));
////        lampModel = glm::scale(lampModel, glm::vec3(0.2f));
////        glm::mat4 lightView(glm::translate( glm::mat4(1.0f), glm::vec3(0.5f, 0.5f,-3.0f)));
////        glm::mat4 lightProjection(glm::perspective(glm::radians(45.0f), width * 1.0f / height, 0.1f, 100.0f));
////        glUniform3f(glGetUniformLocation(lampShader.Program, "lampColor"), 1.0f, 1.0f, 1.0f);
////        glUniformMatrix4fv(glGetUniformLocation(lampShader.Program, "transform"), 1, GL_FALSE,
////                           glm::value_ptr(lightProjection * lightView * lampModel));
////        glDrawArrays(GL_TRIANGLES, 0, 36);
//
//
//        glBindVertexArray(0);
//        // 交换缓冲
//        glfwSwapBuffers(window);
//    }
//    glDeleteVertexArrays(1, &cubeVAO);
//    glDeleteBuffers(1, &VBO);
//    // Terminate GLFW, clearing any resources allocated by GLFW.
//    glfwTerminate();
//    return 0;
//}
//
//GLuint linkProgram(GLuint *shaders) {
//    GLuint shaderProgram = glCreateProgram();
//    int size = sizeof(shaders) / sizeof(shaders[0]);
//    for (int i = 0; i < size; ++i) {
//        glAttachShader(shaderProgram, shaders[i]);
//    }
//    glLinkProgram(shaderProgram);
//    for (int i = 0; i < size; ++i) {
//        glDeleteShader(shaders[i]);
//    }
//    return shaderProgram;
//}
//
//GLuint createSimpleVertexShader(GLchar *source) {
//    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
//    glShaderSource(vertexShader, 1, &(source), NULL);
//    glCompileShader(vertexShader);
//    return vertexShader;
//}
//
//GLuint createSimpleFragShader(GLchar *source) {
//    GLuint fragShader = glCreateShader(GL_FRAGMENT_SHADER);
//    glShaderSource(fragShader, 1, &(source), NULL);
//    glCompileShader(fragShader);
//    return fragShader;
//}
//
//GLuint createSimpleVBO() {
//    GLuint vbo;
//    // 1. 分配起始地址
//    glGenBuffers(1, &vbo);
//    // 2. 绑定其实是指定到GPU
//    glBindBuffer(GL_ARRAY_BUFFER, vbo);
//    // 3. 分配内存大小
//    glBufferData(GL_ARRAY_BUFFER, sizeof(DRAW_LIGHT::vertices), DRAW_LIGHT::vertices, GL_STATIC_DRAW);
//    // 4. 配置内存定义，这里即一次去3个float, 从这个三个中取3个，作为postion = 0 的属性供shader使用
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid *) 0);
//    glEnableVertexAttribArray(0);
//    return vbo;
//}
//
