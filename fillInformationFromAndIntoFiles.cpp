#include <iostream>
#include "linkInformation.h"
#include "linkInformation.cpp"
#include "fillInformationFromAndIntoFiles.h"
#include <fstream>
;
using namespace std;


int isNotFilled()
{
    static int x=0;
    x++;
    return x;
}
void fillVectorsFromFiles()
{
    //fill vector linkk
    {
        ifstream in("all files/fromTo.txt");
        if(in.fail())
        {
            cout<<"Error in file fromTo.txt\n";
        }
        int idques;
        while(in>>idques)
        {
            linkFromTo x;
            x.idQuestion=idques;
            in>>x.idFrom>>x.idTo;
            linkk.push_back(x);
        }
        in.close();
    }
    //fill vector ques
    {
        ifstream in("all files/Questions.txt");
        if(in.fail())
        {
            cout<<"Error in file Questions.txt\n";
        }
        int idques;
        while(in>>idques)
        {
            string question;
            getline(in,question,'\n');
            ques.push_back({idques,question});
        }
        in.close();
    }
    //fill vector Answre
    {
        ifstream in("all files/Answres.txt");
        if(in.fail())
        {
            cout<<"Error in file Answres.txt\n";
        }
        int idans;
        while(in>>idans)
        {
            string ans;
            getline(in,ans,'\n');
            Answre.push_back({idans,ans});
        }
        in.close();
    }
    //fill vector thAnswre
    {
        ifstream in("all files/thread answres.txt");
        if(in.fail())
        {
            cout<<"Error in file thread answres.txt\n";
        }
        int idAnsThread;
        while(in>>idAnsThread)
        {
            string ThreadAns;
            getline(in,ThreadAns,'\n');
            thAnswre.push_back({idAnsThread,ThreadAns});
        }
        in.close();
    }
    //fill vector users
    {
        ifstream in("all files/users.txt");
        if(in.fail())
        {
            cout<<"Error in file users.txt\n";
        }
        int iduser;
        string name,username,email,pass;
        bool allwoAnonymous,AnonymounAccount;
        while(in>>iduser)
        {
            in>>name>>username>>email>>pass>>AnonymounAccount>>allwoAnonymous;
            linkUser x;
            x.allowAnonymous=allwoAnonymous;
            x.iduser=iduser;
            x.username=username;
            x.AnonymousAccount=AnonymounAccount;
            users.push_back(x);
        }
        in.close();
    }
    //fill vector threadQues
    {
        ifstream in("all files/Threads ques.txt");
        if(in.fail())
        {
            cout<<"Error in file Threads ques.txt\n";
        }
        int idques,idThread,idFrom;
        while(in>>idques)
        {
            string ThQuestion;
            in>>idThread>>idFrom;
            getline(in,ThQuestion,'\n');
            Threads x;
            x.idFrom=idFrom;
            x.idQuestion=idques;
            x.idThread=idThread;
            x.QuestionThread=ThQuestion;
            threadsQues.push_back(x);
        }
        in.close();
    }
}
void fillFilesFromVectors()
{
    {
        ofstream out("all files/Questions.txt");
        if(out.fail())
        {
            cout<<"Error in out file Question.txt\n";
        }
        for(int i=0; i<ques.size(); i++)
        {
            out<<ques[i].first<<" "<<ques[i].second<<"\n";
        }
        out.close();
    }
    {
        ofstream out("all files/fromTo.txt");
        if(out.fail())
        {
            cout<<"Error in out file fromTo.txt\n";
        }
        for(int i=0; i<linkk.size(); i++)
        {
            out<<linkk[i].idQuestion<<" "<<linkk[i].idFrom<<" "<<linkk[i].idTo<<"\n";
        }
        out.close();
    }
    {
        ofstream out("all files/Answres.txt");
        if(out.fail())
        {
            cout<<"Error in out file Answre.txt\n";
        }
        for(int i=0; i<Answre.size(); i++)
        {
            out<<Answre[i].first<<" "<<Answre[i].second<<"\n";
        }
        out.close();
    }
    {
        ofstream out("all files/Threads ques.txt");
        if(out.fail())
        {
            cout<<"Error in out file Threads ques.txt\n";
        }
        for(int i=0; i<threadsQues.size(); i++)
        {
            out<<threadsQues[i].idQuestion<<" "<<threadsQues[i].idThread<<" "<<threadsQues[i].idFrom<<" "<<threadsQues[i].QuestionThread<<"\n";
        }
        out.close();
    }
    {
        ofstream out("all files/thread answres.txt");
        if(out.fail())
        {
            cout<<"Error in out file Threads thread answres.txt\n";
        }
        for(int i=0; i<thAnswre.size(); i++)
        {
            out<<thAnswre[i].first<<" "<<thAnswre[i].second<<"\n";
        }
        out.close();
    }
}
