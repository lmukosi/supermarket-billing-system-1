// Including necessary header files for input and output operations, and file handling
#include<iostream>
#include<fstream>



// Using the standard namespace for convenience
using namespace std;

// Declaration of the 'shopping' class
class shopping
{
private:
    int pcode;        // Product code
    float price;      // Product price
    float dis;        // Product discount
    string pname;     // Product name

public: // Public section for declaring member functions

    void menu(); // Function to display the main menu

    void administrator(); // Function to handle administrator-related actions

    void buyer(); // Function to handle buyer-related actions

    void add(); // Function to add a new product

    void edit(); // Function to edit an existing product

    void rem();  // Function to remove a product

    void list();  // Function to list all products

    void receipt(); // Function to generate a receipt
};


void shopping::menu()
{
m: // Using a goto statement to loop back to label 'm

    // Declaration of variables to store user input
    int choice;
    string email;
    string password;

    // Displaying the main menu for the supermarket
    cout << "\t\t\t\t__________________________________________________\n";
    cout << "\t\t\t\t                                                  \n";
    cout << "\t\t\t\t             Supermarket Main Menu                \n";
    cout << "\t\t\t\t                                                  \n";
    cout << "\t\t\t\t__________________________________________________\n";
    cout << "\t\t\t\t                                                  \n";
    cout << "\t\t\t\t|  1.  Administrator      |\n";
    cout << "\t\t\t\t|                         |\n";
    cout << "\t\t\t\t|  2.  Buyer              |\n";
    cout << "\t\t\t\t|                         |\n";
    cout << "\t\t\t\t|  3.  Exit               |\n";
    cout << "\t\t\t\t|                         |\n";
    cout << "\n\t\t\t\t   Please Selcet  ";
    cin >> choice;

    // Switch statement to handle different choices
    switch (choice)
    {
    case 1:
    {
        // Administrator login section
        cout << "\t\t\t Please Login \n";
        cout << "\t\t\t Enter Email : \n";
        cin >> email;
        cout << "\t\t\t Password : ";
        cin >> password;

        // Check if the entered email and password match the expected values
        if (email == "lmukosi@ymail.com" && password == "Luck@M")
        {
            administrator();
        }
        else
        {
            cout << "\033[1;31m" << "Invalid email/password !";
        }
        break;
    }
    case 2:
    {
        buyer();
    }
    case 3:
    {
        exit(0);
    }
    default:
    {
        cout << "Invalid choice. Please try again.";// Display message for invalid choices
    }
    }
    // Using a goto statement to loop back to label 'm'
    goto m;
}

// Function definition for the 'administrator' function in the 'shopping' class
void shopping::administrator()
{
m: // Assuming 'm' is a label, it could be used for a goto statement later

    // Variable to store user's choice
    int choice;

    // Displaying the administrator menu
    cout << "\n\n\n\t\t\t administrator menu";
    cout << "\n\t\t\t|______1. Add the product______|";
    cout << "\n\t\t\t|                              |";
    cout << "\n\t\t\t|______2. Modify the product___|";
    cout << "\n\t\t\t|                              |";
    cout << "\n\t\t\t|______3. Delete the product___|";
    cout << "\n\t\t\t|                              |";
    cout << "\n\t\t\t|______4. Back to main menu____|";

    // Prompting the user to enter their choice
    cout << "\n\n\t Please enter your choice : ";
    cin >> choice;

    // Switch statement to handle different choices
    switch (choice)
    {
    case 1:
        add();
        break;

    case 2:
        edit();
        break;

    case 3:
        rem();
        break;

    case 4:
        menu();
        break;

    default:
        cout << "Invalid choice. Please try again.";

    }

    // Using a goto statement to loop back to label 'm'
    goto m;
}

// Function definition for the 'buyer' function in the 'shopping' class
void shopping::buyer()
{
m: // Assuming 'm' is a label, it could be used for a goto statement later

    // Variable to store user's choice
    int choice;
    cout << "\t\t\t  Buyer  \n";
    cout << "\t\t\t___________________\n";
    cout << "                         \n";
    cout << "\t\t\t 1. Buy product    \n";
    cout << "                         \n";
    cout << "\t\t\t 2. Go back        \n";
    cout << "\t\t\t Enter your choice :";
    cin >> choice;

    switch (choice)
    {
    case 1:
        receipt();
        break;

    case 2:
        menu();
        break;

    default:
        cout << "Invalid choice. Please try again.";

    }

    // Using a goto statement to loop back to label 'm'
    goto m;
}

