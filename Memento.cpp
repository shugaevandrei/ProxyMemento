#include "Memento.h"
#include "ImplConfig.h"

Memento::Memento(std::shared_ptr<ImplConfig> state)
    : state_(std::move(state)) {}

std::shared_ptr<ImplConfig> Memento::getState() const { return state_; }
