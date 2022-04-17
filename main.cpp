#include <iostream>
#include <vector>
using namespace std;
// CLASSES
class Products {

private:
    //Data members
    string productName;
    string productID;
    float productPrice = 0;
    static int numOfProducts; //keep a count of total number of products

public:

    //Default constructor
    Products(){
        productName = "Undetermined";
        //cout << "Default constructor called" << endl;
    }

    //Parametized constructor
    Products(string pname, string pID, float pPrice){
        productName = pname;
        productID = pID;
        productPrice = pPrice;

    }
    //Member functions
    void setData(string name, string productID, float price) {
        this->productName = name;
        this->productID = productID;
        this->productPrice = price;

    }

    void displayData(){
        cout << "--- Product details ---" << endl;
        cout << "Name: " << productName << endl;
        cout << "ID: " << productID << endl;
        cout << "Price: " << productPrice << endl;
    }

};

class Bank{
public:
    string username;
    float bankBalance = 0;
    float lastTransaction;

    //Parametized constructor
    Bank(string name){
        username = name;
        bankBalance = 0;
    }
    void setName(string name){
        this->username = name;
    }
    string getUserName(){
        return username;
    }
    void setBalance(float balance){
        this->bankBalance = balance;
    }

    float getBalance(){
        return bankBalance;
    }

    void depositIntoAccount(){
        int deposit;
        cout << "Write deposit amount: ";
        cin >> deposit;
        lastTransaction = +deposit;
        bankBalance += deposit;
        cout << "New balance: " << bankBalance << endl;
    }

    void withdrawFromAccount(){
        int withdraw;
        cout << "Enter withdraw amount: ";
        cin >> withdraw;
        if(bankBalance >= withdraw){
            bankBalance -= withdraw;
            lastTransaction = -withdraw;
            cout << "You have successfully withdrawn " << withdraw << " from your account"<< endl;
            cout << "New balance " << bankBalance << endl;
        }else{
            cout << "Your balance is " << bankBalance << endl;
            cout << "Please enter a valid amount!";
        }
    }

    void lastTransactions(){
        if(lastTransaction>0){
            cout << "Last trasaction was + " << lastTransaction << endl;
        }
        else if (lastTransaction<0){
            cout << "Last transaction was " << lastTransaction << endl;
        }
        else{
            cout << "You dont have any transaction yet!" << endl;
        }
    }

};

//FUNCTIONS
static Products addProducts(string name, string productID, float price){
    Products productx(name,productID,price);
    return productx;
}
static void mainMenu(){
    cout << "\n-----MAIN MENU-------" << endl;
    cout << " Options: " << endl;
    cout << " 1. Shopping menu" << endl;
    cout << " 2. Product setting menu"<< endl;
    cout << " 3. Bank " << endl;
    cout << " 4. Shopping cart/recip " << endl;
    cout << " 5. Personal account " << endl;    // Deposit, transfer, see last transactions, edit personal account
    cout << " 6. Exit " << endl;
    cout << "Please enter your option: ";
}
static void shoppingMenu(){}
static void productSettingMenu(vector<Products>allproducts){
    int userOption;
    cout << "\n---- AWESOME-PRODUCT SETTING MENU----" << endl;
    cout << "Option: " << endl;
    cout << "1. Add product" << endl;
    cout << "2. Delete product" << endl;    //Still not finished
    cin >> userOption;

    switch (userOption) {
        case 1:
            string pName, pID;
            float pPrice;
            Products productUserOption;
            cout << "ADD PRODUCT: " << endl;
            cout << "Please enter product name";
            cin >> pName;
            cout << "\nEnter product ID (str): ";
            cin >> pID;
            cout << "\nPrice: ";
            cin >> pPrice;
            productUserOption = addProducts(pName, pID, pPrice); // Gives back product object
            allproducts.push_back(productUserOption); //Adds the new product to the end of the list
            cout << "You have now successfully added a new product!" << endl;
            break;
    }

}
static void shoppingCart(){}
static void shoppingRecip(){}
static void personalAccount(){}

static void bankMainMenu(Bank userName){
    int userOption;
    cout << " -----WELCOME TO AWESOME-BANK ----" << endl;
    cout << "Options: " << endl;
    cout << "1. See balance" << endl;
    cout << "2. Deposit money" << endl;
    cout << "3. Withdraw money" << endl;
    cout << "4. See last transactions " << endl;
    cout << "5. Exit " << endl;


    bool bankMenu = true;
    do{
        cin >> userOption;
        switch (userOption) {
            case 1:
                cout << "Your balance is: " << userName.getBalance() << endl; break;
            case 2:
                userName.depositIntoAccount(); break;
            case 3:
                userName.withdrawFromAccount(); break;
            case 4:
                userName.lastTransactions(); break;
            case 5:
                bankMenu = false; break;
            default:
                cout << "Please try a valid option! " << endl;break;
        }
    } while(bankMenu);

}

int main() {

    vector<Products> allProducts;
    //Make an empty product
    Products product1, product2, product3("Milk", "milk", 1.5);
    //Set the values with setData()
    product2.setData("Coco", "coco", 1.0);
    //call display function to see its details
    product1.displayData();
    product2.displayData();
    product3.displayData();

    // Bank user

    Bank user1("Natcha");
    Bank *bank_ptr = &user1;
    int userMainMenuOption;
    //Program starts from here
    cout << "-------WELCOME TO AWESOME-APPLICATION--------" << endl;
    mainMenu();
    bool mainMenu = true;
    do{
        cin >> userMainMenuOption;
        switch (userMainMenuOption) {
            case 1:
                cout << " SHOPPING MENU" << endl; break;
            case 2:
                productSettingMenu(allProducts);  // Auto adds new products to the list
                break;
            case 3:
                bankMainMenu(user1);
                break;
            case 4:
                shoppingRecip(); break;
            case 5:
                cout << "Goodbye!" << endl;
                mainMenu = false; break;
            default:
                cout << "Please try a valid option" << endl; break;
        }
    } while(mainMenu);


    return 0;
}
