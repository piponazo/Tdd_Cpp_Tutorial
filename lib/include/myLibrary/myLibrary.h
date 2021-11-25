#pragma once

#include <string>
#include "exportHeader.h"

enum class CodeType
{
  Code128 = 1,
  Code39,
  Codabar,
  ITF
};

enum class XDim
{
  dim127,
  dim148
};

class API_EXPORT BarcodeLabelGenerator
{
public:
  std::string codeType(const CodeType& codeType);
  std::string xdim(const XDim& val);

  std::string generate(const CodeType& type, const XDim& dim);

private:
};
