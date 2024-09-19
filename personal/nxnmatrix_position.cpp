#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<int>current(2,0);
        int direction=0,maxx=INT_MIN,maxy=INT_MIN;
        for(int &i:commands){
            for(int i:current){
                cout<<i<<",";
            }
            cout<<endl;
            if(i==-1){
                cout<<"turning right\n";
                if(direction==3)
                    direction=0;
                else
                    direction+=1;
            }else if(i==-2){
                cout<<"turning left\n";
                if(direction==0)
                    direction=3;
                else
                    direction-=1;
            }else{
                if(direction==0){
                    cout<<"going top\n";
                    current[1]+=i;
                    for(vector<int> j:obstacles){
                        if(j[0]==current[0]&&j[1]<current[1]&&j[1]>current[1]-i)
                            current[1]=j[1]-1;
                            break;
                    }
                }else if(direction==1){
                    cout<<"going right\n";
                    current[0]+=i;
                    for(vector<int> j:obstacles){
                        if(j[1]==current[1]&&j[0]<current[0]&&j[0]>current[0]-i)
                            current[0]=j[0]-1;
                            break;
                    }
                }else if(direction==2){
                    cout<<"going left\n";
                    current[1]-=i;
                    for(vector<int> j:obstacles){
                        if(j[0]==current[0]&&j[1]>current[1]&&j[1]<current[1]+i)
                            current[1]=j[1]+1;
                            break;
                    }
                }else if(direction==3){
                    cout<<"going down\n";
                    current[0]-=i;
                    for(vector<int> j:obstacles){
                        if(j[1]==current[1]&&j[0]>current[0]&&j[0]<current[0]+i)
                            current[0]=j[0]+1;
                            break;
                    }
                }
            }
            if(abs(current[0])>maxx)
                maxx=current[0];
            if(abs(current[1])>maxy)
                maxy=current[1];
        }
        return maxx*maxx+maxy*maxy;
    }
};

int main(){
  Solution s1;
  vector<int> stp = {7,-2,-2,7,5};
  vector<vector<int>> obs = {{-3,2},{-2,1},{0,1},{-2,4},{-1,0},{-2,-3},{0,-3},{4,4},{-3,3},{2,2}};
  cout<<s1.robotSim(stp, obs);
  return 0;
}