// This function adds a new product to the shopping database.
void shopping::add()
{
m: // This statement seems to be a placeholder or an error. It doesn't have any effect and can be removed.

    fstream data; // File stream object for handling input/output operations on the "database.txt" file.
    int c;
    int token = 0;
    float p;
    float d;
    string n;

    // Display messages to get information about the new product from the user.
    cout << "\n\n\t\t\t Add new product  ";
    cout << "\n\n\t\t\t Enter the product code ";
    cin >> pcode;
    cout << "\n\n\t\t\t Name of the product ";
    cin >> pname;
    cout << "\n\n\t\t\t Price of the product ";
    cin >> price;
    cout << "\n\n\t\t\t Discount on the product ";
    cin >> dis;

    // Open the "database.txt" file for input.
    data.open("database.txt", ios::in);

    if (!data) // Check if the file doesn't exist.
    {
        // If the file doesn't exist, open it in append mode for output and create a new entry.
        data.open("database.txt", ios::app | ios::out);
        data << "  " << pcode << " " << pname << "  " << price << "  " << dis << "\n";
        data.close(); // Close the file.
    }
    else // If the file exists, check for existing product codes.
    {
        data >> c >> n >> p >> d; // Read the first entry from the file.
        while (!data.eof())
        {
            if (c == pcode)
            {
                token++; // If the product code already exists, increment the token.
            }
            data >> c >> n >> p >> d; // Read the next entry from the file.
        }

        data.close(); // Close the file.

        // If the product code already exists, go back to the beginning of the function.
        if (token == 1)
            goto m;
        else
        {
            // If the product code doesn't exist, open the file in append mode and add the new entry.
            data.open("database.txt", ios::app | ios::out);
            data << "  " << pcode << " " << pname << "  " << price << "  " << dis << "\n";
            data.close(); // Close the file.
        }
    }

    // Display a message indicating that the record has been inserted.
    cout << "\033[0;41m" << "\n\n\t\t Record inserted !";
}

void shopping::edit()
{
    fstream data, data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;

    cout << "\n\t\t\t Modify the record";
    cout << "\n\t\t\t Product code : ";
    cin >> pkey;

    data.open("database.txt", ios::in);
    if (!data) // Check if the file doesn't exist.
    {
        cout << "\n\nFile doesn't exist";
    }
    else
    {
        data1.open("database1.txtx, ios::app|ios::out");

        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            if (pkey == pcode)
            {
                cout << "\n\t\t Product new code :";
                cin >> c;
                cout << "\n\t\t Name of the product";
                cin >> n;
                cout << "\n\t\t Discount : ";
                cin >> d;
                data1 << "  " << pcode << " " << pname << "  " << price << "  " << dis << "\n";
                cout << "\033[0;41m" << "\n\n\t\t Record edited !";
                token++;
            }
            else
            {
                data1 << "  " << pcode << " " << pname << "  " << price << "  " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();

        remove("database.txt!");

        if (token == 0)
        {
            cout << "\n\n record not found !";
        }
    }
}
void shopping::rem()
{

    fstream data, data1;
    int pkey;
    int token = 0;
    cout << "\n\n\t Delete product";
    cout << "\n\n\t Product code : ";
    cin >> pkey;
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "File doean't exist";
    }

    else
    {
        data1.open("database1.txtx, ios::app|ios::out");
        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            if (pkey == pcode)
            {
                cout << "\n\t\t Product deleted succesfully : ";
                token++;
            }
            else {
                data1 << "  " << pcode << " " << pname << "  " << price << "  " << dis << "\n";
            }
            data.close();
            data1.close();
            remove("database.txt");
            rename("database1.txt", "database.txt");

            if (token == 0)
            {
                cout << "\n\n Record not found";
            }
        }
    }
}

void shopping::list()
{
    fstream data;
    data.open("database.txt", ios::in);
    cout << "\n\n|_________________________________________\n";
    cout << "ProNo\t\tName\t\tPrice\n";
    cout << "\n\n|_________________________________________\n";
    data >> pcode >> pname >> price >> dis;
    while (!data.eof())
    {
        cout << pcode << "\t\t" << pname << "\t\t" << price << "\n";
        data >> pcode >> pname >> price >> dis;
    }
    data.close();
}

//on this fuction there a bit focus of arrays
void shopping::receipt()
{

    fstream data;

    int arrc[100];
    int arrq[100];
    char choice;
    int c = 0;
    float amount = 0;
    float dis = 0;
    float total = 0;

    cout << "\n\n\t\t\t RECEIPT";
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "Empty database";
    }
    else
    {
        data.close();

        list();
        cout << "\n|_________________________________________|\n";
        cout << "\n|                                         |\n";
        cout << "\n|      Please place the order             |\n";
        cout << "\n|_________________________________________|\n";
        do
        {
        m:
            cout << "\n\nEnter Product code";
            cin >> arrc[c];
            cout << "\n\nEnter Product quantity";
            cin >> arrq[c];
            for (int i = 0; i < c; i++)
            {
                if (arrc[c] == arrc[i])
                {
                    cout << "\n\n Duplicate product code. Please try again";
                    goto m;
                }
            }
            c++;
            cout << "\n\n Do you want to buy another product? if yes then press y else no";
            cin >> choice;

        } while (choice);

        cout << "\n\n\t\t\t______________RECEIPT_______________\n";
        cout << "\nProduct No.\t Product Name\t Product Quantity\t Price\t Amount with discout\n";

        for (int i = 0; i < c; i++)
        {
            data.open("database.txt", ios::in);
            data >> pcode >> pname >> price >> dis;
            while (!data.eof())
            {
                if (pcode = arrc[i])
                {
                    amount = price * arrq[i];
                    dis = amount - (amount * dis / 100);
                    total = total + dis;
                    cout << "\n" << pcode << "\t\t" << pname << "\t\t" << price << "\t\t" << amount << "\t\t" << dis;

                }
                data >> pcode >> pname >> price >> dis;
            }
        }
        data.close();
    }
    cout << "\n\n________________________________________";
    cout << "\n Total Amount";
}
int main()
{
    shopping s;
    s.menu();
}