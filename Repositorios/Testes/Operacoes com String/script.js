var nome = window.prompt('Qual é o seu nome?')

let nameSize = nome.length

document.writeln(`Prazer <strong>${nome.toUpperCase()}</strong>, seu nome tem ${nameSize} letras.`)