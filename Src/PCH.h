#pragma once

// Defines
#define INL_XCC(x) #x
#define INL_CC(x) INL_XCC(x)
#define INL_IND(x) x
#define INL_INC #include
#define INL(name) INL_INC INL_CC(INL_IND(name)INL_IND(_inl.h))

#include <memory>

// Utility
#include "Utility/XString.h"

// Containers
#include "Structure/DataStruct.h"
