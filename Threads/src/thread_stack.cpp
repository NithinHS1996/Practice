
/*****************************************************************************
*
******************************************************************************
*           C++   M O D U L E   S P E C I F I C A T I O N   B L O C K
******************************************************************************
*
*   Module Name:    thread_stack.cpp
*
*   Project:        multi threading practice
*
*   Author:         Nithin HS
*
*   Description:    thread safe stack implementation
*
*   Portability:    None
*
******************************************************************************
*
*   Public
*   Class:          None
*
*   Public
*   Functions:      None
*
*   Public
*   Variables:      None
*
*   External
*   Functions:      thread api's
*
*   External
*   Variables:      None
*
******************************************************************************
*
*   Revision History:
*
*   Date        Rev     By      Description of Revision
*
*   23-01-2022  1.00    NHS     First release
*
*****************************************************************************/

/************************/
/* System Include Files */
/************************/

/************************/
/* Project Include Files */
/************************/

#include "thread_guard.hpp"
#include "thread_stack.hpp"

/******************/
/* Module Defines */
/******************/

/* Module's private typedefs and defines go here. */

/********************/
/* Module Variables */
/********************/

/* Module's private (static) variables go here. */

/********************/
/* Module Constants */
/********************/

/* Module's private (static) const variables go here. */

/*************/
/* Functions */
/*************/

/*****************************************************************************
*           C++   F U N C T I O N   S P E C I F I C A T I O N   B L O C K
******************************************************************************
*
*   Function:       push
*
*   Call:           push()
*
*   Input(s):       element to push into stack
*
*   Output(s):      None
*
*   Description:    Function main
*
*   Calls:          None
*
*****************************************************************************/
template <typename T>
void CThreadStack<T>::Push(T lelement)
{
    std::lock_guard<std::mutex> lg(m_oMutex);
    m_oStack.push(lelement);
}

/*****************************************************************************
*           C++   F U N C T I O N   S P E C I F I C A T I O N   B L O C K
******************************************************************************
*
*   Function:       func
*
*   Call:           main()
*
*   Input(s):       None
*
*   Output(s):      None
*
*   Description:    Function main
*
*   Calls:          None
*
*****************************************************************************/
template <typename T>
void CThreadStack<T>::Pop()
{
    std::lock_guard<std::mutex> lg(m_oMutex);
    m_oStack.pop();
}

/*****************************************************************************
*           C++   F U N C T I O N   S P E C I F I C A T I O N   B L O C K
******************************************************************************
*
*   Function:       func
*
*   Call:           main()
*
*   Input(s):       None
*
*   Output(s):      None
*
*   Description:    Function main
*
*   Calls:          None
*
*****************************************************************************/
template <typename T>
T& CThreadStack<T>::Top()
{
    std::lock_guard<std::mutex> lg(m_oMutex);
    return m_oStack.top();
}

/*****************************************************************************
*           C++   F U N C T I O N   S P E C I F I C A T I O N   B L O C K
******************************************************************************
*
*   Function:       func
*
*   Call:           main()
*
*   Input(s):       None
*
*   Output(s):      None
*
*   Description:    Function main
*
*   Calls:          None
*
*****************************************************************************/
template <typename T>
bool CThreadStack<T>::Empty()
{
    std::lock_guard<std::mutex> lg(m_oMutex);
    return (m_oStack.empty()?true:false);
}

/*****************************************************************************
*           C++   F U N C T I O N   S P E C I F I C A T I O N   B L O C K
******************************************************************************
*
*   Function:       func
*
*   Call:           main()
*
*   Input(s):       None
*
*   Output(s):      None
*
*   Description:    Function main
*
*   Calls:          None
*
*****************************************************************************/
template <typename T>
size_t CThreadStack<T>::Size()
{
    std::lock_guard<std::mutex> lg(m_oMutex);
    return m_oStack.size();
}

/*****************************************************************************
*           C++   F U N C T I O N   S P E C I F I C A T I O N   B L O C K
******************************************************************************
*
*   Function:       func
*
*   Call:           main()
*
*   Input(s):       None
*
*   Output(s):      None
*
*   Description:    Function main
*
*   Calls:          None
*
*****************************************************************************/
int main()
{
    cout << "Hi from Main\n";
/*
    std::thread thread_id(add_to_list, 10);
    std::thread thread_id1(add_to_list_lg, 20);

    ThreadGuard threadguard(thread_id);
    ThreadGuard threadguard1(thread_id1);

    this_thread::sleep_for(std::chrono::milliseconds(1000));
    cout << "List size is" << myList.size() << "\n";
*/

    CThreadStack<int> threadstack;
    threadstack.Push(10);
    cout << "Element inside stack is" << threadstack.Top();
    return 0;
}
