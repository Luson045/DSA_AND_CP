#include <bits/stdc++.h>
using namespace std;

long long main() {
	// your code goes here
    long long t;
    cin>>t;
    while(t--){
        long long n,m;
        cin>>n>>m;
        vector<string>s(m);
        for(long long i=0;i<m;i++){
            cin>>s[i];
        }
        long long hamming_sum=0;
        for(long long i=0;i<n;i++){
            long long c0=0,c1=0,cq=0;
            for(long long j=0;j<m;j++){
                if(s[j][i]=='0'){
                    c0++;
                }else if(s[j][i]=='1'){
                    c1++;
                }else{
                    cq++;
                }
            }
            if(cq>0){
                long long total=c0+c1+cq;
                long long majority=total/2;
                if(c0>c1){
                    long long f1=min(cq,majority-c1);
                    c1+=f1;
                    c0+=cq-f1;
                }else{
                    long long f0=min(cq,majority-c0);
                    c0+=f0;
                    c1+=cq-f0;
                }
            }
            hamming_sum+=(c0*c1);
        }
        cout<<hamming_sum<<endl;
    }
    return 0;
}
