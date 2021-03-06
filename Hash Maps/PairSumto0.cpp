// Pair Sum to 0
// Using HashMaps

#include<iostream>
using namespace std;
#include<unordered_map>

void PairSum(int *input, int n) {

	unordered_map<int,int> m;
        for(int i=0;i<n;i++){

     	int rep = m.count(0-input[i]);
        if(rep>0){
            for(int j=0;j<m[0-input[i]];j++){
                if(input[i]<0-input[i]){
                    cout<<input[i]<<" "<<0 - input[i]<<endl;
                }
                else{
                    cout<<0-input[i]<<" "<<input[i]<<endl;
                }
            }
         }
            if(m.count(input[i])>0)
                m[input[i]]++;
            else
                m[input[i]]=1;
     	}

 }

int main()
{
    int n;
    int arr[100000];
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    PairSum(arr, n);
    return 0;
}
