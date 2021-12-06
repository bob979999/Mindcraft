#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
    std::cout << "x: " << xpos << "y: " << ypos << std::endl;
}

int main()
{

    if (!glfwInit())
    {
        printf("Failed to initialize GLFW.\n");
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    const int width = 1920;
    const int height = 1080;

    const char *title = "Mindcraft";

    GLFWwindow *window = glfwCreateWindow(width, height, title, nullptr, nullptr);

    if (window == nullptr)
    {
        printf("Failed to create window.\n");
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        printf("Failed to initialize Glad.\n");
        return -1;
    }

    glViewport(0, 0, width, height);

    glfwSetCursorPosCallback(window, cursor_position_callback);

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(250.0f / 255.0f, 119.0f / 255.0f, 110.0f / 255.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}