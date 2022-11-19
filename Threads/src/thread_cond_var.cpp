
/*****************************************************************************
*
******************************************************************************
*           C++   M O D U L E   S P E C I F I C A T I O N   B L O C K
******************************************************************************
*
*   Module Name:    thread_cond_var.cpp
*
*   Project:        multi threading practice
*
*   Author:         Nithin HS
*
*   Description:    condition variables usage
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
#include <stack>
#include <thread>
#include <mutex>
#include <condition_variable>

/******************/
/* Module Defines */
/******************/

/* Module's private typedefs and defines go here. */

/********************/
/* Module Variables */
/********************/

/* Module's private (static) variables go here. */
int Distancetravelled;
int FinalDestination = 10;
std::mutex mut;
std::condition_variable cv;

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
*   Function:       KeepMoving
*
*   Call:           KeepMoving()
*
*   Input(s):       None
*
*   Output(s):      None
*
*   Description:    keeps printing the distance travelled
*
*   Calls:          None
*
*****************************************************************************/

void KeepMoving()
{
    while(Distancetravelled++ != 9)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        cout << "Hey im moving: " << Distancetravelled << "\n";
    }

    if(FinalDestination == Distancetravelled)
    {
        cv.notify_one();
        cout << "Done mving\n";
    }
}

/*****************************************************************************
*           C++   F U N C T I O N   S P E C I F I C A T I O N   B L O C K
******************************************************************************
*
*   Function:       KeepAlarm
*
*   Call:           KeepAlarm()
*
*   Input(s):       None
*
*   Output(s):      None
*
*   Description:    prints when the time is up
*
*   Calls:          None
*
*****************************************************************************/

void KeepAlarm()
{
    while(Distancetravelled != 10);
    cout << "Hey im at: " << Distancetravelled << "\n";
}

/*****************************************************************************
*           C++   F U N C T I O N   S P E C I F I C A T I O N   B L O C K
******************************************************************************
*
*   Function:       InformMe
*
*   Call:           InformMe()
*
*   Input(s):       None
*
*   Output(s):      None
*
*   Description:    prints when we reach the location
*
*   Calls:          None
*
*****************************************************************************/

void InformMe()
{
    std::unique_lock<std::mutex> ul(mut);
    cv.wait(ul, []{return (FinalDestination == Distancetravelled);});
    cout << "Hey im at exact locaton\n";
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

    std::thread thread_id1(KeepMoving);
    std::thread thread_id2(KeepAlarm);
    std::thread thread_id3(InformMe);

    ThreadGuard threadguard1(thread_id1);
    ThreadGuard threadguard2(thread_id2);
    ThreadGuard threadguard3(thread_id3);

    this_thread::sleep_for(std::chrono::milliseconds(1000));
    cout << "Done with the main\n";

    return 0;
}
