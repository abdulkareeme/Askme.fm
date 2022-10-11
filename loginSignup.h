#ifndef loginSystem
#define loginSystem
#include <iostream>
using namespace std;

int login (string u,string pass);
struct Signup
{
    int id;
    string name,email,passowrd,username,userid;
    bool AnonimousRecive,AnonimousAccount;
    Signup(string n,string u, string e,string pass,bool anA,bool anR);
};
#endif // loginSystem
