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
//    GLchar *vertexShaderSource = "#version 330 core \n"
//                                 "layout (location = 0) in vec3 position;\n"
//                                 "uniform mat4 transform;\n"
//                                 "void main()\n"
//                                 "{\n"
//                                 "    // 注意从右向左读\n"
//                                 "    gl_Position = transform * vec4(position, 1.0f);\n"
//                                 "}";
//    // 片元着色
//    GLchar *fragmentShaderSource = "#version 330 core\n"
//                                   "out vec4 color;\n"
//                                   "\n"
//                                   "uniform vec3 objectColor;\n"
//                                   "uniform vec3 lightColor;\n"
//                                   "\n"
//                                   "void main()\n"
//                                   "{\n"
//                                   "    color = vec4(lightColor * objectColor, 1.0f);\n"
//                                   "}";
//
//    GLchar *lightFragmentShaderSource = "#version 330 core\n"
//                                        "out vec4 color;\n"
//                                        "\n"
//                                        "void main()\n"
//                                        "{\n"
//                                        "    color = vec4(1.0f); //设置四维向量的所有元素为 1.0f\n"
//                                        "}";
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
//
//
//
//    // 创建VAO对象
//    GLuint VAO;
//    glGenVertexArrays(1, &VAO);
//    glBindVertexArray(VAO);
//    // 创建vbo
//    GLuint VBO;
//    // 1. 分配起始地址
//    glGenBuffers(1, &VBO);
//    // 2. 绑定其实是指定到GPU
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    // 3. 分配内存大小
//    glBufferData(GL_ARRAY_BUFFER, sizeof(DRAW_LIGHT::vertices), DRAW_LIGHT::vertices, GL_STATIC_DRAW);
//    // 4. 配置内存定义，这里即一次去3个float, 从这个三个中取3个，作为postion = 0 的属性供shader使用
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid *) 0);
//    glEnableVertexAttribArray(0);
//
//
//    // Then, we set the light's VAO (VBO stays the same. After all, the vertices are the same for the light object (also a 3D cube))
//    GLuint lightVAO;
//    glGenVertexArrays(1, &lightVAO);
//    glBindVertexArray(lightVAO);
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(DRAW_LIGHT::vertices), DRAW_LIGHT::vertices, GL_STATIC_DRAW);
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid *) 0);
//    glEnableVertexAttribArray(0);
//
//    // 创建VBO对象
//
//    // 顶点等着色器的链接
//    // 1. 创建Shader, 由于是用字符串表示的，c++编译器肯定涉及不到该dsl的编译、需要主动触发shader编译
//    GLuint vertexShader = createSimpleVertexShader(DRAW_LIGHT::vertexShaderSource);
//    GLuint fragmentShader = createSimpleFragShader(DRAW_LIGHT::fragmentShaderSource);
//    // 2. 链接shader
//    GLuint shaderProgram = linkProgram(reinterpret_cast<GLuint *>(new GLint[2]{static_cast<GLint>(vertexShader),
//                                                                               static_cast<GLint>(fragmentShader)}));
//
//
//    GLuint lightFragmentShader = createSimpleFragShader(DRAW_LIGHT::lightFragmentShaderSource);
//    GLuint lightProgram = linkProgram(reinterpret_cast<GLuint *>(new GLint[2]{static_cast<GLint>(vertexShader),
//                                                                              static_cast<GLint>(lightFragmentShader)}));
//
//    glBindBuffer(GL_ARRAY_BUFFER, 0);
//    glBindVertexArray(0);
//
//    glm::vec3 lightPos(0.2f, 0.5f, 0.4f);
//
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
//        glUseProgram(lightProgram);
//        glBindVertexArray(lightVAO);
//
//        int timeSecond = (int)glfwGetTime();
//        float angle = glm::radians((timeSecond % 360) * 1.0f);
//        printf("%f \n", angle);
//        glm::mat4 lightModel(glm::mat4(1.0f));
//        lightModel = glm::rotate(lightModel,  glm::radians(15.0f), glm::vec3(1.0f, 0.0f, 0.0f));
//        lightModel = glm::rotate(lightModel,  glm::radians(-15.0f), glm::vec3(0.0f, 1.0f, 0.0f));
//        lightModel = glm::scale(lightModel, glm::vec3(0.2f));
//        glm::mat4 lightView(glm::translate( glm::mat4(1.0f), glm::vec3(0.5f, 0.5f,-3.0f)));
//        glm::mat4 lightProjection(glm::perspective(glm::radians(45.0f), width * 1.0f / height, 0.1f, 100.0f));
//        glUniformMatrix4fv(glGetUniformLocation(lightProgram, "transform"), 1, GL_FALSE,
//                           glm::value_ptr( lightProjection * lightView * lightModel));
//        glDrawArrays(GL_TRIANGLES, 0, 36);
//
//        glUseProgram(shaderProgram);
//        glBindVertexArray(VAO);
//        glm::mat4 model(glm::mat4(1.0f));
//        model = glm::rotate(model, glm::radians(15.0f), glm::vec3(1.0f, 0.0f, 0.0f));
//        model = glm::rotate(model,  glm::radians(-15.0f), glm::vec3(0.0f, 1.0f, 0.0f));
//        glm::mat4 view(glm::mat4(1.0f));
//        // 注意，我们将矩阵向我们要进行移动场景的反向移动。
//        view = glm::translate(view, glm::vec3(-0.5f, 0.0f, -5.0f));
//        glm::mat4 projection(glm::mat4(1.0f));
//        projection = glm::perspective(glm::radians(45.0f), width * 1.0f / height, 0.1f, 100.0f);
//        glm::mat4 transform = projection * view * model;
//
//        GLint transformLoc = glGetUniformLocation(shaderProgram, "transform");
//        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
//        // 在此之前不要忘记首先'使用'对应的着色器程序(来设定uniform)
//        GLint objectColorLoc = glGetUniformLocation(shaderProgram, "objectColor");
//        GLint lightColorLoc  = glGetUniformLocation(shaderProgram, "lightColor");
//        glUniform3f(objectColorLoc, 1.0f, 0.5f, 0.31f);// 我们所熟悉的珊瑚红
//        glUniform3f(lightColorLoc,  1.0f, 1.0f, 1.0f); // 依旧把光源设置为白色
//
//        glDrawArrays(GL_TRIANGLES, 0, 36);
//
//        glBindVertexArray(lightVAO);
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
