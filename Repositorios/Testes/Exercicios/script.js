// Questão 01 - Imprimir os números de 1 a 10

/*
for(let i=1; i<=10; i++){
    console.log(i)
}
*/

/*************************************************************/
/*************************************************************/

// Questão 02 - Imprimir os números ímpares menores que 100

/*
for(let i=1; i<100; i+=2){
    console.log(i)
}
*/

/*************************************************************/
/*************************************************************/

// Questão 03 - Imprimir a tabuada do 8

/*
const valor = 8

for(let i=1; i<=10; i++){
    console.log(`${valor} x ${i} = ${valor*i}`)
}
*/

/*************************************************************/
/*************************************************************/

// Questão 04 - Imprimir as tabuadas do 1 ao 10

/*
for(let valor = 1; valor<=10; valor++){
    for(let i=1; i<=10; i++){
        console.log(`${valor} x ${i} = ${valor*i}`)
    }
    console.log('')
}
*/

// Outra maneira de resolver

/*
function tabuada(valor){
    for(let i=1; i<=10; i++){
        console.log(`${valor} x ${i} = ${valor*i}`)
    }
    console.log('')
}

for(let valor = 1; valor<=10; valor++){
    tabuada(valor)
}
*/

/*************************************************************/
/*************************************************************/

// Questão 05 - Somar os números de 1 a 10

/*
let soma = 0
let inicio = 1
let fim = 10

for(let i = inicio; i<=fim; i++){
    soma+=i
}

console.log(`A soma de ${inicio} até ${fim} é igual a ${soma}`)
*/

/*************************************************************/
/*************************************************************/

// Questão 06 - Calcular o fatorial de 10

/*
function fatorial(n){
    let fat = 1

    for(let i = 1; i<=n; i++){
        fat*=i
    }

    return fat
}

let valor = 10

console.log(`${valor}! = ${fatorial(valor)}`)
*/

// outra solução (com recursão)

/*
function fatorial(n){
    if(n==1){
        return 1
    }else{
        return n*fatorial(n-1)
    }
}

let valor = 10

console.log(`${valor}! = ${fatorial(valor)}`)
*/

/*************************************************************/
/*************************************************************/

// Questão 07 - Crie uma função para calcular a porcentagem de um número

/*
function porcentage(numero1, numero2){
    return (numero1/100)*numero2
}

let valor = 983
let perc = 37
let resultado = porcentage(perc, valor)

console.log(`${perc}% de ${valor} é ${resultado.toFixed(2).replace('.',',')}`)
*/

/*************************************************************/
/*************************************************************/

// Questão 08 - Calcule a soma dos números ímpares maiores que 10 e menores que 30

/*
let inicio = 10
let fim = 30
let soma = 0

for(let i=inicio+1; i<fim; i++){
    if(i%2 == 1){
        soma += i
    }
}

console.log(soma)
*/

/*************************************************************/
/*************************************************************/

// Questão 09 - Crie uma função que converta de celsius para Fahrenheit

/*
function celsiusToFahrenheit(temp){
    return (9/5)*temp + 32
}

let temperature = 100
console.log(`${temperature}ºC = ${celsiusToFahrenheit(temperature).toFixed(2)}ºF`)
*/

/*************************************************************/
/*************************************************************/

// Questão 10 - Calcule a soma dos elementos de um array

/*
function somaVetor(vetor){
    let soma = 0

    for(let i=0; i<vetor.length; i++){
        soma += vetor[i]
    }

    return soma
}

var vetor = [1,2,3,4,5,6,7,8,9,10]

console.log(somaVetor(vetor))
*/

/*************************************************************/
/*************************************************************/

// Questão 11 - Crie uma função que receba um array e retorne outro apenas com os números positivos no array original

/*
function Imprimir(vetor){
    for(let i=0; i<vetor.length; i++){
        console.log(vetor[i])
    }
}

function removeNegativos(vetor){
    var arrayAux = []

    for(let i=0; i<vetor.length; i++){
        if(vetor[i]>=0){
            arrayAux.push(vetor[i])
        }
    }

    return arrayAux
}

var array = [0,-1,2,-3,-5,4,-5,-9,10]
var arrayNovo = removeNegativos(array)

console.log('Antes de remover os negativos:')
Imprimir(array)
console.log('Após remover os negativos:')
Imprimir(arrayNovo)
*/

/*************************************************************/
/*************************************************************/

// Questão 12 - Crie uma função que calcule a soma dos dígitos de um número

/*
function somaDigitos(numero){
    var numeroString = numero.toString()
    var soma = 0

    for(var digito of numeroString){
        soma += parseInt(digito)
    }

    return soma
}

let numero = 1529

console.log(`A soma dos dígitos de ${numero} é ${somaDigitos(numero)}`)
*/

/*************************************************************/
/*************************************************************/

// Questão 13 - Imprimir os 10 primeiros números de fibonacci sem usar recursividade

/*
function fib(n){
    if(n==1 || n==2){
        return 1
    }

    let a = 1, b = 1, c
    for(let i = 3; i<=n; i++){
        c = a+b
        a = b
        b = c
    }

    return c
}

let final = 100

for(let valor = 1; valor<=final; valor++){
    console.log(`F(${valor}) = ${fib(valor)}`)
}
*/


/*************************************************************/
/*************************************************************/

// Questão 14 - Resolva a questão 13 com recursividade

/*
function fib(n){
    if(n==1 || n==2){
        return 1
    }else{
        return fib(n-1) + fib(n-2)
    }
}

let final = 10

for(let valor = 1; valor<=final; valor++){
    console.log(`F(${valor}) = ${fib(valor)}`)
}
*/

/*************************************************************/
/*************************************************************/

// Questão 14 - Crie uma função que retorna se um número é primo

/*
function isPrime(n){
    let divisers = 0;

    for(let i = 1; i<=n; i++){
        if(n%i == 0){
            divisers++
        }
    }

    return (divisers==2)
}

var numero = 2017
var resultado = (isPrime(numero))? ' é primo':' não é primo'

console.log(numero + resultado)


for(let valor = 1; valor<=1000000; valor++){
    if(isPrime(valor)){
        console.log(valor)
    }
}
*/