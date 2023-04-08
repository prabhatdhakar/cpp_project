#include "../headers.hpp"

std::string rm_dir(std::vector<std::string>& tokens){
    if (tokens.size() == 1)
            return "Usage: rm <directory_name>";
        else
        {
            try
            {
                std::filesystem::remove_all(tokens[1]);
                return "Directory removed successfully.";
            }
            catch (std::exception& e)
            {
                return "Error: " + std::string(e.what());
            }
        }
}