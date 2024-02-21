function textoMulta(velocidade){
    let taxa = 0

    if(velocidade >= 60 && velocidade < 80){
        taxa = 1
    }else if(velocidade >= 80 && velocidade < 100){
        taxa = 2
    }else if(velocidade >= 100){
        taxa = 2.5
    }

    let multa = taxa*velocidade

    if(multa == 0){
        return 'Continue dirigindo com segurança.'
    }else{
        return `<strong>Você está multado!!</strong> Sua multa foi de ${multa.toLocaleString('pt-BR', {style: 'currency', currency:'BRL'})}`
    }
}

function calcular(){
    var texto = document.querySelector('.velocity')
    var velocidade = Number(texto.value)

    var multa = textoMulta(velocidade)

    document.querySelector('.analise').innerHTML = `Sua velocidade é de <strong>${velocidade}</strong> km/h. <br>` + multa
}