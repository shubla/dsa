#include <stdio.h>

#define cap 5

int stack[cap]; // Declare an array to represent the stack
int top = -1; // Initialize the top of the stack to -1 (empty)

// Function to check if the stack is empty
int is_empty() {
    return top == -1;
}

// Function to check if the stack is full
int is_full() {
    return top == cap - 1;
}

// Function to push an element onto the stack
void push(int item) {
    if (is_full()) {
        printf("Stack overflow. Cannot push item.\n");
    } else {
        stack[++top] = item; // Increment top and add the item to the stack
        printf("Pushed %d onto the stack.\n", item);
    }
}

// Function to pop an element from the stack
void pop() {
    if (is_empty()) {
        printf("Stack underflow. Cannot pop from an empty stack.\n");
    } else {
        printf("Popped %d from the stack.\n", stack[top]); // Print the popped item
        top--; // Decrement top to remove the item from the stack
    }
}
void Peek()
{
    if(top==-1)
    {
        printf("\nStack Is  Empty !\n");
        return;
    }
    else
    {
        printf("The Top Element In The Stack Is:%d \n",stack[top]);
    }
}
// Function to display the stack in a stack-like format
void display_stack() {
    if(top==-1)
    {
        printf("\nStack Is Empty !\n");
    }
    printf("Stack (top to bottom): \n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
        printf("---\n");
    }
    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("Stack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display Stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int value;
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            }
            case 2:
                pop();
                break;
            case 3:
                Peek();
                break;

            case 4:
            display_stack();
                break;
                
            case 5:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
