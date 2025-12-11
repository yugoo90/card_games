#ifndef GAMETYPEDTO_HPP
#define GAMETYPEDTO_HPP

#include "oatpp/Types.hpp"
#include "oatpp/macro/codegen.hpp"

#include <string>

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * DTO for Game Type
 */

ENUM (GameType, v_int32,
    VALUE(GOFISH, 0, "GoFish"),
    VALUE(CRAZYEIGHTS, 1, "CrazyEights")
);

#include OATPP_CODEGEN_END(DTO)
#endif /* GAMETYPEDTO_HPP */