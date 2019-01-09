

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;




void database(fstream inFile){};

void adjfunc(int i, string item, string b){

    string adj = "";
     while(item.at(i) != '.'){
        adj += item.at(i);

        i++;

    }

    cout  << b << " Adjective-->" << adj << endl;
}

void nounfunc(int i, string item, string b){
    string noun = "";
    while(item.at(i)!= '.'){
        noun += item.at(i);
       i++;
    }

    cout << b << " Noun-->" << noun << endl;

};



void verbfunc( int i, string item, string b){

    

    string verb = "";
    
    while(item.at(i) != '.'){

        verb += item.at(i);

        i++;

    }

    cout << b << " " << verb << endl;

};

int main() {
    vector<std::string>::iterator itr;
    fstream inFile;
    inFile.open("..."); //Text File Path Goes Here
    
    if(inFile.fail()){
        cerr << "ERROR" << endl;
        exit(1);
    }
    
    string item;
    while(!inFile.eof()){
        string a,b,noun,adj,verb;
        getline(inFile,item);
        
        //This loop reads the first word and find the '|'. After it is found it jumps to read the rest of the sentence
        string c;
        int i =0;
       while(i < item.size()){
            if(item.at(i) == '|'){
                i++;
                break;
            }else{
                b+=item.at(i);
                i++;
            }
        }
        
        /*
        string delimieter = "|";
        string token;
        size_t pos = 0;
         */
        
       //This loop reads if it is either a noun, verb or adjective
       while(i < item.size()){
         if(item.at(i) == '|'){
         
           break;
      }else{
          c+=item.at(i);
          
       
      /*  while((pos = item.find(delimieter))!=std::string::npos){
            token = item.substr(0, pos);
            cout << token << endl;
            item.erase(0,pos + delimieter.length());
            c +=item.at(i);
            */
       if(c == "noun"){
                nounfunc(i+4,item,b);
               c = "";
            }
          if(c == "adjective"){
              adjfunc(i+4, item,b);
              c="";
             
          }
          if(c == "verb"){
              verbfunc(i+4, item,b);
              c="";
          }
          
           i++;
            
    }
        
    
}
        
    }return 0;
}
    


    



  
