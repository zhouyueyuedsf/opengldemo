//#include <iostream>
//
//#define GLEW_STATIC
//
//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
//#include <SOIL.h>
//
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
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
//            -0.5f, -0.5f, -0.5f,
//            0.5f, -0.5f, -0.5f,
//            0.5f, 0.5f, -0.5f,
//            0.5f, 0.5f, -0.5f,
//            -0.5f, 0.5f, -0.5f,
//            -0.5f, -0.5f, -0.5f,
//
//            -0.5f, -0.5f, 0.5f,
//            0.5f, -0.5f, 0.5f,
//            0.5f, 0.5f, 0.5f,
//            0.5f, 0.5f, 0.5f,
//            -0.5f, 0.5f, 0.5f,
//            -0.5f, -0.5f, 0.5f,
//
//            -0.5f, 0.5f, 0.5f,
//            -0.5f, 0.5f, -0.5f,
//            -0.5f, -0.5f, -0.5f,
//            -0.5f, -0.5f, -0.5f,
//            -0.5f, -0.5f, 0.5f,
//            -0.5f, 0.5f, 0.5f,
//
//            0.5f, 0.5f, 0.5f,
//            0.5f, 0.5f, -0.5f,
//            0.5f, -0.5f, -0.5f,
//            0.5f, -0.5f, -0.5f,
//            0.5f, -0.5f, 0.5f,
//            0.5f, 0.5f, 0.5f,
//
//            -0.5f, -0.5f, -0.5f,
//            0.5f, -0.5f, -0.5f,
//            0.5f, -0.5f, 0.5f,
//            0.5f, -0.5f, 0.5f,
//            -0.5f, -0.5f, 0.5f,
//            -0.5f, -0.5f, -0.5f,
//
//            -0.5f, 0.5f, -0.5f,
//            0.5f, 0.5f, -0.5f,
//            0.5f, 0.5f, 0.5f,
//            0.5f, 0.5f, 0.5f,
//            -0.5f, 0.5f, 0.5f,
//            -0.5f, 0.5f, -0.5f,
//    };
//// 顶点着色
//    const GLchar *vertexShaderSource = "#version 330 core \n"
//                                       "layout (location = 0) in vec3 position;\n"
//                                       "uniform mat4 transform;\n"
//                                       "void main()\n"
//                                       "{\n"
//                                       "    // 注意从右向左读\n"
//                                       "    gl_Position = transform * vec4(position, 1.0f);\n"
//                                       "}";
//    // 片元着色
//    const GLchar *fragmentShaderSource = "#version 330 core\n"
//                                         "out vec4 color;\n"
//                                         "void main()\n"
//                                         "{\n"
//                                         "color = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
//                                         "}\n\0";
//
//    GLuint bindTexture();
//
//    GLuint bindTexture() {
//        GLuint texture;
//        glGenTextures(1, &texture);
//        // 纹理根据id绑定
//        glBindTexture(GL_TEXTURE_2D, texture);
//
//        return texture;
//    }
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
//
//    // 创建VAO对象
//    GLuint VAO;
//    glGenVertexArrays(1, &VAO);
//    glBindVertexArray(VAO);
//
//    // 创建VBO对象
//    GLuint VBO;
//    // 1. 分配起始地址
//    glGenBuffers(1, &VBO);
//    // 2. 绑定其实定制到GPU
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    // 3. 分配内存大小
//    glBufferData(GL_ARRAY_BUFFER, sizeof(DRAW_LIGHT::vertices), DRAW_LIGHT::vertices, GL_STATIC_DRAW);
//    // 4. 配置内存定义，这里即一次去3个float, 从这个三个中取3个，作为postion = 0 的属性供shader使用
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid *) 0);
//    glEnableVertexAttribArray(0);
//
//    // 顶点等着色器的链接
//    // 1. 创建Shader, 由于是用字符串表示的，c++编译器肯定涉及不到该dsl的编译、需要主动触发shader编译
//    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
//    glShaderSource(vertexShader, 1, &(DRAW_LIGHT::vertexShaderSource), NULL);
//    glCompileShader(vertexShader);
//
//    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//    glShaderSource(fragmentShader, 1, &(DRAW_LIGHT::fragmentShaderSource), NULL);
//    glCompileShader(fragmentShader);
//
//    // 2. 链接shader
//    GLuint shaderProgram = glCreateProgram();
//    glAttachShader(shaderProgram, vertexShader);
//    glAttachShader(shaderProgram, fragmentShader);
//    glLinkProgram(shaderProgram);
//    glDeleteShader(vertexShader);
//    glDeleteShader(fragmentShader);
//
//    glBindBuffer(GL_ARRAY_BUFFER, 0);
//    glBindVertexArray(0);
//    // 应用纹理
//    while (!glfwWindowShouldClose(window)) {
//        // 输入事件
//        glfwPollEvents();
//        // Render
//        // Clear the colorbuffer
//        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//        //  Draw the triangle
//        glUseProgram(shaderProgram);
//        glBindVertexArray(VAO);
//
//        glm::mat4 model(glm::mat4(1.0f));
//        model = glm::rotate(model, -90.0f, glm::vec3(1.0f, 0.0f, 0.0f));
//        glm::mat4 view(glm::mat4(1.0f));
//        // 注意，我们将矩阵向我们要进行移动场景的反向移动。
//        view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
//        glm::mat4 projection(glm::mat4(1.0f));
//        projection = glm::perspective(45.0f, width * 1.0f / height, 0.1f, 100.0f);
//        glm::mat4 transform = projection * view * model;
//
//        GLint transformLoc = glGetUniformLocation(shaderProgram, "transform");
//        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
//
//        glDrawArrays(GL_TRIANGLES, 0, 36);
//
//        glBindVertexArray(0);
//        // 交换缓冲
//        glfwSwapBuffers(window);
//    }
//    glDeleteVertexArrays(1, &VAO);
//    glDeleteBuffers(1, &VBO);
//    // Terminate GLFW, clearing any resources allocated by GLFW.
//    glfwTerminate();
//    return 0;
//}
//
