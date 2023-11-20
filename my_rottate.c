#include <stdio.h>

unsigned int my_rottate(unsigned int,int);
void print_bin(unsigned int,int);
int size_int(void);

int main()
{
    unsigned int inNum; /*the number that we will get from the input*/
    int spaceChange,sizeOfInt; /*number of moves we will do to the binary number and the size of the sibit in int on every system*/

    printf("please enter a positive number\n"); /*input the number,we are working on unsinged int so i dont think negative numbers mean anything yet the code works with them*/
    scanf("%u",&inNum);
    printf("please enter how many binary spaces u want your number to move(positive number is to the right and negative to the left)\n"); /*how much to move the binary number*/
    scanf("%d",&spaceChange);
    sizeOfInt=size_int(); /*checking the size of the sibit in int */
    printf("your number in decimal\n%u\n",inNum); /*starts of the output of the number that was enter in diffrent bases*/
    printf("your number in binary\n");
    print_bin(inNum,sizeOfInt);/*call to print the number in binary*/
    printf("\nyour number in octal\n%o\n",inNum);
    printf("your number in hexadecimal\n%x\n",inNum); /*end of output for the entered number*/
    inNum=my_rottate(inNum,spaceChange); /*calling for the question metod that will move the binary number*/
    printf("your new number in decimal\n%u\n",inNum);/*starts of the output of the changed number*/
    printf("your new number in binary\n");
    print_bin(inNum,sizeOfInt);/*call to print the number in binary*/
    printf("\nyour new number in octal\n%o\n",inNum);
    printf("your new number in hexadecimal\n%x\n",inNum);/*end of output of the changed number*/

    return 0;
}

unsigned int my_rottate(unsigned int a,int b)
{
    int lastByte=1,sizeOfInt=size_int();

    lastByte<<=sizeOfInt-1;/*will use lastByte for the matipulation of the most left sibit*/
    if(b>0)/*rotate the binary number to right*/
    {
        for(;b!=0;b--)/*how many sibit we need to move*/
        {
            if(a%2==1)/*if the most right sibit is one we save it to put in the most left one else its zero so the >> will add one by diffult */
            {
                a>>=1;
                a=a|lastByte;
            }
            else a>>=1;
        }
    }
    if(b<0)/*rotate the binary number to left*/
    {
        for(;b!=0;b++)
        {
            if(a&lastByte)/*if the most left sibit is one we will move the binary one time to left and add one else we dont need to add cause it was zero */
            {
                a<<=1;
                a+=1;
            }
            else a<<=1;
        }
    }
    return a;/*for if the user enter b=0, thus not changing the number or after one of the if statmets finnished*/
}

void print_bin(unsigned int num,int size)/*printing the binarry number*/
{
     unsigned int i;
	
    for (i=1<<(size-1); i>0; i = i / 2)
        (num & i) ? printf("1") : printf("0");/*if its not zero we know to print one and it goes from left to right*/
}

int size_int(void)/*checking the int size, copy paste from the book*/
{
    int count,mask = -1;

    for (count=0; mask; mask <<= 1,count++)
    ;
    return count;
}
