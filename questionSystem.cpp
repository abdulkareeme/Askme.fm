#include <iostream>
#include "linkInformation.h"
#include "linkInformation.cpp"
#include "checkFunction.h"
#include "getInformationFromFiles.h"
#include "fillInformationFromAndIntoFiles.h"
#include "questionSystem.h"
#include "idGeneretor.h"
;
using namespace std;
;
void QuestionSystem::AskQ(int from, int to,string question)
{
    if(CheckIfUserIsAnonymous(from))
    {
        if(!CheckIfUserAllowAnonymousQuestion(to))
        {
            cout<<"NOTE : This user dose not allow Anonymous Question , Do you want to countionue ? Y/N : ";
            char c;
            cin>>c;
            if(c=='N')return;
            else if(c!='Y')
            {
                cout<<"invalid input\n";
                return;
            }
        }
    }
    idQ=generate_id("all files/last id question.txt");
    ofstream fques("all files/Questions.txt");
    fques<<idQ<<" "<<question<<"\n";
    ofstream link("all files/fromTo.txt");
    link<<idQ<<" "<<from<<" "<<to<<"\n";
    link.close();
    fques.close();

    linkFromTo x;
    x.idFrom=from;
    x.idTo=to;
    x.idQuestion=idQ;
    linkk.push_back(x);

    ques.push_back({idQ,question});

}
void QuestionSystem::AskTH(int from,int idques,string question)
{
    int to =getIdReciverFromIdQuestion(idques);
    if(CheckIfUserIsAnonymous(from))
    {
        if(!CheckIfUserAllowAnonymousQuestion(to))
        {
            cout<<"NOTE : This user dose not allow Anonymous Question , Do you want to countionue ? Y/N : ";
            char c;
            cin>>c;
            if(c=='N')return;
            else if(c!='Y')
            {
                cout<<"invalid input\n";
                return;
            }
        }
    }
    idTH=generate_id("all files/last id question.txt");
    ofstream fthread("all files/Threads ques.txt");
    fthread<<idques<<" "<<idTH<<" "<<from<<" "<<question<<"\n";
    fthread.close();

    Threads x;
    x.idFrom= from;
    x.idQuestion=idques;
    x.idThread=idTH;
    x.QuestionThread=question;
    threadsQues.push_back(x);
}
void QuestionSystem::AnswereToMyQuestion(int idQuestion,int myId,string myAnswere)
{
    if(checkIfQuestionToMe(idQuestion,myId))
    {
        ofstream out("all files/Answres.txt");
        out<<idQuestion<<" "<<myAnswere<<"\n";
        out.close();
        Answre.push_back({idQuestion,myAnswere});
    }
    else
    {
        cout<<"The question is not to you or it is not exist\n";
    }
}
void QuestionSystem::AnswereToMyThreadQuestion(int idThread, int myId, string myAnswere)
{
    int idQuestion=getQuestionTdFromThreadId(idThread);
    if(idQuestion==-1)
    {
        cout<<"No such question is this id\n";
        return;
    }

    if(checkIfQuestionToMe(idQuestion,myId))
    {
        if(checkIfThreadAnswereIsExist(idThread))
        {
            cout<<"The answere is already exist \n";
        }
        else
        {
            ofstream out("all files/thread answres.txt");
            out<<idThread<<" "<<myAnswere<<"\n";
            thAnswre.push_back({idThread,myAnswere});
            out.close();
        }
    }
    else
    {
        cout<<"The question is not to you or it is not exist\n";
    }
}
void QuestionSystem::DeleteQuestion(int idQuestion,int myId)
{
    bool IsMyQueston=0;
    for(int i=0; i<linkk.size(); i++)
    {
        if(idQuestion==linkk[i].idQuestion && myId==linkk[i].idFrom)IsMyQueston=1;
    }
    if(IsMyQueston)
    {
        for(auto it=ques.begin(); it!=ques.end(); it++)
        {
            if((*it).first==idQuestion)
            {
                ques.erase(it);
                it--;
            }
        }
        for(auto it=linkk.begin(); it!=linkk.end(); it++)
        {
            if((*it).idQuestion==idQuestion)
            {
                linkk.erase(it);
                it--;
            }
        }
        for(auto it=Answre.begin(); it!=Answre.end(); it++)
        {
            if((*it).first==idQuestion)
            {
                Answre.erase(it);
                it--;
            }
        }
        vector<int>getIdThreads;
        for(auto it=threadsQues.begin(); it!=threadsQues.end(); it++)
        {
            if((*it).idQuestion==idQuestion)
            {
                getIdThreads.push_back((*it).idThread);
                threadsQues.erase(it);
                it--;
            }
        }
        for(int i=0; i<getIdThreads.size(); i++)
        {
            for(auto it=thAnswre.begin(); it!=thAnswre.end(); it++)
            {
                if((*it).first==getIdThreads[i])
                {
                    thAnswre.erase(it);
                    it--;
                }
            }
        }
        fillFilesFromVectors();
    }
    else
    {
        cout<<"This is not your question you are not allowed to delete it !!\n";
    }
}

