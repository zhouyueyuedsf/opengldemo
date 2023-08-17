//#include <iostream>
//
//// GLEW
//#define GLEW_STATIC
//#include <GL/glew.h>
//
//// GLFW
//#include <GLFW/glfw3.h>
//#include <glm/ext/matrix_float4x4.hpp>
//#include <glm/ext/matrix_transform.hpp>
//#include <glm/ext/matrix_clip_space.hpp>
//#include <glm/gtc/type_ptr.hpp>
//#include "Shader.h"
//
//// Function prototypes
//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
//
//// Window dimensions
//const GLuint WIDTH = 800, HEIGHT = 600;  void key_callback(GLFWwindow *window, int key, int scancode, int action, int mode) {
//        // 当用户按下ESC键,我们设置window窗口的WindowShouldClose属性为true
//        // 关闭应用程序
//        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
//            glfwSetWindowShouldClose(window, GL_TRUE);
//    }
//// The MAIN function, from here we start the application and run the game loop
//int main()
//{
//    // Init GLFW
//    glfwInit();
//    // Set all the required options for GLFW
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
//    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//
//    // Create a GLFWwindow object that we can use for GLFW's functions
//    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr);
//    if (window == nullptr)
//        {
//            std::cout << "Failed to create GLFW window" << std::endl;
//            glfwTerminate();
//            return -1;
//        }
//    glfwMakeContextCurrent(window);
//
//    // Set the required callback functions
//    glfwSetKeyCallback(window, key_callback);
//
//    // Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
//    glewExperimental = GL_TRUE;
//    // Initialize GLEW to setup the OpenGL Function pointers
//    glewInit();
//
//    // Define the viewport dimensions
//    int width, height;
//    glfwGetFramebufferSize(window, &width, &height);
//    glViewport(0, 0, width, height);
//
//
//    GLfloat vertices[] = {
//            -0.5f, -0.5f, -0.5f, // 1
//            0.5f, -0.5f, -0.5f, // 2
//            0.5f,  0.5f, -0.5f, // 3
//            0.5f,  0.5f, -0.5f, // 4
//            -0.5f,  0.5f, -0.5f, // 5
//            -0.5f, -0.5f, -0.5f, // 6
//
//    };
//
//    // 创建VAO对象
//    GLuint VAO;
//    glGenVertexArrays(1, &VAO);
//    glBindVertexArray(VAO);
//
//    GLuint VBO;
//    // 1. 分配起始地址
//    glGenBuffers(1, &VBO);
//    // 2. 绑定其实是指定到GPU
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    // 3. 分配内存大小
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//    // 4. 配置内存定义，这里即一次取3个float, 从这个三个中取3个，作为postion = 0 的属性供shader使用
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid *) 0);
//    // 5. 这一步例行公事，意思是启用顶点属性
//    glEnableVertexAttribArray(0);
//
//
//    GLuint EBO;
//    GLuint indices[] = { // 注意索引从0开始!
//            0, 1, 3, // 第一个三角形
//            1, 2, 3  // 第二个三角形
//    };
//
//    glGenBuffers(1, &EBO);
//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//    // Uncommenting this call will result in wireframe polygons.
//    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//
//
//    Shader shader("/Users/bytedance/CLionProjects/untitled/shaders/draw_tri.vs", "/Users/bytedance/CLionProjects/untitled/shaders/draw_tri.frag");
//    // Game loop
//    while (!glfwWindowShouldClose(window))
//    {
//        // Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
//        glfwPollEvents();
//        // Render
//        // Clear the colorbuffer
//        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT);
//
//        shader.Use();
//        glBindVertexArray(VAO);
//        glDrawArrays(GL_TRIANGLES, 0, 6);
//
//
//        // Swap the screen buffers
//        glfwSwapBuffers(window);
//    }
//    // Properly de-allocate all resources once they've outlived their purpose
//    glDeleteVertexArrays(1, &VAO);
//    glDeleteBuffers(1, &VBO);
////    glDeleteBuffers(1, &EBO);
//    // Terminate GLFW, clearing any resources allocated by GLFW.
//    glfwTerminate();
//    return 0;
//}