#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll grid[10][10][10][10];
bool sub_grid[10][10];
ll one , two ;
vector<pair<ll,ll> > pr_bot={{1,1},{0,0},{0,2},{2,2},{2,0},{1,0},{0,1},{1,2},{2,1} };// higher priority first for bot player
vector<pair<ll,ll> > pr_input={{1,0},{0,1},{1,2},{2,1},{0,0},{0,2},{2,2},{2,0},{1,1} };// lower priority first for user input

void print_sub_grid(ll x , ll y , ll z)
{
    for(ll i=0 ; i<3 ; i++) cout<<grid[x][y][z][i]<<" ";
    cout<<"   ";
}
void Print_grid()
{
    // first row main grid
    print_sub_grid(0,0,0); print_sub_grid(0,1,0); print_sub_grid(0,2,0); cout<<endl;
    print_sub_grid(0,0,1); print_sub_grid(0,1,1); print_sub_grid(0,2,1); cout<<endl;
    print_sub_grid(0,0,2); print_sub_grid(0,1,2); print_sub_grid(0,2,2); cout<<endl;
    cout<<endl;
    // second row main grid
    print_sub_grid(1,0,0); print_sub_grid(1,1,0); print_sub_grid(1,2,0); cout<<endl;
    print_sub_grid(1,0,1); print_sub_grid(1,1,1); print_sub_grid(1,2,1); cout<<endl;
    print_sub_grid(1,0,2); print_sub_grid(1,1,2); print_sub_grid(1,2,2); cout<<endl;
    cout<<endl;

    // third row main grid
    print_sub_grid(2,0,0); print_sub_grid(2,1,0); print_sub_grid(2,2,0); cout<<endl;
    print_sub_grid(2,0,1); print_sub_grid(2,1,1); print_sub_grid(2,2,1); cout<<endl;
    print_sub_grid(2,0,2); print_sub_grid(2,1,2); print_sub_grid(2,2,2); cout<<endl;
    cout<<endl;
}


int principle_diagonally_game_possible(ll x , ll y , ll val)
{
    if(sub_grid[x][y]==true) return -1;
    if(grid[x][y][0][0]==grid[x][y][1][1] and grid[x][y][1][1]==val and grid[x][y][2][2]==0) return 2;
    if(grid[x][y][0][0]==grid[x][y][2][2] and grid[x][y][0][0]==val and grid[x][y][1][1]==0) return 1;
    if(grid[x][y][1][1]==grid[x][y][2][2] and grid[x][y][2][2]==val and grid[x][y][0][0]==0) return 0;
    return -1 ;
}

int secondary_diagonally_game_possible(ll x , ll y , ll val)
{
    if(sub_grid[x][y]==true) return -1;
    if(grid[x][y][0][2]==grid[x][y][1][1] and grid[x][y][0][2]==val and grid[x][y][2][0]==0) return 2;
    if(grid[x][y][0][2]==grid[x][y][2][0] and grid[x][y][0][2]==val and grid[x][y][1][1]==0) return 1;
    if(grid[x][y][1][1]==grid[x][y][2][0] and grid[x][y][2][0]==val and grid[x][y][0][2]==0) return 0;
    return -1 ;
}
int first_column_game_possible(ll x , ll y , ll val)
{
    if(sub_grid[x][y]==true) return -1;
    if(grid[x][y][0][0]==grid[x][y][1][0] and grid[x][y][0][0]==val and grid[x][y][2][0]==0) return 2;
    if(grid[x][y][0][0]==grid[x][y][2][0] and grid[x][y][2][0]==val and grid[x][y][1][0]==0) return 1;
    if(grid[x][y][1][0]==grid[x][y][2][0] and grid[x][y][2][0]==val and grid[x][y][0][0]==0) return 0;
    return -1 ;
}

