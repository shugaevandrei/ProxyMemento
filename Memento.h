#pragma once

#include <memory>

class ImplConfig;

class Memento
{
public:
    explicit Memento(std::shared_ptr<ImplConfig> state);
    std::shared_ptr<ImplConfig> getState() const;

private:
    std::shared_ptr<ImplConfig> state_;
};
