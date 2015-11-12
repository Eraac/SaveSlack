#ifndef BASEREPO_HPP
#define BASEREPO_HPP

#include "Utility/database.hpp"

namespace Repo
{
    class BaseRepo
    {
        protected:
        static Utility::Database m_database;
    };
}

#endif // BASEREPO_HPP

