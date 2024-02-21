class Button{
  float x, y, w, h;
  String s;
  
  Button(float x, float y, float w, float h, String s){
    this.x = x;
    this.y = y;
    this.w = w;
    this.h = h;
    this.s = s;
  }
  
  void show(){
    fill(220);
    rect(x-w/2, y-h/2, w, h);
    textSize(24);
    fill(0);
    textMode(CENTER);
    text(s, x-5, y+h/4);
  }
}
