#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_TEXTS 20

struct User {
    int userId;
    char userName[20];
    char hasDueBook;
    int dueBookId;
};

struct Text {
    int textId;
    char textName[30];
    char textAuthor[20];
    char isAvailable;
    int currentUserId;
};

void displayText(struct Text text) {
    printf("\n\tText Information\nText ID: %d\tText Name: %s\nAuthor: %s\nAvailable: %c\tDue by User ID: %d\n",
           text.textId, text.textName, text.textAuthor, text.isAvailable, text.currentUserId);
}

void displayUser(struct User user) {
    printf("\n\tUser Information\nUser ID: %d\tUser Name: %s\nDue: %c\t\tDue text ID: %d\n",
           user.userId, user.userName, user.hasDueBook, user.dueBookId);
}

int main() {
    struct User users[MAX_USERS] = {0};
    struct Text texts[MAX_TEXTS] = {0};

    int option, searchId, secondaryId, count, flag;

    printf("\n\t\tWELCOME!\n");

    do {
        printf("\n\tLibrary Management System\n\t=========================\n"
               "1. Add new text\t\t2. Search text\n"
               "3. Add new user\t4. Search user\n"
               "5. Issue text\t\t6. Submit text\n"
               "7. Delete text\t\t8. Delete user\n"
               "9. List of texts\t10. Exit\n"
               "11. Update text\t12. Update user\n"
               "13. Search texts by author\t14. Search texts by name\n"
               "15. List texts by availability\t16. List users with due texts\n"
               "17. Sort texts\t\t18. Sort users\n"
               "Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1: // Add a text
                for (int i = 0; i < MAX_TEXTS; i++) {
                    if (texts[i].textId == 0) {
                        printf("Enter text name: ");
                        scanf("%s", texts[i].textName);
                        printf("Enter author name: ");
                        scanf("%s", texts[i].textAuthor);
                        printf("Enter text ID: ");
                        scanf("%d", &texts[i].textId);
                        texts[i].isAvailable = 'y';
                        texts[i].currentUserId = 0;
                        printf("Text added successfully.\n\n");
                        break;
                    }
                }
                break;

            case 2: // Search text
                printf("Enter text ID: ");
                scanf("%d", &searchId);
                count = 0;
                for (int i = 0; i < MAX_TEXTS; i++) {
                    if (searchId == texts[i].textId) {
                        displayText(texts[i]);
                        count++;
                        break;
                    }
                }
                if (count == 0) {
                    printf("Text not found.\n\n");
                }
                break;

            case 3: // Add a user
                for (int i = 0; i < MAX_USERS; i++) {
                    if (users[i].userId == 0) {
                        printf("Enter user's name: ");
                        scanf("%s", users[i].userName);
                        printf("Enter user ID: ");
                        scanf("%d", &users[i].userId);
                        users[i].hasDueBook = 'n';
                        users[i].dueBookId = 0;
                        printf("User added successfully.\n\n");
                        break;
                    }
                }
                break;

            case 4: // Search user
                printf("Enter user ID: ");
                scanf("%d", &searchId);
                count = 0;
                for (int i = 0; i < MAX_USERS; i++) {
                    if (searchId == users[i].userId) {
                        displayUser(users[i]);
                        count++;
                        break;
                    }
                }
                if (count == 0) {
                    printf("User not found.\n\n");
                }
                break;

            case 5: // Issue text
                printf("Enter text ID: ");
                scanf("%d", &searchId);
                printf("Enter user ID: ");
                scanf("%d", &secondaryId);
                count = 0;
                flag = 0;
                for (int i = 0; i < MAX_TEXTS; i++) {
                    if (searchId == texts[i].textId && texts[i].isAvailable == 'y') {
                        texts[i].isAvailable = 'n';
                        texts[i].currentUserId = secondaryId;
                        count++;
                        break;
                    }
                }
                for (int i = 0; i < MAX_USERS; i++) {
                    if (secondaryId == users[i].userId && users[i].hasDueBook == 'n') {
                        users[i].hasDueBook = 'y';
                        users[i].dueBookId = searchId;
                        flag++;
                        break;
                    }
                }
                if (count == 1 && flag == 1) {
                    printf("Text issued successfully.\n\n");
                } else if (count == 1 && flag == 0) {
                    for (int i = 0; i < MAX_TEXTS; i++) {
                        if (searchId == texts[i].textId) {
                            texts[i].isAvailable = 'y';
                            texts[i].currentUserId = 0;
                            break;
                        }
                    }
                    printf("Text not issued. User has a due text.\n\n");
                }
                break;

            case 6: // Submit text
                printf("Enter text ID: ");
                scanf("%d", &searchId);
                for (int i = 0; i < MAX_TEXTS; i++) {
                    if (searchId == texts[i].textId) {
                        texts[i].isAvailable = 'y';
                        secondaryId = texts[i].currentUserId;
                        texts[i].currentUserId = 0;
                        break;
                    }
                }
                for (int i = 0; i < MAX_USERS; i++) {
                    if (secondaryId == users[i].userId) {
                        users[i].hasDueBook = 'n';
                        users[i].dueBookId = 0;
                        break;
                    }
                }
                printf("Text ID %d submitted successfully.\n\n", searchId);
                break;

            case 7: // Delete text
                printf("Enter text ID to be deleted: ");
                scanf("%d", &searchId);
                count = 0;
                for (int i = 0; i < MAX_TEXTS; i++) {
                    if (searchId == texts[i].textId) {
                        for (int j = i; j < MAX_TEXTS - 1; j++) {
                            texts[j] = texts[j + 1];
                        }
                        texts[MAX_TEXTS - 1].textId = 0; // Clear last element
                        count++;
                        break;
                    }
                }
                if (count != 0) {
                    printf("Text ID %d deleted.\n\n", searchId);
                } else {
                    printf("Text not found.\n\n");
                }
                break;

            case 8: // Delete user
                printf("Enter user ID to be deleted: ");
                scanf("%d", &searchId);
                count = 0;
                for (int i = 0; i < MAX_USERS; i++) {
                    if (searchId == users[i].userId) {
                        for (int j = i; j < MAX_USERS - 1; j++) {
                            users[j] = users[j + 1];
                        }
                        users[MAX_USERS - 1].userId = 0; // Clear last element
                        count++;
                        break;
                    }
                }
                if (count != 0) {
                    printf("User ID %d deleted.\n\n", searchId);
                } else {
                    printf("User not found.\n\n");
                }
                break;

            case 9: // List all texts
                count = 0;
                for (int i = 0; i < MAX_TEXTS; i++) {
                    if (texts[i].textId != 0) {
                        count++;
                    }
                }
                printf("\n\t\tText list\tTotal texts: %d\n\nID\tName\t\t\tAuthor\t\t\tAvailable\tUser ID\n\n", count);
                for (int i = 0; i < MAX_TEXTS; i++) {
                    if (texts[i].textId != 0) {
                        printf("%d\t%s\t\t%s\t\t%c\t\t%d\n", texts[i].textId, texts[i].textName, texts[i].textAuthor, texts[i].isAvailable, texts[i].currentUserId);
                    }
                }
                break;

            case 10: // Exit
                printf("\n\t\tTHANK YOU!");
                exit(0);
                break;

            case 11: // Update text
                printf("Enter text ID to update: ");
                scanf("%d", &searchId);
                count = 0;
                for (int i = 0; i < MAX_TEXTS; i++) {
                                        if (searchId == texts[i].textId) {
                        printf("Enter new text name: ");
                        scanf("%s", texts[i].textName);
                        printf("Enter new author name: ");
                        scanf("%s", texts[i].textAuthor);
                        printf("Enter new availability (y/n): ");
                        scanf(" %c", &texts[i].isAvailable);
                        printf("Text updated successfully.\n\n");
                        count++;
                        break;
                    }
                }
                if (count == 0) {
                    printf("Text not found.\n\n");
                }
                break;

            case 12: // Update user
                printf("Enter user ID to update: ");
                scanf("%d", &searchId);
                count = 0;
                for (int i = 0; i < MAX_USERS; i++) {
                    if (searchId == users[i].userId) {
                        printf("Enter new user name: ");
                        scanf("%s", users[i].userName);
                        printf("Enter new due status (y/n): ");
                        scanf(" %c", &users[i].hasDueBook);
                        printf("Enter new due text ID: ");
                        scanf("%d", &users[i].dueBookId);
                        printf("User updated successfully.\n\n");
                        count++;
                        break;
                    }
                }
                if (count == 0) {
                    printf("User not found.\n\n");
                }
                break;

            case 13: // Search texts by author
                printf("Enter author's name: ");
                char authorName[20];
                scanf("%s", authorName);
                count = 0;
                for (int i = 0; i < MAX_TEXTS; i++) {
                    if (strcmp(authorName, texts[i].textAuthor) == 0) {
                        displayText(texts[i]);
                        count++;
                    }
                }
                if (count == 0) {
                    printf("No texts found by this author.\n\n");
                }
                break;

            case 14: // Search texts by name
                printf("Enter text name: ");
                char textName[30];
                scanf("%s", textName);
                count = 0;
                for (int i = 0; i < MAX_TEXTS; i++) {
                    if (strstr(texts[i].textName, textName)) {
                        displayText(texts[i]);
                        count++;
                    }
                }
                if (count == 0) {
                    printf("No texts found with this name.\n\n");
                }
                break;

            case 15: // List texts by availability
                printf("Enter availability (y/n): ");
                char availabilityStatus;
                scanf(" %c", &availabilityStatus);
                count = 0;
                for (int i = 0; i < MAX_TEXTS; i++) {
                    if (texts[i].isAvailable == availabilityStatus) {
                        displayText(texts[i]);
                        count++;
                    }
                }
                if (count == 0) {
                    printf("No texts with this availability status.\n\n");
                }
                break;

            case 16: // List users with due texts
                count = 0;
                for (int i = 0; i < MAX_USERS; i++) {
                    if (users[i].hasDueBook == 'y') {
                        displayUser(users[i]);
                        count++;
                    }
                }
                if (count == 0) {
                    printf("No users with due texts.\n\n");
                }
                break;

            case 17: // Sort texts
                for (int i = 0; i < MAX_TEXTS - 1; i++) {
                    for (int j = i + 1; j < MAX_TEXTS; j++) {
                        if (texts[i].textId != 0 && texts[j].textId != 0 && texts[i].textId > texts[j].textId) {
                            struct Text temp = texts[i];
                            texts[i] = texts[j];
                            texts[j] = temp;
                        }
                    }
                }
                printf("Texts sorted by ID.\n\n");
                break;

            case 18: // Sort users
                for (int i = 0; i < MAX_USERS - 1; i++) {
                    for (int j = i + 1; j < MAX_USERS; j++) {
                        if (users[i].userId != 0 && users[j].userId != 0 && users[i].userId > users[j].userId) {
                            struct User temp = users[i];
                            users[i] = users[j];
                            users[j] = temp;
                        }
                    }
                }
                printf("Users sorted by ID.\n\n");
                break;

            default:
                printf("Invalid choice. Please enter a number between 1 and 18.\n\n");
                break;
        }

    } while (option != 10);

    return 0;
}
