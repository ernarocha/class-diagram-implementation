#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;

class Order {
private:
    struct OrderDetail {
        string name;
        string address;
        double totalPrice;
        string productIDs[100];
        string products[100];
        double prices[100];
        int quantities[100];
        int productCount;
    };

    OrderDetail items[100];
    int orderCount;

public:
    Order() : orderCount(0) {}

    int counter;

    void setOrderDetails(string name, string address, double price, string product[], string productIDs[], double productPrices[], int quantity[], int productCount, int orderNum) {
        items[orderCount].name = name;
        items[orderCount].address = address;
        items[orderCount].totalPrice = price;
        items[orderCount].productCount = productCount;

        for (int i = 0; i < productCount; ++i) {
            items[orderCount].products[i] = product[i];
            items[orderCount].productIDs[i] = productIDs[i];
            items[orderCount].prices[i] = productPrices[i];
            items[orderCount].quantities[i] = quantity[i];
        }

        counter++;
        orderCount++; 
        cout << "Order Count: " << counter << endl;
    }

    void displayOrders() {

        cout << "--------------------------------------------------------------------\n";
        cout << "Orders" << endl;
        cout << "--------------------------------------------------------------------\n";

        for (int i = 0; i < orderCount; i++) {
            cout << endl << "Order ID: " << (i + 1) << endl;

            cout << "Total Amount: PHP " << fixed << setprecision(2) << items[i].totalPrice << endl;
            cout << "Order Details:" << endl;
            cout << string(67, '-') << endl;
            cout << left << setw(13) << "Product ID" << setw(35) << "Product Name" << setw(10) << "Price" << setw(10) << "Quantity" << endl;
            cout << string(67, '-') << endl;

        for (int j = 0; j < items[i].productCount; j++) {
            cout << left << setw(13) << items[i].productIDs[j] << setw(35) << items[i].products[j] << setw(10) << items[i].prices[j] << setw(10) << items[i].quantities[j] << endl;
        }
        cout << string(67, '-') << endl;
        }
    }

