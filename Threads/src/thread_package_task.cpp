
/*****************************************************************************
*
******************************************************************************
*           C++   M O D U L E   S P E C I F I C A T I O N   B L O C K
******************************************************************************
*
*   Module Name:    thread_package_task.cpp
*
*   Project:        multi threading practice
*
*   Author:         Nithin HS
*
*   Description:    future with package_task usage
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
*   Function:       SomeWork
*
*   Call:           SomeWork()
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

int SomeWork()
{
    cout << "Hey doing some work\n";
}

/*****************************************************************************
*           C++   F U N C T I O N   S P E C I F I C A T I O N   B L O C K
******************************************************************************
*
*   Function:       AsyncWork
*
*   Call:           AsyncWork()
*
*   Input(s):       None
*
*   Output(s):      None
*
*   Description:    does async work
*
*   Calls:          None
*
*****************************************************************************/

int AsyncWork(int a,int b)
{
    cout << "The AsyncWork thread id is: " << std::this_thread::get_id() << "\n";
    return (a+b);
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
    std::packaged_task<int(int,int)> task_1(AsyncWork);
    std::future<int> future_1 = task_1.get_future();
    std::thread thread_id(std::move(task_1),1,2);
    thread_id.detach();

    //SomeWork();
   cout << "Hey got the future value: " << future_1.get() << "\n";
    return 0;
}
