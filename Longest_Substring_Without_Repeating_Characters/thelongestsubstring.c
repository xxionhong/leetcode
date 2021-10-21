#include <stdio.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int check_duplicate(char *, int, int);
void sliding_window(char *);
void hashtable(char *);

int check_duplicate(char *s, int left, int right)
{
    if (left == right)
    {
        return -1;
    }
    while (left < right)
    {
        if (s[left] == s[right])
        {
            return left;
        }
        left += 1;
    }
    return -1;
}

void sliding_window(char *s)
{
    int left = 0, right = 0;
    int max = 0;
    int result = 0;
    while (left <= right && s[right] != '\0')
    {
        result = check_duplicate(s, left, right);
        if (result == -1)
        {
            right += 1;
        }
        else
        {
            max = MAX((right - left), max);
            printf("left= %d, right=%d, max=%d\n", left, right, max);
            left = result + 1;
            right += 1;
        }
    }
    max = MAX((right - left), max);
    printf("left= %d, right=%d, max=%d\n", left, right, max);
}

void hashtable(char *s)
{
    int map[128];
    memset(map, -1, sizeof(map));
    int max = 0, temp = 0;
    int left = 0, right = 0;
    while (right < strlen(s))
    {
        if (map[(int)s[right]] == -1)
        {
            map[(int)s[right]] = right;
        }
        else if (map[(int)s[right]] != -1)
        {
            temp = right - left;
            max = MAX(max, temp);
            printf("run left= %d, right=%d, max= %d\n", left, right, max);
            temp = 0;
            left = MAX(map[(int)s[right]] + 1, left);
            map[(int)s[right]] = right;
        }
        
        right += 1;
    }
    temp = right - left;
    max = MAX(max, temp);
    printf("end left= %d, right=%d, max= %d\n", left, right, max);
    printf("Max: %d\n", max);
}

int main()
{
    char str[21];
    printf("Input a string < 20 Chars:\n");
    scanf("%20s", str);

    sliding_window(str);
    printf("-------------\n");
    hashtable(str);

    return 0;
}