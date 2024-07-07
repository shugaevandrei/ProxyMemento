#include "ProxyOriginatorConfig.h"
#include "ImplConfig.h"

ProxyOriginatorConfig::ProxyOriginatorConfig(std::shared_ptr<ImplConfig> config)
    : config_(std::move(config)) {}

ProxyOriginatorConfig &ProxyOriginatorConfig::operator=(const ImplConfig &other)
{
    config_->setFirstParam(other.getFirstParam());
    config_->setSecondParam(other.getSecondParam());
    return *this;
}

int ProxyOriginatorConfig::getFirstParam() const
{
    qDebug() << "I'm proxy getFirstParam";
    return config_->getFirstParam();
}

int ProxyOriginatorConfig::getSecondParam() const
{
    qDebug() << "I'm proxy getSecondParam";
    return config_->getSecondParam();
}

void ProxyOriginatorConfig::setFirstParam(int param)
{
    qDebug() << "I'm proxy setFirstParam";
    config_->setFirstParam(param);
}

void ProxyOriginatorConfig::setSecondParam(int param)
{
    qDebug() << "I'm proxy setSecondParam";
    config_->setSecondParam(param);
}

Memento ProxyOriginatorConfig::saveStateToMemento() const
{
    return Memento(config_->clone());
}

void ProxyOriginatorConfig::getStateFromMemento(const Memento& memento)
{
    setParamsFromState(memento.getState());
}

void ProxyOriginatorConfig::setParamsFromState(const std::shared_ptr<ImplConfig>& state)
{
    config_->setFirstParam(state->getFirstParam());
    config_->setSecondParam(state->getSecondParam());
    qDebug() << "I'm ProxyOriginatorConfig addMemento" << state->getFirstParam() << state->getSecondParam();
}
