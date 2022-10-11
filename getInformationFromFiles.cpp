#include <iostream>
#include "linkInformation.h"
#include "linkInformation.cpp"
#include "getInformationFromFiles.h"

using namespace std;
int getIdReciverFromIdQuestion(int idQuestionCheck)
{
    for(auto [idQuestion,idFrom,idTo] : linkk)
    {
        if(idQuestion==idQuestionCheck)
        {
            return idTo;
        }
    }
    return -1;
}
int getIdFromUsername(string usernameCheck)
{
    for(auto [iduser,AnonymousAccount,allwoAnonymous,username]:users)
    {
        if(usernameCheck==username)
        {
            return iduser;
        }
    }
    return -1;
}
string getUsernameFromId(int idUserCheck)
{
    for(auto [iduser,AnonymousAccount,allwoAnonymous,username]:users)
    {
        if(iduser==idUserCheck)
        {
            return username;
        }
    }
}
int getQuestionTdFromThreadId(int threadIdCheck)
{
    for(auto [idQuestion, idthread, idFrom, question]:threadsQues)
    {
        if(threadIdCheck==idthread)
        {
            return idQuestion;
        }
    }
    return -1;
}
void printAllUsers()
{
    for(auto [idUser,AnonynmousAccount,AllowAnonymous,username]:users)
    {
        cout<<idUser<<" "<<username;
        if(!AllowAnonymous)
        {
            cout<<"\t\tNOTE : This user dose not allow Anonymous Question";
        }
        cout<<"\n";
    }
}
void getQuestionWithAnswere(int idQuestionCheck,string & getQuestion,string & getAnswere)
{
    for(auto [idQuestion,question]:ques)
    {
        if(idQuestion==idQuestionCheck)
        {
            getQuestion=question ;
        }
    }
    getAnswere="No answere yet";
    for(auto [idQuestion,Answere]:Answre)
    {
        if(idQuestion==idQuestionCheck)
        {
            getAnswere=Answere;
        }
    }
}
string getAnswereThreadFromId(int idThreadCheck)
{
    for(auto [idThread,Ans]:thAnswre)
    {
        if(idThread==idThreadCheck)
        {
            return Ans;
        }
    }
    return " No Answere";
}
