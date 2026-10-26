#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct Node {
    char ch;
    long long count;       // 此節點的字元數
    long long size;        // 整棵子樹的字元數
    uint64_t priority;

    struct Node *left;
    struct Node *right;
} Node;

/* 產生偽隨機優先值 */
uint64_t randomPriority(void)
{
    static uint64_t state = UINT64_C(88172645463325252);

    state ^= state << 13;
    state ^= state >> 7;
    state ^= state << 17;

    return state;
}

long long getSize(Node *node)
{
    return node == NULL ? 0 : node->size;
}

/* 孩子或 count 改變後，更新 size */
void pull(Node *node)
{
    if (node == NULL)
        return;

    node->size = getSize(node->left)
               + node->count
               + getSize(node->right);
}

Node *makeNode(char ch, long long count, uint64_t priority)
{
    Node *node = malloc(sizeof(*node));

    if (node == NULL)
        exit(EXIT_FAILURE);

    node->ch = ch;
    node->count = count;
    node->size = count;
    node->priority = priority;
    node->left = NULL;
    node->right = NULL;

    return node;
}

/* 把 A 的文字放前面，B 的文字放後面 */
Node *merge(Node *A, Node *B)
{
    if (A == NULL)
        return B;

    if (B == NULL)
        return A;

    if (A->priority > B->priority) {
        A->right = merge(A->right, B);
        pull(A);
        return A;
    } else {
        B->left = merge(A, B->left);
        pull(B);
        return B;
    }
}

/*
 * A：前 p 個字元
 * B：其餘字元
 */
void split(Node *root, long long p, Node **A, Node **B)
{
    if (root == NULL) {
        *A = NULL;
        *B = NULL;
        return;
    }

    long long L = getSize(root->left);
    long long C = root->count;

    if (p < L) {
        /* 切割位置在左子樹 */
        Node *leftA;
        Node *leftB;

        split(root->left, p, &leftA, &leftB);

        root->left = leftB;
        pull(root);

        *A = leftA;
        *B = root;
    } else if (p > L + C) {
        /* 切割位置在右子樹 */
        Node *rightA;
        Node *rightB;

        split(root->right, p - L - C, &rightA, &rightB);

        root->right = rightA;
        pull(root);

        *A = root;
        *B = rightB;
    } else if (p == L) {
        /* 剛好切在目前節點前面 */
        *A = root->left;
        root->left = NULL;

        pull(root);
        *B = root;
    } else if (p == L + C) {
        /* 剛好切在目前節點後面 */
        *B = root->right;
        root->right = NULL;

        pull(root);
        *A = root;
    } else {
        /* 切在目前節點的字元區段內 */
        long long leftCount = p - L;
        long long rightCount = C - leftCount;

        /*
         * 右半段沿用原節點的優先值，
         * 並接收原本的右子樹。
         */
        Node *rightPart = makeNode(
            root->ch,
            rightCount,
            root->priority
        );

        rightPart->right = root->right;

        /*
         * 原節點作為左半段，
         * 保留原本的左子樹。
         */
        root->count = leftCount;
        root->right = NULL;

        pull(root);
        pull(rightPart);

        *A = root;
        *B = rightPart;
    }
}

/* 在前 p 個字元後面，插入 count 個 ch */
Node *insert(Node *root, long long p, char ch, long long count)
{
    Node *A;
    Node *B;

    split(root, p, &A, &B);

    Node *middle = makeNode(ch, count, randomPriority());

    Node *temp = merge(A, middle);
    return merge(temp, B);
}

/* 印出時，用來累積相鄰的同字元區段 */
typedef struct {
    int hasPending;
    char ch;
    long long count;
} PrintState;

void inorderPrint(Node *root, PrintState *state)
{
    if (root == NULL)
        return;

    inorderPrint(root->left, state);

    if (!state->hasPending) {
        state->hasPending = 1;
        state->ch = root->ch;
        state->count = root->count;
    } else if (state->ch == root->ch) {
        state->count += root->count;
    } else {
        printf("%c %lld ", state->ch, state->count);

        state->ch = root->ch;
        state->count = root->count;
    }

    inorderPrint(root->right, state);
}

void printWord(Node *root)
{
    PrintState state = {0, '\0', 0};

    inorderPrint(root, &state);

    if (state.hasPending)
        printf("%c %lld ", state.ch, state.count);

    puts("$");
}

void freeTree(Node *root)
{
    if (root == NULL)
        return;

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main(void)
{
    Node *root = NULL;
    char command[16];

    while (scanf("%15s", command) == 1) {
        if (strcmp(command, "print") == 0) {
            printWord(root);
        } else if (strcmp(command, "insert") == 0) {
            char position[32];
            char ch;
            long long count;
            long long p;

            scanf("%31s %c %lld", position, &ch, &count);

            if (strcmp(position, "left") == 0) {
                p = 0;
            } else if (strcmp(position, "right") == 0) {
                p = getSize(root);
            } else {
                long long k = strtoll(position, NULL, 10);
                p = k - 1;
            }

            root = insert(root, p, ch, count);
        }
    }

    freeTree(root);
    return 0;
}