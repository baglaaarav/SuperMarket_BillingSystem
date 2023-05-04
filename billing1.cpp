#include<iostream>
#include<fstream>
using namespace std;

class shopping{
    int pcode;//product code
    float price;//price
    float dis;//discount
    string pname; //product name;

    public:
    void menu();
    void administrator();
    void buyer();
    void add(); 
    void edit();
    void rem();
    void list();
    void recept();
};
//making the menu function
void shopping :: menu(){
    m:
    int choice;
    string email;
    string password;


    cout << "_________________________________________\n";
    cout << "                                        \n";
    cout << "         SuperMarket Main Menu          \n";
    cout << "                                        \n";
    cout << "_________________________________________\n";
    cout << "                                        \n";

    cout << "1) Administrator     |"<<endl;
    cout << "                      "<<endl;
    cout << "2) Buyer             |"<<endl;
    cout << "                      "<<endl;
    cout << "3) Exit              |"<<endl;
    cout << "                      "<<endl;
    cout << "Please select"<<endl;

    cin >> choice;

    switch(choice){
        case 1:
            cout << "Please Login :"<<endl;;
            cout << "Enter Email : ";
            cin >> email;
            cout <<endl;
            cout << "Password : "<<endl ;
            cin >> password;
            cout << endl;
            if(email == "aaravbagla@email.com" && password =="12345678"){
                administrator();
            }
            else{
                cout << "Invalid email/password \n try again"<<endl;
            }
            break;
        case 2:
            buyer();
        case 3:
            exit(0);

        default:
            cout << "Please select from given options";
    }
    goto m;
}
//creating the administrator
void shopping :: administrator(){
    m:
    int choice;
    cout << "\n\n\n\tAdministrator menu ";
    cout << "\n1) Add the product      "<<endl;
    cout << "                          \n";
    cout << "\n2) Modify the product      "<<endl;
    cout << "                          \n";
    cout << "\n3) Delete the product      "<<endl;
    cout << "                          \n";
    cout << "\n4) back to main menu     "<<endl;
    cout << "                          \n";

    cin >> choice;
    switch(choice){
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


        default:
            cout << "Invalid number"<<endl;
    }

    goto m;
}

//creating the buyer function
void shopping :: buyer(){
    m:
    int choice;
    cout << "Buyer          "<<endl;
    cout << "                        "<<endl;
    cout << "1)Buy product  "<<endl;
    cout << "                        "<<endl;
    cout << "2)Go back      "<<endl;
    cout << "                        "<<endl;

    cin >> choice;
    switch (choice)
    {
    case 1:
        recept();
        break;
    case 2:
        menu();
        break;
    default:
        cout << "Invalid number"<<endl;
    }
    goto m;
}
//creating add option
void shopping :: add(){
    m:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;


    cout << "\n\nAdd The Product "<<endl<<endl<<endl;
    cout << "Product code of the product"<<endl;
    cin >> pcode;
    cout << "Name of the product"<<endl;
    cin >> pname;
    cout << "Price of the product"<<endl;
    cin >> price;
    cout << "Discount of the product"<<endl;
    cin >> dis;
    //opening the file 
    data.open("database.txt", ios::in); //ios means input output stream

    if(!data){
        data.open("database.txt", ios::app|ios::out);
        data << " "<< pcode << " "<<pname<< " "<<price<<" "<<dis<<"\n";
        data.close();
    }
    else{
        data >> c >> n >> p >> d;
        while (!data.eof()){  //end of file 
            if(c == pcode){
                token++;
            }
            data >> c >> n >> p >> d;
        }
        //closing the file 
        data.close();
        if(token == 1){
            goto m;
        }
        else{
            data.open("database.txt", ios::app|ios::out);
            data << " "<< pcode << " "<<pname<< " "<<price<<" "<<dis<<"\n";
            data.close(); 
        }
    }
    
    
    cout << "\n\nrecord inserted ! ";
}