    int getOrderCount() {
    return orderCount;
    }
};

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
    Order order;

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

            system("cls");
            cout << "-------------------------------------------------------\n";
            cout << "Selected Product:";
            cout << "\n-------------------------------------------------------\n";
            cout << fixed << setprecision(2);
            cout << setw(15) << left << "Product ID"
                 << setw(30) << left << "Name"
                 << setw(15) << left << "Price" << endl;
            cout << "-------------------------------------------------------\n";

            cout << setw(15) << left << items[totalQty].getProductID()
                 << setw(30) << left << items[totalQty].getProductName()
                 << setw(15) << left << items[totalQty].getPrice() << endl;

            cout << endl
                 << "Product added successfully!" << endl;

            totalQty++;
        } else {
            cout << "Shopping Cart is full! Unable to add more products." << endl;
        }
    }

    void viewCart() {
        if (totalQty == 0) {
            cout << "No products added to the cart." << endl;
            return;
        } else {
            cout << fixed << setprecision(2);
            cout << endl
                 << "--------------------------------------------------------------------\n";
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
    }

    void displayProductsForCheckout() {
        cout << fixed << setprecision(2);
        cout << endl
             << "--------------------------------------------------------------------\n";
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

    int orderNum;
    int orderCounter = 0;

    void checkout() {
        string name, address, phone;
        string productNames[10], productIDs[10];
        double productPrices[10];
        int productQuantities[10];
        int orderNum = 1;

        cout << "\nPlease enter your name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Please enter your address: ";
        getline(cin, address);

        cout << "Please enter your phone number: ";
        getline(cin, phone);
        system("cls");

        cout << "--------------------------------------------------------------------\n";
        cout << "Customer Details\n";
        cout << "--------------------------------------------------------------------\n";
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Phone: " << phone << endl << endl;

        cout << "--------------------------------------------------------------------\n";
        cout << "Order Details" << endl;
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

            productIDs[i] = items[i].getProductID();
            productNames[i] = items[i].getProductName();
            productPrices[i] = items[i].getPrice();
            productQuantities[i] = quantities[i];
        }

        order.setOrderDetails(name, address, totalPrice, productNames, productIDs, productPrices, productQuantities, totalQty, orderNum);

        cout << "--------------------------------------------------------------------\n";
        cout << "Total Amount: PHP " << totalPrice << endl;
        cout << "--------------------------------------------------------------------\n\n";

        cout << "You have successfully checked out the products!\n\n";
        cout << "Proceeding to the Grocery Menu..." << endl;
        system("pause");
        system("cls");
        
        totalQty = 0;
        totalPrice = 0.0;
        orderNum++;
        orderCounter++;
        }

        int getCartQty() {
            return totalQty;
        }

        int getOrderNum() {
            return orderNum;
        }
        int getOrderCounter() {
            return orderCounter;
    }

        void displayOrders() {
            order.displayOrders();
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
    Order order;
    int choice;
    char procToCheckout;
    char addAnother;
    int numOfOrders = order.getOrderCount();

    do
    {
        cout << "--------------------------\n";
        cout << "      Grocery Menu" << endl;
        cout << "--------------------------\n";
        cout << "1 - View Products\n";
        cout << "2 - View Shopping Cart\n";
        cout << "3 - View Orders\n";
        cout << "4 - Exit\n";
        cout << "--------------------------\n";
        cout << endl
             << "Enter your choice: ";
        cin >> choice;
        system("cls");

        switch (choice) {
            case 1: {
                do {
                    string id;
                    int qty;
                    bool found = false;

                    cout << "-----------------------------------------------------\n";
                    cout << "                     Products" << endl;
                    cout << "-----------------------------------------------------\n";
                    cout << setw(15) << left << "Product ID"
                        << setw(30) << left << "Name"
                        << setw(15) << left << "Price" << endl;
                    cout << "-----------------------------------------------------\n";

                    cout << fixed << setprecision(2);
                    for (int i = 0; i < 10; i++)
                    {
                        cout<< setw(15) << left << items[i].getProductID()
                            << setw(30) << left << items[i].getProductName()
                            << setw(15) << left << items[i].getPrice() << endl;
                    }
                    cout << "-----------------------------------------------------\n";

                    do {
                        cout << endl << "Enter the Product ID to add to cart: ";
                        cin >> id;

                        for (char &c : id) {
                            c = toupper(c);
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

                    } while (!found);

                        cout << endl << "Do you want to add another product to the shopping cart? (Y/N): ";
                        cin >> addAnother;
                        cout << endl;

                    } while (toupper(addAnother) == 'Y');
                        cout << "Proceeding to the Grocery Menu...\n";
                        system("pause");
                        system("cls");
                        break;
                    }

            case 2:
                cart.viewCart();

                if (cart.getCartQty() > 0) {
                cout << endl << "Do you want to checkout all the products? (Y/N): ";
                cin >> procToCheckout;

                if (toupper(procToCheckout) == 'Y') {
                    system("cls");
                    cart.displayProductsForCheckout();
                    cart.checkout();
                } else {
                    cout << endl << "Proceeding to the Grocery Menu..." << endl;
                    system("pause");
                    system("cls");
                }
            } else {
                cout << endl << "Proceeding to the Grocery Menu..." << endl;
                system("pause");
                system("cls");
            }
            break;

            case 3:
                numOfOrders = cart.getOrderCounter();

                if (numOfOrders == 0) {
                    cout << "No orders yet!" << endl;
                } else {
                    cart.displayOrders();
                }
                cout << endl << "Proceeding to the Grocery Menu..." << endl;
                system("pause");
                system("cls");
                break;

            case 4:
                cout << "Thank you!\n\nExiting...";
                break;

            default:
                cout << "Invalid input! Please enter numbers 1 to 4 only. " << endl << endl;
                cout << "Proceeding to the Grocery Menu...\n";
                system("pause");
                system("cls");
            }
            
    } while (choice != 4);

    return 0;
}