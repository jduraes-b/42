/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 18:56:57 by jduraes-          #+#    #+#             */
/*   Updated: 2025/05/14 20:19:28 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.hpp"

Server::Server(int port, int pass): _port(port), _epoll_fd(-1), _server_fd(-1)
{
}

void Server:start()
{
	_server_fd = socket(AF_INET, SOCK_STREAM, 0);//creates socket
	if (_server_fd == -1)
		throw std::runtime_error("Failed to create socket");
	fcntl(_server_fd, F_SETFL, O_NONBLOCK); //sets non-blocking mode
	sockaddr_in server_addr = {}; //initializes struct with zero values
	server_addr.sin_family = AF_INET; //sets adress family to use IPv4
	server_addr.sin_family = AF_INET; //accepts connections to any network interface
	server_addr.sin_port = htons(port);//converts port to network format and sets it
	if (bind(_server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1)
        throw std::runtime_error("Failed to bind socket");
	if (listen(server_fd, SOMAXCONN) == -1)//constant that specifies max allowed queued connections
        throw std::runtime_error("Failed to listen on socket");
	    _epoll_fd = epoll_create1(0);
    if (_epoll_fd == -1)
        throw std::runtime_error("Failed to create epoll instance");
	epoll_event event = {};
	event.events = EPOLLIN; // Monitor for incoming connections
	event.data.fd = _server_fd;
	if (epoll_ctl(_epoll_fd, EPOLL_CTL_ADD, _server_fd, &event) == -1)
		throw std::runtime_error("Failed to add server socket to epoll");
	std::cout << "Server started on port " << port << std::endl;	

	const int MAX_EVENTS = 10;
	epoll_event events[MAX_EVENTS];
	while (true)
	{
		int	num_events = epoll_wait(_epoll_fd, events, MAX_EVENTS, -1);
		if (num_events == -1)
			throw std::runtime_error("epoll_wait failed");
		for (int i = 0; i < num_events; i++)
		{
			if (events[i].data.fd == _server_fd)
				acceptClient(); //TODO
			else
				handleClient(); //TODO
		}
	}
}
