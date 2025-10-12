#include <iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter number of items: ";
    cin>>n;
    cout<<"enter the  no of person:";
    int k;

    int start[100] ,end[100];
   int person[10]={0};

   cout<<"enter the strttime of shop:\n";
    for(int i=0;i<n;i++){
         cin>>start[i];
    }
    cout<<"enter the time of shop :\n";
    for(int i=0;i<n;i++){
         cin>>end[i];
    }
    
    for(int i=0; i<n; i++){
        for(int j=0;j<n-1; j++){
            if(end[j]>end[j+1]){
               
                int temp=end[j];
                end[j]=end[j+1];
                end[j+1]=temp;

                temp=start[j];
                start[j]=start[j+1];
                start[j+1]=temp;

            }
        }

    }
    int count=0;
    for (int i=0; i<n; i++){
        cout<<"shop"<<i+1<<":"<<start[i]<<"to"<<end[i]<<endl;

        
    }
    cout<<"you entered:\n";
    for(int i=0; i<n; i++){
          cout<<"shop"<<i+1<<":"<<start[i]<<"to"<<end[i]<<endl;
    }
    return 0;
}
