function xor(a: any, b: any) {
    return !!a !== !!b;
}
export function signal(input:Boolean[],last:Boolean[]):Boolean[]{
	let output:Boolean[]=new Array(8).fill(false);
	//output[7,5,3,1]记录了本次的输入
	output[7]=input[3];
	output[5]=input[2];
	output[3]=input[1];
	output[1]=input[0];
	//output[6]只有在「本次输入与上次输入完全相反」时，才会得到true
	output[6]=xor(input[3],last[7])&&xor(input[2],last[5])&&xor(input[1],last[3])&&xor(input[0],last[1]);
	//output[4,2]组成二位计数器
	output[4]=xor(last[4],last[2]);
	output[2]=!last[2];
	//result[0]等于所有输入、（上次）输出的异或和
	output[0]=xor(input[0],xor(input[1],xor(input[2],xor(input[3],xor(last[0],xor(last[1],xor(last[2],xor(last[3],xor(last[4],xor(last[5],xor(last[6],last[7])))))))))));
	return output;
}
