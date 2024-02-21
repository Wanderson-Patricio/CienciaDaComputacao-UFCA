class Game{
  Stack[] stacks;
  Button[] buttons;
  
  Game(int numOfPieces){
    stacks = new Stack[3];
    buttons = new Button[3];
    
    stacks[0] = new Stack(numOfPieces, 200, numOfPieces);
    buttons[0] = new Button(200, 30, 75, 30, "A");
    stacks[1] = new Stack(numOfPieces, 500, 0);
    buttons[1] = new Button(500, 30, 75, 30, "B");
    stacks[2] = new Stack(numOfPieces, 800, 0);
    buttons[2] = new Button(800, 30, 75, 30, "C");
  }
  
  void show(){
    for(Stack s : stacks){
      s.show();
    }
    
    for(Button b : buttons){
      b.show();
    }
  }
  
  void play(int ori, int dest){
    if(ori < 0 || ori > 2 || dest < 0 || dest > 2 || stacks[ori].isEmpty() || stacks[dest].isFull()) return;
    if(stacks[ori].peek().w < stacks[dest].peek().w) return;
    
    Piece removed = stacks[ori].pop();
    stacks[dest].push(removed);
  }
}
