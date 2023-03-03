// int c=0;
void tower(int n, char beg, char mid, char end)
{
    // printf("%d.",++c);
    if(n==1)
    {
        printf("Move Disk 1 from Peg %c to Peg %c\n",beg,end);
        return;
    }
    
    tower(n-1,beg,end,mid);
    printf("Move disk %d from Peg %c to Peg %c\n",n,beg,end);
    tower(n-1,mid,beg,end);
}


int main()
{
    int n;
    printf("\n Enter number of disks in A:");
    scanf("%d",&n);
    
    printf("Follow these steps to Achieve the target position\n");
    tower(n,'A','B','C');

    return 0;
}