#include "Caretaker.h"

void Caretaker::addMemento(const Memento &memento)
{
    mementos_.push_back(memento);
}

Memento Caretaker::getMemento(size_t index) const
{
    if (index < mementos_.size()) {
        return mementos_.at(index);
    }
    throw std::out_of_range("Invalid memento index");
}
