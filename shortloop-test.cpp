
#include <bits/stdc++.h>
#define io  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;


vector<string> split(string str, string token){
    vector<string>result;
    while(str.size()){
        int index = str.find(token);
        if(index!=string::npos){
            result.push_back(str.substr(0,index));
            str = str.substr(index+token.size());
            if(str.size()==0)result.push_back(str);
        }else{
            result.push_back(str);
            str = "";
        }
    }
    return result;
}
 

struct dir{
	string name;
	vector<dir*> childs;
	vector<string> text_files;
};

dir*root_pointer;

void pwd(dir* d){
 	cout<<"pwd: "<<d->name<<endl;
}

dir* create_dir(string name) {
    dir* newNode = new struct dir();
    newNode->name = name;
    newNode->childs = {};
    newNode->text_files = {};
    return newNode; 
}

void mkdir(dir* d, string new_dir_name){
	cout<<endl;
	cout<<"mkdir "<<new_dir_name<<endl;
	dir * temp =  create_dir(new_dir_name);
	d->childs.push_back(temp);
}


void ls(dir* d){

	cout<<endl;

	cout<<"ls:"<<endl;

	cout<<"name "<<d->name<<endl;

	cout<<"directories: "<<d->childs.size()<<endl;
	for(int i=0;i<d->childs.size();i++){
		dir *temp = (d->childs)[i];

		cout<<"dir "<<i<<":"<<d->childs[i]->name<<endl;
	}


	cout<<"files: "<<d->text_files.size()<<endl;
	for(int i=0;i<d->text_files.size();i++){
		cout<<"file "<<i<<":"<<d->text_files[i]<<endl;
	}

	cout<<endl;
}



dir* cd(string path){

	cout<<endl;
	cout<<"cd "<< path<<endl;
	vector<string> dirs = split(path, "/");
	dir * current_dir = root_pointer;


	for(int i=1;i<dirs.size();i++){
		vector<dir*> childs = current_dir->childs;


		bool found = false;


		for(int j=0;j<childs.size();j++){
			if(childs[j]->name==dirs[i]){
				current_dir = childs[j];
				found = true;
			}
		}

		if(found==false){
		}

	}

	return current_dir;
}



void touch(dir* d, string filename){
	cout<<endl;
	cout<<"touch "<<filename<<endl;
	// string new_file_path = d->name + "/" + filename;
	d->text_files.push_back(filename);
}
 
void solve() {
    
    dir root = {"/",{},{}};
    root_pointer = &root;
    dir* pwd_pointer = &root;


    pwd(pwd_pointer);

    ls(pwd_pointer);

    mkdir(pwd_pointer, "aniket");
    mkdir(pwd_pointer, "rawat");

    touch(pwd_pointer, "file1");
    touch(pwd_pointer, "file2");

    ls(pwd_pointer);

    pwd_pointer = cd("/aniket");

    pwd(pwd_pointer);
    ls(pwd_pointer);

    mkdir(pwd_pointer, "new_dir1");
    touch(pwd_pointer, "new_file1");

    ls(pwd_pointer);

    pwd_pointer = cd("/aniket/new_dir1");

    ls(pwd_pointer);

    pwd_pointer = cd("/aniket");

    pwd(pwd_pointer);
    ls(pwd_pointer);

}
 
int main() { io

    int t=1; 
    // cin>>t; 
    while (t--) {
        solve();
    }
    return 0;
}