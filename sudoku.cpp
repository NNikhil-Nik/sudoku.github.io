#include&lt;iostream&gt;
#include&lt;windows.h&gt;
#include&lt;bits/stdc++.h&gt;
using namespace std;
void Print_Board(int board[9][9])
{
cout &lt;&lt; &quot;------+-------+---------&quot; &lt;&lt; endl;
for(int i = 0; i &lt;9; i++)
{
for(int j = 0; j &lt; 9; j++)
{
cout &lt;&lt; board[i][j] &lt;&lt; &quot; &quot;;
if(j == 2||j==5||j==8) cout &lt;&lt; &quot;| &quot;;
}

cout &lt;&lt; endl;
if(i== 2||i==5||i==8) cout &lt;&lt; &quot;------+-------+---------&quot; &lt;&lt; endl;}

}

void check(int board[9][9],int board1[9][9])
{
int f=0;
for (int i=0;i&lt;9;i++)
{

for(int j=0;j&lt;9;j++)
{
if(board[i][j]!=board1[i][j])
{
f=1;
}
}
}
if(f==0)
cout&lt;&lt;&quot;Solution is correct \n&quot;;
else
cout&lt;&lt;&quot;Solution is not correct&quot;;

}
void printSudoku9x9(int arr[9][9]) {
cout &lt;&lt; &quot;-------------------------&quot; &lt;&lt; endl;
for (int y = 0; y &lt; 9; y++) {
for (int x = 0; x &lt; 9; x++)
cout &lt;&lt; arr[y][x] &lt;&lt; &quot; &quot;;
cout &lt;&lt; endl;
}
cout &lt;&lt; &quot;-------------------------&quot; &lt;&lt; endl;

}

bool canPlace9x9(int arr[9][9], int row, int col, int n)
{
if (arr[row][col] != 0) return false;

bool status = true;
int gridx = (col / 3) * 3;
int gridy = (row / 3) * 3;
for (int i = 0; i &lt; 9; i++) {
if (arr[row][i] == n) { status = false; break; }
if (arr[i][col] == n) { status = false; break; }
if (arr[gridy + i / 3][gridx + i % 3] == n) { status = false; break; }
}
return status;
}

void nextEmpty(int arr[9][9], int row, int col, int&amp; rowNext, int&amp; colNext)
{

int indexNext = 9 * 9 + 1;
for (int i = row * 9 + col + 1; i &lt; 9 * 9; i++) {
if (arr[i / 9][i % 9] == 0) {

indexNext = i;
break;
}
}
rowNext = indexNext / 9;
colNext = indexNext % 9;
//cout &lt;&lt; row &lt;&lt; &quot;,&quot; &lt;&lt; col &lt;&lt; &quot;|&quot; &lt;&lt; rowNext &lt;&lt; &quot;,&quot; &lt;&lt; colNext &lt;&lt; endl;
}

void copyArray(int arr[9][9], int arrCpy[9][9]) {
for (int y = 0; y &lt; 9; y++)

for (int x = 0; x &lt; 9; x++)
arrCpy[y][x] = arr[y][x];

}
std::vector&lt;int&gt; findPlaceables(int arr[9][9], int row, int col) {
vector&lt;int&gt; placebles = {};
for (int n = 1; n &lt;= 9; n++)
if (canPlace9x9(arr, row, col, n)) placebles.push_back(n);
return placebles;
}

bool solveSudoku9x9(int arr[9][9], int row, int col)
{
system(&quot;cls&quot;);
cout&lt;&lt;&quot;Solving sudoku&quot;&lt;&lt;endl;
cout&lt;&lt;endl;
cout&lt;&lt;endl;
cout&lt;&lt;endl;
cout&lt;&lt;endl;
cout&lt;&lt;endl;
printSudoku9x9(arr);

if (row &gt; 8) return true;
if (arr[row][col] != 0) {
int rowNext, colNext;
nextEmpty(arr, row, col, rowNext, colNext);
return solveSudoku9x9(arr, rowNext, colNext);
}

std::vector&lt;int&gt; placebles = findPlaceables(arr, row, col);

if (placebles.size() == 0) {

return false;

};

bool status = false;
for (int i = 0; i &lt; placebles.size(); i++) {
int n = placebles[i];
int arrCpy[9][9];
copyArray(arr, arrCpy);
//cout &lt;&lt; &quot;(&quot; &lt;&lt; row &lt;&lt; &quot;,&quot; &lt;&lt; col &lt;&lt; &quot;) =&gt;&quot; &lt;&lt; n &lt;&lt; endl;
arrCpy[row][col] = n;
int rowNext = row;
int colNext = col;
nextEmpty(arrCpy, row, col, rowNext, colNext);
if (solveSudoku9x9(arrCpy, rowNext, colNext)) {
copyArray(arrCpy, arr);
status = true;
break;
}
}
return status;
}

