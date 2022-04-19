#include <stdio.h>
int main()
{
    char s[20];
    int t;
    FILE* fp;
    fp = fopen("file.txt", "w");
    if (fp == NULL) return 0;
    t=fprintf(fp, "%s", "HelloWorld!");
    if (t == 0)
    {
        printf("No");
    }
    else printf("Yes");
    fclose(fp);

    /*fp = fopen("file.txt", "r");
    if (fp == NULL) return 0;
    fscanf(fp, "%s", s);
    fclose(fp);

    printf("%s", s);*/
    return 0;
}
