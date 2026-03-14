const fs = require('fs');

const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

let input = fs.readFileSync(filePath).toString().trim().split('\n');

solution(input);

function solution(input) {
    const initdigit = 10 ** (input[0].length - 1);
    const N = Number(input[0]);
    const answer = Array.from({length: 10}, () => 0);

    for (let i = initdigit; i >= 1; i = i/10){
        eachDigit(N, i);
    }
    let overZero = 0;
    for (let i = 1; i <= initdigit; i *= 10) {
        overZero += i; 
        // i가 1, 10, 100... 이 되면서 overZero는 1, 11, 111... 이 됩니다!
        }
    answer[0] -= overZero;

    console.log(answer.join(' '));

    function addAllTo(n){
        for (let k = 0; k < 10; k++){
            answer[k] = answer[k] + n;
        }
    }

    function eachDigit(Num, digit){
        const upperDigit =  Math.floor(Num / (digit * 10));
        const lowerDigit = Num % digit;
        const curDigit = Math.floor(Num / digit) % 10;
        // console.log(`upper: ${upperDigit},cur :${curDigit}, lower : ${lowerDigit}`);

        addAllTo(upperDigit * digit);

        for (let j = 0; j < curDigit; j++){
            answer[j] = answer[j] + digit;
        }

        //curDigit은 본인보다 낮은 자리수의 값 만큼 반복되었을 것
        answer[curDigit] = answer[curDigit] + lowerDigit + 1;
        
    }
} 
