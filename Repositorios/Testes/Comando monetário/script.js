/*
var nome = window.prompt('Qual é o seu nome?')
window.alert(`Prazer em te conhecer, ${nome}!`)
*/

/*
var n1 = Number(prompt('Digite um número:'))
var n2 = Number(prompt('Digite outro número:'))

var soma = n1 + n2
var sub = n1 - n2
var mult = n1*n2
var div = n1/n2

let texto = `${n1} + ${n2} = ${soma} \n 
${n1} - ${n2} = ${sub} \n
${n1} x ${n2} = ${mult} \n
${n1} / ${n2} = ${div}`

window.alert(texto)
*/

//Calculando o desconto em um produto

var valor = 450

let desconto, taxa

if(valor >= 1000){
    taxa = 0.15
}else if(valor >= 500){
    taxa = 0.10
}else{
    taxa = 0
}

desconto = taxa*valor
let valorDescontado = valor - desconto

document.write(`O preço original do produto é R$ ${valor.toFixed(2).replace('.',',')}</br>`)
document.write(`Com desconto ficará ${valorDescontado.toLocaleString('pt-BR', {style: 'currency', currency:'BRL'})}`)
