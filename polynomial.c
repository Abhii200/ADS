#include <stdio.h>
#include <stdlib.h>

// Node structure for polynomial terms
typedef struct Node {
    int coeff;
    int exp;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int coeff, int exp) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node in sorted order
Node* insertNode(Node* head, int coeff, int exp) {
    Node* newNode = createNode(coeff, exp);
    if (!head || head->exp < exp) {
        newNode->next = head;
        return newNode;
    }
    Node* temp = head;
    while (temp->next && temp->next->exp > exp) {
        temp = temp->next;
    }
    if (temp->exp == exp) {
        temp->coeff += coeff; // Combine like terms
        free(newNode);
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head;
}

// Function to add two polynomials
Node* addPolynomials(Node* poly1, Node* poly2) {
    Node* result = NULL;
    while (poly1 || poly2) {
        if (!poly2 || (poly1 && poly1->exp > poly2->exp)) {
            result = insertNode(result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        } else if (!poly1 || (poly2 && poly2->exp > poly1->exp)) {
            result = insertNode(result, poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        } else {
            result = insertNode(result, poly1->coeff + poly2->coeff, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    return result;
}

// Function to subtract two polynomials
Node* subtractPolynomials(Node* poly1, Node* poly2) {
    Node* result = NULL;
    while (poly1 || poly2) {
        if (!poly2 || (poly1 && poly1->exp > poly2->exp)) {
            result = insertNode(result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        } else if (!poly1 || (poly2 && poly2->exp > poly1->exp)) {
            result = insertNode(result, -poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        } else {
            result = insertNode(result, poly1->coeff - poly2->coeff, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    return result;
}

// Function to multiply two polynomials
Node* multiplyPolynomials(Node* poly1, Node* poly2) {
    Node* result = NULL;
    for (Node* p1 = poly1; p1; p1 = p1->next) {
        for (Node* p2 = poly2; p2; p2 = p2->next) {
            result = insertNode(result, p1->coeff * p2->coeff, p1->exp + p2->exp);
        }
    }
    return result;
}

// Function to display a polynomial
void displayPolynomial(Node* poly) {
    if (!poly) {
        printf("0\n");
        return;
    }
    while (poly) {
        printf("%dX^%d", poly->coeff, poly->exp);
        poly = poly->next;
        if (poly)
            printf(" + ");
    }
    printf("\n");
}

// Main function
int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;

    // First polynomial: 3X^3 + 2X^2 + 1
    poly1 = insertNode(poly1, 3, 3);
    poly1 = insertNode(poly1, 2, 2);
    poly1 = insertNode(poly1, 1, 0);

    // Second polynomial: 4X^2 + 3X + 2
    poly2 = insertNode(poly2, 4, 2);
    poly2 = insertNode(poly2, 3, 1);
    poly2 = insertNode(poly2, 2, 0);

    printf("First Polynomial: ");
    displayPolynomial(poly1);

    printf("Second Polynomial: ");
    displayPolynomial(poly2);

    Node* sum = addPolynomials(poly1, poly2);
    printf("Sum: ");
    displayPolynomial(sum);

    Node* diff = subtractPolynomials(poly1, poly2);
    printf("Difference: ");
    displayPolynomial(diff);

    Node* prod = multiplyPolynomials(poly1, poly2);
    printf("Product: ");
    displayPolynomial(prod);

    return 0;
}