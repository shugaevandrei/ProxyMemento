#include "ImplConfig.h"

ImplConfig::ImplConfig() = default;

int ImplConfig::getFirstParam() const
{
    return firstParam_;
}

int ImplConfig::getSecondParam() const
{
    return secondParam_;
}

void ImplConfig::setFirstParam(int param)
{
    firstParam_ = param;
}

void ImplConfig::setSecondParam(int param)
{
    secondParam_ = param;
}

std::shared_ptr<ImplConfig> ImplConfig::clone() const
{
    return std::make_shared<ImplConfig>(*this);
}
