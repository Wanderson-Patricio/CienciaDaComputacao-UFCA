var agora = new Date()

var horas = agora.getHours()
var minutos = agora.getMinutes()
var segundos = agora.getSeconds()

console.log(`Agoras são exatamente ${horas}h ${minutos}min ${segundos}s`)

if(horas < 6){
    console.log('Está de madrugada.')
}else if(horas < 12){
    console.log('Está de manhã.')
}else if(horas < 18){
    console.log('Está de tarde.')
}else{
    console.log('Está de noite.')
}