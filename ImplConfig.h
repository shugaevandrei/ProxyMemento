#pragma once

#include "AbstractConfig.h"
#include <memory>

class ImplConfig : public AbstractConfig, public std::enable_shared_from_this<ImplConfig>
{
public:
    ImplConfig();
    ~ImplConfig() override = default;

    int getFirstParam() const override;
    int getSecondParam() const override;

    void setFirstParam(int param) override;
    void setSecondParam(int param) override;

    std::shared_ptr<ImplConfig> clone() const;

private:
    int firstParam_{0};
    int secondParam_{0};
};
