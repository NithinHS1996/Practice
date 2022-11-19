
/*****************************************************************************
*
******************************************************************************
*           C++   M O D U L E   S P E C I F I C A T I O N   B L O C K
******************************************************************************
*
*   Module Name:    thread_mutex.cpp
*
*   Project:        multi threading practice
*
*   Author:         Nithin HS
*
*   Description:    usage of mutex
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
*   15-01-2022  1.00    NHS     First release
*
*****************************************************************************/

/************************/
/* System Include Files */
/************************/

#include <chrono>
#include <list>
#include <numeric>
#include <string>
#include <thread>
#include <functional>
#include <algorithm>
#include <mutex>
#include <chrono>

/************************/
/* Project Include Files */
/************************/

#include "thread_guard.hpp"

/******************/
/* Module Defines */
/******************/

/* Module's private typedefs and defines go here. */

/********************/
/* Module Variables */
/********************/

/* Module's private (static) variables go here. */
std::list<int> myList;
std::mutex     mut;
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
*   Function:       add_to_list
*
*   Call:           add_to_list(int)
*
*   Input(s):       None
*
*   Output(s):      None
*
*   Description:    adds data to list
*
*   Calls:          None
*
*****************************************************************************/
void add_to_list(int data)
{
    cout << "Hi from List and my tread id is " << std::this_thread::get_id() << "\n";
    mut.lock();
    myList.push_back(data);
    mut.unlock();
}

/*****************************************************************************
*           C++   F U N C T I O N   S P E C I F I C A T I O N   B L O C K
******************************************************************************
*
*   Function:       add_to_list_lg
*
*   Call:           add_to_list_lg(int)
*
*   Input(s):       None
*
*   Output(s):      None
*
*   Description:    adds data to list
*
*   Calls:          None
*
*****************************************************************************/
void add_to_list_lg(int data)
{
    cout << "Hi from List and my tread id is " << std::this_thread::get_id() << "\n";
    std::lock_guard<std::mutex> lg(mut);
    myList.push_back(data);

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

    std::thread thread_id(add_to_list, 10);
    std::thread thread_id1(add_to_list_lg, 20);

    ThreadGuard threadguard(thread_id);
    ThreadGuard threadguard1(thread_id1);

    this_thread::sleep_for(std::chrono::milliseconds(1000));
    cout << "List size is" << myList.size() << "\n";
    return 0;
}
