//#include <iostream>
//#define GLEW_STATIC
//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
//#include <SOIL.h>
//
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
//{
//    // 当用户按下ESC键,我们设置window窗口的WindowShouldClose属性为true
//    // 关闭应用程序
//    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
//        glfwSetWindowShouldClose(window, GL_TRUE);
//}
//glm::vec3 cubePositions[] = {
//        glm::vec3( 0.0f,  0.0f,  0.0f),
//        glm::vec3( 2.0f,  5.0f, -15.0f),
//        glm::vec3(-1.5f, -2.2f, -2.5f),
//        glm::vec3(-3.8f, -2.0f, -12.3f),
//        glm::vec3( 2.4f, -0.4f, -3.5f),
//        glm::vec3(-1.7f,  3.0f, -7.5f),
//        glm::vec3( 1.3f, -2.0f, -2.5f),
//        glm::vec3( 1.5f,  2.0f, -2.5f),
//        glm::vec3( 1.5f,  0.2f, -1.5f),
//        glm::vec3(-1.3f,  1.0f, -1.5f)
//};
//// 顶点着色
//const GLchar* vertexShaderSource = "#version 330 core\n"
//                                   "layout (location = 0) in vec3 position;\n"
//                                   "layout (location = 1) in vec3 color;\n"
//                                   "layout (location = 2) in vec2 texCoord;\n"
//                                   "uniform mat4 transform;"
//                                   "\n"
//                                   "out vec3 ourColor;\n"
//                                   "out vec2 TexCoord;\n"
//                                   "\n"
//                                   "void main()\n"
//                                   "{\n"
//                                   "    gl_Position = transform * vec4(position, 1.0f);\n"
//                                   "    ourColor = color;\n"
//                                   "    TexCoord = texCoord;\n"
//                                   "}";
//// 片元着色
//const GLchar* fragmentShaderSource = "#version 330 core\n"
//                                     "in vec3 ourColor;\n"
//                                     "in vec2 TexCoord;\n"
//                                     "\n"
//                                     "out vec4 color;\n"
//                                     "\n"
//                                     "uniform sampler2D ourTexture;\n"
//                                     "\n"
//                                     "void main()\n"
//                                     "{\n"
//                                     "    color = texture(ourTexture, TexCoord);\n"
//                                     "}";
//
//GLuint bindTexture();
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
//    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", nullptr, nullptr);
//    if (window == nullptr)
//    {
//        std::cout << "Failed to create GLFW window" << std::endl;
//        glfwTerminate();
//        return -1;
//    }
//    glfwMakeContextCurrent(window);
//    glewExperimental = GL_TRUE;
//    if (glewInit() != GLEW_OK)
//    {
//        std::cout << "Failed to initialize GLEW" << std::endl;
//        return -1;
//    }
//
//    int width, height;
//    glfwGetFramebufferSize(window, &width, &height);
//
//    // Set up vertex data (and buffer(s)) and attribute pointers
//    // 这个是压缩后的矩阵
//    GLfloat vertices[] = {
//            -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//            0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
//            0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//            0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//            -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//            -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//
//            -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//            0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//            0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//            0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//            -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
//            -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//
//            -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//            -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//            -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//            -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//            -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//            -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//
//            0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//            0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//            0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//            0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//            0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//            0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//
//            -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//            0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
//            0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//            0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//            -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//            -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//
//            -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//            0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//            0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//            0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//            -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
//            -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
//    };
//    GLuint indices[] = { // 注意索引从0开始!
//            0, 1, 3, // 第一个三角形
//            1, 2, 3  // 第二个三角形
//    };
//
//    glViewport(0, 0, width, height);
//    glfwSetKeyCallback(window, key_callback);
//
//    // Setup OpenGL options
//    glEnable(GL_DEPTH_TEST);
//
//    // 顶点着色器
//    GLuint vertexShader;
//    vertexShader = glCreateShader(GL_VERTEX_SHADER);
//    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//    glCompileShader(vertexShader);
//    // 片元着色器
//    GLuint fragmentShader;
//    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
//    glCompileShader(fragmentShader);
//
//    // link shaders
//    GLuint shaderProgram;
//
//    shaderProgram = glCreateProgram();
//    glAttachShader(shaderProgram, vertexShader);
//    glAttachShader(shaderProgram, fragmentShader);
//    glLinkProgram(shaderProgram);
//    glDeleteShader(vertexShader);
//    glDeleteShader(fragmentShader);
//
//    // VAO: 顶点数组对象
//    GLuint VBO, VAO, EBO;
//    glGenVertexArrays(1, &VAO);
//    glGenBuffers(1, &VBO);
//    glGenBuffers(1, &EBO);
//
//    glBindVertexArray(VAO);
//
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//    // Position attribute
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
//    glEnableVertexAttribArray(0);
//    // Color attribute
//    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
//    glEnableVertexAttribArray(1);
//    // TexCoord attribute
//    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
//    glEnableVertexAttribArray(2);
//
//    glBindVertexArray(0); // Unbind VAO// Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs), remember: do NOT unbind the EBO, keep it bound to this VAO
//
//
//    int iw, ih;
//    unsigned char* image = SOIL_load_image("/Users/bytedance/CLionProjects/untitled/container.jpeg", &iw, &ih, 0, SOIL_LOAD_RGB);
//
//    // 生成纹理
//    GLuint texture = bindTexture();
//    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, iw, ih, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
//    glGenerateMipmap(GL_TEXTURE_2D);
//
//
//
//    // 应用纹理
//
//    while(!glfwWindowShouldClose(window))
//    {
//        // 输入事件
//        glfwPollEvents();
//        // 渲染指令
//        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
////        glBindTexture(GL_TEXTURE_2D, texture);
//        glUseProgram(shaderProgram);
//
//        glUniform1i(glGetUniformLocation(shaderProgram, "transform"), 0);
//        glActiveTexture(GL_TEXTURE1);
//        double timeSecond = glfwGetTime();
//        glm::mat4 projection(glm::mat4(1.0f));
//        projection = glm::perspective(glm::radians(45.0f), width * 1.0f / height, 0.1f, 100.0f);
//
//        GLfloat radius = 10.0f;
//        GLfloat camX = sin(timeSecond) * radius;
//        GLfloat camZ = cos(timeSecond) * radius;
//        glm::mat4 view(glm::mat4(1.0f));
//        // 注意，我们将矩阵向我们要进行移动场景的反向移动。
//        view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
//        view = glm::rotate(view,  50.0f, glm::vec3(0.0f, 0.0f, -3.0f));
//        view = glm::lookAt(glm::vec3(camX, 0.0, camZ), glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0));
//        glBindVertexArray(VAO);
//
//        for(GLuint i = 0; i < 10; i++)
//        {
//            // Create transformations
//            printf("glfwGetTime() = %d \n", int(timeSecond) % 360);
//            glm::mat4 model = glm::mat4(1.0f);
//            model = glm::translate(model, cubePositions[i]);
//            GLfloat angle = 20.0f * i;
//            model = glm::rotate(model, angle, glm::vec3(1.0f, 0.3f, 0.5f));
//            GLint modelLoc = glGetUniformLocation(shaderProgram, "modelLoc");
//
//            glm::mat4 transform = projection * view * model;
//            // Get matrix's uniform location and set matrix
//            GLint transformLoc = glGetUniformLocation(shaderProgram, "transform");
//            glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
//
//            glDrawArrays(GL_TRIANGLES, 0, 36);
//        }
//        glBindVertexArray(0);
//
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
//GLuint bindTexture() {
//    GLuint texture;
//    glGenTextures(1, &texture);
//    // 纹理根据id绑定
//    glBindTexture(GL_TEXTURE_2D, texture);
//
//    return texture;
//}
//
