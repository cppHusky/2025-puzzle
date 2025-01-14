import {Coordinate} from './lib/coordinate.ts';
import * as operate from './lib/operate.ts';
import * as readline from 'readline';
let you=new Coordinate(0,0);
let enemy=new Coordinate(0,0);
let length:number=0;
operate.initialize(you,enemy,-5,-5);
let stdin=process.openStdin();
stdin.addListener("data",function(d){
	const [a,b]=d.toString().trim().split(' ').map(Number);
	let res=operate.move(you,enemy,length,a,b);
	if(res[0]!=0)
		throw new Error('');
	else{
		you=res[1];
		enemy=res[2];
		length=res[3];
	}
});
