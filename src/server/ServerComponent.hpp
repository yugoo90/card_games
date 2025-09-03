#ifndef SERVERCOMPONENT_HPP
#define SERVERCOMPONENT_HPP

#include <memory>

#include "oatpp/macro/component.hpp"
#include "oatpp/network/tcp/server/ConnectionProvider.hpp"
#include "oatpp/web/server/HttpConnectionHandler.hpp"
#include "oatpp/web/server/HttpRouter.hpp"
#include "oatpp/json/ObjectMapper.hpp"

/**
 *  Class which creates and holds Application components and registers them in the oatpp::base::Environment
 *  Components are created once and can be retrieved anywhere in the code using OATPP_COMPONENT macro
 *  Order of components initialization is from top to bottom
*/

class ServerComponent {
 public:
    /**
     *  Create ConnectionProvider component which listens on the port
     */
    OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::network::ServerConnectionProvider>, serverConnectionProvider)
    ([] {
        return oatpp::network::tcp::server::ConnectionProvider::createShared(
            {"0.0.0.0", 8000, oatpp::network::Address::IP_4});
    }());

    /**
     *  Create Router Component
    */
    OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, httpRouter)
    ([] {
        return oatpp::web::server::HttpRouter::createShared();
    }());

    /**
     *  Create ConnectionHandler component which uses Router component to route requests
    */
    OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::network::ConnectionHandler>, serverConnectionHandler)
    ([] {
        OATPP_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, router);
        return oatpp::web::server::HttpConnectionHandler::createShared(router);
    }());

    /**
     *  Create ObjectMapper component for JSON serialization
    */
    OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::json::ObjectMapper>, objectMapper)
    ([] {
        return std::make_shared<oatpp::json::ObjectMapper>();
    }());

};
#endif