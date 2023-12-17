#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct Stack {
    struct TreeNode* items[100];
    int top;
};

void initializeStack(struct Stack* stack) {
    stack->top = -1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

int isFull(struct Stack* stack) {
    return stack->top == 99;
}

void push(struct Stack* stack, struct TreeNode* node) {
    if (isFull(stack)) {
        printf("Stack overflow! Cannot push node onto the stack.\n");
        return;
    }
    stack->items[++stack->top] = node;
}

struct TreeNode* pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow! Cannot pop from an empty stack.\n");
        return NULL;
    }
    return stack->items[stack->top--];
}

void inorderTraversal(struct TreeNode* root) {
    struct Stack stack;
    initializeStack(&stack);
    struct TreeNode* current = root;

    while (current != NULL || !isEmpty(&stack)) {
        while (current != NULL) {
            push(&stack, current);
            current = current->left;
        }
        current = pop(&stack);
        printf("%d ", current->data);
        current = current->right;
    }
}

void preorderTraversal(struct TreeNode* root) {
    struct Stack stack;
    initializeStack(&stack);
    push(&stack, root);

    while (!isEmpty(&stack)) {
        struct TreeNode* current = pop(&stack);
        printf("%d ", current->data);

        if (current->right != NULL) {
            push(&stack, current->right);
        }
        if (current->left != NULL) {
            push(&stack, current->left);
        }
    }
}

void postorderTraversal(struct TreeNode* root) {
    struct Stack stack1, stack2;
    initializeStack(&stack1);
    initializeStack(&stack2);
    push(&stack1, root);

    while (!isEmpty(&stack1)) {
        struct TreeNode* current = pop(&stack1);
        push(&stack2, current);

        if (current->left != NULL) {
            push(&stack1, current->left);
        }
        if (current->right != NULL) {
            push(&stack1, current->right);
        }
    }

    while (!isEmpty(&stack2)) {
        printf("%d ", pop(&stack2)->data);
    }
}

struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct TreeNode* insertNode(struct TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    return root;
}

void buildTree(struct TreeNode** root) {
    int n, data;
    printf("Enter the number of nodes in the BST: ");
    scanf("%d", &n);

    printf("Enter the values of the nodes:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &data);
        *root = insertNode(*root, data);
    }
}

void displayMenu() {
    printf("\nBinary Search Tree Traversal Menu:\n");
    printf("1. Inorder Traversal\n");
    printf("2. Preorder Traversal\n");
    printf("3. Postorder Traversal\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    struct TreeNode* root = NULL;

    buildTree(&root);

    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 2:
                printf("Preorder Traversal: ");
                preorderTraversal(root);
                printf("\n");
                break;
            case 3:
                printf("Postorder Traversal: ");
                postorderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}
