#pragma once

#include "Memento.h"
#include <vector>
#include <stdexcept>

class Caretaker
{
public:
    void addMemento(const Memento& memento);

    Memento getMemento(size_t index) const;

private:
    std::vector<Memento> mementos_;
};
