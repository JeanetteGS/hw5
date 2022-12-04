// for Json::value
#include <json/json.h>
#include <json/reader.h>
#include <json/writer.h>
#include <json/value.h>
#include <string>

// for JsonRPCCPP
#include <iostream>
// #include "hw5server.h" //already included in "hw5server.cpp"
#include <jsonrpccpp/server/connectors/httpserver.h>
// #include "hw5client.h"
#include <jsonrpccpp/client/connectors/httpclient.h>
#include <stdio.h>

#include "hw5server.cpp"

using namespace jsonrpc;
using namespace std;

int main() {
    HttpServer httpserver(7372);
    Myhw5Server s(httpserver,
		JSONRPC_SERVER_V1V2); // hybrid server (json-rpc 1.0 & 2.0)
    s.StartListening();
    std::cout << "Hit enter to stop the server" << endl;
    getchar();

    s.StopListening();
}