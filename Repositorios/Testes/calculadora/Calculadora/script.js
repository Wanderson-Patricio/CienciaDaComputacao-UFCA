var valor1 
var valor2
var op = ''

// Adiciona um símbolo ao visor 
/*******************************************************************************************/
/*******************************************************************************************/
function insert(symbol){
    
    if(document.querySelector('.resultado').innerHTML.length > 15){
        clean()
    }

    if(op === '' && document.querySelector('.resultado').innerHTML !== ''){
        clean()
        op = '**'
    }

    if(document.querySelector('.resultado').innerHTML.length < 13){
        document.querySelector('.resultado').innerHTML += symbol
    }

}

// Limpa o visor
/*******************************************************************************************/
/*******************************************************************************************/
function clean(){
    document.querySelector('.resultado').innerHTML = ''
}

// insere um ponto caso o número ainda não tenha
/*******************************************************************************************/
/*******************************************************************************************/
function insertDot(){
    var numero = document.querySelector('.resultado').innerHTML

    if(numero === ''){
        insert('0')
    }

    if(!numero.includes('.')){
        insert('.')
    }
}

// Apaga o último dígito digitado
/*******************************************************************************************/
/*******************************************************************************************/
function erase(){
    var resultado = document.querySelector('.resultado').innerHTML
    resultado = resultado.substring(0, resultado.length - 1)

    document.querySelector('.resultado').innerHTML = resultado
}

// Guarda a operção a ser feita
/*******************************************************************************************/
/*******************************************************************************************/
function guardarOp(operacao){
    valor1 = Number(document.querySelector('.resultado').innerHTML)
    op = operacao

    clean()
}

//Calcula o resultado da operação
/*******************************************************************************************/
/*******************************************************************************************/
function calcular(){
    var resultado = document.querySelector('.resultado')
    valor2 = Number(resultado.innerHTML)

    switch(op){
        case '+': resultado.innerHTML = `${valor1+valor2}`; break;
        case '-': resultado.innerHTML = `${valor1-valor2}`; break;
        case '/': {
            var tamanho = `${valor1/valor2}`.length

            if(valor2 == 0){
                resultado.innerHTML = 'Undefined'
            }else if(tamanho > 11){
                resultado.innerHTML =`${(valor1/valor2).toFixed(11)}`
            }else{
                resultado.innerHTML =`${valor1/valor2}`
            }
        }; break;
        case 'x': resultado.innerHTML = `${valor1*valor2}`; break;
    }

    op = ''
}