#include<stdio.h>
#include<string.h>

typedef struct Itemmm
{
    char name[10];
    int qty;
    int price;
}Item;


void add_item(Item* lis, int count)
{
    printf("\n\nWelcome to add_item!\n");
    printf("Enter the details\n");
   
        printf("Name: ");
        scanf("%s",lis[count].name);

        printf("Quantity:");
        scanf("%d",&lis[count].qty);

        printf("Price:");
        scanf("%d",&lis[count].price);
}

void del_item(Item* lis, int count)
{   
    printf("\n\nWelcome to del_item\n");
    char target[10];
    printf("Enter the name of item which needs to be deleted:");
    scanf("%s",target);
    int pos;
    
    for (int i = 0; i < count; i++)
    {
        int result= strcmp(lis[i].name,target);
       if (result==0)
       {
           pos=i;
       }
    } 

    for(int i=pos;i<count;i++)
    {  
        strcpy(lis[i].name,lis[i+1].name);
        lis[i].qty=lis[i+1].qty;
        lis[i].price=lis[i+1].price;
    }
    strcpy(lis[count-1].name,"");
    lis[count-1].qty=0;
    lis[count-1].price=0;
    printf("%s is deleted\n",target);

}

void update_item(Item* lis, int count)
{
    printf("\n\nWelcome to update_item\n");
    char target2[10];
    printf("Enter the name of items which needs to be updated:");
    scanf("%s",target2);
     for (int i = 0; i < count; i++)
    {   
        int result= strcmp(lis[i].name,target2);
        if (result==0)
        {
            printf("Before update\n");
            printf("Price of %s is %d\n",target2,lis[i].price);
            int price2;
            printf("Enter new price:");
            scanf("%d",&price2);
            lis[i].price=price2;

            printf("Before update\n");
            printf("Quantity of %s is %d\n",target2,lis[i].qty);
            int quantity;
            printf("Enter new quantity:");
            scanf("%d",&quantity);
            lis[i].qty=quantity;
            printf("After update:\n");
            printf("Updated price of %s is %d\n",target2,lis[i].price);
            printf("Updated price of %s is %d\n",target2,lis[i].qty);
        }
    }
}

void display(Item* lis, int count)
{   
    if (count==0)
    {
        printf("List is empty\n");
    }
    else
    {
        printf("\n\nDisplaying all items:\n");
        for(int i = 0; i < count; i++)
        {
            printf("Name:%s  ",lis[i].name);
            printf("Quantity:%d  ",lis[i].qty);
            printf("Price:%d\n",lis[i].price);
        }
    }
}

int add_to_Cart(Item* cart,Item* lis, int cart_count,int items_count)
{   
    char target3[10];
    int quan;
    printf("\n\nWelcome to add_to_Cart\n");
    printf("Enter item name to add in cart:");
    scanf("%s",target3);

        for (int i = 0; i < cart_count; i++)
        {
            int result0= strcmp(cart[i].name,target3);
            if (result0==0)
                {
                    printf("This item is already present in cart so can't add again\n");
                    return cart_count;
                }
        }  

        int elem_found = 0;
        for (int i = 0; i < items_count; i++)
        {
            int result= strcmp(lis[i].name,target3);

            if (result==0)
            {
                printf("Enter the quantity of item:");
                scanf("%d",&quan);
                
                elem_found = 1;
                if (quan>lis[i].qty)
                {
                    printf("That much qty is not available in the mart\n");
                    break;
                }
                else
                { 
                    strcpy(cart[cart_count].name,target3);
                    cart[cart_count].price=lis[i].price;
                    cart[cart_count].qty=quan;
                    cart_count++;
                }
            }
        }

        if(elem_found == 0){
            printf("Item not prsent in mart");
        }
    return cart_count;
}

void view_cart(Item* cart, int cart_count)
{   
    if (cart_count==0)
    {
        printf("Cart is empty\n");
    }
    else
    {
        printf("\n\nDisplaying all items in cart:\n");
        for(int i = 0; i < cart_count; i++)
        {
            printf("Name:%s  ",cart[i].name);
            printf("Quantity:%d  ",cart[i].qty);
            printf("Price:%d\n",cart[i].price);
        }
    }
    int total_amount=0;
    for (int i = 0; i < cart_count; i++)
    {
        total_amount+= (cart[i].qty) * (cart[i].price);
    }
    printf("\nTotal amount= %d\n",total_amount);
}

void update_cart(Item* cart, int cart_count, Item* lis, int items_count)
{
    printf("\n\nWelcome to update_cart\n");
    char target2[10];
    printf("Enter the name of items which needs to be updated:");
    scanf("%s",target2);
     for (int i = 0; i < cart_count; i++)
    {   
        int result= strcmp(cart[i].name,target2);
        if (result==0)
        {
            printf("Before update\n");
            printf("Quantity of %s is %d\n",target2,cart[i].qty);
            int quantity;
            printf("Enter new quantity:");
            scanf("%d",&quantity);
            for (int i = 0; i < items_count; i++)
            {
                int result= strcmp(lis[i].name,target2);

                if (result==0)
                {
                    if (quantity>lis[i].qty)
                    {
                        printf("That much qty is not available in the mart\n");
                        break;
                    }
                }
            }
            cart[i].qty=quantity;
            printf("After update:\n");
            printf("Updated quantity of %s is %d",target2,cart[i].qty);
        }
    }
}

