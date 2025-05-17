#ifndef MFC_COMMON_HPP
#define MFC_COMMON_HPP

#include <cstdint>


#define MFC_NOT_COPYABLE(name)                  \
    name(const name&) = delete;                 \
    name& operator=(const name&) = delete;

#define MFC_NOT_MOVABLE(name)                   \
    name(name&&) = delete;                      \
    name& operator= (name&&) = delete;

#define MFC_NAMESPACE_BEGIN namespace mfc {     
#define MFC_NAMESPECE_END }                     

typedef uint8_t     u8;
typedef uint16_t    u16;
typedef uint32_t    u32;
typedef uint64_t    u64;
typedef int8_t      i8;
typedef int16_t     i16;
typedef int32_t     i32;
typedef int64_t     i64;


#endif