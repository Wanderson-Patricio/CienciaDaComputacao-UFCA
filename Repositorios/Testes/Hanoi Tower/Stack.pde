class Stack{
  Piece[] pieces;
  int top;
  float x;
  
  Stack(int size, float x, int numOfPieces){
    pieces = new Piece[size];
    this.x = x;
    
    top = (numOfPieces > 0) ? size - 1 : -1;
    
    for(int i=0; i<numOfPieces; i++){
      color c = color(255, i*255.0/numOfPieces, 255.0*(numOfPieces -i) / numOfPieces);
      float widt = w + (numOfPieces - i)*w/numOfPieces;
      pieces[i] = new Piece(x, height - (i + 0.5) * h, widt, h, c);
    }
  }
  
  void show(){
    fill(255);
    float yStart = 50;
    rect(x, yStart, 10, height - yStart);
    
    if(isEmpty()) return;
    
    for(Piece p : pieces){
      if(p != null) p.show();
    }
  }
  
  boolean isEmpty(){
    return (top == -1);
  }
  boolean isFull(){
    return (top == pieces.length - 1);
  }
  
  Piece peek(){
    return pieces[top];
  }
  
  void push(Piece newPiece){
    if(isFull()) return;
    
    top++;
    newPiece.x = x;
    newPiece.y = height - (top + 0.5) * h;
    pieces[top] = newPiece;
  }
  
  Piece pop(){
    if(isEmpty()) return null;
    
    top--;
    return pieces[top + 1];
  }
}
