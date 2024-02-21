let n = 20;
let WIDTH = 600;
let numberOfBombs = 40;
let w = WIDTH/n;
let h = WIDTH/n;

let board;

let plantBombs = () => {
  let count = 0;
  let row;
  let col;
  
  do{
    do{
      row = floor(random(board.length)); 
      col = floor(random(board.length));  
    }while(board[row][col].isBomb);
    
    board[row][col].isBomb = true;
    count++;
    
  }while(count < numberOfBombs);
}

let revealCell = (row, col) => {
  board[row][col].revealed = true;
  if(board[row][col].nearBombs === 0){
    for(let i = row - 1; i <= row + 1; i++){
      for(let j = col - 1; j <= col + 1; j++){
        if(i >= 0 && i < n && j >= 0 && j < n && !board[i][j].revealed){
          revealCell(i, j);
        }
      }
    }
  }
}

function setup() {
  createCanvas(WIDTH, WIDTH);
  board = new Array(n);
  for(let i = 0; i < n; i++){
    board[i] = new Array(n);
    for(let j = 0; j < n; j++){
      board[i][j] = new tile(i, j);
    }
  }
  
  plantBombs();
  
  for(let arr of board){
    for(let tile of arr){
      tile.countBombs();
    }
  }
  
  textSize(20);
  textAlign(CENTER);
}

function draw() {
  background(0);
  for(let array of board){
    for(let tile of array){
      tile.draw();
    }
  }
}

function mousePressed(event){
  let x = mouseX;
  let y = mouseY;
  let row = floor(x/w);
  let col = floor(y/h);
  
  if(x < 0 || x > WIDTH || y < 0 || y > WIDTH){
    return;
  }
  
  if(event.button == 2){
    if(board[row][col].suspectOfBomb){
      board[row][col].suspectOfBomb = false;
      board[row][col].revealed = false;
      return;
    }
    board[row][col].suspectOfBomb = true;
    board[row][col].revealed = true;
  }else{
    revealCell(row, col); 
    if(board[row][col].isBomb){
      console.log("You Lose!!");
      for(let arr of board){
        for(let tile of arr){
          tile.suspectOfBomb = false;
          tile.revealed = true;
          tile.draw();
        }
      }
      noLoop();
    }
  }
  
}

