#include <iostream>
#include "idGeneretor.h"
#include "loginSignup.h"
#include "linkInformation.h"
#include "linkInformation.cpp"
#include "fillInformationFromAndIntoFiles.h"
#include "getInformationFromFiles.h"
#include "checkFunction.h"
#include "questionSystem.h"
#include "run.h"
using namespace std;

void runMenuOfSystem (int MyId)
{
    QuestionSystem run;
    int chois;
    cin>>chois;
    if(cin.fail())
    {
        cout<<"Invalid value\n";
    }
    else if(chois==9)
    {
        return ;
    }
    else if(chois==8) return;
    else if(chois==5)
    {
        cout<<"If you want to ask a new question press -1 , else press the id of the question : ";
        int idques;
        cin>>idques;
        if(idques==-1)
        {
            cout<<"Enter username of the user you want to ask : ";
            string username;
            cin>>username;
            int idReciver=getIdFromUsername(username);
            if(checkIfAskMyself(MyId,idReciver))
            {
                cout<<"You can\'t ask yourself !\n";
            }
            else
            {
                if(idReciver!=-1)
                {
                    cout<<"Enter your question : ";
                    cin.ignore();
                    string question;
                    getline(cin,question,'\n');
                    run.AskQ(MyId,idReciver,question);
                }
                else
                {
                    cout<<"User dose not exist\n";
                }
            }
        }
        else
        {
            if(checkIfQuestionIsExist(idques))
            {
                cout<<"Enter your question : ";
                cin.ignore();
                string question;
                getline(cin,question,'\n');
                run.AskTH(MyId,idques,question);
            }
            else
            {
                cout<<"No such question in this id ! \n";
            }
        }
    }
    else if(chois==4)
    {
        cout<<"Enter your question id : ";
        int quesId;
        cin>>quesId;
        if(checkIfQuestionIsExist(quesId))
            run.DeleteQuestion(quesId,MyId);
        else cout<<"No such question !\n";
    }
    else if(chois==3)
    {
        cout<<"If you want to answere to a main question press -1 , else press the id of the Thread Question you want to answere : ";
        int idThread;
        cin>>idThread;
        if(idThread==-1)
        {
            cout<<"Enter your question id : ";
            int quesId;
            cin>>quesId;
            if(checkIfAnswereIsExist(quesId))
            {
                cout<<"The answere is already exist.\n";
            }
            else
            {
                cout<<"Enter your Answere : ";
                cin.ignore();
                string Ans;
                getline(cin,Ans,'\n');
                run.AnswereToMyQuestion(quesId,MyId,Ans);
            }
        }
        else
        {
            cout<<"Enter your Answere : ";
            cin.ignore();
            string Ans;
            getline(cin,Ans,'\n');
            run.AnswereToMyThreadQuestion(idThread,MyId,Ans);
        }
    }
    else if(chois==6)
    {
        printAllUsers();
    }
    else if(chois==2)
    {
        for(auto [idQuestion,idFrom,idTo]:linkk)
        {
            if(idFrom==MyId)
            {
                string mainQuestion,mainAnswere;
                getQuestionWithAnswere(idQuestion,mainQuestion,mainAnswere);
                cout<<"Question Id("<<idQuestion<<") from you :\n";
                cout<<"\tQuestion :"<<mainQuestion<<"\t\t"<<"Answere :"<<mainAnswere<<"\n";
                // get Thread question for this question
                for(auto [idQues, idThread, idFrom, threadQuestion]:threadsQues)
                {
                    if(idQues==idQuestion)
                    {
                        cout<<"\t\tQuestion Id("<<idThread<<")";
                        if(CheckIfUserIsAnonymous(idFrom)) // maybe later right it if variable
                        {
                            if(CheckIfUserAllowAnonymousQuestion(idTo))// maybe later right it if variable
                                cout<<" FORM ANONYMOUS USER";
                            else
                            {
                                cout<<" from user "<<getUsernameFromId(idFrom);
                            }
                        }
                        else
                        {
                            cout<<" from user "<<getUsernameFromId(idFrom);
                        }
                        cout<<" :\n";
                        cout<<"\t\t\t Thread :"<<threadQuestion<<"\n";
                        string Ans=getAnswereThreadFromId(idThread);
                        if(Ans!=" No Answere")
                            cout<<"\t\t\tAnswere :"<<Ans<<"\n";
                    }
                }
            }
        }
    }
    else if(chois==1)
    {
        for(auto [idQuestion,idFrom,idTo]:linkk)
        {
            if(idTo==MyId)
            {
                string mainQuestion,mainAnswere;
                getQuestionWithAnswere(idQuestion,mainQuestion,mainAnswere);
                cout<<"Question Id("<<idQuestion<<")" ;
                if(CheckIfUserIsAnonymous(idFrom)) // maybe later right it if variable
                {
                    if(CheckIfUserAllowAnonymousQuestion(idTo))// maybe later right it if variable
                        cout<<" FORM ANONYMOUS USER";
                    else
                    {
                        cout<<" from user "<<getUsernameFromId(idFrom);
                    }
                }
                cout<<" :\n";
                cout<<"\tQuestion :"<<mainQuestion<<"\t\t"<<"Answere :"<<mainAnswere<<"\n";
                // get Thread question for this question
                for(auto [idQues, idThread, idFrom, threadQuestion]:threadsQues)
                {
                    if(idQues==idQuestion)
                    {
                        cout<<"\t\tQuestion Id("<<idThread<<")";
                        if(CheckIfUserIsAnonymous(idFrom)) // maybe later right it if variable
                        {
                            if(CheckIfUserAllowAnonymousQuestion(idTo))// maybe later right it if variable
                                cout<<" FORM ANONYMOUS USER";
                            else
                            {
                                cout<<" from user "<<getUsernameFromId(idFrom);
                            }
                        }
                        else
                        {
                            cout<<" from user "<<getUsernameFromId(idFrom);
                        }
                        cout<<" :\n";
                        cout<<"\t\t\t Thread :"<<threadQuestion<<"\n";
                        string Ans=getAnswereThreadFromId(idThread);
                        if(Ans!=" No Answere")
                            cout<<"\t\t\tAnswere :"<<Ans<<"\n";
                    }
                }
            }
        }
    }
    else if(chois==7)
    {
        for(auto [idQuestionAns,Ans]:Answre)
        {
            for(auto [idQuestion,idFrom,idTo]:linkk)
            {
                if(idQuestion==idQuestionAns)
                {

                    string mainQuestion,mainAnswere;
                    getQuestionWithAnswere(idQuestion,mainQuestion,mainAnswere);
                    cout<<"Question Id("<<idQuestion<<")" ;
                    if(CheckIfUserIsAnonymous(idFrom)) // maybe later right it if variable
                    {
                        if(CheckIfUserAllowAnonymousQuestion(idTo))// maybe later right it if variable
                            cout<<" FORM ANONYMOUS USER";
                        else
                        {
                            cout<<" from user "<<getUsernameFromId(idFrom);
                        }
                    }
                    cout<<" :\n";
                    cout<<"\tQuestion :"<<mainQuestion<<"\t\t"<<"Answere :"<<mainAnswere<<"\n";
                    // Treads
                    for(auto [idQues, idThread, idFrom, threadQuestion]:threadsQues)
                    {
                        if(idQues==idQuestion)
                        {
                            string Ans=getAnswereThreadFromId(idThread);
                            if(Ans==" No Answere")
                                continue;
                            cout<<"Question Id("<<idThread<<") from parent question ("<<idQuestion<<")";
                            if(CheckIfUserIsAnonymous(idFrom)) // maybe later right it if variable
                            {
                                if(CheckIfUserAllowAnonymousQuestion(idTo))// maybe later right it if variable
                                    cout<<" FORM ANONYMOUS USER";
                                else
                                {
                                    cout<<" from user "<<getUsernameFromId(idFrom);
                                }
                            }
                            else
                            {
                                cout<<" from user "<<getUsernameFromId(idFrom);
                            }
                            cout<<" to user "<<getUsernameFromId(idTo)<<" :\n";
                            cout<<"\tThread :"<<threadQuestion<<"\t\tAnswere :"<<Ans<<"\n"; "\n";
                        }
                    }

                }
            }
        }
    }
    else
    {
        cout<<"Invalid value\n";
    }
}
void runMenuOfSignup()
{
    string name,email,username,pass;
    bool AnonymousRecive,AnonimousAccount;
    cout<<"\nEnter your name : ";
    cin>>name;
    cout<<"\nEnter your email : ";
    cin>>email;
    cout<<"\nEnter your username : ";
    cin>>username;
    cout<<"\nEnter your passowrd : ";
    cin>>pass;
    cout<<"\nDo you allow the anonymous users to ask you a questions? press 0/1 : ";
    cin>>AnonymousRecive;
    cout<<"\nDo you want your account to be anonymous ? Press 0/1 : ";
    cin>>AnonimousAccount;
    Signup NewAccount = Signup(name,username,email,pass,AnonimousAccount,AnonymousRecive);
}
