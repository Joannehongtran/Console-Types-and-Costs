#include <iostream>
using namespace std;

double round(double var)
{
    double value = (int)(var * 100 + .5);
    return (double)value / 100;
}

int main()
{
    char console,shipping,index=-1;
    int GB,quantity;
    double price,tax,shipcost;
    double eightGB[] = {419.99, 379.99, 339.99};
    double sixteenGB[] = {499.99, 469.99, 409.99};
    cout<<"Enter the brand name of the game console (X for Xbox, N for Nintendo, P for PlayStation):";
    cin>>console;
    switch(console){
        case 'X':
            index = 0;
            break;
        case 'N':
            index = 1;
            break;
        case 'P':
            index = 2;
            break;
        default:
            cout<<"Please enter valid input";
            exit(0);
    }
    cout<<"Enter the memory size of the game console (8 or 16 gigabytes):";
    cin>>GB;
    cout<<"Enter quantity to buy:";
    cin>>quantity;
    if(GB!=8 || GB!=16){
        cout<<"Please enter valid input";
        exit(0);
    }
    if(quantity<0 && quantity>20){
        cout<<"Please enter valid input";
        exit(0);
    }
    if(GB==8){
        price = eightGB[index]*quantity;
    }else if(GB==16){
        price = sixteenGB[index]*quantity;
    }
    cout<<"The item price for ("<<quantity<<" x Xbox) is $"<<price;
    tax = round(price*0.0975);
    cout<<"\nThe sale tax is $"<<tax;
    cout<<"\nEnter shipping method (R for Regular, E for Expedite):";
    cin>>shipping;
    if(shipping=='R'){
        cout<<"Shipping cost is $5.00";
        shipcost = 5.00;
    }else if(shipping=='E'){
        cout<<"Shipping cost is $10.00";
        shipcost = 10.00;
    }
    cout<<"\nThe total bill is $"<<(price+tax+shipcost);
    return 0;
}
