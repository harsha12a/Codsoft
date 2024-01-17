#include <iostream>
#include <ctime>
using namespace std;
int main(){
    srand(time(0));
    int randomNumber=rand();
    cout<<"Enter range:";
    int n;
    cin>>n;
    randomNumber=randomNumber%n;
    while(1){
        int guess;
        cout<<"enter a guess in range 0 to "<<n<<": ";
        cin>>guess;
        if(guess==randomNumber){
            cout<<"You guessed correctly\n";
            break;
        } 
        else if(guess>randomNumber){
            cout<<"You have guessed too high,please try again\n";
            continue;
        } 
        else if(guess<randomNumber){
            cout<<"You have guessed too low,please try again\n";
            continue;
        }
    }
    return 0;
}