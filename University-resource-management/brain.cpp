#include "brain.h"
#include "dataset.h"


brain::brain()
{
}
QString brain::autenticate(QString username, QString pass)
{
    User s=users.Search_ID(users.Search_UserName(username));
    if(s.Get_password()==pass){
        ID=s.Get_ID();
        return s.Get_role();}
    else {
        return "no";
    }
}

void brain::signup(User add)
{
    users.Insert(add);
}

User brain::Load_user(QString ID)
{
    users.Search_ID(ID);
}

QString brain::Get_ID()
{
    return ID;
}
