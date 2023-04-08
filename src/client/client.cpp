#include <boost/asio.hpp>
#include <iostream>
#include <string>

using boost::asio::ip::tcp;

int main(int argc, char* argv[])
{
    try
    {
        if (argc != 3)
        {
            std::cerr << "Usage: client <host> <port>\n";
            return 1;
        }
        boost::asio::io_context io_context;
        tcp::resolver resolver(io_context);
        tcp::resolver::results_type endpoints =
        resolver.resolve(argv[1], argv[2]);
        tcp::socket socket(io_context);
        boost::asio::connect(socket, endpoints);
        //user validation
        std::string username;
        std::string password;
    while(true){    
                std::cout << "Enter username: ";
                std::getline(std::cin, username);
                std::cout << "Enter password: ";
                std::getline(std::cin, password);
        // Send username and password to server
        std::string credentials = username + " " + password + "\n";
        boost::asio::write(socket, boost::asio::buffer(credentials));

        // Read response from server
        boost::asio::streambuf buf;
        boost::asio::read_until(socket, buf, "\n");
        std::string response = boost::asio::buffer_cast<const char*>(buf.data());
        response = response.substr(0, response.size() - 1);

        // Check if credentials are valid
        if (response != "OK")
        {
            std::cerr << "Invalid credentials. Enter again!!\n";
            continue;
        }
        break;
    }
       // bool validated = false;
        while (true)
        {
            std::cout << "--> ";
            std::string command;
            std::getline(std::cin, command);
            if(command == "quit")
                break;
            boost::asio::write(socket, boost::asio::buffer(command + "\n"));
            boost::asio::streambuf buf;
            boost::asio::read_until(socket, buf, "\n");
            std::string response = boost::asio::buffer_cast<const char*>(buf.data());
            response = response.substr(0, response.size() - 1);
            std::cout << response << std::endl;
        }
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
