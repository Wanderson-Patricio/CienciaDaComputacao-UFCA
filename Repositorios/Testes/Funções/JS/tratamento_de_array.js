function minimum(array){

    let minimum = array[0]

    for(let i in array){
        if(array[i] < minimum){

            minimum = array[i]

        }
    }

    return minimum

}


function maximum(array){
    let maximum = array[0]

    for(let i in array){
        if(array[i] > maximum){

            maximum = array[i]

        }
    }

    return maximum

}


function soma(array){
    let soma = 0

    for(numero of array){
        soma+=numero
    }

    return soma
}

function mean(array){
    return soma(array)/(array.length)
}

function swap(a, b){
    let aux = a
    a = b
    b = aux
}

function sortVector(array){
    let menor
    let n = array.length

    for(let i = 0; i<n-1; i++){

        menor = i

        for(let j = i+1; j<n; j++){
            if(array[j] < array[menor]){
                menor = j
            }
        }

        swap(array[menor], array[i])
    }
}




/*******************************************************/
/*******************************************************/
/*******************************************************/
/*******************************************************/




let array = [10,9,8,7,6,5,4,3,2]

array.sort()
console.log(array)

sortVector(array)
console.log(array)

console.log(soma(array))
console.log(mean(array))