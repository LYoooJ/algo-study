const fs = require('fs');

const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

let input = fs.readFileSync(filePath).toString().trim().split('\n');

solution(input);

function solution(input) {
    const answer = input[0].split('').reduce((acc, cur) => (cur === cur.toUpperCase()) ? acc + cur.toLowerCase() : acc + cur.toUpperCase(), '');
    console.log(answer);
}