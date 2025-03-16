#include "LoadFileWindow.h"

LoadFileWindow::LoadFileWindow() {

}
void LoadFileWindow::load_file_window_up_dir() {
    bool move_up = ImGui::ArrowButton("Up", ImGuiDir::ImGuiDir_Up);
    if (!curr_dir.empty())
    {
        if (move_up)
        {   
            curr_dir.append("../");
            pressed_str.clear();
        }
    }
}

void LoadFileWindow::load_file_window_load_folders() {  
    my_vec = Utils::ListCurrentFilesinDirectory(curr_dir);
    my_vec_bool.clear();
    for (int i = 0; i < my_vec.size(); i++)
    {
        bool res = ImGui::Button(my_vec[i].c_str(), {150, 20});
        my_vec_bool.push_back(res);
    }
}

void LoadFileWindow::load_file_window_find_file_or_directory() {
    for (int i = 0; i < my_vec_bool.size(); i++)
    {
        if (my_vec_bool[i])
        {
            std::string temp_dir = curr_dir;
            pressed_str = my_vec[i];
            temp_dir.append(pressed_str);
            temp_dir.append("/");

            if (Utils::isDirectory(temp_dir)) {
                curr_dir = temp_dir;
                pressed_str.append(" directory");
            } else {
                pressed_str.append(" file");
            }            
        }
    }
}

void LoadFileWindow::load_file_window_get_curr_dir() {
    ImGui::Text("Select Files from the following ");
    curr_dir = Utils::getCurrentWorkingDirectory() +"/";
    curr_dir = Utils::sanitizeCurrWorkingDirectory(curr_dir);
    ImGui::Text("%s",curr_dir.c_str());  
}
void LoadFileWindow::run(int id) {
    ImGui::BeginChild(id, {720, 640});
    ImGui::SetWindowCollapsed(true);

    load_file_window_get_curr_dir();
    load_file_window_up_dir();
    load_file_window_load_folders();
    load_file_window_find_file_or_directory();

    ImGui::Text("Pressed : %s", pressed_str.c_str());
    chdir(curr_dir.c_str());
    ImGui::EndChild();
}