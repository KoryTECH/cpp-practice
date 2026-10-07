# HTTP Server Documentation

This project contains a simple HTTP server written in C++ using the Windows Winsock API. The server listens on port `8080`, accepts one client connection, prints the incoming HTTP request, and responds with a basic message: `Hello, world!`.

The implementation is in [httpserver.cpp](httpserver.cpp).

---

## 1. Project Overview

This program demonstrates how to:

- initialize the Winsock library on Windows,
- create a TCP socket,
- bind the socket to a local address and port,
- listen for incoming connections,
- accept a client connection,
- receive raw HTTP data,
- send a hardcoded HTTP response.

It is a minimal educational example and is not a production-ready web server.

---

## 2. File Structure

```text
cpp practice/
├── httpserver.cpp
├── README.md
└── other example C++ files...
```

The main file is:

- [httpserver.cpp](httpserver.cpp) — the HTTP server implementation.

---

## 3. What the Server Does

When the program runs, it performs the following sequence:

1. Initializes Winsock.
2. Creates a TCP socket.
3. Binds the socket to `INADDR_ANY` on port `8080`.
4. Starts listening.
5. Accepts a single incoming connection.
6. Receives the HTTP request bytes from the client.
7. Prints the raw request to the console.
8. Sends a generated HTTP response.
9. Closes the sockets and exits.

---

## 4. Technical Requirements

### Platform

This code is designed for Microsoft Windows because it uses:

- `winsock2.h`
- `ws2tcpip.h`
- `WSAStartup()`
- `closesocket()`

### Required Library

```cpp
#pragma comment(lib, "ws2_32.lib")
```

This tells the compiler to link against the Winsock library.

---

## 5. Code Breakdown

### 5.1 Includes

```cpp
#include <iostream>
#include <string>
#include <winsock2.h>
#include <ws2tcpip.h>
```

These provide:

- console input/output,
- string manipulation,
- socket programming APIs,
- Windows networking definitions.

---

### 5.2 Winsock Initialization

```cpp
WSADATA wsaData;
if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
    std::cerr << "WSAStartup failed\n";
    return 1;
}
```

`WSAStartup()` initializes Winsock. It must be called before any socket operations. `MAKEWORD(2, 2)` requests Winsock version 2.2.

If initialization fails, the program exits immediately.

---

### 5.3 Create a Socket

```cpp
SOCKET server_fd = socket(AF_INET, SOCK_STREAM, 0);
```

This creates a TCP socket:

- `AF_INET` = IPv4
- `SOCK_STREAM` = stream-oriented connection (TCP)
- `0` = default protocol for TCP

If the socket creation fails, the program reports the WinSock error and exits.

---

### 5.4 Bind the Socket

```cpp
sockaddr_in address{};
address.sin_family = AF_INET;
address.sin_addr.s_addr = INADDR_ANY;
address.sin_port = htons(8080);
```

This configures the socket to bind to:

- all local network interfaces (`INADDR_ANY`),
- port `8080`.

`htons()` converts the port from host byte order to network byte order.

```cpp
if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) == SOCKET_ERROR) {
    std::cerr << "Bind failed: " << WSAGetLastError() << "\n";
    closesocket(server_fd);
    WSACleanup();
    return 1;
}
```

If the port is already in use, binding fails.

---

### 5.5 Listen for Connections

```cpp
if (listen(server_fd, 5) == SOCKET_ERROR) {
    std::cerr << "Listen failed: " << WSAGetLastError() << "\n";
    closesocket(server_fd);
    WSACleanup();
    return 1;
}
```

The server enters listening mode. The second parameter, `5`, is the backlog size: how many pending incoming connections can be queued.

---

### 5.6 Accept a Client

```cpp
sockaddr_in client_address{};
int client_len = sizeof(client_address);
SOCKET client_fd = accept(server_fd, (struct sockaddr*)&client_address, &client_len);
```

When a client connects, `accept()` creates a new socket specifically for that connection.

- `server_fd` stays open for future connections.
- `client_fd` is used for communication with the current client.

If `accept()` fails, the server logs the error and exits.

---

### 5.7 Receive the HTTP Request

```cpp
char buffer[4096] = {0};
int bytes_read = recv(client_fd, buffer, sizeof(buffer) - 1, 0);
```

This reads up to 4095 bytes from the client into `buffer`.

If data is received, it prints the request to the console:

