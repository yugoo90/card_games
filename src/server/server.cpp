#include "oatpp/json/ObjectMapper.hpp"
#include "oatpp/web/server/HttpConnectionHandler.hpp"
#include "oatpp/network/Server.hpp"
#include "oatpp/network/tcp/server/ConnectionProvider.hpp"
#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/macro/codegen.hpp"

#include "../controller/Controller.hpp"
#include "../server/ServerComponent.hpp"


void run() {
    /* Register Components in scope of run() method. */
    ServerComponent components;

    /* Create a Router for HTTP requests routing */
    OATPP_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, router);

    /* Create Controller and add all of its endpoints to router */
    auto controller = std::make_shared<Controller>();
    router->addController(controller);

    /* Create HTTP connection handler with router */
    auto connectionHandler = 
        oatpp::web::server::HttpConnectionHandler::createShared(router);

    /* Create TCP connection provider */
    OATPP_COMPONENT(std::shared_ptr<oatpp::network::ServerConnectionProvider>, 
        connectionProvider);
    
    /* Create server that takes proided TCP connections 
     * and passes them to HTTP connection handler
    */
    oatpp::network::Server server(connectionProvider, connectionHandler);

    /* Print info about server port */
    OATPP_LOGi("MyApp", 
        "Server running on port %s",
        connectionProvider->getProperty("port").getData());
    
    /* Run server */
    server.run();
}

int main() {
    /* Init oatpp Environment */
    oatpp::Environment::init();

    /* Run App */
    run();

    /* Destroy oatpp Environment */
    oatpp::Environment::destroy();

    return 0;
}