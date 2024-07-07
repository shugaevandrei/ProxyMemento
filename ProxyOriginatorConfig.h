#pragma once

#include "AbstractConfig.h"
#include "Memento.h"
#include <memory>
#include <QDebug>

class ProxyOriginatorConfig : public AbstractConfig
{
public:
    explicit ProxyOriginatorConfig(std::shared_ptr<ImplConfig> config);
    ~ProxyOriginatorConfig() override = default;

    ProxyOriginatorConfig &operator=(const ImplConfig& other);

    int getFirstParam() const override;
    int getSecondParam() const override;

    void setFirstParam(int param) override;
    void setSecondParam(int param) override;

    Memento saveStateToMemento() const;
    void getStateFromMemento(const Memento& memento);

private:
    std::shared_ptr<ImplConfig> config_;

    void setParamsFromState(const std::shared_ptr<ImplConfig>& state);
};
