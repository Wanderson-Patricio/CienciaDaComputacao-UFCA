function isEven(numero){
    return (numero%2 == 0)
}

let numero = 250

let res = (isEven(numero)) ? 'é par' : 'é ímpar'

console.log(`${numero} ` + res)