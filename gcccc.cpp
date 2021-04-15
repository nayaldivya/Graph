#include <bits/stdc++.h>
using namespace std;


void encrypt(string words) {
    
   // Participant's code will go here
    words.erase(remove(words.begin(), words.end(), ' '), words.end());
    cout  << words << " ";
    int n=words.size(); int k=0;
    cout << n << "\n";
    int row,column;
    if((floor(sqrt(n)) * ceil(sqrt(n)) >= n))
    {   
		cout << "1\n";
		row=floor(sqrt(n));
        column=ceil(sqrt(n));
        cout << row << " "<< column << "\n";
    }
    else
    {
        cout << "2\n";
		row=ceil(sqrt(n));
        column=ceil(sqrt(n));
        cout << row << " "<< column << "\n";
    }
    char matrix[row][column];
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            matrix[i][j]=words[k++];
        }
	}
    for(int i=0;i<column;i++)
    {
        for(int j=0;j<row;j++)
        {
            cout << matrix[i][j];
        }
        if(i==column-1) return;
        cout<<" ";
    }
}


int main() {
    string words;
    getline(cin, words);

    encrypt(words);

    // Do not remove below line
    //cout << result << "\n";
    // Do not print anything after this line

    return 0;
}


