int numOfPieces = 5;
float w = 75;
float h = 25;
boolean isOrigin = true;
int ori = -1, dest = -1;
int jogadas = 0;
Game game;

void setup(){
  size(1000, 600);
  game = new Game(numOfPieces);
}

void draw(){
  background(0);
  game.show();
  fill(255);
  textMode(32);
  text(jogadas + " ", 950, 50);
  
  if(game.isOver()){
    println("Você Terminou em " + jogadas + " movimentos.");
    println("O jogo perfeito seria de " + perfectHanoiGame(numOfPieces) + " movimentos.");
    noLoop();
  }
}

void mousePressed(){
  float x = mouseX, y = mouseY;
  if(isOrigin){
    ori = but(x, y);
    if(ori != -1) isOrigin = false;
  }else{
    dest = but(x, y);
    if(dest != -1){
      game.play(ori,dest);
      if(ori != dest) jogadas++;
      isOrigin = true;
      ori = -1;
      dest = -1;
    }
  }
  
}

int but(float x, float y){
  if(y < 15 || y > 45) return -1;
  
  if(x > 162.5 && x < 237.5) return 0;
  if(x > 462.5 && x < 537.5) return 1;
  if(x > 762.5 && x < 837.5) return 2;
  
  return -1;
}

int perfectHanoiGame(int n){
  if(n == 0) return 0;
  
  return 1 + 2 * perfectHanoiGame(n-1); 
}

void HanoiGame(int n, int origin, int dest, int help){
  if(n == 0) return;
  
  HanoiGame(n-1, origin, help, dest);
  game.play(origin,dest);
  background(0);
  delay(10);
  game.show();
  HanoiGame(n-1, help, dest, origin);
}
