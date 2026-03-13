const fs = require('fs');

const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

let input = fs.readFileSync(filePath).toString().trim().split('\n');

solution(input);

function solution(input) {
  const T = Number(input[0]); 
  const cache = Array.from(Array(15), () => Array(15).fill(0)); // 15x15 크기의 2차원 배열을 0으로 초기화! (0층~14층, 0호~14호)
  const answer = [];
  for (let i = 0; i < T ; i++){
    const k = Number(input[i * 2 + 1]);
    const n = Number(input[i * 2 + 2]);
    answer.push(member(k, n));
  }

  function member(a, b){
    if (a === 0) return b;
    if (b === 1) return 1;
    if (cache[a][b] === 0){
    cache[a][b] = member(a-1, b) + member(a, b-1);
    }
    return cache[a][b];
  }
  console.log(answer.join('\n'));
}