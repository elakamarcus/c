/* Contact list */

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
void createContact( struct contact *ctptr);
void removeContact( struct contact *ctptr);
int getNumContacts( struct contact *contacts[MAXCONTACTS]);

int main() {

    struct contact contacts[MAXCONTACTS] = {0};
    int i;
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
            createContact(&contacts[0]);
        }
        else if(i==2){
            listContacts(&contacts);
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

void createContact( struct contact *ctptr) {
    /* first find the first empty contact, or quit if the array is full */
    int max = getNumContacts(ctptr);
    if(max == MAXCONTACTS){
        printf("Contact list full.\n");
        return -1;
    }
    getchar( );
    printf("Enter the first name:");
    fgets(ctptr[max].firstname, 50, stdin);
    ctptr[max].firstname[strlen(ctptr[max].firstname) - 1] = '\0';
    printf("Enter last name:");
    fgets(ctptr[max].lastname, 50, stdin);
    ctptr[max].lastname[strlen(ctptr[max].lastname) - 1] = '\0';
    printf("Enter phone number:");
    fgets(ctptr[max].phone, 15, stdin);
    ctptr[max].phone[strlen(ctptr[max].phone) - 1] = '\0';
    printf("Enter email address:");
    fgets(ctptr[max].email, 20, stdin);
    ctptr[max].email[strlen(ctptr[max].email) - 1] = '\0';
    printf("Enter priority (1-100):");
    scanf("%d", &ctptr[max].priority);
}

void listContacts( struct contact *ctsptr[MAXCONTACTS]){
/*    printf("Not yet implemented.\n");
    int max = getNumContacts(ctsptr);
    for(int i=0;i<=max;i++){
        printf("Contact: %d\n", i+1);
        printf("\t%s\n", (*ctsptr[i]).firstname);
        printf("\t%s\n", (*ctsptr[i]).lastname);
        printf("\t%s\n", (*ctsptr[i]).phone);
        printf("\t%s\n", (*ctsptr[i]).email);
        printf("\t%d\n", (*ctsptr[i]).priority);
    }
*/
    int i = 0;
    printf("Contact: %d\n", i+1);
    printf("\t%s\n", (*ctsptr[i]).firstname);
    printf("\t%s\n", (*ctsptr[i]).lastname);
    printf("\t%s\n", (*ctsptr[i]).phone);
    printf("\t%s\n", (*ctsptr[i]).email);
    printf("\t%d\n", (*ctsptr[i]).priority);

}

void removeContact( struct contact *ctptr){
    printf("Not yet implemented.\n");

}

int getNumContacts( struct contact *contacts[MAXCONTACTS]) {
    int max = MAXCONTACTS;
    int b=0; // the 'length of array'


    return b;
}
