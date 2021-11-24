#pragma once

#include <string>
#include "exportHeader.h"

enum class BarcodeType {
  Code128 = 1,
  Code39,
  Codabar,
};

class API_EXPORT BarcodeLabelGenerator
{
public:
  std::string codeType(const BarcodeType& type);

private:
};
