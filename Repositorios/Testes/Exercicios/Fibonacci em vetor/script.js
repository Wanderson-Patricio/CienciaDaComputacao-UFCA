let fib = [1,1]

const n = 3

for(let i = 2; i<n; i++){
    fib[i] = fib[i-1] + fib[i-2]
}

for(let numero of fib){
    document.write(`${numero} <br>`)
    document.body.style.fontSize = '12pt'
}