/*file: vigner cipher
  author: ahmed mohamed ahmed
  section : s11
  ID : 20231013*/
#include <iostream>
#include <string>
#include <cctype>

using namespace std;
    
void checklength(string phrase , int length){
    while(true){
        if (phrase.length() > length){
            cout << "please don't exceed " <<length <<" characters";
            getline(cin , phrase);
        }else if (phrase.length() <= length)
        {
            break ;
        }
        
    }
}

char get_char(int keyw,int result){
    for (int i = int('A');i <= int('Z');i++) {

        if ((i + keyw) % 26 == result) {
            return char(i);
        }
    }
}




void cipher(string message , string keyword){
    string newWord = ""; 
    int newcharacter ;
    cout << "enter the message you want to cipher (don't exceed 80 character) : ";
    getline(cin.ignore() , message) ;
    checklength(message , 80);
    cout << endl << "enter the keyword (don't exceed 8 characters): ";
    cin >> keyword ;
    cin.ignore();
    checklength(keyword , 8);
    while (message.length() > keyword.length())
    {
        keyword += keyword;
    }
    keyword = keyword.substr(0 , message.size());
    // cout << keyword ;
    for (int i = 0; i < message.length(); i++)
    {
        message[i] = toupper(message[i]);
        keyword[i] = toupper(keyword[i]);
        if (isalpha(message[i]))
        {
            newcharacter = (int(message[i]) + int(keyword[i])) % 26;
            newWord += char(newcharacter + 65);

        }else{
                newWord += message[i] ;
            }
    }

    cout << newWord << endl << endl ;

}

void decipher(string message , string keyword){
    string newWord = ""; 
    int originalCharacter ;
    cout << "enter the message you want to decipher (don't exceed 80 character) : ";
    getline(cin.ignore() , message) ;
    checklength(message , 80);
    cout << endl << "enter the keyword (don't exceed 8 characters): ";
    cin >> keyword ;
    cin.ignore();
    checklength(keyword , 8);
    while (message.length() > keyword.length())
    {
        keyword += keyword;
    }
    keyword = keyword.substr(0 , message.size());
    for (int i = 0; i < message.length(); i++)
    {
        message[i] = toupper(message[i]);
        keyword[i] = toupper(keyword[i]);
        originalCharacter = int(message[i]) - 65 ;
        if(isalpha(message[i]))
        {
            newWord += get_char(int(keyword[i]) , originalCharacter);
        }else{
            newWord += message[i]; 
        }
    }
    cout << newWord << endl << endl ;
}

int main () {
    char user_input1 ;
    string message ;
    string keyword ;
    cout << "welcome to vigner ciphering program \n";
    do
    {
        cout << "A) cipher a message "<< endl << "B) decipher a message" << endl << "C) exit the program \n";
        cout << "please enter your choice : ";
        cin >> user_input1 ;
        user_input1 = tolower(user_input1);
        switch (user_input1)
        {
        case 'a' :
            cipher(message , keyword) ;
            break;
        case 'b' : 
            decipher(message , keyword) ;
            break;
        case 'c' :
            cout << "thank you for using our program \n";
            break;
            return 0;
        default:
            cout << "please enter a valid choice: \n";
        }
    } while (user_input1 != 'c');
  


    return 0;
}
    