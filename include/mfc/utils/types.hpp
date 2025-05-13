#ifndef MFC_TYPES_HPP
#define MFC_TYPES_HPP

#include <cstdint>



typedef uint16_t u16;



#define MFC_NOT_COPYABLE(name)                  \
    name(const name&) = delete;                 \
    name& operator=(const name&) = delete;

#define MFC_NOT_MOVABLE(name)                   \
    name(name&&) = delete;                      \
    name& operator= (name&&) = delete;


#endif