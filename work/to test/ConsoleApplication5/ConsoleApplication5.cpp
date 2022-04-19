#include <stdio.h>
#include<iostream>
#include<string.h>
#include<cstringt.h>
int main() {

    char nums[12];
    scanf("%s", nums);
    printf("%p", nums);
    int i, j, temp,min;
    for (i = 0; i <9; i++) 
    {
        min = nums[i];
        for (j = i+1; j <10; j++)
        {
            if (nums[j] < min) 
            {
                temp = nums[j];
                nums[j] = min;
                nums[i] = temp;
            }
        }
    }

    //输出排序后的数组
    for (i = 0; i < 10; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}