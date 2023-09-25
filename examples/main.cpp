//============================================================================
// Name        : WppObjectRegestry.cpp
// Author      : Valentin
// Version     :
//============================================================================

#include <iostream>
#include <thread>
#include <chrono>

#include "Server.h"
#include "Security.h"
#include "Device.h"
#include "Connection.h"

#include "WppClient.h"
#include "WppRegistry.h"

using namespace std;
using namespace wpp;

void socketPolling(Connection *connection) {
	while (true) {
		connection->loop();
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}

int main() {
	cout << endl << "------------------- Creating requiered components -------------------" << endl;
	Connection connection("56830", AF_INET);
	ServerImpl server;
	SecurityImpl security;
	DeviceImpl device;

	// Client initialization
	cout << endl << "------------------- Creating WppClient -------------------" << endl;
	WppClient::create({"Test name", "", ""}, connection);
	WppClient *client = WppClient::takeOwnership();
	if (!client) {
		cout << endl << "ERR: WppClient can not be taken" << endl;
		return -1;
	}
	WppRegistry &registry = client->registry();

	// Initialize wpp objects
	cout << endl << "------------------- Initialization wpp Server -------------------" << endl;
	server.init(registry.server());
	cout << endl << "------------------- Initialization wpp Security -------------------" << endl;
	security.init(registry.security());
	cout << endl << "------------------- Initialization wpp Device -------------------" << endl;
	device.init(registry.device());

	// Giving ownership to registry
	client->giveOwnership();

	cout << endl << "------------------- Starting Connection thread -------------------" << endl;
	thread my_thread(socketPolling, &connection);

	time_t callTime = 0;
	for (int iterationCnt = 0; true; iterationCnt++) {
		time_t currTime = time(NULL);

		cout << endl << "------------------- iteration:" << iterationCnt << " -------------------" << endl;
		if (currTime >= callTime || connection.getPacketQueueSize()) {
			// Handle client state and process packets from the server
			client = WppClient::takeOwnership();
			if (client) { 
				callTime = currTime + client->loop();
				client->giveOwnership();
				cout << "Sleep time: " << callTime - time(NULL) << endl;
			}
		}
		this_thread::sleep_for(chrono::seconds(1));
	}
}

