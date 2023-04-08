
#include "headers.hpp"
using boost::asio::ip::tcp;
std::mutex mtx;
std::string handle_command(const std::string& command)
{
    std::vector<std::string> tokens = split_string(command, ' ');
    if (tokens[0] == "pwd")
        return pwd();
    else if (tokens[0] == "mkdir")
        return mkdir(tokens);
    else if (tokens[0] == "ls")
        return list();
    else if (tokens[0] == "cd")
        return change_dir(tokens);
    else if (tokens[0] == "rm")
        return rm_dir(tokens);
    else if (tokens[0] == "sys")
        return sys();
    else if (tokens[0] == "get")
        return get_file(tokens);
    else if(tokens[0][0] == '@')
            return user_validation(tokens);
    else
        return "Unknown command.";
}

void session(tcp::socket sock)
{
    try
    {
        while (true)
        {
            boost::asio::streambuf buf;
            boost::asio::read_until(sock, buf, "\n");
            std::string data = boost::asio::buffer_cast<const char*>(buf.data());
            data = data.substr(0, data.size() - 1);
            std::string response = handle_command(data) + "\n";
            mtx.lock();
            boost::asio::write(sock, boost::asio::buffer(response));
            mtx.unlock();
        }
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception in thread: " << e.what() << std::endl;
    }
}

void server(boost::asio::io_context& io_context, unsigned short port)
{
    tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), port));
    while (true)
    {
        try
        {
            tcp::socket sock(io_context);
            acceptor.accept(sock);
            std::thread(session, std::move(sock)).detach();
        }
        catch (std::exception& e)
        {
            std::cerr << "Exception in thread: " << e.what() << std::endl;
        }
    }
}

int main(int argc, char* argv[])
{
    try
    {
        if (argc != 2)
        {
            std::cerr << "Usage: server <port>\n";
            return 1;
        }
        boost::asio::io_context io_context;
        std::thread t(server, std::ref(io_context), std::atoi(argv[1]));
        t.join();
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}