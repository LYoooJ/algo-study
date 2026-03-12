class Node {
  constructor(value){
    this.value = value;
    this.next = undefined;
  }
}

class Queue {
  constructor(head, tail){
    this.head = undefined;
    this.tail = undefined;
    this.length = 0;
  }
  add(node) {
    if (this.length === 0) {
      this.head = node;
      this.tail = node;
    } else {
    this.tail.next = node;
    this.tail = node;
    }
    this.length = this.length + 1;
  }

  delete() {
    if (this.length === 0) {
      return new Node(-1);
    } 
    const _head = this.head;
    this.length = this.length - 1;
    if (this.length === 0) {
      this.head = undefined;
      this.tail = undefined;
    } else {
    this.head = this.head.next;
    }
    return _head;
  }
}

const fs = require('fs');

const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

let input = fs.readFileSync(filePath).toString().trim().split('\n');

solution(input); 


function solution(input) {
  const insts = input.slice(1).map(line => line.split(' '));
  const queue = new Queue;
  let answer = [];
  for (const inst of insts){
    if(inst[0] === 'push'){
      const newNode = new Node(Number(inst[1]));
      queue.add(newNode);
      continue;
    }
    if(inst[0] === 'pop'){
      answer.push(queue.delete().value);
      continue;
    }
    if(inst[0] === 'size'){
      answer.push(queue.length);
      continue;
    }
    if(inst[0] === 'empty'){
      answer.push((queue.length) ? 0 : 1);
      continue;
    }
    if(inst[0] === 'front'){
      answer.push(queue.head?.value ?? -1); //undefined.value 는 Crash 야기 
      // value || -1 => value 값이 0인 경우에도 -1로 뱉음
      // 옵셔널 체이닝(?.)과 널 병합 연산자(??)를 통해 queue.head가 있으면 value를 주고, 없거나 null/undefined면 -1을 줘!
      continue;
    }
    if(inst[0] === 'back'){
      answer.push(queue.tail?.value ?? -1); 
      continue;
    }
  } 

  console.log(answer.join('\n'));
}
