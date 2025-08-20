#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include <memory>
#include <iostream>
#include <vector>
#include "UI.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class Controller : public oatpp::web::server::api::ApiController {
 public:
    Controller(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, ObjectMapper)) 
        : oatpp::web::server::api::ApiController(ObjectMapper) {}
    
    ENDPOINT("GET", "/" , root) {

    }
}


#include #include OATPP_CODEGEN_END(ApiController)

#endif