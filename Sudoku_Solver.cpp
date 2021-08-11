#include<bits/stdc++.h>
using namespace std;
 int sudoku[9][9]={
   {3, 0, 6, 5, 0, 8, 4, 0, 0},
   {5, 2, 0, 0, 0, 0, 0, 0, 0},
   {0, 8, 7, 0, 0, 0, 0, 3, 1},
   {0, 0, 3, 0, 1, 0, 0, 8, 0},
   {9, 0, 0, 8, 6, 3, 0, 0, 5},
   {0, 5, 0, 0, 9, 0, 6, 0, 0},
   {1, 3, 0, 0, 0, 0, 2, 5, 0},
   {0, 0, 0, 0, 0, 0, 0, 7, 4},
   {0, 0, 5, 2, 0, 6, 3, 0, 0}
};

bool PresentinColumn(int col,int num)
{
   for(int i=0;i<9;i++)if(sudoku[i][col]==num)return true;
   return false;
}
bool PresentinRow(int row,int num)
{
   for(int i=0;i<9;i++)if(sudoku[row][i]==num)return true;
   return false;
}
bool inGrid(int row, int col,int num)
{
  for(int i=0;i<3;i++)
  {
      for(int j=0;j<3;j++){if(sudoku[i+row][j+col]==num) return true;}


  }
  return false;
}
void sudokuGrid(){ 
   for (int row = 0; row < 9; row++){
      for (int col = 0; col < 9; col++){
         if(col == 3 || col == 6)
            cout << " | ";
         cout << sudoku[row][col] <<" ";
      }
      if(row == 2 || row == 5){
         cout << endl;
         for(int i = 0; i<9; i++)
            cout << "---";
      }
      cout << endl;
   }
}
bool isVoid(int &row,int &col)
{
  for(row=0;row<9;row++){
      for( col=0;col<9;col++){
          if(sudoku[row][col]==0)return true;
      }
  }
  return false;
}
bool isValid(int row, int col,int num)
{
return !PresentinRow(row,num)&&!PresentinColumn(col,num)&&!inGrid(row - row%3 ,
col - col%3, num);

}
bool solveIt()
{
  int row, col;
   if (!isVoid(row, col))
      return true; //when all places are filled
   for (int num = 1; num <= 9; num++){ //valid numbers are 1 - 9
      if (isValid(row, col, num)){ //check validation, if yes, put the number in the grid
         sudoku[row][col] = num;
         
         //BACKTRACKING STEP 
         if (solveIt()) //recursively go for other rooms in the grid
            return true;
         sudoku[row][col] = 0; //turn to unassigned space beyond sudoku grid when conditions are not satisfied
      }
   }
   return false;

}


int main()
{
if(solveIt()==true){cout<<"Valid Grid!! Here's the Solution :-\n\n";sudokuGrid();}
else cout<<"DAMN!!! No Solution Exists Buckaroo";

}