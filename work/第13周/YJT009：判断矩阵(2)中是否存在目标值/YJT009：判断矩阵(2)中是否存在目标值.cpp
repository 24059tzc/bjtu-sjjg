#include<stdio.h>
int Search_Bin(int ST[], int key, int length)
{ // 在有序表ST中折半查找其关键字等于key的数据元素。若找到，则函数值为
  //该元素在表中的位置，否则为0。
    int low = 0; int high = length - 1, mid;  // 置区间初值
    while (low <= high) {
        mid = (low + high) / 2;
        if (key == ST[mid])   return mid;
        if (key == ST[low])return low;
        if (key == ST[high])return high;//找到待查元素
        else if (key < ST[mid])   high = mid - 1; //继续在前半区间进行查找
        else  low = mid + 1;  // 继续在后半区间进行查找
    }
    return 0; // 顺序表中不存在待查元素
}
int main()
{
    char c;
    for (int i = 0; i < 9; i++)
    {
        c = getchar();
    }
    int temp2, num = 1;
    int temp[30], temp3[10];
    int i = 0, j = 0, k = 0;
    while (c != ']')
    {
        while (c != ']')
        {
            c = getchar();
            temp2 = 0;
            while (c >= '0' && c <= '9')
            {
                temp3[k++] = c - '0';
                c = getchar();
            }
            for (int m = k - 1; m >= 0; m--)
            {
                temp2 = temp2 + num * temp3[m];
                num = num * 10;
            }
            num = 1;
            temp[j++] = temp2;
            k = 0;
        }
        c = getchar();
    }
    for (int i = 0; i < 8; i++)
    {
        getchar();
    }
    int target;
    scanf("%d", &target);
    int order = Search_Bin(temp, target, j);
    if (order == 0)printf("false\n");
    else printf("true\n");
    return 0;
}