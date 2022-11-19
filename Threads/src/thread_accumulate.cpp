
/*****************************************************************************
*
******************************************************************************
*           C++   M O D U L E   S P E C I F I C A T I O N   B L O C K
******************************************************************************
*
*   Module Name:    thread_yield.cpp
*
*   Project:        multi threading practice
*
*   Author:         Nithin HS
*
*   Description:    moving ownership of the thread
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
#include <vector>
#include <numeric>
#include <string>
#include <thread>
#include <functional>
#include<algorithm>

/************************/
/* Project Include Files */
/************************/

#include "thread_guard.hpp"

/******************/
/* Module Defines */
/******************/

/* Module's private typedefs and defines go here. */
#define MIN_BLOCK 1000

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

string func(string str, int a)
{
    return str + "-" +to_string(a);
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

void func1()
{
    std::vector<int> vec{1,2,3,4};
    int sum = accumulate(vec.begin(),vec.end(),0);
    cout << "value of the sum is " << sum << "\n";
    int prod = accumulate(vec.begin(),vec.end(),1,std::multiplies<int>());
    cout << "value of the prod is " << prod << "\n";
    string str = accumulate(vec.begin(), vec.end(), to_string(0),func);
    cout << "string value is " << str << "\n";
}

/*****************************************************************************
*           C++   F U N C T I O N   S P E C I F I C A T I O N   B L O C K
******************************************************************************
*
*   Function:       parallel_accumulate
*
*   Call:           parallel_accumulate(itr1,itr2,multiplies)
*
*   Input(s):       Iterator start, Iterator end, operation
*
*   Output(s):      operation results
*
*   Description:    Function does operation in parallel threads
*
*   Calls:          None
*
*****************************************************************************/
template <typename iterator,typename T>
T parallel_accumulate(iterator start,iterator end,T &ref)
{
    int input_size = std::distance(start, end);
    int allowed_threads_by_elements = input_size/MIN_BLOCK;
    int allowed_threads_by_hardware = thread::hardware_concurrency();
    int num_of_threads = std::min(allowed_threads_by_elements, allowed_threads_by_hardware);

    int block_size = (input_size + 1)/num_of_threads;

    std::vector<T> results(num_of_threads);
    std::vector<std::thread> threads(num_of_threads - 1);

    iterator last;

    for(int i = 0; i < num_of_threads - 1; i++)
    {
	last = start;
	std::advance(last, block_size);
	threads[i] = std::thread(accumulate<iterator, T>, start, last, std::ref(results[i]));
	start = last;
    }
    results[num_of_threads - 1] = std::accumulate(start,end,0);
    std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));
    return std::accumulate(results.begin(),results.end(),ref);

    cout << thread::hardware_concurrency() << "\n";
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
    func1();
    std::vector<int> vec{1,2,3,4,5,6,7};
    std::vector<int>::iterator it = vec.begin();
    const int size = 8000;
    int* my_array = new int[size];
    int ref = 0;

    srand(0);

    for(size_t i = 0; i < size; i++)
    {
	my_array[i] = rand() % 10;
    }
    int ret_val = parallel_accumulate<int*, int>(my_array, my_array + size,ref);
    cout << ret_val;
    return 0;
}
