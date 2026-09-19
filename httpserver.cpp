#include <iostream>
#include <string>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")

int main() {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "WSAStartup failed\n";
        return 1;
    }

    //Create a socket.
    
    SOCKET server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == INVALID_SOCKET) {
        std::cerr << "Failed to create socket: " << WSAGetLastError() << "\n";
        WSACleanup();
        return 1;
    }

    // Describe the address we want to bind to.
    sockaddr_in address{};
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;      
    address.sin_port = htons(8080);            

    //Bind the socket to that address + port.
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) == SOCKET_ERROR) {
        std::cerr << "Bind failed: " << WSAGetLastError() << "\n";
        closesocket(server_fd);
        WSACleanup();
        return 1;
    }

    // Start listening. Backlog = how many pending connections the OS queues.
    if (listen(server_fd, 5) == SOCKET_ERROR) {
        std::cerr << "Listen failed: " << WSAGetLastError() << "\n";
        closesocket(server_fd);
        WSACleanup();
        return 1;
    }

    std::cout << "Listening on http://localhost:8080\n";

    // Block here until a client connects. Returns a NEW socket representing that connection; server_fd stays free to accept more connections later.
    sockaddr_in client_address{};
    int client_len = sizeof(client_address);
    SOCKET client_fd = accept(server_fd, (struct sockaddr*)&client_address, &client_len);
    if (client_fd == INVALID_SOCKET) {
        std::cerr << "Accept failed: " << WSAGetLastError() << "\n";
        closesocket(server_fd);
        WSACleanup();
        return 1;
    }

    // Read whatever the client sent. This is the raw HTTP request text.
    char buffer[4096] = {0};
    int bytes_read = recv(client_fd, buffer, sizeof(buffer) - 1, 0);
    if (bytes_read > 0) {
        std::cout << "--- Raw request received (" << bytes_read << " bytes) ---\n";
        std::cout << buffer << "\n";
    } else {
        std::cout << "No data received (error: " << WSAGetLastError() << ")\n";
    }
    std::cout << "-----------------------------------------\n";

    // Build a hardcoded HTTP response.
    std::string body = "Hello, world!";
    std::string response =
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/plain\r\n"
        "Content-Length: " + std::to_string(body.size()) + "\r\n"
        "Connection: close\r\n"
        "\r\n" +
        body;

    // Send it back over the SAME connection socket.
    send(client_fd, response.c_str(), (int)response.size(), 0);

    // Clean up. On Windows use closesocket(), not close().
    closesocket(client_fd);
    closesocket(server_fd);
    WSACleanup();

    return 0;
}
