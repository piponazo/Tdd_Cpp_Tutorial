#include <myLibrary/myLibrary.h>

std::string BarcodeLabelGenerator::codeType(const BarcodeType &type)
{
  return "0" + std::to_string(static_cast<int>(type));
//  switch (type) {
//  case BarcodeType::Code128: return "01";
//  case BarcodeType::Code39:  return "02";
//  case BarcodeType::Codabar: return "03";
//  }
//  return "00";
}