int Solver()

{
int a;
int board[9][9];
/*{
{ 3, 1, 6, 5, 7, 8, 4, 9, 2 },
{ 5, 2, 9, 1, 3, 4, 7, 6, 8 },
{ 4, 8, 7, 6, 2, 9, 5, 3, 1 },
{ 2, 6, 3, 0, 1, 5, 9, 8, 7 },
{ 9, 7, 4, 8, 6, 0, 1, 2, 5 },
{ 8, 5, 1, 7, 9, 2, 6, 4, 3 },
{ 1, 3, 8, 0, 4, 7, 2, 0, 6 },
{ 6, 9, 2, 3, 5, 1, 8, 7, 4 },
{ 7, 4, 5, 0, 8, 6, 3, 1, 0 } };
*/

for(int i=0;i&lt;9;i++)
{
cout&lt;&lt;&quot;Enter the values u want to enter in row &quot;&lt;&lt;i+1&lt;&lt;&quot; of the Sudoku &quot;&lt;&lt;endl;
for(int j=0;j&lt;9;j++)
{

cin&gt;&gt;a;
board[i][j]=a;
}
}

if (solveSudoku9x9(board, 0, 0)) cout &lt;&lt; &quot;successfully solved board!&quot; &lt;&lt; std::endl;
Print_Board(board);
return 0;

}

void setcolor(unsigned short color)
{
HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hcon,color);
}

