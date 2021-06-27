#include<stdio.h>

// La cola de prioridad consta de dos numeros enteros.
// El primero es el valor del numero y el segundo la prioridad que este tiene en la cola.


struct node {
	int node;
	int priority;
};

// Se crea puntero que apunte al ultimo de la cola.

int end = -1;

//Se crea matriz tipo nodo, esta matriz contiene dos elementos,  valor y prioridad. 

struct node pr_c[200000];

// Definimos funcion insertar

void insert (int node, int priority)
{
	end++; // aumenta el tamano de la cola de uno en uno. 

	pr_c[end].node=node;  // Insertamos el valor del nodo en la matriz. 
	pr_c[end].priority=priority; // Insertamos la prioridad del nodo en la matriz.
}
 int getHighestPriority() // Funcion para obtener el de mayor prioridad.
{
	int index = -1; // Se guardara el valor que tenga mayor prioridad.
	int highest_priority = -1; // se guarda la prioridad mas alta guardada en el index.

	// Se recorre todos los valores que tenemos
	// el tamano de la cola se guarda en end, entonces la iteracion llega hasta end.

	for (int i=0; i<=end; i++) // para i igual a cero y i menor o igual a end i aumentara de uno en uno  
	{
		// si se tienen dos valores con la misma prioridad, se escoge el valor mas alto.

		if((highest_priority == pr_c[i].priority) && (index > -1) && (pr_c[index].node > pr_c[i].node))
		{
			index = i;
			highest_priority = pr_c[i].priority;
		}

		// Si ese no es el caso, que escoja el de mayor prioridad.

		else if(highest_priority < pr_c[i].priority)
		{
			index=i;
			highest_priority=pr_c[i].priority;
		}
	}
	return index; // si todo sale bien, le pedimos que retorne el elemento que tiene la mayor prioridad.
}

void deleteHighestPriority() // Funcion para  eliminar el nodo que tenga la mayor prioridad en la cola. 
{
	int index = getHighestPriority(); // se guarda elemento que se desea eliminar.
	
	for (int i =index; i<end; i++) // para i igual a index, i menor a end, i se incrementa en uno
	{
		// para todos los valores, asignar cual es el que se desea eliminar
		pr_c[i] = pr_c[i +1]; 
	}
	end--; // reducimos la cola en uno porque se ha eliminado un elemento de la cola.
}

// se crea funcion main

int main()
{
	//Primero insertamos elementos y luego llamamos la funcion.
	
	printf("Insertar 23 con prioridad 1 en la cola\n");
	insert(23, 1);
	printf("Insertar 30 con prioridad 2 en la cola\n");
	insert(30, 2);
	printf("Insertar 25 con prioridad 3 en la cola\n");
	insert(25, 3);
	printf("Insertar 28 con rpioridad 4 en la cola\n");
	insert(28, 4);
	printf("Insertar 9 con prioridad 5 en la cola\n");
	insert(9, 5);

	//LLamamos a la funcion getHighestPriority que retornara el valor con mayor prioridad. 

	int index = getHighestPriority();
	int valor = pr_c[index].node;
	printf("En este momento %d tiene mayor prioridad en la cola.\n", valor);

	//LLamamos funcion deleteHighestPriority para elimianar nodo que tiene la mayor prioridad en la cola.
	
	printf("Eliminar elemento con mayor prioridad en la cola.\n");
	deleteHighestPriority();

	index = getHighestPriority();
	valor = pr_c[index].node;
	printf("En este momento %d tiene la mayor prioridad en la cola...\n", valor);

	return 0;
}

	