int second_column_game_possible(ll x , ll y , ll val)
{
    if(sub_grid[x][y]==true) return -1;
    if(grid[x][y][0][1]==grid[x][y][1][1] and grid[x][y][0][1]==val and grid[x][y][2][1]==0) return 2;
    if(grid[x][y][0][1]==grid[x][y][2][1] and grid[x][y][0][1]==val and grid[x][y][1][1]==0) return 1;
    if(grid[x][y][1][1]==grid[x][y][2][1] and grid[x][y][2][1]==val and grid[x][y][0][1]==0) return 0;
    return -1 ;
}

int third_column_game_possible(ll x , ll y , ll val)
{
    if(sub_grid[x][y]==true) return -1;
    if(grid[x][y][0][2]==grid[x][y][1][2] and grid[x][y][0][2]==val and grid[x][y][2][2]==0) return 2;
    if(grid[x][y][0][2]==grid[x][y][2][2] and grid[x][y][0][2]==val and grid[x][y][1][2]==0) return 1;
    if(grid[x][y][1][2]==grid[x][y][2][2] and grid[x][y][2][2]==val and grid[x][y][0][2]==0) return 0;
    return -1 ;
}

int first_row_game_possible(ll x , ll y , ll val)
{
    if(sub_grid[x][y]==true) return -1;
    if(grid[x][y][0][0]==grid[x][y][0][1] and grid[x][y][0][1]==val and grid[x][y][0][2]==0) return 2;
    if(grid[x][y][0][0]==grid[x][y][0][2] and grid[x][y][0][2]==val and grid[x][y][0][1]==0) return 1;
    if(grid[x][y][0][1]==grid[x][y][0][2] and grid[x][y][0][2]==val and grid[x][y][0][0]==0) return 0;
    return -1 ;
}

int second_row_game_possible(ll x , ll y , ll val)
{
    if(sub_grid[x][y]==true) return -1;
    if(grid[x][y][1][0]==grid[x][y][1][1] and grid[x][y][1][1]==val and grid[x][y][1][2]==0) return 2;
    if(grid[x][y][1][0]==grid[x][y][1][2] and grid[x][y][1][2]==val and grid[x][y][1][1]==0) return 1;
    if(grid[x][y][1][1]==grid[x][y][1][2] and grid[x][y][1][2]==val and grid[x][y][1][0]==0) return 0;
    return -1 ;
}

int third_row_game_possible(ll x , ll y , ll val)
{
    if(sub_grid[x][y]==true) return -1;
    if(grid[x][y][2][0]==grid[x][y][2][1] and grid[x][y][2][1]==val and grid[x][y][2][2]==0) return 2;
    if(grid[x][y][2][0]==grid[x][y][2][2] and grid[x][y][2][2]==val and grid[x][y][2][1]==0) return 1;
    if(grid[x][y][2][1]==grid[x][y][2][2] and grid[x][y][2][2]==val and grid[x][y][2][0]==0) return 0;
    return -1 ;
}
bool grid_center_check(ll x , ll y)
{
    if(grid[x][y][1][1]==0) return false;
    return true;
}
bool Sub_Grid_Move_Possible(ll x , ll y)
{
    if(sub_grid[x][y]==true) return false;
    return true;
}


bool next_game_possible(ll x , ll y ,ll val)
{
    //true mane ami ekane move dibo na
    if(sub_grid[x][y]==true) return true;
    if(principle_diagonally_game_possible(x,y,val)!=-1) return true;
    if(secondary_diagonally_game_possible(x,y,val)!=-1) return true;
    if(first_row_game_possible(x,y,val)!=-1) return true;
    if(second_row_game_possible(x,y,val)!=-1) return true;
    if(third_row_game_possible(x,y,val)!=-1) return true;
    if(first_column_game_possible(x,y,val)!=-1) return true;
    if(second_column_game_possible(x,y,val)!=-1) return true;
    if(third_column_game_possible(x,y,val)!=-1) return true;
    return false;
}


