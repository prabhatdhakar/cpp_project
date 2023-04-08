#include "../headers.hpp"

std::string get_file(std::vector<std::string>& tokens){
        if (tokens.size() == 1)
            return "Usage: get <file_path>";
        else
        {
            std::ifstream file(tokens[1], std::ios::binary | std::ios::ate);
            if (!file)
                return "File not found.";
            std::streamsize size = file.tellg();
            file.seekg(0, std::ios::beg);
            std::vector<char> buffer(size);
            if (file.read(buffer.data(), size))
            {
                return std::string(buffer.data(), size);
            }
            else
                return "Error reading file.";
        }
}