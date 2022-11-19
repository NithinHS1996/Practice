
/*****************************************************************************
*
******************************************************************************
*           C++   M O D U L E   S P E C I F I C A T I O N   B L O C K
******************************************************************************
*
*   Module Name:    thread_promise_exp.cpp
*
*   Project:        multi threading practice
*
*   Author:         Nithin HS
*
*   Description:    promise with exception usage
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
*   Function:       Printing
*
*   Call:           Printing()
*
*   Input(s):       None
*
*   Output(s):      None
*
*   Description:    prints the value
*
*   Calls:          None
*
*****************************************************************************/

void Printing(std::future<int>& future_1)
{
    cout << "The Promise thread id is: " << std::this_thread::get_id() << "\n";
   try
    {
        cout << "Hey got the future value: " << future_1.get() << "\n";
    }
    catch(...)
    {
	cout << "Exeption caught" << "\n";
    }

}

/*****************************************************************************
*           C++   F U N C T I O N   S P E C I F I C A T I O N   B L O C K
******************************************************************************
*
*   Function:       Calculation
*
*   Call:           Calculation()
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

void Calculation(std::promise<int>& prom)
{
    cout << "The calculation thread id is: " << std::this_thread::get_id() << "\n";
    int x;
    cout << "Enter the number to find the square\n";
    try
    {
	std::cin >> x;
	if(x < 0)
	{
	    throw 10;
	}
        prom.set_value(10);
    }
    catch(...)
    {
	cout << "caugth exp\n";
	prom.set_exception(std::current_exception());
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

    std::thread printing_thread(Printing,std::ref(fut));
    std::thread calculation_thread(Calculation,std::ref(prom));

    printing_thread.join();
    calculation_thread.join();

    return 0;
}
