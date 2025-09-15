#ifndef RESPONSEDTO_HPP
#define RESPONSEDTO_HPP

#include "oatpp/Types.hpp"
#include "oatpp/macro/codegen.hpp"

#include <string>

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * Response Data Transfer Object
 */
class ResponseDTO : public oatpp::DTO {
  
  DTO_INIT(ResponseDTO, DTO)

  DTO_FIELD(String, message);      // Response message
};

#include OATPP_CODEGEN_END(DTO)

#endif // RESPONSEDTO_HPP