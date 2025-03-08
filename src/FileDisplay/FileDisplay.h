#pragma once
#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <dirent.h>
//glfw headers
#include <GLFW/glfw3.h>
#include <GL/gl.h>

//imgui headers
#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

//ComparePro
#include "Utils/Utils.h"


struct FileDisplayConf {
    int width;
    int breadth;
};

class FileDisplay {
    public:
        FileDisplay(FileDisplayConf myConf);
        void start();
        void stop();
    private:
        void imgui_render();
        void imgui_frame_init();
        void imgui_opengl_init();
        void imgui_glfw_init();
        void imgui_opengl_destroy();
        void imgui_glfw_destroy();
        void filedisplaywindow();
        void loadfilewindow(bool& loadfilebutton, int id);
        FileDisplayConf m_fileDisplayConf;
        GLFWwindow* window;
        ImVec4 clear_color;
        const char *m_glsl_version;
};