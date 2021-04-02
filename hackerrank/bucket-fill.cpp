#include <bits/stdc++.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

using namespace std;

vector<vector<int>> dp;

void visit(vector<string> &picture, int i, int j, char c, int color){
  if(j < 0 || i < 0 || j >= picture[i].size() || i >= picture.size())
    return;

  if(picture[i][j] != c || dp[i][j])
    return;
  
  dp[i][j] = color;
  visit(picture, i-1, j, c, color);
  visit(picture, i+1, j, c, color);
  visit(picture, i, j-1, c, color);
  visit(picture, i, j+1, c, color);
}

int strokeRequired(vector<string> &picture){

  dp.resize(picture.size());
  for(int i=0; i<picture.size(); i++){
    dp[i].resize(picture[i].size());
    for(int j=0; j<dp[i].size(); j++){
      dp[i][j] = 0;
    }
  }
  
  char current;
  int count = 1;
  for(int i=0; i<picture.size(); i++){
    for(int j=0; j<picture[i].size(); j++){
  
      if(dp[i][j]) continue;
      
      dp[i][j] = count;
      current = picture[i][j];

      visit(picture, i-1, j, current, count);
      visit(picture, i+1, j, current, count);
      visit(picture, i, j-1, current, count);
      visit(picture, i, j+1, current, count);
      count++;
    }
  }

  return count-1;
}

int main (){
  vector<string> picture;
  int ssize;
  cin >>ssize;
  string inpt;
  
  for(int i=0; i<ssize; i++){
    cin >> inpt;
    picture.push_back(inpt);
  }

  cout << strokeRequired(picture) << endl;

  return 0;
}