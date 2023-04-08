#include "headers.hpp"

std::string user_validation(std::vector<std::string>& tokens){
        if(tokens[0] == "@prabhat" && tokens[1] == "1234"){
            return "OK";
        }
        return "-1";
}