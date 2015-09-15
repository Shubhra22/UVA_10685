//
//  main.cpp
//  UVA_10685
//
//  Created by Shuvro Sarker on 9/14/15.
//  Copyright (c) 2015 Shuvro Sarker. All rights reserved.
//

#include <iostream>
#include <map>
#include <string>
#define max 5005
using namespace std;

int par[max];
int num[max];
map<string, int> animal;

void makeSet(int x)
{
    animal.clear();
    par[x]=x;
    num[x]=1;
}

int Find(int x)
{
    if (par[x] == x)
    {
        return x;
    }
    return par[x]= Find(par[x]);
}


void Union(int x,int y)
{
    int u = Find(x);
    int v = Find(y);
    if(u!=v)
    {
        par[u] = v;
        num[v]+=num[u];
    }
}
int main(int argc, const char * argv[])
{
    int C,V;
    while(cin >> C >> V)
    {
        
        if(C<=0 && V <= 0) break;
        
        string anim1, anim2;
       
        for (int i =1; i<=C; i++)
        {
            makeSet(i);
        }
        
        for (int i = 1; i <=C; i++)
        {
            cin >> anim1;
            
            animal[anim1] = i;
            
            
        }
       
        while (V--)
        {
            cin >> anim1 >> anim2;
            Union(animal[anim1], animal[anim2]);
         }
        int Max = 0;
        for (int i = 1; i <= C; i++)
        {
            if(num[i] > Max)
            {
                Max=num[i];
            }
        }
        cout << Max<<endl;
    }
    
    return 0;
}
