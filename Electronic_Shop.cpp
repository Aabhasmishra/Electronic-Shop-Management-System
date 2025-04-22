#include<iostream>
#include<fstream> /* X10  */
#include<conio.h>
#include<windows.h>
using namespace std;
class user;
class electronic;
void display();
void gotoxy(short x, short y);

class user
{
    protected:
    string username, password, name, gender, account_type, country, currency, state, city, area, chAc; // Ac: Account
    int age, plot_num, value=0, visit=0;
    long long int mobile_num, city_pincode;
    public:
        void id_password(void);
        void add_account(void);
        void view_profile(void);
        void change_profile(void);
};

class electronic : public user
{
    protected:
        string product, PrName, display_type, display_size, screen_resolution, front_camera, rare_camera, battery, processor, GPU, SSD, color, warranty, os;
        int  product_no=0, pr_no, GPU_memory, ram, discount;
        long long int price;
    public:
        electronic(void);
        void main_menu();
        void Product_list();
        void currency_change();
        void ask_for_buy();
        void change_product();
        void search_product();
        void add_laptop();
        void laptop_list();
        void display_laptop();
        void add_mobile();
        void mobile_list();
        void display_mobile();
        void add_headphone();
        void headphone_list();
        void display_headphone();
        void add_smartwatch();
        void smartwatch_list();
        void display_smartwatch();
        void add_pendrive();
        void pendrive_list();
        void display_pendrive();
        void add_mouse();
        void mouse_list();
        void display_mouse();
        void receipt(string, int, long long int, int, int);
};

void display()
{
    cout<<"\n\n\t\t\t\t\t------------------------------------------------------------"<<endl;
    cout<<"\t\t\t\t\t\t\t     Electronics Shop"<<endl;
    cout<<"\t\t\t\t\t------------------------------------------------------------"<<endl<<endl;
}

