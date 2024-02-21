var data = new Date()
var anoAtual = data.getFullYear()

function verificar(){
    var anoForm = document.querySelector('.ano')

    if(anoForm.value.length == 0){

        alert('Digite a sua data de nascimento.')

    }else if(Number(anoForm.value) > anoAtual){

        alert('Digite uma data válida.')

    }else{

        var sexo = document.getElementsByName('sexo')
        var idade = anoAtual-parseInt(anoForm.value)

        var resultado = document.querySelector('.resultado')
        var foto = document.createElement('img')
        foto.setAttribute('class', 'foto')

        var genero = '', nomeImagem = ''
    
        if(sexo[0].checked){

            genero = 'um homem'

            if(idade < 14){
                nomeImagem = './Imagens/crianca_homem.png'
            }else if(idade < 30){
                nomeImagem = './Imagens/jovem_homem.png'
            }else if(idade < 60){
                nomeImagem = './Imagens/adulto_homem.png'
            }else{
                nomeImagem = './Imagens/idoso_homem.png'
            }

        }else{

            genero = 'uma mulher'

            if(idade < 14){
                nomeImagem = './Imagens/crianca_mulher.png'
            }else if(idade < 30){
                nomeImagem = './Imagens/jovem_mulher.png'
            }else if(idade < 60){
                nomeImagem = './Imagens/adulto_mulher.png'
            }else{
                nomeImagem = './Imagens/idoso_mulher.png'
            }
        }

        resultado.innerHTML = `Você é ${genero} de ${idade} anos.`
        foto.setAttribute('src', nomeImagem)

        resultado.appendChild(foto)

    }
}