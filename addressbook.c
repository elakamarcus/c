/* Address book

todo:
- finish remove function
- function to enumerate no. contacts
or use control var

*/

#include <stdio.h>
#include <string.h>

#define MAXCONTACTS 5

typedef struct contact {
    char firstname[50];
    char lastname[50];
    char phone[15];
    char email[20];
} contact;

contact contacts[MAXCONTACTS];

void menu(){
    printf("Make your selection:\n");
    printf("1. Create contacts\n");
    printf("2. List contacts\n");
    printf("3. Quit\n");

}

void printAllContact(contact* allcont, int n){
    for(int i=0; i< n; i++){
        printf("Contact: %d\n", i+1);
        printf("\t%s, %s\n", allcont[i].lastname, allcont[i].firstname);
        printf("\t%s\n", allcont[i].email);
        printf("\t%s\n", allcont[i].phone);
    }
    printf("Size of allcont = %d\n", sizeof(allcont));
}

struct contact createContact( ) {
    struct contact ctptr;
    /* first find the first empty contact, or quit if the array is full */
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
    getchar( ); /* remove \n from input buffer */

    printf("Size of ctptr: %d\n", sizeof(ctptr));
    return ctptr;
}

int main(){
    printf("Size of struct contact: %d\n", sizeof(struct contact));
    int selection;
    do {
        menu();
        scanf("%d", &selection);
        getchar();
        if(selection == 1){
            for(int i=0; i<MAXCONTACTS; i++){
            contacts[i] = createContact();
            printf("Size of contacts: %d\n", sizeof(contacts));
            }
        }
        else if(selection == 2){
            printAllContact(contacts, MAXCONTACTS);
        }
    }while(selection <=2 && selection >=1);
    if(selection==3){
        printf("It's over.\n");
    }
}
