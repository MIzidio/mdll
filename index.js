import readline from 'readline/promises'

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
})
let isOpen = true
while (isOpen) {
  const answer = await rl.question("> ")
  if (!answer.trim()) {
    rl.close()
    isOpen = false
  } else if (answer === '1 + 2 + 3') {
    console.log('6')
  } else {
    console.log('ERROR')
  }
}