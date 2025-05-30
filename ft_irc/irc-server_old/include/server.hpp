#ifndef SERVER_HPP
#define SERVER_HPP

#include <vector>
#include <string>
#include <sys/epoll.h>
#include <memory>
#include "client.hpp"

class Client;

class Server 
{
	private:
		int _port;
		int _epoll_fd;
		int _server_fd;
		std::vector<Client*> _clients;
		
	public:
		Server(int port);
		void start();
		void acceptClient();
		void handleClient();
		void handleCommand(Client &client, const std::string &command);
};

#endif // SERVER_HPP