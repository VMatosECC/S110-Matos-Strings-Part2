// S110-Matos-Strings-Part2.cpp 

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

//Prototypes----------------------------------
void experiment01();
void experiment02();
void experiment03();
string natoCoding(string s, vector<string> vNatoCode);
string bubbleSort(string s);

int main()
{
    //experiment01();
    //experiment02();
    experiment03();

    cout << "Hello World!\n";
}
void experiment03()
{
    //Tokenizer (extract words from a string)
    string s = "The brown fox jumps over the lazy dog";

    string head = "";
    string rest = s;

    while (rest.size() > 0) {
        int blank = rest.find(" ");
        if (blank < 0) {
            head = rest;    //last token!
            rest = "";
        }
        else {
            head = rest.substr(0, blank);
            rest = rest.substr(blank + 1);
        }
        cout << "head [" << head << "]" 
            << "\t\trest [" << rest << "]" << endl;
    }
}



// Anagrams -------------------------------------
void experiment02()
{
    string s1 = "state";
    string s2 = "taste";
    string sorted1 = bubbleSort(s1);
    string sorted2 = bubbleSort(s2);
    if (sorted1 == sorted2)
    {
        cout << s1 << " and " << s2 << " are anagramatic " << endl;
    }
    else {
        cout << s1 << " and " << s2 << " are NOT anagramatic " << endl;
    }



}




//User-Defined Functions ------------------------
string bubbleSort(string s)
{
    for (int right = s.size() - 1; right > 0; right--)
    {
        for (int i = 0; i < right; i++)
        {
            if (s[i] > s[i + 1]) {
                swap(s[i], s[i+1]);
            }
        }
    }
    return s;
}





void experiment01()
{
    //Encode string using NATO code
    vector<string> vLetter;
    vector<string> vNatoCode;

    ifstream natofile("c:/temp/natocode.txt");
    if (!natofile) {
        cout << "ERROR - File not found\n";
        exit(1);
    }

    string letter, code, sound;
    while (getline(natofile, letter, ',')) {
        getline(natofile, code, ',');
        getline(natofile, sound);

        cout << letter << "\t" << code << endl;
        vLetter.push_back(letter);
        vNatoCode.push_back(code);

    }
    natofile.close();

    string s = "BARTSIMPSON";
    string encodedStr = natoCoding(s, vNatoCode);
    cout << s << endl;
    cout << encodedStr << endl;
}

string natoCoding(string s, vector<string> vNatoCode)
{  
    string res = "";
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        string nato = vNatoCode[c - 'A'];
        res.append(nato);
        res.append(", ");
    }
    return res;
}