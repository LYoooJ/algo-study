const fs = require('fs');

const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

let input = fs.readFileSync(filePath).toString().trim().split('\n');

solution(input);

function solution(input) {
    let answer = '';

    for (const testCase of input.slice(1)){
      const [R, S] = testCase.trim().split(' ');
      const line = S.split('').map(word => word.repeat(Number(R))).join('');
      answer += `${line}\n`
    }
    console.log(answer.trim());
}