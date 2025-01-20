import {signal} from "./lib/signal.ts"
let output:Boolean[]=new Array(8).fill(false);
console.log(output);
let stdin=process.stdin;
stdin.on("data",(d)=>{
	const [i3,i2,i1,i0]=d.toString().trim().split(' ').map(val=>val==='1'||val.toLowerCase()==='true');
	console.log([i3,i2,i1,i0]);
	output=signal([i0,i1,i2,i3],output);
	console.log(output);
});
