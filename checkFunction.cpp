#include <iostream>
#include "checkFunction.h"
#include "linkInformation.h"
//#include "linkInformation.cpp"
#include <utility>
#include <vector>
using namespace std;
vector<linkUser>users; // iduser , AnonimousAccount , allwoAnomymous , username
vector<linkFromTo>linkk; // idques , idfrom , idto
vector<pair<int,string>>ques; // id , question
vector<pair<int,string>>Answre; // idques , Answere
vector<pair<int,string>>thAnswre; // idtread , Answre
vector<Threads>threadsQues; // idques , idthread , idFrom , question

bool CheckIfUserIsAnonymous(int idUserCheck)
{
    for(auto [iduser, AnonimousAccount, allwoAnomymous, username]:users)
    {
        if(iduser==idUserCheck)
        {
            return AnonimousAccount;
        }
    }
}
bool CheckIfUserAllowAnonymousQuestion(int idUserCheck)
{
    for(auto [iduser, AnonimousAccount, allwoAnomymous, username]:users)
    {
        if(iduser==idUserCheck)
        {
            return allwoAnomymous;
        }
    }
}
bool checkIfQuestionToMe(int idQuestionCheck,int myId)
{
    for(auto [idQues,idFrom,idTo] : linkk)
    {
        if(idQues==idQuestionCheck)
        {
            if(myId==idTo)
                return 1;
        }
    }
    return 0;
}
bool checkIfAnswereIsExist(int idquestionCheck)
{
    for(auto [idQues,Ans]:Answre)
    {
        if(idQues==idquestionCheck) return 1;
    }
    return 0;
}
bool checkIfThreadAnswereIsExist(int IdThreadCheck)
{
    for(auto [idThread,Ans]:thAnswre)
    {
        if(idThread==IdThreadCheck)return 1;
    }
    return 0;
}
bool checkIfQuestionIsExist(int idQuesCheck)
{
    for(auto [idQues,Question]: ques)
    {
        if(idQues==idQuesCheck)return 1;
    }
    return 0;
}
bool checkIfAskMyself(int MyId,int idTo)
{
    return MyId==idTo;
}
