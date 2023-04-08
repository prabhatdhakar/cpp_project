#ifndef HEADERS
#define HEADERS
#include <boost/asio.hpp>
#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <mutex>
#include <chrono>
#include <sstream>
#include <filesystem>
#include <fstream>

#ifdef _WIN32
#include <windows.h>
#else
#include <sys/utsname.h>
#endif

std::string pwd();
std::string mkdir(std::vector<std::string>&);
std::string rm_dir(std::vector<std::string>&);
std::string list();
std::string change_dir(std::vector<std::string>&);
std::string sys();
std::string get_file(std::vector<std::string>&);
std::string user_validation(std::vector<std::string>&);
std::vector<std::string> split_string(const std::string&, char);

#endif