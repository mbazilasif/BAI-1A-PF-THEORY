//Author: Bazil Asif

#include <stdio.h>
#include <string.h>
void DisplayMenu () {
    printf("Please choose from the menu below \n");
    printf("1. Member Registration \n");
    printf("2. Display Availaible books \n");
    printf("3. Borrow a book\n");
    printf("4. Return a book \n");
    printf("5. Display Member Record\n");
    printf("6. Exit\n");
}

void DisplayBooks (int BookIDs[], char BookTitles[][50], int AvailaibleCopies[], int TotalBooks){
    printf("%-10s %-25s %-10s\n","Book ID", "Book Title", "Available Copies");
    for (int i=0;i<TotalBooks;i++){
        printf("%-10d %-25s %-10d\n",BookIDs[i],BookTitles[i],AvailaibleCopies[i]);
    }

}

void RegisterMember (char name[], int *StudentID, int *membertype){
    printf("Enter your name: ");
    scanf("%s",name);
    printf("Enter your StudentID: ");
    scanf("%d",StudentID);
    printf("Enter member type - 1 for Student 2 for Faculty: ");
    scanf("%d",membertype);
    while (*membertype != 1 && *membertype !=2){
        printf("Invalid. Memeber type can only be 1 or 2: ");
        scanf("%d",membertype);
    }

}

void BorrowBook(int BookIDs[], char BookTitles[][50], int AvailableCopies[],  int TotalBooks, int BorrowedBookIDs[], int *BorrowedCount, int memberType){
    DisplayBooks(BookIDs,BookTitles,AvailableCopies,TotalBooks);
    int ID;
    int found = 0;
    int index = 0;
    if (*BorrowedCount >= 3){
        printf("Limit has been reached - You cannot borrow more books \n");
        return;
    }
    else {
        printf("Enter the BookID: ");
        scanf("%d",&ID);
    }
    for (int i=0;i<TotalBooks;i++){
        if (ID == BookIDs[i]){
            found = 1;
            index = i;
            break;
        }
    }

    if (found == 0){
        printf("Invalid BookID. Not found \n");
    }

    if (found == 1){
        if (AvailableCopies[index] == 0){
            printf("No copies are currently availaible! \n");
        }
        else {
            AvailableCopies[index] = AvailableCopies[index] - 1;
            BorrowedBookIDs[*BorrowedCount] = BookIDs[index];
            (*BorrowedCount) ++;
            
        }
    }
}

float ReturnBook(int BookIDs[], int AvailableCopies[], int TotalBooks, int  BorrowedBookIDs[], int *BorrowedCount, int MemberType, float *totalFine){
    int ID;
    int days;
    int extradays = 0;
    char code [20];
    float NewFine = 0;
    int found = 0;
    int index = 0;
    int BookIndex = 0;

    if (*BorrowedCount == 0) {
    printf("You have no books to return.\n");
    return 0.0f;
    }

    printf("Enter book id: ");
    scanf("%d",&ID);
    for (int i=0;i<*BorrowedCount;i++){
        if (ID == BorrowedBookIDs[i]){
            found = 1;
            index = i;
            break;
        }
    }

   if (found == 0){
    printf("Invalid Return \n");
    return 0.00;
   }

   for (int i = 0; i < TotalBooks; i++){
    if (ID == BookIDs[i]){
        BookIndex = i;
        break;
    }
   }

   printf("Number of days book was kept: ");
   scanf("%d", &days);

    
    if (MemberType == 1){
        if (days >14){
            extradays = days - 14;
            NewFine = extradays * 20;
        }
    }
    else if (MemberType == 2){
        if (days > 30){
            extradays = days - 30;
            NewFine = extradays * 10;
        }
    }
        
    *totalFine = *totalFine + NewFine;
    
    if (NewFine > 0){
        printf("Enter membership code: ");
        scanf("%s",code);
        if (strcmp(code, "LIB2026") == 0) {
            NewFine = NewFine * 0.5;
        }
    }
    
    AvailableCopies[BookIndex]++;
    for (int i= index;i<*BorrowedCount-1;i++){
        BorrowedBookIDs[i] = BorrowedBookIDs[i + 1];
    }
    (*BorrowedCount) -- ;
    printf("You have to pay %.2f fine \n",NewFine);    
    return NewFine;
}

void DisplayMemberRecord(char name[], int StudentID, int MemberType, int  BorrowedBookIDs[], int BorrowedCount, float TotalFine, float FineAfterWaiver){
    printf("\n--- Member Record ---\n");
    printf("Name: %s \n",name);
    printf("StudentID: %d \n",StudentID);
    if (MemberType == 1){
        printf("Member Type: Student \n");
    }
    else {
        printf("Member Type: Faculty \n");
    }
    printf("Number of borrowed books: %d \n",BorrowedCount);
    for (int i=0;i<BorrowedCount;i++){
        printf("Borrowed Book ID: %d \n",BorrowedBookIDs[i]);
    }
    printf("Fine before waivers: %.2f \n",TotalFine);
    printf("Payable Fine after waivers: %.2f \n",FineAfterWaiver);
    }


int main () {
    int BookIDs[] = {101,102,103,104};
    char BookTitles[100][50] = {"C Programming","Database Systems","Computer Networks","Operating Systems"};
    int AvailableCopies[] = {5,3,0,4};
    char Name[100];
    int StudentId = 0, MemberType = 0, BorrowedCount = 0, choice = 0, TotalBooks = 4;
    int BorrowedBooksID[100];
    float TotalFine = 0, FineAfterWaiver = 0;
    
    do{
        DisplayMenu();
        printf("Enter your choice: ");
        scanf("%d",&choice);
        while (choice <1 || choice >6){
            printf("Choice must be between 1 and 6. Enter again: ");
            scanf("%d",&choice);
        }
        switch (choice){
            case 1:
                RegisterMember(Name,&StudentId,&MemberType);
                break;
            case 2:
                DisplayBooks(BookIDs,BookTitles,AvailableCopies,TotalBooks);
                break;
            case 3:
                BorrowBook(BookIDs,BookTitles,AvailableCopies,TotalBooks,BorrowedBooksID,&BorrowedCount,MemberType);
                break;
            case 4:
                FineAfterWaiver += ReturnBook(BookIDs, AvailableCopies, TotalBooks,BorrowedBooksID, &BorrowedCount,MemberType, &TotalFine);
                break;
            case 5 :
                DisplayMemberRecord(Name,StudentId,MemberType,BorrowedBooksID,BorrowedCount,TotalFine,FineAfterWaiver);
                break;
            case 6:
                break;
            default:
                printf("Invalid menu option");

        }
    }
    while (choice !=6);
}
