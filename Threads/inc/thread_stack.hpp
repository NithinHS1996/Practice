/***************************************/
/* thread_stack.hpp - thread_stack.cpp header file */
/***************************************/

/******************/
/* Global Defines */
/******************/

/* Module's public typedefs and defines go here. */
#pragma once

#include <iostream>
#include <stack>
#include <thread>
#include <mutex>

using namespace std;

/********************/
/* Global Variables */
/********************/

/* Module's public variables go here. */

/********************/
/* Global Constants */
/********************/

/* Module's public const variables go here. */

/********************/
/* Global Functions */
/********************/

/* Module's public function prototypes go here. */

template <typename T>
class CThreadStack
{
    std::stack<T> m_oStack;
    std::mutex m_oMutex;

public:
    void Push(T lelement);
    void Pop();
    T& Top();
    bool Empty();
    size_t Size();
};
