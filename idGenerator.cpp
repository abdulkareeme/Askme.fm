#include "idGeneretor.h"
#include <bits/stdc++.h>
#include <fstream>

int generate_id(std::string path)
{
    std::ifstream fID(path);
    int id;
    fID>>id;
    fID.close();
    std::ofstream oID(path);
    oID<<id+1;
    return id+1;
}
