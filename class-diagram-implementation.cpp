#include <iostream>
#include <iomanip>
#include <cctype> 
using namespace std;

class Product {
private:
    string productName;
    string productID;
    double unitPrice;
    int productQty;

public:
    Product(string id = "", string name = "", double p = 0.0, int qty = 0) {
        productID = id;
        productName = name;
        unitPrice = p;
        productQty = qty;
    }

    double getPrice() {
        return unitPrice;
    }

    string getProductID() {
        return productID;
    }

    string getProductName() {
        return productName;
    }

    int getProductQty() {
        return productQty;
    }

    void setProductQty(int quantity) {
        productQty = quantity;
    }

    string getProductDetails() {
        return "Product ID: " + productID + "\nProduct Name: " + productName + "\nUnit Price: " + to_string(unitPrice) + "\nQuantity: " + to_string(productQty);
    }
};

class ShoppingCart {
private:
    Product items[10];
    int quantities[10];
    int totalQty;
    double totalPrice;

public:
    ShoppingCart() {
        totalQty = 0;
        totalPrice = 0.0;
    }

    void addToCart(Product product, int quantity) {
        if (totalQty < 10) {
            product.setProductQty(quantity);
            items[totalQty] = product;
            quantities[totalQty] = quantity;
            totalPrice += product.getPrice() * quantity;

            
            cout << "\nSelected Product:";
            cout << "\n-------------------------------------------------------\n";
            cout << fixed << setprecision(2);
            cout << setw(15) << left << "Product ID"
                 << setw(30) << left << "Name"
                 << setw(15) << left << "Price" << endl;
            cout << "-------------------------------------------------------\n";

            cout << setw(15) << left << items[totalQty].getProductID()
                 << setw(30) << left << items[totalQty].getProductName()
                 << setw(15) << left << items[totalQty].getPrice() << endl;

            cout << endl << "Product added successfully!" << endl;

            totalQty++; 
        } else {
            cout << "Shopping Cart is full! Unable to add more products." << endl;
        }
    }

    void viewCart() {
    if (totalQty == 0) {
        cout << "No products added to the cart." << endl;
    } else {
        cout << fixed << setprecision(2);
        cout << endl << "--------------------------------------------------------------------\n";
        cout << "                       Shopping Cart\n";
        cout << "--------------------------------------------------------------------\n";
        cout << setw(15) << left << "Product ID"
             << setw(30) << left << "Name"
             << setw(15) << left << "Price"
             << setw(15) << left << "Quantity" << endl;
        cout << "--------------------------------------------------------------------\n";

        for (int i = 0; i < totalQty; i++) {
            cout << setw(15) << left << items[i].getProductID()
                 << setw(30) << left << items[i].getProductName()
                 << setw(15) << left << items[i].getPrice()
                 << setw(15) << left << quantities[i] << endl;
        }

        cout << "--------------------------------------------------------------------\n";
        cout << "Total Amount: PHP " << totalPrice << endl;
        cout << "--------------------------------------------------------------------\n";
    }
    
    // Prompt to return to the grocery menu
    cout << endl << "Proceeding to the Grocery Menu..." << endl;
    system("pause");
    system("cls");   // Clear the screen after the pause
}

    void displayProductsForCheckout() {

        cout << fixed << setprecision(2);
        cout << endl << "--------------------------------------------------------------------\n";
        cout << "Checkout" << endl;
        cout << "--------------------------------------------------------------------\n";
        cout << setw(15) << left << "Product ID"
             << setw(30) << left << "Name"
             << setw(15) << left << "Price"
             << setw(15) << left << "Quantity" << endl;
        cout << "--------------------------------------------------------------------\n";

        for (int i = 0; i < totalQty; i++) {
            cout << setw(15) << left << items[i].getProductID()
                 << setw(30) << left << items[i].getProductName()
                 << setw(15) << left << items[i].getPrice()
                 << setw(15) << left << quantities[i] << endl;
        }
        cout << "--------------------------------------------------------------------\n";
        cout << "Total Amount: PHP " << totalPrice << endl;
        cout << "--------------------------------------------------------------------\n";
    }

