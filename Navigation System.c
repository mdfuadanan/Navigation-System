# include <stdio.h>
# include <string.h>
# define M 100// M for Max
# define B 9 // B for Bolocks
typedef struct{
int to;
char path_name[10];
} E; // E for Edge
E matrix[B][M];// This line makes a makes a 2D array which is used as (9*4)matrix for edge
int Enumber[B]={0};// Edge number for Enumber
int BTI (char C);// BTI for Blocks to Index trancformation
char ITB (int i);// ITB for Index to Blocks trancformation
void Generate_map();// Void Decalration for generating map function
void New_path(char a,char b, char *path_name);// Void Decalration for making path
void travel(char a, char b);// This is for path search
void Delete_path(char a, char b,char *path_name);// This is for delete path
int main()
{
    Generate_map();
    while(1){
    int Option;
    char a,b,path_name[10];
        printf("            <-Street 1->   \n");
        printf("        A--------B--------C\n");
        printf("        |        |        |\n");
        printf("        |   <-Street 2->  |\n");
        printf("Road 1  | Road 2 | Road 3 |\n");
        printf("        D--------E--------F\n");
        printf("        |        |        |\n");
        printf("        |    <-Street 3-> |\n");
        printf("        |        |        |\n");
        printf("        G--------H--------I\n");
        printf("    Current Default Map    \n");
        printf("Road are in column and Street are in row\n");
        printf("***Navigation System***\n");
        printf("1.Travel\n");
        printf("2.Add path\n");
        printf("3.Delete path\n");
        printf("4.Exit program.\n");
        printf("Enter:");
        scanf ("%d",&Option);
        switch (Option)
        {
        case 1:
            printf("Source Block:");
            scanf(" %c",&a); 
            printf("Destination Block:");
            scanf(" %c",&b);
            travel(a,b);
            break;
        case 2:
            printf("Source Block:");
            scanf(" %c",&a);
            printf("Destination Block:");
            scanf(" %c",&b);
            printf("Path Name:");
            scanf("%s",path_name);
            New_path(a,b,path_name);
            break;
        case 3:
            printf("Source Block:");
            scanf(" %c",&a);
            printf("Destination Block:");
            scanf(" %c",&b);
            printf("Path Name:");
            scanf("%s",path_name);
            Delete_path(a,b,path_name);
            break;
        case 4:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice!!!\n");
            break;
            }}
        return 0;
}
void Generate_map()
{//This part generates Streets part of the map
    New_path('A','B',"Street 1");
    New_path('B','C',"Street 1");
    New_path('D','E',"Street 2");
    New_path('E','F',"Street 2");
    New_path('G','H',"Street 3");
    New_path('H','I',"Street 3");
//This part generates Roads part of the map
    New_path('A','D',"Road 1");
    New_path('D','G',"Road 1");
    New_path('B','E',"Road 2");
    New_path('E','H',"Road 2");
    New_path('C','F',"Road 3");
    New_path('F','I',"Road 3");
}
void New_path(char a,char b, char *path_name)
{
    int x = BTI(a);
    int y = BTI(b);
    strcpy (matrix[x][Enumber[x]].path_name,path_name);// This three line establish path x->y path
    matrix[x][Enumber[x]].to=y;
    Enumber[x]++;
    strcpy (matrix[y][Enumber[y]].path_name,path_name);// This three line establish path y->x path
    matrix[y][Enumber[y]].to=x;
    Enumber[y]++;

}
int BTI (char C)
{
    if(C>='A'&&C<='I')
    {
        return C-'A';
    }
    else
    {
        return -1;
    }
}
char ITB (int i)
{
    return (char)(i+'A');
}
void travel(char a, char b){
    int start = BTI(a);
    int end = BTI(b);
    if (start == -1 || end == -1) 
    { 
        printf("Invalid!\n");
        return;
    }
    //BFS is used
    int Q[M], f = 0, r = 0, P[B]; // Queue, front, rear, parent
    int V[B] = {0};               
    char Via[B][10];  
    Q[r++] = start;
    V[start] = 1;
    P[start] = -1;
    Via[start][0] = '\0';

    while (f < r) 
    {
        int x = Q[f++];
        if (x == end) 
        {
            break;
        } 
        for (int i = 0; i < Enumber[x]; i++) // loops until how many edges that Block has 
        {
            int y = matrix[x][i].to;// places destination block of x block's i number road or street to y.
            if (!V[y]) // checks if y block is visited or not
            {
                Q[r++] = y;
                V[y] = 1;
                P[y] = x;
                strcpy(Via[y], matrix[x][i].path_name); 
            }
        }
    }

    if (!V[end])//  Checks if end destination is ever visited 
    {
        printf("No path found from %c to %c.\n", a, b);
        return;
    }

    char path[B];// char type array for visited array.
    int i = 0;
    int curr = end;// put end block in curr
    while (curr != -1)// loops until curr is null.
    {
        path[i++] = ITB(curr);//changes parth block number to letter
        curr = P[curr];// changes curr to parent of current curr block.
    }

    printf("Path:\n");
    printf("At Block %c\n", path[i - 1]);
    for (curr = i - 1; curr > 0; curr--)// Revese the path and print start -> end
    {
        int from = BTI(path[curr]);// present block
        int to = BTI(path[curr - 1]);//
        printf("Go to Block %c via %s\n", path[curr - 1], Via[to]);
    }
    printf("Arrived at Block %c\n", path[0]);
}

void Delete_path(char a, char b,char *path_name ) 
{ 
    int x = BTI(a);
    int y = BTI(b); 
    if (x == -1 || y == -1) 
    { 
        printf("Invalid block name.\n"); 
        return; 
    } 
    int i; 
    int removed = 0; 
 
    for (i = 0; i < Enumber[x]; i++) 
    {
    if (matrix[x][i].to == y) {
    matrix[x][i] = matrix[x][Enumber[x] - 1];// This three line delete the path x->y path
    Enumber[x]--; 
    removed = 1; 
    break; 
    }}
    for (i = 0; i < Enumber[y]; i++) 
    { 
    if (matrix[y][i].to == x) { 
    matrix[y][i] = matrix[y][Enumber[y] - 1];// This three line delete the path x->y path
    Enumber[y]--; 
    break; } } 
    if (removed) 
    printf("Path %c <-> %c is removed .\n", a,b ); 
    else 
    printf("Path not found.\n"); 
}