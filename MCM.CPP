#include<iostream.h>
#include<conio.h>
#include<string.h>
#define MAX_STRLEN 60
#define MAX_SIZE 30
#define MAX_ORDER 10
struct String{
char string[MAX_STRLEN];
int length(){
 for(int s=0;string[s]!='\0';s++);
  return s;
}


};
struct position{
int position;
char position_name[3];
};
struct matrix{
int value;
int k;
};

class MatrixChain{
struct position position[MAX_SIZE];
struct String String,Result_String;
struct matrix matrix[MAX_ORDER][MAX_ORDER];
int positions;
int k_array[2][MAX_ORDER-1];
public:
MatrixChain(){
positions=0;
}

void set_position(){
int type=0;
cout<<"Select Input Type"<<endl;
cout<<"1)Matrix Order Types Values:(2*3,3*4,4*5)"<<endl;
cout<<"2)Direct Position:(2 3 4 5)"<<endl;
cin>>type;

while(type!=1&&type!=2){
 cout<<"Please Select Currect Type!"<<endl;
 cout<<"1)Matrix Order Types Values:(2*3,3*4,4*5)"<<endl;
 cout<<"2)Direct Position:(2 3 4 5)"<<endl;
 cin>>type;
}

if(type==2){
cout<<"Enter Total Number Of the Positions: ";
cin>>positions;
cout<<"Enter "<<positions<<" Positions"<<endl;

  for(int s=0;s<positions;s++){
    cin>>position[s].position;

     if(s>9){
       position[s].position_name[0]='P';
       position[s].position_name[1]=(s%10)+'0';
       position[s].position_name[2]=(s/10)+'0';
       position[s].position_name[3]='\0';
     }else{
       position[s].position_name[0]='P';
       position[s].position_name[1]=s+'0';
       position[s].position_name[2]='\0';
     }

  }

}else{
cout<<"Enter The Matrix Order"<<endl;
cin>>String.string;
extract_position();
}
show_position();
}


void MCM(){
matrix[positions][positions];
// bydefault matrix's element is zero
 set_Zeros();
int row;
  for(int s=0;s<positions-2;s++){
     row=0;
     for(int j=s+1;j<positions-1;j++){
	 min(row++,j);
     }
  }
  show_matrix();
}

int set_k_array(){
int length=0;
int row=0;
  for(int s=0;s<positions;s++){
       row=0;
       for(int j=s+1;j<positions-1;j++){

	    if(!is_present(matrix[row][j].k,length)){
		k_array[0][length]=matrix[row][j].k;
		k_array[1][length++]=1;
	    }else{

		  for(int k=0;k<length;k++){
		     if(k_array[0][k]==matrix[row][j].k){
			  k_array[1][k]+=1;
			    break;
			}
		    }

	     }
       row++;
     }
  }

 return length;
}

void set_parentheses(){

 int length=set_k_array();
    sort(length);

 int string_len=0;
 for(int s=1;s<positions;s++){

      Result_String.string[string_len++]='A';

     if(s>9){
       Result_String.string[string_len++]=s%10+'0';
       Result_String.string[string_len++]=s/10+'0';
       Result_String.string[string_len++]=' ';
     }else{
      Result_String.string[string_len++]=s+'0';
      Result_String.string[string_len++]=' ';
     }
 }
 Result_String.string[string_len-1]='\0';
//......................
// (A1 A2)*((A3*A4)*A5)
//\/\/\/\/\/\/\/\/\/\/\/\

for(s=0;s<length;s++){
  int m=k_array[0][s];
 if(k_array[1][s]!=k_array[1][s+1] && s<length/2+1){
    for(int j=0;j<Result_String.length();j++){
      if((Result_String.string[j]-'0')==m+1){
	  addSpace(j+1);
	  int k=j+1;
	  j+=3;
	   Result_String.string[j++]='(';

	    while(Result_String.string[j+1]!='\0'
		  &&(Result_String.string[j+2]!='(')){

		  Result_String.string[j]=Result_String.string[j+1];
		  j++;
	       }
	     Result_String.string[j]=')';
	     j=k+1;
	     Result_String.string[j--]=')';

	   while(j!=0 && Result_String.string[j-2]!=')'){
	     Result_String.string[j]=Result_String.string[j-1];
	      j--;
	     }
	      Result_String.string[j]='(';
	     break;
	 }
     }
   }
}

 cout<<Result_String.string<<endl;
}

private:

void addSpace(int index){
int length=Result_String.length();

// add space
for(int s=length;s<length+4;s++){
  Result_String.string[length]=' ';
}
Result_String.string[s]='\0';
length+=4;
//shift elements
for(s=length-1; s>index+4;s--){
 Result_String.string[s]=Result_String.string[s-4];

}

for(s=index+1;s<=index+4;s++){
Result_String.string[s]=' ';
}

}

void sort(int length){
 for(int s=1;s<length;s++){
   for(int j=0;j<length-s;j++){
     if(k_array[1][j] < k_array[1][j+1]){

       int value=k_array[0][j];
       int k=k_array[1][j];
	   k_array[0][j]=k_array[0][j+1];
	   k_array[1][j]=k_array[1][j+1];

	   k_array[0][j+1]=value;
	   k_array[1][j+1]=k;
     }
   }
 }

}

int is_present(int find,int length){
 for(int s=0;s<length;s++){
   if(k_array[0][s]==find){
     return 1;
   }
 }
 return 0;
}

void min(int i,int j){
int min_array[2][MAX_ORDER];
int length=0;
 for(int k=i;k<j;k++){
    min_array[0][length]=solve(i,j,k);
    min_array[1][length++]=k;
 }


int value=min_array[0][0];
int key=min_array[1][0];

for(k=1;k<length;k++){
  if(value>min_array[0][k]){
    value=min_array[0][k];
    key=min_array[1][k];
  }
}
matrix[i][j].value=value;
matrix[i][j].k=key;
}

int solve(int i,int j,int k){
 return (
    matrix[i][k].value + matrix[k+1][j].value+ (
       position[i].position * position[k+1].position * position[j+1].position
    )
 );
}

void set_Zeros(){

 for(int s=0;s<positions-1;s++){
    matrix[s][s].value=0;
 }
}

void extract_position(){
int save;
 for(int s=0;s<String.length();){

    if(String.string[s]!=','&&String.string[s]!='*'&&String.string[s]!='\0'){
      save=0;
     // for 10*99,99*100
	while(String.string[s]!=','&&String.string[s]!='*'&&String.string[s]!='\0'){
	    save=(save*10)+(String.string[s]-'0');
	  s++;
	}
	position[positions].position=save;

	 if(positions>9){
	    position[positions].position_name[0]='P';
	    position[positions].position_name[1]=positions%10+'0';
	    position[positions].position_name[2]=positions/10+'0';
	    position[positions].position_name[3]='\0';
	 }else{
	    position[positions].position_name[0]='P';
	    position[positions].position_name[1]=positions+'0';
	    position[positions].position_name[2]='\0';
	 }
	 positions++;
    }else if(String.string[s]==','){
      while(String.string[s]!='*')
       s++;
    }else if(String.string[s]=='*'){
      s++;
    }else{
     s++;
    }
 }
}
void show_position(){
for(int s=0;s<positions;s++){
  cout<<position[s].position<<" "<<position[s].position_name<<endl;
}
}
void show_matrix(){
  for(int s=0;s<positions-1;s++){

     for(int j=0;j<positions-1;j++){
	cout<<matrix[s][j].value<<"."<<matrix[s][j].k<<" |";
     }
     cout<<endl;
  }
}
}x;


void main(){
clrscr();
x.set_position();
x.MCM();
x.set_parentheses();
getch();
}

