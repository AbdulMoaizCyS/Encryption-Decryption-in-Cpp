#include <iostream>
#include <vector>
#include <fstream>
#include <string>

std::vector<std::string> Encrypt();
std::vector<std::string> DecryptFile(std::string path);

int main(){

    std::string Choice;
    std::vector<std::string> Encrypted;
    std::vector<std::string> Decrypted;

    do{
        std::cout << "=========================\n";
        std::cout << " VADERS CEASER SHIFT SIM\n";
        std::cout << "=========================\n";
        std::cout << "---->ENTER '1' TO ENCRYPT A MESSAGE!<----\n";
        std::cout << "---->ENTER '2' TO DECRYPT A MESSAGE!<----\n";
        std::cout << "---->ENTER '-1' TO EXIT THE SIM!<----\n";
        std::cin >> Choice;

        if(Choice == "1"){

            std::string C;
            Encrypted = Encrypt();
            do{

                std::cout << "---->IF YOU WISH TO SEE YOUR ENCRYPTED TEXT PLEASE PRESS '1'!<----\n";
                std::cout << "---->IF YOU WISH TO SAVE YOUR ENCRYPTED TEXT IN A FILE PLEASE PRESS '2'!<----\n";
                std::cout << "---->IF YOU WISH TO DO NOTHING, PLEASE PRESS '-1'!(WARNING! ENCRYPTED TEXT WILL BE LOST!)<----\n";
                std::cin >> C;

                if(C == "1"){

                    for(int i=0;i<Encrypted.size();i++){
                        std::cout << Encrypted[i] <<std::endl;
                    }

                }else if(C == "2"){
                    std::string path;
                    
                    std::cout << "---->PLEASE ENTER FILE PATH, WHERE YOU WOULD LIKE THE ENCRYPTED TEXT TO BE STORED!<----\n";
                    std::getline( std::cin >>std::ws, path);

                    std::ofstream  file(path);

                    if(file.is_open()){

                        for(int i=0;i<Encrypted.size();i++){
                            file << Encrypted[i] << std::endl;
                        }
                        file.close();
                        std::cout << "---->ENCRYPTED TEXT HAS BEEN STORED SUCCESFULY AT: " << path << "<----\n" << std::endl;
                    }else{
                        std::cout << "---->ERROR!! INVALID FILE PATH PROVIDED!!!!!!!!!<----\n";
                    }



                }else if(C == "-1"){
                    std::cout << "----> '-1' DETECTED!<----\n";
                }else{
                    std::cout << "---->ERROR! INCORRECT OPTION!<----\n";
                }

            }while(C!="-1");

        }else if(Choice == "2"){
            std::string C1;

            std::string FilePath;
            std::cout << "---->PLEASE ENTER THE FILE PATH WHERE ENCRYPTED TEXT IS STORED!<----\n";
            std::cin >> FilePath;
            Decrypted = DecryptFile(FilePath);

            do{
                std::cout << "---->IF YOU WISH TO SEE YOUR DECRYPTED TEXT PLEASE PRESS '1'!<----\n";
                std::cout << "---->IF YOU WISH TO SAVE YOUR DECRYPTED TEXT IN A FILE PLEASE PRESS '2'!<----\n";
                std::cout << "---->IF YOU WISH TO DO NOTHING, PLEASE PRESS '-1'!(WARNING! DECRYPTED TEXT WILL BE LOST!)<----\n";
                std::cin >> C1;

                if(C1 == "1"){
                    for(auto it=Decrypted.begin();it<Decrypted.end();it++){
                        std::cout << *it << '\n';
                    }
                }
                else if(C1 == "2"){
                    std::string path;
                    std::cout << "---->PLEASE ENTER THE PATH WHERE YOU WOULD LIKE TO STORE DECRYPTED TEXT!<----\n";
                    std::getline(std::cin >>std::ws, path);

                    std::ofstream file(path);

                    if(file.is_open()){
                        for(int i=0;i<Decrypted.size();i++){
                            file << Decrypted[i] << '\n';
                        }
                        file.close();
                        std::cout << "---->DECRYPTED TEXT SUCESSFULY STORED AT: " << path << " !<----\n";
                    }else{
                        std::cout << "---->ERROR! INVALID FILE PATH!<----\n";
                    }


                }else if(C1 == "-1"){
                    std::cout << "----> '-1' DETECTED! EXITING!<----\n";
                }else{
                    std::cout << "---->INVALID CHOICE!!!!!<----\n";
                }
            }while(C1!="-1");


        }else if(Choice == "-1"){
            std::cout << "---->EXITING VADERS CEASER SIM<----\n";
        }else{
            std::cout << "---->INVALID INPUT!! TRY AGAIN!!<----\n";
        }




    }while(Choice != "-1");



    return 0;
}


std::vector<std::string> Encrypt(){
    std::vector<std::string> EncryptedText;
    std::string line;

    std::string temp;
    char t;
    int length=0;

    do{

        std::cout << "---->PLEASE ENTER A LINE OF TEXT!(IF YOU WISH TO STOP ENTERING LINES ENTER '-1')!<----\n";
        std::getline(std::cin >>std::ws ,line);

        if(line=="-1"){
            std::cout << "---->'-1' DETECTED!<----\n";

        }else{
            length = line.length();
            temp="";
            for(int i=0;i<length;i++){
    
                t = line[i];
                if(t>='a' && t <='z'){
                    temp+="|";
                    temp +=std::to_string((int(((t-'a'+3)%26) + 'a')));  
                    temp+="|";
                }else if(t>='A' && t <= 'Z'){
                    temp+="|";
                    temp +=std::to_string((int(((t-'A'+3)%26) + 'A'))) ;  
                    temp+="|";

                }else{
                    temp+="||";
                    temp+=std::to_string(int(t));
                    temp+="|";
                }
            }

            EncryptedText.push_back(temp);
        }



    }while(line!="-1");



    return EncryptedText;

}


std::vector<std::string> DecryptFile(std::string path){

    std::vector<std::string> DecodedText;
    std::ifstream file(path);
    std::string line;

    if(file.is_open()){

        std::string temp;
        std::string decoded;
        char C;
        int t=0;
        while(std::getline(file,line)){
            decoded="";temp="";
            C=' ';t=0;
            int i=0;
            while(i<line.size()){
                temp.clear();
                if(line[i] == '|'){
                    if(i+1 <line.size() && line[i+1] == '|'){
                        i+=2;
                        while(i < line.size() && line[i] != '|'){
                            temp+=line[i];
                            i++;
                        }
                        t=std::stoi(temp);
                        C = char(t);
                        decoded += C;
                        if(i<line.size() && line[i] == '|'){
                            i++;
                        }


                    }else{
                        i++;
                        while(i < line.size() && line[i] != '|'){
                            temp+=line[i];
                            i++;
                        }
                        t=std::stoi(temp);
                        if(t>= 65 && t <= 90){
                            C = char(((t-'A' -3 +26)%26) + 'A');
                            decoded += C;
                        }else if( t >= 97 && t <= 122){
                            C = char(((t-'a' -3 +26)%26) + 'a');
                            decoded += C;
                        }
                        if(i<line.size() && line[i] == '|'){
                            i++;
                        }

                    }
                }else{
                    i++;
                }

                

            }
            DecodedText.push_back(decoded);
        }
        file.close();
    }else{
        std::cout << "---->ERROR! INVALID FILE PATH!<----\n";
    }

    return DecodedText;

}