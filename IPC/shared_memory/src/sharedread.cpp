#include<iostream.h>
#include<sys/mman.h>

int main()
{
    int N = 5;
    
    int *ptr = mmap(NULL, N*sizeof(int), PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, 0, 0);
    if(ptr == MAP_FAILED)
        cout << "mapping failed\n";
        
    for(int i = 0; i < N; i++)
        ptr[i] = i*10;
    for(int i = 0; i < N; i++)
        cout << ptr[i];
        
    cout << "\n";
    
    int err = munmap(ptr, 10*sizeof(int));
    if(err)
    	cout << "Unmapping failed\";
    
    return 0;
}
