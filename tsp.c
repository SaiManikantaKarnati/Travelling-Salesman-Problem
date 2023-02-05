#include<iostream>
using namespace std;
int c = 0, cost = 99;
int graph[4][4] = { {0, 4, 2, 6}, {4, 0, 5, 2}, {2, 5, 0, 6}, {6, 2, 6, 0} };

void display_graph()
{
    int i,j;
    for(i=0;i<4;i++)
    {
        cout << "\n";
        for(j=0;j<4;j++)
        {
            cout << "  " << graph[i][j];
        }    
    }
}

void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void copy_arr(int *array, int n)
{
    int i, total = 0;
    for(i=0;i<=n;i++)
        total = total + graph[array[i % 4]][array[(i + 1) % 4]];
    if(cost > total)
        cost = total;
}  

void calc(int *array, int i, int n) 
{
   int j, k; 
   if (i == n)
        copy_arr(array, n);
   else
   {
        for (j=i;j<=n;j++)
        {
            swap((array + i), (array + j));
            calc(array, i + 1, n);
            swap((array + i), (array + j));
        }
    }
} 

int main()
{
   int arr[] = {0, 1, 2, 3};  
   cout << "Cost matrix : " << endl;
   display_graph();
   calc(arr, 0, 3);
   cout << "\nMinimum distance to travel all routes : " << cost << endl;
}
