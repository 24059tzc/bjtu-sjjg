#include <iostream>
#include<stdio.h>
#include<string.h>
int main()
{

    char nums[15];
    int i;
    fgetpos(nums);
    
    for (i = 0; i < 11; i++) 
    {
        printf("%c ", nums[i]);
    }
}