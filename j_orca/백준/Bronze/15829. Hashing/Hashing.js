const fs = require('fs');

const filePath = process.platform === 'linux' ? 0 : './input.txt';


let input = fs.readFileSync(filePath).toString().trim().split('\n');

solution(input);

function solution(input) {
    const char = [...input[1]].map((char) => BigInt(char.charCodeAt(0) - 96));
    const H = char.reduce((acc, cur, i) => acc + cur * (31n)**BigInt(i) , 0n) % 1234567891n;
    console.log(H.toString());
}