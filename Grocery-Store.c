#include <stdio.h>
#include <string.h>

char emlployeeId[10];
char password[10];
int items[20];
int quantity[20];

int i, j, q;
int sum;
int discAmount, discountedBill;
int noOfItems, itemNo;
char choice;
int option;

void menu() 
{
    printf("\n **Menu** \n\n");
    printf("1. Add items (Max 20)\n");
    printf("2. Remove items \n");
    printf("3. Calculate Bill \n");
    printf("4. Calculate Discount \n");
    printf("5. Exit \n");

    chooseOption();
}

void addItems()
{
    getchar();

    printf("\nWant to add item ? (y/n) ");
    scanf("%c", &choice);
    printf("\nHow many items you want to add ? ");
    scanf("%d", &noOfItems);

    if(choice == 'y')
    {
        for (i = 0, j = 0; i < noOfItems, j < noOfItems; i++, j++)
        {
            printf("Enter product id for item %d: ", i + 1);
            scanf("%d", &items[i]);
            printf("Enter product quantity for item %d: ", j + 1);
            scanf("%d", &quantity[j]);
        }

        printf("\nItems array:\n");

        for (i = 0, j = 0; i < noOfItems, j < noOfItems; i++, j++)
        {
            printf("%d,   %d\n", items[i], quantity[j]);
        }
    }
    else if (choice == 'n')
    {
        menu();
    }
}

void removeItems()
{
    getchar();

    printf("\nWant to remove item ? (y/n) ");
    scanf("%c", &choice);
    printf("\nEnter item no: ");
    scanf("%d", &itemNo);

    if (choice == 'y')
    {       
        for (i = itemNo - 1, j = itemNo - 1; i < 3 - 1, j < 3 - 1; i++, j++)
        {
            items[i] = items[i + 1];
            quantity[j] = quantity[j + 1];

            if (quantity[j] > 1)
            {
                printf ("Item no %d has %d quantity. How many of them you want to remove ? ", itemNo, quantity[j]);
                scanf("%d", &q);
                quantity[j] = quantity[j] - q;
                printf("Now item no %d has %d quantity.", itemNo, quantity[j]);
            }
            else
            {
                printf("Item removed!\n");
            }
            
        }
            

        printf("Items array:\n");

        for (i = 0, j = 0; i < noOfItems - 1, j < noOfItems - 1; i++, j++)
        {
            printf("%d,   %d\n", items[i], quantity[j]);
        }       
    }
    else if (choice == 'n')
    {
        menu();
    }
}

void bill()
{
    sum = 0;
    printf("\nItems array:\n");
    printf("Item -> Product ID -> Quantity -> Price\n");

    for (i = 0, j = 0; i < noOfItems-1, j < noOfItems-1; i++, j++)
    {
        printf("%d -> %d -> %d -> %d\n", i+1, items[i], quantity[j], items[i]*quantity[j]);
        sum = sum + (items[i] * quantity[j]);
    }

    printf("Total Bill = %d\n", sum);
}

// int totalPrice()
// {
//     int total = 0;

//     for (i = 0, j = 0; i < noOfItems, j < noOfItems; i++, j++)
//     {
//         total = total + (items[i] * quantity[j]);
//     }

//     return total;
// }

void discount()
{
    int total = 0;

    for (i = 0, j = 0; i < noOfItems-1, j < noOfItems-1; i++, j++)
    {
        total = total + (items[i] * quantity[j]);
    }

    printf("Membership Card (M)\n");
    printf("Special Discount (S)\n");
    printf("No Discount (N)\n");

    scanf("%c", &choice);

    printf("\nTotal Bill = %d\n", total);

    if (choice == 'M')
    {
        discountedBill = total - (total * 0.1);
    }
    else if (choice == 'S')
    {
        printf("Enter the amount of discount = ");
        scanf("%d", &discAmount);
        printf("\n");
        discountedBill = total - (total * (discAmount / 100));
    }
    else if (choice == 'N')
    {
        discountedBill = total;
    }

    printf("Need to pay = %d\n", discountedBill);
    printf("\nThank You!!\n");
}

void chooseOption() 
{
    printf("Choose your option : ");
    scanf("%d", &option);

    switch (option)
    {
    case 1: 
        addItems();
        break;

    case 2:
        removeItems();
        break;

    case 3:
        bill();
        break;

    case 4:
        discount();
        break;

    case 5:
        menu();
        break;

    default:
        break;
    }
}

int main()
{
    printf("\nHey there, please login first to enter into the software.\n");
    
    printf("Enter your employee id: ");
    gets(emlployeeId);
        
    printf("Enter your password: ");
    gets(password);

    if (strcmp(emlployeeId, "00011") == 0 || strcmp(emlployeeId, "00012") == 0 || strcmp(emlployeeId, "00013") == 0 || strcmp(emlployeeId, "00014") == 0 || strcmp(emlployeeId, "00015") == 0)
    {
        if (strcmp(password, "abcd") == 0)
        {
            printf("\nNow you are logged in.\n");

            menu();
            addItems();
            removeItems();
            //bill();
            discount();
        }
        else
        {
            printf("Invalid password\n");
        }
        
    }
    else 
    {
        printf("Username wrong\n");
    }

        return 0;
}