    void checkout() {
        string name, address, phone;

        cout << "\nPlease enter your name: ";
        cin.ignore(); 
        getline(cin, name);

        cout << "Please enter your address: ";
        getline(cin, address);

        cout << "Please enter your phone number: ";
        getline(cin, phone);

        cout << "--------------------------------------------------------------------\n";
        cout << "Customer Details\n";
        cout << "--------------------------------------------------------------------\n";
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Phone: " << phone << endl;
        system("cls");

        cout << "--------------------------------------------------------------------\n";
        cout << endl << "Order Details" << endl;
        cout << "--------------------------------------------------------------------\n";
        cout << setw(15) << left << "Product ID"
             << setw(30) << left << "Name"
             << setw(15) << left << "Price"
             << setw(15) << left << "Quantity" << endl;
        cout << "--------------------------------------------------------------------\n";

        for (int i = 0; i < totalQty; i++) {
            cout << setw(15) << left << items[i].getProductID()
                 << setw(30) << left << items[i].getProductName()
                 << setw(15) << left << items[i].getPrice()
                 << setw(15) << left << quantities[i] << endl;
        }
        cout << "--------------------------------------------------------------------\n";
        cout << "Total Amount: PHP " << totalPrice << endl;
        cout << "--------------------------------------------------------------------\n\n";
                
        cout << "\nYou have successfully checked out the products!\n\n";
        cout << "Proceeding to the Grocery Menu...\n";
        system("pause");
        system("cls");

        totalQty = 0;
        totalPrice = 0.0;
    }

    int getCartQty(){
        return totalQty;
    }
};

int main() {
    Product items[] = {
        Product("A001", "Rice (5kg)", 280.00),
        Product("B002", "Canned Tuna", 45.00),
        Product("C003", "Instant Coffee (50g)", 95.00),
        Product("D004", "Brown Sugar (1kg)", 80.00),
        Product("E005", "Cooking Oil (1L)", 170.00),
        Product("F006", "Pasta Spaghetti (1kg)", 85.00),
        Product("G007", "Tomato Sauce (250g)", 95.00),
        Product("H008", "Dishwashing Liquid (500ml)", 90.00),
        Product("I009", "Toilet Paper (4 rolls)", 120.00),
        Product("J010", "Laundry Detergent (1kg)", 180.00),
    };

    ShoppingCart cart;
    int choice;
    char procToCheckout;
    char addAnother;

    do {
        cout << "--------------------------\n";
        cout << "      Grocery Menu" << endl;
        cout << "--------------------------\n";
        cout << "1 - View Products\n";
        cout << "2 - View Shopping Cart\n";
        cout << "3 - Checkout\n";
        cout << "4 - Exit\n";
        cout << "--------------------------\n";
        cout << endl << "Enter your choice: ";
        cin >> choice;
        system("cls");

        switch (choice) {
            case 1: {
    do {
        string id;
        int qty;
        bool found = false;

        cout << endl << "                   Products" << endl;
        cout << "-----------------------------------------------------\n";
        cout << setw(15) << left << "Product ID"
             << setw(30) << left << "Name"
             << setw(15) << left << "Price" << endl;
        cout << "-----------------------------------------------------\n";

        cout << fixed << setprecision(2);
        for (int i = 0; i < 10; i++) {
            cout << setw(15) << left << items[i].getProductID()
                 << setw(30) << left << items[i].getProductName()
                 << setw(15) << left << items[i].getPrice() << endl;
        }

        do {
            cout << endl << "Enter the Product ID to add to cart: ";
            cin >> id;

            for (char &c : id) {
                c = toupper(c); // Ensure product ID is capitalized
            }

            for (int i = 0; i < 10; i++) {
                if (items[i].getProductID() == id) {
                    cout << "Enter Quantity: ";
                    cin >> qty;

                    cart.addToCart(items[i], qty);
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << endl << "Product ID not found!\n";
            }

        } while (!found);  // Repeat until valid product ID is found

                cout << endl << "Do you want to add another product to the shopping cart? (Y/N): ";
                cin >> addAnother;
                cout << endl;

    } while (toupper(addAnother) == 'Y');  // Repeat if the user wants to add another product

    cout << "Proceeding to the Grocery Menu...\n";
    system("pause");
    system("cls");
    break;
}
            case 2:
                cart.viewCart();

            if (cart.getCartQty() > 0) {
                cart.displayProductsForCheckout();

                cout << endl << "Do you want to checkout all the products? (Y/N): ";
                cin >> procToCheckout;

        if (toupper(procToCheckout) == 'Y') {
                cart.displayProductsForCheckout();
                cart.checkout();
        }
    }
    break;

            case 3:
                if(cart.getCartQty() == 0){
                    cout << "No products to checkout!" << endl <<endl;
                    cout << "Proceeding to the Grocery Menu..." << endl;
                }
                //else{
                    system("pause");
                    system("cls");
                    //cart.checkout();
                //}
                break;

            case 4:
                cout << "Thank you!\n\nExiting...";
                break;

            default:
                cout << "Invalid input! Please enter numbers 1 to 4 only." << endl <<endl;
                cout << "Proceeding to the Grocery Menu...\n";
                system("pause");
                system("cls");
        }

    } while (choice != 4);

    return 0;
}