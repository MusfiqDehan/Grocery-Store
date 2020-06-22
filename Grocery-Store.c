#include <stdio.h>
#include <string.h>
#include <windows.h>

char emlployeeId[10];
char password[10];
int productID[20];
int quantity[20];
int pricePerItem[20];
int totalPriceOfItem[20];

int i, j, k, l, q;
int sum;
int discAmount;
double discountedBill;
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
    system("clear");
}

void addItems()
{
    getchar();
    system("cls");
    printf("\nWant to add item ? (y/n) ");
    scanf("%c", &choice);
    printf("How many items you want to add ? ");
    scanf("%d", &noOfItems);
    printf("\n");

    if(choice == 'y')
    {
        for (i = 0, j = 0; i < noOfItems, j < noOfItems, k < noOfItems; i++, j++, k++)
        {
            printf("Enter product id for item %d: ", i + 1);
            scanf("%d", &productID[i]);
            printf("Enter product quantity for item %d: ", j + 1);
            scanf("%d", &quantity[j]);
            printf("Enter price (each) for item %d: ", k + 1);
            scanf("%d", &pricePerItem[k]);
            printf("\n");
        }

        printf("\n        ***Added Item's List***\n");
        printf("\nItemNo    ProductID    Quantity    PricePerItem\n");

        for (i = 0, j = 0, k = 0; i < noOfItems, j < noOfItems, k < noOfItems; i++, j++, k++)
        {
            printf(" %d          %d            %d              %d\n", i+1, productID[i], quantity[j], pricePerItem[k]);
        }
    }
    else if (choice == 'n')
    {
        menu();
    }
    getchar();
    menu();
}

void removeItems()
{
    system("cls");
    getchar();

    printf("\nWant to remove item ? (y/n) ");
    scanf("%c", &choice);
    printf("\nWhich item you want to remove? Enter item no: ");
    scanf("%d", &itemNo);

    if (choice == 'y')
    {
        for (i = itemNo - 1, j = itemNo - 1, k = itemNo - 1; i < noOfItems - 1, j < noOfItems - 1, k < noOfItems - 1; i++, j++, k++)
        {
            productID[i] = productID[i + 1];
            quantity[j] = quantity[j + 1];
            pricePerItem[k] = pricePerItem[k + 1];

            if (quantity[j] != 1)
            {
                printf ("Item no %d has %d quantity. How many of them you want to remove ? ", itemNo, quantity[j]);
                scanf("%d", &q);
                quantity[j+1] = quantity[j+1] - q;
                printf("Now item no %d has %d quantity.", itemNo, quantity[j+1]);
                //menu();
            }
            else
            {
                printf("Item removed!\n");
            }
            
        }
            

        printf("\n******Items' List After Removed*******\n");
        printf("\nItemNo    ProductID    Quantity    PricePerItem\n");

        for (i = 0, j = 0, k=0; i < noOfItems-1, j < noOfItems-1, k < noOfItems-1; i++, j++, k++)
        {
            printf(" %d          %d            %d             %d\n", i + 1, productID[i], quantity[j], pricePerItem[k]);
        }
    }
    else if (choice == 'n')
    {
        menu();
    }
    getchar();
    menu();
}

void bill()
{
    system("cls");
    sum = 0;
    printf("\n        *******Bill and List of Items*******\n");
    printf("\nItemNo    ProductID    Quantity    PricePerItem     TotalPriceOfItem\n");

    for (i = 0, j = 0, k = 0, l = 0; i < noOfItems - 1, j < noOfItems - 1, k < noOfItems - 1, l < noOfItems - 1; i++, j++, k++, l++)
    {
        totalPriceOfItem[l] =  quantity[j]* pricePerItem[k];
        printf(" %d          %d            %d             %d            %d\n", i + 1, productID[i], quantity[j], pricePerItem[k], totalPriceOfItem[l]);
        sum = sum + totalPriceOfItem[l];
    }

    printf("\nTotal Bill = %d\n", sum);
    printf("\n");
    getchar();
    menu();
}

void discount()
{
    system("cls");
    getchar();

    printf("Membership Card (M)\n");
    printf("Special Discount (S)\n");
    printf("No Discount (N)\n");

    scanf("%c", &choice);

    printf("\nTotal Bill = %d\n", sum);

    if (choice == 'M')
    {
        discountedBill = (double)(sum * 0.1);
    }
    else if (choice == 'S')
    {
        printf("\nEnter the amount of discount = ");
        scanf("%d", &discAmount);
        discountedBill = (double)(sum * (discAmount * 0.01));
    }
    else if (choice == 'N')
    {
        discountedBill = (double)sum;
    }

    printf("\nNeed to pay = %.2lf\n", (double)(sum - discountedBill));
    printf("\nThank You!!\n");
    printf("(Press any key to exit)\n");
    getchar();
    menu();
}

void chooseOption() 
{
    printf("\nChoose your option : ");
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
        break;

    default:
        break;
    }
}

int main()
{
    printf("\n       **********GROCERY STORE***********\n");
    printf("\nHey there, please login first to enter into the software.\n");
    
    printf("\nEnter your employee id: ");
    gets(emlployeeId);
        
    printf("Enter your password: ");
    gets(password);

    if (strcmp(emlployeeId, "00011") == 0 || strcmp(emlployeeId, "00012") == 0 || strcmp(emlployeeId, "00013") == 0 || strcmp(emlployeeId, "00014") == 0 || strcmp(emlployeeId, "00015") == 0)
    {
        if (strcmp(password, "abcd") == 0)
        {
            printf("\nNow you are logged in.\n");

            menu();
        }
        else
        {
            printf("Invalid password\n");
        }
        
    }
    else 
    {
        printf("Wrong Username\n");
    }

    getchar();
    return 0;
}
