#ifndef checkFunction
#define checkFunction
#include <iostream>
#include "linkInformation.h"
#include <vector>
using namespace std;

bool CheckIfUserIsAnonymous(int idUserCheck);
bool CheckIfUserAllowAnonymousQuestion(int idUserCheck);
bool checkIfQuestionToMe(int idQuestionCheck,int myId);
bool checkIfAnswereIsExist(int idquestionCheck);
bool checkIfThreadAnswereIsExist(int IdThreadCheck);
bool checkIfQuestionIsExist(int idQuesCheck);
bool checkIfAskMyself(int MyId,int idTo);
#endif // checkFunction
