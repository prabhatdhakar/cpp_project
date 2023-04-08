#include "../headers.hpp"
std::string mkdir(std::vector<std::string>& tokens){
        if (tokens.size() == 1)
            return "Usage: mkdir <directory_name>";
        else
        {
            std::filesystem::create_directory(tokens[1]);
            return "Directory created successfully.";
        }
}