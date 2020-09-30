/************************************************************
 *  name : Youngwoo Park
 *  date : 09-30-2020
 *  level: l2
 *  problem source: programmers
 *  lang: C++
 *  skill:  bfs
 * *********************************************************/
#include <vector>
#include <iostream>
using namespace std;

vector<vector<bool>> visited;
vector<vector<int>> board;
int count = 0;
bool findRoute(int r, int c, int col){
    if(r < 0 || r >= board.size()  || c < 0 || c >= board[0].size())
        return false;
    else if(visited[r][c] == true){
        return false;
    }
    else if(board[r][c] != col)
        return false;
    else{
        visited[r][c] = true;
        count++;
        //cout << "Visit " << r << "," <<c << endl;
        if(findRoute(r-1,c, col) || findRoute(r,c+1, col) || findRoute(r+1,c, col) || findRoute(r,c-1, col)   )
        {
            return true;
        }
        return false;
    }
}
pair<int,int> findNextPoint(){
    for(int i = 0 ; i < board.size() ; i++){
        for(int j = 0 ;  j < board[i].size() ; j++){
            if(board[i][j] > 0 && visited[i][j] == false)
                return {i,j};
        }
    }    
    return {-1,-1};
}
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    visited.clear();
    board.clear();
    for(int i = 0 ; i < m ; i++){
        visited.push_back(vector<bool>());
        board.push_back(vector<int>());
        for(int j = 0 ; j < n ; j ++){
            visited[i].push_back(false);
            board[i].push_back(picture[i][j]);
        }
    }
    count = 0;
    board = picture;
    pair<int,int> start = findNextPoint();
    while(start.first != -1 && start.second != -1){
        count = 0;
        //cout << "< " << start.first << " and " << start.second << ">" << endl;
        findRoute(start.first, start.second, picture[start.first][start.second]);
        //cout << count << endl;
        if(max_size_of_one_area  < count)
            max_size_of_one_area = count;
        number_of_area ++;
        start = findNextPoint();
    }
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}