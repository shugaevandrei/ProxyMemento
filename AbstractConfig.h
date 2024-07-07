#pragma once

class AbstractConfig
{
public:
    AbstractConfig() = default;
    virtual ~AbstractConfig() = default;

    virtual int getFirstParam() const = 0;
    virtual int getSecondParam() const = 0;

    virtual void setFirstParam(int param) = 0;
    virtual void setSecondParam(int param) = 0;
};
