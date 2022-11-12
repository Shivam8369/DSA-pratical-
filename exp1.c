/***********************************
 Implementation of Stack Using Array 
***********************************/

#include <stdio.h>
int STK[100], TOP = -1, i, n, x, choice;
void Push();
void Pop();
void Peep();
void change();
void Display();
void main()
{
    printf("\t WELCOME to Implementation of STACK using array !! \n");
    printf("Enter the size of Stack (Maximum size = 100): ");
    scanf("%d", &n);
    do
    {
        printf("\n Stack Operation available: \n");
        printf("\t1.Push\t 2.Pop\t 3.Peep\t 4.Display\t 5.Exit \n");
        printf("\n Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            Push();
            break;
        case 2:
            Pop();
            break;
        case 3:
            Peep();
            break;
        case 4:
            Display();
            break;
        case 5:
            printf("Exit: Program Finished !! ");
            break;
        default:
            printf("Please enter a valid choide: 1, 2, 3, 4, 5 \n");
        }
    } while (choice != 5);
}

// Function to perform PUSH Operation
void Push()
{
    if (TOP >= n - 1)
    {
        printf(" Stack Overflow \n");
    }
    else
    {
        printf(" Enter the element to be pushed: ");
        scanf("%d", &x);
        TOP++;
        STK[TOP] = x;
    }
}

// Function to perform POP Operation
void Pop()
{
    if (TOP < 0)
    {
        printf(" Stack Underflow \n");
    }
    else
    {
        printf(" The popped element is: %d \n", STK[TOP]);
        TOP--;
    }
}

// Function to perform PEEP Opeartion
void Peep()
{
    printf(" Enter the position of the element from the top which you want to peep: ");
    scanf("%d", &i);
    if (TOP - i + 1 < 0)
    {
        printf(" Stack Underflow on Peep \n");
    }
    else
    {
        printf(" The %d element from the top is: %d \n", i, STK[TOP - i + 1]);
    }
}

// Function to DISPLAY the Stack
void Display()
{
    if (TOP < 0)
    {
        printf(" Stack is empty \n");
    }
    else
    {
        printf(" The element in the stack are:");
        for (i = TOP; i > -1; i--)
        {
            printf("\n %d \n", STK[i]);
        }
    }
}ś