void sudukochecker(int board[9][9],int board1[9][9],vector&lt;vector&lt;int&gt; &gt;&amp; colour)
{
cout &lt;&lt; &quot;------+-------+---------&quot; &lt;&lt; endl;
for(int i = 0; i &lt;9; i++)
{
for(int j = 0; j &lt; 9; j++)
{
if(colour[i][j]==1)
{
if(board[i][j]==board1[i][j])
{
setcolor(10);

}
else
setcolor(4);

}
else
setcolor(7);
cout &lt;&lt; board[i][j] &lt;&lt; &quot; &quot;;

if(j == 2||j==5||j==8) cout &lt;&lt; &quot;| &quot;;
}
cout &lt;&lt; endl;
if(i== 2||i==5||i==8) cout &lt;&lt; &quot;------+-------+---------&quot; &lt;&lt; endl;

}
check(board,board1);

}
void Diff1()
{
int a,b,count1;
int el;
vector&lt;vector&lt;int&gt; &gt; col(9,vector&lt;int&gt;(9, 0));
int mat2[9][9]= { { 3, 1, 6, 5, 7, 8, 4, 9, 2 },
{ 5, 2, 9, 1, 3, 4, 7, 6, 8 },
{ 4, 8, 7, 6, 2, 9, 5, 3, 1 },
{ 2, 6, 3, 4, 1, 5, 9, 8, 7 },
{ 9, 7, 4, 8, 6, 3, 1, 2, 5 },
{ 8, 5, 1, 7, 9, 2, 6, 4, 3 },
{ 1, 3, 8, 9, 4, 7, 2, 5, 6 },
{ 6, 9, 2, 3, 5, 1, 8, 7, 4 },
{ 7, 4, 5, 2, 8, 6, 3, 1, 9 } };

int mat1[9][9]={
{ 3, 1, 6, 5, 7, 8, 4, 9, 2 },
{ 5, 2, 9, 1, 3, 4, 7, 6, 8 },

{ 4, 8, 7, 6, 2, 9, 5, 3, 1 },
{ 2, 6, 3, 0, 1, 5, 9, 8, 7 },
{ 9, 7, 4, 8, 6, 0, 1, 2, 5 },
{ 8, 5, 1, 7, 9, 2, 6, 4, 3 },
{ 1, 3, 8, 0, 4, 7, 2, 0, 6 },
{ 6, 9, 2, 3, 5, 1, 8, 7, 4 },
{ 7, 4, 5, 0, 8, 6, 3, 1, 0 } };

Print_Board(mat1);
for(int k=1;k&lt;=81;k++)
{
cout&lt;&lt;&quot;Enter Index of element to enter:&quot;;
cout&lt;&lt;endl&lt;&lt;&quot;i:&quot;;
cin&gt;&gt;a;
cout&lt;&lt;&quot;j:&quot;;
cin&gt;&gt;b;
if(a&gt;9 &amp;&amp; b&gt;9)
{
cout&lt;&lt;&quot;Matrix filled:&quot;;
sudukochecker(mat1,mat2,col);
exit(0);

}
else if(mat1[a-1][b-1]!=0)
{
cout&lt;&lt;&quot;Element already exist:&quot;&lt;&lt;endl;
}

else

{
col[a-1][b-1]=1;
cout&lt;&lt;&quot;Enter Number:&quot;;
cin&gt;&gt;el;
mat1[a-1][b-1]=el;
}
}
}
void Diff2(){
int a,b,count1;
int el;
vector&lt;vector&lt;int&gt; &gt; col(9,vector&lt;int&gt;(9, 0));
int mat2[9][9]= {
{5,6,2,8,7,9,4,1,3},
{9,7,4,3,5,1,6,8,2},
{8,1,3,6,2,4,5,9,7},
{6,2,1,5,4,7,9,3,8},
{7,5,9,1,8,3,2,6,4},
{4,3,8,9,6,2,1,7,5},
{2,9,6,7,3,5,8,4,1},
{3,8,5,4,1,6,7,2,9},
{1,4,7,2,9,8,3,5,6}};

int mat1[9][9]={
{0,0,2,8,0,0,0,1,0},
{0,7,4,3,0,1,0,8,0},
{0,0,0,0,2,4,0,0,0},
{6,0,0,5,0,0,9,0,0},

{0,0,0,0,8,0,0,0,0},
{0,0,8,0,0,2,0,0,5},
{0,0,0,7,3,0,0,0,0},
{0,8,0,4,0,6,7,2,0},
{0,4,0,0,0,8,3,0,0}};

Print_Board(mat1);
for(int k=1;k&lt;=81;k++)
{
cout&lt;&lt;&quot;Enter Index of element to enter:&quot;;
cout&lt;&lt;endl&lt;&lt;&quot;i:&quot;;
cin&gt;&gt;a;
cout&lt;&lt;&quot;j:&quot;;
cin&gt;&gt;b;
if(a&gt;9 &amp;&amp; b&gt;9)
{
cout&lt;&lt;&quot;Matrix filled:&quot;;
sudukochecker(mat1,mat2,col);
exit(0);

}
else if(mat1[a-1][b-1]!=0)
{
cout&lt;&lt;&quot;Element already exist:&quot;&lt;&lt;endl;
}

else
{
cout&lt;&lt;&quot;Enter Number:&quot;;

cin&gt;&gt;el;
mat1[a-1][b-1]=el;
}

}
}
void Diff3(){
int a,b,count1;
int el;
vector&lt;vector&lt;int&gt; &gt; col(9,vector&lt;int&gt;(9, 0));
int mat2[9][9]= {
{5,6,2,8,7,9,4,1,3},
{9,7,4,3,5,1,6,8,2},
{8,1,3,6,2,4,5,9,7},
{6,2,1,5,4,7,9,3,8},
{7,5,9,1,8,3,2,6,4},
{4,3,8,9,6,2,1,7,5},
{2,9,6,7,3,5,8,4,1},
{3,8,5,4,1,6,7,2,9},
{1,4,7,2,9,8,3,5,6}};

int mat1[9][9]={
{9,0,0,0,2,5,0,0,8},
{0,0,1,8,0,0,0,0,5},
{0,0,0,3,0,0,0,2,0},
{5,0,0,0,1,0,0,9,3},
{0,3,0,0,0,0,0,8,0},
{8,9,0,0,3,0,0,0,4},

{0,7,0,0,0,9,0,0,0},
{4,0,0,0,0,3,7,0,0},
{2,0,0,6,4,0,0,0,1}};

Print_Board(mat1);
for(int k=1;k&lt;=81;k++)
{
cout&lt;&lt;&quot;Enter Index of element to enter:&quot;;
cout&lt;&lt;endl&lt;&lt;&quot;i:&quot;;
cin&gt;&gt;a;
cout&lt;&lt;&quot;j:&quot;;
cin&gt;&gt;b;
if(a&gt;9 &amp;&amp; b&gt;9)
{
cout&lt;&lt;&quot;Matrix filled:&quot;;
sudukochecker(mat1,mat2,col);
exit(0);

}
else if(mat1[a-1][b-1]!=0)
{
cout&lt;&lt;&quot;Element already exist:&quot;&lt;&lt;endl;
}

else
{
cout&lt;&lt;&quot;Enter Number:&quot;;

cin&gt;&gt;el;
mat1[a-1][b-1]=el;
}
}
}
void Diff4(){
int a,b,count1;
int el;
vector&lt;vector&lt;int&gt; &gt; col(9,vector&lt;int&gt;(9, 0));
int mat2[9][9]= {
{9,6,2,3,7,8,1,5,4},
{3,7,4,5,6,1,2,8,9},
{1,8,5,4,2,9,6,3,7},
{8,2,7,6,1,3,4,9,5},
{6,4,9,2,5,7,3,1,8},
{5,3,1,9,8,4,7,2,6},
{4,9,6,8,3,2,5,7,1},
{2,1,8,7,4,5,9,6,3},
{7,5,3,1,9,6,8,4,2}};

int mat1[9][9]={
{0,0,2,8,0,0,0,1,0},
{0,7,4,3,0,1,0,8,0},
{0,0,0,0,2,4,0,0,0},
{6,0,0,5,0,0,9,0,0},
{0,0,0,0,8,0,0,0,0},
{0,0,8,0,0,2,0,0,5},
{0,0,0,7,3,0,0,0,0},
{0,8,0,4,0,6,7,2,0},

{0,4,0,0,0,8,3,0,0}};

Print_Board(mat1);
for(int k=1;k&lt;=81;k++)
{
cout&lt;&lt;&quot;Enter Index of element to enter:&quot;;
cout&lt;&lt;endl&lt;&lt;&quot;i:&quot;;
cin&gt;&gt;a;
cout&lt;&lt;&quot;j:&quot;;
cin&gt;&gt;b;
if(a&gt;9 &amp;&amp; b&gt;9)
{
cout&lt;&lt;&quot;Matrix filled:&quot;;
sudukochecker(mat1,mat2,col);
exit(0);

}
else if(mat1[a-1][b-1]!=0)
{
cout&lt;&lt;&quot;Element already exist:&quot;&lt;&lt;endl;
}

else
{
cout&lt;&lt;&quot;Enter Number:&quot;;
cin&gt;&gt;el;
mat1[a-1][b-1]=el;

}
}
}

