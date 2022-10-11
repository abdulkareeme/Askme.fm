#ifndef linkInfo
#define linkInfo
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

struct linkUser
{
    int iduser;
    bool AnonymousAccount;
    bool allowAnonymous;
    string username;
};
struct linkFromTo
{
    int idQuestion,idFrom,idTo;
};
struct Threads
{
    int idQuestion ;
    int idThread;
    int idFrom;
    string QuestionThread;
};
extent <vector<linkUser>>users; // iduser , AnonimousAccount , allwoAnomymous , username
extent <vector<linkFromTo>>linkk; // idques , idfrom , idto
extent <vector<pair<int,string>>>ques; // id , question
extent <vector<pair<int,string>>>Answre; // idques , Answere
extent <vector<pair<int,string>>>thAnswre; // idtread , Answre
extent <vector<Threads>>threadsQues; // idques , idthread , idFrom , question
#endif // linkInfo






