
/*****************************************************************************
*
******************************************************************************
*           C++   M O D U L E   S P E C I F I C A T I O N   B L O C K
******************************************************************************
*
*   Module Name:    thread_atomic.cpp
*
*   Project:        multi threading practice
*
*   Author:         Nithin HS
*
*   Description:    atomic usage
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
*   30-01-2022  1.00    NHS     First release
*
*****************************************************************************/

/************************/
/* System Include Files */
/************************/

/************************/
/* Project Include Files */
/************************/

#include "thread_guard.hpp"
#include <atomic>
#include <thread>

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
*   Function:       DoSomeWork
*
*   Call:           DoSomeWork()
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

void AtomicFlag()
{
    cout << "The DoSomeWork thread id is: " << std::this_thread::get_id() << "\n";
    std::atomic_flag flag = ATOMIC_FLAG_INIT;
    cout << "Value is: " << flag.test_and_set() << "\n";
    cout << "Value afte test and set is :" << flag.test_and_set() << "\n";
    flag.clear();
    cout << "Value afte flag clear is :" << flag.test_and_set() << "\n";
}

/*****************************************************************************
*           C++   F U N C T I O N   S P E C I F I C A T I O N   B L O C K
******************************************************************************
*
*   Function:       AtomicBool
*
*   Call:           AtomicBool()
*
*   Input(s):       None
*
*   Output(s):      None
*
*   Description:    does AtomicBool operations
*
*   Calls:          None
*
*****************************************************************************/

void AtomicBool()
{
    cout << "The DoSomeWork thread id is: " << std::this_thread::get_id() << "\n";

    std::atomic<bool> x(false);
    cout << "Is lock free: " << x.is_lock_free() << "\n";

    std::atomic<bool> y(true);
    x.store(y);
    cout << "Value in x is: " << x.load() << "\n";

    bool z = x.exchange(false);
    cout << "z and x values are: " << z << " " << x << "\n";


}

/*****************************************************************************
*           C++   F U N C T I O N   S P E C I F I C A T I O N   B L O C K
******************************************************************************
*
*   Function:       DoSomeWork
*
*   Call:           DoSomeWork()
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

void AtomicCompareAndExchange()
{
    cout << "The DoSomeWork thread id is: " << std::this_thread::get_id() << "\n";

    std::atomic<int> x(10);
    int expected = 10;
    bool ret = x.compare_exchange_weak(expected, 5);              //weak is not a successful operation use strong instead

    cout << "is operation sucess " << ret << "\n";
    cout << "the value in x is: " << x << "\n";
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

    //std::thread atomicFlag(AtomicFlag);
    //std::thread atomicBool(AtomicBool);
    std::thread atomiccmpexc(AtomicCompareAndExchange);

    //atomicFlag.join();
    //atomicBool.join();
    atomiccmpexc.join();
    return 0;
}
