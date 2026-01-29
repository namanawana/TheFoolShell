#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>
#include <sstream>
using namespace std;
int main(){
    string command;
    cout<<"Welcome to FoolShell v1.0\n";
    cout<<"Type 'help' for commands\n";
    vector<string>  history;

    while(true){
        cout<<"myshell> ";
        getline(cin,command);
        history.push_back(command);

        if (command=="exit"){
            cout<<"exiting shell...\n";
            break;
        }
        vector<string> tokens;
        stringstream ss(command);
        string word;
        while (ss>>word) tokens.push_back(word);
        if (tokens.size()==0) continue;
        if (tokens[0] == "help") {
            cout << "Available built-ins:/n";
            cout << "  cd <dir>    - change directory\n";
            cout << "  clear       - clear the screen\n";
            cout << "  exit        - exit the shell\n";
            cout << "  help        - show this help\n";
            cout << "  history     - show command history\n\n";
            cout << "External commands are executed using execvp.\n";
            cout << "  Any valid Linux command such as:\n";
            cout << "    ls, pwd, whoami, date, cat, gcc, python, etc.\n";
            cout << "  With arguments: e.g., ls -l, cat file.txt, gcc main.cpp\n\n";
            continue;
        }
        if (tokens[0]=="history"){
            for (int i = 0;i< history.size();i++) {
                cout << i+1 <<"."<< history[i]<< endl;
            }
            continue;
        }



        pid_t pid = fork();
        if (pid==0){
            vector<char*> args;
            for(auto &t : tokens) args.push_back((char*)t.c_str());
            args.push_back(NULL);
            execvp(args[0],args.data());
            cout<< "Command not found\n";
            exit(1);
        } else {
            wait(NULL);
        }
        
    }
    return 0;
    
}
