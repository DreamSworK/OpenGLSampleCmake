#pragma once

#include <GLFW/glfw3.h>

void centerWindow(GLFWwindow *window)
{
    int monitorCount;
    GLFWmonitor **monitors = glfwGetMonitors(&monitorCount);

    if (monitorCount)
    {
        GLFWmonitor *monitor = monitors[0];
        if (!monitor)
            return;

        const GLFWvidmode *mode = glfwGetVideoMode(monitor);
        if (!mode)
            return;

        int monitorX, monitorY;
        glfwGetMonitorPos(monitor, &monitorX, &monitorY);

        int windowWidth, windowHeight;
        glfwGetWindowSize(window, &windowWidth, &windowHeight);

        glfwSetWindowPos(window, monitorX + (mode->width - windowWidth) / 2, monitorY + (mode->height - windowHeight) / 2);
    }
}