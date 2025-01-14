import * as operate from './lib/operate.ts';
import * as readline from 'readline';
let matrix:boolean[7][7]=[];
for(let i=1;i<=operate.MapM;i++){
	matrix[i]=[];
	for(let j=1;j<=operate.MapN;j++)
		matrix[i][j]=false;
}
console.log(operate.initialize(matrix));
let stdin=process.openStdin();
stdin.addListener("data",function(d){
	const [a,b]=d.toString().trim().split(' ').map(Number);
	let count_on=operate.click(matrix,a,b);
	if(count_on==0)
		console.log(`Congratulations!`);
	console.log(count_on);
});
