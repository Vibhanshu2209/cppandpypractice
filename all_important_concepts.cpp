#include <iostream>
using namespace std;



#include <string>
void isVowel(char c){
    string v="AEIOUaeiou";
    if(v.find(c) != string::npos) cout<<endl<<"Vowel";
    else cout<<endl<<"not vowel";
}
void strpermutation(string so_far,string rest_of){
    //alternate approach 
    //#include<algorithm> -> call -> next_permutation(s.begin(),s.end())

    if(rest_of=="") cout<<so_far<<endl;   
    else
        for (int i = 0; i < rest_of.length(); i++){

            string next = so_far + rest_of[i];
            string remder = rest_of.substr(0,i) + rest_of.substr(i+1);
            strpermutation(next,remder);
        }
}
void stringConcepts(){
    string s1 = "abcdefghf";

    s1.find_first_of('a'); //0
    s1.find_first_not_of('a'); //1 -> b
    s1.find_last_of('f'); //8
    s1.find_last_not_of('f'); //7 -> h

    cout<<s1.length(); //9
    //s1.replace("ab","cd");
    cout<<endl<<s1;
    isVowel('a'); //1 -> true
    strpermutation("","abc");
    
    cout<<strtol("2000",NULL/*end ptr*/,10/*base*/); //2000 as int  
}

//bit manipulation
string toBinary(int n){
    if(n>1) toBinary(n/2);
    cout<<n%2;
    return "";
}
int numOfBits(int n){
    int c=0;
    while(n) {n = n&(n-1);c++;}
    return c;
}
int getBitAtPos(int n,int pos){
    return ((n & (1<<pos)) != 0);
}
int setBitAtPos(int n,int pos){
    n = (n | (1<<pos));
    return n;
}
void isNumberBitwisePalindrome(int n){
    int rev = 0,aux = n;
    while(aux>0){
        rev = (rev << 1) | (aux & 1);
        aux = aux>>1;
    }
    if(rev==n) cout<<endl<<n<<" is bitwise palindrome.";
    else cout<<endl<<n<<" is not bitwise palindrome.";
}

void bitManipulation(){
    cout<<endl<<"BIT MANIPULATION: ";
    int n = 9;cout<<"No: "<<n<<endl;
    toBinary(n);cout<<endl;//1001
    cout<<endl<<numOfBits(n);
    isNumberBitwisePalindrome(n); //1001 true
    cout<<endl<<getBitAtPos(n,0); //1
    cout<<endl<<toBinary(n)<<"->"<<toBinary(setBitAtPos(n,1))<<endl;
}



int main(){
    stringConcepts();
    bitManipulation();
}

//#include <vector>

