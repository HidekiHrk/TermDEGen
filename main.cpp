#include <iostream>
#include <fstream>

using namespace std;

void printHelp(string funcname, bool help = false){
    if(help){
        cout << "use mode:\n"
        << funcname << " [name] [comment] [path] [icon] [categories]"
        << endl;  
    }
    else{
        cout << "To view help, use: " << funcname << " --help" << endl;
    }

}

int main(int argc, char **args){
    if(argc > 1){
        // printHelp(args[0]);
        if(args[1] == (string) "--help" && argc == 2){
            printHelp(args[0], true);
        }
        else if (argc <= 6){
            string path = "./";
            path += args[1];
            path += ".desktop";
            ofstream file(path);
            if(file.is_open()){
                file << "[Desktop Entry]\nVersion=1.0\nType=Application" << endl;
                string argnames[] = {"Name", "Comment", "Exec", "Icon", "Categories"};
                for(int x = 0; x < argc - 1; x++){
                    string arg = argnames[x];
                    arg += "=";
                    arg += args[x+1];
                    file << arg << endl;
                }
                file << "Terminal=false\nStartupNotify=false" << endl;
                file.close();
                string com = "chmod +x " + path;
                const char *command = com.c_str();
                system(command);
            }
        }
        else{
            printHelp(args[0]);
        }
    }
    else{
        printHelp(args[0]);
    }
    return 0;
}