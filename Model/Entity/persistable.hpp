#ifndef PERSISTABLE_HPP
#define PERSISTABLE_HPP

#include "Model/Repo/baserepo.hpp"

namespace Entity
{
    class Persistable
    {
        public:
        Persistable();
        unsigned int getId() const;

        protected:
        unsigned int m_id;
    };
}

#endif // PERSISTABLE_HPP

