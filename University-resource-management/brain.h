#ifndef BRAIN_H
#define BRAIN_H

#include "office_database.h"
#include "QString"
#include "persons_database.h"
#include "request_database.h"

class brain
{
private:
    Office_database organs;
    Persons_database users;
    request_database reqs;
    static QString ID;


public:
    brain();
    QString autenticate (QString user,QString pass);
    void signup(User add);
    User Load_user(QString ID);
    QString Get_ID();
    void Edit(User user);
 //   organ Get_organ(int line);
   // QString Get_organ_name(int i);
    int Number_of_organs();
    Office_database Get_organs();



};

#endif // BRAIN_H
