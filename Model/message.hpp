#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <QString>
//#include "Model/Repo/messagerepo.hpp"
#include "persistable.hpp"

namespace Repo {
    class PassageRepo;
}

// TODO Faire qqchose de plus propre
namespace Entity
{
    class Message : public Persistable
    {
        //friend class Repo::MessageRepo;

        public:
        Message(QString m_user, QString m_channel, QString m_text, QString m_ts);

        private:
        QString m_user;
        QString m_channel;
        QString m_text;
        QString m_ts;
    };
}

#endif // MESSAGE_HPP