void del_from_cart(Item* cart, int cart_count)
{
    printf("\n\nWelcome to del_from_cart\n");
    char target[10];
    printf("Enter the name of item which needs to be deleted:");
    scanf("%s",target);
    int pos;
    
    for (int i = 0; i < cart_count; i++)
    {
        int result= strcmp(cart[i].name,target);
       if (result==0)
       {
           pos=i;
       }
    } 

    for(int i=pos;i<cart_count;i++)
    {  
        strcpy(cart[i].name,cart[i+1].name);
        cart[i].qty=cart[i+1].qty;
        cart[i].price=cart[i+1].price;
    }
    strcpy(cart[cart_count-1].name,"");
    cart[cart_count-1].qty=0;
    cart[cart_count-1].price=0;
    printf("%s is deleted from cart\n",target);
}

int checkout_bill(Item* cart, int cart_count, Item* lis, int list_count)
{
    printf("\n\nChecking out......\n");
    printf("Generating bill......\n");

    for (int i = 0; i < cart_count; i++)
    {
        printf("Name:%s  ",cart[i].name);
        printf("Quantity:%d  ",cart[i].qty);
        printf("Price:%d\n",cart[i].price);
    }

    int total_cart_items=cart_count;
    printf("\nTotal no. of items= %d\n",total_cart_items);

    int total_amount=0;
    for (int i = 0; i < cart_count; i++)
    {
        total_amount+= (cart[i].qty) * (cart[i].price);
    }
    printf("\nTotal amount= %d\n",total_amount);

    printf("\nChecked out\n");
    printf("Thank you for shopping!!\n");

    // updating the main list after buying
    for (int i = 0; i < list_count; i++)
    {   
        for (int j = 0; j < cart_count; j++)
        {
            int result= strcmp(lis[i].name,cart[j].name);
            if (result==0)
            {
                lis[i].qty= lis[i].qty - cart[j].qty; 
                if (lis[i].qty<=0)
                {
                    strcpy(lis[i].name,lis[i+1].name);
                    lis[i].qty=lis[i+1].qty;
                    lis[i].price=lis[i+1].price;
                    list_count--;
                }   
            }
        }
    } 

    // emptying the cart
    for(int i=0;i<cart_count;i++)
    {  
        strcpy(cart[i].name,"");
        cart[i].qty=0;
        cart[i].price=0; 
    }
    return list_count;
}


int admin(Item* lis, int items_count)
{   
    int ex1=0;
   
    while(ex1==0)
    {
    printf("\n\nWelcome to admin panel\n");
    printf("Press 1 for adding items\n");
    printf("Press 2 for deleting items\n");
    printf("Press 3 for upadating items\n");
    printf("Press 4 for displaying items\n");
    printf("Press 5 for exiting admin panel\n");
    int a;
    printf("Enter your choice:");
    scanf("%d",&a);
    
        switch (a)
        {
        case 1:
            add_item(lis,items_count);
            items_count++;
            break;
    
        case 2:
            del_item(lis, items_count);
            items_count--;
            break;
    
        case 3:
            update_item(lis, items_count);
            break;

        case 4:
            display(lis,items_count);
            break;

        case 5:
            printf("EXITING ADMIN PANEL \n\n");
            ex1=1;
            break;
        }
    }
    return items_count;
}

int user(Item* lis, Item* cart, int items_count)
{
    int cart_count = 0;
    int ex2=0;
    while(ex2==0)
    {
    printf("\n\nWelcome to Shopping Mart!\n");
    printf("Press 1 for view all items items\n");
    printf("Press 2 for add_to_Cart\n");
    printf("Press 3 for view_cart\n");
    printf("Press 4 for upadating items\n");
    printf("Press 5 for del_from_cart\n");
    printf("Press 6 for checkout and view bill\n");
    printf("Press 7 for exiting user panel\n");
    int b;
    printf("Enter your choice:");
    scanf("%d",&b);
    
    switch(b)
        {
        case 1:
            display(lis,items_count);
            break;
    
        case 2:
            cart_count = add_to_Cart(cart,lis,cart_count,items_count);
            break;
    
        case 3:
            view_cart(cart,cart_count);
            break;

        case 4:
            update_cart(cart,cart_count,lis,items_count);
            break;

        case 5:
            del_from_cart(cart,cart_count);
            cart_count--;
            break;
        
        case 6:
            items_count= checkout_bill(cart,cart_count,lis,items_count);
            cart_count = 0;
            break;
            
        case 7:
            printf("EXITING USER PANEL\n\n");
            ex2=1;
            break;
        }
  
    }
    return items_count;
}


void main(){

    Item lis[10];
    Item cart[10];
    int item_count=0;
    int ex=0;
    while(ex==0)
    {
        int n;
        printf("press 1 for admin or Press 2 for user or press 3 for exiting program \n");
        printf("Enter your choice:");
        scanf("%d",&n);

        switch (n)
        {
            case 1:
            item_count = admin(lis, item_count);
            break;

            case 2:
            item_count= user(lis,cart,item_count);
            break;
            
            case 3:
            printf("EXITING THE PROGRAM");
            ex=1;
            break;
        }
    }   
}