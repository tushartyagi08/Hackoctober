#include <iostream>
using namespace std;
 
int countChange(int denoms[], int denomsLength, int amount) {
  // Edge cases
  if(amount <= 0 || denomsLength <= 0)
    return 0;
  
  int i, j, x, y;
 
  // We need n+1 rows as the table 
  // is constructed in bottom up 
  // manner using the base case 0 
  // value case (n = 0) 
  int lookupTable[amount + 1][denomsLength];
 
  // Fill the enteries for 0 
  // value case (n = 0) 
  for (i = 0; i < denomsLength; i++)
    lookupTable[0][i] = 1;
 
  // Fill rest of the table entries 
  // in bottom up manner 
  for (i = 1; i < amount + 1; i++) {
    for (j = 0; j < denomsLength; j++) {
      // Count of solutions including denoms[j] 
      x = (i - denoms[j] >= 0) ? lookupTable[i - denoms[j]][j] : 0;
 
      // Count of solutions excluding denoms[j] 
      y = (j >= 1) ? lookupTable[i][j - 1] : 0;
 
      // total count 
      lookupTable[i][j] = x + y;
    }
  }
  return lookupTable[amount][denomsLength - 1];
}
 
// Driver Code 
int main() { 
  int denoms[4] = {25,10,5,1};
  cout << countChange(denoms, 4, 10) << endl;
}