void shopping :: edit(){
    fstream data, data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;

    cout << "\n\nModify the record";
    cout << "\n\nproduct code : ";
    cin >>pkey;
    data.open("database.txt", ios::in);
    if(!data){
        cout << "\n\nfile does not exist ! ";
    }
    else{
        data1.open("database1.txt", ios::app|ios::out);
        data>>pcode>>pname>>price >> dis;
        while (!data.eof()){  //end of file 
            if(pkey == pcode){
                cout << "\nproduct new code : ";
                cin >> c;
                cout << "\nproduct name : ";
                cin >> n;
                cout << "\nproduct price : ";
                cin >> p ;
                cout << "\ndiscount : ";
                cin >> d;
                cout << endl;
                data1 << " "<< c<< " " << n << " "<< p << " "<< d<< '\n';
                
                cout << "\n\nRecord add !";
                token++;
            }
            else{
                data1 << " "<< pcode << " "<< pname<< " " << price << " "<< dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();



        //now we are removing the database.txt file so that we can rename database1 to database
        remove("database.txt");
        rename("database1.txt", "database.txt");
         

        if(token == 0){
            cout << "\n\nrecord not found !";
        }
    }
}


void shopping :: rem(){
    fstream data, data1;
    int pkey;
    int token = 0;
    cout << "\n\nDelete product" ;
    cout << "\n\nprodcut code : "<<endl;
    cin >> pkey;
    data.open("database.txt", ios::in);
    if(!data){
        cout << "\n\nfile does not exist ! ";
    }
    else{

        data1.open("database1.txt", ios::app|ios::out);
        data>>pcode>>pname>>price >> dis;
        while (!data.eof()){  //end of file 
            if(pkey == pcode){
                cout << "\n\nProduct deleted successfully ! ";
                token++;
            }
            else{
                data1 << " "<< pcode << " "<< pname<< " " << price << " "<< dis << "\n";
            }
             data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close(); 
        //now we are removing the database.txt file so that we can rename database1 to database
        remove("database.txt");
        rename("database1.txt", "database.txt");
         

        if(token == 0){
            cout << "\n\nrecord not found !";
        }
    }
}

void shopping :: list(){
    fstream data;
    data.open("database.txt", ios::in);
    cout << "____________________________________________________________________________\n";
    cout << "ProNo\t\tName\t\tprice" << endl;
    cout << "____________________________________________________________________________\n";
    data >> pcode >> pname >> price >> dis;
    while(!data.eof()){
        cout << pcode << "\t\t" << pname << "\t\t" << price << "\n" ;
        data >> pcode >> pname >> price >> dis;
    }
    data.close();
}

void shopping :: recept(){
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c = 0;
    float amount = 0;
    float dis=0;
    float total = 0;


    cout << "\n\n    Recept ";
    data.open("database.txt",  ios::in);
    if(!data){
        cout << "\n\n Emty database !";
    }
    else{
        data.close();
        list();
        cout <<  "\n___________________________________________________________\n";
        cout << "\n|                                                          |\n";
        cout << "\n                Please Place the order                     |\n";
        cout << "\n|                                                          |\n";
        cout <<  "\n___________________________________________________________\n";
        
        do{
            m:
            cout << "\n\n Enter product code : ";
            cin >> arrc[c];
            cout << "\n\n Enter product quantity : ";
            cin >> arrq[c];
            for(int i = 0;i<c; i++){
                if(arrc[c] == arrc[i]){
                    cout << "\n\n Duplicate product, Please try again \n";
                    goto m;

                }
            }
            c++;
            cout << "Do you want to buy another product? if Yes? Press y else n \n";
            cin >> choice;

        }
        while(choice == 'y');

        cout << "\n\n\t_________________________Recipt____________________\n";

        cout << "\nProduct number\t Product name\t Product quiantity\t price\t Amount with discount\n";
        for(int i = 0;i < c; i++){
            data.open("database.txt", ios:: in);
            data >> pcode >> pname >> price >> dis ;
            while(!data.eof()){
                if(pcode == arrc[i]){
                    amount = price*arrq[i];
                    dis = amount - (amount*dis/100);
                    total = total + dis;
                    cout<<"\n"<<pcode<<"\t"<<pname<<"\t"<<arrq[i]<<"\t" << price<<"\t" << amount<<"\t"<< dis;
                }
                data>> pcode >> pname >>  price>> dis;

            }
        }
        data.close();
    }

    cout << "\n\n______________________________________________";
    cout << "Total amount : "<< total <<endl;
    cout << "\n\n\n\n\n";
    cout << "Thankyou this is the end for the termianl code part ";
}


int main(){
    shopping s;
    s.menu();
}