// Gauss.cpp: определяет точку входа для консольного приложения.
//

#include "iostream" 
#include "mpi.h" 
#include "time.h" 
#include "cassert" 
using namespace std; 
#define DEFAULT_SIZE 1000

int val() 
{ 
	return (int)rand(); 
} 
int main(int argc, char* argv[]) 
{ 
	double elapsed_time; 
	int i,j,k,index; 
	int mynode, totalnodes; 
	double scale; 
	int size; 
	srand((unsigned int) time(0)); 

	MPI_Status status; 
	
	MPI_Init(&argc, &argv); 
	
	MPI_Comm_size(MPI_COMM_WORLD, &totalnodes); 
	//cout << totalnodes << endl;
	MPI_Comm_rank(MPI_COMM_WORLD, &mynode); 

	if (mynode == 0) 
	{ 
    size = DEFAULT_SIZE;

		assert(size % totalnodes == 0); 
		for(int i = 1; i < totalnodes; i++) 
			MPI_Send(&size, 1, MPI_INT, i, 1, MPI_COMM_WORLD); 
	} 

	if (mynode != 0) 
		MPI_Recv(&size, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, &status); 

	elapsed_time = MPI_Wtime(); 
	double **ttA = new double*[size]; 

	for(int l = 0; l < size; l++) 
		ttA[l] = new double[size+1];

	for(int l = 0; l < size; l++) 
	{ 
		for(int m = 0; m < size+1; m++) 
			ttA[l][m] = val(); 
	} 

	int numrows = size / totalnodes; 

	double **A_Local = new double*[numrows]; 

	for(i = 0; i < numrows; i++) 
		A_Local[i] = new double[size+1]; 

	int *myrows = new int[numrows]; 

	for(int i = 0; i < numrows; i++) 
	{ 
		index = mynode + i * totalnodes; 
		myrows[i] = index; 
		for(int j = 0; j < size+1; j++) 
			A_Local[i][j] = ttA[index][j]; 
	} 

	double *tmp = new double[size+1]; 
	double *x = new double[size]; 

	int cnt = 0; 
	for(i = 0; i < size-1; i++) 
	{ 
		if (i == myrows[cnt]) 
		{ 
			//broadcast A_Local[i] & update tmp 
			MPI_Bcast(A_Local[cnt], size+1, MPI_DOUBLE, mynode, MPI_COMM_WORLD); 
			for(j = 0; j < size+1; j++) 
				tmp[j] = A_Local[cnt][j]; 
			cnt++; 
		} 
		else 
			MPI_Bcast(tmp, size+1, MPI_DOUBLE, i%totalnodes, MPI_COMM_WORLD); 

	// update A_Local from tmp 

		for(j = cnt; j < numrows; j++) 
		{ 
			scale = A_Local[j][i]/tmp[i]; 
			for(k = i; k < size+1; k++) 
				A_Local[j][k] = A_Local[j][k] - scale * tmp[k]; 
		} 
	} 

	// preparation for substitution 
	/* init root x equal to right-hand side of system equations ( vector b)otherwise x[i] = 0 */ 
	cnt = 0; 
	for(i = 0; i < size; i++) 
	{ 
		if (i == myrows[cnt]) 
		{ 
			x[i] = A_Local[cnt][size]; 
			cnt++; 
		} 
	else 
		x[i] = 0; 
	} 
	// substitution to find root 
	cnt = numrows-1; 

	for(i = size-1; i>0; i--) 
	{ 
		if(cnt >= 0) 
		{ 
			if (i == myrows[cnt]) 
			{ 
				x[i] = x[i]/A_Local[cnt][i]; 
				MPI_Bcast(x+i, 1, MPI_DOUBLE, mynode, MPI_COMM_WORLD); 
				cnt--; 
			} 
			else 
			MPI_Bcast(x+i, 1, MPI_DOUBLE, i%totalnodes, MPI_COMM_WORLD); 
		} 
		else 
			MPI_Bcast(x+i, 1, MPI_DOUBLE, i%totalnodes, MPI_COMM_WORLD); 

		//update x[i] 
		for(j = 0; j <= cnt; j++) 
			x[myrows[j]] = x[myrows[j]] - A_Local[j][i]*x[i]; 
	} 


	if(mynode==0) 
	{ 
		x[0] = x[0]/A_Local[cnt][0]; 
		MPI_Bcast(x,1,MPI_DOUBLE,0,MPI_COMM_WORLD); 
	} 
	else 
		MPI_Bcast(x,1,MPI_DOUBLE,0,MPI_COMM_WORLD); 

	elapsed_time = MPI_Wtime() - elapsed_time; 

	if(mynode==0) 
	{ 
		for(i=0; i < size;i++) 
			cout <<"x["<< i << "]=\t" << x[i] << endl;
	} 

	delete [] tmp; 
	delete [] myrows; 
	for(i = 0; i < numrows; i++) 
	delete [] A_Local[i]; 
	delete [] A_Local; 
	for( i = 0; i < size; i++) 
	delete [] ttA[i]; 
	delete [] ttA; 
	MPI_Finalize(); 

	return 0; 
} 
