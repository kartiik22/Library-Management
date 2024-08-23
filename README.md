Library Management System - Code Description
The provided code is a console-based Library Management System (LMS) implemented in C. It allows for the management of texts and users within a library. The system supports various functionalities including adding, searching, updating, issuing, and deleting both texts and users. Additionally, it provides options to list and sort texts and users. Below is a detailed description of the code and its components:

Struct Definitions
User Structure

userId: Integer identifier for the user.
userName: String storing the user's name.
hasDueBook: Character indicating whether the user has a due book ('y' for yes, 'n' for no).
dueBookId: Integer representing the ID of the due book, if any.
Text Structure

textId: Integer identifier for the text.
textName: String storing the name of the text.
textAuthor: String storing the author's name.
isAvailable: Character indicating the availability of the text ('y' for available, 'n' for not available).
currentUserId: Integer representing the ID of the user currently holding the text.
Function Definitions
displayText(struct Text text)

Displays information about a given text, including ID, name, author, availability, and current user ID.
displayUser(struct User user)

Displays information about a given user, including ID, name, due status, and due text ID.
Main Program
Initialization

Arrays users and texts are initialized to hold up to MAX_USERS and MAX_TEXTS, respectively. Both arrays are zeroed initially to indicate empty slots.
Menu Display and Input Handling

A loop presents a menu to the user, allowing them to select various operations.
Case Descriptions

Add New Text: Prompts for details to add a new text to the system.
Search Text: Allows searching for a text by its ID and displays its details if found.
Add New User: Prompts for details to add a new user.
Search User: Allows searching for a user by ID and displays their details if found.
Issue Text: Assigns a text to a user, marking it as unavailable and updating the user's due status.
Submit Text: Marks a text as available and updates the user's due status if the text is returned.
Delete Text: Removes a text from the system by its ID.
Delete User: Removes a user from the system by their ID.
List of Texts: Displays all texts with their details.
Exit: Terminates the program.
Update Text: Allows updating the details of an existing text.
Update User: Allows updating the details of an existing user.
Search Texts by Author: Searches and lists texts by a specific author.
Search Texts by Name: Searches and lists texts containing a specific name.
List Texts by Availability: Lists texts based on their availability status.
List Users with Due Texts: Lists users who have texts currently due.
Sort Texts: Sorts the list of texts by their ID.
Sort Users: Sorts the list of users by their ID.
Program Flow
User Interaction

The program operates in a loop, displaying the menu and handling user choices until the user selects the exit option.
Error Handling

Provides feedback for invalid choices and handles edge cases like searching for non-existent texts or users.
Sorting

Implements basic sorting algorithms to arrange texts and users by ID in ascending order.
The system is designed for simplicity and does not include persistent storage, meaning all data is lost upon exiting the program. This code is suitable for understanding basic library management operations and demonstrating fundamental programming concepts in C.




