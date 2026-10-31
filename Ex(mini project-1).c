#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Passenger
{
    int ticketNo;
    char name[50];
    int age;
    char source[30];
    char destination[30];
    struct Passenger *next;
};

struct Passenger *head = NULL;

int ticketCounter = 100;
int totalSeats = 50;

void bookTicket()
{
    struct Passenger *newNode;

    if (totalSeats == 0)
    {
        printf("\nNo seats available!\n");
        return;
    }

    newNode = (struct Passenger *)
              malloc(sizeof(struct Passenger));

    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->ticketNo = ticketCounter++;

    printf("\nEnter Passenger Name: ");
    scanf(" %[^\n]", newNode->name);

    printf("Enter Age: ");
    scanf("%d", &newNode->age);

    printf("Enter Source: ");
    scanf("%s", newNode->source);

    printf("Enter Destination: ");
    scanf("%s", newNode->destination);

    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Passenger *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    totalSeats--;

    printf("\nTicket Booked Successfully!\n");
    printf("Ticket Number: %d\n", newNode->ticketNo);
}

void displayTickets()
{
    struct Passenger *temp = head;

    if (temp == NULL)
    {
        printf("\nNo Tickets Booked!\n");
        return;
    }

    printf("\n--- Passenger Details ---\n");

    while (temp != NULL)
    {
        printf("\nTicket No: %d", temp->ticketNo);
        printf("\nName: %s", temp->name);
        printf("\nAge: %d", temp->age);
        printf("\nSource: %s", temp->source);
        printf("\nDestination: %s\n",
               temp->destination);

        temp = temp->next;
    }
}

void cancelTicket()
{
    int number;
    struct Passenger *temp = head;
    struct Passenger *prev = NULL;

    printf("\nEnter Ticket Number to Cancel: ");
    scanf("%d", &number);

    while (temp != NULL &&
           temp->ticketNo != number)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("\nTicket Not Found!\n");
        return;
    }

    if (prev == NULL)
    {
        head = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }

    free(temp);
    totalSeats++;

    printf("\nTicket Cancelled Successfully!\n");
}

void searchPassenger()
{
    int number;
    struct Passenger *temp = head;

    printf("\nEnter Ticket Number: ");
    scanf("%d", &number);

    while (temp != NULL)
    {
        if (temp->ticketNo == number)
        {
            printf("\nPassenger Found!\n");
            printf("Name: %s\n", temp->name);
            printf("Age: %d\n", temp->age);
            printf("Source: %s\n", temp->source);
            printf("Destination: %s\n",
                   temp->destination);
            return;
        }

        temp = temp->next;
    }

    printf("\nPassenger Not Found!\n");
}

void availableSeats()
{
    printf("\nTotal Seats: 50\n");
    printf("Booked Seats: %d\n",
           50 - totalSeats);
    printf("Available Seats: %d\n",
           totalSeats);
}

int main()
{
    int choice;

    do
    {
        printf("\n===== RAILWAY RESERVATION SYSTEM =====\n");
        printf("1. Book Ticket\n");
        printf("2. Display Tickets\n");
        printf("3. Cancel Ticket\n");
        printf("4. Search Passenger\n");
        printf("5. Available Seats\n");
        printf("6. Exit\n");

        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                bookTicket();
                break;

            case 2:
                displayTickets();
                break;

            case 3:
                cancelTicket();
                break;

            case 4:
                searchPassenger();
                break;

            case 5:
                availableSeats();
                break;

            case 6:
                printf("\nThank You!\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
        }

    } while (choice != 6);

    return 0;
}
