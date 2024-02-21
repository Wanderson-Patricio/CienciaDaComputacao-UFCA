function calcular(){
    let firstNumber = document.querySelector('.fisrt-number')
    let secondNumber = document.querySelector('.second-number')
    let step = document.querySelector('.step')
    // let result = document.querySelector('.result')

    
    if(firstNumber.value.length == 0){
        alert('[ERRO]')
    }

    let texto = ``
    for(let i = parseInt(firstNumber.value); i<=parseInt(secondNumber.value); i+=parseInt(step.value)){
        texto += `${i}  `
    }

    console.log(texto)
}