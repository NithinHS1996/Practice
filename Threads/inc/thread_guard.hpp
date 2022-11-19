/***************************************/
/* thread_guard.hpp - thread_guard.cpp header file */
/***************************************/

/******************/
/* Global Defines */
/******************/

/* Module's public typedefs and defines go here. */
#pragma once
#include <thread>
#include <iostream>

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

class ThreadGuard
{
    thread &thread_id;
public:
    explicit ThreadGuard(thread &id):thread_id(id){}
    ~ThreadGuard()
     {
	cout << "exit\n";
	if(thread_id.joinable())
	    thread_id.join();
     }
    ThreadGuard(const ThreadGuard &) = delete;
    ThreadGuard & operator =(const ThreadGuard &) = delete;
};
