#include "../headers.hpp"

std::string change_dir(std::vector<std::string>& tokens){
        if (tokens.size() == 1)
            return "Usage: cd <directory_path>";
        else
        {
            try
            {
                std::filesystem::current_path(tokens[1]);
                return "Directory changed successfully.";
            }
            catch (std::exception& e)
            {
                return "Failed to change directory: " + std::string(e.what());
            }
        }
}