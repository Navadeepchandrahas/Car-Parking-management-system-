#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
   STRUCTURE: Slot
   Represents one parking slot in a linked list
*/
typedef struct Slot {
    int slotNumber;          // Slot ID
    char car[20];            // Car number (string)
    struct Slot* next;       // Pointer to next slot
} Slot;

/*
   STRUCTURE: Action
   Represents an operation for undo (stack)
*/
typedef struct Action {
    char type[10];           // "park" or "remove"
    int slotNumber;          // Slot affected
    char car[20];            // Car involved
    struct Action* next;     // Pointer to next action (stack)
} Action;

Slot* head = NULL;       // Head of parking slots list
Action* history = NULL;  // Top of undo stack

/* ---------------- STACK OPERATIONS ---------------- */

/*
   FUNCTION: push
   Stores an action in the undo stack
*/
void push(char* type, char* car, int slotNumber) {
    Action* newAction = (Action*)malloc(sizeof(Action));

    strcpy(newAction->type, type);       // Store action type
    strcpy(newAction->car, car);         // Store car number
    newAction->slotNumber = slotNumber;  // Store slot number

    newAction->next = history;           // Link to previous action
    history = newAction;                 // Update top of stack
}

/*
   FUNCTION: pop
   Removes last action from stack
*/
Action* pop() {
    if (history == NULL) return NULL;    // No actions to undo

    Action* temp = history;
    history = history->next;             // Move stack pointer

    return temp;                         // Return popped action
}

/* ---------------- SLOT MANAGEMENT ---------------- */

/*
   FUNCTION: createSlots
   Creates 'n' parking slots as a linked list
*/
void createSlots(int n) {
    Slot* temp = NULL;

    // Create slots in reverse order
    for (int i = n; i >= 1; i--) {
        Slot* newSlot = (Slot*)malloc(sizeof(Slot));

        newSlot->slotNumber = i;   // Assign slot number
        strcpy(newSlot->car, "");  // Empty slot
        newSlot->next = temp;      // Link to next

        temp = newSlot;
    }

    head = temp; // Set head of list
}

/*
   FUNCTION: park
   Parks a car in the first available slot
*/
void park(char* car) {
    Slot* temp = head;

    while (temp != NULL) {
        // Check if slot is empty
        if (strlen(temp->car) == 0) {
            strcpy(temp->car, car);  // Assign car to slot

            // Save action for undo
            push("park", car, temp->slotNumber);

            printf("Car %s parked at slot %d\n", car, temp->slotNumber);
            return;
        }
        temp = temp->next;
    }

    printf("Parking Full\n");
}

/*
   FUNCTION: removeCar
   Removes a car from parking
*/
void removeCar(char* car) {
    Slot* temp = head;

    while (temp != NULL) {
        // Check if car matches
        if (strcmp(temp->car, car) == 0) {
            // Save action before removing
            push("remove", car, temp->slotNumber);

            strcpy(temp->car, ""); // Make slot empty

            printf("Car %s removed from slot %d\n", car, temp->slotNumber);
            return;
        }
        temp = temp->next;
    }

    printf("Car not found\n");
}

/*
   FUNCTION: view
   Displays all parked cars
*/
void view() {
    Slot* temp = head;

    while (temp != NULL) {
        if (strlen(temp->car) > 0) {
            printf("Slot %d: %s\n", temp->slotNumber, temp->car);
        }
        temp = temp->next;
    }
}

/*
   FUNCTION: search
   Finds a car's slot
*/
void search(char* car) {
    Slot* temp = head;

    while (temp != NULL) {
        if (strcmp(temp->car, car) == 0) {
            printf("Car %s found at slot %d\n", car, temp->slotNumber);
            return;
        }
        temp = temp->next;
    }

    printf("Car not found\n");
}

/*
   FUNCTION: undo
   Reverses last action
*/
void undo() {
    Action* last = pop();

    if (last == NULL) {
        printf("Nothing to undo\n");
        return;
    }

    Slot* temp = head;

    while (temp != NULL) {
        if (temp->slotNumber == last->slotNumber) {

            // If last action was park → undo by removing car
            if (strcmp(last->type, "park") == 0) {
                strcpy(temp->car, "");
            }

            // If last action was remove → undo by restoring car
            else if (strcmp(last->type, "remove") == 0) {
                strcpy(temp->car, last->car);
            }

            printf("Undo successful\n");

            free(last); // Free memory
            return;
        }
        temp = temp->next;
    }
}

/* ---------------- MAIN FUNCTION ---------------- */

int main() {
    int n, choice;
    char car[20];

    // Get number of slots
    printf("Enter number of slots: ");
    scanf("%d", &n);

    createSlots(n); // Initialize parking

    while (1) {
        // Menu
        printf("\n1. Park\n2. Remove\n3. View\n4. Search\n5. Undo\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter car number: ");
                scanf("%s", car);
                park(car);
                break;

            case 2:
                printf("Enter car number: ");
                scanf("%s", car);
                removeCar(car);
                break;

            case 3:
                view();
                break;

            case 4:
                printf("Enter car number: ");
                scanf("%s", car);
                search(car);
                break;

            case 5:
                undo();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}