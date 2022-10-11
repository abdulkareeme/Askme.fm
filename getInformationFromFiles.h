#ifndef getInfo
#define getInfo
#include <iostream>
#include "linkInformation.h"

using namespace std;

int getIdReciverFromIdQuestion(int idQuestionCheck);
int getIdFromUsername(string usernameCheck);
string getUsernameFromId(int idUserCheck);
int getQuestionTdFromThreadId(int threadIdCheck);
void printAllUsers();
void getQuestionWithAnswere(int idQuestionCheck,string & getQuestion,string & getAnswere);
string getAnswereThreadFromId(int idThreadCheck);
#endif // getInfo
