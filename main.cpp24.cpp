// library declaration
#include <iostream>
#include <string>

using namespace std;

// set max array
const int MAX = 50;


// array declaration
int transactionNo[50];
int quantitySold[50];
double pricePerUnit[50];
string cookieType[50];
string customerName[50];

// set count back to 0
int countTransaction = 0;

//[1]recordsales function start
void recordSales()
{
    if (countTransaction < 50)
    {
        cout << "Enter the transaction detail: " << endl;
        // User enter detail about customer
        cout << "Transaction No: ";
        cin >> transactionNo[countTransaction];
        // to make sure the transactionNo not less than 0
        if (transactionNo[countTransaction] < 0)
        {
            cout << "Transaction No must be greater than 0 \n";
            return recordSales();
        }
        cin.ignore();

        cout << "Cookie Type: ";
        cin >> cookieType[countTransaction];

        cout << "Quantity sold: ";
        cin >> quantitySold[countTransaction];
        if (quantitySold[countTransaction] < 0)
        {
            cout << "Quantity must be greater than 0 \n";
            return recordSales();
        }

        cout << "Price per unit: ";
        cin >> pricePerUnit[countTransaction];
        cin.ignore();
        if (pricePerUnit[countTransaction] < 0)
        {
            cout << "Price per unit must be greater than 0 \n";
            return recordSales();
        }

        cout << "Customer Name: ";
        getline(cin, customerName[countTransaction]);
        countTransaction++;
        // enter customer details end
    }
    else
    {
        cout << "Transaction maximum reached" << endl;
    }
}
//[1]recordsales function end

//[2]calculatetotalrevenue function start
double calculateTotalRevenue()
{
    double total = 0.0;
    for (int i = 0; i < countTransaction; i++)
    {
        /* i is for index
        total declaration is to sum for all quantitySold * pricePerUnit depends on which index*/
        total += quantitySold[i] * pricePerUnit[i];
    }
    return total;
}
//[2]totalrevenue function end

//[3]displaysalesrecords function start
void displaySalesRecords()
{
    if (countTransaction < 1)
    {
        cout << "There's is no Record Sales \n";
    }
    else
    {
        cout << "Sales Records:" << endl;
        cout << "\n";
        for (int i = 0; i < countTransaction; i++)
        {
            // use for loop to display all data that contain inside of array
            cout << "-----------------------------------"<<endl;
            cout<<"transactionNo :" << transactionNo [i] <<endl; 
			cout<<"cookieType :"<< cookieType [i] <<endl;
			cout<<"quantitySold :"<< quantitySold [i] <<endl;
			cout<<"pricePerUnit:"<< " RM:" << pricePerUnit [i] <<endl; 
			cout<<"customerName:"<< customerName [i] << endl;
			cout << "-----------------------------------"<<endl;
        }
        for (int i = 0; i < 100; i++);
        

    }
}
//[3]displaysalesrecords function end

//[4]displaysalesrecords function start
// pass parameter
void findSalesByCustomer(string customersearch)
{

    cout << "\n";
    // function start to search for customername
    bool foundcustomer = false;
    for (int i = 0; i < countTransaction; i++)
    {
        if (customerName[i] == customersearch)
        {
            foundcustomer = true;
            cout << "-----------------------------------"<<endl;
            cout<<"transactionNo :" << transactionNo [i] <<endl; 
			cout<<"cookieType :"<< cookieType [i] <<endl;
			cout<<"quantitySold :"<< quantitySold [i] <<endl;
			cout<<"pricePerUnit:"<< " RM:" << pricePerUnit [i] <<endl; 
			cout<<"customerName:"<< customerName [i] << endl;
			cout << "-----------------------------------"<<endl; 
            
        }
    }
    if (!foundcustomer)
    {
        cout << " \n  No sales record for customer :" << customerName << "\n"
             << endl;
    }
}
//[4]displaysalesrecords function end

//[5] updatesalesrecords function start
void updateSalesRecord(int updatetrans)
{
    for (int i = 0; i < countTransaction; i++)
    {
        if (transactionNo[i] == updatetrans)
        {
            cout << "Enter new detail " << updatetrans << ": " << endl;

            // entering all new data for the customer detail
            cout << "Cookie type: ";
            cin >> cookieType[i];

            cout << "Quantity Sold: ";
            cin >> quantitySold[i];

            cout << "Price Per Unit: ";
            cin >> pricePerUnit[i];
            cin.ignore();

            cout << "Customer Name: ";
            getline(cin, customerName[i]);

            cout << "Sales record updated successfully.\n";
            return;
        }
    }
    cout << "The transaction not found in the system" << endl;
}
//[5] updatesalesrecords function end

int main()
{

    int choice;

    // using do while loop to complete the system that user will choose the option until user hit number '6'
    do
    {
    	cout << "\nWELCOME TO SUKA DESSERT\n" <<endl;
         	 
        cout << "[1] Record Sales\n"<< endl;
        cout << "[2] Calculate Total Revenue\n"<< endl;
        cout << "[3] Display Sales Records\n"<<endl;
        cout << "[4] Find Sales by Customer\n"<<endl;
        cout << "[5] Update Sales Record\n"<<endl;
        cout << "[6] Exit\n"<<endl;
        cout << "Enter your choice: "<<endl;
        cin >> choice;
        cout << "\n";
        switch (choice)
        {
        case 1:
            recordSales();
            break;
        case 2:
            cout << "Total Revenue: RM" << calculateTotalRevenue() << "\n";
            break;
        case 3:
            displaySalesRecords();
            break;
        case 4:
        {
            string customersearch;
            cout << "Enter customer name: ";
            cin.ignore();
            getline(cin, customersearch);
            //enter same name in the array and beware for capital letter
            findSalesByCustomer(customersearch);
        }
        break;
        case 5:
        {
            int updatetrans;
            cout << "Enter transaction number to update: ";
            cin >> updatetrans;
            // using transactionNo = updatetrans to complete the updatesalesrecord()
            updateSalesRecord(updatetrans);
        }
        break;
        case 6:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);
    return 0;
}
