#include<iostream>
using namespace std;
void print(int arr[9][9])
{
    cout<<"Solved Sudoku:"<<endl;
    for(int i=0;i<9;i++)
        {for(int j=0;j<9;j++){
        cout<<arr[i][j]<<" ";}
        cout<<endl;}
}
bool safe(int arr[9][9],int r,int c,int n)
{
    for(int i=0;i<9;i++)
        if(arr[r][i]==n)
        return false;
    for(int i=0;i<9;i++)
        if(arr[i][c]==n)
        return false;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        if(arr[i+(r-r%3)][j+(c-c%3)]==n)
        return false;
    return true;
}
int Sudoku(int arr[9][9],int r,int c)
{
    if(r==8 && c==9)
        return 1;
    if(c==9){
        r++;
        c=0;
    }
    if(arr[r][c]!=00)
        return Sudoku(arr,r,c+1);
    for(int i=1;i<=9;i++)
    {
        if(safe(arr,r,c,i)==true)
        {
            arr[r][c]=i;
            if(Sudoku(arr,r,c+1))
                return 1;
        }
        arr[r][c]=0;
    }
    return 0;
}
int main()
{
    int arr[9][9];
    cout<<"Enter values:'00' means vacant places"<<endl;
    for(int i=0;i<9;i++)
    for(int j=0;j<9;j++)
    cin>>arr[i][j];
    if(Sudoku(arr,0,0)==1)
      print(arr);
    else
      cout<<"No Solution exists...try again!!"<<endl;
    return 0;
}
