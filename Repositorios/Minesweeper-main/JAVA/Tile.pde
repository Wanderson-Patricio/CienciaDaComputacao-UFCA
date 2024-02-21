class Tile{
  int i, j, nearBombs;
  float x, y;
  boolean isBomb, revealed, suspectOfBomb;
  
  Tile(int i, int j){
    this.i = i;
    this.j = j;
    this.x = i * w;
    this.y = j * h;
  }
  
  void turnBomb(){
    isBomb = true;
  }
  
  void reveal(){
    revealed = true;
  }
  
  void show(){
    fill(255);
    rect(x, y, w, h);
    fill(0);
    if(revealed) {
      if(suspectOfBomb){
        fill(250, 0, 0);
        rect(x, y, w, h);
        return;
      }
      
      switch(nearBombs){
        case -1: fill(0, 0, 0); break; 
        case 0: fill(128,128,128, 50); break;
        case 1: fill(3, 20, 252); break;
        case 2: fill(0, 102, 0); break;
        case 3: fill(250, 0, 0); break;
        case 4: fill(0,0,0); break;

      }
      if(nearBombs > 0) text(nearBombs, x + w/4, y + 3*h/4);
      if(nearBombs == -1) circle(x + w/2, y + h/2, w/2);
      if(nearBombs == 0) rect(x, y, w, h);
    }
  }
}
