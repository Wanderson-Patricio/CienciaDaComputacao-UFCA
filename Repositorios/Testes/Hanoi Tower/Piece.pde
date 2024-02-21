class Piece{
  float x, y;
  float w, h;
  color cor;
  
  Piece(float x, float y, float w, float h, color cor){
    this.x = x;
    this.y = y;
    this.h = h;
    this.w = w;
    this.cor = cor;
  }
  
  void show(){
    fill(cor);
    strokeWeight(1.5);
    stroke(255);
    rect(x - w/2, y - h/2, w, h);
    noStroke();
    ellipse(x - w/2, y, h, h);
    ellipse(x + w/2, y, h, h);
  }
}
