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
class LoadFileWindow {
    public:
        LoadFileWindow();
        void run(int id);
};