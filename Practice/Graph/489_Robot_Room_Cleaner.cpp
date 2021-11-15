/*
The robot cleaner with 4 given APIs can move forward, turn left or turn right. 
Each turn it made is 90 degrees.

interface Robot {
  // returns true if next cell is open and robot moves into the cell.
  // returns false if next cell is obstacle and robot stays on the current cell.
  boolean move();

  // Robot will stay on the same cell after calling turnLeft/turnRight.
  // Each turn will be 90 degrees.
  void turnLeft();
  void turnRight();

  // Clean the current cell.
  void clean();
}

0 means the cell is blocked, while 1 means the cell is accessible.

room = [
  [1,1,1,1,1,0,1,1],
  [1,1,1,1,1,0,1,1],
  [1,0,1,1,1,1,1,1],
  [0,0,0,1,0,0,0,0],
  [1,1,1,1,1,1,1,1]
],
row = 1,
col = 3
*/
class Solution {
public:
    void cleanRoom(Robot& robot) {
        //need something record visited place
        set<pair<int, int>> visited;
        //direction 0: up, 1: right, 2: down, 3: left
        dfs(visited, 0, 0, 0, robot);
    }
    void dfs(set<pair<int, int>>& visited, int i, int j, int curDir, Robot& robot){
        if(visited.count(make_pair(i, j))) return;
        visited.insert(make_pair(i, j));
        robot.clean();
        
        for(int k= 0; k< 4; k++){
            int x= i, y= j;
            if(robot.move()){
                switch(curDir){
                    case 0: x-= 1; break;
                    case 1: y+= 1; break;
                    case 2: x+= 1; break;
                    case 3: y-= 1; break;
                }
                dfs(visited, x, y, curDir, robot);
                
                //go back to original place, because dfs is our helper function
                //function return does not make the robot move back
                robot.turnRight();
                robot.turnRight();
                robot.move();
                
                //redirect to curDir
                robot.turnRight();
                robot.turnRight();
            }
            robot.turnRight();
            curDir += 1;
            curDir %= 4;
        }
    }
};