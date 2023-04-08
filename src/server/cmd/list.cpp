#include "../headers.hpp"

std::string list(){
        std::ostringstream output;
        for (auto& entry : std::filesystem::directory_iterator("."))
            output << entry.path().filename().string() << std::endl;
        return output.str();
}