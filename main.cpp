#include <QCoreApplication>
#include "saveslack.hpp"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    SaveSlack saveSlack{};

    return a.exec();
}
