
/*****************************************************************************
*
******************************************************************************
*           C++   M O D U L E   S P E C I F I C A T I O N   B L O C K
******************************************************************************
*
*   Module Name:    thread_args.C
*
*   Project:        multi threading practice
*
*   Author:         Nithin HS
*
*   Description:    sending argument to thread
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
*   Function:       func
*
*   Call:           func()
*
*   Input(s):       None
*
*   Output(s):      None
*
*   Description:    Function just prints
*
*   Calls:          None
*
*****************************************************************************/

void func(int a, int b)
{
    cout << "sum is = " << (a+b) << "\n";
}

/*****************************************************************************
*           C++   F U N C T I O N   S P E C I F I C A T I O N   B L O C K
******************************************************************************
*
*   Function:       func1
*
*   Call:           func1()
*
*   Input(s):       None
*
*   Output(s):      None
*
*   Description:    Function just prints
*
*   Calls:          None
*
*****************************************************************************/

void func1(int &a)
{
    while(1){
        cout << "x value is " << a << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
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
*   Description:    Function demonstarte the arguments passed to threads
*
*   Calls:          None
*
*****************************************************************************/
int main()
{
    cout << "Hi from Main\n";
    thread thread_id(func, 2, 3);
    int x = 10;
    thread thread_id1(func1,std::ref(x));
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    x = 100;
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    ThreadGuard threadGuard(thread_id);
    ThreadGuard threadGuard1(thread_id1);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    return 0;
}
