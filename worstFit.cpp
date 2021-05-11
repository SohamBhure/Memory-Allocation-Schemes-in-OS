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


void worstFit()
{   
    cout<<"\n\nWORST FIT MEMORY TABLE:";
    cout<<"\n\nProcess No.\tProcess Size\tBlock Contained\n";

    for(int i=0; i<processSize.size(); i++)
    {
        int t = processSize[i];
        cout<<i+1<<"\t\t"<<t<<"\t\t";

        int temp=0, tempIndex=0;
        for(int j=0; j<blockSize.size(); j++)
        {
            if(blockSize[j]>=temp)
            {
                temp = blockSize[j];
                tempIndex = j;
            }
        }

        if(blockSize[tempIndex]>=t)
        {
            cout<<tempIndex+1;
            blockSize[tempIndex] = blockSize[tempIndex] - t;
        }
        else
        {
            cout<<"None";
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
    worstFit();
    findFrag();
}