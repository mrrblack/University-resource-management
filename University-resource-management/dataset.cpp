#include "dataset.h"
Persons_database::Persons_database()
{
    counter=1000;
    total=0;
}

void Persons_database::Set_URL(QString URL)
{
    this->URL =URL;
}



void Persons_database::Insert(User row)
{
    QFile file(URL);
    file.open(QIODevice::Append);
    QTextStream out(&file);

    //write user info on file

    row.Rand_ID();

<<<<<<< HEAD
    (row.Get_ID()!="")?out <<row.Get_ID()<<';':out<<"#"<<";";
    (row.Get_name()!="")?out <<row.Get_name()<<';':out<<"#"<<";";
    (row.Get_family()!="")?out <<row.Get_family()<<';':out<<"#"<<";";
    (row.Get_phonenum()!="")?out <<row.Get_phonenum()<<';':out<<"#"<<";";
    (row.Get_email()!="")?out <<row.Get_email()<<';':out<<"#"<<";";
    (row.Get_username()!="")?out <<row.Get_username()<<';':out<<"#"<<";";
    (row.Get_password()!="")?out <<row.Get_password()<<';':out<<"#"<<";";
    (row.Get_imgurl()!="")?out <<row.Get_imgurl()<<'U'<<';':out<<"#"<<';'<<'U'<<';';
    counter++;
    total++;
    //out<<'\n';
=======
    out<<"\r\n";
    out<<"1";
    out <<row.Get_ID()<<';';
    out <<row.Get_username()<<';';
    out <<row.Get_password()<<';';
    out <<row.Get_name()<<';';
    out <<row.Get_family()<<';';
    out <<row.Get_email()<<';';
    out <<row.Get_address()<<';';
    out <<row.Get_phonenum()<<';';
    out<<"#";//image url
    out<<'U'<<';';
    out<<'#'<<';';//for office ID

>>>>>>> b3906d58788bcf749480741a3728d115719523e0

    file.close();
}

void Persons_database::Update()
{

}
QString Persons_database::Select(int row)
{
    //open file
    QFile file(URL);
    file.open(QIODevice::ReadOnly);

    int counter=0;// use for arrive to requst line.
    QString line;
    while(!file.atEnd()){

        line=file.readLine();
        if(row==counter){
            break;
        }

        counter++;
    }
    file.close();


    return line;

}
QString Persons_database::Select_obj(int row, int column)
{

    QString line;
    QString result="";
    line =Select(row);
    int pos_semi_1=0,pos_semi_2=0;//position of semicolons(;).firs one and second.
    for (int i=0;line[i]!='\x0'&&column>=0;i++){
        if(line[i]==';'){//save position of semis.
            pos_semi_1=pos_semi_2;
            pos_semi_2=i;
            column--;
        }
    }
    //for first column.
    if (pos_semi_1==0)
        pos_semi_1--;
    for (int i=pos_semi_1+1;i<pos_semi_2;i++){
        result.append(line[i]);
    }
    return result;
}

int Persons_database::Number_of_row()
{
    QFile file(URL);
    file.open(QIODevice::ReadOnly);

    int counter=0;
    QString line;
    while(!file.atEnd()){
        file.readLine();
        counter++;
    }
    file.close();
    return counter;
}
//void Persons_database::Search()
//{

//}
void Persons_database::Delete(QString ID)
{

}
//------------------------------------------------------------



void User::Rand_ID()
{
    srand((unsigned)time(NULL));
    QString m_id="";//rand charactor added into it
    char rnum;//rand charactor
    for (int i=0;i<6;i++){
        rnum =(rand() % 10)+48;
        m_id.append(rnum);
    }
    ID = m_id;//set id
}




void User::Set_ID(QString ID)
{
    this->ID=ID;
}
void User::Set_name(QString name){
    this->name=name;
}
void User::Set_family(QString family)
{
    this->family=family;
}
void User::Set_phonenum(QString phonenum){
    this->phonenum=phonenum;
}
void User::Set_email(QString email){
    this->email=email;
}
void User::Set_username(QString username){
    this->username=username;
}
void User::Set_password(QString password ){
    this->password=password;
}
void User::Set_imgurl(QString imgurl){
    this->imgurl=imgurl;
}
void User::Set_role(QString role){
    this->role=role;
}
void User::Set_address(QString add){
    this->address=add;
}
void User::Set_office_ID(QString office_ID){
    this->office_ID=office_ID;
}
QString User::Get_ID(){
    return ID;
}
QString User::Get_name(){
    return name;
}
QString User::Get_family(){
    return family;
}
QString User::Get_phonenum(){
    return phonenum;
}
QString User::Get_email(){
    return email;
}
QString User::Get_username(){
    return username;
}
QString User::Get_password(){
    return password;
}
QString User::Get_imgurl(){
    return imgurl;
}
QString User::Get_role(){
    return role;
}

QString User::Get_address()
{
    return address;
}

QString User::Get_office_ID()
{
    return office_ID;
}