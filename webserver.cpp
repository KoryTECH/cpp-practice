#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib") //Tells the MSVC linker to link against the import library for ws2_32.dll

int main(){
    WSADATA wsaData;
    
    WSAstartup(MAKEWORD(2,2), &wsadata); // initiation call

    
    
}