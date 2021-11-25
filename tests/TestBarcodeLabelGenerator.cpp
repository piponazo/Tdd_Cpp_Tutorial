#include <myLibrary/myLibrary.h>

#include <gtest/gtest.h>
#include <iostream>

TEST(BarcodeLabelGenerator, generatesCodeTypeTextForCode128)
{
  BarcodeLabelGenerator generator;
  const std::string expected{"01"};
  ASSERT_EQ(expected, generator.codeType(CodeType::Code128));
}

TEST(BarcodeLabelGenerator, generatesCodeTypeTextForCode39)
{
  BarcodeLabelGenerator generator;
  const std::string expected{"02"};
  ASSERT_EQ(expected, generator.codeType(CodeType::Code39));
}

TEST(BarcodeLabelGenerator, generatesCodeTypeTextForCodabar)
{
  BarcodeLabelGenerator generator;
  const std::string expected{"03"};
  ASSERT_EQ(expected, generator.codeType(CodeType::Codabar));
}

TEST(BarcodeLabelGenerator, generatesCodeTypeTextForITF)
{
  BarcodeLabelGenerator generator;
  const std::string expected{"04"};
  ASSERT_EQ(expected, generator.codeType(CodeType::ITF));
}

TEST(BarcodeLabelGenerator, generatesCodeTypeTextForUnexpectedType_throwException)
{
  BarcodeLabelGenerator generator;
  ASSERT_THROW(generator.codeType(static_cast<CodeType>(99)), std::out_of_range);
}

TEST(BarcodeLabelGenerator, generatesXDimTextForValidValue)
{
  BarcodeLabelGenerator generator;
  ASSERT_EQ("127", generator.xdim(XDim::dim127));
  ASSERT_EQ("148", generator.xdim(XDim::dim148));
}

TEST(BarcodeLabelGenerator, generatesXDimTextForInvalidValue_throwsException)
{
  BarcodeLabelGenerator generator;
  ASSERT_THROW(generator.xdim(static_cast<XDim>(126)), std::out_of_range);
}

TEST(BarcodeLabelGenerator, generatesWholeStringWithValidValues)
{
  BarcodeLabelGenerator generator;
  ASSERT_EQ("01127", generator.generate(CodeType::Code128, XDim::dim127));
  ASSERT_EQ("02148", generator.generate(CodeType::Code39, XDim::dim148));
}

TEST(BarcodeLabelGenerator, xxx)
{
  BarcodeLabelGenerator generator;
  std::vector<CodeType> types {CodeType::Code128, CodeType::Code39, CodeType::Codabar, CodeType::ITF};
  std::vector<XDim> dims {XDim::dim127, XDim::dim148};

  for (const auto& type: types) {
    for (const auto& dim: dims) {
      std::cout << generator.generate(type, dim) << std::endl;
    }
  }
}
