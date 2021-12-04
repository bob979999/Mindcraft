
#include <iostream>
#include <glfw3.h>

int main()
{
    if (!glfwInit())
    {
        printf("Failed to initialize GLFW.");
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    const int width = 1920;
    const int height = 1080;

    const char* title = "Mindcraft";

    GLFWwindow* window = glfwCreateWindow(width, height, title, nullptr, nullptr);

    if (window == nullptr){
        printf("Failed to create window.");
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    return 0;
}