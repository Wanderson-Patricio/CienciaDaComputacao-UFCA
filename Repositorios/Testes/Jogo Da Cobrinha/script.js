const canvas = document.querySelector('.canvas')
const context = canvas.getContext('2d')

// Constantes da tela
const gameOver = false
const WIDTH = 600
const HEIGTH = 600
const BLOCKS = 30
const BLOCK_SIZE = WIDTH/BLOCKS
const CANVAS_COLOR = '#000000'
const FPS = 15

// Pontuação
let SCORE = 0
const SCORE_SPAN = document.querySelector('.Score')
let TIME = 0
const TIME_SPAN = document.querySelector('.Time')

// Constantes da  maçã
const FOOD_COLOR = '#ff0000'
var apple

// Constantes Da Cobra
const INICIAL_SIZE = 3
const SNAKE_COLOR = '#008000'
const SNAKE_SPEED = 10
var snake

//********************************************* */
//********************************************* */

class Snake{

    constructor(x, y, size){
        this.x = x
        this.y = y
        this.size = size
        this.body = []
        for(let i = size-1; i>=0; i--){
            this.body.push([x+i, y])
        }
    }

    
}

snake = new Snake(0 ,0, INICIAL_SIZE)

//********************************************* */
//********************************************* */

class Apple{

    constructor(){
        let IsInsideTheSnake

        let x = Math.floor(Math.random() * BLOCKS)
        let y = Math.floor(Math.random() * BLOCKS)
        
        
        do{
            IsInsideTheSnake = false
            let x = Math.floor(Math.random() * BLOCKS)
            let y = Math.floor(Math.random() * BLOCKS)

            for(let i=0; i<snake.body.length; i++){
                if(snake.body[i][0] == x && snake.body[i][1] == y){
                    IsInsideTheSnake = true
                    break
                }
            }
        }while(IsInsideTheSnake)

        context.fillStyle = FOOD_COLOR
        context.fillRect(x*BLOCK_SIZE, y*BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE, FOOD_COLOR)

        this.x = x
        this.y = y
    }

}

apple = new Apple()

//********************************************* */
//********************************************* */

var direction = 'rigth'


//********************************************* */
//********************************************* */


// função para desenhar a maçã
function drawApple(){
    context.fillStyle = FOOD_COLOR
    context.fillRect(apple.x*BLOCK_SIZE, apple.y*BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE, FOOD_COLOR)
}

// Função para mover a cobrinha
function move(){
    direction = direction.toUpperCase()

    
    for(let i = snake.body.length-1; i>0; i--){
        snake.body[i][0] = snake.body[i-1][0]
        snake.body[i][1] = snake.body[i-1][1]
    }

    
    switch(direction){
        case 'LEFT':{
            snake.body[0][0] --
            break
        }
        case 'RIGTH':{
            snake.body[0][0] ++
            break
        }
        case 'UP':{
            snake.body[0][1] --
            break
        }
        case 'DOWN':{
            snake.body[0][1] ++
            break
        }
    }
    
}

// Função para a movimentação no Teclado
window.addEventListener('keydown', (event) => {
    setTimeout(() => {
        if (event.keyCode == 37 && snake.body[1][0] !== snake.body[0][0] - 1) {
            direction = 'LEFT'
        } else if (event.keyCode == 38 && snake.body[1][1] !== snake.body[0][1] - 1) {
            direction = 'UP'
        } else if (event.keyCode == 39 && snake.body[1][0] !== snake.body[0][0] + 1) {
            direction = 'RIGTH'
        } else if (event.keyCode == 40 && snake.body[1][1] !== snake.body[0][1] + 1) {
            direction = 'DOWN'
        }
    }, 1)
})

// Função para checar colisão
function checkColision(){
    

    // Colisão com a parede
    if(snake.body[0][0] < 0 || snake.body[0][0] >= BLOCKS){
        return true
    }

    if(snake.body[0][1] < 0 || snake.body[0][1] >= BLOCKS){
        return true
    }

    // Colisão com o corpo
    for(let i=2; i<snake.body.length; i++){
        if(snake.body[i][0] == snake.body[0][0] && snake.body[i][1] == snake.body[0][1]){
            return true
        }
    }

    return false
}


// Função para desenhar a tela
function drawCanvas(){
    context.fillStyle = CANVAS_COLOR;
    for(let i = 0; i< HEIGTH/BLOCK_SIZE; i++){
        for(let j=0; j<WIDTH/BLOCK_SIZE; j++){
            context.fillRect(i*BLOCK_SIZE, j*BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE)
        }
    }

    //context.fillRect(0, 0, WIDTH, HEIGTH);
}


// Função para desenhar a cobrinha
function drawSnake(){
    context.fillStyle = SNAKE_COLOR

    for(let i = 0; i<snake.body.length; i++){
        x = snake.body[i][0]
        y = snake.body[i][1]
        context.fillRect(x*BLOCK_SIZE, y*BLOCK_SIZE, BLOCK_SIZE - 1, BLOCK_SIZE-1)
    }
}

// Função de Update
function update(){
    if(checkColision()){
        gameOver = true
        return
    }

    if(victory()){
        
        return
    }


    drawCanvas()
    drawApple()
    drawSnake(snake)
}

// Atualiza o tempo de jogo
function updateTime() {
    if(!gameOver){
        TIME++
        TIME_SPAN.innerHTML = `Time: ${TIME} s`
    }
}

// Função para verificar se a cobrinha comeu a maçã
function ateFood(){
    if(apple.x == snake.body[0][0] && apple.y == snake.body[0][1]){
        return true
    }

    return false
}

// Função para aumentar a cobra
function growSnake() {
    snake.body.push([0,0])
    for(let i=snake.body.length - 1; i>=1; i--){
        snake.body[i][0] = snake.body[i-1][0]
        snake.body[i][1] = snake.body[i-1][1]
    }
    
    snake.body[0][0] = apple.x
    snake.body[0][1] = apple.y

    context.fillStyle = CANVAS_COLOR
    context.fillRect(apple.x * BLOCK_SIZE, apple.y * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE)
    apple = new Apple()
}

// Atualiza a pontuação
function updateScore() {
    if(ateFood()){
        SCORE++

        growSnake()
        
    }

    SCORE_SPAN.innerHTML = `Score: ${SCORE}`
}

function victory(){
    if(SCORE == BLOCKS**2 - INICIAL_SIZE){
        window.alert(`Parabéns! Seu tempo foi de: ${TIME} s`);
        return true
    }

    return false
}

// Game Loop
window.onload = function() {
    setInterval(update, 1000/FPS)
    setInterval(updateScore, 1000/FPS)
    setInterval(updateTime, 1000)
    setInterval(move, 1000/SNAKE_SPEED)
}