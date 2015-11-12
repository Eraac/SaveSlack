#include "persistable.hpp"

Entity::Persistable::Persistable() : m_id(0) {}

unsigned int Entity::Persistable::getId() const
{
    return m_id;
}
