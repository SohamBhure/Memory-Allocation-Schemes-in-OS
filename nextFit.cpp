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

void nextFit()
{
    cout<<"\n\nNEXT FIT MEMORY TABLE:";
    cout<<"\n\nProcess No.\tProcess Size\tBlock Contained\n";

    int j=0;
    for(int i=0; i<processSize.size(); i++)
    {
        int t = processSize[i];
        cout<<i+1<<"\t\t"<<t<<"\t\t";

        int n = blockSize.size(), k=0, flag=0;

        while(k<n)
        {
            //cout<<j%n<<" ";
            if(blockSize[j%n]>=t)
            {
                flag = 1;
                cout<<(j%n)+1;
                blockSize[j%n] = blockSize[j%n] - t;
                //j++;
                break; 
            }
            j++;
            k++;
        }

        if(flag==0)
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
    nextFit();
    findFrag();
}