void gotoxy(short x, short y)
{
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

electronic::electronic(void)
    {
        int str1;
        string str2;
        ifstream PrNo;
        PrNo.open("Product.txt");
        while(PrNo.eof()==0)
        {
            PrNo>>str1;
            getline(PrNo,str2);
        }
        PrNo.close();
        product_no = str1;
    }

void user::id_password(void)
{
    system("cls");
    int choose;
    string chPa;
    cout<<"\n\n\t\t\t\t\t\t     ###################################";
    cout<<"\n\t\t\t\t\t\t     |   Welcome to Electronics Shop   |";
    cout<<"\n\t\t\t\t\t\t     ###################################"<<endl<<endl;
    X1:
    cout<<"\t\t\t\t\t\t\t1. Enter your id and password"<<endl<<endl;
    cout<<"\t\t\t\t\t\t\t2. Create a new account"<<endl<<endl;
    cout<<"\t\t\t\t\t\t\tChoose 1 or 2: ";
    cin>>choose;
    X5:
    ifstream CheckAc;
    CheckAc.open("Account.txt");

    switch(choose)
    {
        case 1:
            cout<<endl<<"\t\t\t\t\t\t     Enter username and password"<<endl<<"\t\t\t\t\t\t     Enter Username: ";
            cin>>username;
            cout<<"\t\t\t\t\t\t     Enter Password: ";
            cin>>password;

            while(CheckAc.eof()==0)
            {
                CheckAc>>chAc>>chPa;
                    if(chAc == username){
                        if(chPa == password){
                            cout<<"\t\t\t\t\t\t     Login successfully"<<endl;
                            CheckAc>>account_type>>name>>country>>currency>>age>>gender>>mobile_num>>state>>city>>city_pincode>>area>>plot_num;
                            CheckAc.close();
                            cout<<"\t\t\t\t\t\t     Press any key to continue......";
                            getch();
                            goto X7;
                            break;
                        }
                        else{
                            cout<<"\t\t\t\t\t\t     Your Password is incorrect"<<endl<<endl<<"\t\t\t\t\t\t     Please Enter your username and password again"<<endl;
                            goto X5;
                        }
                    }
                    else{
                        getline(CheckAc, chAc);
                    }
            }
            CheckAc.close();
            cout<<endl<<"\t\t\t\t\t\t     Couldn't find your account. Try another"<<endl;
            goto X5;
            X7:
            break;
        case 2:
            add_account();
            break;
        default:
            cout<<"\n\t\t\t\t\t\t      -----> Chose valid number <-----"<<endl;
            goto X1;
    }
}

void user::add_account(){
    system("cls");
    int choose;
    int choose1;
    int choose2;
    if(value==0){
        cout<<"\n\n\t\t\t\t\t------------------------------------------------------------"<<endl;
        cout<<"\t\t\t\t\t\t\t    Create a new account"<<endl;
        cout<<"\t\t\t\t\t------------------------------------------------------------"<<endl<<endl;
    }
    else{
        cout<<"\n\n\t\t\t\t\t------------------------------------------------------------"<<endl;
        cout<<"\t\t\t\t\t\t\t    Modify Account"<<endl;
        cout<<"\t\t\t\t\t------------------------------------------------------------"<<endl<<endl; 
        goto X1;
    }
    X6:
    cout<<"\t\t\t\t\t\t   Which type of account you want to create?"<<endl<<"\t\t\t\t\t\t   1. Buyer account"<<endl<<"\t\t\t\t\t\t   2. Administrator account"<<endl<<"\t\t\t\t\t\t   Choose 1 or 2: ";
    cin>>choose1;

    switch (choose1)
    {
    case 1:
        account_type = "B";
        break;

    case 2:
        account_type = "A";
        break;
    
    default:
        cout<<"\n\t\t\t\t\t\t   Choose valid number"<<endl;
        goto X6;
        break;
    }
    X1:
    cout<<"\t\t\t\t\t\t   Enter your name: ";
    cin>>name;
    X:
    cout<<endl<<"\t\t\t\t\t\t   Choose your Country and Currency"<<endl<<endl;
    cout<<"\t\t\t\t\t\t   1. India - Indian Rupee\n\t\t\t\t\t\t   2. United States - United States Dollar\n\t\t\t\t\t\t   3. Japan - Japanese Yen"<<endl<<endl;
    cout<<"\t\t\t\t\t\t   Choose from 1 to 3: ";
    cin>>choose2;

    switch (choose2)
    {
    case 1:
        country = "India";
        currency = "Rupees";
        break;
        
    case 2:
        country = "United_States";
        currency = "Dollar";
        break;

    case 3:
        country = "Japan";
        currency = "Yen";
        break;
    
    default:
        system("cls");
        if(value==1){
            cout<<"\n\t\t\t\t\t\t   ---> Choose valid number <---"<<endl;
            goto X;
        }
        cout<<"\n\n\t\t\t\t\t------------------------------------------------------------"<<endl;
        cout<<"\t\t\t\t\t\t\t    Creat a new account"<<endl;
        cout<<"\t\t\t\t\t------------------------------------------------------------"<<endl<<endl;

        cout<<"\t\t\t\t\t\t   Which type of account you want to creat?"<<endl<<"\t\t\t\t\t\t   1. Buyer account"<<endl<<"\t\t\t\t\t\t   2. Administrator account"<<endl<<"\t\t\t\t\t\t   Choose 1 or 2: "<<choose1<<endl;
        cout<<"\t\t\t\t\t\t   Enter your name: "<<name<<endl;
        cout<<"\n\t\t\t\t\t\t   ---> Choose valid number <---"<<endl;
        goto X;
        break;
    }

    cout<<"\t\t\t\t\t\t   Enter your age: ";
    cin>>age;
    X3:
    cout<<endl<<"\t\t\t\t\t\t   Choose your Gender:"<<endl<<"\t\t\t\t\t\t   1. Male"<<endl<<"\t\t\t\t\t\t   2. Female"<<endl;
    cout<<"\t\t\t\t\t\t   Choose 1 or 2: ";
    cin>>choose;

    if(choose==1){
        gender = "Male";
    }
    else if(choose==2){
        gender = "Female";
    }
    else{
        cout<<"\n\t\t\t\t\t\t      -----> Chose valid number <-----";
        goto X3;
    }

    cout<<endl<<"\t\t\t\t\t\t   Enter your mobile number: ";
    cin>>mobile_num;
    cout<<endl<<"\t\t\t\t\t\t   Enter your Address: ";
    cout<<endl<<"\t\t\t\t\t\t   Enter your state: ";
    cin>>state;
    cout<<"\t\t\t\t\t\t   Enter your city name: ";
    cin>>city;
    cout<<"\t\t\t\t\t\t   Enter your city pin code: ";
    cin>>city_pincode;
    cout<<"\t\t\t\t\t\t   Enter your colony or society name: ";
    cin>>area;
    cout<<"\t\t\t\t\t\t   Enter your plot number: ";
    cin>>plot_num;
    X4:
    cout<<endl<<"\t\t\t\t\t\t   Creat username and password"<<endl<<"\t\t\t\t\t\t   Creat Username: ";
    cin>>username;
    cout<<"\t\t\t\t\t\t   Creat Password: ";
    cin>>password;

    ifstream CheckAc;
    CheckAc.open("Account.txt");
    
    while(CheckAc.eof()==0)
    {
        CheckAc>>chAc;
        if(chAc != username){
            getline(CheckAc, chAc);
        }
        else{
            cout<<"\n\t\t\t\t\t\t   That username is Taken. Please try another.";
            goto X4;
        }
    }
    CheckAc.close();
    if(value==0){
        cout<<"\n\t\t\t\t\t\t   Your account is created successfully";
    }

    ofstream NewAc;
    NewAc.open("Account.txt", ios::app);
    NewAc<<username<<" "<<password<<" "<<account_type<<" "<<name<<" "<<country<<" "<<currency<<" "<<age<<" "<<gender<<" "<<mobile_num<<" "<<state<<" "<<city<<" "<<city_pincode<<" "<<area<<" "<<plot_num<<endl;
    NewAc.close();
}

void user::view_profile()
{
    system("cls");
    display();
    cout<<"\t\t\t\t\t\t   ------- Your Profile -------"<<endl<<endl;
    cout<<"\t\t\t\t\t\t\tName: "<<name<<endl;
    cout<<"\t\t\t\t\t\t\tGender: "<<gender<<endl;
    cout<<"\t\t\t\t\t\t\tAge: "<<age<<endl;
    cout<<"\t\t\t\t\t\t\tCountry: "<<country<<endl;
    cout<<"\t\t\t\t\t\t\tCurrency: "<<currency<<endl;
    cout<<"\t\t\t\t\t\t\tMobile Number: "<<mobile_num<<endl<<endl;
    cout<<"\t\t\t\t\t\t   ------- Your Address -------"<<endl<<endl;
    cout<<"\t\t\t\t\t\t\tState: "<<state<<endl;
    cout<<"\t\t\t\t\t\t\tCity Name: "<<city<<endl;
    cout<<"\t\t\t\t\t\t\tCity pin code: "<<city_pincode<<endl;
    cout<<"\t\t\t\t\t\t\tColony or Society name: "<<area<<endl;
    cout<<"\t\t\t\t\t\t\tPlot Number: "<<plot_num<<endl<<endl;
    cout<<"\t\t\t\t\t\t\tPress any key to continue......";
    getch();
}

void user::change_profile()
{
    system("cls");
    string username2, a, line;
    username2 = username;
    add_account();

    fstream getdata;
    fstream putdata;
    getdata.open("Account.txt", ios::in);
    putdata.open("Account2.txt", ios::app|ios::out);
    getdata>>a;
    getline(getdata, line);

    while(getdata.eof()==0)
    {
        if(a==username2){
            cout<<endl<<"\t\t\t\t\t\t   Your account is modified sucessfully"<<endl;
        }
        else{
            putdata<<a<<line<<endl;
        }
        getdata>>a;
        getline(getdata, line);
    }
    getdata.close();
    putdata.close();
    remove("Account.txt");
    rename("Account2.txt", "Account.txt");
    cout<<"\t\t\t\t\t\t   Press any key to continue......";
    getch();
}

void electronic::main_menu()
{
    system("cls");
    int choose;
    cout<<"\n\n\t\t\t\t\t------------------------------------------------------------"<<endl;
    cout<<"\t\t\t\t\t\t\t        Main Menu"<<endl;
    cout<<"\t\t\t\t\t------------------------------------------------------------"<<endl<<endl;
    cout<<"\t\t\t\t\t\t\t  1. Product List"<<endl<<endl;
    cout<<"\t\t\t\t\t\t\t  2. Search Product"<<endl<<endl;
    if(account_type=="B"){
        cout<<"\t\t\t\t\t\t\t  3. View Profile"<<endl<<endl;
        cout<<"\t\t\t\t\t\t\t  4. Modify Profile"<<endl<<endl;
        cout<<"\t\t\t\t\t\t\t  5. Exit"<<endl<<endl;
        X1:
        cout<<"\t\t\t\t\t\t\t  Choose from 1 to 5: ";
    }
    else{
        cout<<"\t\t\t\t\t\t\t  3. Add Product"<<endl<<endl;
        cout<<"\t\t\t\t\t\t\t  4. Modify Product"<<endl<<endl;
        cout<<"\t\t\t\t\t\t\t  5. Delete Product"<<endl<<endl;
        cout<<"\t\t\t\t\t\t\t  6. View Profile"<<endl<<endl;
        cout<<"\t\t\t\t\t\t\t  7. Change Profile"<<endl<<endl;
        cout<<"\t\t\t\t\t\t\t  8. Exit"<<endl<<endl;
        X2:
        cout<<"\t\t\t\t\t\t\t  Choose from 1 to 8: ";
    }
    cin>>choose;
    if(account_type=="B" && (choose<1 || choose>5)){
        cout<<"\n\t\t\t\t\t\t   -----> Enter valid number <------"<<endl<<endl;
        goto X1;
    }
    switch(choose)
    {
        case 1:
            Product_list();
            break;
        case 2:
            search_product();
            main_menu();
            break;
        case 3:
            if(account_type=="B"){
                view_profile();
            }
            else if(account_type=="A"){
                value=1;
                Product_list();
            }
            value=0;
            main_menu();
            break;
        case 4:
            if(account_type=="B"){
                value=1;
                change_profile();
            }
            else if(account_type=="A"){
                value=2;
                Product_list();
                change_product();
            }
            value=0;
            main_menu();
            break;
        case 5:
            if(account_type=="B"){
                exit(0);
            }
            else if(account_type=="A"){
                value=3;
                Product_list();
                change_product();
            }
            value=0;
            main_menu();
            break;
        case 6:
            view_profile();
            main_menu();
            break;
        case 7:
            value=1;
            change_profile();
            value=0;
            main_menu();
            break;
        case 8:
            exit(0);
            break;
        default:
            cout<<"\n\t\t\t\t\t\t   -----> Enter valid number <------"<<endl<<endl;
            if(account_type=="B"){
                goto X1;
            }
            else{
                goto X2;
            }
            break;
    }
}

void electronic::search_product()
{
    int a;
    char pr_type;
    string name1, name2;
    system("cls");
    display();
    X:
    cout<<"\t\t\t\t\t\t    ------- Search Product -------"<<endl<<endl;
    cout<<"\t\t\t\t\t\t  Enter the name of product: ";
    cin>>name1;
    cout<<endl;
    ifstream SearchPr;
    SearchPr.open("Product.txt");
    while(SearchPr.eof()==0)
    {
        SearchPr>>a>>pr_type>>name2;
        if(name1==name2){
            goto X1;
        }
        getline(SearchPr, name2);
    }
    if(a==product_no){
        cout<<"\t\t\t\t\t\t  Product not found. Search again"<<endl;
        goto X;
    }
    X1:
    SearchPr.close();

    ifstream displayPr;
    displayPr.open("Product.txt");
    while(displayPr.eof()==0){
        displayPr>>pr_no>>product;
        if(pr_no==a){
            if(product=="L"){
                displayPr>>PrName>>display_type>>display_size>>screen_resolution>>processor>>ram>>GPU>>GPU_memory>>color>>SSD>>os>>warranty>>price>>discount;
                display_laptop();
                break;
            }
            else if(product=="M"){
                displayPr>>PrName>>display_type>>display_size>>screen_resolution>>processor>>rare_camera>>front_camera>>battery>>ram>>color>>SSD>>os>>warranty>>price>>discount;
                display_mobile();
                break;
            }
            else if(product=="H"){
                displayPr>>PrName>>display_size>>GPU>>color>>SSD>>os>>battery>>warranty>>price>>discount;
                display_headphone();
                break;
            }
            else if(product=="W"){
                displayPr>>PrName>>display_type>>display_size>>screen_resolution>>processor>>rare_camera>>front_camera>>color>>GPU>>os>>warranty>>price>>discount;
                display_smartwatch();
                break;
            }
            else if(product=="P"){
                displayPr>>PrName>>SSD>>price>>discount;
                display_pendrive();
                break;
            }
            else if(product=="O"){
                displayPr>>PrName>>display_type>>screen_resolution>>GPU>>color>>warranty>>price>>discount;
                display_mouse();
                break;
            }
        }
        getline(displayPr, name2);
    }
    displayPr.close();
    if(account_type=="B"){
        ask_for_buy();
    }
    cout<<"\t\t\t\t\t\t     Press any key to continue......";
    getch();
}

void electronic::change_product()
{
    int a;
    string b, c, PrName2, line;
    PrName2 = PrName;
    if(value==2){
        if(product=="L"){
            add_laptop();
        }
        else if(product=="M"){
            add_mobile();
        }
        else if(product=="H"){
            add_headphone();
        }
        else if(product=="W"){
            add_smartwatch();
        }
        else if(product=="P"){
            add_pendrive();
        }
        else if(product=="O"){
            add_mouse();
        }
    }

    fstream getdata;
    fstream putdata;
    getdata.open("Product.txt", ios::in);
    putdata.open("Product2.txt", ios::app|ios::out);
    getdata>>a>>b>>c;
    getline(getdata, line);

    while(getdata.eof()==0)
    {
        if(c==PrName2){
            if(value==2){
                cout<<"\n\t\t\t\t\t\t\tYour product modified successfully"<<endl;
            }
            else{
                cout<<"\n\t\t\t\t\t\t\tYour product deleted successfully"<<endl;
            }
        }
        else if(a<pr_no){
            putdata<<a<<" "<<b<<" "<<c<<line<<endl;
        }
        else{
            putdata<<a-1<<" "<<b<<" "<<c<<line<<endl;   
        }
        getdata>>a>>b>>c;
        getline(getdata, line);
    }
    getdata.close();
    putdata.close();
    remove("Product.txt");
    rename("Product2.txt", "Product.txt");
    cout<<"\t\t\t\t\t\t\tPress any key to continue......";
    getch();
}

void electronic::Product_list()
{
    system("cls");
    int choose;
    display();
    if(account_type=="A" && value==1){
        cout<<"\t\t\t\t\t\t     Which product you want to enter?"<<endl<<endl;
    }
    cout<<"\t\t\t\t\t\t   ------- List of Products -------"<<endl<<endl;
    cout<<"\t\t\t\t\t\t\t  1. Laptop"<<endl;
    cout<<"\t\t\t\t\t\t\t  2. Mobile"<<endl;
    cout<<"\t\t\t\t\t\t\t  3. Headphone"<<endl;
    cout<<"\t\t\t\t\t\t\t  4. Smart Watch"<<endl;
    cout<<"\t\t\t\t\t\t\t  5. pendrive"<<endl;
    cout<<"\t\t\t\t\t\t\t  6. Mouse"<<endl<<endl;
    cout<<"\t\t\t\t\t\t\t  Press 0 for back to main menu"<<endl<<endl;
    X:
    cout<<"\t\t\t\t\t\t\t  Choose from 0 to 6: ";
    cin>>choose;

    switch (choose)
    {
    case 0:
        main_menu();
        break;

    case 1:
        if(account_type=="B"){
            laptop_list();
        }
        else if(account_type=="A" && value==0){
            laptop_list();
            Product_list();
        }
        else if(account_type=="A" && value==2){
            laptop_list();
        }
        else if(account_type=="A" && value==3){
            laptop_list();
        }
        else{
            add_laptop();
            Product_list();
        }
        break;

    case 2:
        if(account_type=="B"){
            mobile_list();
        }
        else if(account_type=="A" && value==0){
            mobile_list();
            Product_list();
        }
        else if(account_type=="A" && value==2){
            mobile_list();
        }
        else if(account_type=="A" && value==3){
            mobile_list();
        }
        else{
            add_mobile();
            Product_list();
        }
        break;

    case 3:
        if(account_type=="B"){
            headphone_list();
        }
        else if(account_type=="A" && value==0){
            headphone_list();
            Product_list();
        }
        else if(account_type=="A" && value==2){
            headphone_list();
        }
        else if(account_type=="A" && value==3){
            headphone_list();
        }
        else{
            add_headphone();
            Product_list();
        }
        break;

    case 4:
        if(account_type=="B"){
            smartwatch_list();
        }
        else if(account_type=="A" && value==0){
            smartwatch_list();
            Product_list();
        }
        else if(account_type=="A" && value==2){
            smartwatch_list();
        }
        else if(account_type=="A" && value==3){
            smartwatch_list();
        }
        else{
            add_smartwatch();
            Product_list();
        }
        break;

    case 5:
        if(account_type=="B"){
            pendrive_list();
        }
        else if(account_type=="A" && value==0){
            pendrive_list();
            Product_list();
        }
        else if(account_type=="A" && value==2){
            pendrive_list();
        }
        else if(account_type=="A" && value==3){
            pendrive_list();
        }
        else{
            add_pendrive();
            Product_list();
        }
        break;

    case 6:
        if(account_type=="B"){
            mouse_list();
        }
        else if(account_type=="A" && value==0){
            mouse_list();
            Product_list();
        }
        else if(account_type=="A" && value==2){
            mouse_list();
        }
        else if(account_type=="A" && value==3){
            mouse_list();
        }
        else{
            add_mouse();
            Product_list();
        }
        break;

    
    default:
        cout<<"\t\t\t\t\t\t   -----> Enter valid number <------"<<endl<<endl;
        goto X;
        break;
    }
}

void electronic::currency_change()
{
    if(currency=="Rupees"){
        cout<<"\t\t\t\t\t\t     Oiginal Price: "<<price<<" "<<currency<<endl<<endl;
        cout<<"\t\t\t\t\t\t     Price with discount: "<<price - (price*discount)/100<<" "<<currency<<endl<<endl;
        cout<<"\t\t\t\t\t\t     Saving: "<<(price*discount)/100<<" "<<currency<<endl<<endl;
    }
    else if(currency=="Dollar"){
        price = price*0.013;
        cout<<"\t\t\t\t\t\t     Original Price: "<<price<<" "<<currency<<endl<<endl;
        cout<<"\t\t\t\t\t\t     Price with discount: "<<price - (price*discount)/100<<" "<<currency<<endl<<endl;
        cout<<"\t\t\t\t\t\t     Saving: "<<(price*discount)/100<<" "<<currency<<endl<<endl;
    }
    else{
        price = price*1.64;
        cout<<"\t\t\t\t\t\t     Original Price: "<<price<<" "<<currency<<endl<<endl;
        cout<<"\t\t\t\t\t\t     Price with discount: "<<price - (price*discount)/100<<" "<<currency<<endl<<endl;
        cout<<"\t\t\t\t\t\t     Saving: "<<(price*discount)/100<<" "<<currency<<endl<<endl;
    }
}

void electronic::ask_for_buy()
{
    int choose, quantity;
    X8:
    cout<<"\t\t\t\t\t\t     Do you want to buy this product?"<<endl<<"\t\t\t\t\t\t     1. Yes"<<endl<<"\t\t\t\t\t\t     2. No"<<endl<<"\t\t\t\t\t\t     Choose from 1 or 2: ";
    cin>>choose;
    switch (choose)
    {
    case 1:
        X9:
        cout<<"\t\t\t\t\t\t     Enter quantity: ";
        cin>>quantity;
        if(quantity<1){
            cout<<"\n\t\t\t\t\t\t     -----> Enter valid number <-----"<<endl;
            goto X9;
        }
        cout<<"\t\t\t\t\t\t     Price with discount: "<<quantity*(price - (price*discount)/100)<<" "<<currency<<endl<<endl;
        X10:
        cout<<"\t\t\t\t\t\t     Do you want to buy another product?"<<endl<<"\t\t\t\t\t\t     1. Yes"<<endl<<"\t\t\t\t\t\t     2. No"<<endl<<"\t\t\t\t\t\t     Choose from 1 or 2: ";
        cin>>choose;
        if(choose==1){
            cout<<"\t\t\t\t\t\t     Press any key to continue......";
            getch();
            receipt(PrName, quantity, price, discount, 0);
            main_menu();
        }
        else if(choose==2){
            cout<<"\t\t\t\t\t\t     Press any key to continue......";
            getch();
            receipt(PrName, quantity, price, discount, 1);
            main_menu();
        }
        else{
            cout<<"\n\t\t\t\t\t\t      -----> Enter valid number <-----"<<endl;
            goto X10;
        }
        break;

    case 2:
        cout<<"\t\t\t\t\t\t     Press any key to go back to main menu......";
        getch();
        main_menu();
        break;
    
    default:
        cout<<"\n\t\t\t\t\t\t     -----> Chose valid number <-----"<<endl;
        goto X8;
        break;
    }
}

void electronic::add_laptop()
{
    system("cls");
    product = "L";
    cout<<"\n\n\t\t\t\t\t------------------------------------------------------------"<<endl;
    cout<<"\t\t\t\t\t\t\t\t  Laptop"<<endl;
    cout<<"\t\t\t\t\t------------------------------------------------------------"<<endl<<endl;
    if(value==2){
        cout<<"\t\t\t\t\t\t     ------- Modify your laptop -------"<<endl<<endl;
    }
    cout<<"\t\t\t\t\t\t------- Enter the details of laptop -------"<<endl<<endl;
    cout<<"\t\t\t\t\t\t    ----- Don't use space button -----"<<endl<<endl;
    cout<<"\t\t\t\t\t\tEnter the name of laptop: ";
    cin>>PrName;
    cout<<"\t\t\t\t\t\tEnter the display type of laptop: ";
    cin>>display_type;
    cout<<"\t\t\t\t\t\tEnter the display size of laptop(in inch): ";
    cin>>display_size;
    cout<<"\t\t\t\t\t\tEnter the screen resolution of laptop: ";
    cin>>screen_resolution;
    cout<<"\t\t\t\t\t\tEnter the processor of laptop: ";
    cin>>processor;
    cout<<"\t\t\t\t\t\tEnter the RAM of laptop(in GigaByte): ";
    cin>>ram;
    cout<<"\t\t\t\t\t\tEnter the Graphic Processor of laptop: ";
    cin>>GPU;
    cout<<"\t\t\t\t\t\tEnter the graphic memory of laptop(in GigaByte): ";
    cin>>GPU_memory;
    cout<<"\t\t\t\t\t\tEnter the color of laptop: ";
    cin>>color;
    cout<<"\t\t\t\t\t\tEnter the SSD capacity of laptop(in GigaByte): ";
    cin>>SSD;
    cout<<"\t\t\t\t\t\tEnter the Operating System of laptop: ";
    cin>>os;
    cout<<"\t\t\t\t\t\tEnter the warranty of laptop: ";
    cin>>warranty;
    cout<<"\t\t\t\t\t\tEnter the price(in Indian Rupees) of laptop: ";
    cin>>price;
    cout<<"\t\t\t\t\t\tEnter the discount on laptop(in percentage %): ";
    cin>>discount;
    product_no++;
    ofstream NewPr;
    NewPr.open("Product.txt", ios::app);
    NewPr<<product_no<<" "<<product<<" "<<PrName<<" "<<display_type<<" "<<display_size<<" "<<screen_resolution<<" "<<processor<<" "<<ram<<" "<<GPU<<" "<<GPU_memory<<" "<<color<<" "<<SSD<<" "<<os<<" "<<warranty<<" "<<price<<" "<<discount<<endl;
    NewPr.close();
    if(value==1){
        cout<<"\n\t\t\t\t\t\tYour product added successfully"<<endl;
    }
    cout<<"\n\t\t\t\t\t\tPress any key to continue......";
        // cout<<"\n\t\t\t\t\t\tYour product modified successfully";
    getch();
}

void electronic::laptop_list()
{
    system("cls");
    int a[50], i=0, k=0, choose, quantity;
    char type;
    string str1;
    ifstream L_list;
    L_list.open("Product.txt");
    display();
    cout<<"\t\t\t\t\t\t   ------- List of Laptops -------"<<endl<<endl;
    while(L_list.eof()==0)
    {
        L_list>>pr_no>>type;
        if(type=='L'){
            a[i]=pr_no;
            L_list>>str1;
            cout<<"\t\t\t\t\t\t\t"<<i+1<<". "<<str1<<endl;
            i++;
        }
        getline(L_list, str1);
        k++;
        if(k==product_no){
            break;
        }
    }
    L_list.close();
    cout<<"\n\t\t\t\t\t\t\tPress 0 for going back"<<endl<<endl;

    if(value==2){
        cout<<"\t\t\t\t\t\t\tChoose which product you want to modify"<<endl;
    }
    else if(value==3){
        cout<<"\t\t\t\t\t\t\tChoose which product you want to delete"<<endl;
    }

    X7:
    cout<<"\t\t\t\t\t\t\tChoose from 0 to "<<i<<": ";
    cin>>choose;
    if(choose<0 || choose>i){
        cout<<"\n\t\t\t\t\t\t      -----> Chose valid number <-----"<<endl;
        goto X7;
    }
    else if(choose==0){
        Product_list();
    }

    ifstream L_details;
    L_details.open("Product.txt");
    while (L_details.eof()==0)
    {
        L_details>>pr_no;
        if(pr_no==a[choose-1]){
            L_details>>product>>PrName>>display_type>>display_size>>screen_resolution>>processor>>ram>>GPU>>GPU_memory>>color>>SSD>>os>>warranty>>price>>discount;
            break;
        }
        else{
            getline(L_details, str1);
        }
    }
    L_details.close();
    if(value==2 || value==3){
        goto X;
    }
    system("cls");
    display();
    display_laptop();
    if(account_type=="A"){
        cout<<"\t\t\t\t\t\t     Press any key to continue......";
        getch();
        goto X;
    }
    ask_for_buy();
    X:;
}

void electronic::display_laptop()
{
    cout<<"\t\t\t\t\t\t     ------- Laptop Details -------"<<endl<<endl;
    cout<<"\t\t\t\t\t\t     Name: "<<PrName<<endl<<endl;
    cout<<"\t\t\t\t\t\t     Color: "<<color<<endl<<endl;
    cout<<"\t\t\t\t\t\t     Display type: "<<display_type<<endl<<endl;
    cout<<"\t\t\t\t\t\t     Display size: "<<display_size<<" inch"<<endl<<endl;
    cout<<"\t\t\t\t\t\t     Screen resolution: "<<screen_resolution<<endl<<endl;
    cout<<"\t\t\t\t\t\t     Processor: "<<processor<<endl<<endl;
    cout<<"\t\t\t\t\t\t     RAM: "<<ram<<" GB"<<endl<<endl;
    cout<<"\t\t\t\t\t\t     Graphic Processor: "<<GPU<<endl<<endl;
    cout<<"\t\t\t\t\t\t     Graphic memory: "<<GPU_memory<<" GB"<<endl<<endl;
    cout<<"\t\t\t\t\t\t     SSD capacity: "<<SSD<<" GB"<<endl<<endl;
    cout<<"\t\t\t\t\t\t     Operating System: "<<os<<endl<<endl;
    cout<<"\t\t\t\t\t\t     Warranty: "<<warranty<<endl<<endl;
    cout<<"\t\t\t\t\t\t     Discount: "<<discount<<"%"<<endl<<endl;
    currency_change();
}

void electronic::receipt(string v, int w, long long int x, int y, int z)
{
    system("cls");
    static string Prname2[10];
    static int quantity2[10], discount2[10], i=0;
    static long long int price2[10], total_price=0;
    Prname2[i]=v;
    quantity2[i]=w;
    price2[i]=x;
    discount2[i]=y;
    i++;

    if(z==1)
    {
        cout<<"\n\n\t      =================================================================================================================="<<endl;
        gotoxy(14, 3);
        cout<<"|";
        gotoxy(58, 3);
        cout<<"Electronics Shop Receipt";
        gotoxy(127, 3);
        cout<<"|"<<endl;
        cout<<"\t      =================================================================================================================="<<endl<<endl;

        gotoxy(14, 5);
        cout<<"|";
        gotoxy(16, 5);
        cout<<"No";
        gotoxy(20, 5);
        cout<<"Product Name";
        gotoxy(41, 5);
        cout<<"Quantity";
        gotoxy(53, 5);
        cout<<"discount";
        gotoxy(66, 5);
        cout<<"Original Price";
        gotoxy(85, 5);
        cout<<"Amount";
        gotoxy(106, 5);
        cout<<"Amount wity discount"<<endl;
        gotoxy(127, 5);
        cout<<"|"<<endl;
        cout<<"\t      ------------------------------------------------------------------------------------------------------------------"<<endl;
        int k=7;
        for(int j=0; j<i; j++)
        {
            gotoxy(14, k);
            cout<<"|";
            gotoxy(16, k);
            cout<<j+1;
            gotoxy(20, k);
            cout<<Prname2[j];
            gotoxy(44, k);
            cout<<quantity2[j];
            gotoxy(55, k);
            cout<<discount2[j]<<"%";
            gotoxy(66, k);
            cout<<price2[j]<<" "<<currency;
            gotoxy(85, k);
            cout<<price2[j]*quantity2[j]<<" "<<currency;
            gotoxy(106, k);
            cout<<quantity2[j]*(price2[j] - (price2[j]*discount2[j])/100)<<" "<<currency<<endl;
            gotoxy(127, k);
            cout<<"|"<<endl;
            total_price += quantity2[j]*(price2[j] - (price2[j]*discount2[j])/100);
            k++;
        }
    cout<<"\t      ------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"\t       Username: "<<username<<endl<<"\t       Total Amount: "<<total_price<<" "<<currency<<endl<<"\t       Press any key to continue......";
    getch();
    }
}

void electronic::add_mobile()
{
    system("cls");
    product = "M";
    cout<<"\n\n\t\t\t\t\t------------------------------------------------------------"<<endl;
    cout<<"\t\t\t\t\t\t\t\t  Mobile"<<endl;
    cout<<"\t\t\t\t\t------------------------------------------------------------"<<endl<<endl;
    if(value==2){
        cout<<"\t\t\t\t\t\t     ------- Modify your mobile -------"<<endl<<endl;
    }
    cout<<"\t\t\t\t\t\t------- Enter the details of mobile -------"<<endl<<endl;
    cout<<"\t\t\t\t\t\t    ----- Don't use space button -----"<<endl<<endl;
    cout<<"\t\t\t\t\t\tEnter the name of mobile: ";
    cin>>PrName;
    cout<<"\t\t\t\t\t\tEnter the color of mobile: ";
    cin>>color;
    cout<<"\t\t\t\t\t\tEnter the display type of mobile: ";
    cin>>display_type;
    cout<<"\t\t\t\t\t\tEnter the display size of mobile(in inch): ";
    cin>>display_size;
    cout<<"\t\t\t\t\t\tEnter the screen resolution of mobile: ";
    cin>>screen_resolution;
    cout<<"\t\t\t\t\t\tEnter the processor of mobile: ";
    cin>>processor;
    cout<<"\t\t\t\t\t\tEnter the Rare camera of mobile: ";
    cin>>rare_camera;
    cout<<"\t\t\t\t\t\tEnter the Front camera of mobile: ";
    cin>>front_camera;
    cout<<"\t\t\t\t\t\tEnter the RAM of mobile(in GigaByte): ";
    cin>>ram;
    cout<<"\t\t\t\t\t\tEnter the Battery capacity of mobile(in mAh): ";
    cin>>battery;
    cout<<"\t\t\t\t\t\tEnter the storage capacity of mobile(in GigaByte): ";
    cin>>SSD;
    cout<<"\t\t\t\t\t\tEnter the Operating System of mobile: ";
    cin>>os;
    cout<<"\t\t\t\t\t\tEnter the warranty of mobile: ";
    cin>>warranty;
    cout<<"\t\t\t\t\t\tEnter the price(in Indian Rupees) of mobile: ";
    cin>>price;
    cout<<"\t\t\t\t\t\tEnter the discount on mobile(in percentage %): ";
    cin>>discount;
    product_no++;
    ofstream NewPr;
    NewPr.open("Product.txt", ios::app);
    NewPr<<product_no<<" "<<product<<" "<<PrName<<" "<<display_type<<" "<<display_size<<" "<<screen_resolution<<" "<<processor<<" "<<rare_camera<<" "<<front_camera<<" "<<battery<<" "<<ram<<" "<<color<<" "<<SSD<<" "<<os<<" "<<warranty<<" "<<price<<" "<<discount<<endl;
    NewPr.close();  
    if(value==1){
        cout<<"\n\t\t\t\t\t\tYour product added successfully"<<endl;
    }
    cout<<"\n\t\t\t\t\t\tPress any key to continue......";
    getch();  
}

void electronic::mobile_list()
{
    system("cls");
    int a[50], i=0, k=0, choose, quantity;
    char type;
    string str1;
    ifstream L_list;
    L_list.open("Product.txt");
    display();
    cout<<"\t\t\t\t\t\t   ------- List of Mobiles -------"<<endl<<endl;
    while(L_list.eof()==0)
    {
        L_list>>pr_no>>type;
        if(type=='M'){
            a[i]=pr_no;
            L_list>>str1;
            cout<<"\t\t\t\t\t\t\t"<<i+1<<". "<<str1<<endl;
            i++;
        }
        getline(L_list, str1);
        k++;
        if(k==product_no){
            break;
        }
    }
    L_list.close();
    cout<<"\n\t\t\t\t\t\t\tPress 0 for going back"<<endl<<endl;

    if(value==2){
        cout<<"\t\t\t\t\t\t\tChoose which product you want to modify"<<endl;
    }
    else if(value==3){
        cout<<"\t\t\t\t\t\t\tChoose which product you want to delete"<<endl;
    }

    X7:
    cout<<"\t\t\t\t\t\t\tChoose from 0 to "<<i<<": ";
    cin>>choose;
    if(choose<0 || choose>i){
        cout<<"\n\t\t\t\t\t\t      -----> Chose valid number <-----"<<endl;
        goto X7;
    }
    if(choose==0){
        Product_list();
    }

    ifstream L_details;
    L_details.open("Product.txt");
    while (L_details.eof()==0)
    {
        L_details>>pr_no;
        if(pr_no==a[choose-1]){
            L_details>>product>>PrName>>display_type>>display_size>>screen_resolution>>processor>>rare_camera>>front_camera>>battery>>ram>>color>>SSD>>os>>warranty>>price>>discount;
            break;
        }
        else{
            getline(L_details, str1);
        }
    }
    L_details.close();
    if(value==2 || value==3){
        goto X;
    }
    system("cls");
    display();
    display_mobile();
    if(account_type=="A"){
        cout<<"\t\t\t\t\t\t     Press any key to continue......";
        getch();
        goto X;
    }
    ask_for_buy();
    X:;
}

void electronic::display_mobile()
{
    cout<<"\t\t\t\t\t\t     ------- Mobile Details -------"<<endl<<endl;
    cout<<"\t\t\t\t\t\t     Name: "<<PrName<<endl<<endl;
    cout<<"\t\t\t\t\t\t     Color: "<<color<<endl<<endl;
    cout<<"\t\t\t\t\t\t     Display type: "<<display_type<<endl<<endl;
    cout<<"\t\t\t\t\t\t     Display size: "<<display_size<<" inch"<<endl<<endl;
    cout<<"\t\t\t\t\t\t     Screen resolution: "<<screen_resolution<<endl<<endl;
    cout<<"\t\t\t\t\t\t     Processor: "<<processor<<endl<<endl;
    cout<<"\t\t\t\t\t\t     RAM: "<<ram<<" GB"<<endl<<endl;
    cout<<"\t\t\t\t\t\t     Rare Camera: "<<rare_camera<<endl<<endl;
    cout<<"\t\t\t\t\t\t     Front Camera: "<<front_camera<<endl<<endl;
    cout<<"\t\t\t\t\t\t     Battery: "<<battery<<" mAh"<<endl<<endl;
    cout<<"\t\t\t\t\t\t     SSD capacity: "<<SSD<<" GB"<<endl<<endl;
    cout<<"\t\t\t\t\t\t     Operating System: "<<os<<endl<<endl;
    cout<<"\t\t\t\t\t\t     Warranty: "<<warranty<<endl<<endl;
    cout<<"\t\t\t\t\t\t     Discount: "<<discount<<"%"<<endl<<endl;
    currency_change();
}

void electronic::add_headphone()
{
    system("cls");
    product = "H";
    cout<<"\n\n\t\t\t\t\t------------------------------------------------------------"<<endl;
    cout<<"\t\t\t\t\t\t\t\tHeadphones"<<endl;
    cout<<"\t\t\t\t\t------------------------------------------------------------"<<endl<<endl;
    if(value==2){
        cout<<"\t\t\t\t\t\t     ------- Modify your headphone -------"<<endl<<endl;
    }
    cout<<"\t\t\t\t\t\t------- Enter the details of Headphone -------"<<endl<<endl;
    cout<<"\t\t\t\t\t\t    ----- Don't use space button -----"<<endl<<endl;
    cout<<"\t\t\t\t\t\tEnter the name of Headphone: ";
    cin>>PrName;
    cout<<"\t\t\t\t\t\tHeadphone Type: ";
    cin>>display_size;
    cout<<"\t\t\t\t\t\tEnter the color of Headphone: ";
    cin>>color;
    cout<<"\t\t\t\t\t\tWith Mic: ";
    cin>>GPU;
    cout<<"\t\t\t\t\t\tEnter the Connectivity of Headphone: ";
    cin>>SSD;
    cout<<"\t\t\t\t\t\tEnter the Play Time of Headphone: ";
    cin>>os;
    cout<<"\t\t\t\t\t\tEnter the Battery of Headphone(in mAh): ";
    cin>>battery;
    cout<<"\t\t\t\t\t\tEnter the warranty of Headphone: ";
    cin>>warranty;
    cout<<"\t\t\t\t\t\tEnter the price(in Indian Rupees) of Headphone: ";
    cin>>price;
    cout<<"\t\t\t\t\t\tEnter the discount on Headphone(in percentage %): ";
    cin>>discount;
    product_no++;
    ofstream NewPr;
    NewPr.open("Product.txt", ios::app);
    NewPr<<product_no<<" "<<product<<" "<<PrName<<" "<<display_size<<" "<<GPU<<" "<<color<<" "<<SSD<<" "<<os<<" "<<battery<<" "<<warranty<<" "<<price<<" "<<discount<<endl;
    NewPr.close();
    if(value==1){
        cout<<"\n\t\t\t\t\t\tYour product added successfully"<<endl;
    }
    cout<<"\n\t\t\t\t\t\tPress any key to continue......";
    getch();
}

void electronic::headphone_list()
{
    system("cls");
    int a[50], i=0, k=0, choose, quantity;
    char type;
    string str1;
    ifstream L_list;
    L_list.open("Product.txt");
    display();
    cout<<"\t\t\t\t\t\t  ------- List of Headphones -------"<<endl<<endl;
    while(L_list.eof()==0)
    {
        L_list>>pr_no>>type;
        if(type=='H'){
            a[i]=pr_no;
            L_list>>str1;
            cout<<"\t\t\t\t\t\t\t"<<i+1<<". "<<str1<<endl;
            i++;
        }
        getline(L_list, str1);
        k++;
        if(k==product_no){
            break;
        }
    }
    L_list.close();
    cout<<"\n\t\t\t\t\t\t\tPress 0 for going back"<<endl<<endl;

    if(value==2){
        cout<<"\t\t\t\t\t\t\tChoose which product you want to modify"<<endl;
    }
    else if(value==3){
        cout<<"\t\t\t\t\t\t\tChoose which product you want to delete"<<endl;
    }
    
    X7:
    cout<<"\t\t\t\t\t\t\tChoose from 0 to "<<i<<": ";
    cin>>choose;
    if(choose<0 || choose>i){
        cout<<"\n\t\t\t\t\t\t      -----> Chose valid number <-----"<<endl;
        goto X7;
    }
    if(choose==0){
        Product_list();
    }

    ifstream L_details;
    L_details.open("Product.txt");
    while (L_details.eof()==0)
    {
        L_details>>pr_no;
        if(pr_no==a[choose-1]){
            L_details>>product>>PrName>>display_size>>GPU>>color>>SSD>>os>>battery>>warranty>>price>>discount;
            break;
        }
        else{
            getline(L_details, str1);
        }
    }
    L_details.close();
    if(value==2 || value==3){
        goto X;
    }
    system("cls");
    if(value==2 || value==3){
        goto X;
    }
    display();
    display_headphone();
    if(account_type=="A"){
        cout<<"\t\t\t\t\t\t     Press any key to continue......";
        getch();
        goto X;
    }
    ask_for_buy();
    X:;
}

void electronic::display_headphone()
{
    cout<<"\t\t\t\t\t\t    ------- Headphone Details -------"<<endl<<endl;
    cout<<"\t\t\t\t\t\t     Name: "<<PrName<<endl<<endl;
    cout<<"\t\t\t\t\t\t     Type: "<<display_size<<endl<<endl;
    cout<<"\t\t\t\t\t\t     Color: "<<color<<endl<<endl;
    cout<<"\t\t\t\t\t\t     With Mic: "<<GPU<<endl<<endl;
    cout<<"\t\t\t\t\t\t     Connectivity: "<<SSD<<" inch"<<endl<<endl;
    cout<<"\t\t\t\t\t\t     Play Time: "<<os<<" hr"<<endl<<endl;
    cout<<"\t\t\t\t\t\t     Battery: "<<battery<<" mAh"<<endl<<endl;
    cout<<"\t\t\t\t\t\t     Warranty: "<<warranty<<endl<<endl;
    cout<<"\t\t\t\t\t\t     Discount: "<<discount<<"%"<<endl<<endl;
    currency_change();
}

void electronic::add_smartwatch()
{
    system("cls");
    product = "W";
    cout<<"\n\n\t\t\t\t\t------------------------------------------------------------"<<endl;
    cout<<"\t\t\t\t\t\t\t\tSmart Watch"<<endl;
    cout<<"\t\t\t\t\t------------------------------------------------------------"<<endl<<endl;
    if(value==2){
        cout<<"\t\t\t\t\t\t     ------- Modify your smart watch -------"<<endl<<endl;
    }
    cout<<"\t\t\t\t\t   ------- Enter the details of Smart Watch -------"<<endl<<endl;
    cout<<"\t\t\t\t\t\t    ----- Don't use space button -----"<<endl<<endl;
    cout<<"\t\t\t\t\t\tEnter the name of Smart Watch: ";
    cin>>PrName;
    cout<<"\t\t\t\t\t\tEnter the color of Smart Watch: ";
    cin>>color;
    cout<<"\t\t\t\t\t\tEnter the display type of Smart Watch: ";
    cin>>display_type;
    cout<<"\t\t\t\t\t\tEnter the display size of Smart Watch(in inch): ";
    cin>>display_size;
    cout<<"\t\t\t\t\t\tEnter the screen resolution of Smart Watch: ";
    cin>>screen_resolution;
    cout<<"\t\t\t\t\t\tWater Resistant: ";
    cin>>processor;
    cout<<"\t\t\t\t\t\tAccelerometer Sensor: ";
    cin>>rare_camera;
    cout<<"\t\t\t\t\t\tOptical Heart Rate Sensor: ";
    cin>>front_camera;
    cout<<"\t\t\t\t\t\tG-sensor: ";
    cin>>GPU;
    cout<<"\t\t\t\t\t\tUsage: ";
    cin>>os;
    cout<<"\t\t\t\t\t\tEnter the warranty of Smart Watch: ";
    cin>>warranty;
    cout<<"\t\t\t\t\t\tEnter the price(in Indian Rupees) of Smart Watch: ";
    cin>>price;
    cout<<"\t\t\t\t\t\tEnter the discount on Smart Watch(in percentage %): ";
    cin>>discount;
    product_no++;
    ofstream NewPr;
    NewPr.open("Product.txt", ios::app);
    NewPr<<product_no<<" "<<product<<" "<<PrName<<" "<<display_type<<" "<<display_size<<" "<<screen_resolution<<" "<<processor<<" "<<rare_camera<<" "<<front_camera<<" "<<color<<" "<<GPU<<" "<<os<<" "<<warranty<<" "<<price<<" "<<discount<<endl;
    NewPr.close();  
    if(value==1){
        cout<<"\n\t\t\t\t\t\tYour product added successfully"<<endl;
    }
    cout<<"\n\t\t\t\t\t\tPress any key to continue......";
    getch();  
}

void electronic::smartwatch_list()
{
    system("cls");
    int a[50], i=0, k=0, choose, quantity;
    char type;
    string str1;
    ifstream L_list;
    L_list.open("Product.txt");
    display();
    cout<<"\t\t\t\t\t\t------- List of Smart Watch -------"<<endl<<endl;
    while(L_list.eof()==0)
    {
        L_list>>pr_no>>type;
        if(type=='W'){
            a[i]=pr_no;
            L_list>>str1;
            cout<<"\t\t\t\t\t\t\t"<<i+1<<". "<<str1<<endl;
            i++;
        }
        getline(L_list, str1);
        k++;
        if(k==product_no){
            break;
        }
    }
    L_list.close();
    cout<<"\n\t\t\t\t\t\t\tPress 0 for going back"<<endl<<endl;

    if(value==2){
        cout<<"\t\t\t\t\t\t\tChoose which product you want to modify"<<endl;
    }
    else if(value==3){
        cout<<"\t\t\t\t\t\t\tChoose which product you want to delete"<<endl;
    }
    
    X7:
    cout<<"\t\t\t\t\t\t\tChoose from 0 to "<<i<<": ";
    cin>>choose;
    if(choose<0 || choose>i){
        cout<<"\n\t\t\t\t\t\t      -----> Chose valid number <-----"<<endl;
        goto X7;
    }
    if(choose==0){
        Product_list();
    }

    ifstream L_details;
    L_details.open("Product.txt");
    while (L_details.eof()==0)
    {
        L_details>>pr_no;
        if(pr_no==a[choose-1]){
            L_details>>product>>PrName>>display_type>>display_size>>screen_resolution>>processor>>rare_camera>>front_camera>>color>>GPU>>os>>warranty>>price>>discount;
            break;
        }
        else{
            getline(L_details, str1);
        }
    }
    L_details.close();
    if(value==2 || value==3){
        goto X;
    }
    system("cls");
    display();
    display_smartwatch();
    if(account_type=="A"){
        cout<<"\t\t\t\t\t\t     Press any key to continue......";
        getch();
        goto X;
    }
    ask_for_buy();
    X:;
}

void electronic::display_smartwatch()
{
    cout<<"\t\t\t\t\t\t  ------- Smart Watch Details -------"<<endl<<endl;
    cout<<"\t\t\t\t\t\t     Name: "<<PrName<<endl<<endl;
    cout<<"\t\t\t\t\t\t     Color: "<<color<<endl<<endl;
    cout<<"\t\t\t\t\t\t     Display type: "<<display_type<<endl<<endl;
    cout<<"\t\t\t\t\t\t     Display size: "<<display_size<<" inch"<<endl<<endl;
    cout<<"\t\t\t\t\t\t     Screen resolution: "<<screen_resolution<<endl<<endl;
    cout<<"\t\t\t\t\t\t     Water Resistant: "<<processor<<endl<<endl;
    cout<<"\t\t\t\t\t\t     Accelerometer Sensor: "<<rare_camera<<endl<<endl;
    cout<<"\t\t\t\t\t\t     Optical Heart Rate Sensor: "<<front_camera<<endl<<endl;
    cout<<"\t\t\t\t\t\t     G-sensor: "<<GPU<<endl<<endl;
    cout<<"\t\t\t\t\t\t     Usage: "<<os<<endl<<endl;
    cout<<"\t\t\t\t\t\t     Warranty: "<<warranty<<endl<<endl;
    cout<<"\t\t\t\t\t\t     Discount: "<<discount<<"%"<<endl<<endl;
    currency_change();
}

void electronic::add_pendrive()
{
    system("cls");
    product = "P";
    cout<<"\n\n\t\t\t\t\t------------------------------------------------------------"<<endl;
    cout<<"\t\t\t\t\t\t\t\t  Pen Drive"<<endl;
    cout<<"\t\t\t\t\t------------------------------------------------------------"<<endl<<endl;
    if(value==2){
        cout<<"\t\t\t\t\t\t     ------- Modify your pendrive -------"<<endl<<endl;
    }
    cout<<"\t\t\t\t\t\t------- Enter the details of Pen Drive -------"<<endl<<endl;
    cout<<"\t\t\t\t\t\t    ----- Don't use space button -----"<<endl<<endl;
    cout<<"\t\t\t\t\t\tEnter the name of Pen Drive: ";
    cin>>PrName;
    cout<<"\t\t\t\t\t\tEnter the storage capacity of Pen Drive(in GigaByte): ";
    cin>>SSD;
    cout<<"\t\t\t\t\t\tEnter the price(in Indian Rupees) of Pen Drive: ";
    cin>>price;
    cout<<"\t\t\t\t\t\tEnter the discount on Pen Drive(in percentage %): ";
    cin>>discount;
    product_no++;
    ofstream NewPr;
    NewPr.open("Product.txt", ios::app);
    NewPr<<product_no<<" "<<product<<" "<<PrName<<" "<<SSD<<" "<<price<<" "<<discount<<endl;
    NewPr.close();
    if(value==1){
        cout<<"\n\t\t\t\t\t\tYour product added successfully"<<endl;
    }
    cout<<"\n\t\t\t\t\t\tPress any key to continue......";
    getch(); 
}

void electronic::pendrive_list()
{
    system("cls");
    int a[50], i=0, k=0, choose, quantity;
    char type;
    string str1;
    ifstream L_list;
    L_list.open("Product.txt");
    display();
    cout<<"\t\t\t\t\t\t   ------- List of Pen Drive -------"<<endl<<endl;
    while(L_list.eof()==0)
    {
        L_list>>pr_no>>type;
        if(type=='P'){
            a[i]=pr_no;
            L_list>>str1;
            cout<<"\t\t\t\t\t\t\t"<<i+1<<". "<<str1<<endl;
            i++;
        }
        getline(L_list, str1);
        k++;
        if(k==product_no){
            break;
        }
    }
    L_list.close();
    cout<<"\n\t\t\t\t\t\t\tPress 0 for going back"<<endl<<endl;

    if(value==2){
        cout<<"\t\t\t\t\t\t\tChoose which product you want to modify"<<endl;
    }
    else if(value==3){
        cout<<"\t\t\t\t\t\t\tChoose which product you want to delete"<<endl;
    }
    
    X7:
    cout<<"\t\t\t\t\t\t\tChoose from 0 to "<<i<<": ";
    cin>>choose;
    if(choose<0 || choose>i){
        cout<<"\n\t\t\t\t\t\t      -----> Chose valid number <-----"<<endl;
        goto X7;
    }
    if(choose==0){
        Product_list();
    }

    ifstream L_details;
    L_details.open("Product.txt");
    while (L_details.eof()==0)
    {
        L_details>>pr_no;
        if(pr_no==a[choose-1]){
            L_details>>product>>PrName>>SSD>>price>>discount;
            break;
        }
        else{
            getline(L_details, str1);
        }
    }
    L_details.close();
    if(value==2 || value==3){
        goto X;
    }
    system("cls");
    display();
    display_pendrive();
    if(account_type=="A"){
        cout<<"\t\t\t\t\t\t     Press any key to continue......";
        getch();
        goto X;
    }
    ask_for_buy();
    X:;
}

void electronic::display_pendrive()
{
    cout<<"\t\t\t\t\t\t    ------- Pen Drive Details -------"<<endl<<endl;
    cout<<"\t\t\t\t\t\t     Name: "<<PrName<<endl<<endl;
    cout<<"\t\t\t\t\t\t     Storage capacity: "<<SSD<<" GB"<<endl<<endl;
    cout<<"\t\t\t\t\t\t     Discount: "<<discount<<"%"<<endl<<endl;
    currency_change();
}

void electronic::add_mouse()
{
    system("cls");
    product = "O";
    cout<<"\n\n\t\t\t\t\t------------------------------------------------------------"<<endl;
    cout<<"\t\t\t\t\t\t\t\t  Mouse"<<endl;
    cout<<"\t\t\t\t\t------------------------------------------------------------"<<endl<<endl;
    if(value==2){
        cout<<"\t\t\t\t\t\t     ------- Modify your mouse -------"<<endl<<endl;
    }
    cout<<"\t\t\t\t\t\t------- Enter the details of Mouse -------"<<endl<<endl;
    cout<<"\t\t\t\t\t\t    ----- Don't use space button -----"<<endl<<endl;
    cout<<"\t\t\t\t\t\tEnter the name of Mouse: ";
    cin>>PrName;
    cout<<"\t\t\t\t\t\tWired or Wireless: ";
    cin>>GPU;
    cout<<"\t\t\t\t\t\tConnectivity: ";
    cin>>display_type;
    cout<<"\t\t\t\t\t\tDPI: ";
    cin>>screen_resolution;
    cout<<"\t\t\t\t\t\tEnter the color of mouse: ";
    cin>>color;
    cout<<"\t\t\t\t\t\tEnter the warranty of mouse: ";
    cin>>warranty;
    cout<<"\t\t\t\t\t\tEnter the price(in Indian Rupees) of mouse: ";
    cin>>price;
    cout<<"\t\t\t\t\t\tEnter the discount on mouse(in percentage %): ";
    cin>>discount;
    product_no++;
    ofstream NewPr;
    NewPr.open("Product.txt", ios::app);
    NewPr<<product_no<<" "<<product<<" "<<PrName<<" "<<display_type<<" "<<screen_resolution<<" "<<GPU<<" "<<color<<" "<<warranty<<" "<<price<<" "<<discount<<endl;
    NewPr.close();
    if(value==1){
        cout<<"\n\t\t\t\t\t\tYour product added successfully"<<endl;
    }
    cout<<"\n\t\t\t\t\t\tPress any key to continue......";
    getch();
}

void electronic::mouse_list()
{
    system("cls");
    int a[50], i=0, k=0, choose, quantity;
    char type;
    string str1;
    ifstream L_list;
    L_list.open("Product.txt");
    display();
    cout<<"\t\t\t\t\t\t   ------- List of Mouse -------"<<endl<<endl;
    while(L_list.eof()==0)
    {
        L_list>>pr_no>>type;
        if(type=='O'){
            a[i]=pr_no;
            L_list>>str1;
            cout<<"\t\t\t\t\t\t\t"<<i+1<<". "<<str1<<endl;
            i++;
        }
        getline(L_list, str1);
        k++;
        if(k==product_no){
            break;
        }
    }
    L_list.close();
    cout<<"\n\t\t\t\t\t\t\tPress 0 for going back"<<endl<<endl;

    if(value==2){
        cout<<"\t\t\t\t\t\t\tChoose which product you want to modify"<<endl;
    }
    else if(value==3){
        cout<<"\t\t\t\t\t\t\tChoose which product you want to delete"<<endl;
    }
    
    X7:
    cout<<"\t\t\t\t\t\t\tChoose from 0 to "<<i<<": ";
    cin>>choose;
    if(choose<0 || choose>i){
        cout<<"\n\t\t\t\t\t\t      -----> Chose valid number <-----"<<endl;
        goto X7;
    }
    if(choose==0){
        Product_list();
    }

    ifstream L_details;
    L_details.open("Product.txt");
    while (L_details.eof()==0)
    {
        L_details>>pr_no;
        if(pr_no==a[choose-1]){
            L_details>>product>>PrName>>display_type>>screen_resolution>>GPU>>color>>warranty>>price>>discount;
            break;
        }
        else{
            getline(L_details, str1);
        }
    }
    L_details.close();
    if(value==2 || value==3){
        goto X;
    }
    system("cls");
    display();
    display_mouse();
    if(account_type=="A"){
        cout<<"\t\t\t\t\t\t     Press any key to continue......";
        getch();
        goto X;
    }
    ask_for_buy();
    X:;
}

void electronic::display_mouse()
{
    cout<<"\t\t\t\t\t\t     ------- Mouse Details -------"<<endl<<endl;
    cout<<"\t\t\t\t\t\t     Name: "<<PrName<<endl<<endl;
    cout<<"\t\t\t\t\t\t     Color: "<<color<<endl<<endl;
    cout<<"\t\t\t\t\t\t     Wired or Wireless: "<<GPU<<endl<<endl;
    cout<<"\t\t\t\t\t\t     Connectivity: "<<display_type<<endl<<endl;
    cout<<"\t\t\t\t\t\t     DPI: "<<screen_resolution<<endl<<endl;
    cout<<"\t\t\t\t\t\t     Warranty: "<<warranty<<endl<<endl;
    cout<<"\t\t\t\t\t\t     Discount: "<<discount<<"%"<<endl<<endl;
    currency_change();
}

int main()
{
    electronic a;
    a.id_password();
    a.main_menu();
    return 0;
}