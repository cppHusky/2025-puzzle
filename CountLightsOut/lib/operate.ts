export const MapM:number=6;
export const MapN:number=6;
export function initialize(matrix:boolean[][]):number{
	let count_on:number=0;
	for(let i=1;i<=MapM;i++)
		for(let j=1;j<=MapN;j++){
			matrix[i][j]=(Math.random()>.5?true:false);
			if(matrix[i][j])
				count_on++;
		}
	return count_on;
}
export function click(matrix:boolean[][],i:number,j:number):number{
	matrix[i][j]=!matrix[i][j];
	if(i!=1)
		matrix[i-1][j]=!matrix[i-1][j];
	if(i!=6)
		matrix[i+1][j]=!matrix[i+1][j];
	if(j!=1)
	   	matrix[i][j-1]=!matrix[i][j-1];
	if(j!=6)
		matrix[i][j+1]=!matrix[i][j+1];
	let count_on:number=0;
	for(let i=1;i<=MapM;i++)
		for(let j=1;j<=MapN;j++)
			if(matrix[i][j])
				count_on++;
	return count_on;
}
