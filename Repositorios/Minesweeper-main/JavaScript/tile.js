class tile{
  constructor(i, j){
    this.i = i;
    this.j = j;
    this.x = i * w;
    this.y = j * h;
    this.isBomb = false;
    this.revealed = false;
    this.nearBombs = 0;
    this.suspectOfBomb = false;
  }
  
  countBombs(){
    let row = this.i;
    let col = this.j;
    
    if(board[row][col].isBomb){
      this.nearBombs = -1;
      return;
    }
    
    let count = 0;
    for(let i = row - 1; i <= row + 1; i++){
      for(let j = col - 1; j <= col + 1; j++){
        if(i >= 0 && i < n && j >= 0 && j < n && board[i][j].isBomb){
          count++;
        }
      }
    }
    this.nearBombs = count;
  }
  
  draw(){
    rect(this.x, this.y, w, h);
    if(this.revealed){
      if(this.suspectOfBomb){
        text("B",this.x + w/2, this.y+3*h/4);
      }else{
        text(str(this.nearBombs),this.x + w/2, this.y+3*h/4);
      }
    }
  }
}
