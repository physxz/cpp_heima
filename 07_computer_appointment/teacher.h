#pragma once
#include <string>
#include <vector>
#include "identity.h"
#include "orderFile.h"
#include "student.h"

class Teacher: public Identity
{
public:
    Teacher();

    Teacher(int id, string name, string passwd);

    virtual void operateMenu();

    void showAllOrder();

    void checkOrder();

    int m_EmpId;
};