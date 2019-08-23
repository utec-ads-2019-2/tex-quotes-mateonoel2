#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
    string text;

    int counter = 0;

    auto *Queue = new queue<string>;

    while(getline(cin, text)){

        if(text.empty()){
            break;
        }

        for(int i=0; i<text.size(); i++) {
            if (text[i] == '\"') {
                if(counter==0){
                    text.replace(text.find('\"'), 1, "``");
                }
                else if(counter==1){
                    text.replace(text.find('\"'), 1, "''");
                }
                counter++;

                if(counter==2){
                    counter=0;
                }
            }
        }

        Queue->push(text);
    }

    while(!Queue->empty()){
        cout << Queue->front()<<'\n';
        Queue->pop();
    }

    return 0;
}