bool sub_grid_game_possible(ll x , ll y ,ll val)
{

    if(sub_grid[x][y]==true) return false;

    //principle diagonally game possible
    if(grid[x][y][0][0]== grid[x][y][1][1] and grid[x][y][1][1] == grid[x][y][2][2] and grid[x][y][1][1]==val) return true;

    //secondary diagonally game possible
    if(grid[x][y][0][2]== grid[x][y][1][1] and grid[x][y][1][1] == grid[x][y][2][0] and grid[x][y][1][1]==val) return true;

    //first row game possible
    if(grid[x][y][0][0]== grid[x][y][0][1] and grid[x][y][0][1] == grid[x][y][0][2] and grid[x][y][0][1]==val) return true;

    //second row game possible
    if(grid[x][y][1][0]== grid[x][y][1][1] and grid[x][y][1][1] == grid[x][y][1][2] and grid[x][y][1][1]==val) return true;

    //third row game possible
    if(grid[x][y][2][0]== grid[x][y][2][1] and grid[x][y][2][1] == grid[x][y][2][2] and grid[x][y][2][1]==val) return true;

    //first column game possible
    if(grid[x][y][0][0]== grid[x][y][1][0] and grid[x][y][1][0] == grid[x][y][2][0] and grid[x][y][1][0]==val) return true;

    //second column game possible
    if(grid[x][y][0][1]== grid[x][y][1][1] and grid[x][y][1][1] == grid[x][y][2][1] and grid[x][y][1][1]==val) return true;

    //third column game possible
    if(grid[x][y][0][2]== grid[x][y][1][2] and grid[x][y][1][2] == grid[x][y][2][2] and grid[x][y][1][2]==val) return true;

    return false;
}


