#include "FileDisplay.h"
#include "common_def.h"
static void glfw_error_callback(int error, const char *description);
FileDisplay::FileDisplay(FileDisplayConf myConf)
{
    m_fileDisplayConf = myConf;
    imgui_glfw_init();
    imgui_glfw_set_version();
    imgui_glfw_create_window();
    imgui_set_context();
    imgui_set_style();
}
bool FileDisplay::imgui_glfw_init()
{
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
    {
        printf("GLFW Init Failed \n");
        return RETURN_CODES::E_NOK;
    }
    return RETURN_CODES::E_OK;
}
void FileDisplay::imgui_glfw_set_version() {
    m_glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
}
bool FileDisplay::imgui_glfw_create_window() {
    // Create window with graphics context
    window = glfwCreateWindow(1280, 720, "ComparePro", nullptr, nullptr);
    if (window == nullptr)
    {
        printf("Error Creating GLFW Window \n");
        return RETURN_CODES::E_NOK;
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync
    return RETURN_CODES::E_OK;
}

void FileDisplay::imgui_set_context()
{
    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;  // Enable Gamepad Controls
    
}
void FileDisplay::imgui_set_style() {
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
        m_load_file_window.run(id);
    }
    ImGui::End();
}
void FileDisplay::start()
{
    clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
    while ((!glfwWindowShouldClose(window)))
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