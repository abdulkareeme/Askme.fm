#include <bits/stdc++.h>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <windows.h>
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
HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);


int main()
{
    system("Color F1");
    while (true)
    {
        int q;
        cout<<"Menu:\npress 1 to login\npress 2 to signup\nPress 1 or 2 : ";
        cin>>q;
        if(cin.fail())
        {
            cout<<"Invalid value\n";
        }
        else if(q==1)
        {
            string user, pass;
            cout<<"\nEnter your username : ";
            cin>>user;
            cout<<"\nEnter your passowrd : ";
            cin>>pass;
            if(login(user,pass)!=-1)
            {
                //fill the vectors if not filled yet
                if(isNotFilled()==1)
                {
                    fillVectorsFromFiles();
                }
                int MyId=login(user,pass);
                cout<<"Sucsess login \n";
                while(true)
                {

                    cout<<"Menu :\n\
        1 - Print questions to me\n\
        2 - Print questions from me\n\
        3 - Answere question\n\
        4 - Delete Question\n\
        5 - Ask question\n\
        6 - List system users\n\
        7 - feed\n\
        8 - logout\n\
        9 - exit\n\
        Press number in this range 1-9 : ";
                    runMenuOfSystem(MyId);
                }
            }
            else
            {
                cout<<"Error in username or password\n\n";
            }
        }
        else if(q==2)
        {
            runMenuOfSignup();
        }
        else
        {
            cout<<"Invalid value\n";
        }
    }
}
