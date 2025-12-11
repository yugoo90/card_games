#ifndef AILEVELDTO_HPP
#define AILEVELDTO_HPP

#include "oatpp/Types.hpp"
#include "oatpp/macro/codegen.hpp"

#include <string>

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * DTO for AI Level
 */

ENUM (AILevel, v_int32,
    VALUE(EASY, 0, "Easy"),
    VALUE(NORMAL, 1, "Normal"),
    VALUE(HARD, 2, "Hard")
);

#include OATPP_CODEGEN_END(DTO)
#endif // AILEVELDTO_HPP