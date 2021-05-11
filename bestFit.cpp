#include<bits/stdc++.h>
using namespace std;

vector<int> blockSize, processSize, DUP;

void inputBlock()
{
    int n;
    cout<<"\nEnter Number of Memory Blocks: ";
    cin>>n;

    cout<<"Enter Size of each Block: ";
    for(int i=0; i<n; i++)
    {
        int temp;
        cin>>temp;
        blockSize.push_back(temp);
    }
    DUP = blockSize;
}


void inputProcess()
{
    int n;
    cout<<"\nEnter Number of Processes: ";
    cin>>n;

    cout<<"Enter Size of each Process: ";
    for(int i=0; i<n; i++)
    {
        int temp;
        cin>>temp;
        processSize.push_back(temp);
    }
}


void bestFit()
{   
    cout<<"\n\nBEST FIT MEMORY TABLE:";
    cout<<"\n\nProcess No.\tProcess Size\tBlock Contained\n";

    for(int i=0; i<processSize.size(); i++)
    {
        int t = processSize[i];
        cout<<i+1<<"\t\t"<<t<<"\t\t";

        vector<pair<int,int>> minVals;
        for(int j=0; j<blockSize.size(); j++)
        {
            if(blockSize[j]>=t)
            {
                minVals.push_back(make_pair(blockSize[j], j));
            }
        }


        if(minVals.size()==0)
        {
            cout<<"None";
        }
        else
        {
            sort(minVals.begin(), minVals.end());
            int tempIndex=minVals[0].second;
            blockSize[tempIndex] = blockSize[tempIndex] - t;
            cout<<tempIndex+1;
        }
        
        cout<<endl;
    }
}


void findFrag()
{
    int frag=0;
    for(int i=0; i<DUP.size(); i++)
    {
        if(DUP[i]!=blockSize[i])
        {
            frag = frag + blockSize[i];
        }
    }
    cout<<"\n\nTotal Fragmentation: "<<frag;
}

int main()
{
    inputBlock();
    inputProcess();
    bestFit();
    findFrag();
}