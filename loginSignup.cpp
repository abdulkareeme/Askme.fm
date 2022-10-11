#include <iostream>
#include "loginSignup.h"
#include "linkInformation.h"
#include "linkInformation.cpp"
#include "idGeneretor.h"
#include <fstream>
using namespace std;
int login (string u,string pass)
{
    ifstream uin ("all files/users.txt");
    string fn,fem,fpass,fuse;
    int fid;
    bool fAnA,fAnR;
    int ok=-1;
    while(uin>>fid)
    {
        uin>>fn>>fuse>>fem>>fpass>>fAnA>>fAnR;
        if(fuse==u)
        {
            if(fpass==pass)
            {
                ok=fid;
            }
            else
            {
                ok=-1;
            }
        }
    }
    return ok;
}

Signup::Signup(string n,string u, string e,string pass,bool anA,bool anR)
{
    ifstream uin ("all files/users.txt");
    string fn,fem,fpass,fuse;
    int fid;
    bool fAnR,fAnA;
    string ok="";
    while(uin>>fid)
    {
        uin>>fn>>fuse>>fem>>fpass>>fAnR>>fAnA;
        if(e==fem)
        {
            ok+="Email is alredy exist";
        }
        if(u==fuse)
        {
            if(ok!="")ok+=" and ";
            ok+="username is alredy exist";
        }
    }
    if(ok=="")
    {
        uin.close();
        name=n;
        username=u;
        email=e;
        passowrd=pass;
        id=generate_id("all files/last id users.txt");
        AnonimousRecive=anR;
        AnonimousAccount=anA;
        uin.close();
        ofstream uout("all files/users.txt", ios::out | ios::app);
        uout<<id<<" "<<name<<" "<<username<<" "<<email<<" "<<passowrd<<" "<<AnonimousAccount<<" "<<AnonimousRecive<<"\n";
        uout.close();

        linkUser x;
        x.allowAnonymous=AnonimousRecive;
        x.AnonymousAccount=AnonimousAccount;
        x.iduser=id;
        x.username=username;
        users.push_back(x);
    }
    else
    {
        cout<<ok<<"\n";
    }
}
