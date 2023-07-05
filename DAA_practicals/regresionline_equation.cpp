#include<iostream>
#include<vector>

using namespace std;

vector<int > line( vector<int > x,vector<int> y){
    float x_mean=0;
    float y_mean=0;
    for(auto  count : x){
        x_mean=x_mean+ count;
    }
    for(auto  count2 : y){
        y_mean=y_mean+ count2;
    }

    vector<float> _x ;
    vector<float> _y ;
    for( auto count : x){
        _x.push_back(count - x_mean);
    }
    for( auto count : y){
        _y.push_back(count - y_mean);
    }

    vector<float> _x2;
    vector<float> _y2;
    for(auto count : _x){
      _x2.push_back(count*count);
    } 
    for(auto count : _y){
      _y2.push_back(count*count);
    } 

    float b1=0;
    float _x2mean;
    for(auto count : _x2){
        _x2mean=_x2mean+count;
    } 
    float _y2mean;
    for(auto count : _y2){
        _y2mean=_y2mean+count;
    }

    b1= 
        
}