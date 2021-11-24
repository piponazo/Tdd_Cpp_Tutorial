#include <myLibrary/myLibrary.h>

#include <gtest/gtest.h>

TEST(BarcodeLabelGenerator, generateCodeTypeLabelForCode128)
{
  BarcodeLabelGenerator generator;
  ASSERT_EQ("01", generator.codeType(BarcodeType::Code128));
}


TEST(BarcodeLabelGenerator, generateCodeTypeLabelForCode39)
{
  BarcodeLabelGenerator generator;
  ASSERT_EQ("02", generator.codeType(BarcodeType::Code39));
}

TEST(BarcodeLabelGenerator, generateCodeTypeLabelForCodebar)
{
  BarcodeLabelGenerator generator;
  ASSERT_EQ("03", generator.codeType(BarcodeType::Codabar));
}
