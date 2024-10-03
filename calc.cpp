#include<iostream>
using namespace std;
class Calculator{
public:
virtual double calculate(double a,double b)=0;
};
class addition:public Calculator{
double calculate(double a,double b) override
{
    return a+b;
}
};
class Substraction:public Calculator{
    double calculate(double a,double b) override{
        return a-b;
    }
};
class Multiplication:public Calculator{
    double calculate(double a,double b) override{
        return a*b;
    }
};
class Division:public Calculator{
    double calculate(double a,double b)override{
        if(b!=0){
            return a/b;
        }else{
            throw invalid_argument("Division by Zero");
        }
    }
};
int main()
{
    double a,b;
    char op;
    cout<<"Input the First Number;"<<endl;
    cin>>a;
    cout<<"Input the Second number:"<<endl;
    cin>>b;
    cout<<"Input The Operator(+,-,*,/)"<<endl;
    cin>>op;
    Calculator*calculator = nullptr;
    switch(op){
        case '+':
        calculator = new addition();
        break;
        case '-':
        calculator = new Substraction();
        break;
        case '*':
        calculator = new Multiplication();
        break;
        case '/':
        calculator = new Division();
        break;
        default:
        cout<<"Invalid Operator"<<endl;
        return 1;
    }
    try{
        double result = calculator-> calculate(a,b);
        cout<<"Result is:"<<result<<endl;
    }
    catch(const invalid_argument& e)
    {
        cout<<e.what()<<endl;
    }
    delete calculator;
    return 0;
}