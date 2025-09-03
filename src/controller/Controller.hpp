#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "oatpp/macro/component.hpp"
#include "oatpp/macro/codegen.hpp"
#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/json/ObjectMapper.hpp"

#include <memory>
#include <iostream>
#include <vector>


#include OATPP_CODEGEN_BEGIN(ApiController)

class Controller : public oatpp::web::server::api::ApiController {
 public:
    Controller(OATPP_COMPONENT(std::shared_ptr<oatpp::json::ObjectMapper>, ObjectMapper)) 
        : oatpp::web::server::api::ApiController(ObjectMapper) {}

    static std::shared_ptr<Controller> createShared(OATPP_COMPONENT(std::shared_ptr<oatpp::json::ObjectMapper>, ObjectMapper)) {
        return std::make_shared<Controller>(ObjectMapper);
    }
    
    ENDPOINT("GET", "/" , root) {
        return createResponse(Status::CODE_200, "Welcome to the Card Games API!");
    }
};


#include OATPP_CODEGEN_END(ApiController)

#endif