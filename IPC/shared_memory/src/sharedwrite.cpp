#include<iostream.h>
#include<sys/mman.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>
#include<memory.h>

using namespace std;

typedef struct student
{
   int roll_num;
   int marks;
   char name[128];
   char city[128];
} student_t;

int main()
{
    const char* filepath = "test.txt"
    
    int fd = open(filepath, O_RDWR);
    
    if(fd < 0)
    {
        cout << "Open file error\n";
    }
    
    struct stat statbuf;
    int err = fstat(fd, &statbuf);
    if(err<0)
        cout << "Error getting file size\n";
        
    char *ptr = mmap(NULL, statbuf.st_size, PROT_READ|PRTO_WRITE,MAP_SHARED,fd,0);
    if(ptr == MAP_FAILED)
        cout << "Error opening mmap\n";
        
    close(fd);
    
    student_t stud = {123, 90, "Nithin", "Bangalore"};
    
    memcpy(ptr, &stud, sizeof(stud));
    
    msync(ptr, sizeof(stud), MS_SYNC);
    
    err = munmap(ptr , statbuf.st_size);
    
    if(err != 0)
        cout <<"unmap failed\n";
        
    return 0;
}
