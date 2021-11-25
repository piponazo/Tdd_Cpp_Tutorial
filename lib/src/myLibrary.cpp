#include <myLibrary/myLibrary.h>

#include <stdexcept>

std::string BarcodeLabelGenerator::codeType(const CodeType &codeType)
{
  int val = static_cast<int>(codeType);
  if (val < 1 || val > 4) {
    throw std::out_of_range("CodeType is not supported");
  }
  return "0" + std::to_string(val);
}

std::string BarcodeLabelGenerator::xdim(const XDim &val)
{
  switch (val)
  {
    case XDim::dim127: return "127";
    case XDim::dim148: return "148";
  }

    throw std::out_of_range("XDim is not supported");
}

std::string BarcodeLabelGenerator::generate(const CodeType &type, const XDim &dim)
{
  return codeType(type) + xdim(dim);
}
