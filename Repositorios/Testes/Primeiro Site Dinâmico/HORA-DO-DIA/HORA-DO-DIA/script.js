// Atualizando o Horário

var agora = new Date()

var hora = agora.getHours()
var min = agora.getMinutes()
var seg = agora.getSeconds()

const horario = document.querySelector('.horario')

horario.innerHTML = `Agora são ${hora}h ${min}min ${seg}s`

/*******************************************************************/
/*******************************************************************/
/*******************************************************************/

function carregar(){
    var imagem = document.querySelector('.imagem')

    if(hora >= 6 && hora <12){
        imagem.src = './Imagens/manha.png'
        document.body.style.backgroundColor = '#e0e410bb'
    }else if(hora <18){
        imagem.src = './Imagens/tarde.png'
        document.body.style.backgroundColor = '#e68d07a9'
    }else{
        imagem.src = './Imagens/noite.png'
        document.body.style.backgroundColor = '#053783a9'
    }
}