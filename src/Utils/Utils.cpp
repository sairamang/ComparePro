#include "Utils.h"
#include <filesystem>
#include <stack>
Utils Utils::myinstance;

void Utils::printUsage()
{
    std::cout << "Usage : ./comparepro [Options] file1 file2" << std::endl;
}

bool Utils::isFileExists(std::string mFilePath)
{
    return std::filesystem::is_regular_file(mFilePath);
}
std::string Utils::getCurrentWorkingDirectory()
{
    char buffer[300];
    std::string curr_working_dir;
    if (getcwd(buffer, 300) != NULL)
    {
        curr_working_dir = buffer;
    }
    return curr_working_dir;
}
bool Utils::isDirectory(std::string filePath)
{
    return std::filesystem::is_directory(filePath);
}
void Utils::split_path_by_folders(std::string& currWorkingDir, std::vector<std::string>& temp_string_array) {
    std::string temp_str;
    for (int i = 0; i < currWorkingDir.size(); i++)
    {
        if ('/' != currWorkingDir[i])
        {
            temp_str.push_back(currWorkingDir[i]);
        }
        else
        {
            if (!temp_str.empty())
            {
                temp_string_array.push_back(temp_str);
                temp_str.clear();
            }
        }
    }
}
void Utils::filter_out_double_dot(std::vector<std::string>& temp_string_array, std::stack<std::string>& my_stack) {
    for(int i =  0 ; i < temp_string_array.size();i++) {        
        if (temp_string_array[i] != "..") {
            my_stack.push(temp_string_array[i]);
        } else {
            if (!my_stack.empty())
                my_stack.pop();
        }
    }
}
void Utils::form_final_str_from_stack(std::stack<std::string>& my_stack, std::string& final_str) {
    std::vector<std::string> string_vec;
    while(!my_stack.empty()) {
        std::string temp_str = my_stack.top();
        string_vec.push_back(temp_str);
        my_stack.pop();
    }
    
    for (int i = string_vec.size() -1 ;i >=0;i--) {
        final_str = final_str + "/" + string_vec[i];
    }
    final_str.append("/");
}
std::string Utils::sanitizeCurrWorkingDirectory(std::string currWorkingDir)
{
    std::vector<std::string> temp_string_array;
    std::string final_str;

    split_path_by_folders(currWorkingDir, temp_string_array);
    
    std::stack<std::string> mystack;
    filter_out_double_dot(temp_string_array, mystack);

    form_final_str_from_stack(mystack, final_str);
    
    return final_str;
}

std::vector<std::string> Utils::ListCurrentFilesinDirectory(std::string directoryPath)
{
    std::vector<std::string> myvec;
    if (std::filesystem::is_directory(directoryPath))
    {
        for (auto &entry : std::filesystem::directory_iterator(directoryPath))
        {
            myvec.push_back(entry.path());
        }

        for (auto &it : myvec)
        {
            it.erase(0, directoryPath.length());
        }
        return myvec;
    }
    return myvec;
}