#ifndef MGC_SOURCE_LOCATION_HPP
#define MFC_SOURCE_LOCATION_HPP


#include <format>
#include <string>

#include "mfc/basic/common.hpp"

MFC_NAMESPACE_BEGIN

struct SourceLocation
{
  public:
    SourceLocation() = default;
    explicit constexpr SourceLocation(u16 line, u16 col) : line(line), col(col) {}

    u16 getLine() const { return line; }

    u16 getCol() const { return col; }

    // std::string toString() const { return std::format("<line:{}, col:{}>", line, col); }

  private:
    u16 line = 0;
    u16 col = 0;
};

// the start and stop locations for a token, symbol, or expression
struct SourceRange
{
  public:
    explicit constexpr SourceRange(SourceLocation start, SourceLocation stop) : start(start), stop(stop) {}
    SourceLocation getStart() const { return start; }
    SourceLocation getEnd() const { return stop; }

  private:
    const SourceLocation start = SourceLocation();
    const SourceLocation stop = SourceLocation();
};

MFC_NAMESPECE_END

#endif