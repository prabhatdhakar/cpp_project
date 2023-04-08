#include "../headers.hpp"
std::string pwd(){
    return std::filesystem::current_path().string();
}        