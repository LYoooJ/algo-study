const fs = require('fs');

const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

let input = fs.readFileSync(filePath).toString().trim().split('\n');

solution(input);

function solution(input) {
    // const numbers = input[1].split('').map(Number);
    // let answer = 0;
    // for (const num of numbers){
    //   answer += num;
    // }
    const answer = input[1].split('').map(Number).reduce((acc, cur) => acc + cur, 0);
    console.log(answer);
}