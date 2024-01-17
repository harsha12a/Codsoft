#include<iostream>
using namespace std;
class calculator{
    public:
    double op1,op2;
    calculator(){
        cout<<"Enter operand 1 :";
        cin>>op1;
        cout<<"Enter operand 2 :";
        cin>>op2;
    }
    double sum(){
        return op1+op2;
    }
    double sub(){
        return op1-op2;
    }
    double mul(){
        return op1*op2;
    }
    double div(){
        return op1/op2;
    }
};
int main(){
    calculator calc;
    int choice;
    cout<<"--Enter 1 for addition--\n"<<"--Enter 2 for subtraction--\n"<<"--Enter 3 for multiplication--\n"<<"--Enter 4 for division--\n";
    cout<<"Your choice :";
    cin>>choice;
    switch(choice){
        case 1:cout<<"Sum of "<<calc.op1<<" and "<<calc.op2<<" is "<<calc.sum();
            break;
        case 2:cout<<"Subtraction of "<<calc.op1<<" and "<<calc.op2<<" is "<<calc.sub();
            break;
        case 3:cout<<"Product of "<<calc.op1<<" and "<<calc.op2<<" is "<<calc.mul();
            break;
        case 4:cout<<"Quotient of "<<calc.op1<<" and "<<calc.op2<<" is "<<calc.div();
            break;
        default:cout<<"\nOperation not available\n";
            break;
    }
    return 0;
}