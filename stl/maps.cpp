#include <bits/stdc++.h>
using namespace std;

//for more info visit cpprefeerence....

int main(){
  map<string, int> marksMap;
  marksMap["s1"] = 21;
  marksMap["s2"] = 22;
  marksMap["s3"] = 23;
  marksMap["s4"] = 24;

//iterating a map
  map<string, int> :: iterator iter;
  for(iter=marksMap.begin();iter!=marksMap.end();iter++){
    cout<<(*iter).first<<" "<<(*iter).second<<"\n";//.first is the key & .second is the value, where *iter is the entry in the map 
  }
  

//inserting
  marksMap.insert({{"s5",12},{"s6",199}});

  //after insertion
  cout<<"after inserting\n";
  for(iter=marksMap.begin();iter!=marksMap.end();iter++){
    cout<<(*iter).first<<" "<<(*iter).second<<endl;
  }
  
  return 0;
}