int main()
{
    Print_grid();
    //2 input player , 1 bot payer

    ll x, y , a , b ;

    //grid[2][2][0][2]=1; grid[2][2][1][2]=1;
    //grid[1][0][0][2]=2; grid[1][0][1][2]=2;
    User_move:
    while(true)
    {

        cout<<" Take input for User : ";
        cin>>x>>y>>a>>b;
        if(sub_grid[x][y]==true)
        {
            cout<<"Invalid Move : Take input again "<<endl;
        }
        else if(grid[x][y][a][b]!=0)
        {
            cout<<"Invalid Move : Take input again "<<endl;
        }
        else break ;
    }
    grid[x][y][a][b]=2;
    if(sub_grid_game_possible(x,y,2)==true)
    {
        sub_grid[x][y]=true ;
    }
    Print_grid();


    while(true)
    {

            //a b == equivalent  sub grid
            ll pos , pos1 , pos2;
            // ami dektesi amar ki kono game possible

            pos = principle_diagonally_game_possible(a,b,1);
            if(pos!=-1)
            {
                pos1 = pos ;
                pos2 = pos ;
                grid[a][b][pos1][pos2]=1;
                sub_grid[a][b]=true;
                printf("Bot Player Move : Main Grid:%lld %lld     Sub_Grid:%lld %lld\n",a,b,pos1,pos2);
                Print_grid();
                if(sub_grid[pos1][pos2]==true)  goto User_move;
                goto next_move;
            }

            pos = secondary_diagonally_game_possible(a,b,1);
            if(pos!=-1)
            {
                pos1 = pos ;
                pos2 = 2 - pos ;
                grid[a][b][pos1][pos2]=1;
                sub_grid[a][b]=true;
                printf("Bot Player Move : Main Grid:%lld %lld     Sub_Grid:%lld %lld\n",a,b,pos1,pos2);
                Print_grid();
                if(sub_grid[pos1][pos2]==true)  goto User_move;
                goto next_move;
            }

            pos = first_row_game_possible(a,b,1);
            if(pos!=-1)
            {
                pos1 = 0 ;
                pos2 = pos ;
                grid[a][b][pos1][pos2]=1;
                sub_grid[a][b]=true;
                printf("Bot Player Move : Main Grid:%lld %lld     Sub_Grid:%lld %lld\n",a,b,pos1,pos2);
                Print_grid();
                if(sub_grid[pos1][pos2]==true)  goto User_move;
                goto next_move;
            }
            pos = second_row_game_possible(a,b,1);
            if(pos!=-1)
            {
                pos1 = 1 ;
                pos2 = pos ;
                grid[a][b][pos1][pos2]=1;
                sub_grid[a][b]=true;
                printf("Bot Player Move : Main Grid:%lld %lld     Sub_Grid:%lld %lld\n",a,b,pos1,pos2);
                Print_grid();
                if(sub_grid[pos1][pos2]==true)  goto User_move;
                goto next_move;
            }
            pos = third_row_game_possible(a,b,1);
            if(pos!=-1)
            {
                pos1 = 2 ;
                pos2 = pos ;
                grid[a][b][pos1][pos2]=1;
                sub_grid[a][b]=true;
                printf("Bot Player Move : Main Grid:%lld %lld     Sub_Grid:%lld %lld\n",a,b,pos1,pos2);
                Print_grid();
                if(sub_grid[pos1][pos2]==true)  goto User_move;
                goto next_move;
            }


            pos = first_column_game_possible(a,b,1);
            if(pos!=-1)
            {
                pos1 = pos ;
                pos2 = 0 ;
                grid[a][b][pos1][pos2]=1;
                sub_grid[a][b]=true;
                printf("Bot Player Move : Main Grid:%lld %lld     Sub_Grid:%lld %lld\n",a,b,pos1,pos2);
                Print_grid();
                if(sub_grid[pos1][pos2]==true)  goto User_move;
                goto next_move;
            }
            pos = second_column_game_possible(a,b,1);
            if(pos!=-1)
            {
                pos1 = pos ;
                pos2 = 1 ;
                grid[a][b][pos1][pos2]=1;
                sub_grid[a][b]=true;
                printf("Bot Player Move : Main Grid:%lld %lld     Sub_Grid:%lld %lld\n",a,b,pos1,pos2);
                Print_grid();
                if(sub_grid[pos1][pos2]==true)  goto User_move;
                goto next_move;
            }
            pos = third_column_game_possible(a,b,1);
            if(pos!=-1)
            {
                pos1 = pos ;
                pos2 = 2 ;
                grid[a][b][pos1][pos2]=1;
                sub_grid[a][b]=true;
                printf("Bot Player Move : Main Grid:%lld %lld     Sub_Grid:%lld %lld\n",a,b,pos1,pos2);
                Print_grid();
                if(sub_grid[pos1][pos2]==true)  goto User_move;
                goto next_move;
            }

//------------------------------------------------------------------------------------------------------

             // ami dektesi tar ki kono game possible
            pos = principle_diagonally_game_possible(a,b,2);
            if(pos!=-1)
            {
                pos1 = pos ;
                pos2 = pos ;
                grid[a][b][pos1][pos2]=1;
                printf("Bot Player Move : Main Grid:%lld %lld     Sub_Grid:%lld %lld\n",a,b,pos1,pos2);
                Print_grid();
                goto next_move;
            }

            pos = secondary_diagonally_game_possible(a,b,2);
            if(pos!=-1)
            {
                pos1 = pos ;
                pos2 = 2 - pos ;
                grid[a][b][pos1][pos2]=1;
                printf("Bot Player Move : Main Grid:%lld %lld     Sub_Grid:%lld %lld\n",a,b,pos1,pos2);
                Print_grid();
                goto next_move;
            }

            pos = first_row_game_possible(a,b,2);
            if(pos!=-1)
            {
                pos1 = 0 ;
                pos2 = pos ;
                grid[a][b][pos1][pos2]=1;
                printf("Bot Player Move : Main Grid:%lld %lld     Sub_Grid:%lld %lld\n",a,b,pos1,pos2);
                Print_grid();
                goto next_move;
            }
            pos = second_row_game_possible(a,b,2);
            if(pos!=-1)
            {
                pos1 = 1 ;
                pos2 = pos ;
                grid[a][b][pos1][pos2]=1;
                printf("Bot Player Move : Main Grid:%lld %lld     Sub_Grid:%lld %lld\n",a,b,pos1,pos2);
                Print_grid();
                goto next_move;
            }
            pos = third_row_game_possible(a,b,2);
            if(pos!=-1)
            {
                pos1 = 2 ;
                pos2 = pos ;
                grid[a][b][pos1][pos2]=1;
                printf("Bot Player Move : Main Grid:%lld %lld     Sub_Grid:%lld %lld\n",a,b,pos1,pos2);
                Print_grid();
                goto next_move;
            }


            pos = first_column_game_possible(a,b,2);
            if(pos!=-1)
            {
                pos1 = pos ;
                pos2 = 0 ;
                grid[a][b][pos1][pos2]=1;
                printf("Bot Player Move : Main Grid:%lld %lld     Sub_Grid:%lld %lld\n",a,b,pos1,pos2);
                Print_grid();
                goto next_move;
            }
            pos = second_column_game_possible(a,b,2);
            if(pos!=-1)
            {
                pos1 = pos ;
                pos2 = 1 ;
                grid[a][b][pos1][pos2]=1;
                printf("Bot Player Move : Main Grid:%lld %lld     Sub_Grid:%lld %lld\n",a,b,pos1,pos2);
                Print_grid();
                goto next_move;
            }
            pos = third_column_game_possible(a,b,2);
            if(pos!=-1)
            {
                pos1 = pos ;
                pos2 = 2 ;
                grid[a][b][pos1][pos2]=1;
                printf("Bot Player Move : Main Grid:%lld %lld     Sub_Grid:%lld %lld\n",a,b,pos1,pos2);
                Print_grid();
                goto next_move;
            }
//------------------------------------------------------------------------------------------------------

    // jehetu tar ba amar game dewa possible hoy nai tai ekon ami thake emon weak ghor dibo jekane tar game
    // dewa possible na


            for(auto &[p,q]:pr_input)
            {
                if(sub_grid[a][b]==false and grid[a][b][p][q]==0 and next_game_possible(p,q,2)==false)
                {
                    pos1 = p ;
                    pos2 = q ;

                    grid[a][b][pos1][pos2]=1;
                    printf("Bot Player Move : Main Grid:%lld %lld     Sub_Grid:%lld %lld\n",a,b,pos1,pos2);
                    Print_grid();
                    goto next_move;

                }
            }
            x=a,y=b;
            goto wish;
//----------------------------------------------------------------------------------------------------------------------

    // Bot player er move dewa shesh ekon user input nibe

            next_move:

            if(sub_grid[pos1][pos2]==true) goto User_move ;
            while(true)
            {
                printf("User Player Move : Default  Main Grid : %lld %lld  \n",pos1,pos2);
                cout<<"              Take input for sub grid : ";
                cin>>x>>y;
                if(grid[pos1][pos2][x][y]==true)
                {
                    cout<<"Invalid Move : Take input again "<<endl;
                }
                else break ;
            }
            grid[pos1][pos2][x][y]=2;
            if(sub_grid_game_possible(pos1,pos2,2)==true)
            {
                sub_grid[pos1][pos2]=true ;
            }
            a = x ;
            b = y ;
            Print_grid();
            wish:
//--------------------------------------------------------------------------------------------------------------
            if(sub_grid[x][y]==true)
            {
                cout<<"Bot player should choose subgrid\n";
                for(auto &[p,q]: pr_bot)
                {
                    if(next_game_possible(p,q,1)==true and sub_grid[p][q]==false)// bot player can give e game
                    {
                        a = p ;
                        b = q ;

                        pos = principle_diagonally_game_possible(a,b,1);
                        if(pos!=-1)
                        {
                            pos1 = pos ;
                            pos2 = pos ;
                            grid[a][b][pos1][pos2]=1;
                            sub_grid[a][b]=true;
                            printf("Bot Player Move : Main Grid:%lld %lld     Sub_Grid:%lld %lld\n",a,b,pos1,pos2);
                            Print_grid();
                            if(sub_grid[pos1][pos2]==true)  goto User_move;
                            a=pos1;b=pos2;
                            goto next_move;
                        }

                        pos = secondary_diagonally_game_possible(a,b,1);
                        if(pos!=-1)
                        {
                            pos1 = pos ;
                            pos2 = 2 - pos ;
                            grid[a][b][pos1][pos2]=1;
                            sub_grid[a][b]=true;
                            printf("Bot Player Move : Main Grid:%lld %lld     Sub_Grid:%lld %lld\n",a,b,pos1,pos2);
                            Print_grid();
                            if(sub_grid[pos1][pos2]==true)  goto User_move;
                            a=pos1;b=pos2;
                            goto next_move;
                        }

                        pos = first_row_game_possible(a,b,1);
                        if(pos!=-1)
                        {
                            pos1 = 0 ;
                            pos2 = pos ;
                            grid[a][b][pos1][pos2]=1;
                            sub_grid[a][b]=true;
                            printf("Bot Player Move : Main Grid:%lld %lld     Sub_Grid:%lld %lld\n",a,b,pos1,pos2);
                            Print_grid();
                            if(sub_grid[pos1][pos2]==true)  goto User_move;
                            a=pos1;b=pos2;
                            goto next_move;
                        }
                        pos = second_row_game_possible(a,b,1);
                        if(pos!=-1)
                        {
                            pos1 = 1 ;
                            pos2 = pos ;
                            grid[a][b][pos1][pos2]=1;
                            sub_grid[a][b]=true;
                            printf("Bot Player Move : Main Grid:%lld %lld     Sub_Grid:%lld %lld\n",a,b,pos1,pos2);
                            Print_grid();
                            if(sub_grid[pos1][pos2]==true)  goto User_move;
                            a=pos1;b=pos2;
                            goto next_move;
                        }
                        pos = third_row_game_possible(a,b,1);
                        if(pos!=-1)
                        {
                            pos1 = 2 ;
                            pos2 = pos ;
                            grid[a][b][pos1][pos2]=1;
                            sub_grid[a][b]=true;
                            printf("Bot Player Move : Main Grid:%lld %lld     Sub_Grid:%lld %lld\n",a,b,pos1,pos2);
                            Print_grid();
                            if(sub_grid[pos1][pos2]==true)  goto User_move;
                            a=pos1;b=pos2;
                            goto next_move;
                        }


                        pos = first_column_game_possible(a,b,1);
                        if(pos!=-1)
                        {
                            pos1 = pos ;
                            pos2 = 0 ;
                            grid[a][b][pos1][pos2]=1;
                            sub_grid[a][b]=true;
                            printf("Bot Player Move : Main Grid:%lld %lld     Sub_Grid:%lld %lld\n",a,b,pos1,pos2);
                            Print_grid();
                            if(sub_grid[pos1][pos2]==true)  goto User_move;
                            a=pos1;b=pos2;
                            goto next_move;
                        }
                        pos = second_column_game_possible(a,b,1);
                        if(pos!=-1)
                        {
                            pos1 = pos ;
                            pos2 = 1 ;
                            grid[a][b][pos1][pos2]=1;
                            sub_grid[a][b]=true;
                            printf("Bot Player Move : Main Grid:%lld %lld     Sub_Grid:%lld %lld\n",a,b,pos1,pos2);
                            Print_grid();
                            if(sub_grid[pos1][pos2]==true)  goto User_move;
                            a=pos1;b=pos2;
                            goto next_move;
                        }
                        pos = third_column_game_possible(a,b,1);
                        if(pos!=-1)
                        {
                            pos1 = pos ;
                            pos2 = 2 ;
                            grid[a][b][pos1][pos2]=1;
                            sub_grid[a][b]=true;
                            printf("Bot Player Move : Main Grid:%lld %lld     Sub_Grid:%lld %lld\n",a,b,pos1,pos2);
                            Print_grid();
                            if(sub_grid[pos1][pos2]==true)  goto User_move;
                            a=pos1;b=pos2;
                            goto next_move;
                        }
                    }
                }

//------------------------------------------------------------------------------------------------------
             // ekon amra dekbo kono smain grid e user ki kono game dite parbe
             for( auto &[p,q]:pr_input)
             {
                 if(sub_grid[p][q]==false and next_game_possible(p,q,2)==true)
                 {

                       a=p,b=q;
                       pos = principle_diagonally_game_possible(a,b,2);
                        if(pos!=-1)
                        {
                            pos1 = pos ;
                            pos2 = pos ;
                            grid[a][b][pos1][pos2]=1;
                            printf("Bot Player Move : Main Grid:%lld %lld     Sub_Grid:%lld %lld\n",a,b,pos1,pos2);
                            Print_grid();
                            goto next_move;
                        }

                        pos = secondary_diagonally_game_possible(a,b,2);
                        if(pos!=-1)
                        {
                            pos1 = pos ;
                            pos2 = 2 - pos ;
                            grid[a][b][pos1][pos2]=1;
                            printf("Bot Player Move : Main Grid:%lld %lld     Sub_Grid:%lld %lld\n",a,b,pos1,pos2);
                            Print_grid();
                            goto next_move;
                        }

                        pos = first_row_game_possible(a,b,2);
                        if(pos!=-1)
                        {
                            pos1 = 0 ;
                            pos2 = pos ;
                            grid[a][b][pos1][pos2]=1;
                            printf("Bot Player Move : Main Grid:%lld %lld     Sub_Grid:%lld %lld\n",a,b,pos1,pos2);
                            Print_grid();
                            goto next_move;
                        }
                        pos = second_row_game_possible(a,b,2);
                        if(pos!=-1)
                        {
                            pos1 = 1 ;
                            pos2 = pos ;
                            grid[a][b][pos1][pos2]=1;
                            printf("Bot Player Move : Main Grid:%lld %lld     Sub_Grid:%lld %lld\n",a,b,pos1,pos2);
                            Print_grid();
                            goto next_move;
                        }
                        pos = third_row_game_possible(a,b,2);
                        if(pos!=-1)
                        {
                            pos1 = 2 ;
                            pos2 = pos ;
                            grid[a][b][pos1][pos2]=1;
                            printf("Bot Player Move : Main Grid:%lld %lld     Sub_Grid:%lld %lld\n",a,b,pos1,pos2);
                            Print_grid();
                            goto next_move;
                        }


                        pos = first_column_game_possible(a,b,2);
                        if(pos!=-1)
                        {
                            pos1 = pos ;
                            pos2 = 0 ;
                            grid[a][b][pos1][pos2]=1;
                            printf("Bot Player Move : Main Grid:%lld %lld     Sub_Grid:%lld %lld\n",a,b,pos1,pos2);
                            Print_grid();
                            goto next_move;
                        }
                        pos = second_column_game_possible(a,b,2);
                        if(pos!=-1)
                        {
                            pos1 = pos ;
                            pos2 = 1 ;
                            grid[a][b][pos1][pos2]=1;
                            printf("Bot Player Move : Main Grid:%lld %lld     Sub_Grid:%lld %lld\n",a,b,pos1,pos2);
                            Print_grid();
                            goto next_move;
                        }
                        pos = third_column_game_possible(a,b,2);
                        if(pos!=-1)
                        {
                            pos1 = pos ;
                            pos2 = 2 ;
                            grid[a][b][pos1][pos2]=1;
                            printf("Bot Player Move : Main Grid:%lld %lld     Sub_Grid:%lld %lld\n",a,b,pos1,pos2);
                            Print_grid();
                            goto next_move;
                        }


                 }
             }

//---------------------------------------------------------------------------------------------------









                for(auto &[p,q]:pr_input)//user can't give a game
                {
                    if(sub_grid[p][q]==false and next_game_possible(p,q,2)==false)
                    {
                        a = p ;
                        b = q ;
                        for(auto &[r,s]:pr_bot)
                        {
                            if(grid[a][b][r][s]==0)
                            {
                                pos1 = r ;
                                pos2 = s ;
                                grid[a][b][pos1][pos2]=1;
                                printf("Bot Player Move : Main Grid:%lld %lld     Sub_Grid:%lld %lld\n",a,b,pos1,pos2);
                                Print_grid();
                                a=pos1;b=pos2;
                                goto next_move;
                            }
                        }

                    }
                }

//--------------------------------------------------------------------------------------------------------------------
           cout<<"Game is over"<<endl;
           return 0;

         }

    }


    return 0;
}




