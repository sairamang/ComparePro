#include "FileDisplay.h"
static void glfw_error_callback(int error, const char *description);
FileDisplay::FileDisplay(FileDisplayConf myConf)
{
    m_fileDisplayConf = myConf;
    imgui_glfw_init();
    imgui_opengl_init();
}
void FileDisplay::imgui_glfw_init()
{
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
    {
        printf("GLFW Init Failed \n");
        return;
    }
    m_glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    // Create window with graphics context
    window = glfwCreateWindow(1280, 720, "ComparePro", nullptr, nullptr);
    if (window == nullptr)
    {
        printf("Error Creating GLFW Window \n");
        return;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync
}

void FileDisplay::imgui_opengl_init()
{
    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;  // Enable Gamepad Controls

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(m_glsl_version);
}

static void glfw_error_callback(int error, const char *description)
{
    fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}
void FileDisplay::imgui_frame_init()
{
    // Start the Dear ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}
void FileDisplay::imgui_render()
{
    // Rendering
    ImGui::Render();
    int display_w, display_h;
    glfwGetFramebufferSize(window, &display_w, &display_h);
    glViewport(0, 0, display_w, display_h);
    glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    glfwSwapBuffers(window);
}
void FileDisplay::loadfilewindow(bool &loadfilebutton, int id)
{
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
                ImGui::Text("Opening Directory");
            } else {
                pressed_str.append(" file");
                ImGui::Text("Opening File");
            }            
        }
    }
    ImGui::Text("Pressed : %s", pressed_str.c_str());
    ImGui::EndChild();
}
void FileDisplay::filedisplaywindow()
{
    static bool load_file_button = false;
    ImGui::Begin("ComparePro");
    ImGui::SetWindowPos({0, 0});
    int id;

    ImGui::Text("Select a File");
    if (false == load_file_button)
    {
        load_file_button = ImGui::Button("Load File", ImVec2(120, 20));
    }
    if (load_file_button)
    {
        std::cout << "Load File Button pressed" << std::endl;
        loadfilewindow(load_file_button, id);
    }
    ImGui::End();
}
void FileDisplay::start()
{
    clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        if (glfwGetWindowAttrib(window, GLFW_ICONIFIED) != 0)
        {
            ImGui_ImplGlfw_Sleep(10);
            continue;
        }
        imgui_frame_init();
        filedisplaywindow();
        imgui_render();
    }
}

void FileDisplay::stop()
{
    imgui_opengl_destroy();
    imgui_glfw_destroy();
}

void FileDisplay::imgui_opengl_destroy()
{
    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void FileDisplay::imgui_glfw_destroy()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}