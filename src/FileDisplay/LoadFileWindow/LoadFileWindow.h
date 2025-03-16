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
    private:
        std::string curr_dir;
        std::string pressed_str;
        std::vector<std::string> my_vec;
        std::vector<bool> my_vec_bool;
        void load_file_window_get_curr_dir();
        void load_file_window_up_dir();
        void load_file_window_load_folders();
        void load_file_window_find_file_or_directory();
};