```cpp
std::cout << "--- Raw request received (" << bytes_read << " bytes) ---\n";
std::cout << buffer << "\n";
```

This is useful for debugging because it shows the raw HTTP request text.

A typical browser request looks like:

```http
GET / HTTP/1.1
Host: localhost:8080
User-Agent: Mozilla/5.0
Accept: text/html
...
```

---

### 5.8 Build the HTTP Response

```cpp
std::string body = "Hello, world!";
std::string response =
    "HTTP/1.1 200 OK\r\n"
    "Content-Type: text/plain\r\n"
    "Content-Length: " + std::to_string(body.size()) + "\r\n"
    "Connection: close\r\n"
    "\r\n" +
    body;
```

This creates a minimal valid HTTP response:

- status: `200 OK`
- content type: `text/plain`
- content length: length of body
- connection: close
- body: `Hello, world!`

The `\r\n` sequences are required because HTTP uses carriage-return and newline separators between headers.

---

### 5.9 Send the Response

```cpp
send(client_fd, response.c_str(), (int)response.size(), 0);
```

This sends the response back to the browser or client.

The response is sent using the same socket created for the accepted connection.

---

### 5.10 Cleanup

```cpp
closesocket(client_fd);
closesocket(server_fd);
WSACleanup();
```

The code closes the client socket, closes the listening socket, and terminates the Winsock session cleanly.

---

## 6. Example HTTP Response

The server sends something like this:

```http
HTTP/1.1 200 OK
Content-Type: text/plain
Content-Length: 13
Connection: close

Hello, world!
```

This is a valid minimal HTTP response body for a plain text page.

---

## 7. How to Run the Server

### Compile with g++ on Windows

```powershell
g++ .\httpserver.cpp -o .\httpserver.exe
```

### Run it

```powershell
.\httpserver.exe
```

Then open a browser and visit:

```text
http://localhost:8080
```

The browser will receive the response and display:

```text
Hello, world!
```

---

## 8. Expected Console Output

When a client connects, the server prints something similar to:

```text
Listening on http://localhost:8080
--- Raw request received (xxx bytes) ---
GET / HTTP/1.1
Host: localhost:8080
...
-----------------------------------------
```

---

## 9. Characteristics of the Program

### Strengths

- easy to understand,
- demonstrates TCP socket basics,
- shows how a raw HTTP request is received,
- shows how a basic HTTP response is constructed,
- useful for learning network programming.

### Limitations

This server is intentionally minimal, and it does not include:

- a request loop,
- multiple client support,
- path routing,
- HTML file serving,
- multi-threading,
- request parsing,
- robust error recovery,
- HTTPS support,
- production-grade security.

The program handles only one client request and then exits.

---

## 10. Important Design Notes

### Single-Connection Server

The server accepts one connection and then stops. It does not continue listening for more clients after the first request is served.

### Raw Request Handling

The program reads everything the client sends as a raw byte stream and prints it. It does not parse the request method, URL, headers, or body.

### Hardcoded Response

The HTTP response is fixed and does not vary based on the client request. Every request gets the same response.

---

## 11. Real-World Improvement Ideas

To turn this into a more useful HTTP server, you could add:

1. a loop to accept multiple connections,
2. parsing of `GET`, `POST`, and other HTTP methods,
3. route detection such as `/`, `/about`, `/api`,
4. HTML file serving,
5. JSON responses,
6. multi-threading or asynchronous networking,
7. proper request/response buffering,
8. logging for requests and errors.

---

## 12. Summary

This project is a simple introduction to socket programming and HTTP in C++. It shows how a Windows server can:

- open a port,
- listen for traffic,
- accept a client,
- receive a request,
- respond with a valid HTTP message.

Although it is not a full web server, it is an excellent starting point for learning the fundamentals of networked applications and HTTP communication.

---

## 13. Learning Takeaways

After studying this file, a learner should understand:

- how to initialize Winsock,
- how TCP sockets work,
- how `bind()`, `listen()`, and `accept()` fit together,
- how to read incoming data with `recv()`,
- how to create a simple HTTP response,
- how to send data using `send()`.

This is a foundational example for network programming in C++.

---

## 14. License and Usage

This code is intended for educational learning and experimentation. You may modify and reuse it for personal practice and learning projects.

---

If you want, I can also create:

- a more advanced version of this server that handles multiple clients,
- a version that serves HTML pages,
- or a detailed line-by-line annotated version of [httpserver.cpp](httpserver.cpp).
