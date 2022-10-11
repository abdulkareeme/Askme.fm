#ifndef systemQues
#define systemQues
#include <iostream>
#include "linkInformation.h"
#include "checkFunction.h"
#include "getInformationFromFiles.h"
#include "fillInformationFromAndIntoFiles.h"

using namespace std;


struct QuestionSystem
{
    int idQ;
    int idTH;
    void AskQ(int from, int to,string question);
    void AskTH(int from,int idques,string question);
    void AnswereToMyQuestion(int idQuestion,int myId,string myAnswere);
    void AnswereToMyThreadQuestion(int idThread, int myId, string myAnswere);
    void DeleteQuestion(int idQuestion,int myId);
};
#endif // systemQues