void practise(){
printf(&quot; ===========================================\n&quot;);
printf(&quot; | | | |\n&quot;);
printf(&quot; | | SUDUKO Practise | |\n&quot;);
printf(&quot; | | | |\n&quot;);
printf(&quot; | | 1. Difficulty 1 | |\n&quot;);
printf(&quot; | | 2. Difficulty 2 | |\n&quot;);
printf(&quot; | | 3. Difficulty 3 | |\n&quot;);
printf(&quot; | | 4. Difficulty 4 | |\n&quot;);
printf(&quot; | | | |\n&quot;);
printf(&quot; | | | |\n&quot;);
printf(&quot; ===========================================\n\n&quot;);
printf(&quot; Enter The Option: &quot;);
fflush(stdin);
int ch;

cin&gt;&gt;ch;
system(&quot;cls&quot;);

// Switch statements begins
switch (ch) {
case 1:
Diff1();
break;

case 2:
Diff2();
break;
case 3:
fflush(stdin);
Diff3();
break;
case 4:
Diff4();
default:
cout&lt;&lt;&quot;Wrong Choice \n&quot;;
}
}
void choicescreen()
{
printf(&quot; ===========================================\n&quot;);
printf(&quot; | | | |\n&quot;);
printf(&quot; | | SUDOKU SOLVER | |\n&quot;);
printf(&quot; | | | |\n&quot;);
printf(&quot; | | 1. Sudoku Solver | |\n&quot;);
printf(&quot; | | 2. Sudoku Practise | |\n&quot;);
printf(&quot; | | | |\n&quot;);
printf(&quot; | | | |\n&quot;);
printf(&quot; ===========================================\n\n&quot;);
printf(&quot; Enter The Option: &quot;);
fflush(stdin);
int ch;

cin&gt;&gt;ch;

system(&quot;cls&quot;);

// Switch statements begins
switch (ch) {
case 1:
Solver();
break;
case 2:
practise();
break;
default:
cout&lt;&lt;&quot;Wrong Choice \n&quot;;
}
}

void mainscreen()
{
char endFrontScreen[2];
setcolor(6);

cout&lt;&lt;&quot; +-++-++-++-++-++-+ +-++-++-++-++-++-+\n&quot;;
cout&lt;&lt;&quot; |S||o||d||u||k||o| |S||o||l||v||e||r|\n&quot;;
cout&lt;&lt;&quot; +-++-++-++-++-++-+ +-++-++-++-++-++-+\n&quot;;

cout&lt;&lt;&quot; P r o j e c t B y : \n&quot;;
cout&lt;&lt;&quot; \n&quot;;
cout&lt;&lt;&quot; Sankalp Dwivedi | Nikhil Varshney | Dhruv Taneja \n&quot;;
cout&lt;&lt;&quot; \n&quot;;
gets(endFrontScreen);

system(&quot;cls&quot;);
choicescreen();

}

int main()
{

int mat[9][9] =
{
{5, 3, 0, 0, 7, 0, 0, 0, 0},
{6, 0, 0, 1, 9, 5, 0, 0, 0},
{0, 9, 8, 0, 0, 0, 0, 6, 0},
{8, 0, 0, 0, 6, 0, 0, 0, 3},
{4, 0, 0, 8, 0, 3, 0, 0, 1},
{7, 0, 0, 0, 2, 0, 0, 0, 6},
{0, 6, 0, 0, 0, 0, 2, 8, 0},
{0, 0, 0, 4, 1, 9, 0, 0, 5},
{0, 0, 0, 0, 8, 0, 0, 7, 9}
};
mainscreen();

}
