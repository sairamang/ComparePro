#include "LoadFileWindow.h"

LoadFileWindow::LoadFileWindow() {

}
void LoadFileWindow::run(int id) {
    ImGui::BeginChild(id, {720, 640});
    ImGui::Text("Select Files from the following ");

    static std::string pressed_str;
    static std::string curr_dir = Utils::getCurrentWorkingDirectory() +"/";
    ImGui::Text("%s",curr_dir.c_str());    

    bool move_up = ImGui::ArrowButton("Up", ImGuiDir::ImGuiDir_Up);
    bool move_down = ImGui::ArrowButton("Down", ImGuiDir::ImGuiDir_Down);
    if (!curr_dir.empty())
    {
        if (move_up)
        {   
            curr_dir.append("../");
            pressed_str.clear();
        }
            
        if (move_down)
        {
            std::size_t pos1 = curr_dir.find_last_of("/");
            curr_dir.erase(curr_dir.begin() + pos1);
            std::size_t pos = curr_dir.find_last_of("/");
            if (pos != 18446744073709551615UL)
            {
                curr_dir.erase(pos + curr_dir.begin() + 1, curr_dir.end());
            }
            else
            {
                curr_dir.append("/");
            }
            pressed_str.clear();
        }
    }
    chdir(curr_dir.c_str());
    std::vector<std::string> myvec = Utils::ListCurrentFilesinDirectory(curr_dir);
    std::vector<bool> myvecbool;

    for (int i = 0; i < myvec.size(); i++)
    {
        bool res = ImGui::Button(myvec[i].c_str(), {150, 20});
        myvecbool.push_back(res);
    }

    for (int i = 0; i < myvecbool.size(); i++)
    {
        if (myvecbool[i])
        {
            std::string temp_dir = curr_dir;
            pressed_str = myvec[i];
            temp_dir.append(pressed_str);
            temp_dir.append("/");

            if (Utils::isDirectory(temp_dir)) {
                curr_dir= temp_dir;
                pressed_str.append(" directory");
            } else {
                pressed_str.append(" file");
            }            
        }
    }
    ImGui::Text("Pressed : %s", pressed_str.c_str());
    ImGui::EndChild();
}