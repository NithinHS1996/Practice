
/*****************************************************************************
*
******************************************************************************
*           C++   M O D U L E   S P E C I F I C A T I O N   B L O C K
******************************************************************************
*
*   Module Name:    thread_promise.cpp
*
*   Project:        multi threading practice
*
*   Author:         Nithin HS
*
*   Description:    future with promise usage
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
*   29-01-2022  1.00    NHS     First release
*
*****************************************************************************/

/************************/
/* System Include Files */
/************************/

/************************/
/* Project Include Files */
/************************/

#include "thread_guard.hpp"
#include <future>
#include <thread>
#include <mutex>


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
*   Function:       Promise
*
*   Call:           Promise()
*
*   Input(s):       None
*
*   Output(s):      None
*
*   Description:    does SomeWork
*
*   Calls:          None
*
*****************************************************************************/

int Promise(std::future<int>& future_1)
{
    cout << "The Promise thread id is: " << std::this_thread::get_id() << "\n";
    cout << "Hey got the future value: " << future_1.get() << "\n";
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
    cout << "The main thread id is: " << std::this_thread::get_id() << "\n";
    std::promise<int> prom;
    std::future<int> fut = prom.get_future();
    std::thread thread_id(Promise,std::ref(fut));
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    prom.set_value(10);
    thread_id.join();

    return 0;
}
