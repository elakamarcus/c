/* Address book

todo:
- finish remove function
- function to enumerate no. contacts
or use control var

*/

#include <stdio.h>
#include <string.h>

#define MAXCONTACTS 5

struct contact {
    char firstname[50];
    char lastname[50];
    char phone[15];
    char email[20];
    int priority;
};


void menu();
struct contact createContact( void );
void removeContact( struct contact *ctptr);
int getNumContacts( struct contact *contacts[MAXCONTACTS]);
void printcontact( struct contact *b );

int main() {

    struct contact contacts[MAXCONTACTS] = {0};
    int i,count;
    count = 0;
    do {
        menu();
        printf("\nInput your selection: ");
        scanf("%d", &i);
        if(i==1){
                /* should first find.
                1. if contacts are full.
                2. which is next available.
                3. consider send the whole array.
                 */
           contacts[count] = createContact();
           count += 1;
        }
        else if(i==2){
            printcontact(&contacts[count]);
        }
        else if(i==3){
            printf("Which contact to remove?\n");
            listContacts(&contacts);

        }

    }while(i!=4);
    if(i==4){
        printf("End program. Press any key.");
    }
    return;
}

void menu(){

    printf("1. Add a contact\n");
    printf("2. List contacts\n");
    printf("3. Remove a contact\n");
    printf("4. Quit\n");

}

struct contact createContact( void ) {
    struct contact ctptr;
    /* first find the first empty contact, or quit if the array is full */
    int max = 0;
    getchar( );
    printf("Enter the first name: ");
    fgets(ctptr.firstname, 50, stdin);
    ctptr.firstname[strlen(ctptr.firstname) - 1] = '\0';
    printf("Enter last name: ");
    fgets(ctptr.lastname, 50, stdin);
    ctptr.lastname[strlen(ctptr.lastname) - 1] = '\0';
    printf("Enter phone number: ");
    fgets(ctptr.phone, 15, stdin);
    ctptr.phone[strlen(ctptr.phone) - 1] = '\0';
    printf("Enter email address: ");
    fgets(ctptr.email, 20, stdin);
    ctptr.email[strlen(ctptr.email) - 1] = '\0';
    printf("Enter priority (1-100): ");
    scanf("%d", &ctptr.priority);

    return ctptr;
}

void printcontact ( struct contact *b ){
    printf("Contact: %s, %s\n", b->lastname, b->firstname );
    printf("\tPhone: %s\n", b->phone); // pointer operator
    printf("\tEmail: %s\n", b->email);
    printf("\tPrio: %d\n", b->priority);

}

void removeContact( struct contact *ctptr){
    printf("Not yet implemented.\n");

}

int getNumContacts( struct contact *contacts[MAXCONTACTS]) {
    int max = MAXCONTACTS;
    int b=0; // the 'length of array'

    return b;
}
