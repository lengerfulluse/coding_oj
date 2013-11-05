#include<stdio.h>
#include<iostream>
#include<string>
#include<cstring>
#include<cstdlib>
using namespace std;
void arraysize(char arr[10]);
main()
{
    string str("hello");
    char *str1="hello";
    char str2[]="welcome you";
    char str3[10]="vector";
    /* for the pointer in function, sizeof(str) is the sizeof(pointer). */
    arraysize(str3);
    void *p = malloc(100);
    cout<<sizeof(p)<<endl;
    printf("%d %d %d %d %d %d\n",sizeof(str1),sizeof(str2),sizeof("abcd"),sizeof(str3), strlen(str3), sizeof(str));
}

void arraysize(char arr[10]) {
    cout<<sizeof(arr)<<endl;
}
/* some classical explaination about the sizeof and strlen. 
*  
* wrote:
* > hello,
* > what is difference between sizeof("abcd") and strlen("abcd")? why
* > both functions gives different output when applied to same string
* > "abcd".
* > I tried following example for that.
* > #include <stdio.h>
* > #include <string.h>
* > void main()
* > {
* > char *str1="abcd";
* > char str2[]="abcd";
* > printf("%d %d %d",sizeof(str1),sizeof(str2),sizeof("abcd"));
* > printf("%d %d %d",strlen(str1),strlen(str2),strlen("abcd"));
* > }
* 
* sizeof is an operator and strlen is a C library function.
* sizeof gives the size in bytes of its operand. size is determined
* by the type of operand.
* "abcd" is a string literal and its size is 5.
* So, sizeof("abcd") = 5.
* strlen("abcd") = 4. It does not include the terminating null character.
* 
* sizeof(str1) --> The operand str1 is a pointer to char. So, its type
* is char pointer and size will be the size of char
* pointer.
* sizeof(str2) --> str2 is an array of characters. Standard C says
* that "sizeof operator When applied to an operand
* that has array type, the result is the total number
* of bytes in the array. So, sizeof(str2) = 5.
* 
* sizeof("abcd") = 5.
* 
* strlen(str1) = 4.
* strlen(str2) = 4.
* strlen("abcd") = 4.
*/
